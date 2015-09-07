#pragma once

#include "Data.h"
#include "Graph.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

namespace P1
{

//剖面图绘制基类
class Graph : public BaseGraph
{
protected:
	//绘制钻场
	virtual void drawSites() = 0;
	//绘制钻孔
	virtual void drawPores() = 0;
	//绘制底板岩巷
	virtual void drawRockTunnel() = 0;
	//绘制工作面的3条巷道
	virtual void drawTunnel() = 0;
	//绘制煤层
	virtual void drawCoal() = 0;

protected:
	//构造函数
	Graph(const cbm::CoalPtr& coal, const cbm::DesignDrillingSurfTechnologyPtr& tech);
	//执行具体的绘图工作(绘制煤层、工作面巷道、钻场、钻孔、底板岩巷)
	virtual void subDraw();

	/** 辅助计算方法. */
protected:
	//计算煤层的尺寸(长-倾向, 宽-走向, 高-厚度)
	void caclCoalExtent(double& Lc, double& Wc, double& Hc) const;
	AcGePoint3d caclCoalBasePoint1() const;
	AcGePoint3d caclCoalBasePoint2() const;
	AcGePoint3d caclCoalBasePoint3() const;
	//计算钻孔的尺寸(长宽高)
	void caclPoreExtent(double& Lp, double& Wp, double& Hp) const;
	AcGePoint3d caclPoreBasePoint1() const;
	AcGePoint3d caclPoreBasePoint2() const;
	//计算钻场的基点位置
	//绘制一条巷道巷道上的钻场(gap_y有正负之分,决定钻场在巷道的哪一侧)
	void drawSitesOnTunnel(const AcGePoint3d& spt, const AcGePoint3d& ept, double gap_x, double gap_y, double w, double h, double angle=0, bool excludeFirst=true);

	/** 计算和绘图用到的参数. */
protected:
	//倾向长度和走向长度
	double L1, L2;
	//煤层厚度和倾角(弧度)
	double thick, angle;
	//工作面巷道的宽度和高度
	double w, h;
	//钻场长宽高以及钻场间距
	double Ls, Ws, Hs, site_gap;
	//底板巷的宽度和高度
	double wd, hd;
	//左右上下帮距
	double left, right, top, bottom;
	//岩巷和工作面的水平投影距离、垂距
	double h_offset, v_offset;
	//钻孔半径和抽采半径
	double radius, pore_gap;
	//上下左右边距(仅用于绘图美观,不参与实际计算)
	double left_margin, right_margin, top_margin, bottom_margin;

	/** 上述计算参数都是从这2个对象指针中提取出来的. */
protected:
	cbm::CoalPtr coal;                 // 煤层指针
	cbm::DesignDrillingSurfTechnologyPtr tech;  // 设计掘进工作面指针

}; // class Graph

//平面图(注:内部计算忽略了巷道的宽度值)
//以工作面切眼巷道的中点为原点,煤层倾向方向为x轴正方向,走向方向(机巷->风巷)为y轴正方向
class PlanGraph : public Graph
{
public:
	PlanGraph(const cbm::CoalPtr& coal, const cbm::DesignDrillingSurfTechnologyPtr& tech);

protected:
	//绘制钻场
	virtual void drawSites();
	//绘制钻孔
	virtual void drawPores();
	//绘制底板岩巷
	virtual void drawRockTunnel();
	//绘制工作面的3条巷道
	virtual void drawTunnel();
	//绘制煤层
	virtual void drawCoal();
}; // class PlanGraph

//倾向剖面图
//以工作面切眼巷道沿倾向剖面的的中点为原点,煤层倾向方向为x轴正方向,巷道的高度方向为y轴正方向
class HeadGraph : public Graph
{
public:
	HeadGraph(const cbm::CoalPtr& coal, const cbm::DesignDrillingSurfTechnologyPtr& tech);

protected:
	//绘制钻场
	virtual void drawSites();
	//绘制钻孔
	virtual void drawPores();
	//绘制底板岩巷
	virtual void drawRockTunnel();
	//绘制工作面的3条巷道
	virtual void drawTunnel();
	//绘制煤层
	virtual void drawCoal();
}; // class HeadGraph

//走向剖面图(利用自定义ucs简化计算过程)
//以工作面切眼巷道的中点为原点,煤层走向方向(风巷->机巷)为x轴正方向,剖面的向上方向为y轴正方向
class DipGraph : public Graph
{
public:
	DipGraph(const cbm::CoalPtr& coal, const cbm::DesignDrillingSurfTechnologyPtr& tech);

protected:
	//绘制钻场
	virtual void drawSites();
	//绘制钻孔
	virtual void drawPores();
	//绘制底板岩巷
	virtual void drawRockTunnel();
	//绘制工作面的3条巷道
	virtual void drawTunnel();
	//绘制煤层
	virtual void drawCoal();
}; // class DipGraph

} // namespace P1