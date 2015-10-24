#include "stdafx.h"
#include "CefForMFC.h"
#include "CefForMFCDlg.h"

#include "ClientApp.h"
#include "ClientHandler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CefForMFCDlg::CefForMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CefForMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CefForMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CefForMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CefForMFCDlg 消息处理程序
BOOL CefForMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CefMainArgs main_args(AfxGetApp()->m_hInstance);  

	CefRefPtr<ClientApp> app(new ClientApp);  

	int exit_code = CefExecuteProcess(main_args, app.get(), NULL);  
	if (exit_code >= 0){  
		exit(exit_code);  
	}  

	CefSettings settings;  
	CefSettingsTraits::init(&settings);  
	settings.multi_threaded_message_loop = true;  
	CefInitialize(main_args, settings, app.get(), NULL);  

	CefWindowInfo info;
	RECT rect;  
	this->GetClientRect(&rect);  
	info.SetAsChild(this->GetSafeHwnd(), rect);  

	CefBrowserSettings b_settings;  
	CefRefPtr<CefClient> client(new ClientHandler);  

	std::string url = "https://www.baidu.com";  
	CefBrowserHost::CreateBrowser(info, client.get(), url, b_settings, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CefForMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND,reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CefForMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CefForMFCDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}

int CefForMFCDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}

void CefForMFCDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// CefShutdown();
	CDialog::OnClose();
}

void CefForMFCDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	// TODO: 在此处添加消息处理程序代码
	// CefShutdown();
}
