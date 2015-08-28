#pragma once

//检查进程是否存在
#include <tlhelp32.h> 
//返回 -1 没有找到
//返回  0 找到自身
//返回  1 找到除自身外的另一个

enum pathType
{
	CURRENT_USER = 0, //得到的目录C:\Users\hd\AppData\Roaming\Autodesk\AutoCAD 2010\R18.0\chs\Support
	LOCAL_MACHINE = 1, //得到的目录是CAD的安装目录
};

class LaucherHelper
{
	public:
		static int FindProcess(TCHAR* appName);
		static BOOL IsAutoCADExist();
		static CString GetCADPath();
		static BOOL copyCadFile();
		static BOOL recoverCadFile();
		static BOOL writeReg();
		static BOOL deleteReg();
};
