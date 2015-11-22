#include "StdAfx.h"
#include "Graph21.h"

#include <ArxHelper/HelperClass.h>
#include "CbmClientHelper.h"

namespace P21
{

    Graph::Graph( cbm::Coal& _coal, cbm::DesignWorkSurfTechnology& _tech )
        : BaseGraph(), coal( _coal ), tech( _tech )
    {
        left_margin = 20;
        right_margin = 20;
        bottom_margin = 20;
        top_margin = 40;

        //倾向长度和走向长度
        L1 = tech.l1, L2 = tech.l2;
        //煤层厚度和倾角(弧度)
        thick = coal.thick, angle = DegToRad( coal.dip_angle );
        //工作面巷道的宽度和高度
        w = tech.w, h = tech.h;
        //底板巷的宽度和高度
        wd = tech.wd, hd = tech.hd;
        //左右上下帮距
        left = tech.left_side, right = tech.right_side;
        top = tech.top_side, bottom = tech.bottom_side;
        //钻场长度、宽度和高度
        Ls = tech.ls, Ws = tech.ws, Hs = tech.hs;
        //岩巷和工作面的水平投影距离、垂距
        h_offset = tech.h_offset, v_offset = tech.v_offset;
        //钻孔半径和抽采半径(孔径的单位是mm)
        radius = tech.dp * 0.5 * 0.001, pore_gap = tech.gp;
        //钻场间距
        site_gap = tech.gs;
        //只布置一条岩巷
        single_rock_tunnel = ( tech.single_rock_tunnel != 0 );
        //两条岩巷之间的距离
        d_offset = tech.d_offset;
        //底板巷与工作面切眼的水平投影距离
        p_offset = tech.p_offset;
    }

    void Graph::subDraw()
    {
        //绘制图形
        drawCoal();
        drawTunnel();
        drawRockTunnel();
        drawPores();
        drawSites();
    }

    void Graph::caclCoalExtent( double& Lc, double& Wc, double& Hc ) const
    {
        //计算宽度(倾向长度L2+工作面左帮控制范围left+偏移)
        //Lc = (L1 + left + left_margin + right_margin)*cos(angle);
        Lc = L1 + left + left_margin + right_margin;
        Wc = L2 + left + right + bottom_margin + top_margin;
        Hc = thick;
    }

    AcGePoint3d Graph::caclCoalBasePoint1() const
    {
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        return ArxDrawHelper::CaclPt( getPoint(), v1, -1 * ( left + left_margin ), v2, -1 * ( 0.5 * L2 + left + bottom_margin ) );
    }

    AcGePoint3d Graph::caclCoalBasePoint2() const
    {
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        return ArxDrawHelper::CaclPt( getPoint(), v1, -1 * ( left + left_margin ), v2, -0.5 * thick );;
    }

    AcGePoint3d Graph::caclCoalBasePoint3() const
    {
        double Lc = 0, Wc = 0, Hc = 0;
        caclCoalExtent( Lc, Wc, Hc );

        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        return ArxDrawHelper::CaclPt( getPoint(), v1, -0.5 * Wc, v2, -0.5 * thick );;
    }

    void Graph::caclPoreExtent( double& Lp, double& Wp, double& Hp ) const
    {
        //计算长度(倾向长度L2+工作面左帮控制范围left+偏移)
        //Lp = (L1 + left)*cos(angle);
        Lp = L1 + left;
        Wp = L2 + left + right;
        Hp = 0.5;
    }

    AcGePoint3d Graph::caclPoreBasePoint1() const
    {
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        return ArxDrawHelper::CaclPt( getPoint(), v1, -1 * left, v2, -1 * ( left + 0.5 * L2 ) );
    }

    AcGePoint3d Graph::caclPoreBasePoint2() const
    {
        double Lp = 0, Wp = 0, Hp = 0;
        caclPoreExtent( Lp, Wp, Hp );
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        return ArxDrawHelper::CaclPt( getPoint(), v1, -1 * left, v2, 0.5 * thick + Hp );
    }

//绘制一条巷道上的钻场
    void Graph::drawSitesOnTunnel( const AcGePoint3d& spt, const AcGePoint3d& ept, double gap_x, double gap_y, double w, double h, double angle, bool excludeFirst )
    {
        AcGePoint3dArray pts;
        ArxDrawHelper::Divide( spt, ept, gap_x, gap_y, pts, false );
        int start = excludeFirst ? 1 : 0; // 是否绘制第一个钻场
        for( int i = start; i < pts.length(); i++ )
        {
            AcDbObjectId siteId = this->drawRect( pts[i], angle, w, h );
        }
    }

