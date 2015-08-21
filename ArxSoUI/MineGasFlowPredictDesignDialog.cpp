#include "stdafx.h"
#include "MineGasFlowPredictDesignDialog.h"
#include "NameDialog.h"
#include "SComboxHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasFlowPredictDesignDialog::MineGasFlowPredictDesignDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_gas_flow_predict_design"), bModal)
{
}

MineGasFlowPredictDesignDialog::~MineGasFlowPredictDesignDialog()
{
}

void MineGasFlowPredictDesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineGasFlowPredictDesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_WsQrEdit = FindChildByName2<SEdit>(L"ws_qr");
	m_WsAEdit = FindChildByName2<SEdit>(L"ws_A");
	m_TwsQaEdit = FindChildByName2<SEdit>(L"tws_qa");
	m_WsCombox = FindChildByName2<SComboBox>(L"ws");
	m_TwsCombox = FindChildByName2<SComboBox>(L"tws");

	initWsDatas();
	initTwsDatas();
	fillWsCombox();
	fillTwsCombox();

	return 0;
}


void MineGasFlowPredictDesignDialog::OnSaveButtonClick()
{
	//保存当前工作面的数据
	WorkSurfPtr work_surf = getCurSelWs();
	if(work_surf == 0) return;

	Utils::cstring_to_double((LPCTSTR)m_WsAEdit->GetWindowText(), work_surf->a);
	Utils::cstring_to_double((LPCTSTR)m_WsQrEdit->GetWindowText(), work_surf->qr);
	if(!work_surf->save()) return;

	DrillingSurfPtr drilling_surf = getCurSelTws();
	if(drilling_surf == 0) return;

	Utils::cstring_to_double((LPCTSTR)m_TwsQaEdit->GetWindowText(), drilling_surf->qa);
	if(!drilling_surf->save()) return;

	SMessageBox(GetSafeWnd(),_T("保存数据成功!"),_T("友情提示"),MB_OK);
}

void MineGasFlowPredictDesignDialog::OnWsComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void MineGasFlowPredictDesignDialog::OnTwsComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void MineGasFlowPredictDesignDialog::OnDelWsButtonClick()
{
	WorkSurfPtr work_surf = getCurSelWs();
	if(work_surf == 0) return;

	//从数据库中删除
	if(work_surf->remove())
	{
		//从采区列表中删除
		SComboBoxHelper::DeleteCurSel(m_WsCombox);
		SComboBoxHelper::Select(m_WsCombox, 0);
		if(m_WsCombox->GetCount() == 0)
		{
			initWsDatas();
		}
	}
}

void MineGasFlowPredictDesignDialog::OnAddWsButtonClick()
{
	NameDialog dlg(TRUE);
	dlg.SetWindowTitle(_T("新增工作面"));
	dlg.Run(GetSafeWnd());
	CString name = dlg.name;

	if(name.IsEmpty()) return;
	if(m_WsCombox->FindString(name) != -1)
	{
		CString msg;
		msg.Format(_T("回采工作面%s已存在!"), name);
		SMessageBox(GetSafeWnd(),msg,_T("友情提示"),MB_OK);
	}
	else
	{
		//提交到数据库
		WorkSurfPtr work_surf(new WorkSurf);
		work_surf->name = name;
		work_surf->work_area = FIND_BY_ID(WorkArea, work_area_id);
		if(work_surf->save())
		{
			//插入到采区列表
			int nItem = SComboBoxHelper::Add(m_WsCombox, work_surf->name, work_surf->getID());
			SComboBoxHelper::Select(m_WsCombox, nItem);
		}
	}
}

void MineGasFlowPredictDesignDialog::OnDelTwsButtonClick()
{
	DrillingSurfPtr drilling_surf = getCurSelTws();
	if(drilling_surf == 0) return;

	//从数据库中删除
	if(drilling_surf->remove())
	{
		//从采区列表中删除
		SComboBoxHelper::DeleteCurSel(m_TwsCombox);
		SComboBoxHelper::Select(m_TwsCombox, 0);
		if(m_TwsCombox->GetCount() == 0)
		{
			initTwsDatas();
		}
	}
}

