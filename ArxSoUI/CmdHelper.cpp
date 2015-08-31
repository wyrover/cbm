#include "StdAfx.h"
#include "CmdHelper.h"
#include "Data.h"

#include <Util/HelperClass.h>
#include <ArxHelper/HelperClass.h>

//#include <DefGE/Tunnel.h>
//#include <DefGE/CoalSurface.h>

void CmdHelper::DrawTunnel()
{
	//AcGePoint3d startPt, endPt;
	//double angle;
	//if( !PromptSEPt( _T( "巷道" ), startPt, endPt, angle ) ) return;

	//// 3、创建图元
	//Tunnel* pTunnel = new Tunnel( startPt, endPt );  // 巷道

	//// 4、初始化并提交到数据库
	//if( !ArxUtilHelper::PostToModelSpace( pTunnel ) ) 
	//{
	//	delete pTunnel; pTunnel = 0;
	//}
	//else
	//{
	//	TunnelLink tunnel_link;
	//	tunnel_link.setDataSource(pTunnel->objectId());
	//	tunnel_link.m_width = 40;
	//	tunnel_link.m_height = 50;
	//	tunnel_link.m_projType = 0;
	//	tunnel_link.update(true);
	//}
}

void CmdHelper::TestTunnel()
{
	AcDbObjectId objId = ArxUtilHelper::SelectObject( _T( "请选择一个图元实体:" ) );
	if( objId.isNull() ) return;
	
	//初始化建立8个数据
	//TestLink::Init(objId, 8);

	TestLink tunnel_link;
	tunnel_link.setDataSource(objId);
	tunnel_link.m_width = 400;
	tunnel_link.m_height = 500;
	tunnel_link.m_projType = 110;
	tunnel_link.update(true);
}

void CmdHelper::DrawCoalSurf()
{
	//AcGePoint3d pt;
	//if(!ArxUtilHelper::PromptPt( _T( "\n请选择插入点坐标" ), pt )) return;

	//// 3、创建图元
	//CoalSurface* pCS = new CoalSurface();
	//pCS->setInsertPt(pt);

	//// 4、初始化并提交到数据库
	//if( !ArxUtilHelper::PostToModelSpace( pCS ) ) 
	//{
	//	delete pCS; pCS = 0;
	//}
	//else
	//{
	//	CoalSurfaceLink cs_link;
	//	cs_link.setDataSource(pCS->objectId());
	//	cs_link.m_width = 300;
	//	cs_link.m_height = 1200;
	//	cs_link.m_angle = 8;
	//	cs_link.m_thick = 5;
	//	cs_link.update(true);
	//}
}

void CmdHelper::TestCoalSurf()
{

}

