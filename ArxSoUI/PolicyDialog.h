#pragma once
#include "AcadSouiDialog.h"

class PolicyDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	PolicyDialog(BOOL bModal = FALSE);
	~PolicyDialog(void);

	/** 控件消息处理 */
protected:
	void OnP1ButtonClick();
	void OnP2ButtonClick();
	void OnP3ButtonClick();
	void OnP4ButtonClick();
	void OnP6ButtonClick();
	void OnP7ButtonClick();
	void OnP8ButtonClick();
	void OnP5ButtonClick();

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
		EVENT_NAME_COMMAND(_T("P1"), OnP1ButtonClick)
		EVENT_NAME_COMMAND(_T("P2"), OnP2ButtonClick)
		EVENT_NAME_COMMAND(_T("P3"), OnP3ButtonClick)
		EVENT_NAME_COMMAND(_T("P4"), OnP4ButtonClick)
		EVENT_NAME_COMMAND(_T("P6"), OnP6ButtonClick)
		EVENT_NAME_COMMAND(_T("P7"), OnP7ButtonClick)
		EVENT_NAME_COMMAND(_T("P8"), OnP8ButtonClick)
		EVENT_NAME_COMMAND(_T("P5"), OnP5ButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(PolicyDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SLink* m_Link14;
};
