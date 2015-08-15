#include "stdafx.h"
#include "HighDrillingSiteDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

HighDrillingSiteDialog::HighDrillingSiteDialog(BOOL bModal) : AcadSouiDialog(_T("layout:high_drilling_site"), bModal)
{
}

HighDrillingSiteDialog::~HighDrillingSiteDialog()
{
}

void HighDrillingSiteDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT HighDrillingSiteDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_L1Edit = FindChildByName2<SEdit>(L"L1");
	m_L2Edit = FindChildByName2<SEdit>(L"L2");
	m_LgEdit = FindChildByName2<SEdit>(L"Lg");
	m_AdjLayerListctrl = FindChildByName2<SListCtrl>(L"adj_layer");
	return 0;
}


void HighDrillingSiteDialog::OnSaveButtonClick()
{
}

void HighDrillingSiteDialog::OnAddButtonClick()
{
}

void HighDrillingSiteDialog::OnDelButtonClick()
{
}

void HighDrillingSiteDialog::OnModifyButtonClick()
{
}
