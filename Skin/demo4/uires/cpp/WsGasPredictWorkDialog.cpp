#include "stdafx.h"
#include "WsGasPredictWorkDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

WsGasPredictWorkDialog::WsGasPredictWorkDialog(BOOL bModal) : AcadSouiDialog(_T("layout:ws_gas_predict_work"), bModal)
{
}

WsGasPredictWorkDialog::~WsGasPredictWorkDialog()
{
}

void WsGasPredictWorkDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT WsGasPredictWorkDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_CoalThickEdit = FindChildByName2<SEdit>(L"coal_thick");
	m_WsK1Edit = FindChildByName2<SEdit>(L"ws_K1");
	m_WsK2Edit = FindChildByName2<SEdit>(L"ws_K2");
	m_K3Edit = FindChildByName2<SEdit>(L"K3");
	m_MineHeightEdit = FindChildByName2<SEdit>(L"mine_height");
	m_TwQ4Edit = FindChildByName2<SEdit>(L"tw_q4");
	m_PumpMcEdit = FindChildByName2<SEdit>(L"pump_Mc");
	m_QREdit = FindChildByName2<SEdit>(L"q_r");
	m_KfEdit = FindChildByName2<SEdit>(L"Kf");
	return 0;
}


void WsGasPredictWorkDialog::OnSaveButtonClick()
{
}

void WsGasPredictWorkDialog::OnK3CaclButtonClick()
{
}

void WsGasPredictWorkDialog::OnKfCaclButtonClick()
{
}
