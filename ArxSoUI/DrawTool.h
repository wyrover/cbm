#pragma once

class DrawTool
{
public:
	static AcDbObjectId DrawTunnel1(const CString& name, const AcGePoint3d& spt, const AcGePoint3d& ept, double width);
	static AcDbObjectId DrawTunnel2(const CString& name,const AcGePoint3d& pt, double width, double height);
};