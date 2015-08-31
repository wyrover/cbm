#include "StdAfx.h"
#include "CmdHelper.h"
#include "Data.h"
#include "DrawTool.h"

#include <Util/HelperClass.h>
#include <ArxHelper/HelperClass.h>

void CmdHelper::DrawTunnel()
{
	//选择2点
	AcGePoint3d startPt, endPt;
	if( !ArxUtilHelper::PromptSEPt( startPt, endPt ) ) return;

	//绘制巷道
	DrawTool::DrawTunnel1(_T("巷道1"), startPt, endPt, 30);
}

void CmdHelper::TestTunnel()
{
	AcDbObjectId objId = ArxUtilHelper::SelectEntity( _T( "请选择一个图元实体:" ) );
	if( objId.isNull() ) return;
	
	TestLink tunnel_link;
	tunnel_link.setDataSource(objId);
	tunnel_link.m_width = 400;
	tunnel_link.m_height = 500;
	tunnel_link.m_projType = 110;
	tunnel_link.update(true);
}

void CmdHelper::DrawCoalSurf()
{
	AcDbObjectIdArray objIds;
	ArxUtilHelper::SelectEntities(objIds);
	ArxGroupHelper::CreateGroup(_T("测试"), objIds);

	ArxEntityHelper::EraseObject2(objIds[0], Adesk::kTrue);
}

void CmdHelper::TestCoalSurf()
{

}

