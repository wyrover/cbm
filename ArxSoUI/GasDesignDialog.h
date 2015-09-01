#pragma once
#include "AcadSouiDialog.h"

class GasDesignDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	GasDesignDialog(BOOL bModal = FALSE);
	~GasDesignDialog(void);

	/** 控件消息处理 */
protected:
	void OnP11ButtonClick();
	void OnP12ButtonClick();
	void OnP13ButtonClick();
	void OnP21ButtonClick();
	void OnP22ButtonClick();
	void OnP23ButtonClick();
	void OnP24ButtonClick();
	void OnP25ButtonClick();
	void OnP31ButtonClick();
	void OnP32ButtonClick();
	void OnP33ButtonClick();
	void OnP34ButtonClick();
	void OnCoalComboxSelChanged(SOUI::EventArgs *pEvt);

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
		EVENT_NAME_COMMAND(_T("P1_1"), OnP11ButtonClick)
		EVENT_NAME_COMMAND(_T("P1_2"), OnP12ButtonClick)
		EVENT_NAME_COMMAND(_T("P1_3"), OnP13ButtonClick)
		EVENT_NAME_COMMAND(_T("P2_1"), OnP21ButtonClick)
		EVENT_NAME_COMMAND(_T("P2_2"), OnP22ButtonClick)
		EVENT_NAME_COMMAND(_T("P2_3"), OnP23ButtonClick)
		EVENT_NAME_COMMAND(_T("P2_4"), OnP24ButtonClick)
		EVENT_NAME_COMMAND(_T("P2_5"), OnP25ButtonClick)
		EVENT_NAME_COMMAND(_T("P3_1"), OnP31ButtonClick)
		EVENT_NAME_COMMAND(_T("P3_2"), OnP32ButtonClick)
		EVENT_NAME_COMMAND(_T("P3_3"), OnP33ButtonClick)
		EVENT_NAME_COMMAND(_T("P3_4"), OnP34ButtonClick)
		EVENT_NAME_HANDLER(_T("coal"), EVT_CB_SELCHANGE, OnCoalComboxSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(GasDesignDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SComboBox* m_CoalCombox;

public:
	int mine_id;

protected:
	virtual void OnDestroyWindow();

private:
	void fillCoalCombox();
};
