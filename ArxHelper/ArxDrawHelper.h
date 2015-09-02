#pragma once

#include "dlimexp.h"
#include <math.h>

#ifndef PI
	#define PI 3.1415926535897932384626433832795
#endif

//度数转弧度
#define DegToRad(x) x*0.01745329251994329576923690768489
//弧度转度数
#define RadToDeg(x) x*57.295779513082320876798154814105
//平方
#define square(x)  x*x
//余切
#define cot(x) 1.0/tan(x)

//常用图形绘制函数
class ARXHELPER_DLLIMPEXP ArxDrawHelper
{
public:
	static AcGePoint2d Point3D_To_2D(const AcGePoint3d& pt);
	static AcGePoint3d Point2D_To_3D(const AcGePoint2d& pt);
	static AcGePoint3d MidPoint(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	static CString MakeUpperText(const CString& inStr);
	static CString MakeLowerText(const CString& inStr);
	static void MakeGridWithHole(const AcGePoint3d& basePt,double w,double h,double gap_x,double gap_y,double left, double right, double top, double bottom,AcGePoint3dArray& pts);
	static void MakeGridWithHole(const AcGePoint3d& basePt, double w, double h, int nx, int ny, double left,double right, double top,double bottom,AcGePoint3dArray& pts);
	static void MakeGrid(const AcGePoint3d& basePt,double w,double h,double gap_x,double gap_y,AcGePoint3dArray& pts);
	static void MakeGrid(const AcGePoint3d& basePt, double w, double h,int nx,int ny,AcGePoint3dArray& pts);
	static void Divide(const AcGePoint3d& spt, const AcGePoint3d& ept, double gap_x, double gap_y, AcGePoint3dArray& pts);
	static AcGePoint3d CacLineClosePt(const AcGePoint3d& spt, const AcGePoint3d& ept, const AcGePoint3d& pt);
	static AcGePoint3d CaclPt(const AcGePoint3d& pt, const AcGeVector3d& v1, double width, const AcGeVector3d& v2, double height);
	static void BuildRect(const AcGePoint3d& pt, double angle,double width,double height,AcGePoint3dArray& pts);
	static int ClockWise(const AcGePoint3dArray& polygon);
	static bool OffSetPolygon( const AcGePoint3dArray& polygon, double offset, bool is_inner, AcGePoint3dArray& offset_polygon );

	static AcDbObjectId GetTextStyle(const CString& style);
	static AcDbObjectId CreateTextStyle(const CString& style, const CString& winFont, Adesk::Boolean bold, Adesk::Boolean italic, int charset, int pitchAndFamily);
	static AcDbObjectId DrawText(const AcGePoint3d& pt, const CString& text, double height, AcDb::TextHorzMode hm=AcDb::kTextLeft, AcDb::TextVertMode vm=AcDb::kTextBase);
	static AcDbObjectId DrawMText(const AcGePoint3d& pt, double angle, const CString& text, double height);

	static AcDbObjectId DrawArc(const AcGePoint3d& spt, const AcGePoint3d& pt, const AcGePoint3d& ept);
	static AcDbObjectId DrawCircle(const AcGePoint3d& pt, double radius);
	static AcDbObjectId DrawEllipse(const AcGePoint3d& pt, double width, double height);

	static AcDbObjectId DrawLine(const AcGePoint3d& spt, const AcGePoint3d& ept);
	static AcDbObjectId DrawLine(const AcGePoint3d& pt, double angle, double length);
	static AcDbObjectId DrawPolyLine( const AcGePoint3d& spt, const AcGePoint3d& ept, double width );
	static AcDbObjectId DrawPolyLine( const AcGePoint3d& pt, double angle, double length, double width );
	static AcDbObjectId DrawPolyLine(const AcGePoint3dArray& pts, bool isClosed = false);
	static AcDbObjectId DrawSpline(const AcGePoint3dArray& pts);
	
	static void DrawArrow( const AcGePoint3d& pt, double angle, double width, double length );
	static void DrawLines(const AcGePoint3dArray& pts);
	static AcDbObjectId DrawRect( const AcGePoint3d& pt, double angle, double width, double height );

	static void CreatePolygonLoop( AcDbHatch* pHatch, const AcGePoint3dArray& pts );
	static void CreateCircleLoop( AcDbHatch* pHatch, const AcGePoint3d& pt, double radius );
	static void CreatePreDefinedHatch( AcDbHatch* pHatch, const CString& patName, double scale );
	static void CreateGradientObject( AcDbHatch* pHatch, const CString& gradName, const AcCmColor& c1, const AcCmColor& c2 );
	static AcDbObjectId DrawPolygonHatch( const AcGePoint3dArray& pts, const CString& patName, double scale );
	static AcDbObjectId DrawCircleGradient( const AcGePoint3d& pt, double radius, const CString& gradName, const AcCmColor& c1, const AcCmColor& c2 );

	//两条直线夹角的角度标注
	static AcDbObjectId Make2LineAngularDim(const AcGePoint3d& pt1, const AcGePoint3d& pt2, 
		const AcGePoint3d& pt3, const AcGePoint3d& pt4, const AcGePoint3d& textPt);
	//圆或圆弧的角度标注
	static AcDbObjectId Make3PointAngularDim(const AcGePoint3d& centerPt, const AcGePoint3d& pt1, 
		const AcGePoint3d& pt2, const AcGePoint3d& textPt);
	//对齐标注
	static AcDbObjectId MakeAlignedDim(const AcGePoint3d& pt1, const AcGePoint3d& pt2, double offset = 30, bool clockwise=true);
	//直径标注
	static AcDbObjectId MakeDiametricDim(const AcGePoint3d& centerPt, double radius, const AcGePoint3d& textPt);
	//坐标/基线/连续标注
	static AcDbObjectId MakeOrdinateDim(Adesk::Boolean useXAxis, const AcGePoint3d& featurePt, const AcGePoint3d& leaderPt);
	//半径/折弯标注
	static AcDbObjectId MakeRadialDim(const AcGePoint3d& centerPt, double radius, const AcGePoint3d& textPt);
	static AcDbObjectId MakeRotatedDim(const AcGePoint3d& pt1, const AcGePoint3d& pt2, double ang, const AcGePoint3d& textPt);

	//创建文字样式
	static AcDbObjectId CreateTextstyle(const CString& textStyleName, bool modifyExistStyle=false);
	//获取文字样式id
	static AcDbObjectId GetTextStyleId(const CString& textStyleName);
	//创建标注样式
	static AcDbObjectId CreateDimStyle(const CString& dimStyleName, bool modifyExistStyle=false);
	//获取标注样式id
	static AcDbObjectId GetDimStyle(const CString& dimStyleName);
};
