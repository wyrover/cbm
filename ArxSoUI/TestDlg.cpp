// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestDlg.h"


// TestDlg 对话框

IMPLEMENT_DYNAMIC(TestDlg, CDialog)

TestDlg::TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TestDlg::IDD, pParent)
{

}

TestDlg::~TestDlg()
{
}

void TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TestDlg, CDialog)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()



// TestDlg 消息处理程序

BOOL TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	MoveWindow(0,0,350,190);

	// TODO:  在此添加额外的初始化
	dlg.Create(GetSafeHwnd(),WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, NULL, 0,0,0,0);
	dlg.GetNative()->SendMessage(WM_INITDIALOG);
	//dlg.CenterWindow();

	//CRect rect(0,0,0,0);
	//GetDlgItem(IDC_SOUI_WND)->GetWindowRect(&rect);
	//ScreenToClient(&rect);
	//dlg.MoveWindow(&rect);

	//透明窗口
	//Set WS_EX_LAYERED on this window
	::SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ::GetWindowLongPtr(GetSafeHwnd(), GWL_EXSTYLE | WS_EX_LAYERED));
	//Make this window 70% alpha transparent
	this->SetLayeredWindowAttributes(0,(255*90)/100,LWA_ALPHA);

	dlg.ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


LRESULT TestDlg::OnNcHitTest(CPoint point)
{
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);
	//return CDialog::OnNcHitTest(point);
}
