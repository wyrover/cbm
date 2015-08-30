#include "StdAfx.h"
#include "MineGE.h"

#include "config.h"
#include "DataHelperImpl.h"
#include "DefaultCurDrawHelper.h"
#include "HelperClass.h"

#include <MineGEDraw/MineGEDraw_Jig.h>
#include <MineGEDraw/MineGEDrawSystem.h>

static bool HasDataObject( const AcDbObjectId& dictId )
{
    AcDbDictionary* pDict;
    if( Acad::eOk != acdbOpenObject( pDict, dictId, AcDb::kForWrite ) ) return false;

    AcDbObjectId objId;
    bool ret = pDict->has( DATA_OBJECT_EXT_DICT_KEY );
    pDict->close();

    return ret;
}

static AcDbObjectId CreateDataObject( const AcDbObjectId& dictId,
                                      const CString& type,
                                      const AcDbObjectId& objId )
{
    AcDbDictionary* pDict;
    if( Acad::eOk != acdbOpenObject( pDict, dictId, AcDb::kForWrite ) ) return AcDbObjectId::kNull;

    // 创建数据对象
    DataObject* pDO = new DataObject();
    // 设置图元id
    pDO->setGE( objId );
    // 记录类型名称
    pDO->setType( type );
    // 初始化数据
    pDO->initData();

    AcDbObjectId dbObjId;
    if( Acad::eOk != pDict->setAt( DATA_OBJECT_EXT_DICT_KEY, pDO, dbObjId ) )
    {
        delete pDO;
    }
    else
    {
        pDO->close();
    }
    pDict->close();

    return dbObjId;
}

static AcDbObjectId GetDataObject( const AcDbObjectId& dictId )
{
    if( dictId.isNull() ) return AcDbObjectId::kNull;

    AcDbDictionary* pDict;
    if( Acad::eOk != acdbOpenObject( pDict, dictId, AcDb::kForRead ) ) return AcDbObjectId::kNull;

    AcDbObjectId objId;
    pDict->getAt( DATA_OBJECT_EXT_DICT_KEY, objId );

    pDict->close();

    return objId;
}

// 对图元关联所有的标签图元进行变换(可见图元，不包括已删除掉的图元)
static void TransformAllTagGE( const AcDbObjectId& objId, const AcGeMatrix3d& xform )
{
    AcDbObjectIdArray objIds;
    DrawHelper::GetAllTagGEById( objId, objIds );
    ArxEntityHelper::TransformEntities2( objIds, xform );
}

Adesk::UInt32 MineGE::kCurrentVersionNumber = 1 ;

// 有修改，使得MineGE成为抽象类
ACRX_NO_CONS_DEFINE_MEMBERS ( MineGE, AcDbEntity )

MineGE::MineGE() :m_bFollow( false )
{
    //acutPrintf(_T("\nMineGE::MineGE()..."));
}

MineGE::~MineGE ()
{
    //acutPrintf(_T("\nMineGE::~MineGE()..."));
}

CString MineGE::getTypeName() const
{
    // 返回类型名称
    // 使用了虚函数方法isA()
    return this->isA()->name();
}

CString MineGE::getCurDraw() const
{
	assertReadEnabled();

	CString curDraw;
	ArxDbgAppXdata xdata( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );
	xdata.getXdata( ( MineGE* )this ); // 提取扩展数据到xdata对象中(强制去掉const属性)
	if( !xdata.isEmpty() ) 
	{
		xdata.getString(0, curDraw);
	}
	else
	{
		//如果还没有扩展数据,则返回系统提供的默认可视化效果
		//GetDefaultCurDraw(getTypeName(), curDraw);
	}
	return curDraw;
}

void MineGE::initPropertyData()
{
    //assertWriteEnabled();
    if( !m_dataObjectId.isNull() ) return;

    Acad::ErrorStatus es = upgradeOpen();
    if( es == Acad::eOk || es == Acad::eWasOpenForWrite )
    {
        createExtensionDictionary();
        AcDbObjectId dictId = extensionDictionary();
        m_dataObjectId = CreateDataObject( dictId, getTypeName(), objectId() );
    }
    if( es == Acad::eOk )
    {
        downgradeOpen();
    }
}