void MineGasFlowPredictDesignDialog::OnAddTwsButtonClick()
{
	NameDialog dlg(TRUE);
	dlg.SetWindowTitle(_T("新增掘进面"));
	dlg.Run(GetSafeWnd());
	CString name = dlg.name;

	if(name.IsEmpty()) return;
	if(m_TwsCombox->FindString(name) != -1)
	{
		CString msg;
		msg.Format(_T("掘进工作面%s已存在!"), name);
		SMessageBox(GetSafeWnd(),msg,_T("友情提示"),MB_OK);
	}
	else
	{
		//提交到数据库
		DrillingSurfPtr drilling_surf(new DrillingSurf);
		drilling_surf->name = name;
		drilling_surf->work_area = FIND_BY_ID(WorkArea, work_area_id);
		if(drilling_surf->save())
		{
			//插入到采区列表
			int nItem = SComboBoxHelper::Add(m_TwsCombox, drilling_surf->name, drilling_surf->getID());
			SComboBoxHelper::Select(m_TwsCombox, nItem);
		}
	}
}

void MineGasFlowPredictDesignDialog::OnDestroyWindow()
{
	//删除所有的附加数据
	SComboBoxHelper::Clear(m_WsCombox);
	SComboBoxHelper::Clear(m_TwsCombox);
	AcadSouiDialog::OnDestroyWindow();
}

void MineGasFlowPredictDesignDialog::initWsDatas()
{
	m_WsAEdit->SetWindowText(NULL);
	m_WsQrEdit->SetWindowText(NULL);
}

void MineGasFlowPredictDesignDialog::initTwsDatas()
{
	m_TwsQaEdit->SetWindowText(NULL);
}

void MineGasFlowPredictDesignDialog::fillWsCombox()
{
	SComboBoxHelper::Clear(m_WsCombox);
	RecordPtrListPtr lists = FIND_MANY(WorkSurf, FKEY(WorkArea), Utils::int_to_cstring(work_area_id));
	if(lists == 0) return;

	for(int i=0;i<lists->size();i++)
	{
		WorkSurfPtr work_surf = DYNAMIC_POINTER_CAST(WorkSurf, lists->at(i));
		if(work_surf == 0) continue;

		SComboBoxHelper::Add(m_WsCombox, work_surf->name, work_surf->getID());
	}
	SComboBoxHelper::Select(m_WsCombox, 0);
}

void MineGasFlowPredictDesignDialog::fillTwsCombox()
{
	SComboBoxHelper::Clear(m_TwsCombox);
	RecordPtrListPtr lists = FIND_MANY(DrillingSurf, FKEY(WorkArea), Utils::int_to_cstring(work_area_id));
	if(lists == 0) return;

	for(int i=0;i<lists->size();i++)
	{
		DrillingSurfPtr drilling_surf = DYNAMIC_POINTER_CAST(DrillingSurf, lists->at(i));
		if(drilling_surf == 0) continue;

		SComboBoxHelper::Add(m_TwsCombox, drilling_surf->name, drilling_surf->getID());
	}
	SComboBoxHelper::Select(m_TwsCombox, 0);
}

WorkSurfPtr MineGasFlowPredictDesignDialog::getCurSelWs()
{
	int ws_id = SComboBoxHelper::GetCurSelItemID(m_WsCombox);
	if(ws_id == 0) return WorkSurfPtr();
	return FIND_BY_ID(WorkSurf, ws_id);
}

DrillingSurfPtr MineGasFlowPredictDesignDialog::getCurSelTws()
{
	int tws_id = SComboBoxHelper::GetCurSelItemID(m_TwsCombox);
	if(tws_id == 0) return DrillingSurfPtr();
	return FIND_BY_ID(DrillingSurf, tws_id);
}