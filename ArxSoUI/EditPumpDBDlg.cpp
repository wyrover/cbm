#include "stdafx.h"
using namespace SOUI;

#include "MainDlg.h"
#include "SListCtrl2.h"

#include <controls.extend/FileHelper.h>
#include <controls.extend/SChatEdit.h>
#include <controls.extend/gif/SGifPlayer.h>
#include <controls.extend/reole/richeditole.h>

void CMainDlg::OnListCtrlDblClickEvent(SOUI::EventArgs *pEvt)
{
	EventLCDblClick *pEvtLCDblClick = (EventLCDblClick*)pEvt;
	int nCurSel = pEvtLCDblClick->nCurSel;
	SListCtrl2 *pList = (SListCtrl2*)pEvt->sender;
	if(nCurSel < 0 || nCurSel >=pList->GetColumnCount()) return;

	FindChildByName(L"typeEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 0));
	FindChildByName(L"factoryEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 1));
	FindChildByName(L"speedEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 2));
	FindChildByName(L"powerEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 3));
	FindChildByName(L"lengthEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 4));
	FindChildByName(L"widthEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 5));
	FindChildByName(L"heightEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 6));
	FindChildByName(L"weightEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 7));
	FindChildByName(L"absPEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 8));
	FindChildByName(L"maxPEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 9));
	FindChildByName(L"minPEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 10));
	FindChildByName(L"maxQEdit")->SetWindowText(pList->GetSubItemText(nCurSel, 11));
}