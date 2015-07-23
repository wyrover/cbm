#pragma once

//非模态登录对话框
class LoginDlg : public SOUI::SHostWnd
{
public:
    LoginDlg(void);
    ~LoginDlg(void);
    
public:
	//virtual BOOL PreTranslateMessage(MSG* pMsg);
	LRESULT OnAcadKeepFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	BOOL m_mouseInWindow;
	BOOL m_bTracking;

	//控件消息处理
protected:
	void OnLogin();
	void OnReg();

	//菜单消息处理
protected:
	//处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	//标题栏4个按钮的消息
protected:
	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();

	//窗口消息处理
protected:
	//对话框初始化过程
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);
	//开启Aero特效
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//窗口渐显过程
	void OnShowWindow(BOOL bShow, UINT nStatus);
	//销毁窗口或对话框
	void OnDestory();
	//窗口大小变化
	void OnSize(UINT nType, SOUI::CSize size);

    EVENT_MAP_BEGIN()
		//标题栏的4个按钮消息(可以用id号，也可以用名字，根据xml文件实际定义来做)
		EVENT_NAME_COMMAND(_T("btn_close"), OnClose)
		//EVENT_ID_COMMAND(1, OnClose)
		//EVENT_ID_COMMAND(2, OnMaximize)
		//EVENT_ID_COMMAND(3, OnRestore)
		//EVENT_ID_COMMAND(5, OnMinimize)
        EVENT_NAME_COMMAND(_T("btn_login"),OnLogin)
		EVENT_NAME_COMMAND(_T("btn_reg"),OnReg)
    EVENT_MAP_END()

	//HOST消息及响应函数映射表
	BEGIN_MSG_MAP_EX(LoginDlg)
		MESSAGE_HANDLER(WM_ACAD_KEEPFOCUS,OnAcadKeepFocus)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_DESTROY(OnDestory)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_COMMAND(OnCommand)
		MSG_WM_SHOWWINDOW(OnShowWindow)
		MSG_WM_MOUSELEAVE(OnMouseLeave)
		MSG_WM_MOUSEHOVER(OnMouseHover)
		MSG_WM_MOUSEMOVE(OnMouseMove)
		CHAIN_MSG_MAP(SOUI::SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

private:
	bool m_bLayoutInited;/**<UI完成布局标志 */
};

