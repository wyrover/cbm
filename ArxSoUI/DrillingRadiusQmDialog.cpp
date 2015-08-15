#include "stdafx.h"
#include "DrillingRadiusQmDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DrillingRadiusQmDialog::DrillingRadiusQmDialog(BOOL bModal) : AcadSouiDialog(_T("layout:drilling_radius_qm"), bModal)
{
}

DrillingRadiusQmDialog::~DrillingRadiusQmDialog()
{
}

void DrillingRadiusQmDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DrillingRadiusQmDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_K1Edit = FindChildByName2<SEdit>(L"K1");
	m_RhoEdit = FindChildByName2<SEdit>(L"rho");
	m_AEdit = FindChildByName2<SEdit>(L"a");
	m_TEdit = FindChildByName2<SEdit>(L"t");
	m_Edit12 = FindChildByName2<SEdit>(L"edit12");
	m_QmEdit = FindChildByName2<SEdit>(L"Qm");
	m_Q0Edit = FindChildByName2<SEdit>(L"q0");
	m_REdit = FindChildByName2<SEdit>(L"R");
	return 0;
}


void DrillingRadiusQmDialog::OnSaveButtonClick()
{
}
