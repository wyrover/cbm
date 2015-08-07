#pragma once

#include "AcadSouiDialog.h"

/** 
 * 注册对话框.
 * 有2种形态:模态对话框和非模态对话框,通过构造函数的参数bModal控制
 */
class RegDlg : public AcadSouiDialog
{
public:
    RegDlg(BOOL bModal = FALSE);
    ~RegDlg(void);
    
	/** 控件消息处理 */
protected:
	//注册
	void OnReg();
	void OnSelChanged(SOUI::EventArgs *pEvt);

	/** 菜单消息 */
protected:
	//处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	/** 窗口消息 */
protected:
	//对话框初始化过程
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);

    EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(_T("btn_reg"), OnReg)
		EVENT_NAME_HANDLER(L"mine_base",EVT_CB_SELCHANGE,OnSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
    EVENT_MAP_END()

	//HOST消息及响应函数映射表
	BEGIN_MSG_MAP_EX(RegDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
};

