#pragma once
#include "AcadSouiDialog.h"

class DesignP11Dialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	DesignP11Dialog(BOOL bModal = FALSE);
	~DesignP11Dialog(void);

	/** 控件消息处理 */
protected:
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
		EVENT_NAME_COMMAND(_T("save"), OnSaveButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
		EVENT_MAP_END()

		//HOST消息(WINDOWS消息)映射表
		BEGIN_MSG_MAP_EX(DesignP11Dialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()

protected:
	SEdit* m_ThickEdit;
	SEdit* m_DipAngleEdit;
	SEdit* m_L1Edit;
	SEdit* m_L2Edit;
	SEdit* m_WEdit;
	SEdit* m_HEdit;
	SEdit* m_WdEdit;
	SEdit* m_HdEdit;
	SEdit* m_DpEdit;
	SEdit* m_GpEdit;
	SEdit* m_WsEdit;
	SEdit* m_HsEdit;
	SEdit* m_LeftEdit;
	SEdit* m_RightEdit;
	SEdit* m_TopEdit;
	SEdit* m_BottomEdit;
	SEdit* m_VDistEdit;
	SEdit* m_HDistEdit;
	SEdit* m_NameEdit;

public:
	int coal_id;

private:
	void initDatas();
};
