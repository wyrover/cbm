#include "stdafx.h"
#include "PolicyDialog.h"
#include "UIHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

static CString GetSuffix( const CString& strFileName )
{
    return strFileName.Right( strFileName.GetLength() - strFileName.ReverseFind( _T( '.' ) ) - 1 );
}

//打开pdf文件(调用自带的pdf.exe,和arx程序打包在一起)
static bool OpenPdf( const CString& pdfExePath, const CString& cwdPath, const CString& pdfFile )
{
    bool hidden = false;

    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    memset( &si, 0, sizeof( si ) );
    si.cb = sizeof( si );
    si.wShowWindow = hidden ? SW_HIDE : SW_SHOW;
    si.dwFlags = STARTF_USESHOWWINDOW;

    CString cmdLine;
    cmdLine.Format( _T( " %s" ), pdfFile );

    BOOL ret = CreateProcess( ( LPCTSTR )pdfExePath, ( LPTSTR )( LPCTSTR )cmdLine, NULL, FALSE, NULL, NULL, NULL, ( LPCTSTR )cwdPath, &si, &pi );
    if( ret )
    {
        //WaitForSingleObject(pi.hProcess, INFINITE);
        //CloseHandle(pi.hThread);
        //CloseHandle(pi.hProcess);

        //HANDLE& hProcess, HANDLE& hThread
        // 返回进程和线程句柄
        //hProcess = pi.hProcess;
        //hThread = pi.hThread;
    }
    return ( ret == TRUE );
}

//打开html文件(调用系统的默认浏览器)
static bool OpenHtml( const CString& url )
{
    return ( long )ShellExecute( NULL, _T( "open" ), url, NULL, NULL, SW_SHOWNORMAL ) > 32;
}

//打开chm文件(调用系统自带的chm程序)
static bool OpenChm( const CString& chmFile )
{
    return ( long )ShellExecute( NULL, _T( "open" ), chmFile, NULL, NULL, SW_SHOWNORMAL ) > 32;
}

PolicyDialog::PolicyDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:policy" ), bModal )
{
}

PolicyDialog::~PolicyDialog()
{
}

void PolicyDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT PolicyDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_Link14 = FindChildByName2<SLink>( L"link14" );
    return 0;
}


void PolicyDialog::OnP1ButtonClick()
{
    OpenPdf( _T( "pdf.exe" ), _T( "." ), _T( "help\\AQ1018-2006瓦斯涌出量预测.pdf" ) );
}

void PolicyDialog::OnP2ButtonClick()
{
    OpenHtml( _T( "help\\index.html" ) );
}

void PolicyDialog::OnP3ButtonClick()
{
}

void PolicyDialog::OnP4ButtonClick()
{
}

void PolicyDialog::OnP6ButtonClick()
{
}

void PolicyDialog::OnP7ButtonClick()
{
}

void PolicyDialog::OnP8ButtonClick()
{
}

void PolicyDialog::OnP5ButtonClick()
{
}
