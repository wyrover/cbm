#include "stdafx.h"
#include "DrillingRadiusDesignDialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

DrillingRadiusDesignDialog::DrillingRadiusDesignDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:drilling_radius_design" ), bModal )
{
    mine_id = 0;
}

DrillingRadiusDesignDialog::~DrillingRadiusDesignDialog()
{
}

void DrillingRadiusDesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT DrillingRadiusDesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_K1Edit = FindChildByName2<SEdit>( L"K1" );
    m_RhoEdit = FindChildByName2<SEdit>( L"rho" );
    m_AEdit = FindChildByName2<SEdit>( L"a" );
    m_TEdit = FindChildByName2<SEdit>( L"t" );
    m_LEdit = FindChildByName2<SEdit>( L"L" );
    m_Q0Edit = FindChildByName2<SEdit>( L"q0" );
    m_REdit = FindChildByName2<SEdit>( L"R" );
    m_QmEdit = FindChildByName2<SEdit>( L"Qm" );
    m_GasW0Edit = FindChildByName2<SEdit>( L"gas_W0" );
    m_QSumEdit = FindChildByName2<SEdit>( L"QSum" );
    m_EtaEdit = FindChildByName2<SEdit>( L"eta" );
    m_GasWc3Edit = FindChildByName2<SEdit>( L"gas_Wc3" );
    m_HwEdit = FindChildByName2<SEdit>( L"hw" );
    m_CoalCombox = FindChildByName2<SComboBox>( L"coal" );

    initCoalDatas();
    initDrillingRadiusDatas();

    return 0;
}


void DrillingRadiusDesignDialog::OnCaclButtonClick()
{
    //提取界面数据
    double R = 0, L = 0, K1 = 0, rho = 0, q0 = 0, a = 0, t = 0, h = 0, W = 0, Q = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_REdit->GetWindowText(), R );
    Utils::cstring_to_double( ( LPCTSTR )m_LEdit->GetWindowText(), L );
    Utils::cstring_to_double( ( LPCTSTR )m_K1Edit->GetWindowText(), K1 );
    Utils::cstring_to_double( ( LPCTSTR )m_RhoEdit->GetWindowText(), rho );
    Utils::cstring_to_double( ( LPCTSTR )m_Q0Edit->GetWindowText(), q0 );
    Utils::cstring_to_double( ( LPCTSTR )m_AEdit->GetWindowText(), a );
    Utils::cstring_to_double( ( LPCTSTR )m_TEdit->GetWindowText(), t );
    Utils::cstring_to_double( ( LPCTSTR )m_HwEdit->GetWindowText(), h );
    Utils::cstring_to_double( ( LPCTSTR )m_GasW0Edit->GetWindowText(), W );
    Utils::cstring_to_double( ( LPCTSTR )m_QSumEdit->GetWindowText(), Q );
    if( R == 0 || h == 0 || W == 0 || L == 0 )
    {
        SMessageBox( GetSafeHwnd(), _T( "无效数据,不能出现等于0的情况!" ), _T( "友情提示" ), MB_OK );
        return;
    }

    //计算Qm
    double Qm = 0;
    if( 2 * R < h || fabs( 2 * R - h ) < 1e-3 ) // 2R<=h
    {
        double S = PI * R * R;
        Qm = 1440 * K1 * q0 * ( 1 - exp( -1 * a * t ) ) / ( rho * a * S * ( R + L ) );
    }
    else
    {
        double S = 2 * R * R * asin( 0.5 * h / R ) + h * sqrt( R * R - 0.25 * h * h );
        Qm = 1440 * K1 * q0 * ( 1 - exp( -1 * a * t ) ) / ( rho * a * S * ( R + L ) );
    }

    //计算eta和Wc,按照公式要求eta>=0.3, Wc<=8
    double eta = Qm / W; //
    double Wc = W - Q;
    //更新到界面
    m_EtaEdit->SetWindowText( Utils::double_to_cstring( eta ) );
    m_GasWc3Edit->SetWindowText( Utils::double_to_cstring( Wc ) );

    //打印提示
    CString msg;
    msg.Format( _T( "根据规定要求:\\n" ) );
    msg.AppendFormat( _T( "    抽采率η=%.2f应大于等于0.3" ), eta );
    msg.AppendFormat( _T( "    抽采后煤层残存瓦斯含量Wc=%.3f应小于等于8" ), Wc );
    SMessageBox( GetSafeHwnd(), msg, _T( "友情提示" ), MB_OK );
}

