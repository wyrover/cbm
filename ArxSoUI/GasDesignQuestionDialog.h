#pragma once
#include "AcadSouiDialog.h"

class GasDesignQuestionDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	GasDesignQuestionDialog(BOOL bModal = FALSE);
	~GasDesignQuestionDialog(void);

	/** 控件消息处理 */
protected:
	void OnTechnologyListboxSelChanged(SOUI::EventArgs *pEvt);
	void OnGoButtonClick();
	void OnDesignComboxSelChanged(SOUI::EventArgs *pEvt);
	void OnNewDesignButtonClick();
	void OnDelDesignButtonClick();

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
		EVENT_NAME_HANDLER(_T("technology"), EVT_LB_SELCHANGED, OnTechnologyListboxSelChanged)
		EVENT_NAME_COMMAND(_T("go"), OnGoButtonClick)
		EVENT_NAME_HANDLER(_T("design"), EVT_CB_SELCHANGE, OnDesignComboxSelChanged)
		EVENT_NAME_COMMAND(_T("new_design"), OnNewDesignButtonClick)
		EVENT_NAME_COMMAND(_T("del_design"), OnDelDesignButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(GasDesignQuestionDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SListBox* m_TechnologyListbox;
	SComboBox* m_DesignCombox;

public:
	int coal_id; // 煤层id
	int region;  // 传入的参数(表示在哪个区域做抽采,工作面、掘进面、采空区???)
	int tech_id; // 传出的参数

protected:
	virtual void OnDestroyWindow();

private:
	void fillDatas();
};
