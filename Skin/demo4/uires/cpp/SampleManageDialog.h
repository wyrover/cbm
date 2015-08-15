#pragma once
#include "AcadSouiDialog.h"

class SampleManageDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	SampleManageDialog(BOOL bModal = FALSE);
	~SampleManageDialog(void);

	/** 控件消息处理 */
protected:
	void OnLogoutButtonClick();
	void OnRegionComboxSelChanged(SOUI::EventArgs *pEvt);

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
		EVENT_NAME_COMMAND(_T("logout"), OnLogoutButtonClick)
		EVENT_NAME_HANDLER(_T("region"), EVT_CB_SELCHANGE, OnRegionComboxSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(SampleManageDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SComboBox* m_RegionCombox;
	SListCtrl* m_CoalListctrl;
	SListCtrl* m_TechnologyListctrl;
};
