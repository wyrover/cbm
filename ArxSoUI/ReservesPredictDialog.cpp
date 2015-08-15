#include "stdafx.h"
#include "ReservesPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

ReservesPredictDialog::ReservesPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:reserves_predict"), bModal)
{
}

ReservesPredictDialog::~ReservesPredictDialog()
{
}

void ReservesPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT ReservesPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ReserveGasEdit = FindChildByName2<SEdit>(L"reserve_gas");
	m_ReserveW1Edit = FindChildByName2<SEdit>(L"reserve_w1");
	m_ReserveW2Edit = FindChildByName2<SEdit>(L"reserve_w2");
	m_ReserveW3Edit = FindChildByName2<SEdit>(L"reserve_w3");
	m_PumpWcEdit = FindChildByName2<SEdit>(L"pump_Wc");
	m_PumpKdEdit = FindChildByName2<SEdit>(L"pump_Kd");
	m_PumpK1Edit = FindChildByName2<SEdit>(L"pump_K1");
	m_PumpK2Edit = FindChildByName2<SEdit>(L"pump_K2");
	m_PumpK4Edit = FindChildByName2<SEdit>(L"pump_K4");
	m_PumpK3Edit = FindChildByName2<SEdit>(L"pump_K3");
	m_PumpMyEdit = FindChildByName2<SEdit>(L"pump_My");
	m_PumpMcEdit = FindChildByName2<SEdit>(L"pump_Mc");
	return 0;
}


void ReservesPredictDialog::OnSaveButtonClick()
{
}
