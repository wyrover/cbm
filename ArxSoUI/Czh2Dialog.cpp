#include "stdafx.h"
#include "Czh2Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

Czh2Dialog::Czh2Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_2"), bModal)
{
	coal_id = 0;
}

Czh2Dialog::~Czh2Dialog()
{
}

void Czh2Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh2Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_CzkEdit = FindChildByName2<SEdit>(L"czk");
	m_CzwEdit = FindChildByName2<SEdit>(L"czw");
	return 0;
}


void Czh2Dialog::OnSaveButtonClick()
{
	AcadSouiDialog::OnOK();
}

void Czh2Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;
}
