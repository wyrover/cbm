#pragma once
#include "AcadSouiDialog.h"

class TwsGasFlowPredictDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	TwsGasFlowPredictDialog(BOOL bModal = FALSE);
	~TwsGasFlowPredictDialog(void);

	/** 控件消息处理 */
protected:
	void OnSaveButtonClick();
	void OnCaclButtonClick();
	void OnWcCaclButtonClick();
	void OnTwsComboxSelChanged(SOUI::EventArgs *pEvt);

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
		EVENT_NAME_COMMAND(_T("cacl"), OnCaclButtonClick)
		EVENT_NAME_COMMAND(_T("wc_cacl"), OnWcCaclButtonClick)
		EVENT_NAME_HANDLER(_T("tws"), EVT_CB_SELCHANGE, OnTwsComboxSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(TwsGasFlowPredictDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_Q3Edit;
	SEdit* m_Q4Edit;
	SEdit* m_QaEdit;
	SEdit* m_Q0Edit;
	SEdit* m_DEdit;
	SEdit* m_VEdit;
	SEdit* m_LEdit;
	SEdit* m_VrEdit;
	SEdit* m_GasW0Edit;
	SEdit* m_RhoEdit;
	SEdit* m_SEdit;
	SEdit* m_GasWc2Edit;
	SComboBox* m_TwsCombox;

protected:
	virtual void OnDestroyWindow();

private:
	void initTwsDatas();
	void fillTwsCombox();
	DrillingSurfPtr getCurSelTws();
};
