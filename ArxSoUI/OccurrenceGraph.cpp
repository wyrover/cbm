#include "stdafx.h"
#include "OccurrenceGraph.h"

#include <ArxHelper/HelperClass.h>
#include "CbmClientHelper.h"
#include "SQLClientHelper.h"

OccurrenceGraph::OccurrenceGraph(cbm::Mine& _mine, double _factor) : mine(_mine), factor(_factor)
{
	L1 = 100*factor;
}

void OccurrenceGraph::subDraw()
{
	//绘制图形
	drawAllCoals(this->mine);
}

void OccurrenceGraph::drawCoal(cbm::Coal& coal, const AcGePoint3d& basePt)
{
	//煤层倾角
	double angle = DegToRad( coal.dip_angle );
	//煤层厚度
	double thick = coal.thick;
	
	acutPrintf(_T("\n煤层厚度:%.3f"), thick);
	//绘制煤层(以煤层的左下角位置为基点)
	AcDbObjectId coalId = this->drawRect2( basePt, angle, L1, thick );
	//标注煤层编号
	AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
	v1.rotateBy(angle, AcGeVector3d::kZAxis);
	v2.rotateBy(angle, AcGeVector3d::kZAxis);

	this->drawMText( basePt + v1 * L1 *0.5 + v2 * thick * 0.5, angle, C2W(coal.name), 10 );
	//标注煤层厚度
	//this->drawAlignedDim(basePt+v1*L1, basePt+v1*L1+v2*thick, 30, false);
}

void OccurrenceGraph::drawAllCoals(cbm::Mine& mine)
{
	//查找矿井的所有煤层
	std::vector<cbm::Coal> coal_lists;
	SQLClientHelper::GetCoalListByForeignKey(coal_lists, "mine_id", mine.id);
	if(coal_lists.empty()) return;
	
	AcGePoint3d basePt;
	for( int i = 0; i < coal_lists.size(); i++ )
	{
		cbm::Coal& coal = coal_lists[i];
		if(coal.id < 0) continue;
		
		//与上覆煤层的间距
		double layer_gap = coal.layer_gap;
		//当前煤层的基点
		AcGePoint3d pt = basePt - AcGeVector3d::kYAxis*layer_gap;
		//标注煤层间距(第一个煤层的间距不标注)
		if(i > 0)
		{
			this->drawAlignedDim(basePt, pt, 30, false);
		}
		//更新当前煤层的基点
		basePt  = pt;
		//绘制煤层
		this->drawCoal(coal, basePt);
	}
}
