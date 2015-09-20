#pragma once

#include "Data.h"
#include "Graph.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

namespace P23
{

    //剖面图绘制基类
    class Graph : public BaseGraph
    {
    protected:
        //绘制钻孔
        virtual void drawPores() = 0;
        //绘制巷道
        virtual void drawTunnel() = 0;
        //绘制煤层
        virtual void drawCoal() = 0;

    protected:
        //构造函数
        Graph( const cbm::CoalPtr& coal, const cbm::DesignWorkSurfTechnologyPtr& tech );
        //执行具体的绘图工作(绘制煤层、工作面巷道、钻场、钻孔等等)
        virtual void subDraw();

        /** 辅助计算方法. */
    protected:
        //计算煤层的尺寸(长-倾向, 宽-走向, 高-厚度)
        void caclCoalExtent( double& Lc, double& Wc, double& Hc ) const;

        /** 计算和绘图用到的参数. */
    protected:
        //倾向长度和走向长度
        double L1, L2;
        //煤层厚度和倾角(弧度)
        double thick, angle;
        //工作面巷道的宽度和高度
        double w, h;
        //钻孔半径、钻孔底间距、钻孔压茬长度、顺层斜交钻孔倾角
        double radius, pore_gap, pore_stubble, pore_angle;
        //顺层钻孔类型
        int pore_type;

        //上下左右边距(仅用于绘图美观,不参与实际计算)
        double left_margin, right_margin, top_margin, bottom_margin;

        /** 上述计算参数都是从这3个对象指针中提取出来的. */
    protected:
        cbm::CoalPtr coal;                 // 煤层指针
        cbm::DesignWorkSurfTechnologyPtr tech;     // 设计抽采技术参数指针

    }; // class Graph

    //平面图
    //以掘进巷道的起点为原点,掘进方向作为x轴正方向，垂直向上的方向为y轴正方向
    class PlanGraph : public Graph
    {
    public:
        PlanGraph( const cbm::CoalPtr& coal, const cbm::DesignWorkSurfTechnologyPtr& tech );

    protected:
        //绘制钻孔
        virtual void drawPores();
        //绘制巷道
        virtual void drawTunnel();
        //绘制煤层
        virtual void drawCoal();

    private:
        void drawParallelPores();
        void drawCrossPores();
    }; // class PlanGraph

} // namespace P23