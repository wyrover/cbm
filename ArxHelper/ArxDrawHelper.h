#pragma once

#include "dlimexp.h"

//常用图形绘制函数
class ARXHELPER_DLLIMPEXP ArxDrawHelper
{
public:
	static void DrawEllipse(const AcGePoint3d& pt, double width, double height);
	static void DrawText(const AcGePoint3d& pt, const CString& text, double height, AcDb::TextHorzMode hm=AcDb::kTextLeft, AcDb::TextVertMode vm=AcDb::kTextBase);
	static void DrawMText(const AcGePoint3d& pt, double angle, const CString& text, double height);
	static void DrawLines(const AcGePoint3dArray& pts);
	static void DrawPLines(const AcGePoint3dArray& pts, bool isClosed = false);
	static void DrawSplines(const AcGePoint3dArray& pts);
	static void DrawArc(const AcGePoint3d& spt, const AcGePoint3d& pt, const AcGePoint3d& ept);
	static void DrawLine(const AcGePoint3d& spt, const AcGePoint3d& ept);
	static void DrawCircle(const AcGePoint3d& pt, double radius);
};
