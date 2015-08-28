#include "stdafx.h"
#include "laucherHelper.h"
#include "Registry.h"
#include "RegEntry.h"
#include <shlwapi.h>

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
static BOOL IsWow64() 
{ 
	BOOL bIsWow64 = FALSE; 
	LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress( 
		GetModuleHandle(TEXT("kernel32")),"IsWow64Process"); 
	if (NULL != fnIsWow64Process) 
	{ 
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64)) 
		{ 
			// handle error 
			//AfxMessageBox(_T("IsWow64 error!")); 
		} 
	}
	return bIsWow64; 
}

static CString GetCADPathByWinAPI( TCHAR* locationKey ,pathType pat)
{
	CString cadPath;

	TCHAR cadKey[MAX_PATH];
	_tcscpy(cadKey, _T("Software\\Autodesk\\AutoCAD\\R18.0\\ACAD-8001:804"));

	HKEY hRoot = (CURRENT_USER == pat)?HKEY_CURRENT_USER:HKEY_LOCAL_MACHINE;
	CRegistry reg;

	DWORD dwAccess = KEY_ALL_ACCESS;
	//判断是否64位
	if(IsWow64())
	{
		dwAccess |= KEY_WOW64_64KEY;
	}
	bool ret = reg.Open( cadKey, hRoot, dwAccess);
	if(ret)
	{
		ret = false;
		int n = reg.Count();
		for(int i=0;i<n;i++)
		{
			CRegEntry* entry = reg.GetAt(i);
			if(!_tcscmp(locationKey, entry->lpszName))
			{
				cadPath = (CString)*entry;
				ret = true; break;
			}
		}
		//SubKeyExists不好使!
		//std::string name = locationKey.toStdString();
		//ret = reg.SubKeyExists(name.c_str());
		//if(ret)
		//{
		//	cadPath = QString::fromStdString((std::string)reg[name.c_str()]);
		//}
	}
	reg.Close();

	return cadPath;
}

static CString GetWorkDir() 
{  
	//TCHAR pFileName[MAX_PATH]; 
	//int nPos = GetCurrentDirectory( MAX_PATH, pFileName); 

	//CString csFullPath(pFileName);  
	//if( nPos < 0 ) 
	//	return CString(_T("")); 
	//else 
	//	return csFullPath; 
	HMODULE module = GetModuleHandle(0); 
	TCHAR pFileName[MAX_PATH]; 
	GetModuleFileName(module, pFileName, MAX_PATH); 

	CString csFullPath(pFileName); 
	int nPos = csFullPath.ReverseFind( _T('\\') ); 
	if( nPos < 0 ) 
		return CString(""); 
	else 
		return csFullPath.Left( nPos ); 
}

bool writeTestKeybyWinAPI(CString& currentPath)
{
	TCHAR cadKey[MAX_PATH];
	_tcscpy(cadKey, _T("Software\\Autodesk\\AutoCAD\\R18.0\\ACAD-8001:804\\Applications\\CBM"));

	DWORD dwAccess = KEY_ALL_ACCESS;
	//判断是否64位
	if(IsWow64())
	{
		dwAccess |= KEY_WOW64_64KEY;
	}

	CRegistry reg;
	bool ret = reg.Open( cadKey, HKEY_LOCAL_MACHINE, dwAccess);
	if(ret)
	{
		//if(reg.Count()>0)
		//{
		reg[_T("LOADCTRLS")] = (DWORD)2;
		currentPath.Append(_T("\\VVLoader.arx"));
		reg[_T("LOADER")] = currentPath;
		//}
	}
	reg.Close();

	return ret;
}

//data为0去掉搜索和登录框，为1时显示
static bool MotifiInfomationKey(int data)
{
	TCHAR cadKey[MAX_PATH];
	_tcscpy(cadKey, _T("Software\\Autodesk\\AutoCAD\\R18.0\\ACAD-8001:804\\InfoCenter"));

	DWORD dwAccess = KEY_ALL_ACCESS;
	//判断是否64位
	if(IsWow64())
	{
		dwAccess |= KEY_WOW64_64KEY;
	}

	CRegistry reg;
	bool ret = reg.Open( cadKey, HKEY_CURRENT_USER, dwAccess);
	if(ret)
	{
		ret = false;
		if(reg.Count()>0)
		{
			int n = reg.Count();
			for(int i=0;i<n;i++)
			{
				CRegEntry* entry = reg.GetAt(i);
				if(0 == _tcscmp(_T("InfoCenterOn"),entry->lpszName))
				{
					*entry = data;
					ret = true; break;
				}
			}
		}
	}
	reg.Close();

	return ret;
}

