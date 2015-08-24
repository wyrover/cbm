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
	mine_id = 0;
	W = 0;
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
	m_GasWc2Edit = FindChildByName2<SEdit>(L"gas_Wc2");

	initDatas();

	return 0;
}


void MineGasReservesPredict2Dialog::OnSaveButtonClick()
{
	MinePtr mine = FIND_BY_ID(Mine, mine_id);
	if(mine == 0) return;

	//从界面提取数据进行计算
	double K1=0,K2=0,K3=0,K4=0,My=0,Mc=0;
	Utils::cstring_to_double((LPCTSTR)m_PumpK2Edit->GetWindowText(), K2);
	Utils::cstring_to_double((LPCTSTR)m_PumpK3Edit->GetWindowText(), K3);
	Utils::cstring_to_double((LPCTSTR)m_PumpK4Edit->GetWindowText(), K4);
	Utils::cstring_to_double((LPCTSTR)m_GasW0Edit->GetWindowText(), My);
	Utils::cstring_to_double((LPCTSTR)m_GasWc2Edit->GetWindowText(), Mc);

	if(My <= 0)
	{
		SMessageBox(GetSafeWnd(),_T("煤层原始瓦斯含量My的值必须大于0!!!"),_T("友情提示"),MB_OK);
	}
	else
	{
		//计算可抽瓦斯量
		K1 = K4*(My-Mc)/My;
		double Wc = K1*K2*K3*W;
		mine->pump_k = K1*K2*K3;
		mine->pump_k1 = K1;
		mine->pump_k1 = K2;
		mine->pump_k1 = K3;
		mine->pump_k4 = K4;
		mine->pump_wc = Wc;
		mine->gas_w0 = My;
		mine->gas_wc2 = Mc;
		//保存到数据库
		if(mine->save())
		{
			SMessageBox(GetSafeWnd(),_T("保存数据成功!"),_T("友情提示"),MB_OK);
		}
		else
		{
			SMessageBox(GetSafeWnd(),_T("保存数据失败!"),_T("友情提示"),MB_OK);
		}
	}
}

void MineGasReservesPredict2Dialog::OnCaclButtonClick()
{
	MinePtr mine = FIND_BY_ID(Mine, mine_id);
	if(mine == 0) return;

	//从界面提取数据进行计算
	double K1=0,K2=0,K3=0,K4=0,My=0,Mc=0;
	Utils::cstring_to_double((LPCTSTR)m_PumpK2Edit->GetWindowText(), K2);
	Utils::cstring_to_double((LPCTSTR)m_PumpK3Edit->GetWindowText(), K3);
	Utils::cstring_to_double((LPCTSTR)m_PumpK4Edit->GetWindowText(), K4);
	Utils::cstring_to_double((LPCTSTR)m_GasW0Edit->GetWindowText(), My);
	Utils::cstring_to_double((LPCTSTR)m_GasWc2Edit->GetWindowText(), Mc);

	if(My <= 0)
	{
		SMessageBox(GetSafeWnd(),_T("煤层原始瓦斯含量My的值必须大于0!!!"),_T("友情提示"),MB_OK);
	}
	else
	{
		K1 = K4*(My-Mc)/My;
		double Wc = K1*K2*K3*W;
		m_PumpK1Edit->SetWindowText(Utils::double_to_cstring(K1));
	}
}

void MineGasReservesPredict2Dialog::initDatas()
{
	m_PumpKdEdit->SetWindowText(NULL);
	m_PumpK1Edit->SetWindowText(NULL);
	m_PumpK2Edit->SetWindowText(NULL);
	m_PumpK3Edit->SetWindowText(NULL);
	m_PumpK4Edit->SetWindowText(NULL);
	m_GasW0Edit->SetWindowText(NULL); //煤层原始瓦斯含量
	m_GasWc2Edit->SetWindowText(NULL); // 运出地面后残余瓦斯含量
	m_PumpWcEdit->SetWindowText(NULL); //煤层可抽瓦斯量
}
