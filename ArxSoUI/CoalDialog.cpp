#include "stdafx.h"
#include "CoalDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

CoalDialog::CoalDialog(BOOL bModal) : AcadSouiDialog(_T("layout:coal"), bModal)
{
}

CoalDialog::~CoalDialog()
{
}

void CoalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT CoalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_NumberEdit = FindChildByName2<SEdit>(L"number");
	m_FValueEdit = FindChildByName2<SEdit>(L"f_value");
	m_ThickEdit = FindChildByName2<SEdit>(L"thick");
	m_RankCombox = FindChildByName2<SComboBox>(L"rank");
	m_PressureEdit = FindChildByName2<SEdit>(L"pressure");
	m_GasContentEdit = FindChildByName2<SEdit>(L"gas_content");
	m_GasPenetrationEdit = FindChildByName2<SEdit>(L"gas_penetration");
	m_ConstComplexityCombox = FindChildByName2<SComboBox>(L"const_complexity");
	m_VarCoeffEdit = FindChildByName2<SEdit>(L"var_coeff");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_CavingZoneHeightEdit = FindChildByName2<SEdit>(L"caving_zone_height");
	m_ResAbundanceCombox = FindChildByName2<SComboBox>(L"res_abundance");
	m_LayerGapEdit = FindChildByName2<SEdit>(L"layer_gap");
	m_InfluenceFactorEdit = FindChildByName2<SEdit>(L"influence_factor");
	m_MineIndexEdit = FindChildByName2<SEdit>(L"mine_index");
	m_StabilityCombox = FindChildByName2<SComboBox>(L"stability");
	return 0;
}


void CoalDialog::OnSaveButtonClick()
{
}

void CoalDialog::OnNextButtonClick()
{
}

void CoalDialog::OnCancelButtonClick()
{
}

void CoalDialog::OnRankComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void CoalDialog::OnConstComplexityComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void CoalDialog::OnAddCoalButtonClick()
{
}

void CoalDialog::OnResAbundanceComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void CoalDialog::OnStabilityComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
