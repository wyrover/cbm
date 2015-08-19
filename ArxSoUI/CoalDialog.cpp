#include "stdafx.h"
#include "CoalDialog.h"
#include "DecisionDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

struct ItemData
{
	int id;
	int nItem;
};

CoalDialog::CoalDialog(BOOL bModal) : AcadSouiDialog(_T("layout:coal"), bModal)
{
}

CoalDialog::~CoalDialog()
{
}

void CoalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT CoalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_NumberEdit = FindChildByName2<SEdit>(L"number");
	m_FValueEdit = FindChildByName2<SEdit>(L"f_value");
	m_ThickEdit = FindChildByName2<SEdit>(L"thick");
	m_RankCombox = FindChildByName2<SComboBox>(L"rank");
	m_PressureEdit = FindChildByName2<SEdit>(L"pressure");
	m_GasContentEdit = FindChildByName2<SEdit>(L"gas_content");
	m_GasPenetrationEdit = FindChildByName2<SEdit>(L"gas_penetration");
	m_ConstComplexityCombox = FindChildByName2<SComboBox>(L"const_complexity");
	m_VarCoeffEdit = FindChildByName2<SEdit>(L"var_coeff");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_CavingZoneHeightEdit = FindChildByName2<SEdit>(L"caving_zone_height");
	m_ResAbundanceCombox = FindChildByName2<SComboBox>(L"res_abundance");
	m_LayerGapEdit = FindChildByName2<SEdit>(L"layer_gap");
	m_InfluenceFactorEdit = FindChildByName2<SEdit>(L"influence_factor");
	m_MineIndexEdit = FindChildByName2<SEdit>(L"mine_index");
	m_StabilityCombox = FindChildByName2<SComboBox>(L"stability");
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");

	initCoalDatas();
	fillCoalList();
	return 0;
}


void CoalDialog::OnNextButtonClick()
{
	AcadSouiDialog::OnOK();
	DecisionDialog* dlg = new DecisionDialog(FALSE);
	dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
}

void CoalDialog::OnCancelButtonClick()
{
	AcadSouiDialog::OnCancel();
}

void CoalDialog::OnSaveButtonClick()
{
	int nCurSel = m_CoalCombox->GetCurSel();
	ItemData* pData = (ItemData*)m_CoalCombox->GetItemData(nCurSel);
	if(pData == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, pData->id);
	if(coal == 0) return;

	Utils::cstring_to_double((LPCTSTR)m_ThickEdit->GetWindowText(), coal->thick); // 煤厚
	coal->rank = m_RankCombox->GetCurSel() + 1; // 煤阶
	Utils::cstring_to_double((LPCTSTR)m_PressureEdit->GetWindowText(), coal->pressure); // 储层压力
	Utils::cstring_to_double((LPCTSTR)m_GasContentEdit->GetWindowText(), coal->gas_content); // 含气量
	Utils::cstring_to_double((LPCTSTR)m_GasPenetrationEdit->GetWindowText(), coal->gas_penetration); // 渗透率
	Utils::cstring_to_double((LPCTSTR)m_FValueEdit->GetWindowText(), coal->f_value); // f值
	coal->res_abundance = m_ResAbundanceCombox->GetCurSel() + 1; // 煤层气储量丰度
	coal->complexity = m_ConstComplexityCombox->GetCurSel() + 1; // 构造复杂程度
	Utils::cstring_to_double((LPCTSTR)m_MineIndexEdit->GetWindowText(), coal->mine_index); // 可采性指数
	Utils::cstring_to_double((LPCTSTR)m_VarCoeffEdit->GetWindowText(), coal->var_coeff); // 变异系数
	coal->stability = m_StabilityCombox->GetCurSel() + 1; // 煤层稳定性
	Utils::cstring_to_double((LPCTSTR)m_DipAngleEdit->GetWindowText(), coal->dip_angle); // 煤层倾角
	Utils::cstring_to_double((LPCTSTR)m_CavingZoneHeightEdit->GetWindowText(), coal->czh); // 冒落带高度
	if(!coal->save()) return;

	SMessageBox(GetSafeWnd(),_T("更新成功!"),_T("友情提示"),MB_OK);
}

