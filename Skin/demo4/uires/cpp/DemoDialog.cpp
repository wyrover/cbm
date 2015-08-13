#include "stdafx.h"
#include "DemoDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DemoDialog::DemoDialog(BOOL bModal) : AcadSouiDialog(_T("layout:demo"), bModal)
{
}

DemoDialog::~DemoDialog()
{
}

void DemoDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DemoDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_UserEdit = FindChildByName2<SEdit>(L"edit_user");
	m_Edit11 = FindChildByName2<SEdit>(L"edit11");
	m_Img17 = FindChildByName2<SImageWnd>(L"img17");
	m_Listbox29 = FindChildByName2<SListBox>(L"listbox29");
	m_Richedit30 = FindChildByName2<SRichEdit>(L"richedit30");
	m_Richedit31 = FindChildByName2<SRichEdit>(L"richedit31");
	m_Listctrl45 = FindChildByName2<SListCtrl>(L"listctrl45");
	m_Tabctrl48 = FindChildByName2<STabCtrl>(L"tabctrl48");
	m_Tabctrl49 = FindChildByName2<STabCtrl>(L"tabctrl49");
	m_Tree1Treectrl = FindChildByName2<STreeCtrl>(L"tree1");
	m_Combox71 = FindChildByName2<SComboBox>(L"combobox71");
	m_Link73 = FindChildByName2<SLink>(L"link73");
	m_Radio75 = FindChildByName2<SRadioBox>(L"radio75");
	return 0;
}


void DemoDialog::OnButton12Click()
{
}

void DemoDialog::OnButton13Click()
{
}

void DemoDialog::OnButton32Click()
{
}

void DemoDialog::OnCombox71SelChanged(SOUI::EventArgs *pEvt)
{
	if(!m_bLayoutInited) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;

	// do something
}
