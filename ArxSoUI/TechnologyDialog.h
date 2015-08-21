#pragma once
#include "AcadSouiDialog.h"

class TechnologyDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	TechnologyDialog(BOOL bModal = FALSE);
	~TechnologyDialog(void);

	/** 控件消息处理 */
protected:
	void OnTechnologyListboxSelChanged(SOUI::EventArgs *pEvt);
	void OnDocReadButtonClick();
	void OnVideoPlayButtonClick();
	void OnDocSelectButtonClick();
	void OnVideoSelectButtonClick();
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
		EVENT_NAME_HANDLER(_T("technology"), EVT_LB_SELCHANGED, OnTechnologyListboxSelChanged)
		EVENT_NAME_COMMAND(_T("doc_read"), OnDocReadButtonClick)
		EVENT_NAME_COMMAND(_T("video_play"), OnVideoPlayButtonClick)
		EVENT_NAME_COMMAND(_T("doc_select"), OnDocSelectButtonClick)
		EVENT_NAME_COMMAND(_T("video_select"), OnVideoSelectButtonClick)
		EVENT_NAME_COMMAND(_T("save"), OnSaveButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(TechnologyDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SListBox* m_TechnologyListbox;
	SCheckBox* m_IsKeyCheck;
	SEdit* m_DocEdit;
	SEdit* m_VideoEdit;
	SStatic* m_RegionLabel;

public:
	CString regionName; // 示范矿区(外部传入)

protected:
	virtual void OnDestroyWindow();

private:
	void fillTechnologyListBox();
};
