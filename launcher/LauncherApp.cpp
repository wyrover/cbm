#include "stdafx.h"
#include "LauncherApp.h"
#include "MySoUiLoader.h"
#include "SouiDialog.h"
#include "SouiXmlName.h"

BEGIN_MESSAGE_MAP(CLauncherApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CLauncherApp::CLauncherApp()
{
}

// 唯一的一个 ClauncherApp 对象
CLauncherApp theApp;

static void InitSouiEnviroment(HINSTANCE hInstance)
{
	new MySoUiLoader(hInstance);
	SoUILoader::getSingletonPtr()->init();
}

static void UnInitSouiEnviroment()
{
	delete SoUILoader::getSingletonPtr();
}

static void StartFromSoui()
{
	//SouiDialog类及其派生类的构造函数都接受一个参数,用来指定xml资源的名称
	//本例中资源名称是动态获取的
	//用户使用的时候可以从SouiDialog类派生,并在派生类的构造函数中指定xml资源文件名
	//详细用法参考ArxSoUI项目中的对话框类
	SouiDialog dlg(RES_NAME, TRUE);
	dlg.Run(GetActiveWindow());
	//MFC程序本身就有消息循环了,不需要用getApp()->Run()启动消息循环
	//只有纯粹的win32程序才需要用getApp()->Run()启动消息循环
	//SoUILoader::getSingletonPtr()->getApp()->Run(dlg->m_hWnd);
}

//static void StartFromMFC(CWnd*& m_pMainWnd)
//{
//	//创建mfc主对话框
//	Cmfc_testDlg dlg;
//	m_pMainWnd = &dlg;
//	//进入模态消息循环,直到关闭对话框
//	INT_PTR nResponse = dlg.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: 在此放置处理何时用
//		//  “确定”来关闭对话框的代码
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: 在此放置处理何时用
//		//  “取消”来关闭对话框的代码
//	}
//}

// ClauncherApp 初始化
BOOL CLauncherApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinAppEx::InitInstance();
	AfxEnableControlContainer();
	AfxInitRichEdit2();
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	//初始化soui环境
	InitSouiEnviroment(m_hInstance);

	//(1)从soui启动
	StartFromSoui();
	//(2)或者从mfc启动
	//StartFromMFC(m_pMainWnd);

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

int CLauncherApp::ExitInstance()
{
	//退出soui环境
	UnInitSouiEnviroment();
	return CWinAppEx::ExitInstance();
}
