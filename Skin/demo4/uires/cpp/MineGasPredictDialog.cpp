#include "stdafx.h"
#include "MineGasPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasPredictDialog::MineGasPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_gas_predict"), bModal)
{
}

MineGasPredictDialog::~MineGasPredictDialog()
{
}

void MineGasPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineGasPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_K1GasEdit = FindChildByName2<SEdit>(L"K1_gas");
	m_QREdit = FindChildByName2<SEdit>(L"q_r");
	m_K2GasEdit = FindChildByName2<SEdit>(L"K2_gas");
	return 0;
}


void MineGasPredictDialog::OnK1HelpButtonClick()
{
}

void MineGasPredictDialog::OnSaveButtonClick()
{
}

void MineGasPredictDialog::OnK2HelpButtonClick()
{
}
