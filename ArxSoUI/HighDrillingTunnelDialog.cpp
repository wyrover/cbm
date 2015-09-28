#include "stdafx.h"
#include "HighDrillingTunnelDialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

HighDrillingTunnelDialog::HighDrillingTunnelDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:high_drilling_tunnel" ), bModal )
{
    mine_id = 0;
}

HighDrillingTunnelDialog::~HighDrillingTunnelDialog()
{
}

void HighDrillingTunnelDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT HighDrillingTunnelDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_HwEdit = FindChildByName2<SEdit>( L"hw" );
    m_CzkEdit = FindChildByName2<SEdit>( L"czk" );
    m_DipAngleEdit = FindChildByName2<SEdit>( L"dip_angle" );
    m_RockCombox = FindChildByName2<SComboBox>( L"rock" );
    m_HzMinEdit = FindChildByName2<SEdit>( L"Hz_min" );
    m_HzMaxEdit = FindChildByName2<SEdit>( L"Hz_max" );
    m_WsCombox = FindChildByName2<SComboBox>( L"ws" );

    initWsDatas();
    fillWsCombox();

    return 0;
}


void HighDrillingTunnelDialog::OnRockComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void HighDrillingTunnelDialog::OnSaveButtonClick()
{
    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return;

    //根据id查找回采工作面
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    //高抽巷数据
    HighDrillingTunnelPtr hdt = FIND_ONE( HighDrillingTunnel, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdt == 0 )
    {
        hdt.reset( new HighDrillingTunnel );
    }

    Utils::cstring_to_double( ( LPCTSTR )m_CzkEdit->GetWindowText(), hdt->k );
    Utils::cstring_to_double( ( LPCTSTR )m_HzMaxEdit->GetWindowText(), hdt->hz_max );
    Utils::cstring_to_double( ( LPCTSTR )m_HzMinEdit->GetWindowText(), hdt->hz_min );
    hdt->rock = m_RockCombox->GetCurSel() + 1;
    if( hdt->save() )
    {
        SMessageBox( GetSafeHwnd(), _T( "保存数据成功!!!" ), _T( "友情提示" ), MB_OK );
    }
}

void HighDrillingTunnelDialog::OnWsComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
    initWsDatas();
    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return;

    //根据id查找回采工作面
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;
    WorkAreaPtr work_area = DYNAMIC_POINTER_CAST( WorkArea, work_surf->work_area );
    if( work_area == 0 ) return;
    CoalPtr coal = DYNAMIC_POINTER_CAST( Coal, work_area->coal );
    if( coal == 0 ) return;

    //工作面数据
    m_HwEdit->SetWindowText( Utils::double_to_cstring( coal->hw ) ); // 采高
    //煤层数据
    m_DipAngleEdit->SetWindowText( Utils::double_to_cstring( coal->dip_angle ) ); // 煤层倾角
    //高抽巷数据
    HighDrillingTunnelPtr hdt = FIND_ONE( HighDrillingTunnel, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdt != 0 )
    {
        m_CzkEdit->SetWindowText( Utils::double_to_cstring( hdt->k ) ); //K
        m_RockCombox->SetCurSel( hdt->rock - 1 ); // 岩性
        m_HzMinEdit->SetWindowText( Utils::double_to_cstring( hdt->hz_min ) );
        m_HzMaxEdit->SetWindowText( Utils::double_to_cstring( hdt->hz_max ) );
    }
}

void HighDrillingTunnelDialog::OnCaclButtonClick()
{
    double k = 0, alpha = 0, h = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_CzkEdit->GetWindowText(), k );
    Utils::cstring_to_double( ( LPCTSTR )m_DipAngleEdit->GetWindowText(), alpha );
    int rock_id = m_RockCombox->GetCurSel() + 1;
    if( rock_id == 0 )
    {
        SMessageBox( GetSafeHwnd(), _T( "请选择岩性!!!" ), _T( "友情提示" ), MB_OK );
        return;
    }

    //查找rock表得到a,b,c
    double a = 0, b = 0, c = 0;
    RockPtr rock = FIND_BY_ID( Rock, rock_id );
    if( rock != 0 )
    {
        a = rock->a;
        b = rock->b;
        c = rock->c;
    }
    double hz_min = h / ( ( k - 1 ) * cos( alpha * PI / 180 ) );
    double hz_max = 100 * h / ( a * h + b ) + c;

    //更新到界面
    m_HzMinEdit->SetWindowText( Utils::double_to_cstring( hz_min ) );
    m_HzMaxEdit->SetWindowText( Utils::double_to_cstring( hz_max ) );
}

void HighDrillingTunnelDialog::OnDestroyWindow()
{
    //删除所有的附加数据
    SComboBoxHelper::Clear( m_WsCombox );
    AcadSouiDialog::OnDestroyWindow();
}

void HighDrillingTunnelDialog::initWsDatas()
{
    m_HwEdit->SetWindowText( NULL );
    m_CzkEdit->SetWindowText( NULL );
    m_DipAngleEdit->SetWindowText( NULL );
    //m_WsCombox->SetCurSel(-1);
    m_HzMinEdit->SetWindowText( NULL );
    m_HzMaxEdit->SetWindowText( NULL );
}

void HighDrillingTunnelDialog::fillWsCombox()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    //查询所有的回采工作面
    RecordPtrListPtr lists = DaoHelper::GetWorkSurfs( mine->getID() );
    if( lists == 0 ) return;

    for( int i = 0; i < lists->size(); i++ )
    {
        WorkSurfPtr work_surf = DYNAMIC_POINTER_CAST( WorkSurf, lists->at( i ) );
        if( work_surf == 0 ) continue;

        SComboBoxHelper::Add( m_WsCombox, work_surf->name, work_surf->getID() );
    }
    SComboBoxHelper::Select( m_WsCombox, 0 );
}

WorkSurfPtr HighDrillingTunnelDialog::getCurSelWs()
{
    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return WorkSurfPtr();
    return FIND_BY_ID( WorkSurf, ws_id );
}
