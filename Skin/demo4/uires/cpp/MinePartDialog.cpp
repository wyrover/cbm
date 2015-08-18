#include "stdafx.h"
#include "MinePartDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MinePartDialog::MinePartDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_part"), bModal)
{
}

MinePartDialog::~MinePartDialog()
{
}

void MinePartDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MinePartDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TopoGeoCombox = FindChildByName2<SComboBox>(L"topo_geo");
	m_GroundCondCheck = FindChildByName2<SCheckBox>(L"ground_cond");
	m_HydrGeoCombox = FindChildByName2<SComboBox>(L"hydr_geo");
	return 0;
}


void MinePartDialog::OnTopoGeoComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void MinePartDialog::OnHydrGeoComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