AcDbObjectId MineGE::getDataObject() const
{
    assertReadEnabled();

    return m_dataObjectId;
}

void MineGE::initDraw()
{
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 )
    {
        Acad::ErrorStatus es = upgradeOpen();
        if( es == Acad::eOk || es == Acad::eWasOpenForWrite )
        {
			if( isNewObject() )
			{
				initAllExtraParamsToXData();
			}
        }
        if( es == Acad::eOk )
        {
            downgradeOpen();
        }
    }
}

void MineGE::updateDrawParams( MineGEDraw* pDraw )
{
    if( pDraw != 0 )
    {
		writeParamToGEDraw(pDraw);
        pDraw->updateExtraParams();
		readParamFromGEDraw(pDraw);
    }
}

void MineGE::switchDraw(const CString& drawName)
{
	assertWriteEnabled();

	MineGEDraw* pDraw = MineGEDrawSystem::GetInstance()->getGEDraw( getTypeName(), drawName );
	if(pDraw != 0)
	{
		ArxDbgAppXdata xdata( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );
		xdata.getXdata( ( MineGE* )this ); // 提取扩展数据到xdata对象中(强制去掉const属性)
		if( !xdata.isEmpty() ) 
		{
			xdata.setString(0, pDraw->isA()->name());
			if(Acad::eOk == xdata.setXdata(this))
			{
				updateDrawParams( pDraw );
			}
		}
	}
}

/*
void MineGE::configDraw( const CString& drawName )
{
    MineGEDraw* pDraw = MineGEDrawSystem::GetInstance()->getGEDraw( getTypeName(), drawName );
    updateDrawParams( pDraw );
}
*/

void MineGE::extractExistedDraw( AcStringArray& existedDraw )
{
    ArxDbgAppXdata xdata( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );
    xdata.getXdata( this );          // 提取扩展数据到xdata对象中
    if( xdata.isEmpty() ) return;    // 没有数据

    int len = 0;
    xdata.getInteger( 1, len );      // 绘制效果个数
    for( int i = 1; i <= len; i++ )
    {
        CString drawName;
        xdata.getString( 2 * i, drawName ); // 绘制效果名称
        existedDraw.append( drawName );
    }
}

// 这里的情况比较复杂
// 必须要保证xdata里的draw与全局的draw是同步的
// 可能存在如下几种情况：
// 1、xdata里的draw 等于 全局的draw
// 2、xdata里的draw 大于 全局的draw(增加了draw插件)
// 3、xdata里的draw 小于 全局的draw(删除了draw插件)
// 4、xata里的部分draw中在全局的draw中没有；全局的部分draw在xdata中没有
// 目前采用最简单的办法，不论draw存在与否，全部都合并到xdata中
// 也就是说xdata中可能存在冗余的、不再使用的draw数据
// 后期可以考虑专门编写一个清理draw的程序
void MineGE::initAllExtraParamsToXData()
{
    // 通过assertWriteEnabled限定只能在write状态下操作
    assertWriteEnabled();

    // 提取已存在的draw
    AcStringArray existedDraw;
    extractExistedDraw( existedDraw );

	//提取当前的可视化效果名称
	CString curDraw = getCurDraw();

    MineGEDrawSystem* pGEService = MineGEDrawSystem::GetInstance();
    AcStringArray drawList;
    pGEService->getAllGEDrawsByGEType( getTypeName(), drawList );

    ArxDbgAppXdata xdata( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );
    xdata.setString( 0, _T( "" ) );                           // 当前绘制效果名称
    xdata.setInteger( 1, 0 );                                 // 绘制效果个数(临时赋给0)

    bool foundNewDraw = false;                                // 是否发现新的draw
    int i = existedDraw.length() + 1;
    int len = drawList.length();
    for( int j = 0; j < len; j++ )
    {
        if( existedDraw.contains( drawList.at( j ) ) ) continue;

        foundNewDraw = true;                                   // 发现了新的draw

        MineGEDraw* pDraw = pGEService->getGEDraw( getTypeName(), drawList.at( j ).kACharPtr() );
        writeKeyParamToGEDraw( pDraw );                          // 写入主要参数到draw中
        // 有些extra param是需要计算的，
        // 且可能与key param有关
        //pDraw->setAllExtraParamsToDefault();                   // 参数置为默认值
        pDraw->updateExtraParams();                              // 计算并更新参数
        xdata.setString( 2 * i, pDraw->isA()->name() );          // 绘制效果名称

        ArxDbgXdataList dataList;
        DrawParamWriter writer( &dataList );
        pDraw->writeExtraParam( writer );
        xdata.setList( 2 * i + 1, dataList );                      // 写入附加参数
        i++;
    }
    xdata.setInteger( 1, i - 1 );                                  // 修正draw的实际个数

	//设置当前可视化效果
	if(curDraw.GetLength() == 0)
	{
		//if(!foundNewDraw)
		//{
			GetDefaultCurDraw(getTypeName(), curDraw);
		//}
		//else
		//{
			//curDraw = drawList.at(0).kACharPtr();
		//}
		xdata.setString(0, curDraw);
	}
    if( foundNewDraw ) xdata.setXdata( this );                     // 只有发现新的draw才会更新xdata
}

