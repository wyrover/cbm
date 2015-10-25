#pragma once

#include "resource.h"
#include "simple_app.h"

// CefDialog 对话框

class CefDialog : public CDialog
{
	DECLARE_DYNAMIC(CefDialog)

public:
	CefDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CefDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

	virtual BOOL OnInitDialog();
};
