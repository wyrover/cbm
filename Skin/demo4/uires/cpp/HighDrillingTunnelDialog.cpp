#include "stdafx.h"
#include "HighDrillingTunnelDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

HighDrillingTunnelDialog::HighDrillingTunnelDialog(BOOL bModal) : AcadSouiDialog(_T("layout:high_drilling_tunnel"), bModal)
{
}

HighDrillingTunnelDialog::~HighDrillingTunnelDialog()
{
}

void HighDrillingTunnelDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT HighDrillingTunnelDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HEdit = FindChildByName2<SEdit>(L"h");
	m_KEdit = FindChildByName2<SEdit>(L"k");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_RockCombox = FindChildByName2<SComboBox>(L"rock");
	m_HzMinEdit = FindChildByName2<SEdit>(L"Hz_min");
	m_Edit14 = FindChildByName2<SEdit>(L"edit14");
	return 0;
}


void HighDrillingTunnelDialog::OnRockComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void HighDrillingTunnelDialog::OnSaveButtonClick()
{
}
