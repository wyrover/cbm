#pragma once
#include "AcadSouiDialog.h"

class RegDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	RegDialog(BOOL bModal = FALSE);
	~RegDialog(void);

	/** 控件消息处理 */
protected:
	void OnRegButtonClick();
	void OnBaseComboxSelChanged(SOUI::EventArgs *pEvt);
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
		EVENT_NAME_COMMAND(_T("reg"), OnRegButtonClick)
		EVENT_NAME_HANDLER(_T("base"), EVT_CB_SELCHANGE, OnBaseComboxSelChanged)
		EVENT_NAME_HANDLER(_T("region"), EVT_CB_SELCHANGE, OnRegionComboxSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(RegDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_NameEdit;
	SEdit* m_ProvinceEdit;
	SEdit* m_CityEdit;
	SEdit* m_CoalNumsEdit;
	SEdit* m_UsernameEdit;
	SEdit* m_PasswordEdit;
	SComboBox* m_BaseCombox;
	SComboBox* m_RegionCombox;

private:
	void fillBaseCombox();
	void fillRegionCombox(const CString& base);
	void clearBaseCombox();
	void clearRegionCombox();
};
