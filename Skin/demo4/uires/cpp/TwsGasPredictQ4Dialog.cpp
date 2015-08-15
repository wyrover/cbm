#include "stdafx.h"
#include "TwsGasPredictQ4Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

TwsGasPredictQ4Dialog::TwsGasPredictQ4Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:tws_gas_predict_q4"), bModal)
{
}

TwsGasPredictQ4Dialog::~TwsGasPredictQ4Dialog()
{
}

void TwsGasPredictQ4Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT TwsGasPredictQ4Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_GasW0Edit = FindChildByName2<SEdit>(L"gas_W0");
	m_TwSEdit = FindChildByName2<SEdit>(L"tw_S");
	m_TwVEdit = FindChildByName2<SEdit>(L"tw_V");
	m_CoalREdit = FindChildByName2<SEdit>(L"coal_r");
	m_PumpMcEdit = FindChildByName2<SEdit>(L"pump_Mc");
	m_TwQ4Edit = FindChildByName2<SEdit>(L"tw_q4");
	return 0;
}


void TwsGasPredictQ4Dialog::OnSaveButtonClick()
{
}
