#include "stdafx.h"
#include "MineDesignDialog.h"
#include "SouiListHelper.h"
#include "NameDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineDesignDialog::MineDesignDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_design"), bModal)
{
	mine_id = 0;
}

MineDesignDialog::~MineDesignDialog()
{
}

void MineDesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineDesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_NameEdit = FindChildByName2<SEdit>(L"name");
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");
	m_WorkAreaCombox = FindChildByName2<SComboBox>(L"work_area");
	m_WsCombox = FindChildByName2<SComboBox>(L"ws");
	m_TwsCombox = FindChildByName2<SComboBox>(L"tws");

	initMineDatas();
	fillCoalCombox();

	return 0;
}

void MineDesignDialog::OnDelCoalButtonClick()
{
	CoalPtr coal = getCurSelCoal();
	if(coal == 0) return;

	//再删除采区
	if(coal->remove())
	{
		//从采区列表中删除
		SComboBoxHelper::DeleteCurSel(m_CoalCombox);
		SComboBoxHelper::Select(m_CoalCombox, 0);
		SMessageBox(GetSafeHwnd(),_T("删除煤层成功"),_T("友情提示"),MB_OK);
	}
	else
	{
		SMessageBox(GetSafeHwnd(),_T("删除煤层失败"),_T("友情提示"),MB_OK);
	}
}

void MineDesignDialog::OnAddCoalButtonClick()
{
	MinePtr mine = FIND_BY_ID(Mine, mine_id);
	if(mine == 0) return;

	NameDialog dlg(TRUE);
	dlg.SetWindowTitle(_T("新增煤层"));
	if(IDOK != dlg.Run(GetSafeHwnd())) return;

	CString name = dlg.name;
	if(name.IsEmpty()) return;

	if(m_CoalCombox->FindString(name) != -1)
	{
		CString msg;
		msg.Format(_T("煤层%s已存在!"), name);
		SMessageBox(GetSafeHwnd(),msg,_T("友情提示"),MB_OK);
	}
	else
	{
		//提交到数据库
		CoalPtr coal(new Coal);
		coal->name = name;
		coal->mine = mine;
		if(coal->save())
		{
			//插入到煤层列表列表
			int nItem = SComboBoxHelper::Add(m_CoalCombox, coal->name, coal->getID());
			SComboBoxHelper::Select(m_CoalCombox, nItem);
			SMessageBox(GetSafeHwnd(),_T("新增煤层成功"),_T("友情提示"),MB_OK);
		}
		else
		{
			SMessageBox(GetSafeHwnd(),_T("新增煤层失败"),_T("友情提示"),MB_OK);
		}
	}
}

void MineDesignDialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	//SComboBoxHelper::Clear(m_CoalCombox);
	SComboBoxHelper::Clear(m_WorkAreaCombox);
	//SComboBoxHelper::Clear(m_WsCombox);
	//SComboBoxHelper::Clear(m_TwsCombox);

	CoalPtr coal = getCurSelCoal();
	if(coal == 0) return;

	//填充采区列表
	RecordPtrListPtr lists = FIND_MANY(WorkArea, FKEY(Coal), coal->getStringID());
	if(lists != 0)
	{
		for(int i=0;i<lists->size();i++)
		{
			WorkAreaPtr work_area = DYNAMIC_POINTER_CAST(WorkArea, lists->at(i));
			SComboBoxHelper::Add(m_WorkAreaCombox, work_area->name, work_area->getID());
		}
		SComboBoxHelper::Select(m_WorkAreaCombox, 0);
	}
}

void MineDesignDialog::OnWorkAreaComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	//SComboBoxHelper::Clear(m_CoalCombox);
	//SComboBoxHelper::Clear(m_WorkAreaCombox);
	SComboBoxHelper::Clear(m_WsCombox);
	SComboBoxHelper::Clear(m_TwsCombox);

	// do something
	WorkAreaPtr work_area = getCurSelWorkArea();
	if(work_area == 0) return;

	//填充回采工作面列表
	RecordPtrListPtr ws_lists = FIND_MANY(WorkSurf, FKEY(WorkArea), work_area->getStringID());
	if(ws_lists != 0)
	{
		for(int i=0;i<ws_lists->size();i++)
		{
			WorkSurfPtr work_surf = DYNAMIC_POINTER_CAST(WorkSurf, ws_lists->at(i));
			SComboBoxHelper::Add(m_WsCombox, work_surf->name, work_surf->getID());
		}
		SComboBoxHelper::Select(m_WsCombox, 0);
	}

	//填充掘进工作面列表
	RecordPtrListPtr tws_lists = FIND_MANY(DrillingSurf, FKEY(WorkArea), work_area->getStringID());
	if(tws_lists != 0)
	{
		for(int i=0;i<tws_lists->size();i++)
		{
			DrillingSurfPtr drilling_surf = DYNAMIC_POINTER_CAST(DrillingSurf, tws_lists->at(i));
			SComboBoxHelper::Add(m_TwsCombox, drilling_surf->name, drilling_surf->getID());
		}
		SComboBoxHelper::Select(m_TwsCombox, 0);
	}	
}

