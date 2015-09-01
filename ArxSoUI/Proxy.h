#pragma once

#include "Data.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

//计算相关的一些类

class Draw
{
public:
	static AcDbObjectId CreateDoubleLine(const AcGePoint3d& spt, const AcGePoint3d& ept, double width);
};

class CoalProxy
{
public:
	CoalProxy();
	void draw();

private:
	//绘制钻孔
	void drawPores();
	//绘制底板岩巷
	void drawRockTunnel();
	//绘制工作面的3条巷道
	void drawWsTunnel();
	//绘制煤层投影平面
	void drawCoal();
	//计算煤层的平面投影范围
	void caclCoalExtent(AcGePoint3d& insertPt, double& Wc, double& Hc);
	//计算钻孔的平面投影范围
	void caclPoreExtent(AcGePoint3d& insertPt, double& Wp, double& Hp);

public:
	AcGePoint3d pt;
	cbm::CoalPtr coal;         // 煤层
	cbm::DesignWorkSurfPtr ws; // 设计工作面
	cbm::DesignTechnologyPtr tech; // 设计抽采技术参数

	//上下左右偏移(仅用于绘图美观,不参与实际计算)
	double left_offset, right_offset, top_offset, bottom_offset;
};