static bool delTestKeybyWinAPI()
{
	TCHAR cadKey[MAX_PATH];
	_tcscpy(cadKey, _T("Software\\Autodesk\\AutoCAD\\R18.0\\ACAD-8001:804\\Applications"));

	DWORD dwAccess = KEY_ALL_ACCESS;
	//判断是否64位
	if(IsWow64())
	{
		dwAccess |= KEY_WOW64_64KEY;
	}

	CRegistry reg;
	reg.Clear(HKEY_LOCAL_MACHINE,cadKey,_T("CBM"),dwAccess);

	return true;
}

static BOOL CopyCUIXandMNR(LPCTSTR cuixPath,LPCTSTR mnrPath)
{
	CString cadPath = GetCADPathByWinAPI(_T("RoamableRootFolder"),CURRENT_USER);
	cadPath.Append(_T("Support"));
	//CString CADcuixPath = cadPath + _T("\\acad.CUIX");
	CString CADcuixPath = cadPath + _T("\\acad.CUIX");
	CString CADmnrPath = cadPath + _T("\\acad.mnr");

	//获取当前程序(.exe)所在的路径
	CString CurrentPath = GetWorkDir();

	CString JLcuixPath = CurrentPath;
	//JLcuixPath.Append("\\Datas\\JL\\acad.CUIX");
	JLcuixPath.Append(cuixPath);
	CString JLmnrPath = CurrentPath + mnrPath;

	if(!CopyFile(JLcuixPath,CADcuixPath,false)) return FALSE;
	if(!CopyFile(JLmnrPath,CADmnrPath,false)) return FALSE;
	return TRUE;
}

int LaucherHelper::FindProcess( TCHAR* appName )
{
	int i=0;  
	PROCESSENTRY32 pe32;  
	pe32.dwSize = sizeof(pe32);   
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
	if(hProcessSnap == INVALID_HANDLE_VALUE)  
	{  
		i+=0;  
	}  
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);  
	while(bMore)  
	{  
		//printf(" 进程名称：%s \n", pe32.szExeFile);  
		if(!_tcscmp(appName,pe32.szExeFile))  
		{  
			//printf("进程运行中"); 
			//AfxMessageBox(appName);
			i+=1;  
		}  
		bMore = ::Process32Next(hProcessSnap, &pe32);  
	}  
	if(i>1)//大于1，排除自身  
	{           
		return 1;  
	}

	else if( i > 0 && i < 2 ) //等于1，找到自身
	{
		return 0;
	}

	else
	{  
		return -1;  
	}  
}

BOOL LaucherHelper::IsAutoCADExist()
{
	BOOL isExist = FALSE;
	//CAD的安装目录
	CString cadPath = GetCADPathByWinAPI(_T("AcadLocation"),LOCAL_MACHINE);
	if(cadPath.IsEmpty()) 
	{
		MessageBox(NULL, _T("未安装CAD!"), _T("警告!"), MB_OK | MB_ICONWARNING);
		isExist = FALSE;
		return FALSE;
	}

	else isExist = TRUE;

	return isExist;

}


CString LaucherHelper::GetCADPath()
{
	CString cadPath = GetCADPathByWinAPI(_T("AcadLocation"),LOCAL_MACHINE);
	cadPath.Append(_T("\\acad.exe"));
	return cadPath;
}

BOOL LaucherHelper::copyCadFile()
{
	if(!CopyCUIXandMNR(_T("\\Datas\\JL\\acad.CUIX"),_T("\\Datas\\JL\\acad.mnr"))) return FALSE;
	return TRUE;
}

BOOL LaucherHelper::recoverCadFile()
{
	if(!CopyCUIXandMNR(_T("\\Datas\\CAD\\acad.CUIX"),_T("\\Datas\\CAD\\acad.mnr"))) return FALSE;
	return TRUE;
}

BOOL LaucherHelper::writeReg()
{
	CString CurrentPath = GetWorkDir();
	if(!writeTestKeybyWinAPI(CurrentPath)) return FALSE;
	if(!MotifiInfomationKey(0)) return FALSE;
	return TRUE;
}

BOOL LaucherHelper::deleteReg()
{
	if(!delTestKeybyWinAPI()) return FALSE;
	if(!MotifiInfomationKey(1)) return FALSE;
	return TRUE;
}
