#include "stdafx.h"
#include "Czh3Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

Czh3Dialog::Czh3Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_3"), bModal)
{
}

Czh3Dialog::~Czh3Dialog()
{
}

void Czh3Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh3Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_RockCombox = FindChildByName2<SComboBox>(L"rock");
	m_HwSumEdit = FindChildByName2<SEdit>(L"hw_sum");
	return 0;
}


void Czh3Dialog::OnSaveButtonClick()
{
	AcadSouiDialog::OnOK();
}

void Czh3Dialog::OnRockComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void Czh3Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;
}