static MineGEDraw* GetDefaultCurDrawPtr( const CString& type )
{
    MineGEDraw* pDraw = 0;

    CString draw;
    if( GetDefaultCurDraw( type, draw ) )
    {
        MineGEDrawSystem* pDrawSystem = MineGEDrawSystem::GetInstance();
        if( pDrawSystem != 0 )
        {
            pDraw = pDrawSystem->getGEDraw( type, draw );
        }
    }
    return pDraw;
}

void MineGE::updateDraw()
{
    assertWriteEnabled();

	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw != 0 )
    {
        updateDrawParams( pDraw );
		//参数更新后LinkedGE图元微调
		onParamsChanged();
    }
}

MineGEDraw* MineGE::getCurDrawPtr() const
{
	CString drawName = getCurDraw();
	return MineGEDrawSystem::GetInstance()->getGEDraw( getTypeName(), drawName );
}

void MineGE::writeExtraParamToGEDraw( MineGEDraw* pDraw ) const
{
    assertReadEnabled();

    ArxDbgAppXdata xdata( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );
    xdata.getXdata( ( MineGE* )this ); // 提取扩展数据到xdata对象中(强制去掉const属性)
	if( xdata.isEmpty() ) return;

    int len = 0;
    xdata.getInteger( 1, len );    // 绘制效果个数
    for( int i = 1; i <= len; i++ )
    {
        CString drawName;
        xdata.getString( 2 * i, drawName ); // 绘制效果名称

        if( drawName.CompareNoCase( pDraw->isA()->name() ) == 0 )
        {
            ArxDbgXdataList dataList;
            xdata.getList( 2 * i + 1, dataList ); // 绘制效果的参数

            ArxDbgXdataListIterator paramList( dataList );
            DrawParamReader reader( &paramList );
            pDraw->readExtraParam( reader ); // 从扩展数据中读取参数
			break;
        }
    }
}

