#include "stdafx.h"
#include "GasDesignP21Dialog.h"
#include "Data.h"
#include "Graph21.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

GasDesignP21Dialog::GasDesignP21Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:gas_design_p2_1" ), bModal )
{
    coal_id = 0;
    tech_id = 0;
}

GasDesignP21Dialog::~GasDesignP21Dialog()
{
}

void GasDesignP21Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT GasDesignP21Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_ThickEdit = FindChildByName2<SEdit>( L"thick" );
    m_DipAngleEdit = FindChildByName2<SEdit>( L"dip_angle" );
    m_L1Edit = FindChildByName2<SEdit>( L"L1" );
    m_L2Edit = FindChildByName2<SEdit>( L"L2" );
    m_WEdit = FindChildByName2<SEdit>( L"w" );
    m_HEdit = FindChildByName2<SEdit>( L"h" );
    m_WdEdit = FindChildByName2<SEdit>( L"Wd" );
    m_HdEdit = FindChildByName2<SEdit>( L"Hd" );
    m_DpEdit = FindChildByName2<SEdit>( L"Dp" );
    m_PoreGapEdit = FindChildByName2<SEdit>( L"pore_gap" );
    m_LsEdit = FindChildByName2<SEdit>( L"Ls" );
    m_WsEdit = FindChildByName2<SEdit>( L"Ws" );
    m_LeftEdit = FindChildByName2<SEdit>( L"left" );
    m_RightEdit = FindChildByName2<SEdit>( L"right" );
    m_TopEdit = FindChildByName2<SEdit>( L"top" );
    m_BottomEdit = FindChildByName2<SEdit>( L"bottom" );
    m_VOffsetEdit = FindChildByName2<SEdit>( L"V_offset" );
    m_HOffsetEdit = FindChildByName2<SEdit>( L"H_offset" );
    m_SiteGapEdit = FindChildByName2<SEdit>( L"site_gap" );
    m_HsEdit = FindChildByName2<SEdit>( L"Hs" );
    m_DOffsetEdit = FindChildByName2<SEdit>( L"D_offset" );
    m_SingleRockTunnelCheck = FindChildByName2<SCheckBox>( L"single_rock_tunnel" );
    m_POffsetEdit = FindChildByName2<SEdit>( L"P_offset" );

    initDatas();

    return 0;
}

void GasDesignP21Dialog::OnPlaneGraphButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //查找抽采技术
    DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
    if( ws_tech == 0 ) return;

    //交互选择基点坐标
    AcGePoint3d pt;
    getPoint( pt );

    //绘制平面图
    P21::PlanGraph graph( coal, ws_tech );
    graph.setPoint( pt );
    graph.draw();

    //AcadSouiDialog::OnOK();
}

void GasDesignP21Dialog::OnHeadGraphButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //查找抽采技术
    DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
    if( ws_tech == 0 ) return;

    //交互选择基点坐标
    AcGePoint3d pt;
    getPoint( pt );

    //绘制平面图
    P21::HeadGraph graph( coal, ws_tech );
    graph.setPoint( pt );
    graph.draw();

    //AcadSouiDialog::OnOK();
}

void GasDesignP21Dialog::OnDipGraphButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //查找抽采技术
    DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
    if( ws_tech == 0 ) return;

    //交互选择基点坐标
    AcGePoint3d pt;
    getPoint( pt );

    //绘制平面图
    P21::DipGraph graph( coal, ws_tech );
    graph.setPoint( pt );
    graph.draw();

    //AcadSouiDialog::OnOK();
}

static int DipAngle( double angle )
{
    if( angle <= 8 ) // 近水平
        return 1;
    else if( angle <= 25 ) // 缓倾斜
        return 2;
    else if( angle <= 45 ) // 倾斜
        return 3;
    else                  // 急倾斜
        return 4;
}

void GasDesignP21Dialog::OnHelpButtonClick()
{
    double angle = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_DipAngleEdit->GetWindowText(), angle );
    int k = DipAngle( angle );
    double left = 15, right = 15, top = 15, bottom = 15;
    if( k > 2 )
    {
        top = 20;
        bottom = 10;
    }
    m_LeftEdit->SetWindowText( Utils::double_to_cstring( left ) );
    m_RightEdit->SetWindowText( Utils::double_to_cstring( right ) );
    m_TopEdit->SetWindowText( Utils::double_to_cstring( top ) );
    m_BottomEdit->SetWindowText( Utils::double_to_cstring( bottom ) );
}

