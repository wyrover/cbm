#pragma once

#include "Data.h"
#include "Graph.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

// 煤层赋存示意图
class OccurrenceGraph : public BaseGraph
{
public:
	OccurrenceGraph(cbm::MinePtr mine);

protected:
	virtual void subDraw();
	//绘制所有煤层
	void drawAllCoals(cbm::MinePtr mine);
	//绘制一个煤层
	void drawCoal(cbm::CoalPtr coal, const AcGePoint3d& basePt);
protected:
	// 矿井数据
	cbm::MinePtr mine;
	// 煤层倾向长度
	//该数据不存在，为了绘图效果美观，内部设定一个值
	double L1;
};