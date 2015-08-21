#include "stdafx.h"
#include "DifficultEvalDialog.h"
#include "SComboxHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DifficultEvalDialog::DifficultEvalDialog(BOOL bModal) : AcadSouiDialog(_T("layout:difficult_eval"), bModal)
{
}

DifficultEvalDialog::~DifficultEvalDialog()
{
}

void DifficultEvalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DifficultEvalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_PermeabilityKEdit = FindChildByName2<SEdit>(L"permeability_k");
	m_DecayAlphaEdit = FindChildByName2<SEdit>(L"decay_alpha");
	m_PermeabilityLambdaEdit = FindChildByName2<SEdit>(L"permeability_lambda");
	m_EvalDifficultCombox = FindChildByName2<SComboBox>(L"eval_difficult");
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");

	initCoalDatas();
	fillCoalCombox();

	return 0;
}


void DifficultEvalDialog::OnCancelButtonClick()
{
	AcadSouiDialog::OnCancel();
}

void DifficultEvalDialog::OnEvalButtonClick()
{
	ItemData* pData = (ItemData*)m_CoalCombox->GetItemData(m_CoalCombox->GetCurSel());
	if(pData == 0) return;
	CoalPtr coal = FIND_BY_ID(Coal, pData->id);
	if(coal == 0) return;

	//提取数据
	Utils::cstring_to_double((LPCTSTR)m_DecayAlphaEdit->GetWindowText(), coal->decay_alpha);
	Utils::cstring_to_double((LPCTSTR)m_PermeabilityLambdaEdit->GetWindowText(), coal->permeability_lambda);
	Utils::cstring_to_double((LPCTSTR)m_PermeabilityKEdit->GetWindowText(), coal->permeability_k);
	
	//进行评价
	//根据钻孔流量衰减系数 和 煤层透气性系数进行评价

	//保存到数据库
	if(coal->save())
	{
		SMessageBox(GetSafeWnd(),_T("更新数据成功(评价方法尚不明确,有问题!!!)"),_T("友情提示"),MB_OK);
	}
}

void DifficultEvalDialog::OnEvalProofButtonClick()
{
	SMessageBox(GetSafeWnd(),_T("弹出评价划分依据(尚未实现!!)"),_T("友情提示"),MB_OK);
}

void DifficultEvalDialog::OnEvalDifficultComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void DifficultEvalDialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
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

	m_DecayAlphaEdit->SetWindowText(Utils::double_to_cstring(coal->decay_alpha));
	m_PermeabilityLambdaEdit->SetWindowText(Utils::double_to_cstring(coal->permeability_lambda));
	m_PermeabilityKEdit->SetWindowText(Utils::double_to_cstring(coal->permeability_k));
	m_EvalDifficultCombox->SetCurSel(coal->eval_difficult-1);
}

void DifficultEvalDialog::OnDestroyWindow()
{
	//删除所有的附加数据
	SComboBoxHelper::Clear(m_CoalCombox);
	AcadSouiDialog::OnDestroyWindow();
}

void DifficultEvalDialog::fillCoalCombox()
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

void DifficultEvalDialog::initCoalDatas()
{
	m_DecayAlphaEdit->SetWindowText(NULL);
	m_PermeabilityKEdit->SetWindowText(NULL);
	m_PermeabilityLambdaEdit->SetWindowText(NULL);
	m_EvalDifficultCombox->SetCurSel(-1);
}