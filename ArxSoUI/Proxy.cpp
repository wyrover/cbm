#include "StdAfx.h"
#include "Proxy.h"

#include <Util/HelperClass.h>
#include <ArxHelper/HelperClass.h>

//绘制双线
class DoubleLine
{
public:
	DoubleLine(const AcGePoint3d& spt, const AcGePoint3d& ept, double width)
		: m_spt(spt), m_ept(ept), m_width(width)
	{

	}
	AcDbObjectId draw()
	{
		//计算始端的2个坐标
		AcGePoint3d m_leftStartPt, m_leftEndPt;
		AcGePoint3d m_rightStartPt, m_rightEndPt;
		caclStartPoint(m_leftStartPt, m_rightStartPt);
		//计算末端的2个坐标
		caclEndPoint(m_leftEndPt, m_rightEndPt);
		//绘制2条直线
		AcDbObjectId line1 = ArxDrawHelper::DrawLine( m_leftStartPt, m_leftEndPt );
		AcDbObjectId line2 = ArxDrawHelper::DrawLine( m_rightStartPt, m_rightEndPt );

		//构造group
		AcDbObjectIdArray objIds;
		objIds.append(line1);
		objIds.append(line2);
		//构造临时的组名
		CString name;
		name.Format(_T("巷道%d"), count++);
		AcDbObjectId groupId = ArxGroupHelper::CreateGroup(name, objIds);
		if(!groupId.isNull())
		{
			ArxGroupHelper::ConvertToAnonymousGroup(groupId);
		}
		return groupId;
	}

protected:
	void caclStartPoint( AcGePoint3d& startPt1, AcGePoint3d& startPt2 )
	{
		AcGeVector3d v = m_ept - m_spt;
		v.normalize();

		v.rotateBy( PI * 0.5, AcGeVector3d::kZAxis );
		startPt1 = m_spt + v * m_width * 0.5;

		v.rotateBy( PI, AcGeVector3d::kZAxis );
		startPt2 = m_spt + v * m_width * 0.5;
	}

	void caclEndPoint( AcGePoint3d& endPt1, AcGePoint3d& endPt2 )
	{
		AcGeVector3d v = m_ept - m_spt;
		v.normalize();

		v.rotateBy( PI * 0.5, AcGeVector3d::kZAxis );
		endPt1 = m_ept + v * m_width * 0.5;

		v.rotateBy( PI, AcGeVector3d::kZAxis );
		endPt2 = m_ept + v * m_width * 0.5;
	}

private:
	AcGePoint3d m_spt, m_ept;
	double m_width;
	//静态成员变量，用于统计对象个数
	static int count;
};

int DoubleLine::count = 0;

AcDbObjectId Draw::CreateDoubleLine(const AcGePoint3d& spt, const AcGePoint3d& ept, double width)
{
	DoubleLine line(spt, ept, width);
	return line.draw();
}


CoalProxy::CoalProxy()
{
	left_offset = 20;
	right_offset = 20;
	bottom_offset = 20;
	top_offset = 40;
}

void CoalProxy::drawPores()
{
	double radius = tech->dp, gap = tech->gp;
	double left = tech->left_side, right = tech->right_side;
	double top = tech->top_side, bottom = tech->bottom_side;
	if(gap <= 0) return;

	//计算钻孔平面投影范围
	AcGePoint3d basePt;
	double Wp = 0, Hp = 0;
	caclPoreExtent(basePt, Wp, Hp);

	//绘制钻孔
	AcGePoint3dArray pts;
	ArxDrawHelper::MakeGridWithHole(basePt, Wp, Hp, gap, gap, left+right, 0, left+right, left+right, pts);
	for(int i=0;i<pts.length();i++)
	{
		ArxDrawHelper::DrawCircle(pts[i], radius);
	}
}

void CoalProxy::drawRockTunnel()
{
	double angle = DegToRad(coal->dip_angle);
	//double L1 = ws->l1, L2 = ws->l2*cos(angle);
	double L1 = ws->l1, L2 = ws->l2;
	double w = tech->wd, h = tech->hd;
	double h_offset = tech->h_offset;
	double left = tech->left_side, right = tech->right_side;

	//绘制机巷
	AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
	AcGePoint3d basePt = ArxDrawHelper::CaclPt(pt, v1, right, v2, h_offset);
	AcDbObjectId t1 = Draw::CreateDoubleLine(basePt, basePt+v1*L2, w);
	//绘制工作面切眼
	AcDbObjectId t2 = Draw::CreateDoubleLine(basePt, basePt+v2*L1, w);
	//绘制风巷
	AcDbObjectId t3 = Draw::CreateDoubleLine(basePt+v2*L1, basePt+v1*L2+v2*L1, w);
	ArxDrawHelper::DrawMText(basePt+v1*L2, 0, _T("底板岩巷"), 10);
	//ArxDrawHelper::DrawMText(basePt+v2*L1, 0, _T("切眼"), 10);
	ArxDrawHelper::DrawMText(basePt+v1*L2+v2*L1, 0, _T("上区段岩巷"), 10);
}

