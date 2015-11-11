#include "StdAfx.h"
#include "CmdHelper.h"

#include "SQLClientHelper.h"
#include "CbmClientHelper.h"
#include <WinHttpClient.h>
#include <ArxHelper/HelperClass.h>

#include <fstream>

void CmdHelper::PostJsonDatasToRpc()
{
	TCHAR strFileName[MAX_PATH];
	if(acedGetString(0, _T("请指定数据文件名称:"), strFileName) != RTNORM) return;

	std::ifstream infile(W2C(strFileName));
	if(!infile) return;

	//有些请求可能需要传递给cad一些参数
	std::string input_datas = "{}";
	infile >> input_datas;

	//服务器生成的密钥
	std::string secret_key = "#";
	infile >> secret_key;
	infile.close();

	acutPrintf(_T("\n1:%s\n2:%s"), C2W(input_datas), C2W(secret_key));
	if(secret_key == "#") return;

	// 收集数据(根据input_datas的内容进行判断:input_datas是一个json数据)

	//发送rpc服务器进行缓存
	std::string out_datas = "{'name':'dlj'}";
	CbmClientHelper::PostJsonDatasFromCAD(secret_key, input_datas, out_datas);
}

void CmdHelper::xxx()
{
	std::string json_data = CbmClientHelper::GetJsonDatasFromCAD("{}");
	//int ret = CbmClientHelper::VerifyMineAccount("dlj", "123");
	//acutPrintf(_T("\n验证结果:%d"), ret);	
	CbmClientHelper::SendCommandToCAD("regen");
}

void CmdHelper::TestWinHttpClient()
{
	// Set URL.
	WinHttpClient client(_T("http://localhost/tt/test.php"));

	// Send http request, a GET request by default.
	client.SendHttpRequest();
	string data = "title=测试1&content=看你的了";
	client.SetAdditionalDataToSend((BYTE *)data.c_str(), data.size());

	// The response header.
	CString httpResponseHeader = client.GetResponseHeader().c_str();
	// The response content.
	CString httpResponseContent = client.GetResponseContent().c_str();
}
