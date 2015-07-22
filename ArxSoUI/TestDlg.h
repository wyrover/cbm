#pragma once

#include "LoginDlg.h"
#include "resource.h"
// TestDlg 对话框

class TestDlg : public CDialog
{
	DECLARE_DYNAMIC(TestDlg)

public:
	TestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDlg();
LoginDlg dlg;
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	afx_msg LRESULT OnNcHitTest(::CPoint point);
};
