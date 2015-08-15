#include "stdafx.h"
#include "PoreFlowDeltaPDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PoreFlowDeltaPDialog::PoreFlowDeltaPDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow_delta_p"), bModal)
{
}

PoreFlowDeltaPDialog::~PoreFlowDeltaPDialog()
{
}

void PoreFlowDeltaPDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreFlowDeltaPDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_PTestEdit = FindChildByName2<SEdit>(L"P_test");
	m_PCurEdit = FindChildByName2<SEdit>(L"P_cur");
	m_PTEdit = FindChildByName2<SEdit>(L"PT");
	m_DeltaPEdit = FindChildByName2<SEdit>(L"delta_p");
	return 0;
}


void PoreFlowDeltaPDialog::OnSaveButtonClick()
{
}
