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

class Graph
{
public:
	virtual ~Graph() {}
	virtual void draw() = 0;

	void setPoint(const AcGePoint3d& pt);
	AcGePoint3d getPoint() const;

public:
	cbm::CoalPtr coal;         // 煤层
	cbm::DesignWorkSurfPtr ws; // 设计工作面
	cbm::DesignTechnologyPtr tech; // 设计抽采技术参数

protected:
	Graph();
	AcGePoint3d m_basePt; // 工作面中心线基点
	//上下左右偏移(仅用于绘图美观,不参与实际计算)
	double m_left_offset, m_right_offset, m_top_offset, m_bottom_offset;
};

class PlanGraph : public Graph
{
public:
	PlanGraph();
	virtual void draw();

private:
	//绘制钻场
	void drawSites();
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
};

class SectionGraph : public Graph
{
public:
	SectionGraph();
	virtual void draw();

private:
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
};