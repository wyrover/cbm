#include "stdafx.h"
#include "SampleManageDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

SampleManageDialog::SampleManageDialog(BOOL bModal) : AcadSouiDialog(_T("layout:sample_manage"), bModal)
{
}

SampleManageDialog::~SampleManageDialog()
{
}

void SampleManageDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT SampleManageDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_RegionCombox = FindChildByName2<SComboBox>(L"region");
	m_CoalListctrl = FindChildByName2<SListCtrl>(L"coal");
	m_TechnologyListctrl = FindChildByName2<SListCtrl>(L"technology");
	return 0;
}


void SampleManageDialog::OnLogoutButtonClick()
{
}

void SampleManageDialog::OnRegionComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
