#include "StdAfx.h"
#include "CmdHelper.h"

#include "SQLClientHelper.h"
#include "CbmClientHelper.h"
#include "Graph11.h"

#include <fstream>
//#include <WinHttpClient.h>
#include <ArxHelper/HelperClass.h>

void CmdHelper::InitAllData()
{
	//初始化必须数据(建立词典、扩展数据appname等)
	SystemHelper::Start();
	//读取字段
	CString appDir = ArxUtilHelper::GetAppPathDir( _hdllInstance );
	FieldHelper::InitDataField( ArxUtilHelper::BuildPath( appDir, _T( "Datas\\煤层气抽采-字段-图元属性.txt" ) ) );
	//加载线型
	acdbHostApplicationServices()->workingDatabase()->loadLineTypeFile( _T( "JIS_02_0.7" ), _T( "acadiso.lin" ) );
}

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
	//// Set URL.
	//WinHttpClient client(_T("http://localhost/tt/test.php"));

	//// Send http request, a GET request by default.
	//client.SendHttpRequest();
	//string data = "title=测试1&content=看你的了";
	//client.SetAdditionalDataToSend((BYTE *)data.c_str(), data.size());

	//// The response header.
	//CString httpResponseHeader = client.GetResponseHeader().c_str();
	//// The response content.
	//CString httpResponseContent = client.GetResponseContent().c_str();
}

void CmdHelper::DrawPlaneGraph11()
{
	int coal_id = -1;
	if(RTNORM != acedGetInt(NULL, &coal_id)) return;
	if(coal_id == -1) return;

	int tech_id = -1;
	if(RTNORM != acedGetInt(NULL, &tech_id)) return;
	if(tech_id == -1) return;

	cbm::Coal coal;
	SQLClientHelper::GetCoalById(coal, coal_id);
	if( coal.id < 0 ) return;

	cbm::DesignDrillingSurfTechnology tws_tech;
	SQLClientHelper::GetDesignDrillingSurfTechnologyById(tws_tech, tech_id);
	if(tws_tech.id < 0 ) return;

	//交互选择基点坐标
	AcGePoint3d pt;
	ArxUtilHelper::PromptPt( _T( "请选择一点:" ), pt );

	//绘制平面图
	P11::PlanGraph graph( coal, tws_tech );
	graph.setPoint( pt );
	graph.draw();
}

void CmdHelper::DrawHeadGraph11()
{
	int coal_id = -1;
	if(RTNORM != acedGetInt(NULL, &coal_id)) return;
	if(coal_id == -1) return;

	int tech_id = -1;
	if(RTNORM != acedGetInt(NULL, &tech_id)) return;
	if(tech_id == -1) return;

	cbm::Coal coal;
	SQLClientHelper::GetCoalById(coal, coal_id);
	if( coal.id < 0 ) return;

	cbm::DesignDrillingSurfTechnology tws_tech;
	SQLClientHelper::GetDesignDrillingSurfTechnologyById(tws_tech, tech_id);
	if(tws_tech.id < 0 ) return;

	//交互选择基点坐标
	AcGePoint3d pt;
	ArxUtilHelper::PromptPt( _T( "请选择一点:" ), pt );

	//绘制平面图
	P11::HeadGraph graph( coal, tws_tech );
	graph.setPoint( pt );
	graph.draw();
}

void CmdHelper::DrawDipGraph11()
{
	int coal_id = -1;
	if(RTNORM != acedGetInt(NULL, &coal_id)) return;
	if(coal_id == -1) return;

	int tech_id = -1;
	if(RTNORM != acedGetInt(NULL, &tech_id)) return;
	if(tech_id == -1) return;

	cbm::Coal coal;
	SQLClientHelper::GetCoalById(coal, coal_id);
	if( coal.id < 0 ) return;

	cbm::DesignDrillingSurfTechnology tws_tech;
	SQLClientHelper::GetDesignDrillingSurfTechnologyById(tws_tech, tech_id);
	if(tws_tech.id < 0 ) return;

	//交互选择基点坐标
	AcGePoint3d pt;
	ArxUtilHelper::PromptPt( _T( "请选择一点:" ), pt );

	//绘制平面图
	P11::DipGraph graph( coal, tws_tech );
	graph.setPoint( pt );
	graph.draw();
}
