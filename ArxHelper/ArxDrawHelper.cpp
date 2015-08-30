#include "stdafx.h"
#include "ArxDrawHelper.h"
#include "ArxUtilHelper.h"

void ArxDrawHelper::DrawEllipse( const AcGePoint3d& pt, double width, double height )
{
    AcGeVector3d v( AcGeVector3d::kXAxis );
    v *= width / 2;
    double ratio = height / width;
    AcDbEllipse* pEllipse = new AcDbEllipse( pt, AcGeVector3d::kZAxis, v, ratio );
    ArxUtilHelper::PostToModelSpace( pEllipse );
}

void ArxDrawHelper::DrawText( const AcGePoint3d& pt, const CString& text, double height, 
							 AcDb::TextHorzMode hm /*= AcDb::kTextLeft*/, AcDb::TextVertMode vm /*= AcDb::kTextBase*/ )
{
    AcDbText* pText = new AcDbText();
    pText->setTextString( text );
    pText->setHeight( height );
    pText->setHorizontalMode( hm );
    pText->setVerticalMode( vm );
    /*
     * 根据AcDbText::setHorizontalMode()的说明
     * 如果设置为AcDb::kTextLeft，应使用setPosition()方法设置插入点
     * 如果设置为非AcDb::kTextLeft，应使用setAlignmentPoint()方法设置插入点
     * AcDbText::setVerticalMode()方法同上!!!
     */
    if( hm != AcDb::kTextLeft || vm == AcDb::kTextBase )
    {
        pText->setAlignmentPoint( pt );
    }
    else
    {
        pText->setPosition( pt );
    }
    // 废弃代码
    /*
    AcGeVector3d v1(AcGeVector3d::kXAxis), v2(AcGeVector3d::kXAxis);
    v1.rotateBy(PI, AcGeVector3d::kZAxis);
    v2.rotateBy(PI*1.5, AcGeVector3d::kZAxis);
    pText->setPosition(pt + (v1*width + v2*height)/2);

    pText->setAlignmentPoint(pt + (v2*height)/2);
    pText->setAlignmentPoint(pt);
    */

    ArxUtilHelper::PostToModelSpace( pText );
}

void ArxDrawHelper::DrawMText( const AcGePoint3d& pt, double angle, const CString& text, double height )
{
    AcDbMText* pMText = new AcDbMText;
    //AcDbObjectId style; // 文字样式
    //pMText->setTextStyle(style);
    pMText->setLocation( pt );
    pMText->setRotation( angle );
    //pMText->setWidth(width); // 不设置宽度，自动调整
    pMText->setTextHeight( height );
    pMText->setAttachment( AcDbMText::kMiddleCenter ); // 默认居中
    pMText->setContents( text );

    //acutPrintf(_T("\n文字宽度:%.3f"), pMText->actualWidth());

    ArxUtilHelper::PostToModelSpace( pMText );
}

void ArxDrawHelper::DrawLines( const AcGePoint3dArray& pts )
{
    // 绘制普通直线
    // 用多条直线连接成一条分支
    int len = pts.length();
    AcDbPolyline* pPline = new AcDbPolyline( len );
    for( int i = 0; i < len - 1; i++ )
    {
        AcDbLine* pLine = new AcDbLine( pts[i], pts[i + 1] );
        ArxUtilHelper::PostToModelSpace( pLine );
    }
}

void ArxDrawHelper::DrawPLines( const AcGePoint3dArray& pts, bool isClosed )
{
    // 绘制多段线
    int len = pts.length();
    if( len < 2 ) return;
    AcDbPolyline* pPline = new AcDbPolyline( len );
    for( int i = 0; i < len; i++ )
    {
        AcGePoint2d pt;
        pt.set( pts[i].x, pts[i].y );
        pPline->addVertexAt( i, pt );
    }
    pPline->setClosed( isClosed );
    ArxUtilHelper::PostToModelSpace( pPline );
}

void ArxDrawHelper::DrawSplines( const AcGePoint3dArray& pts )
{
    // 绘制样条曲线
    AcDbSpline* pSpline = new AcDbSpline( pts );
    ArxUtilHelper::PostToModelSpace( pSpline );
}

static void Swap( double& a, double& b )
{
    double temp = a;
    a = b;
    b = temp;
}

void ArxDrawHelper::DrawArc( const AcGePoint3d& spt, const AcGePoint3d& pt, const AcGePoint3d& ept )
{
    AcGeCircArc3d arc( spt, pt, ept );
    AcGePoint3d cnt = arc.center();
    double radius = arc.radius();
    AcGeVector3d sv = spt - cnt;
    AcGeVector3d ev = ept - cnt;
    double sa = sv.angleTo( AcGeVector3d::kXAxis, -AcGeVector3d::kZAxis );
    double ea = ev.angleTo( AcGeVector3d::kXAxis, -AcGeVector3d::kZAxis );

    if( arc.normal().z <= 0 )
    {
        Swap( sa, ea );
    }

    AcDbArc* pArc = new AcDbArc( cnt, radius, sa, ea );
    ArxUtilHelper::PostToModelSpace( pArc );
}

void ArxDrawHelper::DrawLine( const AcGePoint3d& spt, const AcGePoint3d& ept )
{
    AcDbLine* pLine = new AcDbLine( spt, ept );
    ArxUtilHelper::PostToModelSpace( pLine );
    pLine->close();
}

void ArxDrawHelper::DrawCircle( const AcGePoint3d& pt, double radius )
{
    AcDbCircle* pCircle = new AcDbCircle( pt, AcGeVector3d::kZAxis, radius );
    ArxUtilHelper::PostToModelSpace( pCircle );
}