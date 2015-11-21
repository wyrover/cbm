#include "StdAfx.h"
#include "Graph11.h"

#include <ArxHelper/HelperClass.h>
#include "CbmClientHelper.h"
#include "SQLClientHelper.h"

#include <numeric>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "AcFstream.h"

#include <sstream>
std::string Int2Str(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

namespace P11
{
	// 删除抽采技术下的所有钻场和钻孔
	static void DeleteAllSiteAndPore(int design_id)
	{
		// 查找与该技术关联的所有
		std::vector<int32_t> site_ids;
		SQLClientHelper::GetDesignSiteIdListByForeignKey(site_ids, "design_technology_id", design_id);

		// 删除所有的钻场(数据库会自动删除包含的钻孔)
		SQLClientHelper::DeleteMoreDesignSite(site_ids);
	}

	static void CaclSitesOnTunnel( AcGePoint3dArray& pts, const AcGePoint3d& spt, const AcGePoint3d& ept, double gap_x, double gap_y, double w=0, double h=0, double angle=0, bool excludeFirst=true )
	{
		AcGePoint3dArray temp_pts;
		ArxDrawHelper::Divide( spt, ept, gap_x, gap_y, temp_pts, true );
		//acutPrintf(_T("\n划分钻场的临时点个数:%d"), temp_pts.length());
		int start = excludeFirst ? 1 : 0; // 是否绘制第一个钻场
		for(int i=start;i<temp_pts.length();i++)
		{
			pts.append(temp_pts[i]);
		}
	}

	PoreHelper::PoreHelper(cbm::Coal& _coal, cbm::DesignDrillingSurfTechnology& _tech)
		: coal( _coal ), tech( _tech )
	{
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
	}

	void PoreHelper::cacl()
	{
		// 删除所有的钻场和钻孔
		DeleteAllSiteAndPore(tech.design_technology_id);

		// 工作面巷道的中点作为原点
		AcGePoint3d orig(AcGePoint3d::kOrigin);

		// 钻孔控制范围
		double Lc = left + L1, Wc = L2 + top + bottom;
		// 控制范围左下角的坐标(钻孔的原点)
		AcGeVector3d v1(AcGeVector3d::kXAxis), v2(AcGeVector3d::kYAxis), v3(AcGeVector3d::kZAxis);
		AcGePoint3d pore_orig = orig + v1*left*-1 + v2*(0.5*L2+left)*-1 + v3*top;
		
		//扣除右帮
		double Ld = L1 - right;

		// 划分网格计算所有的钻孔坐标
		// 假设所有的终孔都在同一个水平面上
		AcGePoint3dArray pore_pts;
		ArxDrawHelper::MakeGridWithHole( pore_orig, Lc, Wc, pore_gap, pore_gap, 0, Lc, 0, Wc, pore_pts, true );

		//计算钻孔在走向(长)和倾向(宽)的个数(行或列)
		int nx = ArxDrawHelper::DivideNum( Lc, pore_gap, true );
		int ny = ArxDrawHelper::DivideNum(Wc, pore_gap, true);
		//计算走向(长)方向的钻场数(行或列)
		int nd = ArxDrawHelper::DivideNum( Ld, site_gap, true ) - 1;
		//计算倾向(宽)方向的钻场数(行或列)
		int nk = ArxDrawHelper::DivideNum( L2, site_gap, true ) - 1;
		//左右两帮范围内的钻孔数(行或列)
		int n1 = ArxDrawHelper::DivideNum( left + right, pore_gap, true );
		//每个钻场之间的钻孔个数
		int dn = ArxDrawHelper::DivideNum( site_gap, pore_gap, true );

		acutPrintf(_T("\n钻孔走向个数:%d  倾向个数:%d  钻孔点总个数:%d"), nx, ny, pore_pts.length());
		acutPrintf(_T("\n钻场走向个数:%d  倾向个数:%d, 两帮范围钻孔个数:%d  钻场之间的个数:%d"), nd, nk, n1, dn);
		// 计算钻场的坐标(CaclSitesOnTunnel函数的后3个参数目前没有用到!!!)
		// (0)工作面底板岩巷的中点坐标
		AcGePoint3d site_orig = orig + v1*right + v2*h_offset + v3*v_offset*-1;
		// (1)计算机巷的钻场坐标
		AcGePoint3dArray site_pts1;
		CaclSitesOnTunnel( site_pts1, site_orig - v2 * L2 * 0.5, site_orig + v1 * Ld - v2 * 0.5 * L2, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0 );
		// (2)计算风巷的钻场坐标
		AcGePoint3dArray site_pts2;
		CaclSitesOnTunnel( site_pts2, site_orig + v2 * L2 * 0.5, site_orig + v1 * Ld + v2 * L2 * 0.5, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0 );
		// (3)计算工作面底板岩巷的钻场坐标
		AcGePoint3dArray site_pts3;
		CaclSitesOnTunnel( site_pts3, site_orig - v2 * L2 * 0.5, site_orig + v2 * L2 * 0.5, site_gap, 0.5 * ( Ws + wd ), Ls, Ws, -PI * 0.5 );

		// 机巷控制的钻孔行数和列数
		int row1 = n1;
		int col1 = nx - n1;
		// 风巷控制的钻孔行数和列数
		int row2 = n1;
		int col2 = nx - n1;
		// 工作面底板岩巷控制的钻孔行数和列数
		int row3 = ny;
		int col3 = n1;

		acutPrintf(_T("\n机巷的钻孔行数和列数:%d和%d"), row1, col1);
		acutPrintf(_T("\n风巷的钻孔行数和列数:%d和%d"), row2, col2);
		acutPrintf(_T("\n工巷的钻孔行数和列数:%d和%d"), row3, col3);

		// 分配工作面底板岩巷控制的钻孔(每个钻场分配xx行)
		IntArray nums3(site_pts3.length(), 0);
		nums3[0] += col3; // 垂直长度也等于left+right,所以直接用col3的数据
		nums3[0] += dn/2;  // 该条巷道从下至上的第一个钻场还需要负责一部分钻孔(任务较重啊)
		for(int i=1;i<site_pts3.length();i++)
		{
			nums3[i] += dn;
		}
		// 微调最后一个钻场的钻孔个数
		int S3 = std::accumulate(nums3.begin(), nums3.end(), 0);
		// 如果有多余的钻孔没分完,直接加到最后一个钻场上
		// 如果钻孔不够,则从最后一个钻场上减去超出的部分
		nums3.back() += row3 - S3;
		acutPrintf(_T("\n工作面钻场控制的钻孔数据:"));
		for(int i=0;i<nums3.size();i++)
		{
			acutPrintf(_T("%d  "), nums3[i]);
		}
		acutPrintf(_T("总计:%d\n"), std::accumulate(nums3.begin(), nums3.end(), 0));

		// 分配机巷控制的钻孔(每个钻场分配xx列)
		IntArray nums1(site_pts1.length(), 0);
		nums1[0] += dn/2;
		for(int i=0;i<nums1.size();i++)
		{
			nums1[i] += dn;
		}
		int S1 = std::accumulate(nums1.begin(), nums1.end(), 0);
		nums1.back() += col1 - S1;
		
		acutPrintf(_T("\n机巷钻场控制的钻孔数据:"));
		for(int i=0;i<nums1.size();i++)
		{
			acutPrintf(_T("%d  "), nums1[i]);
		}
		acutPrintf(_T("总计:%d\n"), std::accumulate(nums1.begin(), nums1.end(), 0));

		// 分配风巷控制的钻孔
		IntArray nums2;
		std::copy(nums1.begin(), nums1.end(), std::back_inserter(nums2));

		acutPrintf(_T("\n风钻场控制的钻孔数据:"));
		for(int i=0;i<nums2.size();i++)
		{
			acutPrintf(_T("%d  "), nums2[i]);
		}
		acutPrintf(_T("总计:%d\n"), std::accumulate(nums2.begin(), nums2.end(), 0));

		// 输出钻孔数据文件(或json格式)
		AcOfstream outfile(_T("test.txt"));

		// 记录所有的钻孔
		std::vector<cbm::DesignPore> pores;
		// 记录所有的钻场
		std::vector<cbm::DesignSite> sites;

		// (1)输出机巷的数据
		int n = site_pts1.length();
		// 钻孔编号
		int m = 1;
		// 倒过来输出(从右至左)
		int r1 = row1;
		int r2 = 0;
		int c1 = nx;
		int c2 = nx;
		for(int i=n-1;i>=0;i--)
		{
			// 钻场坐标x,y,z
			AcGePoint3d site_pt = site_pts1[i];

			//新建钻场
			cbm::DesignSite site;
			site.name = Int2Str(n-i);
			site.x = site_pt.x;
			site.y = site_pt.y;
			site.z = site_pt.z;
			site.design_technology_id = tech.design_technology_id; // 关联技术id
			// 提交到数据库
			int32_t site_id = SQLClientHelper::AddDesignSite(site);
			if(site_id <= 0) 
			{
				acutPrintf(_T("\n添加钻场到数据库失败!!!"));
				break;
			}

			// 钻场的行列起始位置
			c2 -= nums1[i];
			acutPrintf(_T("\n机巷---钻场%d的行:%d~%d, 列:%d~%d"), n-i, r1, r2, c1, c2);
			// 钻孔坐标
			for(int j=r1-1;j>=r2;j--)
			{
				for(int k=c1-1;k>=c2;k--)
				{
					// 编号规则: 巷道编号-钻场编号-钻孔编号
					CString num;
					num.Format(_T("%d-%d-%d"), 1, n-i, m);
					outfile << (LPCTSTR)num << _T('\t');
					outfile << site_pt.x << _T('\t') << site_pt.y << _T('\t') << site_pt.z << _T('\t');
					AcGePoint3d pore_pt = pore_pts[j*nx+k];
					outfile<<pore_pt.x<<_T('\t')<<pore_pt.y<<_T('\t')<<pore_pt.z<<_T('\n');

					// 新建钻孔
					cbm::DesignPore pore;
					pore.name = W2C((LPCTSTR)num);
					pore.x1 = site_pt.x;
					pore.y1 = site_pt.y;
					pore.z1 = site_pt.z;
					pore.x2 = pore_pt.x;
					pore.y2 = pore_pt.y;
					pore.z2 = pore_pt.z;
					AcGeVector3d v = pore_pt - site_pt;
					pore.length = v.length();  // 钻孔长度
					ArxDrawHelper::VectorToAngle(v, pore.angle1, pore.angle2);  // 钻孔角度
					pore.design_site_id = site_id;
					// 记录新建的钻孔对象
					pores.push_back(pore);
					// 钻孔编号加1
					m++;
				}
			}
			c1 = c2;
		}
		outfile<< _T("END\n");

		// (2)输出风巷的数据
		/*int*/ n = site_pts2.length();
		// 钻孔编号
		/*int*/ m = 1;
		// 倒过来输出(从右至左)
		/*int*/ r1 = ny;
		/*int*/ r2 = ny - row2;;
		/*int*/ c1 = nx;
		/*int*/ c2 = nx;
		for(int i=n-1;i>=0;i--)
		{
			// 钻场坐标x,y,z
			AcGePoint3d site_pt = site_pts2[i];

			//新建钻场
			cbm::DesignSite site;
			site.name = Int2Str(n-i);
			site.x = site_pt.x;
			site.y = site_pt.y;
			site.z = site_pt.z;
			site.design_technology_id = tech.design_technology_id; // 关联技术id
			// 提交到数据库
			int32_t site_id = SQLClientHelper::AddDesignSite(site);
			if(site_id <= 0) 
			{
				acutPrintf(_T("\n添加钻场到数据库失败!!!"));
				break;
			}

			// 钻场的行列起始位置
			c2 -= nums2[i];
			acutPrintf(_T("\n风巷---钻场%d的行:%d~%d, 列:%d~%d"), n-i, r1, r2, c1, c2);
			// 钻孔坐标
			for(int j=r1-1;j>=r2;j--)
			{
				for(int k=c1-1;k>=c2;k--)
				{
					// 编号规则: 巷道编号-钻场编号-钻孔编号
					CString num;
					num.Format(_T("%d-%d-%d"), 2, n-i, m);
					outfile << (LPCTSTR)num << _T('\t');
					outfile << site_pt.x << _T('\t') << site_pt.y << _T('\t') << site_pt.z << _T('\t');
					AcGePoint3d pore_pt = pore_pts[j*nx+k];
					outfile<<pore_pt.x<<_T('\t')<<pore_pt.y<<_T('\t')<<pore_pt.z<<_T('\n');

					// 新建钻孔
					cbm::DesignPore pore;
					pore.name = W2C((LPCTSTR)num);
					pore.x1 = site_pt.x;
					pore.y1 = site_pt.y;
					pore.z1 = site_pt.z;
					pore.x2 = pore_pt.x;
					pore.y2 = pore_pt.y;
					pore.z2 = pore_pt.z;
					AcGeVector3d v = pore_pt - site_pt;
					pore.length = v.length();  // 钻孔长度
					ArxDrawHelper::VectorToAngle(v, pore.angle1, pore.angle2);  // 钻孔角度
					pore.design_site_id = site_id;
					// 记录新建的钻孔对象
					pores.push_back(pore);
					// 钻孔编号加1
					m++;
				}
			}
			c1 = c2;
		}
		outfile<< _T("END\n");

		// (3)输出工作面底板岩巷的数据
		/*int*/ n = site_pts3.length();
		// 钻孔编号
		/*int*/ m = 1;
		// 倒过来输出(从右至左)
		/*int*/ r1 = 0;
		/*int*/ r2 = 0;
		/*int*/ c1 = col1;
		/*int*/ c2 = 0;
		for(int i=0;i<n;i++)
		{
			// 钻场坐标(x,y,z
			AcGePoint3d site_pt = site_pts3[i];
			//新建钻场
			cbm::DesignSite site;
			site.name = Int2Str(n-i);
			site.x = site_pt.x;
			site.y = site_pt.y;
			site.z = site_pt.z;
			site.design_technology_id = tech.design_technology_id; // 关联技术id
			// 提交到数据库
			int32_t site_id = SQLClientHelper::AddDesignSite(site);
			if(site_id <= 0) 
			{
				acutPrintf(_T("\n添加钻场到数据库失败!!!"));
				break;
			}

			// 钻场的行列起始位置
			r2 += nums3[i];
			acutPrintf(_T("\n工作面岩巷---钻场%d的行:%d~%d, 列:%d~%d"), n-i, r1, r2, c1, c2);
			// 钻孔坐标
			for(int j=r1;j<r2;j++)
			{
				for(int k=c1-1;k>=c2;k--)
				{
					// 编号规则: 巷道编号-钻场编号-钻孔编号
					CString num;
					num.Format(_T("%d-%d-%d"), 3, i+1, m);
					outfile << (LPCTSTR)num << _T('\t');
					outfile << site_pt.x << _T('\t') << site_pt.y << _T('\t') << site_pt.z << _T('\t');
					AcGePoint3d pore_pt = pore_pts[j*nx+k];
					outfile<<pore_pt.x<<_T('\t')<<pore_pt.y<<_T('\t')<<pore_pt.z<<_T('\n');

					// 新建钻孔
					cbm::DesignPore pore;
					pore.name = W2C((LPCTSTR)num);
					pore.x1 = site_pt.x;
					pore.y1 = site_pt.y;
					pore.z1 = site_pt.z;
					pore.x2 = pore_pt.x;
					pore.y2 = pore_pt.y;
					pore.z2 = pore_pt.z;
					AcGeVector3d v = pore_pt - site_pt;
					pore.length = v.length();  // 钻孔长度
					ArxDrawHelper::VectorToAngle(v, pore.angle1, pore.angle2);  // 钻孔角度
					pore.design_site_id = site_id;
					// 记录新建的钻孔对象
					pores.push_back(pore);
					// 钻孔编号加1
					m++;
				}
			}
			r1 = r2;
		}
		outfile<< _T("END\n");
		outfile.close();

		// 添加到数据库
		SQLClientHelper::AddMoreDesignPore(pores);
	}

    Graph::Graph( cbm::Coal& _coal, cbm::DesignDrillingSurfTechnology& _tech )
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

    PlanGraph::PlanGraph( cbm::Coal& coal, cbm::DesignDrillingSurfTechnology& tech ) : Graph( coal, tech )
    {
    }

    void PlanGraph::drawSites()
    {
        //扣除右帮
        double Ld = L1 - right;

        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right, v2, h_offset );
        //绘制钻场
        drawSitesOnTunnel( basePt - v2 * L2 * 0.5, basePt + v1 * Ld - v2 * 0.5 * L2, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0 );
        drawSitesOnTunnel( basePt - v2 * L2 * 0.5, basePt + v2 * L2 * 0.5, site_gap, 0.5 * ( Ws + wd ), Ls, Ws, -PI * 0.5 );
        drawSitesOnTunnel( basePt + v2 * L2 * 0.5, basePt + v1 * Ld + v2 * L2 * 0.5, site_gap, -0.5 * ( Ws + wd ), Ls, Ws, 0 );
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
        ArxDrawHelper::MakeGridWithHole( basePt, Lp, Wp, pore_gap, pore_gap, left + right, 0, left + right, left + right, pts, true );
        for( int i = 0; i < pts.length(); i++ )
        {
            AcDbObjectId poreId = this->drawCircle( pts[i], radius );
        }
    }

    void PlanGraph::drawRockTunnel()
    {
        //扣除偏移的部分
        double Ld = L1 - right;

        //绘制底板岩巷
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right, v2, h_offset );
        AcDbObjectId t1 = this->drawDoubleLine( basePt - v2 * L2 * 0.5, basePt + v1 * Ld - v2 * L2 * 0.5, wd );
        //绘制上区段岩巷
        AcDbObjectId t2 = this->drawDoubleLine( basePt + 0.5 * v2 * L2, basePt + v1 * Ld + 0.5 * v2 * L2, wd );
        //绘制切眼
        AcDbObjectId t3 = this->drawDoubleLine( basePt - v2 * L2 * 0.5, basePt + v2 * L2 * 0.5, wd );
        this->drawMText( basePt + v1 * Ld - v2 * L2 * 0.5, 0, _T( "底板岩巷" ), 10 );
        this->drawMText( basePt + v1 * Ld + v2 * L2 * 0.5, 0, _T( "上区段岩巷" ), 10 );
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
        this->drawAlignedDim( basePt, basePt + AcGeVector3d::kXAxis * Lc, 50, false );
        this->drawAlignedDim( basePt, basePt + AcGeVector3d::kYAxis * Wc, 30, true );
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

    HeadGraph::HeadGraph( cbm::Coal& coal, cbm::DesignDrillingSurfTechnology& tech ) : Graph( coal, tech )
    {

    }

    void HeadGraph::drawSites()
    {
        //扣除右帮
        double Ld = L1 - right;

        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right, v2, -1 * ( v_offset + 0.5 * thick ) );
        //绘制钻场
        drawSitesOnTunnel( basePt, basePt + v1 * Ld, site_gap, 0, Ls, Ws, 0, false );
    }

    void HeadGraph::drawPores()
    {
        //扣除右帮
        double Ld = L1 - right;

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
        AcGePoint3d siteBasePt = ArxDrawHelper::CaclPt( getPoint(), v1, right, v2, -1 * ( v_offset + 0.5 * thick ) );
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
        //扣除偏移的部分
        double Ld = L1 - right;

        //绘制底板岩巷
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, right, v2, -1 * ( v_offset + 0.5 * thick ) );
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

    DipGraph::DipGraph( cbm::Coal& coal, cbm::DesignDrillingSurfTechnology& tech ) : Graph( coal, tech )
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
        //计算钻孔范围
        double Lp = 0, Wp = 0, Hp = 0;
        caclPoreExtent( Lp, Wp, Hp );

        //计算钻孔在走向方向的个数(只计算在控制范围内的)
        int nx = ArxDrawHelper::DivideNum( left + right, pore_gap, true );

        //计算钻孔的基点
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;

        //计算钻场的基点
        AcGePoint3d rockBasePt = ArxDrawHelper::CaclPt( getPoint(), v1, -1 * h_offset, v2, -1 * v_offset ); //岩巷切眼中点

        AcGePoint3d poreBasePt1 = ArxDrawHelper::CaclPt( getPoint(), v1, -0.5 * Wp, v2, 0.5 * thick + Hp );
        AcGePoint3d siteBasePt1 = rockBasePt - v1 * L2 * 0.5; // 上区段岩巷
        for( int i = 0; i < nx; i++ )
        {
            AcGePoint3d pore_pt = poreBasePt1 + v1 * i * pore_gap + v2 * 0; // 从左至右计算
            AcDbObjectId poreId = this->drawLine( siteBasePt1, pore_pt );
        }

        AcGePoint3d poreBasePt2 = ArxDrawHelper::CaclPt( getPoint(), v1, 0.5 * Wp, v2, 0.5 * thick + Hp );
        AcGePoint3d siteBasePt2 = rockBasePt + v1 * L2 * 0.5; // 底板岩巷
        for( int i = 0; i < nx; i++ )
        {
            AcGePoint3d pore_pt = poreBasePt2 - v1 * i * pore_gap + v2 * 0; // 从右至左计算
            AcDbObjectId poreId = this->drawLine( siteBasePt2, pore_pt );
        }
    }

    void DipGraph::drawRockTunnel()
    {
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        AcGePoint3d basePt = ArxDrawHelper::CaclPt( getPoint(), v1, -1 * h_offset, v2, -1 * v_offset );
        AcDbObjectId t3 = this->drawDoubleLine( basePt - v1 * L2 * 0.5, basePt + v1 * L2 * 0.5, hd ); // 底板切眼
        //为了画出来的巷道(矩形)是水平的,特殊处理下(旋转)
        AcDbObjectId t2 = this->drawRect( basePt - v1 * L2 * 0.5, angle, wd, hd ); // 上区段岩巷
        AcDbObjectId t1 = this->drawRect( basePt + v1 * L2 * 0.5, angle, wd, hd ); // 底板岩巷
    }

    void DipGraph::drawTunnel()
    {
        AcGePoint3d basePt = getPoint();
        AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
        //为了画出来的巷道(矩形)是水平的,特殊处理下(旋转)
        AcDbObjectId t1 = this->drawRect( basePt + v1 * L2 * 0.5, angle, w, h ); // 待掘机巷
        AcDbObjectId t2 = this->drawRect( basePt - v1 * L2 * 0.5, angle, w, h ); // 待掘风巷
        AcDbObjectId t3 = this->drawDoubleLine( basePt-v1*L2*0.5, basePt+v1*L2*0.5, h ); //工作面切眼
    }

    void DipGraph::drawCoal()
    {
        double Lc = 0, Wc = 0, Hc = 0;
        caclCoalExtent( Lc, Wc, Hc );
        AcGePoint3d basePt = caclCoalBasePoint3();

        //绘制煤层
        AcDbObjectId coalId = this->drawRect2( basePt, 0, Wc, Hc );
    }

} // namespace P11