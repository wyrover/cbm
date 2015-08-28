#include "stdafx.h"
#include "LauncherApp.h"
#include "MySoUiLoader.h"
#include "MainuiDialog.h"
#include "SouiXmlName.h"
#include "laucherHelper.h"

BEGIN_MESSAGE_MAP( CLauncherApp, CWinAppEx )
    ON_COMMAND( ID_HELP, &CWinApp::OnHelp )
END_MESSAGE_MAP()

CLauncherApp::CLauncherApp()
{
}

// 唯一的一个 ClauncherApp 对象
CLauncherApp theApp;

static void InitSouiEnviroment( HINSTANCE hInstance )
{
    new MySoUiLoader( hInstance );
    SoUILoader::getSingletonPtr()->init();
}

static void UnInitSouiEnviroment()
{
    delete SoUILoader::getSingletonPtr();
}

static BOOL IsRunning()
{
	if (0 == LaucherHelper::FindProcess(_T("acad.exe")))
	{
		MessageBox(NULL, _T("CAD正在运行!"), _T("警告"), MB_OK | MB_ICONWARNING);
		return TRUE;
	}

	if (1 == LaucherHelper::FindProcess(_T("Launcher.exe")))
	{
		MessageBox(NULL, _T("程序正在运行!"), _T("警告"), MB_OK | MB_ICONWARNING);
		return TRUE;
	}
	return FALSE;
}

static BOOL CADFileInit()
{
	if(!LaucherHelper::IsAutoCADExist()) return FALSE;
	if(!LaucherHelper::copyCadFile()) 
	{
		MessageBox(NULL, _T("程序初始化失败!"), _T("错误提示"), MB_OK | MB_ICONSTOP);
		return FALSE;
	}
	if(!LaucherHelper::writeReg()) 
	{
		MessageBox(NULL, _T("注册表写入失败!"), _T("错误提示"), MB_OK | MB_ICONSTOP);
		return FALSE;
	}
	return TRUE;
}

static void StartFromSoui(SouiDialog* dlg, HWND hParent=NULL)
{
	//dlg->SetWindowTitle(_T("改标题,随便玩玩!"));
	if(dlg->isModal() == TRUE)
	{
		dlg->Run(hParent);
	}
	else
	{
		dlg->Run(hParent);
		//父窗口为0的一般都是主窗口
		if(hParent == NULL)
		{
			//只有主窗口才需要用getApp()->Run()启动消息循环
			//MFC的InitInstance()函数执行的时候,此时还没有消息循环,如果要显示主窗口,那么需要我们人工启动消息循环
			//同理,win32程序的WinMain函数中主窗口也是需要等候MFC程序本身就有消息循环了,不需要用getApp()->Run()启动消息循环
			SoUILoader::getSingletonPtr()->getApp()->Run(dlg->m_hWnd);
		}
	}
}

static void StartFromMFC(CDialog* dlg)
{
	//设置MFC主窗口
	AfxGetApp()->m_pMainWnd = dlg;
	//进入模态消息循环,直到关闭对话框
	INT_PTR nResponse = dlg->DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
}

// ClauncherApp 初始化
BOOL CLauncherApp::InitInstance()
{
    // 如果一个运行在 Windows XP 上的应用程序清单指定要
    // 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
    //则需要 InitCommonControlsEx()。否则，将无法创建窗口。
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof( InitCtrls );
    // 将它设置为包括所有要在应用程序中使用的
    // 公共控件类。
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx( &InitCtrls );
    CWinAppEx::InitInstance();
    AfxEnableControlContainer();
    AfxInitRichEdit2();
    SetRegistryKey( _T( "应用程序向导生成的本地应用程序" ) );

	//如果cad或launcher已经运行就退出
	//保证只有一个实例在运行!!!
	if(IsRunning()) return FALSE;
	//初始化CAD
	if(!CADFileInit()) return FALSE;

    //初始化soui环境
    InitSouiEnviroment( m_hInstance );

	//(1)从soui启动
	if(1)
	{
		//以模态方式启动
		MainuiDialog dlg(TRUE);
		dlg.SetWindowTitle(_T("井下煤层气规模化抽采计算机辅助设计（CAD）系统"));
		StartFromSoui(&dlg, NULL);
	}
	else
	{
		// 或者以非模态方式启动
		MainuiDialog* dlg = new MainuiDialog(FALSE);
		dlg->SetWindowTitle(_T("井下煤层气规模化抽采计算机辅助设计（CAD）系统"));
		StartFromSoui(dlg, NULL);
	}
    //(2)或者从mfc启动
	//Cmfc_testDlg dlg;
	//StartFromMFC(&dlg);

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