void CoalDialog::OnDelButtonClick()
{
	int nCurSel = m_CoalCombox->GetCurSel();
	ItemData* pData = (ItemData*)m_CoalCombox->GetItemData(nCurSel);
	if(pData == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, pData->id);
	if(coal == 0) return;

	if(coal->remove())
	{
		//删除煤层列表中的当前项
		delete pData;
		m_CoalCombox->DeleteString(nCurSel);

		if(m_CoalCombox->GetCount() > 0)
		{
			m_CoalCombox->SetCurSel(0);
		}
		else
		{
			initCoalDatas();
		}
	}
}

void CoalDialog::OnRankComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void CoalDialog::OnConstComplexityComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void CoalDialog::OnAddCoalButtonClick()
{
	CoalPtr coal(new Coal);
	//煤层关联到矿井
	coal->mine = DaoHelper::GetOnlineMine();
	if(coal->mine == 0)
	{
		SMessageBox(GetSafeWnd(),_T("煤层关联到矿井失败!!!"),_T("友情提示"),MB_OK);
		return ;
	}
	coal->name = m_NumberEdit->GetWindowText(); // 名称(编号)
	if(coal->name.IsEmpty())
	{
		SMessageBox(GetSafeWnd(),_T("必须填写煤层编号!!!"),_T("友情提示"),MB_OK);
		return ;
	}
	else if(isCoalExist(coal->name))
	{
		CString msg;
		msg.Format(_T("煤层%s已存在!!!"), coal->name);
		SMessageBox(GetSafeWnd(),msg,_T("友情提示"),MB_OK);
		return ;
	}

	Utils::cstring_to_double((LPCTSTR)m_ThickEdit->GetWindowText(), coal->thick); // 煤厚
	coal->rank = m_RankCombox->GetCurSel() + 1; // 煤阶
	Utils::cstring_to_double((LPCTSTR)m_PressureEdit->GetWindowText(), coal->pressure); // 储层压力
	Utils::cstring_to_double((LPCTSTR)m_GasContentEdit->GetWindowText(), coal->gas_content); // 含气量
	Utils::cstring_to_double((LPCTSTR)m_GasPenetrationEdit->GetWindowText(), coal->gas_penetration); // 渗透率
	Utils::cstring_to_double((LPCTSTR)m_FValueEdit->GetWindowText(), coal->f_value); // f值
	coal->res_abundance = m_ResAbundanceCombox->GetCurSel() + 1; // 煤层气储量丰度
	coal->complexity = m_ConstComplexityCombox->GetCurSel() + 1; // 构造复杂程度
	Utils::cstring_to_double((LPCTSTR)m_MineIndexEdit->GetWindowText(), coal->mine_index); // 可采性指数
	Utils::cstring_to_double((LPCTSTR)m_VarCoeffEdit->GetWindowText(), coal->var_coeff); // 变异系数
	coal->stability = m_StabilityCombox->GetCurSel() + 1; // 煤层稳定性
	Utils::cstring_to_double((LPCTSTR)m_DipAngleEdit->GetWindowText(), coal->dip_angle); // 煤层倾角
	Utils::cstring_to_double((LPCTSTR)m_CavingZoneHeightEdit->GetWindowText(), coal->czh); // 冒落带高度

	if(coal->save())
	{
		//添加到煤层列表中
		int nIndex = m_CoalCombox->GetCount();
		addCoalToListBox(coal->name, coal->getID(), nIndex);
		//切换当前煤层
		m_CoalCombox->SetCurSel(nIndex);

		//打印消息
		CString msg;
		msg.Format(_T("增加煤层成功!"));
		msg.AppendFormat(_T("新煤层id:%d"), coal->getID());
		SMessageBox(GetSafeWnd(),msg,_T("友情提示"),MB_OK);
	}
}

