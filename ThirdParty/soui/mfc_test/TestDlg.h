#pragma once

#include "SouiDialog.h"

class TestDlg : public SouiDialog
{
public:
    TestDlg(BOOL bModal = FALSE);
    ~TestDlg(void);

	//窗口消息处理
protected:
	//对话框初始化过程
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);
    EVENT_MAP_BEGIN()
		CHAIN_EVENT_MAP(SouiDialog)
    EVENT_MAP_END()

	//HOST消息及响应函数映射表
	BEGIN_MSG_MAP_EX(TestDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		CHAIN_MSG_MAP(SouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

};