// 必须在write状态下操作
void MineGE::readExtraParamFromGEDraw( MineGEDraw* pDraw )
{
    assertWriteEnabled();

    ArxDbgAppXdata xdata( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );
    xdata.getXdata( this ); // 提取扩展数据到xdata对象中
	if( xdata.isEmpty() ) return;

    // 进行替换的扩展数据
    // 思路：将原有的扩展数据复制一份，对于修改的draw的数据先进行修改，然后再保存到新的扩展数据中
    ArxDbgAppXdata xdata2( DRAW_PARAMS_XDATA_GROUP, acdbHostApplicationServices()->workingDatabase() );

	CString curDraw;
	xdata.getString(0, curDraw);
    xdata2.setString( 0, curDraw ); // 复制当前绘制效果名称

    int len = 0;
    xdata.getInteger( 1, len );     // 复制绘制效果个数
    xdata2.setInteger( 1, len );

    for( int i = 1; i <= len; i++ )
    {
        CString drawName;
        xdata.getString( 2 * i, drawName ); // 绘制效果名称
        xdata2.setString( 2 * i, drawName );

        if( drawName.CompareNoCase( pDraw->isA()->name() ) == 0 )
        {
            ArxDbgXdataList dataList;
            DrawParamWriter writer( &dataList );
            pDraw->writeExtraParam( writer );

            xdata2.setList( 2 * i + 1, dataList ); // 修改并保存绘制效果的参数
        }
        else
        {
            ArxDbgXdataList dataList;
            xdata.getList( 2 * i + 1, dataList );
            xdata2.setList( 2 * i + 1, dataList );
        }
    }
    xdata2.setXdata( this );
}

void MineGE::readKeyParamFromGEDraw( MineGEDraw* pDraw )
{
    assertWriteEnabled();

    // 从MineGEDraw中读取更新之后的关键参数
    ArxDbgXdataList dataList;
    DrawParamWriter writer( &dataList );
    pDraw->writeKeyParam( writer );

    ArxDbgXdataListIterator dataListIter( dataList );
    DrawParamReader reader( &dataListIter );
    readKeyParam( reader );
}

void MineGE::writeKeyParamToGEDraw( MineGEDraw* pDraw ) const
{
    assertReadEnabled();

    // 将关键参数更新到MineGEDraw中
    ArxDbgXdataList dataList;
    DrawParamWriter writer( &dataList );
    writeKeyParam( writer );

    ArxDbgXdataListIterator dataListIter( dataList );
    DrawParamReader reader( &dataListIter );
    pDraw->readKeyParam( reader );
}

static bool GetPropertyDataFromDataObject( const AcDbObjectId& objId, const AcStringArray& names, AcStringArray& values )
{
    DataObject* pDO;
    if( Acad::eOk != acdbOpenObject( pDO, objId, AcDb::kForRead ) ) return false;

    DataHelperImpl dh( pDO );
    int len = names.length();
    for( int i = 0; i < len; i++ )
    {
        CString value;
        bool ret = dh.getPropertyData( names[i].kACharPtr(), value );
        values.append( value );
    }
    pDO->close();

    return true;
}

void MineGE::writePropertyDataToGEDraw( MineGEDraw* pDraw ) const
{
    assertReadEnabled();

    // 读取要查询的字段名称集合
    AcStringArray names;
    pDraw->regPropertyDataNames( names );
    if( names.isEmpty() ) return;

    // 查询数据，并写入到values中
    AcStringArray values;
    if( !GetPropertyDataFromDataObject( getDataObject(), names, values ) )
    {
        int len = names.length();
        for( int i = 0; i < len; i++ )
        {
            // 如果获取数据失败，添加与names等长的空字符串
            values.append( _T( "" ) );
        }
    }
    //int len = names.length();
    //for( int i = 0; i < len; i++ )
    //{
    //	acutPrintf(_T("\n字段名:%s\t值:%s\n"),names[i].kACharPtr(),values[i].kACharPtr());
    //}

    // 将查询到的数据返回到pDraw
    pDraw->readPropertyDataFromGE( values );
}

void MineGE::writeParamToGEDraw( MineGEDraw* pDraw ) const
{
    assertReadEnabled();

    // 1、将关键参数更新到MineGEDraw中
    writeKeyParamToGEDraw( pDraw );

    // 2、从扩展数据中提取参数
    writeExtraParamToGEDraw( pDraw );

    // 3、读取属性数据，并传递给MineGEDraw
    writePropertyDataToGEDraw( pDraw );
}

