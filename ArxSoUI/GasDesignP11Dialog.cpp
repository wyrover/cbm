#include "stdafx.h"
#include "GasDesignP11Dialog.h"
#include "Data.h"
#include "Graph.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

GasDesignP11Dialog::GasDesignP11Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:gas_design_p1_1" ), bModal )
{
}

GasDesignP11Dialog::~GasDesignP11Dialog()
{
}

void GasDesignP11Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT GasDesignP11Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
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
	m_GsEdit = FindChildByName2<SEdit>(L"Gs");
	m_DsEdit = FindChildByName2<SEdit>(L"Ds");

    initDatas();

    return 0;
}

void GasDesignP11Dialog::OnPlaneGraphButtonClick()
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
		work_surf->coal = coal;
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
		technology->coal = coal;
	}
	Utils::cstring_to_double( ( LPCTSTR )m_WdEdit->GetWindowText(), technology->wd );
	Utils::cstring_to_double( ( LPCTSTR )m_HdEdit->GetWindowText(), technology->hd );
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
	Utils::cstring_to_double( ( LPCTSTR )m_GsEdit->GetWindowText(), technology->gs );
	Utils::cstring_to_double( ( LPCTSTR )m_DsEdit->GetWindowText(), technology->ds );
	//保存到数据库
	if( !technology->save() ) return;

	SMessageBox( GetSafeHwnd(), _T( "保存数据成功" ), _T( "友情提示" ), MB_OK );

	//交互选择基点坐标
	AcGePoint3d pt;
	getPoint(pt);

	//计算煤层平面图并绘制
	PlanGraph cp;
	cp.coal = coal;
	cp.ws = work_surf;
	cp.tech = technology;
	cp.setPoint(pt);
	cp.draw();

	AcadSouiDialog::OnOK();
}

void GasDesignP11Dialog::OnHeadGraphButtonClick()
{
}

void GasDesignP11Dialog::OnDipGraphButtonClick()
{
}

static int DipAngle( double angle )
{
	if( angle <= 8 ) // 近水平
		return 1;
	else if( angle <= 25 ) // 缓倾斜
		return 2;
	else if(angle <= 45)  // 倾斜
		return 3;
	else                  // 急倾斜         
		return 4;
}

void GasDesignP11Dialog::OnHelpButtonClick()
{
	double angle = 0;
	Utils::cstring_to_double((LPCTSTR)m_DipAngleEdit->GetWindowText(), angle);
	int k = DipAngle(angle);
	double left=15, right=15, top=15, bottom=15;
	if(k > 2)
	{
		top = 20;
		bottom = 10;
	}
	m_LeftEdit->SetWindowText( Utils::double_to_cstring( left ) );
	m_RightEdit->SetWindowText( Utils::double_to_cstring( right ) );
	m_TopEdit->SetWindowText( Utils::double_to_cstring( top ) );
	m_BottomEdit->SetWindowText( Utils::double_to_cstring( bottom ) );
}

void GasDesignP11Dialog::initDatas()
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
		m_GsEdit->SetWindowText( Utils::double_to_cstring( technology->gs ) );
		m_DsEdit->SetWindowText( Utils::double_to_cstring( technology->ds ) );
    }
}

bool GasDesignP11Dialog::getPoint(AcGePoint3d& pt)
{
	SouiDialogShowSwitch show_switch(this);
	return ArxUtilHelper::PromptPt(_T("请选择一点:"), pt);
}