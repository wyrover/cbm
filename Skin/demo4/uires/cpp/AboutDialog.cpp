#include "stdafx.h"
#include "AboutDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

AboutDialog::AboutDialog(BOOL bModal) : AcadSouiDialog(_T("layout:about"), bModal)
{
}

AboutDialog::~AboutDialog()
{
}

void AboutDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT AboutDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_Combox71 = FindChildByName2<SComboBox>(L"combobox71");
	m_Check72 = FindChildByName2<SCheckBox>(L"check72");
	m_Link73 = FindChildByName2<SLink>(L"link73");
	m_Check74 = FindChildByName2<SCheckBox>(L"check74");
	m_Radio75 = FindChildByName2<SRadioBox>(L"radio75");
	return 0;
}


void AboutDialog::OnCombox71SelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