void MineGE::readParamFromGEDraw( MineGEDraw* pDraw )
{
    assertWriteEnabled();

    // 1、从MineGEDraw中读取更新后的关键参数
    readKeyParamFromGEDraw( pDraw );

    // 2、将draw的参数保存到扩展数据中
    readExtraParamFromGEDraw( pDraw );
}

void MineGE::updateDrawParam( MineGEDraw* pDraw, bool readOrWrite ) const
{
    if( readOrWrite )
    {
        ( ( MineGE* )this )->readParamFromGEDraw( pDraw ); // 强制去掉const修饰
    }
    else
    {
        writeParamToGEDraw( pDraw );
    }
}

Acad::ErrorStatus MineGE::dwgOutFields( AcDbDwgFiler* pFiler ) const
{
    //acutPrintf(_T("\nid:%d call MineGE::dwgOutFields()..."), objectId());

    assertReadEnabled () ;
    Acad::ErrorStatus es = AcDbEntity::dwgOutFields ( pFiler ) ;
    if ( es != Acad::eOk )
        return ( es ) ;

    if ( ( es = pFiler->writeUInt32 ( MineGE::kCurrentVersionNumber ) ) != Acad::eOk )
        return ( es ) ;

    pFiler->writeSoftPointerId( m_dataObjectId );
    pFiler->writeBool( m_bFollow );

    return ( pFiler->filerStatus () ) ;
}

Acad::ErrorStatus MineGE::dwgInFields( AcDbDwgFiler* pFiler )
{
    //acutPrintf(_T("\nid:%d call MineGE::dwgInFields()..."), objectId());

    assertWriteEnabled () ;
    Acad::ErrorStatus es = AcDbEntity::dwgInFields ( pFiler );
    if ( es != Acad::eOk )
        return ( es ) ;

    Adesk::UInt32 version = 0 ;
    if ( ( es = pFiler->readUInt32 ( &version ) ) != Acad::eOk )
        return ( es ) ;
    if ( version > MineGE::kCurrentVersionNumber )
        return ( Acad::eMakeMeProxy ) ;

    /* 199之前(包括199)的版本使用 */
    //AcString str;
    //pFiler->readString(str);
    //pFiler->readString(str);

    /* 199之后(不包括199)的版本使用 */
    AcDbSoftPointerId id;
    pFiler->readSoftPointerId( &id );
    m_dataObjectId = id;

    pFiler->readBool( &m_bFollow );

    initDraw();

    return ( pFiler->filerStatus () ) ;
}

// DWORD <==> Adesk::UInt32 <==> unsigned long
// Adesk::UInt8 <==> unsigned char
static void LONG2RGB( Adesk::UInt32 rgbColor, Adesk::UInt8& r, Adesk::UInt8& g, Adesk::UInt8& b )
{
    // 下面2段代码是等价的

    /*r = ( rgbColor & 0xffL );
    g = ( rgbColor & 0xff00L ) >> 8;
    b = rgbColor >> 16;*/

    r = GetRValue( rgbColor );
    g = GetGValue( rgbColor );
    b = GetBValue( rgbColor );
}

// 获取cad绘图窗口背景色
static bool GetBackgroundColor( Adesk::UInt8& r, Adesk::UInt8& g, Adesk::UInt8& b )
{
    // 获取cad当前所有的颜色设置
    // 右键"选项"->"显示"->"颜色"
    AcColorSettings cs;
    if( !acedGetCurrentColors( &cs ) ) return false;

    // 读取背景颜色
    DWORD rgbColor = cs.dwGfxModelBkColor;
    LONG2RGB( rgbColor, r, g, b );
    return true;
}

// 废弃代码
/*
Adesk::UInt32 rgbColor = AcCmEntityColor::lookUpRGB(cl.colorIndex()); // 转换成rgb颜色

AcCmEntityColor bgColor(255-r, 255-g, 255-b); // RGB颜色

AcCmEntityColor bgColor;
bgColor.setRGB(0, 0, 0);
if(layerColor.colorIndex() == 7) bgColor.setRGB(r, g, b); // RGB颜色
else bgColor.setRGB(255-r, 255-g, 255-b);
 */

