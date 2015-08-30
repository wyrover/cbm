#include "StdAfx.h"
#include "LinkedGE.h"

#include "DrawHelper.h"

#include <MineGEDraw/LinkedGEDraw.h>
#include <MineGEDraw/MineGEDrawSystem.h>

Adesk::UInt32 LinkedGE::kCurrentVersionNumber = 1 ;

// 有修改
ACRX_NO_CONS_DEFINE_MEMBERS ( LinkedGE, MineGE )

LinkedGE::LinkedGE()
{
}

LinkedGE::LinkedGE( const AcGePoint3d& startPt, const AcGePoint3d& endPt )
    : m_startPt( startPt ), m_endPt( endPt )
{
}

void LinkedGE::setSEPoint( const AcGePoint3d& startPt, const AcGePoint3d& endPt )
{
    assertWriteEnabled();

    m_startPt = startPt;
    m_endPt = endPt;
}

void LinkedGE::getSEPoint( AcGePoint3d& startPt, AcGePoint3d& endPt ) const
{
    assertReadEnabled();

    startPt = m_startPt;
    endPt = m_endPt;
}

void LinkedGE::reverse()
{
    assertWriteEnabled();

    LinkedGEDraw* pDraw = LinkedGEDraw::cast( getCurDrawPtr() ); // 访问父类MineGE的draw对象
    if( pDraw == 0 ) return;

    updateDrawParam( pDraw, false ); // to draw
    pDraw->reverse();
    updateDrawParam( pDraw, true ); // back to ge
}

void LinkedGE::dealWithStartPointBoundary( const AcGeRay3d& boundaryLine )
{
    assertWriteEnabled();

    LinkedGEDraw* pDraw = LinkedGEDraw::cast( getCurDrawPtr() ); // 访问父类MineGE的draw对象
    if( pDraw == 0 ) return;

    updateDrawParam( pDraw, false ); // to draw
    pDraw->dealWithStartPointBoundary( boundaryLine );
    updateDrawParam( pDraw, true ); // back to ge
}

void LinkedGE::dealWithEndPointBoundary( const AcGeRay3d& boundaryLine )
{
    assertWriteEnabled();

    LinkedGEDraw* pDraw = LinkedGEDraw::cast( getCurDrawPtr() );
    if( pDraw == 0 ) return;

    updateDrawParam( pDraw, false );
    pDraw->dealWithEndPointBoundary( boundaryLine );
    updateDrawParam( pDraw, true );
}

double LinkedGE::getAngle() const
{
    assertReadEnabled();

    AcGeVector3d v = m_endPt - m_startPt;
    return v.angleTo( AcGeVector3d::kXAxis, -AcGeVector3d::kZAxis );
}

AcGeVector3d LinkedGE::getStartPointInExtendAngle() const
{
    assertReadEnabled();

    LinkedGEDraw* pDraw = LinkedGEDraw::cast( getCurDrawPtr() );
    if( pDraw == 0 )
    {
        return AcGeVector3d::kIdentity; // 零向量
    }
    else
    {
        updateDrawParam( pDraw, false ); // to draw
        return pDraw->getStartPointInExtendAngle().normalize(); // 标准化
    }
}

AcGeVector3d LinkedGE::getEndPointInExtendAngle() const
{
    assertReadEnabled();

    LinkedGEDraw* pDraw = LinkedGEDraw::cast( getCurDrawPtr() );
    if( pDraw == 0 )
    {
        return AcGeVector3d::kIdentity; // 零向量
    }
    else
    {
        updateDrawParam( pDraw, false ); // to draw
        return pDraw->getEndPointInExtendAngle().normalize(); // 标准化
    }
}

void LinkedGE::extendByLength( double length )
{
    assertWriteEnabled();

    LinkedGEDraw* pDraw = LinkedGEDraw::cast( getCurDrawPtr() );
    if( pDraw == 0 ) return;

    updateDrawParam( pDraw, false ); // to draw
    pDraw->extendByLength( length );
    updateDrawParam( pDraw, true );
}

void LinkedGE::writeKeyParam( DrawParamWriter& writer ) const
{
    //assertReadEnabled();

    writer.writePoint( m_startPt );
    writer.writePoint( m_endPt );
}

void LinkedGE::readKeyParam( DrawParamReader& reader )
{
    //assertWriteEnabled();

    reader.readPoint( m_startPt );
    reader.readPoint( m_endPt );
}

Acad::ErrorStatus LinkedGE::dwgOutFields ( AcDbDwgFiler* pFiler ) const
{
    assertReadEnabled () ;

    //acutPrintf(_T("\nLinkedGE::dwgOutFields"));
    Acad::ErrorStatus es = MineGE::dwgOutFields ( pFiler ) ;
    if ( es != Acad::eOk )
        return ( es ) ;

    if ( ( es = pFiler->writeUInt32 ( LinkedGE::kCurrentVersionNumber ) ) != Acad::eOk )
        return ( es ) ;

    // 保存始末点坐标
    pFiler->writeItem( m_startPt );
    pFiler->writeItem( m_endPt );

    return ( pFiler->filerStatus () ) ;
}

Acad::ErrorStatus LinkedGE::dwgInFields ( AcDbDwgFiler* pFiler )
{
    assertWriteEnabled () ;

    //acutPrintf(_T("\nLinkedGE::dwgInFields"));
    Acad::ErrorStatus es = MineGE::dwgInFields ( pFiler ) ;
    if ( es != Acad::eOk )
        return ( es ) ;

    Adesk::UInt32 version = 0 ;
    if ( ( es = pFiler->readUInt32 ( &version ) ) != Acad::eOk )
        return ( es ) ;
    if ( version > LinkedGE::kCurrentVersionNumber )
        return ( Acad::eMakeMeProxy ) ;

    // 读取始末点坐标
    pFiler->readItem( &m_startPt );
    pFiler->readItem( &m_endPt );

    return ( pFiler->filerStatus () ) ;
}

void LinkedGE::onParamsChanged()
{
	if( !isNewObject() )
	{
		//处理闭合
		//由于reactor中使用事务由很多问题
		//因此该函数中当前正在编辑的图元不参与闭合处理)
		DrawHelper::LinkedGEJunctionClosure( m_startPt );
		DrawHelper::LinkedGEJunctionClosure( m_endPt );
	}
}
