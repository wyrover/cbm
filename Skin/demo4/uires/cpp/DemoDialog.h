#pragma once
#include "AcadSouiDialog.h"

class DemoDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	DemoDialog(BOOL bModal = FALSE);
	~DemoDialog(void);

	/** 控件消息处理 */
protected:
	void OnButton12Click();
	void OnButton13Click();
	void OnButton32Click();
	void OnCombox71SelChanged(SOUI::EventArgs *pEvt);

	/** 菜单消息 */
protected:
	//处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	/** 窗口消息 */
protected:
	//对话框初始化过程
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);

	//控件消息映射表
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(_T("button12"), OnButton12Click)
		EVENT_NAME_COMMAND(_T("button13"), OnButton13Click)
		EVENT_NAME_COMMAND(_T("button32"), OnButton32Click)
		EVENT_NAME_HANDLER(_T("combobox71"), EVT_CB_SELCHANGE, OnCombox71SelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(DemoDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_UserEdit;
	SEdit* m_Edit11;
	SImageWnd* m_Img17;
	SListBox* m_Listbox29;
	SRichEdit* m_Richedit30;
	SRichEdit* m_Richedit31;
	SListCtrl* m_Listctrl45;
	STabCtrl* m_Tabctrl48;
	STabCtrl* m_Tabctrl49;
	STreeCtrl* m_Tree1Treectrl;
	SComboBox* m_Combox71;
	SLink* m_Link73;
	SRadioBox* m_Radio75;
};