/*
 * 在绘制闭合图形时，AcGiFillType默认为kAcGiFillAlways (始终填充)
 * 闭合图形包括：圆、多边形、网格等
 * 参见：AcGiSubEntityTraits::fillType()方法说明
 * 例如，绘制一个圆，当前颜色是黑底白色，那么采用自定义实体绘制的圆有2种情况:
 *	    1) arx程序加载的情况下-- 白边+黑底填充(正常效果，和cad的圆是一样的)
 *		2) arx程序卸载，cad采用代理实体模式显示图元 -- 白边+白底填充
 * 具体参见：绘制填充圆的一些说明.doc
 */

// 慎用AcCmColor::colorIndex()方法，因为color index总共只有256种，且白/黑都使用7表示，无法区分
// 如果要使用rgb颜色，应使用AcCmEntityColor或AcCmColor对象
void MineGE::drawBackground( MineGEDraw* pDraw, AcGiWorldDraw* mode )
{
    if( isNewObject() ) return;

    AcGePoint3dArray pts;
    pDraw->caclBackGroundMinPolygon( pts );

    // 用户没有定义边界
    if( pts.isEmpty() ) return;

    // 获取cad绘图窗口背景色
    Adesk::UInt8 r, g, b;
    if( !GetBackgroundColor( r, g, b ) ) return;

    AcGiSubEntityTraits& traits = mode->subEntityTraits();
    // 保存原有的属性
    Adesk::UInt16 cl = traits.color();;
    AcGiFillType ft = traits.fillType();

    AcCmEntityColor bgColor( r, g, b );
    traits.setTrueColor( bgColor );
    traits.setFillType( kAcGiFillAlways ); // 填充
    //acutPrintf(_T("\n颜色索引：%d"), bgColor.colorIndex());
    mode->geometry().polygon( pts.length(), pts.asArrayPtr() );

    // 恢复属性
    traits.setFillType( ft );
    traits.setColor( cl );
}

Adesk::Boolean MineGE::subWorldDraw( AcGiWorldDraw* mode )
{
    assertReadEnabled () ;

	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 ) return Adesk::kTrue;

    //acutPrintf(_T("\ncall id:%d MineGE::subWorldDraw()..."), objectId());
    // acutPrintf(_T("\ncall drawname:%s..."), pDraw->isA()->name());

    // 1、更新参数到MineGEDraw中
    updateDrawParam( pDraw, false );
    // 2、绘制背景块
    // 该方法在动态效果中可能会有一些问题,特别是jig
    // 猜测原因:绘制填充的多边形可能比较慢
    drawBackground( pDraw, mode );

    // 3、draw对象负责绘制实际图形
    pDraw->worldDraw( mode );

    return Adesk::kTrue;
}

Acad::ErrorStatus MineGE::subTransformBy( const AcGeMatrix3d& xform )
{
	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 ) return Acad::eOk;

    //acutPrintf(_T("\ncall id:%d MineGE::subTransformBy()..."), objectId());

    // 1、更新参数到MineGEDraw中
    updateDrawParam( pDraw, false );

    // 2、执行变换
    pDraw->transformBy( xform );

    // 3、从MineGEDraw中读取更新后的参数
    updateDrawParam( pDraw, true );

	//参数变化后的附加操作
	onParamsChanged();

    // 4、将附带所有的TagGE
    //transformAllTagGE( xform );

    return Acad::eOk;
}

Acad::ErrorStatus MineGE::subGetOsnapPoints (
    AcDb::OsnapMode osnapMode,
    Adesk::GsMarker gsSelectionMark,
    const AcGePoint3d& pickPoint,
    const AcGePoint3d& lastPoint,
    const AcGeMatrix3d& viewXform,
    AcGePoint3dArray& snapPoints,
    AcDbIntArray& geomIds ) const
{
    assertReadEnabled () ;

	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 ) return Acad::eOk;

    // 1、更新参数到MineGEDraw中
    updateDrawParam( pDraw, false );

    // 2、draw对象负责绘制实际图形
    pDraw->getOsnapPoints( osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds );

    return Acad::eOk;
}

