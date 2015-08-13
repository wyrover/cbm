#include "stdafx.h"
#include "MineDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineDialog::MineDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine"), bModal)
{
}

MineDialog::~MineDialog()
{
}

void MineDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_MineNameEdit = FindChildByName2<SEdit>(L"mine_name");
	m_MineCapacityEdit = FindChildByName2<SEdit>(L"mine_capacity");
	m_MineRegionCombox = FindChildByName2<SComboBox>(L"mine_region");
	m_MineBaseCombox = FindChildByName2<SComboBox>(L"mine_base");
	m_TopoGeoCombox = FindChildByName2<SComboBox>(L"topo_geo");
	m_ProvinceEdit = FindChildByName2<SEdit>(L"province");
	m_CityEdit = FindChildByName2<SEdit>(L"city");
	m_HydrGeoCombox = FindChildByName2<SComboBox>(L"hydr_geo");
	return 0;
}


void MineDialog::OnNextButtonClick()
{
}

void MineDialog::OnCancelButtonClick()
{
}

void MineDialog::OnMineRegionComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!m_bLayoutInited) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void MineDialog::OnMineBaseComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!m_bLayoutInited) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void MineDialog::OnTopoGeoComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!m_bLayoutInited) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void MineDialog::OnHydrGeoComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!m_bLayoutInited) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
