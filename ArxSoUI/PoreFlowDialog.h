#pragma once
#include "AcadSouiDialog.h"

class PoreFlowDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	PoreFlowDialog(BOOL bModal = FALSE);
	~PoreFlowDialog(void);

	/** 控件消息处理 */
protected:
	void OnSaveButtonClick();
	void OnKCaclButtonClick();
	void OnBCaclButtonClick();
	void OnDeltaPCaclButtonClick();
	void OnDeltaTCaclButtonClick();
	void OnCaclButtonClick();

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
		EVENT_NAME_COMMAND(_T("K_cacl"), OnKCaclButtonClick)
		EVENT_NAME_COMMAND(_T("b_cacl"), OnBCaclButtonClick)
		EVENT_NAME_COMMAND(_T("delta_p_cacl"), OnDeltaPCaclButtonClick)
		EVENT_NAME_COMMAND(_T("delta_T_cacl"), OnDeltaTCaclButtonClick)
		EVENT_NAME_COMMAND(_T("cacl"), OnCaclButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(PoreFlowDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_KEdit;
	SEdit* m_BEdit;
	SEdit* m_DeltaPEdit;
	SEdit* m_DeltaTEdit;
	SEdit* m_DhEdit;
	SEdit* m_XEdit;
	SEdit* m_QHunEdit;
	SEdit* m_QChunEdit;
	SEdit* m_TEdit;

protected:
	virtual void OnDestroyWindow();

private:
	void initDatas();
	int pore_flow_id; // 内部使用
};
