
// CefForMFC.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"

class CefForMFCApp : public CWinAppEx
{
public:
	CefForMFCApp();

public:
	virtual BOOL InitInstance();
	virtual int CefForMFCApp::ExitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CefForMFCApp theApp;