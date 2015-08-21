#pragma once
#include "AcadSouiDialog.h"

class TechModeDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	TechModeDialog(BOOL bModal = FALSE);
	~TechModeDialog(void);

	/** 控件消息处理 */
protected:
	void OnTechModeComboxSelChanged(SOUI::EventArgs *pEvt);
	void OnSaveButtonClick();
	void OnRadioGroup1Switch(int nID);
	void OnRadioGroup2Switch(int nID);
	void OnRadioGroup3Switch(int nID);

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
		EVENT_NAME_HANDLER(_T("tech_mode"), EVT_CB_SELCHANGE, OnTechModeComboxSelChanged)
		EVENT_NAME_COMMAND(_T("save"), OnSaveButtonClick)
		EVENT_ID_COMMAND_RANGE(110, 111, OnRadioGroup1Switch)
		EVENT_ID_COMMAND_RANGE(120, 121, OnRadioGroup2Switch)
		EVENT_ID_COMMAND_RANGE(100, 101, OnRadioGroup3Switch)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(TechModeDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SComboBox* m_TechModeCombox;
	SRadioBox* m_C2YesRadio;
	SRadioBox* m_C2NoRadio;
	SRadioBox* m_C3YesRadio;
	SRadioBox* m_C3NoRadio;
	SStatic* m_RegionLabel;
	SRadioBox* m_C1YesRadio;
	SRadioBox* m_C1NoRadio;

public:
	CString regionName; // 示范矿区(外部传入)

protected:
	virtual void OnDestroyWindow();

private:
	void fillTechModeCombox();
};
