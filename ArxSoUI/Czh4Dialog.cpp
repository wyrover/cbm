#include "stdafx.h"
#include "Czh4Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

Czh4Dialog::Czh4Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_4"), bModal)
{
}

Czh4Dialog::~Czh4Dialog()
{
}

void Czh4Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh4Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_HEdit = FindChildByName2<SEdit>(L"h");
	return 0;
}


void Czh4Dialog::OnSaveButtonClick()
{
	AcadSouiDialog::OnOK();
}

void Czh4Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;
}
