#pragma once

#include "AcadSouiDialog.h"

/** 
 * 登录对话框.
 * 有2种形态:模态对话框和非模态对话框,通过构造函数的参数bModal控制
 */
class LoginDlg : public AcadSouiDialog
{
public:
    LoginDlg(BOOL bModal = FALSE);
    ~LoginDlg(void);
    
	/** 控件消息处理 */
protected:
	//登录
	void OnLogin();
	//注册
	void OnReg();

	/** 菜单消息 */
protected:
	//处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	/** 窗口消息 */
protected:
	//对话框初始化过程
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);

    EVENT_MAP_BEGIN()
        EVENT_NAME_COMMAND(_T("btn_login"), OnLogin)
		EVENT_NAME_COMMAND(_T("btn_reg"), OnReg)
		CHAIN_EVENT_MAP(AcadSouiDialog)
    EVENT_MAP_END()

	//HOST消息及响应函数映射表
	BEGIN_MSG_MAP_EX(LoginDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
};

