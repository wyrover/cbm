#pragma once
#include "AcadSouiDialog.h"

class AboutDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	AboutDialog(BOOL bModal = FALSE);
	~AboutDialog(void);

	/** 控件消息处理 */
protected:
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
		EVENT_NAME_HANDLER(_T("combobox71"), EVT_CB_SELCHANGE, OnCombox71SelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(AboutDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SComboBox* m_Combox71;
	SCheckBox* m_Check72;
	SLink* m_Link73;
	SCheckBox* m_Check74;
	SRadioBox* m_Radio75;
};
