#include "stdafx.h"
#include "PoreFlowKDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PoreFlowKDialog::PoreFlowKDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow_K"), bModal)
{
}

PoreFlowKDialog::~PoreFlowKDialog()
{
}

void PoreFlowKDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreFlowKDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_A0Edit = FindChildByName2<SEdit>(L"a0");
	m_DEdit = FindChildByName2<SEdit>(L"D");
	m_D1Edit = FindChildByName2<SEdit>(L"d1");
	m_KEdit = FindChildByName2<SEdit>(L"K");
	return 0;
}


void PoreFlowKDialog::OnSaveButtonClick()
{
}
