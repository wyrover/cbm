#include "stdafx.h"
#include "PoreFlowDeltaTDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PoreFlowDeltaTDialog::PoreFlowDeltaTDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow_delta_T"), bModal)
{
}

PoreFlowDeltaTDialog::~PoreFlowDeltaTDialog()
{
}

void PoreFlowDeltaTDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreFlowDeltaTDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TEdit = FindChildByName2<SEdit>(L"t");
	m_DeltaTEdit = FindChildByName2<SEdit>(L"delta_t");
	return 0;
}


void PoreFlowDeltaTDialog::OnSaveButtonClick()
{
}
