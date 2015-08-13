#include "stdafx.h"
#include "RegDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

RegDialog::RegDialog(BOOL bModal) : AcadSouiDialog(_T("layout:reg"), bModal)
{
}

RegDialog::~RegDialog()
{
}

void RegDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT RegDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_NameEdit = FindChildByName2<SEdit>(L"name");
	m_ProvinceEdit = FindChildByName2<SEdit>(L"province");
	m_CoalCountEdit = FindChildByName2<SEdit>(L"coal_count");
	m_CityEdit = FindChildByName2<SEdit>(L"city");
	m_CoalNumsEdit = FindChildByName2<SEdit>(L"coal_nums");
	m_UsernameEdit = FindChildByName2<SEdit>(L"username");
	m_PasswordEdit = FindChildByName2<SEdit>(L"password");
	m_BaseCombox = FindChildByName2<SComboBox>(L"base");
	m_RegionCombox = FindChildByName2<SComboBox>(L"region");
	return 0;
}


void RegDialog::OnRegButtonClick()
{
}

void RegDialog::OnBaseComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}

void RegDialog::OnRegionComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