void GasDesignP21Dialog::OnSaveButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
    if( ws_tech == 0 ) return;

    Utils::cstring_to_double( ( LPCTSTR )m_L1Edit->GetWindowText(), ws_tech->l1 );
    Utils::cstring_to_double( ( LPCTSTR )m_L2Edit->GetWindowText(), ws_tech->l2 );
    Utils::cstring_to_double( ( LPCTSTR )m_WEdit->GetWindowText(), ws_tech->w );
    Utils::cstring_to_double( ( LPCTSTR )m_HEdit->GetWindowText(), ws_tech->h );
    Utils::cstring_to_double( ( LPCTSTR )m_WdEdit->GetWindowText(), ws_tech->wd );
    Utils::cstring_to_double( ( LPCTSTR )m_HdEdit->GetWindowText(), ws_tech->hd );
    Utils::cstring_to_double( ( LPCTSTR )m_VOffsetEdit->GetWindowText(), ws_tech->v_offset );
    Utils::cstring_to_double( ( LPCTSTR )m_HOffsetEdit->GetWindowText(), ws_tech->h_offset );
    Utils::cstring_to_double( ( LPCTSTR )m_DpEdit->GetWindowText(), ws_tech->dp );
    Utils::cstring_to_double( ( LPCTSTR )m_PoreGapEdit->GetWindowText(), ws_tech->gp );
    Utils::cstring_to_double( ( LPCTSTR )m_LeftEdit->GetWindowText(), ws_tech->left_side );
    Utils::cstring_to_double( ( LPCTSTR )m_RightEdit->GetWindowText(), ws_tech->right_side );
    Utils::cstring_to_double( ( LPCTSTR )m_TopEdit->GetWindowText(), ws_tech->top_side );
    Utils::cstring_to_double( ( LPCTSTR )m_BottomEdit->GetWindowText(), ws_tech->bottom_side );
    Utils::cstring_to_double( ( LPCTSTR )m_LsEdit->GetWindowText(), ws_tech->ls );
    Utils::cstring_to_double( ( LPCTSTR )m_WsEdit->GetWindowText(), ws_tech->ws );
    Utils::cstring_to_double( ( LPCTSTR )m_SiteGapEdit->GetWindowText(), ws_tech->gs );
    Utils::cstring_to_double( ( LPCTSTR )m_HsEdit->GetWindowText(), ws_tech->hs );
    Utils::cstring_to_double( ( LPCTSTR )m_DOffsetEdit->GetWindowText(), ws_tech->d_offset );
    Utils::cstring_to_double( ( LPCTSTR )m_POffsetEdit->GetWindowText(), ws_tech->p_offset );
    ws_tech->single_rock_tunnel = m_SingleRockTunnelCheck->IsChecked();

    //保存到数据库
    if( !ws_tech->save() ) return;

    SMessageBox( GetSafeHwnd(), _T( "保存数据成功" ), _T( "友情提示" ), MB_OK );
}

void GasDesignP21Dialog::initDatas()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //填充煤层数据
    m_ThickEdit->SetWindowText( Utils::double_to_cstring( coal->thick ) );
    m_DipAngleEdit->SetWindowText( Utils::double_to_cstring( coal->dip_angle ) );

    DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
    if( ws_tech == 0 ) return;

    m_L1Edit->SetWindowText( Utils::double_to_cstring( ws_tech->l1 ) );
    m_L2Edit->SetWindowText( Utils::double_to_cstring( ws_tech->l2 ) );
    m_WEdit->SetWindowText( Utils::double_to_cstring( ws_tech->w ) );
    m_HEdit->SetWindowText( Utils::double_to_cstring( ws_tech->h ) );
    m_WdEdit->SetWindowText( Utils::double_to_cstring( ws_tech->wd ) );
    m_HdEdit->SetWindowText( Utils::double_to_cstring( ws_tech->hd ) );
    m_VOffsetEdit->SetWindowText( Utils::double_to_cstring( ws_tech->v_offset ) );
    m_HOffsetEdit->SetWindowText( Utils::double_to_cstring( ws_tech->h_offset ) );
    m_DpEdit->SetWindowText( Utils::double_to_cstring( ws_tech->dp ) );
    m_PoreGapEdit->SetWindowText( Utils::double_to_cstring( ws_tech->gp ) );
    m_LeftEdit->SetWindowText( Utils::double_to_cstring( ws_tech->left_side ) );
    m_RightEdit->SetWindowText( Utils::double_to_cstring( ws_tech->right_side ) );
    m_TopEdit->SetWindowText( Utils::double_to_cstring( ws_tech->top_side ) );
    m_BottomEdit->SetWindowText( Utils::double_to_cstring( ws_tech->bottom_side ) );
    m_LsEdit->SetWindowText( Utils::double_to_cstring( ws_tech->ls ) );
    m_WsEdit->SetWindowText( Utils::double_to_cstring( ws_tech->ws ) );
    m_SiteGapEdit->SetWindowText( Utils::double_to_cstring( ws_tech->gs ) );
    m_HsEdit->SetWindowText( Utils::double_to_cstring( ws_tech->hs ) );
    m_SingleRockTunnelCheck->SetCheck( BOOL_2_INT( ws_tech->single_rock_tunnel != 0 ) );
    m_DOffsetEdit->SetWindowText( Utils::double_to_cstring( ws_tech->d_offset ) );
    m_POffsetEdit->SetWindowText( Utils::double_to_cstring( ws_tech->p_offset ) );
}

bool GasDesignP21Dialog::getPoint( AcGePoint3d& pt )
{
    SouiDialogShowSwitch show_switch( this );
    return ArxUtilHelper::PromptPt( _T( "请选择一点:" ), pt );
}