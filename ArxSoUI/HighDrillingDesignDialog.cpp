#include "stdafx.h"
#include "HighDrillingDesignDialog.h"
#include "HighDrillingSiteDialog.h"
#include "HighDrillingPoreDialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

HighDrillingDesignDialog::HighDrillingDesignDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:high_drilling_design" ), bModal )
{
    mine_id = 0;
}

HighDrillingDesignDialog::~HighDrillingDesignDialog()
{
}

void HighDrillingDesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT HighDrillingDesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_L1Edit = FindChildByName2<SEdit>( L"L1" );
    m_L2Edit = FindChildByName2<SEdit>( L"L2" );
    m_LgEdit = FindChildByName2<SEdit>( L"Lg" );
    m_WsCombox = FindChildByName2<SComboBox>( L"ws" );
    m_AbcListctrl = FindChildByName2<SListCtrl>( L"abc" );
    m_BcdListctrl = FindChildByName2<SListCtrl>( L"bcd" );

    initDatas();

    return 0;
}


void HighDrillingDesignDialog::OnWsComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
    initDatas();
    SListCtrlHelper::Clear( m_AbcListctrl );
    SListCtrlHelper::Clear( m_BcdListctrl );

    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return;
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    //高抽巷钻场数据
    HighDrillingSiteParamPtr hdsp = FIND_ONE( HighDrillingSiteParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdsp != 0 )
    {
        m_L1Edit->SetWindowText( Utils::double_to_cstring( hdsp->l1 ) );
        m_L2Edit->SetWindowText( Utils::double_to_cstring( hdsp->l2 ) );
        m_LgEdit->SetWindowText( Utils::double_to_cstring( hdsp->lg ) );
    }

    //高抽巷钻孔数据
    HighDrillingPoreParamPtr hdpp = FIND_ONE( HighDrillingPoreParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdpp != 0 )
    {
        //查找abc范围的钻孔(type=0表示abc区域)
        RecordPtrListPtr abc_lists = FIND_MANY2( HighDrillingPore, FKEY( HighDrillingPoreParam ), hdpp->getStringID(), FIELD( type ), Utils::int_to_cstring( 0 ) );
        if( abc_lists != 0 )
        {
            CString str;
            for( int i = 0; i < abc_lists->size(); i++ )
            {
                HighDrillingPorePtr pore = DYNAMIC_POINTER_CAST( HighDrillingPore, abc_lists->at( i ) );
                //插入一行数据
                int nItem = SListCtrlHelper::Add( m_AbcListctrl, pore->getID() );
                //设置各列数据
                //第1列:序号
                SListCtrlHelper::SetIntItem( m_AbcListctrl, nItem, 0, pore->num );
                //第2列:长度(精度:小数点后3位)
                SListCtrlHelper::SetDoubleItem( m_AbcListctrl, nItem, 1, pore->length, 3 );
                //第3列:角度(精度:小数点后2位)
                SListCtrlHelper::SetDoubleItem( m_AbcListctrl, nItem, 2, pore->angle, 2 );
            }
        }
        //查找bcd范围的钻孔(type=1表示bcd区域)
        RecordPtrListPtr bcd_lists = FIND_MANY2( HighDrillingPore, FKEY( HighDrillingPoreParam ), hdpp->getStringID(), FIELD( type ), Utils::int_to_cstring( 1 ) );
        if( bcd_lists != 0 )
        {
            CString str;
            for( int i = 0; i < bcd_lists->size(); i++ )
            {
                HighDrillingPorePtr pore = DYNAMIC_POINTER_CAST( HighDrillingPore, bcd_lists->at( i ) );
                //插入一行数据
                int nItem = SListCtrlHelper::Add( m_AbcListctrl, pore->getID() );
                //设置各列数据
                //第1列:序号
                SListCtrlHelper::SetIntItem( m_AbcListctrl, nItem, 0, pore->num );
                //第2列:长度(精度:小数点后3位)
                SListCtrlHelper::SetDoubleItem( m_AbcListctrl, nItem, 1, pore->length, 3 );
                //第3列:角度(精度:小数点后2位)
                SListCtrlHelper::SetDoubleItem( m_AbcListctrl, nItem, 2, pore->angle, 2 );
            }
        }
    }
}

void HighDrillingDesignDialog::OnDrillSiteButtonClick()
{
    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return;
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    //显示对话框
    HighDrillingSiteDialog dlg( TRUE );
    dlg.ws_id = work_surf->getID(); // 传入工作面id
    if( IDOK != dlg.Run( GetSafeHwnd() ) ) return;

    //计算钻场参数
    HighDrillingSiteParamPtr hdsp = FIND_ONE( HighDrillingSiteParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdsp == 0 ) return;

    double hn = hdsp->hn;
    double Rtn = hdsp->rtn;
    double q = hdsp->q;
    double hs = hdsp->hs;
    double theta = hdsp->theta;
    double L1 = hn * sqrt( 2.0 * Rtn / q ) + 2 * hs / tan( hdsp->theta * PI / 180 );
    double L2 = hn * sqrt( 2.0 * Rtn / ( 3 * q ) );
    double Lg = L2; // Lg = n*L2????

    //更新到界面
    m_L1Edit->SetWindowText( Utils::double_to_cstring( hdsp->l1 ) );
    m_L2Edit->SetWindowText( Utils::double_to_cstring( hdsp->l2 ) );
    m_LgEdit->SetWindowText( Utils::double_to_cstring( hdsp->lg ) );
}

