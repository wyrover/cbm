#pragma once
#include "AcadSouiDialog.h"

class MineGasReservesPredict2Dialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	MineGasReservesPredict2Dialog(BOOL bModal = FALSE);
	~MineGasReservesPredict2Dialog(void);

	/** 控件消息处理 */
protected:
	void OnSaveButtonClick();
	void OnPumpWcCaclButtonClick();
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
		EVENT_NAME_COMMAND(_T("save"), OnSaveButtonClick)
		EVENT_NAME_COMMAND(_T("pump_wc_cacl"), OnPumpWcCaclButtonClick)
		EVENT_NAME_HANDLER(_T("coal"), EVT_CB_SELCHANGE, OnCoalComboxSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(MineGasReservesPredict2Dialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_PumpWcEdit;
	SEdit* m_PumpKdEdit;
	SEdit* m_PumpK1Edit;
	SEdit* m_PumpK2Edit;
	SEdit* m_PumpK4Edit;
	SEdit* m_PumpK3Edit;
	SEdit* m_GasW0Edit;
	SEdit* m_PumpMcEdit;
	SComboBox* m_CoalCombox;

protected:
	virtual void OnDestroyWindow();

private:
	void fillCoalCombox();
	void initCoalDatas();
};
