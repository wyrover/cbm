// report.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "report.h"
#include "ReportHelper.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;
void jsonTest()
{
	//字符串
	const char* str = 
		"{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
		"\"born\":-100,\"died\":-44}";

	Json::Reader reader;
	Json::Value root;

	//从字符串中读取数据
	if(reader.parse(str,root))
	{
		string praenomen = root["praenomen"].asString();
		string nomen = root["nomen"].asString();
		string cognomen = root["cognomen"].asString();
		int born = root["born"].asInt();
		int died = root["died"].asInt();

		cout << praenomen + " " + nomen + " " + cognomen
			<< " was born in year " << born 
			<< ", died in year " << died << endl;
	}
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		//wcout << argv[1] <<endl;
		//字符串
		const char* str = 
			"{\"tplPath\":\"E:\\\\test\\\\git\\\\cbm\\\\x64\\\\Debug\\\\Datas\\\\JL\\\\tpl\\\\tplBase.doc\",\"EPCMFD_Method\":\"书签啊xxx\",\"cognomen\":\"Caezar\",\"born\":-100,\"died\":-44}";

		//WordHelper rptHelper;
		//rptHelper.creat(str);
		//CString tplPath = _T("E:\\test\\git\\cbm\\x64\\Debug\\Datas\\JL\\tpl\\tplBase.doc");
		CString jsonPath = _T("E:\\test\\git\\cbm\\x64\\Debug\\Datas\\jsDatas.json");
		ReportHelper::CreatReport(jsonPath);
		jsonTest();
	}

	return nRetCode;
}

