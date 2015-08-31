#include "stdafx.h"
#include "DesignP11Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

//#include <DefGE/CoalSurface.h>
//#include <DefGE/DrillSite.h>
//#include <DefGE/DrillPore.h>
//#include <DefGE/Tunnel.h>

DesignP11Dialog::DesignP11Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:design_p1_1" ), bModal )
{
}

DesignP11Dialog::~DesignP11Dialog()
{
}

void DesignP11Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT DesignP11Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
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
    m_GpEdit = FindChildByName2<SEdit>( L"Gp" );
    m_WsEdit = FindChildByName2<SEdit>( L"Ws" );
    m_HsEdit = FindChildByName2<SEdit>( L"Hs" );
    m_LeftEdit = FindChildByName2<SEdit>( L"left" );
    m_RightEdit = FindChildByName2<SEdit>( L"right" );
    m_TopEdit = FindChildByName2<SEdit>( L"top" );
    m_BottomEdit = FindChildByName2<SEdit>( L"bottom" );
    m_VOffsetEdit = FindChildByName2<SEdit>( L"V_offset" );
    m_HOffsetEdit = FindChildByName2<SEdit>( L"H_offset" );
    m_NameEdit = FindChildByName2<SEdit>( L"name" );

    initDatas();

    return 0;
}

//计算工作面的平面尺寸
static void CaclCoalSurfSize( double L1, double L2, double left, double right, double w, double offset, double& Wc, double& Hc )
{
    //计算宽度(倾向长度L2+工作面左帮控制范围left+偏移)
    Wc = L2 + w + 1.2 * left;
    //w = w*cos(DEG_2_RAD(angle));
    Hc = L1 + 2 * w + 1.2 * left + 0.6 * right + offset;
}

static void DrawCoalSurf( const AcGePoint3d& pt, double Wc, double Hc )
{

}

void DesignP11Dialog::OnSaveButtonClick()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //保存煤层数据到数据库
    Utils::cstring_to_double( ( LPCTSTR )m_ThickEdit->GetWindowText(), coal->thick );
    Utils::cstring_to_double( ( LPCTSTR )m_DipAngleEdit->GetWindowText(), coal->dip_angle );
    if( !coal->save() ) return;

    //保存工作面数据
    //查找煤层关联的设计工作面
    DesignWorkSurfPtr work_surf = FIND_ONE( DesignWorkSurf, FKEY( Coal ), coal->getStringID() );
    if( work_surf == 0 )
    {
        work_surf.reset( new DesignWorkSurf );
    }
    work_surf->name = m_NameEdit->GetWindowText();
    Utils::cstring_to_double( ( LPCTSTR )m_L1Edit->GetWindowText(), work_surf->l1 );
    Utils::cstring_to_double( ( LPCTSTR )m_L2Edit->GetWindowText(), work_surf->l2 );
    Utils::cstring_to_double( ( LPCTSTR )m_WEdit->GetWindowText(), work_surf->w );
    Utils::cstring_to_double( ( LPCTSTR )m_HEdit->GetWindowText(), work_surf->h );
    if( !work_surf->save() ) return;

    //保存抽采技术参数
    DesignTechnologyPtr technology = FIND_ONE( DesignTechnology, FKEY( Coal ), coal->getStringID() );
    if( technology == 0 )
    {
        technology.reset( new DesignTechnology );
    }
    Utils::cstring_to_double( ( LPCTSTR )m_WdEdit->GetWindowText(), technology->wd );
    Utils::cstring_to_double( ( LPCTSTR )m_HdEdit->GetWindowText(), technology->wd );
    Utils::cstring_to_double( ( LPCTSTR )m_VOffsetEdit->GetWindowText(), technology->v_offset );
    Utils::cstring_to_double( ( LPCTSTR )m_HOffsetEdit->GetWindowText(), technology->h_offset );
    Utils::cstring_to_double( ( LPCTSTR )m_DpEdit->GetWindowText(), technology->dp );
    Utils::cstring_to_double( ( LPCTSTR )m_GpEdit->GetWindowText(), technology->gp );
    Utils::cstring_to_double( ( LPCTSTR )m_LeftEdit->GetWindowText(), technology->left_side );
    Utils::cstring_to_double( ( LPCTSTR )m_RightEdit->GetWindowText(), technology->right_side );
    Utils::cstring_to_double( ( LPCTSTR )m_TopEdit->GetWindowText(), technology->top_side );
    Utils::cstring_to_double( ( LPCTSTR )m_BottomEdit->GetWindowText(), technology->bottom_side );
    Utils::cstring_to_double( ( LPCTSTR )m_WsEdit->GetWindowText(), technology->ws );
    Utils::cstring_to_double( ( LPCTSTR )m_HsEdit->GetWindowText(), technology->hs );
    if( !technology->save() ) return;
}

void DesignP11Dialog::initDatas()
{
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    //填充煤层数据
    m_ThickEdit->SetWindowText( Utils::double_to_cstring( coal->thick ) );
    m_DipAngleEdit->SetWindowText( Utils::double_to_cstring( coal->dip_angle ) );

    //查找煤层关联的设计工作面
    DesignWorkSurfPtr work_surf = FIND_ONE( DesignWorkSurf, FKEY( Coal ), coal->getStringID() );
    if( work_surf != 0 )
    {
        m_L1Edit->SetWindowText( Utils::double_to_cstring( work_surf->l1 ) );
        m_L2Edit->SetWindowText( Utils::double_to_cstring( work_surf->l2 ) );
        m_WEdit->SetWindowText( Utils::double_to_cstring( work_surf->w ) );
        m_HEdit->SetWindowText( Utils::double_to_cstring( work_surf->h ) );
    }
    //查找与煤层关联的抽采技术参数
    DesignTechnologyPtr technology = FIND_ONE( DesignTechnology, FKEY( Coal ), coal->getStringID() );
    if( technology != 0 )
    {
        m_WdEdit->SetWindowText( Utils::double_to_cstring( technology->wd ) );
        m_HdEdit->SetWindowText( Utils::double_to_cstring( technology->hd ) );
        m_VOffsetEdit->SetWindowText( Utils::double_to_cstring( technology->v_offset ) );
        m_HOffsetEdit->SetWindowText( Utils::double_to_cstring( technology->h_offset ) );
        m_DpEdit->SetWindowText( Utils::double_to_cstring( technology->dp ) );
        m_GpEdit->SetWindowText( Utils::double_to_cstring( technology->gp ) );
        m_LeftEdit->SetWindowText( Utils::double_to_cstring( technology->left_side ) );
        m_RightEdit->SetWindowText( Utils::double_to_cstring( technology->right_side ) );
        m_TopEdit->SetWindowText( Utils::double_to_cstring( technology->top_side ) );
        m_BottomEdit->SetWindowText( Utils::double_to_cstring( technology->bottom_side ) );
        m_WsEdit->SetWindowText( Utils::double_to_cstring( technology->ws ) );
        m_HsEdit->SetWindowText( Utils::double_to_cstring( technology->hs ) );
    }
}
