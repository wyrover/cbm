#pragma once
#include "AcadSouiDialog.h"

class DrainageKeyParamDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	DrainageKeyParamDialog(BOOL bModal = FALSE);
	~DrainageKeyParamDialog(void);

	/** 控件消息处理 */
protected:
	void OnKP1ButtonClick();
	void OnKP2ButtonClick();
	void OnKP3ButtonClick();
	void OnKP4ButtonClick();
	void OnKP6ButtonClick();
	void OnKP7ButtonClick();
	void OnKP8ButtonClick();
	void OnKP9ButtonClick();
	void OnKP10ButtonClick();
	void OnKP11ButtonClick();
	void OnKP5ButtonClick();

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
		EVENT_NAME_COMMAND(_T("KP1"), OnKP1ButtonClick)
		EVENT_NAME_COMMAND(_T("KP2"), OnKP2ButtonClick)
		EVENT_NAME_COMMAND(_T("KP3"), OnKP3ButtonClick)
		EVENT_NAME_COMMAND(_T("KP4"), OnKP4ButtonClick)
		EVENT_NAME_COMMAND(_T("KP6"), OnKP6ButtonClick)
		EVENT_NAME_COMMAND(_T("KP7"), OnKP7ButtonClick)
		EVENT_NAME_COMMAND(_T("KP8"), OnKP8ButtonClick)
		EVENT_NAME_COMMAND(_T("KP9"), OnKP9ButtonClick)
		EVENT_NAME_COMMAND(_T("KP10"), OnKP10ButtonClick)
		EVENT_NAME_COMMAND(_T("KP11"), OnKP11ButtonClick)
		EVENT_NAME_COMMAND(_T("KP5"), OnKP5ButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(DrainageKeyParamDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
};