void CoalDialog::OnResAbundanceComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void CoalDialog::OnStabilityComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void CoalDialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
	ItemData* pData = (ItemData*)m_CoalCombox->GetItemData(nCurSel);
	if(pData == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, pData->id);
	if(coal == 0) return;

	m_NumberEdit->SetWindowText(coal->name);
	m_ThickEdit->SetWindowText(Utils::double_to_cstring(coal->thick));
	m_RankCombox->SetCurSel(coal->rank-1);
	m_PressureEdit->SetWindowText(Utils::double_to_cstring(coal->pressure));
	m_GasContentEdit->SetWindowText(Utils::double_to_cstring(coal->gas_content));
	m_GasPenetrationEdit->SetWindowText(Utils::double_to_cstring(coal->gas_penetration));
	m_FValueEdit->SetWindowText(Utils::double_to_cstring(coal->f_value));
	m_ResAbundanceCombox->SetCurSel(coal->res_abundance-1);
	m_ConstComplexityCombox->SetCurSel(coal->complexity-1);
	m_MineIndexEdit->SetWindowText(Utils::double_to_cstring(coal->mine_index));
	m_VarCoeffEdit->SetWindowText(Utils::double_to_cstring(coal->var_coeff));
	m_StabilityCombox->SetCurSel(coal->stability-1);
	m_DipAngleEdit->SetWindowText(Utils::double_to_cstring(coal->dip_angle));
	m_CavingZoneHeightEdit->SetWindowText(Utils::double_to_cstring(coal->czh));
}

void CoalDialog::OnDestroyWindow()
{
	//删除所有的附加数据
	int n = m_CoalCombox->GetCount();
	for(int i=0;i<n;i++)
	{
		ItemData* pData = (ItemData*)m_CoalCombox->GetItemData(i);
		delete pData;
	}
	AcadSouiDialog::OnDestroyWindow();
}

void CoalDialog::fillCoalList()
{
	MinePtr mine = DaoHelper::GetOnlineMine();
	if(mine == 0) return;

	StringArray coal_names;
	IntArray coal_ids;
	DaoHelper::GetCoalIds(mine->name, coal_ids);
	DaoHelper::GetCoalNames(mine->name, coal_names);

	m_CoalCombox->ResetContent();
	for(int i=0;i<coal_names.size();i++)
	{
		addCoalToListBox(coal_names[i], coal_ids[i], i);
	}
	m_CoalCombox->SetCurSel(0);
}

void CoalDialog::addCoalToListBox(const CString& name, int id, int i)
{
	m_CoalCombox->InsertItem(i, name, 0, 0);
	//附加数据
	ItemData* pData = new ItemData;
	pData->id = id;
	pData->nItem = i;
	m_CoalCombox->SetItemData(i, (LPARAM)pData);
}

bool CoalDialog::isCoalExist(const CString& name)
{
	return m_CoalCombox->FindString(name)!=-1;
}

void CoalDialog::initCoalDatas()
{
	m_CoalCombox->ResetContent();
	m_NumberEdit->SetWindowText(_T(""));
	m_ThickEdit->SetWindowText(_T(""));
	m_RankCombox->SetCurSel(-1);
	m_PressureEdit->SetWindowText(_T(""));
	m_GasContentEdit->SetWindowText(_T(""));
	m_GasPenetrationEdit->SetWindowText(_T(""));
	m_FValueEdit->SetWindowText(_T(""));
	m_ResAbundanceCombox->SetCurSel(-1);
	m_ConstComplexityCombox->SetCurSel(-1);
	m_MineIndexEdit->SetWindowText(_T(""));
	m_VarCoeffEdit->SetWindowText(_T(""));
	m_StabilityCombox->SetCurSel(-1);
	m_DipAngleEdit->SetWindowText(_T(""));
	m_CavingZoneHeightEdit->SetWindowText(_T(""));
}