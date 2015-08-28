#include "stdafx.h"
#include "MainuiDialog.h"
#include "laucherHelper.h"

MainuiDialog::MainuiDialog(LPCTSTR pszXmlName,BOOL bModal) : SouiDialog(pszXmlName, bModal)
{
}

MainuiDialog::~MainuiDialog()
{
}

static void GetDefaultPath( CString& defaultPath )
{
	TCHAR pPath[MAX_PATH]={0};
	SHGetSpecialFolderPath(NULL,pPath,CSIDL_PERSONAL,0);

	defaultPath.Format(_T("%s"),pPath);
}

static BOOL SelectCADFile(CString& fileName)
{
	TCHAR szFileFilter[] = _T("DWG文件(*.dwg)|*.dwg|DFX文件(*.dfx)|*.dfx|所有文件(*.*)|*.*||");
	TCHAR szFileExt[] = _T("dwg");

	CString defaultPath;
	GetDefaultPath(defaultPath);

	CFileDialog dlg(TRUE,szFileExt,defaultPath,OFN_OVERWRITEPROMPT,szFileFilter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框

	dlg.m_ofn.lpstrFile[0] = NULL;
	CString selectedPath;
	if(IDOK == dlg.DoModal())
	{
		selectedPath = dlg.GetPathName();
	}
	else
	{
		return FALSE;
	}

	fileName = selectedPath;
	return TRUE;
}

void MainuiDialog::RunCADApp(CString& sPath,LPTSTR arg)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi ={0};
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_SHOW;
	si.dwFlags=STARTF_USESHOWWINDOW;
	BOOL bReturnValue = CreateProcess( sPath, arg,NULL,FALSE,NULL,NULL,NULL,NULL,&si,&pi );	

	ShowWindow(SW_HIDE);
	//等进程关闭
	DWORD rc = WaitForSingleObject(pi.hProcess,INFINITE);
	ShowWindow(SW_SHOW);
}

void MainuiDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MainuiDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	SouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}


void MainuiDialog::OnCadButtonClick()
{
	//CString sPath= _T("D:\\Program Files\\AutoCAD 2010\\acad.exe");
	CString sPath = LaucherHelper::GetCADPath();
	RunCADApp(sPath);
}

void MainuiDialog::OnCadfileButtonClick()
{
	//CString sPath= _T("D:\\Program Files\\AutoCAD 2010\\acad.exe");
	CString sPath = LaucherHelper::GetCADPath();
	CString selectedPath;
	if(!SelectCADFile(selectedPath)) return;

	CString strArg = _T("motifi ") + selectedPath;
	LPTSTR argument = (LPTSTR)(LPCTSTR)strArg;
	RunCADApp(sPath,argument);
}

void MainuiDialog::OnClose()
{
	if (0 == LaucherHelper::FindProcess(_T("acad.exe")))
	{
		MessageBox(NULL, _T("请先关闭CAD!"), _T("警告"), MB_OK | MB_ICONWARNING);
		return;
	}

	LaucherHelper::deleteReg();
	LaucherHelper::recoverCadFile();
	SouiDialog::OnClose();
}