Acad::ErrorStatus MineGE::subGetGripPoints(
    AcGePoint3dArray& gripPoints,
    AcDbIntArray& osnapModes,
    AcDbIntArray& geomIds ) const
{
    assertReadEnabled () ;

	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 ) return Acad::eOk;

    // 1、更新参数到MineGEDraw中
    updateDrawParam( pDraw, false );

    // 2、draw对象负责绘制实际图形
    pDraw->getGripPoints( gripPoints, osnapModes, geomIds );

    return Acad::eOk;
}

Acad::ErrorStatus MineGE::subMoveGripPointsAt ( const AcDbIntArray& indices, const AcGeVector3d& offset )
{
    assertWriteEnabled () ;

	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 ) return Acad::eOk;

    //acutPrintf(_T("\ncall id:%d MineGE::subMoveGripPointsAt()..."), objectId());

    // 1、更新参数到MineGEDraw中
    updateDrawParam( pDraw, false );

    // 2、执行变换
    pDraw->moveGripPointsAt( indices, offset );

    // 3、从MineGEDraw中读取更新后的参数
    updateDrawParam( pDraw, true );

	//参数变化后的附加操作
	onParamsChanged();

    // 所有的标签图元也进行变换
    // 变换结果偏差较大，不建议在程序中使用
    //transformAllTagGE( AcGeMatrix3d::translation( offset ) );

    return Acad::eOk;
}

Acad::ErrorStatus MineGE::subGetGeomExtents( AcDbExtents& extents ) const
{
    assertReadEnabled () ;

	//获取当前的可视化对象指针
	MineGEDraw* pDraw = getCurDrawPtr();
    if( pDraw == 0 ) return AcDbEntity::subGetGeomExtents( extents );

    // 1、更新参数到MineGEDraw中
    updateDrawParam( pDraw, false );

    Acad::ErrorStatus es = pDraw->getGeomExtents( extents );
    // Draw没有重载实现subGetGeomExtents
    if( Acad::eOk != es )
    {
        //acutPrintf(_T("\n使用背景消隐多边形计算缩放区域...\n"));
        // 使用caclBackGroundMinPolygon()方法计算的多边形代替
        AcGePoint3dArray pts;
        pDraw->caclBackGroundMinPolygon( pts );
        if( pts.isEmpty() )
        {
            es = Acad::eInvalidExtents;
        }
        else
        {
            int len = pts.length();
            for( int i = 0; i < len; i++ )
            {
                extents.addPoint( pts[i] );
            }
            es = Acad::eOk;
        }
    }

    return es;
}

// cad会频繁的调用subClose
Acad::ErrorStatus MineGE::subClose( void )
{
    //acutPrintf(_T("\nid:%d call MineGE::subClose()...\n"), objectId());
	if(!isReallyClosing()) return Acad::eOk;

    Acad::ErrorStatus es = AcDbEntity::subClose () ;

    // new对象并成功提交到数据库之后
    // 初始化可视化效果参数(扩展数据)
    // 构造数据对象(扩展词典)
    if( es == Acad::eOk )
    {
		initDraw();
		initPropertyData();
    }
    return es;
}

Acad::ErrorStatus MineGE::subErase(Adesk::Boolean erasing)
{
	Acad::ErrorStatus retCode = AcDbEntity::subErase ( erasing ) ;

	if( Acad::eOk == retCode )
	{
		onParamsChanged();
	}
	return Acad::eOk;
}

void MineGE::transformAllTagGE( const AcGeMatrix3d& xform )
{
    if( m_bFollow )
    {
        TransformAllTagGE( this->objectId(), xform );
    }
}

void MineGE::enableFollow( bool bFollow )
{
    assertWriteEnabled () ;
    m_bFollow = bFollow;
}