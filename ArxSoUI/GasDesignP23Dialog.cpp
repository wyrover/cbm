#include "stdafx.h"
#include "GasDesignP23Dialog.h"
#include "Data.h"
#include "Graph23.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

GasDesignP23Dialog::GasDesignP23Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:gas_design_p2_3"), bModal)
{
	coal_id = 0;
	tech_id = 0;
}

GasDesignP23Dialog::~GasDesignP23Dialog()
{
}

void GasDesignP23Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT GasDesignP23Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ThickEdit = FindChildByName2<SEdit>(L"thick");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_L1Edit = FindChildByName2<SEdit>(L"L1");
	m_L2Edit = FindChildByName2<SEdit>(L"L2");
	m_WEdit = FindChildByName2<SEdit>(L"w");
	m_HEdit = FindChildByName2<SEdit>(L"h");
	m_DpEdit = FindChildByName2<SEdit>(L"Dp");
	m_PoreGapEdit = FindChildByName2<SEdit>(L"pore_gap");
	m_PoreStubbleEdit = FindChildByName2<SEdit>(L"pore_stubble");
	m_PoreType1Radio = FindChildByName2<SRadioBox>(L"pore_type_1");
	m_PoreType2Radio = FindChildByName2<SRadioBox>(L"pore_type_2");
	m_PoreType3Radio = FindChildByName2<SRadioBox>(L"pore_type_3");
	m_PoreType4Radio = FindChildByName2<SRadioBox>(L"pore_type_4");
	m_PoreAngleEdit = FindChildByName2<SEdit>(L"pore_angle");

	initDatas();

	return 0;
}


void GasDesignP23Dialog::OnHeadGraphButtonClick()
{
}

void GasDesignP23Dialog::OnDipGraphButtonClick()
{
}

void GasDesignP23Dialog::OnPlaneGraphButtonClick()
{
	CoalPtr coal = FIND_BY_ID( Coal, coal_id );
	if( coal == 0 ) return;

	//查找抽采技术
	DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
	if( ws_tech == 0 ) return;

	//交互选择基点坐标
	AcGePoint3d pt;
	getPoint(pt);

	//绘制平面图
	P23::PlanGraph graph(coal, ws_tech);
	graph.setPoint(pt);
	graph.draw();

	//AcadSouiDialog::OnOK();
}

void GasDesignP23Dialog::OnSaveButtonClick()
{
	CoalPtr coal = FIND_BY_ID( Coal, coal_id );
	if( coal == 0 ) return;

	DesignWorkSurfTechnologyPtr ws_tech = FIND_BY_ID( DesignWorkSurfTechnology, this->tech_id );
	if( ws_tech == 0 ) return;

	Utils::cstring_to_double( ( LPCTSTR )m_L1Edit->GetWindowText(), ws_tech->l1 );
	Utils::cstring_to_double( ( LPCTSTR )m_L2Edit->GetWindowText(), ws_tech->l2 );
	Utils::cstring_to_double( ( LPCTSTR )m_WEdit->GetWindowText(), ws_tech->w );
	Utils::cstring_to_double( ( LPCTSTR )m_HEdit->GetWindowText(), ws_tech->h );
	Utils::cstring_to_double( ( LPCTSTR )m_DpEdit->GetWindowText(), ws_tech->dp );
	Utils::cstring_to_double( ( LPCTSTR )m_PoreGapEdit->GetWindowText(), ws_tech->gp );	
	Utils::cstring_to_double( ( LPCTSTR )m_PoreStubbleEdit->GetWindowText(), ws_tech->pore_stubble );
	Utils::cstring_to_double( ( LPCTSTR )m_PoreAngleEdit->GetWindowText(), ws_tech->pore_angle );

	ws_tech->pore_type = 0;
	if(m_PoreType1Radio->IsChecked()) ws_tech->pore_type = 1;
	else if(m_PoreType2Radio->IsChecked()) ws_tech->pore_type = 2;
	else if(m_PoreType3Radio->IsChecked()) ws_tech->pore_type = 3;
	else if(m_PoreType4Radio->IsChecked()) ws_tech->pore_type = 4;

	//保存到数据库
	if( !ws_tech->save() ) return;

	SMessageBox( GetSafeHwnd(), _T( "保存数据成功" ), _T( "友情提示" ), MB_OK );
}

void GasDesignP23Dialog::OnRadioGroup1Switch(int nID)
{
	if(!isLayoutInited()) return;
}

void GasDesignP23Dialog::initDatas()
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
	m_DpEdit->SetWindowText( Utils::double_to_cstring( ws_tech->dp ) );
	m_PoreGapEdit->SetWindowText( Utils::double_to_cstring( ws_tech->gp ) );
	m_PoreStubbleEdit->SetWindowText(Utils::double_to_cstring( ws_tech->pore_stubble ));
	m_PoreAngleEdit->SetWindowText(Utils::double_to_cstring( ws_tech->pore_angle ));

	int type = ws_tech->pore_type;
	if(type == 1)
	{
		m_PoreType1Radio->SetCheck(TRUE);
	}
	else if(type == 2)
	{
		m_PoreType2Radio->SetCheck(TRUE);
	}
	else if(type == 3)
	{
		m_PoreType3Radio->SetCheck(TRUE);
	}
	else if(type == 4)
	{
		m_PoreType4Radio->SetCheck(TRUE);
	}
}

bool GasDesignP23Dialog::getPoint(AcGePoint3d& pt)
{
	SouiDialogShowSwitch show_switch(this);
	return ArxUtilHelper::PromptPt(_T("请选择一点:"), pt);
}