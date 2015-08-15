#include "stdafx.h"
#include "TwsGasPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

TwsGasPredictDialog::TwsGasPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:tws_gas_predict"), bModal)
{
}

TwsGasPredictDialog::~TwsGasPredictDialog()
{
}

void TwsGasPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT TwsGasPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TwQ3Edit = FindChildByName2<SEdit>(L"tw_q3");
	m_TwQ4Edit = FindChildByName2<SEdit>(L"tw_q4");
	return 0;
}


void TwsGasPredictDialog::OnCacl1ButtonClick()
{
}

void TwsGasPredictDialog::OnCacl2ButtonClick()
{
}

void TwsGasPredictDialog::OnSaveButtonClick()
{
}
