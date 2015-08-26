#include "stdafx.h"
#include "DesignDialog.h"
#include "DesignP11Dialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DesignDialog::DesignDialog(BOOL bModal) : AcadSouiDialog(_T("layout:design"), bModal)
{
	mine_id = 0;
}

DesignDialog::~DesignDialog()
{
}

void DesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");

	fillCoalCombox();

	return 0;
}


void DesignDialog::OnP11ButtonClick()
{
	int coal_id = SComboBoxHelper::GetCurSelItemID(m_CoalCombox);
	if(coal_id == 0)
	{
		SMessageBox(GetSafeHwnd(),_T("请选择一个【煤层】进行抽采设计!!!"),_T("友情提示"),MB_OK);
		return;
	}

	AcadSouiDialog::OnOK();
	DesignP11Dialog* dlg = new DesignP11Dialog(TRUE);
	dlg->coal_id = coal_id;
	dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
}

void DesignDialog::OnP12ButtonClick()
{
}

void DesignDialog::OnP13ButtonClick()
{
}

void DesignDialog::OnP21ButtonClick()
{
}

void DesignDialog::OnP22ButtonClick()
{
}

void DesignDialog::OnP23ButtonClick()
{
}

void DesignDialog::OnP24ButtonClick()
{
}

void DesignDialog::OnP25ButtonClick()
{
}

void DesignDialog::OnP31ButtonClick()
{
}

void DesignDialog::OnP32ButtonClick()
{
}

void DesignDialog::OnP33ButtonClick()
{
}

void DesignDialog::OnP34ButtonClick()
{
}

void DesignDialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void DesignDialog::OnDestroyWindow()
{
	//删除所有的附加数据
	SComboBoxHelper::Clear(m_CoalCombox);
	AcadSouiDialog::OnDestroyWindow();
}

void DesignDialog::fillCoalCombox()
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