void HighDrillingDesignDialog::OnDrillPoreButtonClick()
{
    //计算钻孔参数
    //从界面提取Lg数据
    double Lg = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_LgEdit->GetWindowText(), Lg );

    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return;
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    //显示对话框
    HighDrillingPoreDialog dlg( TRUE );
    dlg.ws_id = work_surf->getID();  //传入工作面id
    dlg.Lg = Lg; // 传入Lg数据
    if( IDOK != dlg.Run( GetSafeHwnd() ) ) return;

    SListCtrlHelper::Clear( m_AbcListctrl );
    SListCtrlHelper::Clear( m_BcdListctrl );

    //从数据库提取钻孔参数数据
    //高抽巷钻孔数据
    HighDrillingPoreParamPtr hdpp = FIND_ONE( HighDrillingPoreParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdpp == 0 ) return;

    double Lc = hdpp->lc;
    double Ld = hdpp->ld;
    double beta = hdpp->beta;
    int n1 = hdpp->n1;
    int n2 = hdpp->n2;

    int n = n1 + n2;
    double Lk = Lc + Lg;
    double c = beta * PI / ( 180 * ( n + 1 ) );
    //计算并保存钻孔数据到abc的listctrl中
    for( int i = 0; i < n1; i++ )
    {
        int k = i + 1;
        double beta_i = k * c; // 角度
        double Lz_i = Lk / cos( beta_i ); //长度

        int nItem = SListCtrlHelper::Add( m_AbcListctrl, 0 );
        SListCtrlHelper::SetIntItem( m_AbcListctrl, nItem, 0, k );
        SListCtrlHelper::SetDoubleItem( m_AbcListctrl, nItem, 1, Lz_i, 3 );
        SListCtrlHelper::SetDoubleItem( m_AbcListctrl, nItem, 2, beta_i, 2 );
    }
    for( int j = 0; j < n2; j++ )
    {
        int k = j + 1 + n1;;
        double beta_j = k * c; // 角度
        double Lz_j = Ld / sin( beta_j ); //长度

        int nItem = SListCtrlHelper::Add( m_BcdListctrl, 0 );
        SListCtrlHelper::SetIntItem( m_BcdListctrl, nItem, 0, k );
        SListCtrlHelper::SetDoubleItem( m_BcdListctrl, nItem, 1, Lz_j, 3 );
        SListCtrlHelper::SetDoubleItem( m_BcdListctrl, nItem, 2, beta_j, 2 );
    }
}

void HighDrillingDesignDialog::OnSaveButtonClick()
{
    //计算钻场参数
    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return;
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    HighDrillingSiteParamPtr hdsp = FIND_ONE( HighDrillingSiteParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdsp == 0 ) return;

    Utils::cstring_to_double( ( LPCTSTR )m_L1Edit->GetWindowText(), hdsp->l1 );
    Utils::cstring_to_double( ( LPCTSTR )m_L2Edit->GetWindowText(), hdsp->l2 );
    Utils::cstring_to_double( ( LPCTSTR )m_LgEdit->GetWindowText(), hdsp->lg );
    //保存到数据库
    if( !hdsp->save() ) return;

    HighDrillingPoreParamPtr hdpp = FIND_ONE( HighDrillingPoreParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdpp == 0 ) return;

    //删除与钻孔参数关联所有的高位抽采钻孔(abc和bcd范围)
    DELETE_MANY( HighDrillingPore, FKEY( HighDrillingPoreParam ), hdpp->getStringID() );

    //保存abc范围的钻孔
    for( int i = 0; i < m_AbcListctrl->GetItemCount(); i++ )
    {
        int num = 0;
        double length = 0, angle = 0;
        SListCtrlHelper::GetIntItem( m_AbcListctrl, i, 0, num );
        SListCtrlHelper::GetDoubleItem( m_AbcListctrl, i, 1, length );
        SListCtrlHelper::GetDoubleItem( m_AbcListctrl, i, 2, angle );

        HighDrillingPorePtr pore( new HighDrillingPore );
        pore->num = num;
        pore->length = length;
        pore->angle = angle;
        pore->high_drilling_pore_param = hdpp;
        pore->save(); // 保存到数据库
    }
    //保存bcd范围的钻孔
    for( int i = 0; i < m_BcdListctrl->GetItemCount(); i++ )
    {
        int num = 0;
        double length = 0, angle = 0;
        SListCtrlHelper::GetIntItem( m_BcdListctrl, i, 0, num );
        SListCtrlHelper::GetDoubleItem( m_BcdListctrl, i, 1, length );
        SListCtrlHelper::GetDoubleItem( m_BcdListctrl, i, 2, angle );

        HighDrillingPorePtr pore( new HighDrillingPore );
        pore->num = num;
        pore->length = length;
        pore->angle = angle;
        pore->high_drilling_pore_param = hdpp;
        pore->save(); // 保存到数据库
    }

    SMessageBox( GetSafeHwnd(), _T( "保存数据成功!!!" ), _T( "友情提示" ), MB_OK );
}

void HighDrillingDesignDialog::OnDestroyWindow()
{
    //删除所有的附加数据
    SComboBoxHelper::Clear( m_WsCombox );
    SListCtrlHelper::Clear( m_AbcListctrl );
    SListCtrlHelper::Clear( m_BcdListctrl );
    AcadSouiDialog::OnDestroyWindow();
}

void HighDrillingDesignDialog::initDatas()
{
    m_L1Edit->SetWindowText( NULL );
    m_L2Edit->SetWindowText( NULL );
    //m_WsCombox->SetCurSel(-1);
    m_AbcListctrl->SetSelectedItem( -1 );
    m_BcdListctrl->SetSelectedItem( -1 );
}

void HighDrillingDesignDialog::fillWsCombox()
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

WorkSurfPtr HighDrillingDesignDialog::getCurSelWs()
{
    int ws_id = SComboBoxHelper::GetCurSelItemID( m_WsCombox );
    if( ws_id == 0 ) return WorkSurfPtr();
    return FIND_BY_ID( WorkSurf, ws_id );
}
