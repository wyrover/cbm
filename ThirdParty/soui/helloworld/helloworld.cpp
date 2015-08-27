#include "stdafx.h"
#include "helloworld.h"
#include "MySoUiLoader.h"
#include "SouiDialog.h"
//#include "SouiXmlName.h"

static void InitSouiEnviroment(HINSTANCE hInstance)
{
	new MySoUiLoader(hInstance);
	SoUILoader::getSingletonPtr()->init();
}

static void UnInitSouiEnviroment()
{
	delete SoUILoader::getSingletonPtr();
}

static void StartFromSoui(LPCTSTR pszXmlName, HWND hParent=NULL, bool bModal=true)
{
	if(bModal)
	{
		SouiDialog dlg(pszXmlName, TRUE);
		dlg.SetWindowTitle(_T("改标题,随便玩玩!"));
		dlg.Run(hParent);
	}
	else
	{
		SouiDialog* dlg = new SouiDialog(pszXmlName, FALSE);
		dlg->SetWindowTitle(_T("改标题,随便玩玩!"));
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

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
	InitSouiEnviroment(hInstance);
	// 以模态方式启动
	//StartFromSoui(_T("layout:main"), NULL, true);
	// 或者以非模态方式启动
	StartFromSoui(_T("layout:main"), NULL, false);
	UnInitSouiEnviroment();

	return 0;
}