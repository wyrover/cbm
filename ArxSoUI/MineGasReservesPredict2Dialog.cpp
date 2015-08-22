#include "stdafx.h"
#include "MineGasReservesPredict2Dialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasReservesPredict2Dialog::MineGasReservesPredict2Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_gas_reserves_predict_2"), bModal)
{
}

MineGasReservesPredict2Dialog::~MineGasReservesPredict2Dialog()
{
}

void MineGasReservesPredict2Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineGasReservesPredict2Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_PumpWcEdit = FindChildByName2<SEdit>(L"pump_Wc");
	m_PumpKdEdit = FindChildByName2<SEdit>(L"pump_Kd");
	m_PumpK1Edit = FindChildByName2<SEdit>(L"pump_K1");
	m_PumpK2Edit = FindChildByName2<SEdit>(L"pump_K2");
	m_PumpK4Edit = FindChildByName2<SEdit>(L"pump_K4");
	m_PumpK3Edit = FindChildByName2<SEdit>(L"pump_K3");
	m_GasW0Edit = FindChildByName2<SEdit>(L"gas_W0");
	m_PumpMcEdit = FindChildByName2<SEdit>(L"pump_Mc");
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");

	initCoalDatas();
	fillCoalCombox();

	return 0;
}


void MineGasReservesPredict2Dialog::OnSaveButtonClick()
{
}

void MineGasReservesPredict2Dialog::OnPumpWcCaclButtonClick()
{
	ItemData* pData = (ItemData*)m_CoalCombox->GetItemData(m_CoalCombox->GetCurSel());
	if(pData == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, pData->id);
	if(coal == 0) return;

	//从界面提取数据进行计算
	double K1=0,K2=0,K3=0,K4=0,My=0,Mc=0;
	Utils::cstring_to_double((LPCTSTR)m_PumpK2Edit->GetWindowText(), K2);
	Utils::cstring_to_double((LPCTSTR)m_PumpK3Edit->GetWindowText(), K3);
	Utils::cstring_to_double((LPCTSTR)m_PumpK4Edit->GetWindowText(), K4);
	Utils::cstring_to_double((LPCTSTR)m_GasW0Edit->GetWindowText(), My);
	Utils::cstring_to_double((LPCTSTR)m_PumpMcEdit->GetWindowText(), Mc);

	if(My <= 0)
	{
		SMessageBox(GetSafeWnd(),_T("煤层原始瓦斯含量My的值必须大于0!!!"),_T("友情提示"),MB_OK);
	}
	else
	{
		K1 = K4*(My-Mc)/My;
		double W = 0; // 不知道从哪儿来???
		double Wc = K1*K2*K3*W;
		m_PumpK1Edit->SetWindowText(Utils::double_to_cstring(K1));
		m_PumpWcEdit->SetWindowText(Utils::double_to_cstring(Wc));

	}
}

void MineGasReservesPredict2Dialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
	// do something
	initCoalDatas();
	int coal_id = SComboBoxHelper::GetItemID(m_CoalCombox, nCurSel);
	if(coal_id == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	m_PumpKdEdit->SetWindowText(Utils::double_to_cstring(coal->pump_kd));
	m_PumpK1Edit->SetWindowText(Utils::double_to_cstring(coal->pump_k1));
	m_PumpK2Edit->SetWindowText(Utils::double_to_cstring(coal->pump_k2));
	m_PumpK3Edit->SetWindowText(Utils::double_to_cstring(coal->pump_k3));
	m_PumpK4Edit->SetWindowText(Utils::double_to_cstring(coal->pump_k4));
	m_GasW0Edit->SetWindowText(Utils::double_to_cstring(coal->gas_w0)); //煤层原始瓦斯含量
	m_PumpWcEdit->SetWindowText(Utils::double_to_cstring(coal->gas_wc2)); // 运出地面后残余瓦斯含量
	m_PumpWcEdit->SetWindowText(Utils::double_to_cstring(coal->pump_wc)); //煤层可抽瓦斯量
}

void MineGasReservesPredict2Dialog::OnDestroyWindow()
{
	//删除所有的附加数据
	SComboBoxHelper::Clear(m_CoalCombox);
	AcadSouiDialog::OnDestroyWindow();
}

void MineGasReservesPredict2Dialog::fillCoalCombox()
{
	MinePtr mine = DaoHelper::GetOnlineMine();
	if(mine == 0) return;

	StringArray coal_names;
	IntArray coal_ids;
	DaoHelper::GetCoalIds(mine->name, coal_ids);
	DaoHelper::GetCoalNames(mine->name, coal_names);

	SComboBoxHelper::Clear(m_CoalCombox);
	SComboBoxHelper::Append(m_CoalCombox, coal_names, coal_ids);
	SComboBoxHelper::Select(m_CoalCombox, 0);
}

void MineGasReservesPredict2Dialog::initCoalDatas()
{
	m_PumpKdEdit->SetWindowText(NULL);
	m_PumpK1Edit->SetWindowText(NULL);
	m_PumpK2Edit->SetWindowText(NULL);
	m_PumpK3Edit->SetWindowText(NULL);
	m_PumpK4Edit->SetWindowText(NULL);
	m_GasW0Edit->SetWindowText(NULL); //煤层原始瓦斯含量
	m_PumpWcEdit->SetWindowText(NULL); // 运出地面后残余瓦斯含量
	m_PumpWcEdit->SetWindowText(NULL); //煤层可抽瓦斯量
}