#include "stdafx.h"
#include "MineGasReservesPredictDialog.h"
#include "MineGasReservesPredict1Dialog.h"
#include "MineGasReservesPredict2Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasReservesPredictDialog::MineGasReservesPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_gas_reserves_predict"), bModal)
{
}

MineGasReservesPredictDialog::~MineGasReservesPredictDialog()
{
}

void MineGasReservesPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineGasReservesPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ReserveGasEdit = FindChildByName2<SEdit>(L"reserve_gas");
	m_PumpWcEdit = FindChildByName2<SEdit>(L"pump_Wc");


	return 0;
}


void MineGasReservesPredictDialog::OnSaveButtonClick()
{
	MinePtr mine = DaoHelper::GetOnlineMine();
	if(mine == 0) return;

	Utils::cstring_to_double((LPCTSTR)m_ReserveGasEdit->GetWindowText(), mine->reserve_gas);
	Utils::cstring_to_double((LPCTSTR)m_PumpWcEdit->GetWindowText(), mine->pump_wc);

	if(mine->save())
	{
		SMessageBox(GetSafeWnd(),_T("更新数据成功!"),_T("友情提示"),MB_OK);
	}
}

void MineGasReservesPredictDialog::OnGasCaclButtonClick()
{
	MineGasReservesPredict1Dialog dlg(TRUE);
	dlg.Run(GetSafeWnd());

	//重新计算结果
	MinePtr mine = DaoHelper::GetOnlineMine();
	if(mine == 0) return;

	//更新界面
	m_ReserveGasEdit->SetWindowText(Utils::double_to_cstring(mine->reserve_gas));
}

void MineGasReservesPredictDialog::OnPumpWcCaclButtonClick()
{
	MineGasReservesPredict2Dialog dlg(TRUE);
	dlg.Run(GetSafeWnd());

	//重新计算结果
	MinePtr mine = DaoHelper::GetOnlineMine();
	if(mine == 0) return;

	//更新界面
	m_PumpWcEdit->SetWindowText(Utils::double_to_cstring(mine->pump_wc));
}

void MineGasReservesPredictDialog::fillMineDatas()
{
	MinePtr mine = DaoHelper::GetOnlineMine();
	if(mine == 0) return;

	m_ReserveGasEdit->SetWindowText(Utils::double_to_cstring(mine->reserve_gas));
	m_PumpWcEdit->SetWindowText(Utils::double_to_cstring(mine->pump_wc));
}