void MineDesignDialog::OnDelWorkAreaButtonClick()
{
	WorkAreaPtr work_area = getCurSelWorkArea();
	if(work_area == 0) return;

	//再删除采区
	if(work_area->remove())
	{
		//从采区列表中删除
		SComboBoxHelper::DeleteCurSel(m_WorkAreaCombox);
		SComboBoxHelper::Select(m_WorkAreaCombox, 0);
		SMessageBox(GetSafeHwnd(),_T("删除采区成功"),_T("友情提示"),MB_OK);
	}
	else
	{
		SMessageBox(GetSafeHwnd(),_T("删除采区失败"),_T("友情提示"),MB_OK);
	}
}

void MineDesignDialog::OnAddWorkAreaButtonClick()
{
	CoalPtr coal = getCurSelCoal();
	if(coal == 0) return;

	NameDialog dlg(TRUE);
	dlg.SetWindowTitle(_T("新增采区"));
	if(IDOK != dlg.Run(GetSafeHwnd())) return;

	CString name = dlg.name;
	if(name.IsEmpty()) return;

	if(m_WorkAreaCombox->FindString(name) != -1)
	{
		CString msg;
		msg.Format(_T("采区名称%s已存在!"), name);
		SMessageBox(GetSafeHwnd(),msg,_T("友情提示"),MB_OK);
	}
	else
	{
		//提交到数据库
		WorkAreaPtr work_area(new WorkArea);
		work_area->name = name;
		work_area->coal = coal;
		if(work_area->save())
		{
			//插入到采区列表
			int nItem = SComboBoxHelper::Add(m_WorkAreaCombox, work_area->name, work_area->getID());
			SComboBoxHelper::Select(m_WorkAreaCombox, nItem);
			SMessageBox(GetSafeHwnd(),_T("新增采区成功"),_T("友情提示"),MB_OK);
		}
		else
		{
			SMessageBox(GetSafeHwnd(),_T("新增采区失败"),_T("友情提示"),MB_OK);
		}
	}
}

void MineDesignDialog::OnWsComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void MineDesignDialog::OnTwsComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void MineDesignDialog::OnDelWsButtonClick()
{
	WorkSurfPtr work_surf = getCurSelWs();
	if(work_surf == 0) return;

	//再删除采区
	if(work_surf->remove())
	{
		//从采区列表中删除
		SComboBoxHelper::DeleteCurSel(m_WsCombox);
		SComboBoxHelper::Select(m_WsCombox, 0);
		SMessageBox(GetSafeHwnd(),_T("删除回采工作面成功"),_T("友情提示"),MB_OK);
	}
	else
	{
		SMessageBox(GetSafeHwnd(),_T("删除回采工作面失败"),_T("友情提示"),MB_OK);
	}
}

void MineDesignDialog::OnAddWsButtonClick()
{
	WorkAreaPtr work_area = getCurSelWorkArea();
	if(work_area == 0) return;

	NameDialog dlg(TRUE);
	dlg.SetWindowTitle(_T("新增工作面"));
	if(IDOK != dlg.Run(GetSafeHwnd())) return;

	CString name = dlg.name;
	if(name.IsEmpty()) return;

	if(m_WsCombox->FindString(name) != -1)
	{
		CString msg;
		msg.Format(_T("回采工作面%s已存在!"), name);
		SMessageBox(GetSafeHwnd(),msg,_T("友情提示"),MB_OK);
	}
	else
	{
		//提交到数据库
		WorkSurfPtr work_surf(new WorkSurf);
		work_surf->name = name;
		work_surf->work_area = work_area;
		if(work_surf->save())
		{
			//插入到工作面列表
			int nItem = SComboBoxHelper::Add(m_WsCombox, work_surf->name, work_surf->getID());
			SComboBoxHelper::Select(m_WsCombox, nItem);
			SMessageBox(GetSafeHwnd(),_T("新增工作面成功"),_T("友情提示"),MB_OK);
		}
		else
		{
			SMessageBox(GetSafeHwnd(),_T("新增工作面失败"),_T("友情提示"),MB_OK);
		}
	}
}

