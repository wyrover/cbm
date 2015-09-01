#pragma once
#include "AcadSouiDialog.h"

class GasDesignP11Dialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	GasDesignP11Dialog(BOOL bModal = FALSE);
	~GasDesignP11Dialog(void);

	/** 控件消息处理 */
protected:
	void OnSaveButtonClick();
	void OnPtButtonClick();
	void OnHelpButtonClick();

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
		EVENT_NAME_COMMAND(_T("pt"), OnPtButtonClick)
		EVENT_NAME_COMMAND(_T("help"), OnHelpButtonClick)
		CHAIN_EVENT_MAP(AcadSouiDialog)
		EVENT_MAP_END()

		//HOST消息(WINDOWS消息)映射表
		BEGIN_MSG_MAP_EX(GasDesignP11Dialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()

protected:
	SEdit* m_ThickEdit;
	SEdit* m_DipAngleEdit;
	SEdit* m_L1Edit;
	SEdit* m_L2Edit;
	SEdit* m_WEdit;
	SEdit* m_HEdit;
	SEdit* m_WdEdit;
	SEdit* m_HdEdit;
	SEdit* m_DpEdit;
	SEdit* m_GpEdit;
	SEdit* m_WsEdit;
	SEdit* m_HsEdit;
	SEdit* m_LeftEdit;
	SEdit* m_RightEdit;
	SEdit* m_TopEdit;
	SEdit* m_BottomEdit;
	SEdit* m_VOffsetEdit;
	SEdit* m_HOffsetEdit;
	SEdit* m_NameEdit;
	SEdit* m_ZEdit;
	SEdit* m_XEdit;
	SEdit* m_YEdit;

public:
	int coal_id;

private:
	void initDatas();
	AcGePoint3d getPoint() const;
	void setPoint(const AcGePoint3d& pt);
};