void DrillingRadiusDesignDialog::OnSaveButtonClick()
{
    int coal_id = SComboBoxHelper::GetCurSelItemID( m_CoalCombox );
    if( coal_id == 0 ) return;
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //保存煤层数据
    Utils::cstring_to_double( ( LPCTSTR )m_HwEdit->GetWindowText(), coal->hw );
    Utils::cstring_to_double( ( LPCTSTR )m_GasW0Edit->GetWindowText(), coal->gas_w0 );
    Utils::cstring_to_double( ( LPCTSTR )m_GasWc3Edit->GetWindowText(), coal->gas_wc3 );

    //瓦斯半径数据
    DrillingRadiusParamPtr drp = FIND_ONE( DrillingRadiusParam, FKEY( Coal ), coal->getStringID() );
    if( drp == 0 )
    {
        drp.reset( new DrillingRadiusParam );
    }
    Utils::cstring_to_double( ( LPCTSTR )m_RhoEdit->GetWindowText(), drp->rho );
    Utils::cstring_to_double( ( LPCTSTR )m_AEdit->GetWindowText(), drp->a );
    Utils::cstring_to_double( ( LPCTSTR )m_TEdit->GetWindowText(), drp->t );
    Utils::cstring_to_double( ( LPCTSTR )m_LEdit->GetWindowText(), drp->l );
    Utils::cstring_to_double( ( LPCTSTR )m_Q0Edit->GetWindowText(), drp->q0 );
    Utils::cstring_to_double( ( LPCTSTR )m_REdit->GetWindowText(), drp->r );
    Utils::cstring_to_double( ( LPCTSTR )m_QmEdit->GetWindowText(), drp->qm );
    Utils::cstring_to_double( ( LPCTSTR )m_QSumEdit->GetWindowText(), drp->qsum );
    Utils::cstring_to_double( ( LPCTSTR )m_EtaEdit->GetWindowText(), drp->eta );
    Utils::cstring_to_double( ( LPCTSTR )m_K1Edit->GetWindowText(), drp->k1 );
    //保存到数据库
    if( !drp->save() )
    {
        SMessageBox( GetSafeHwnd(), _T( "保存数据失败!" ), _T( "友情提示" ), MB_OK );
    }
    else
    {
        SMessageBox( GetSafeHwnd(), _T( "保存数据成功!" ), _T( "友情提示" ), MB_OK );
    }
}

void DrillingRadiusDesignDialog::OnCoalComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
    initCoalDatas();
    initDrillingRadiusDatas();

    int coal_id = SComboBoxHelper::GetItemID( m_CoalCombox, nCurSel );
    if( coal_id == 0 ) return;
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;
    //煤层数据
    m_HwEdit->SetWindowText( Utils::double_to_cstring( coal->hw ) );
    m_GasW0Edit->SetWindowText( Utils::double_to_cstring( coal->gas_w0 ) );
    m_GasWc3Edit->SetWindowText( Utils::double_to_cstring( coal->gas_wc3 ) );
    //保存到数据库
    if( !coal->save() ) return;

    //瓦斯半径数据
    DrillingRadiusParamPtr drp = FIND_ONE( DrillingRadiusParam, FKEY( Coal ), coal->getStringID() );
    if( drp != 0 )
    {
        m_RhoEdit->SetWindowText( Utils::double_to_cstring( drp->rho ) );
        m_AEdit->SetWindowText( Utils::double_to_cstring( drp->a ) );
        m_TEdit->SetWindowText( Utils::double_to_cstring( drp->t ) );
        m_LEdit->SetWindowText( Utils::double_to_cstring( drp->l ) );
        m_Q0Edit->SetWindowText( Utils::double_to_cstring( drp->q0 ) );
        m_REdit->SetWindowText( Utils::double_to_cstring( drp->r ) );
        m_QmEdit->SetWindowText( Utils::double_to_cstring( drp->qm ) );
        m_QSumEdit->SetWindowText( Utils::double_to_cstring( drp->qsum ) );
        m_EtaEdit->SetWindowText( Utils::double_to_cstring( drp->eta ) );
        m_K1Edit->SetWindowText( Utils::double_to_cstring( drp->k1 ) );
    }
}

void DrillingRadiusDesignDialog::OnDestroyWindow()
{
    //删除所有的附加数据
    SComboBoxHelper::Clear( m_CoalCombox );
    AcadSouiDialog::OnDestroyWindow();
}

void DrillingRadiusDesignDialog::fillCoalCombox()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    StringArray coal_names;
    IntArray coal_ids;
    DaoHelper::GetCoalIds( mine->getID(), coal_ids );
    DaoHelper::GetCoalNames( mine->getID(), coal_names );

    SComboBoxHelper::Clear( m_CoalCombox );
    SComboBoxHelper::Append( m_CoalCombox, coal_names, coal_ids );
    SComboBoxHelper::Select( m_CoalCombox, 0 );
}

void DrillingRadiusDesignDialog::initCoalDatas()
{
    m_HwEdit->SetWindowText( NULL );
    m_GasW0Edit->SetWindowText( NULL );
    m_GasWc3Edit->SetWindowText( NULL );
    //m_CoalCombox->SetCurSel(-1);
}

void DrillingRadiusDesignDialog::initDrillingRadiusDatas()
{
    m_RhoEdit->SetWindowText( NULL );
    m_AEdit->SetWindowText( NULL );
    m_TEdit->SetWindowText( NULL );
    m_LEdit->SetWindowText( NULL );
    m_Q0Edit->SetWindowText( NULL );
    m_REdit->SetWindowText( NULL );
    m_QmEdit->SetWindowText( NULL );
    m_QSumEdit->SetWindowText( NULL );
    m_EtaEdit->SetWindowText( NULL );
    m_K1Edit->SetWindowText( _T( "1.2" ) );
}
