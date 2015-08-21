#pragma once
#include "AcadSouiDialog.h"

class MineGasReservesPredict1Dialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	MineGasReservesPredict1Dialog(BOOL bModal = FALSE);
	~MineGasReservesPredict1Dialog(void);

	/** 控件消息处理 */
protected:
	void OnSaveButtonClick();
	void OnW1CaclButtonClick();
	void OnW2CaclButtonClick();
	void OnW3CaclButtonClick();
	void OnGasCaclButtonClick();

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
		EVENT_NAME_COMMAND(_T("w1_cacl"), OnW1CaclButtonClick)
		EVENT_NAME_COMMAND(_T("w2_cacl"), OnW2CaclButtonClick)
		EVENT_NAME_COMMAND(_T("w3_cacl"), OnW3CaclButtonClick)
		EVENT_NAME_COMMAND(_T("gas_cacl"), OnGasCaclButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(MineGasReservesPredict1Dialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_ReserveGasEdit;
	SEdit* m_ReserveW1Edit;
	SEdit* m_ReserveW2Edit;
	SEdit* m_ReserveW3Edit;
	SEdit* m_RockGasK2Edit;

private:
	void fillMineDatas();
};
