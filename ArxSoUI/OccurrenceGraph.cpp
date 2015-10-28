#include "stdafx.h"
#include "OccurrenceGraph.h"

OccurrenceGraph::OccurrenceGraph(cbm::MinePtr _mine) : mine(_mine)
{
	L1 = 1000;
}

void OccurrenceGraph::subDraw()
{
	//绘制图形
	drawAllCoals(this->mine);
}

void OccurrenceGraph::drawCoal(cbm::CoalPtr coal, const AcGePoint3d& basePt)
{
	//煤层倾角
	double angle = DegToRad( coal->dip_angle );
	//煤层厚度
	double thick = coal->thick;
	
	//绘制煤层(以煤层的左下角位置为基点)
	AcDbObjectId coalId = this->drawRect2( basePt, angle, L1, thick );
	//标注煤层编号
	AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
	v1.rotateBy(angle, AcGeVector3d::kZAxis);
	v2.rotateBy(angle, AcGeVector3d::kZAxis);

	this->drawMText( basePt + v1 * L1 *0.5 + v2 * thick * 0.5, angle, coal->name, 10 );
	//标注煤层厚度
	this->drawAlignedDim(basePt+v1*L1, basePt+v1*L1+v2*thick, 30, false);
}

void OccurrenceGraph::drawAllCoals(cbm::MinePtr mine)
{
	//查找矿井的所有煤层
	orm::RecordPtrListPtr coal_lists = FIND_MANY(Coal, FKEY(Mine), mine->getStringID());
	if(coal_lists == 0) return;
	
	AcGePoint3d basePt;
	for( int i = 0; i < coal_lists->size(); i++ )
	{
		cbm::CoalPtr coal = DYNAMIC_POINTER_CAST( cbm::Coal, coal_lists->at( i ) );
		if(coal == 0) continue;
		
		//与上覆煤层的间距
		double layer_gap = coal->layer_gap;
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
