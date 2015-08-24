#include "stdafx.h"
#include "Czh1Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

Czh1Dialog::Czh1Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_1"), bModal)
{
	coal_id = 0;
}

Czh1Dialog::~Czh1Dialog()
{
}

void Czh1Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh1Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_CzkEdit = FindChildByName2<SEdit>(L"czk");
	return 0;
}


void Czh1Dialog::OnSaveButtonClick()
{
	AcadSouiDialog::OnOK();
}

void Czh1Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;
}