    PlanGraph::PlanGraph( cbm::Coal& coal, cbm::DesignWorkSurfTechnology& tech ) : Graph( coal, tech )
    {
    }

    void PlanGraph::drawSites()
    {
        double right_offset = p_offset;
        double rock_L2 = d_offset;

        //扣除右帮
        double Ld = L1 - right_offset;

        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right_offset, v2, h_offset );
        //绘制钻场
        if( single_rock_tunnel )
        {
            drawSitesOnTunnel( basePt - v2 * rock_L2 * 0.5, basePt + v1 * Ld - v2 * 0.5 * rock_L2, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0, false );
        }
        else
        {
            drawSitesOnTunnel( basePt - v2 * rock_L2 * 0.5, basePt + v1 * Ld - v2 * 0.5 * rock_L2, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0 );
            drawSitesOnTunnel( basePt - v2 * rock_L2 * 0.5, basePt + v2 * rock_L2 * 0.5, site_gap, 0.5 * ( Ws + wd ), Ls, Ws, -PI * 0.5 );
            drawSitesOnTunnel( basePt + v2 * rock_L2 * 0.5, basePt + v1 * Ld + v2 * rock_L2 * 0.5, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0 );
        }
    }

    void PlanGraph::drawPores()
    {
        if( pore_gap <= 0 ) return;

        //计算钻孔平面投影范围
        double Lp = 0, Wp = 0, Hp = 0;
        caclPoreExtent( Lp, Wp, Hp );
        //平面图钻孔范围的左下角基点坐标
        AcGePoint3d basePt = caclPoreBasePoint1();

        //绘制钻孔
        AcGePoint3dArray pts;
        ArxDrawHelper::MakeGridWithHole( basePt, Lp, Wp, pore_gap, pore_gap, 0, Lp, 0, Wp, pts, true );
        for( int i = 0; i < pts.length(); i++ )
        {
            AcDbObjectId poreId = this->drawCircle( pts[i], radius );
        }
    }

    void PlanGraph::drawRockTunnel()
    {
        //double right_offset = right;
        double right_offset = p_offset;
        double rock_L2 = d_offset;

        //扣除偏移的部分
        double Ld = L1 - right_offset;

        //绘制底板岩巷
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right_offset, v2, h_offset );
        AcDbObjectId t1 = this->drawDoubleLine( basePt - v2 * rock_L2 * 0.5, basePt + v1 * Ld - v2 * rock_L2 * 0.5, wd );
        this->drawMText( basePt + v1 * Ld - v2 * rock_L2 * 0.5, 0, _T( "底板岩巷" ), 10 );
        if( !single_rock_tunnel )
        {
            //绘制上区段岩巷
            AcDbObjectId t2 = this->drawDoubleLine( basePt + 0.5 * v2 * rock_L2, basePt + v1 * Ld + 0.5 * v2 * rock_L2, wd );
            //绘制切眼
            AcDbObjectId t3 = this->drawDoubleLine( basePt - v2 * rock_L2 * 0.5, basePt + v2 * rock_L2 * 0.5, wd );
            this->drawMText( basePt + v1 * Ld + v2 * rock_L2 * 0.5, 0, _T( "上区段岩巷" ), 10 );
        }
    }

    void PlanGraph::drawTunnel()
    {
        //工作面巷道的中点位置作为基点
        AcGePoint3d basePt = getPoint();
        //绘制机巷
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcDbObjectId t1 = this->drawDoubleLine( basePt - v2 * L2 * 0.5, basePt + v1 * L1 - v2 * L2 * 0.5, w );
        //绘制风巷
        AcDbObjectId t2 = this->drawDoubleLine( basePt + v2 * L2 * 0.5, basePt + v1 * L1 + v2 * L2 * 0.5, w );
        //绘制工作面切眼
        AcDbObjectId t3 = this->drawDoubleLine( basePt - v2 * L2 * 0.5, basePt + v2 * L2 * 0.5, w );
        this->drawMText( basePt + v1 * L1 - v2 * L2 * 0.5, 0, _T( "待掘机巷" ), 10 );
        this->drawMText( basePt + v1 * L1 + v2 * L2 * 0.5, 0, _T( "待掘风巷" ), 10 );
    }

    void PlanGraph::drawCoal()
    {
        //计算煤层的长宽高
        double Lc = 0, Wc = 0, Hc = 0;
        caclCoalExtent( Lc, Wc, Hc );
        //计算平面图中煤层的左下角基点坐标
        AcGePoint3d basePt = caclCoalBasePoint1();

        //绘制煤层面
        AcDbObjectId coalId = this->drawRect2( basePt, 0, Lc, Wc );
        this->drawAlignedDim( basePt, basePt + AcGeVector3d::kXAxis * Lc, _T(""), 50, false );
        this->drawAlignedDim( basePt, basePt + AcGeVector3d::kYAxis * Wc, _T(""), 30, true );
        //附加数据
        if( !coalId.isNull() )
        {
            CoalData data;
            data.setDataSource( coalId );
            data.m_name = _T( "测试" );
            data.m_thick = coal.thick;
            data.m_angle = coal.dip_angle;
            data.m_width = tech.l1;
            data.m_height = tech.l2;
            data.m_pt = basePt;
            data.update( true );
        }
    }

    HeadGraph::HeadGraph( cbm::Coal& coal, cbm::DesignWorkSurfTechnology& tech ) : Graph( coal, tech )
    {

    }

    void HeadGraph::drawSites()
    {
        double right_offset = p_offset;
        //扣除右帮
        double Ld = L1 - right_offset;

        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right_offset, v2, -1 * ( v_offset + 0.5 * thick ) );
        //绘制钻场
        drawSitesOnTunnel( basePt, basePt + v1 * Ld, site_gap, 0, Ls, Ws, 0, false );
    }

    void HeadGraph::drawPores()
    {
        double right_offset = p_offset;

        //扣除右帮
        double Ld = L1 - right_offset;

        //计算钻孔范围
        double Lp = 0, Wp = 0, Hp = 0;
        caclPoreExtent( Lp, Wp, Hp );

        //计算钻孔在倾向方向的个数
        int nx = ArxDrawHelper::DivideNum( Lp, pore_gap, true );
        //计算钻场的个数
        int nd = ArxDrawHelper::DivideNum( Ld, site_gap, false );

        //第1列钻场(工作面巷道上的布置的钻场)
        int n1 = ArxDrawHelper::DivideNum( left + right, pore_gap, true );
        //每个钻场之间的钻孔个数(倾向方向)
        int dn = ArxDrawHelper::DivideNum( nx, nd, true );
        //第2列钻场
        int n2 = dn + dn / 2;

        //建立钻孔和钻场的个数联系
        IntArray nums;
        nums.push_back( n1 );
        nums.push_back( n2 );
        ArxDrawHelper::Shuffle( nx - n1 - n2, nd - 2, nums );

        //计算钻孔的基点
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d poreBasePt = caclPoreBasePoint2();

        //依次计算钻场与钻孔的关联
        AcGePoint3d siteBasePt = ArxDrawHelper::CaclPt( getPoint(), v1, right_offset, v2, -1 * ( v_offset + 0.5 * thick ) );
        int start = 0;
        for( int i = 0; i < nd; i++ )
        {
            AcGePoint3d site_pt = siteBasePt + v1 * i * site_gap + v2 * 0;
            int end = start + nums[i];
            for( int j = start; j < end; j++ )
            {
                AcGePoint3d pore_pt = poreBasePt + v1 * j * pore_gap + v2 * 0;
                AcDbObjectId poreId = this->drawLine( site_pt, pore_pt );
            }
            start = end;
        }
    }

    void HeadGraph::drawRockTunnel()
    {
        double right_offset = p_offset;

        //扣除偏移的部分
        double Ld = L1 - right_offset;

        //绘制底板岩巷
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right_offset, v2, -1 * ( v_offset + 0.5 * thick ) );
        AcDbObjectId t1 = this->drawDoubleLine( basePt - v1 * Hs * 0.5, basePt + v1 * Ld, wd );
    }

    void HeadGraph::drawTunnel()
    {

    }

    void HeadGraph::drawCoal()
    {
        double Lc = 0, Wc = 0, Hc = 0;
        caclCoalExtent( Lc, Wc, Hc );
        AcGePoint3d basePt = caclCoalBasePoint2();

        //绘制煤层
        AcDbObjectId coalId = this->drawRect2( basePt, 0, Lc, Hc );
    }

    DipGraph::DipGraph( cbm::Coal& coal, cbm::DesignWorkSurfTechnology& tech ) : Graph( coal, tech )
    {
        //建立ucs
        AcGeVector3d xAxis( AcGeVector3d::kXAxis ), yAxis( AcGeVector3d::kYAxis );
        xAxis.rotateBy( -1 * angle, AcGeVector3d::kZAxis );
        yAxis.rotateBy( -1 * angle, AcGeVector3d::kZAxis );
        setUcs( AcGePoint3d::kOrigin, xAxis, yAxis );
    }

    void DipGraph::drawSites()
    {

    }

    void DipGraph::drawPores()
    {
        double rock_L2 = d_offset;

        //计算钻孔范围
        double Lp = 0, Wp = 0, Hp = 0;
        caclPoreExtent( Lp, Wp, Hp );

        //计算钻孔在走向方向的个数(只计算在控制范围内的)
        int nx = ArxDrawHelper::DivideNum( 0.5 * Wp, pore_gap, true );

        //计算钻孔的基点
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d rockBasePt = ArxDrawHelper::CaclPt( getPoint(), v1, -1 * h_offset, v2, -1 * v_offset ); //岩巷切眼中点
        AcGePoint3d siteBasePt1 = rockBasePt - v1 * rock_L2 * 0.5; // 上区段岩巷
        AcGePoint3d siteBasePt2 = rockBasePt + v1 * rock_L2 * 0.5; // 底板岩巷

        if( single_rock_tunnel )
        {
            siteBasePt1 = siteBasePt2;
        }
        //计算钻场的基点
        AcGePoint3d poreBasePt1 = ArxDrawHelper::CaclPt( getPoint(), v1, -0.5 * Wp, v2, 0.5 * thick + Hp );
        for( int i = 0; i < nx; i++ )
        {
            AcGePoint3d pore_pt = poreBasePt1 + v1 * i * pore_gap + v2 * 0; // 从左至右计算
            AcDbObjectId poreId = this->drawLine( siteBasePt1, pore_pt );
        }
        AcGePoint3d poreBasePt2 = ArxDrawHelper::CaclPt( getPoint(), v1, 0.5 * Wp, v2, 0.5 * thick + Hp );
        for( int i = 0; i < nx; i++ )
        {
            AcGePoint3d pore_pt = poreBasePt2 - v1 * i * pore_gap + v2 * 0; // 从右至左计算
            AcDbObjectId poreId = this->drawLine( siteBasePt2, pore_pt );
        }
    }

    void DipGraph::drawRockTunnel()
    {
        double rock_L2 = d_offset;

        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, -1 * h_offset, v2, -1 * v_offset );
        AcDbObjectId t3 = this->drawDoubleLine( basePt - v1 * L2 * 0.5, basePt + v1 * L2 * 0.5, hd ); // 底板切眼
        //为了画出来的巷道(矩形)是水平的,特殊处理下(旋转)
        AcDbObjectId t1 = this->drawRect( basePt + v1 * rock_L2 * 0.5, angle, wd, hd ); // 底板岩巷
        if( !single_rock_tunnel )
        {
            AcDbObjectId t2 = this->drawRect( basePt - v1 * rock_L2 * 0.5, angle, wd, hd ); // 上区段岩巷
        }
    }

    void DipGraph::drawTunnel()
    {
        AcGePoint3d basePt = getPoint();
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        //为了画出来的巷道(矩形)是水平的,特殊处理下(旋转)
        AcDbObjectId t1 = this->drawRect( basePt + v1 * L2 * 0.5, angle, w, h ); // 待掘机巷
        AcDbObjectId t2 = this->drawRect( basePt - v1 * L2 * 0.5, angle, w, h ); // 待掘风巷
        AcDbObjectId t3 = this->drawDoubleLine( basePt - v1 * L2 * 0.5, basePt + v1 * L2 * 0.5, h ); // 工作面切眼
    }

    void DipGraph::drawCoal()
    {
        double Lc = 0, Wc = 0, Hc = 0;
        caclCoalExtent( Lc, Wc, Hc );
        AcGePoint3d basePt = caclCoalBasePoint3();

        //绘制煤层
        AcDbObjectId coalId = this->drawRect2( basePt, 0, Wc, Hc );
    }

} // namespace P21