#include "stdafx.h"
#include "PoreFlowBDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PoreFlowBDialog::PoreFlowBDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow_b"), bModal)
{
}

PoreFlowBDialog::~PoreFlowBDialog()
{
}

void PoreFlowBDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreFlowBDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_XEdit = FindChildByName2<SEdit>(L"X");
	m_BEdit = FindChildByName2<SEdit>(L"b");
	return 0;
}


void PoreFlowBDialog::OnSaveButtonClick()
{
}
