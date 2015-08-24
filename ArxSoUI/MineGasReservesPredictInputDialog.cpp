#include "stdafx.h"
#include "MineGasReservesPredictInputDialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasReservesPredictInputDialog::MineGasReservesPredictInputDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_gas_reserves_predict_input"), bModal)
{
	type = 0;
	mine_id = 0;
}

MineGasReservesPredictInputDialog::~MineGasReservesPredictInputDialog()
{
}

void MineGasReservesPredictInputDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineGasReservesPredictInputDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ResA1Edit = FindChildByName2<SEdit>(L"res_A1");
	m_GasX1Edit = FindChildByName2<SEdit>(L"gas_X1");
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");

	initCoalDatas();
	fillCoalCombox();

	return 0;
}

void MineGasReservesPredictInputDialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
	initCoalDatas();
	int coal_id = SComboBoxHelper::GetItemID(m_CoalCombox, nCurSel);
	if(coal_id == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	//更新到界面
	m_ResA1Edit->SetWindowText(Utils::double_to_cstring(coal->res_a1));
	m_GasX1Edit->SetWindowText(Utils::double_to_cstring(coal->gas_x1));
}

void MineGasReservesPredictInputDialog::OnSaveButtonClick()
{
	int coal_id = SComboBoxHelper::GetCurSelItemID(m_CoalCombox);
	if(coal_id == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	//从界面提取数据
	Utils::cstring_to_double((LPCTSTR)m_ResA1Edit->GetWindowText(), coal->res_a1);
	Utils::cstring_to_double((LPCTSTR)m_GasX1Edit->GetWindowText(), coal->gas_x1);

	//保存到数据库
	if(coal->save())
	{
		SMessageBox(GetSafeWnd(), _T("保存数据成功!!!"), _T("友情提示"), MB_OK);
	}
	else
	{
		SMessageBox(GetSafeWnd(), _T("保存数据失败!!!"), _T("友情提示"), MB_OK);
	}
}

void MineGasReservesPredictInputDialog::OnDestroyWindow()
{
	//删除所有的附加数据
	SComboBoxHelper::Clear(m_CoalCombox);
	AcadSouiDialog::OnDestroyWindow();
}

void MineGasReservesPredictInputDialog::initCoalDatas()
{
	m_ResA1Edit->SetWindowText(NULL);
	m_GasX1Edit->SetWindowText(NULL);
}

void MineGasReservesPredictInputDialog::fillCoalCombox()
{
	MinePtr mine = FIND_BY_ID(Mine, mine_id);
	if(mine == 0) return;

	StringArray coal_names;
	IntArray coal_ids;
	DaoHelper::GetCoalIds(mine->getID(), coal_ids);
	DaoHelper::GetCoalNames(mine->getID(), coal_names);

	SComboBoxHelper::Clear(m_CoalCombox);
	SComboBoxHelper::Append(m_CoalCombox, coal_names, coal_ids);
	SComboBoxHelper::Select(m_CoalCombox, 0);
}

CoalPtr MineGasReservesPredictInputDialog::getCurSelCoal()
{
	int coal_id = SComboBoxHelper::GetCurSelItemID(m_CoalCombox);
	if(coal_id == 0) return CoalPtr();
	return FIND_BY_ID(Coal, coal_id);
}
