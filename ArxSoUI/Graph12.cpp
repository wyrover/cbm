#include "StdAfx.h"
#include "Graph12.h"

#include <ArxHelper/HelperClass.h>
#include "CbmClientHelper.h"

namespace P12
{

    Graph::Graph( cbm::Coal& _coal, cbm::DesignDrillingSurfTechnology& _tech )
        : BaseGraph(), coal( _coal ), tech( _tech )
    {
        left_margin = 20;
        right_margin = 20;
        bottom_margin = 20;
        top_margin = 20;

        //倾向长度和走向长度
        L1 = tech.l1, L2 = tech.l2;
        //煤层厚度和倾角(弧度)
        thick = coal.thick, angle = DegToRad( coal.dip_angle );
        //工作面巷道的宽度和高度
        w = tech.w, h = tech.h;
        //左右上下帮距
        left = tech.left_side, right = tech.right_side;
        top = tech.top_side, bottom = tech.bottom_side;
        //钻孔半径和钻孔底间距(孔径的单位是mm)
        radius = tech.dp * 0.5 * 0.001, pore_gap = tech.gbp;
        //钻孔超前距
        leading = tech.leading_dist;
        //钻孔控制条带长度
        L_stripe = tech.l_stripe;
    }

    void Graph::subDraw()
    {
        //绘制图形
        drawCoal();
        drawTunnel();
        drawPores();
    }

    void Graph::caclCoalExtent( double& Lc, double& Wc, double& Hc ) const
    {
        //计算宽度(倾向长度L2+工作面左帮控制范围left+偏移)
        //Lc = (L1 + left + left_margin + right_margin)*cos(angle);
        Lc = L1 + left + left_margin + right_margin;
        //Wc = L2 + left + right + bottom_margin + top_margin;
        Wc = w + left + right + bottom_margin + top_margin;
        Hc = thick;
    }

    PlanGraph::PlanGraph( cbm::Coal& coal, cbm::DesignDrillingSurfTechnology& tech ) : Graph( coal,  tech )
    {
    }

    void PlanGraph::drawPores()
    {
        if( pore_gap <= 0 ) return;

        //巷道的中点位置作为基点
        AcGePoint3d basePt = getPoint();
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;

        //绘制钻孔抽采控制范围
        double Lp = 0, Wp = 0, Hp = 0;
        Lp = L1;
        Wp = left + right + w;
        drawLine( basePt + v1 * 0 + v2 * Wp * 0.5, 0, Lp );
        drawLine( basePt + v1 * 0 - v2 * Wp * 0.5, 0, Lp );

        //计算扇形钻孔在抽采轮廓线的水平间距
        double L0 = leading, W0 = left, D = pore_gap, Ls = L_stripe;
        DoubleArray h_dists;
        ArxDrawHelper::Solve1( L0, W0, D, L_stripe - leading, h_dists );

        //计算扇形钻孔在条带边界上的垂直间距
        DoubleArray v_dists;
        ArxDrawHelper::Solve2( Ls, W0, D, v_dists );

        //标注
        this->drawAlignedDim( basePt, basePt + v1 * Ls, 50, false );      //条带范围
        this->drawAlignedDim( basePt + v1 * ( Ls - L0 ), basePt + v1 * Ls, 30, false ); //钻孔超前距

        //计算每个条带的起始位置
        AcGePoint3dArray pts;
        ArxDrawHelper::Divide( basePt, basePt + v1 * L1, L_stripe - leading, 0, pts, true );
        for( int i = 0; i < pts.length(); i++ )
        {
            //绘制掘进面
            AcGePoint3d pt = pts[i];
            drawLine( pt - v2 * w * 0.5, pt + v2 * w * 0.5 );
            //绘制掘进面的起始垂线
            drawLine( pt - v2 * W0, pt + v2 * W0 );

            //记录钻孔图元id
            AcDbObjectIdArray objIds;

            //超前距的断面中心点坐标
            AcGePoint3d poreBeginPt = pt + v1 * L0;
            //绘制上部轮廓线的扇形钻孔
            double pore_dist = 0;
            for( int j = 0; j < h_dists.size(); j++ )
            {
                AcDbObjectId poreId = drawLine( pt, poreBeginPt + v1 * pore_dist + v2 * W0 );
                pore_dist += h_dists[j];
                objIds.append( poreId );
            }
            //绘制下部轮廓线的扇形钻孔
            pore_dist = 0;
            for( int j = 0; j < h_dists.size(); j++ )
            {
                AcDbObjectId poreId = drawLine( pt, poreBeginPt + v1 * pore_dist - v2 * W0 );
                pore_dist += h_dists[j];
                objIds.append( poreId );
            }

            //绘制上部条带断面的扇形钻孔
            pore_dist = 0;
            for( int j = 0; j < v_dists.size(); j++ )
            {
                AcDbObjectId poreId = drawLine( pt, pt + v1 * Ls + v2 * ( W0 + pore_dist ) );
                pore_dist -= v_dists[j];
                objIds.append( poreId );
            }
            //绘制下部条带断面的扇形钻孔
            pore_dist = 0;
            for( int j = 0; j < v_dists.size(); j++ )
            {
                AcDbObjectId poreId = drawLine( pt, pt + v1 * Ls - v2 * ( W0 + pore_dist ) );
                pore_dist -= v_dists[j];
                objIds.append( poreId );
            }

            //绘制中心线的钻孔
            {
                AcDbObjectId poreId = drawLine( pt, pt + v1 * Ls );
                objIds.append( poreId );
            }

            // 绘制条带断面
            AcGePoint3d poreEndPt = pt + v1 * L_stripe;
            drawLine( poreEndPt - v2 * W0, poreEndPt + v2 * W0 );

            //i为奇数修改线型为虚线
            if( i % 2 != 0 )
            {
                ArxDrawHelper::SetLineType( objIds, _T( "JIS_02_0.7" ) );
            }
            objIds.removeAll();
        }
    }

    void PlanGraph::drawTunnel()
    {
        //巷道的中点位置作为基点
        AcGePoint3d basePt = getPoint();
        //绘制掘进巷
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcDbObjectId t1 = this->drawDoubleLine( basePt, basePt + v1 * L1, w );
    }

    void PlanGraph::drawCoal()
    {
        //计算煤层的长宽高
        double Lc = 0, Wc = 0, Hc = 0;
        caclCoalExtent( Lc, Wc, Hc );

        //计算平面图中煤层的左下角基点坐标
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, -1 * left_margin, v2, -0.5 * Wc );

        //绘制煤层面
        AcDbObjectId coalId = this->drawRect2( basePt, 0, Lc, Wc );
        this->drawAlignedDim( basePt, basePt + v1 * Lc, 50, false );
        this->drawAlignedDim( basePt, basePt + v2 * Wc, 30, true );
    }
} // namespace P12