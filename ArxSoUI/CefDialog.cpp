// CefDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CefDialog.h"
#include "CefLaoder.h"

// CefDialog 对话框

IMPLEMENT_DYNAMIC(CefDialog, CDialog)

CefDialog::CefDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CefDialog::IDD, pParent)
{

}

CefDialog::~CefDialog()
{
}

void CefDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CefDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CefDialog 消息处理程序

void CefDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	//TODO: 在此处添加消息处理程序代码
	//问题：调整窗口大小的时候，浏览器不会跟着变化大小。
	//参考1：http://blog.csdn.net/mushao999/article/details/37606189
	//	CefRefPtr<CefBrowser> browser = CefLaoder::getSingletonPtr()->getApp()->GetBrowser();
	//	if(browser)
	//	{
	//		CefWindowHandle hwnd = browser->GetWindowHandle();
	//		::MoveWindow(hwnd,100,100,800,800, true); 
	//	}
	//}
	//参考2：http://www.heycode.com/a13696.html
	//CWnd* cefwindow= FindWindowEx(this->GetSafeHwnd(),NULL,L"CefBrowserWindow",NULL);
	//cefwindow->MoveWindow(0,0,cx,cy);
}

BOOL CefDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	::CRect rt;
	GetWindowRect(&rt);
	CefLaoder::getSingletonPtr()->createWindow(this->GetSafeHwnd(), rt);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
