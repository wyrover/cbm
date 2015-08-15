#include "stdafx.h"
#include "WsGasPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

WsGasPredictDialog::WsGasPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:ws_gas_predict"), bModal)
{
}

WsGasPredictDialog::~WsGasPredictDialog()
{
}

void WsGasPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT WsGasPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_QREdit = FindChildByName2<SEdit>(L"q_r");
	m_Radio68 = FindChildByName2<SRadioBox>(L"radio68");
	m_Radio69 = FindChildByName2<SRadioBox>(L"radio69");
	return 0;
}


void WsGasPredictDialog::OnWorkCacllButtonClick()
{
}

void WsGasPredictDialog::OnAdjCaclButtonClick()
{
}

void WsGasPredictDialog::OnSaveButtonClick()
{
}
