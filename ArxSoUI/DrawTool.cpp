#include "StdAfx.h"
#include "DrawTool.h"
#include <ArxHelper/HelperClass.h>

class DoubleLine
{
public:
	AcDbObjectId draw(const CString& name)
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
		return ArxGroupHelper::CreateGroup(name, objIds);
	}

protected:
	void caclStartPoint( AcGePoint3d& startPt1, AcGePoint3d& startPt2 )
	{
		AcGeVector3d v = m_endPt - m_startPt;
		v.normalize();

		v.rotateBy( PI * 0.5, AcGeVector3d::kZAxis );
		startPt1 = m_startPt + v * m_width * 0.5;

		v.rotateBy( PI, AcGeVector3d::kZAxis );
		startPt2 = m_startPt + v * m_width * 0.5;
	}

	void caclEndPoint( AcGePoint3d& endPt1, AcGePoint3d& endPt2 )
	{
		AcGeVector3d v = m_endPt - m_startPt;
		v.normalize();

		v.rotateBy( PI * 0.5, AcGeVector3d::kZAxis );
		endPt1 = m_endPt + v * m_width * 0.5;

		v.rotateBy( PI, AcGeVector3d::kZAxis );
		endPt2 = m_endPt + v * m_width * 0.5;
	}

public:
	AcGePoint3d m_startPt, m_endPt;
	double m_width;
};

class Rect
{
public:
	AcDbObjectId draw(const CString& name)
	{
		if(m_width > 0 && m_height > 0) 
		{
			//绘制矩形框
			AcDbObjectId rect = ArxDrawHelper::DrawRect(m_pt, 0, m_width, m_height);

			//构造group
			AcDbObjectIdArray objIds;
			objIds.append(rect);
			return ArxGroupHelper::CreateGroup(name, objIds);
		}
		else
		{
			return AcDbObjectId::kNull;
		}
	}
public:
	AcGePoint3d m_pt;
	double m_width, m_height;
};

AcDbObjectId DrawTool::DrawTunnel1(const CString& name, const AcGePoint3d& spt, const AcGePoint3d& ept, double width)
{
	DoubleLine tunnel;
	tunnel.m_startPt = spt;
	tunnel.m_endPt = ept;
	tunnel.m_width = width;
	return tunnel.draw(name);
}

AcDbObjectId DrawTool::DrawTunnel2(const CString& name, const AcGePoint3d& pt, double width, double height)
{
	Rect tunnel;
	tunnel.m_pt = pt;
	tunnel.m_width = width;
	tunnel.m_height = height;
	return tunnel.draw(name);
}