void CoalProxy::drawWsTunnel()
{
	double angle = DegToRad(coal->dip_angle);
	//double L1 = ws->l1, L2 = ws->l2*cos(angle);
	double L1 = ws->l1, L2 = ws->l2;
	double w = ws->w, h = ws->h;
	
	//绘制机巷
	AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
	AcDbObjectId t1 = Draw::CreateDoubleLine(pt, pt+v1*L2, w);
	//绘制工作面切眼
	AcDbObjectId t2 = Draw::CreateDoubleLine(pt, pt+v2*L1, w);
	//绘制风巷
	AcDbObjectId t3 = Draw::CreateDoubleLine(pt+v2*L1, pt+v1*L2+v2*L1, w);
	ArxDrawHelper::DrawMText(pt+v1*L2, 0, _T("待掘机巷"), 10);
	//ArxDrawHelper::DrawMText(pt+v2*L1, 0, _T("切眼"), 10);
	ArxDrawHelper::DrawMText(pt+v1*L2+v2*L1, 0, _T("待掘风巷"), 10);
}

void CoalProxy::drawCoal()
{
	//计算煤层面的平面投影范围
	AcGePoint3d basePt;
	double Wc = 0, Hc = 0;
	caclCoalExtent(basePt, Wc, Hc);

	//绘图煤层面
	AcGePoint3d insertPt = ArxDrawHelper::CaclPt(basePt,AcGeVector3d::kXAxis,0.5*Wc,AcGeVector3d::kYAxis,0.5*Hc);
	AcDbObjectId objId = ArxDrawHelper::DrawRect(insertPt, 0, Wc, Hc);
	ArxDrawHelper::MakeAlignedDim(basePt, basePt+AcGeVector3d::kXAxis*Wc, 50, false);
	ArxDrawHelper::MakeAlignedDim(basePt, basePt+AcGeVector3d::kYAxis*Hc, 30, true);
	//附加数据
	if(!objId.isNull())
	{
		CoalData data;
		data.setDataSource(objId);
		data.m_name = _T("测试");
		data.m_thick = coal->thick;
		data.m_angle = coal->dip_angle;
		data.m_width = ws->l1;
		data.m_height = ws->l2;
		data.m_pt = basePt;
		data.update(true);
	}
}

//计算工作面的平面尺寸
void CoalProxy::caclCoalExtent( AcGePoint3d& insertPt, double& Wc, double& Hc )
{
	double L1 = ws->l1, L2 = ws->l2;
	double w = ws->w, h = ws->h;
	double left = tech->left_side, right = tech->right_side;
	double top = tech->top_side, bottom = tech->bottom_side;
	double thick = coal->thick, angle = DegToRad(coal->dip_angle);

	//计算宽度(倾向长度L2+工作面左帮控制范围left+偏移)
	//Wc = (L2 + w + left + left_offset + right_offset)*cos(angle);
	Wc = L2 + w + left + left_offset + right_offset;
	Hc = L1 + 2 * w + left + right + bottom_offset + top_offset;
	
	AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
	insertPt = ArxDrawHelper::CaclPt(pt,v1,-1*(w*0.5+left+left_offset),v2,-1*(w*0.5+left+bottom_offset));
}

void CoalProxy::caclPoreExtent( AcGePoint3d& insertPt, double& Wp, double& Hp )
{
	double L1 = ws->l1, L2 = ws->l2;
	double w = ws->w, h = ws->h;
	double left = tech->left_side, right = tech->right_side;
	double top = tech->top_side, bottom = tech->bottom_side;
	double thick = coal->thick, angle = DegToRad(coal->dip_angle);

	//计算宽度(倾向长度L2+工作面左帮控制范围left+偏移)
	//Wp = (L2 + w + left)*cos(angle);
	Wp = L2 + w + left;
	Hp = L1 + 2 * w + left + right;

	AcGeVector3d v1 = AcGeVector3d::kXAxis, v2 = AcGeVector3d::kYAxis;
	insertPt = ArxDrawHelper::CaclPt(pt,v1,-1*(w*0.5+left),v2,-1*(w*0.5+left));
}

void CoalProxy::draw()
{
	ArxDocLockSwitch lock_switch;
	drawCoal();
	drawWsTunnel();
	drawRockTunnel();
	drawPores();
}