void MineDesignDialog::OnDelTwsButtonClick()
{
	DrillingSurfPtr drilling_surf = getCurSelTws();
	if(drilling_surf == 0) return;

	//再删除采区
	if(drilling_surf->remove())
	{
		//从采区列表中删除
		SComboBoxHelper::DeleteCurSel(m_TwsCombox);
		SComboBoxHelper::Select(m_TwsCombox, 0);
		SMessageBox(GetSafeHwnd(),_T("删除掘进面成功"),_T("友情提示"),MB_OK);
	}
	else
	{
		SMessageBox(GetSafeHwnd(),_T("删除掘进面失败"),_T("友情提示"),MB_OK);
	}
}

void MineDesignDialog::OnAddTwsButtonClick()
{
	WorkAreaPtr work_area = getCurSelWorkArea();
	if(work_area == 0) return;

	NameDialog dlg(TRUE);
	dlg.SetWindowTitle(_T("新增掘进面"));
	if(IDOK != dlg.Run(GetSafeHwnd())) return;

	CString name = dlg.name;
	if(name.IsEmpty()) return;
	if(m_TwsCombox->FindString(name) != -1)
	{
		CString msg;
		msg.Format(_T("掘进工作面%s已存在!"), name);
		SMessageBox(GetSafeHwnd(),msg,_T("友情提示"),MB_OK);
	}
	else
	{
		//提交到数据库
		DrillingSurfPtr drilling_surf(new DrillingSurf);
		drilling_surf->name = name;
		drilling_surf->work_area = work_area;
		if(drilling_surf->save())
		{
			//插入到采区列表
			int nItem = SComboBoxHelper::Add(m_TwsCombox, drilling_surf->name, drilling_surf->getID());
			SComboBoxHelper::Select(m_TwsCombox, nItem);
			SMessageBox(GetSafeHwnd(),_T("新增掘进面成功"),_T("友情提示"),MB_OK);
		}
		else
		{
			SMessageBox(GetSafeHwnd(),_T("新增掘进面失败"),_T("友情提示"),MB_OK);
		}
	}
}

void MineDesignDialog::OnSaveButtonClick()
{
}

void MineDesignDialog::OnDestroyWindow()
{
	//删除所有的附加数据
	SComboBoxHelper::Clear(m_WorkAreaCombox);
	SComboBoxHelper::Clear(m_WsCombox);
	SComboBoxHelper::Clear(m_TwsCombox);
	SComboBoxHelper::Clear(m_CoalCombox);
	AcadSouiDialog::OnDestroyWindow();
}

void MineDesignDialog::initMineDatas()
{
	MinePtr mine = FIND_BY_ID(Mine, mine_id);
	if(mine == 0) return;

	m_NameEdit->SetWindowText(mine->name);
}

void MineDesignDialog::fillCoalCombox()
{
	SComboBoxHelper::Clear(m_CoalCombox);

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

CoalPtr MineDesignDialog::getCurSelCoal()
{
	int coal_id = SComboBoxHelper::GetCurSelItemID(m_CoalCombox);
	if(coal_id == 0) return CoalPtr();
	return FIND_BY_ID(Coal, coal_id);
}

WorkAreaPtr MineDesignDialog::getCurSelWorkArea()
{
	int work_area_id = SComboBoxHelper::GetCurSelItemID(m_WorkAreaCombox);
	if(work_area_id == 0) return WorkAreaPtr();
	return FIND_BY_ID(WorkArea, work_area_id);
}

DrillingSurfPtr MineDesignDialog::getCurSelTws()
{
	int tws_id = SComboBoxHelper::GetCurSelItemID(m_TwsCombox);
	if(tws_id == 0) return DrillingSurfPtr();
	return FIND_BY_ID(DrillingSurf, tws_id);
}

WorkSurfPtr MineDesignDialog::getCurSelWs()
{
	int ws_id = SComboBoxHelper::GetCurSelItemID(m_WsCombox);
	if(ws_id == 0) return WorkSurfPtr();
	return FIND_BY_ID(WorkSurf, ws_id);
}
