#pragma once
#include "AcadSouiDialog.h"

class TwsGasPredictDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	TwsGasPredictDialog(BOOL bModal = FALSE);
	~TwsGasPredictDialog(void);

	/** 控件消息处理 */
protected:
	void OnCacl1ButtonClick();
	void OnCacl2ButtonClick();
	void OnSaveButtonClick();

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
		EVENT_NAME_COMMAND(_T("cacl1"), OnCacl1ButtonClick)
		EVENT_NAME_COMMAND(_T("cacl2"), OnCacl2ButtonClick)
		EVENT_NAME_COMMAND(_T("save"), OnSaveButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(TwsGasPredictDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_TwQ3Edit;
	SEdit* m_TwQ4Edit;
};
