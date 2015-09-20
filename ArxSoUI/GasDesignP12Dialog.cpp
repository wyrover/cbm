#include "stdafx.h"
#include "GasDesignP12Dialog.h"
#include "Data.h"
#include "Graph12.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

GasDesignP12Dialog::GasDesignP12Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:gas_design_p1_2" ), bModal )
{
    coal_id = 0;
    tech_id = 0;
}

GasDesignP12Dialog::~GasDesignP12Dialog()
{
}

void GasDesignP12Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT GasDesignP12Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_ThickEdit = FindChildByName2<SEdit>( L"thick" );
    m_DipAngleEdit = FindChildByName2<SEdit>( L"dip_angle" );
    m_LmEdit = FindChildByName2<SEdit>( L"Lm" );
    m_WEdit = FindChildByName2<SEdit>( L"w" );
    m_HEdit = FindChildByName2<SEdit>( L"h" );
    m_DpEdit = FindChildByName2<SEdit>( L"Dp" );
    m_GbpEdit = FindChildByName2<SEdit>( L"Gbp" );
    m_LeftEdit = FindChildByName2<SEdit>( L"left" );
    m_RightEdit = FindChildByName2<SEdit>( L"right" );
    m_TopEdit = FindChildByName2<SEdit>( L"top" );
    m_BottomEdit = FindChildByName2<SEdit>( L"bottom" );
    m_LeadingDistEdit = FindChildByName2<SEdit>( L"leading_dist" );
    m_LStripeEdit = FindChildByName2<SEdit>( L"L_stripe" );

    initDatas();

    return 0;
}


void GasDesignP12Dialog::OnHeadGraphButtonClick()
{

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

void GasDesignP12Dialog::OnHelpButtonClick()
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

void GasDesignP12Dialog::OnDipGraphButtonClick()
{
}

void GasDesignP12Dialog::OnPlaneGraphButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //查找抽采技术
    DesignDrillingSurfTechnologyPtr tws_tech = FIND_BY_ID( DesignDrillingSurfTechnology, this->tech_id );
    if( tws_tech == 0 ) return;

    //交互选择基点坐标
    AcGePoint3d pt;
    getPoint( pt );

    //绘制平面图
    P12::PlanGraph graph( coal, tws_tech );
    graph.setPoint( pt );
    graph.draw();

    //AcadSouiDialog::OnOK();
}

void GasDesignP12Dialog::OnSaveButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, this->coal_id );
    if( coal == 0 ) return;

    DesignDrillingSurfTechnologyPtr tws_tech = FIND_BY_ID( DesignDrillingSurfTechnology, this->tech_id );
    if( tws_tech == 0 ) return;

    Utils::cstring_to_double( ( LPCTSTR )m_LmEdit->GetWindowText(), tws_tech->lm );
    Utils::cstring_to_double( ( LPCTSTR )m_WEdit->GetWindowText(), tws_tech->w );
    Utils::cstring_to_double( ( LPCTSTR )m_HEdit->GetWindowText(), tws_tech->h );
    Utils::cstring_to_double( ( LPCTSTR )m_DpEdit->GetWindowText(), tws_tech->dp );
    Utils::cstring_to_double( ( LPCTSTR )m_LeftEdit->GetWindowText(), tws_tech->left_side );
    Utils::cstring_to_double( ( LPCTSTR )m_RightEdit->GetWindowText(), tws_tech->right_side );
    Utils::cstring_to_double( ( LPCTSTR )m_TopEdit->GetWindowText(), tws_tech->top_side );
    Utils::cstring_to_double( ( LPCTSTR )m_BottomEdit->GetWindowText(), tws_tech->bottom_side );
    Utils::cstring_to_double( ( LPCTSTR )m_LeadingDistEdit->GetWindowText(), tws_tech->leading_dist );
    Utils::cstring_to_double( ( LPCTSTR )m_LStripeEdit->GetWindowText(), tws_tech->l_stripe );
    Utils::cstring_to_double( ( LPCTSTR )m_GbpEdit->GetWindowText(), tws_tech->gbp );
    //保存到数据库
    if( !tws_tech->save() ) return;

    SMessageBox( GetSafeHwnd(), _T( "保存数据成功" ), _T( "友情提示" ), MB_OK );
}

void GasDesignP12Dialog::initDatas()
{
    CoalPtr coal = FIND_BY_ID( Coal, this->coal_id );
    if( coal == 0 ) return;

    //填充煤层数据
    m_ThickEdit->SetWindowText( Utils::double_to_cstring( coal->thick ) );
    m_DipAngleEdit->SetWindowText( Utils::double_to_cstring( coal->dip_angle ) );

    DesignDrillingSurfTechnologyPtr tws_tech = FIND_BY_ID( DesignDrillingSurfTechnology, this->tech_id );
    if( tws_tech == 0 ) return;

    m_LmEdit->SetWindowText( Utils::double_to_cstring( tws_tech->lm ) );
    m_WEdit->SetWindowText( Utils::double_to_cstring( tws_tech->w ) );
    m_HEdit->SetWindowText( Utils::double_to_cstring( tws_tech->h ) );
    m_DpEdit->SetWindowText( Utils::double_to_cstring( tws_tech->dp ) );
    m_LeftEdit->SetWindowText( Utils::double_to_cstring( tws_tech->left_side ) );
    m_RightEdit->SetWindowText( Utils::double_to_cstring( tws_tech->right_side ) );
    m_TopEdit->SetWindowText( Utils::double_to_cstring( tws_tech->top_side ) );
    m_BottomEdit->SetWindowText( Utils::double_to_cstring( tws_tech->bottom_side ) );
    m_LeadingDistEdit->SetWindowText( Utils::double_to_cstring( tws_tech->leading_dist ) );
    m_LStripeEdit->SetWindowText( Utils::double_to_cstring( tws_tech->l_stripe ) );
    m_GbpEdit->SetWindowText( Utils::double_to_cstring( tws_tech->gbp ) );
}

bool GasDesignP12Dialog::getPoint( AcGePoint3d& pt )
{
    SouiDialogShowSwitch show_switch( this );
    return ArxUtilHelper::PromptPt( _T( "请选择一点:" ), pt );
}