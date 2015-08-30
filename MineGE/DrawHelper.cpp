#include "StdAfx.h"
#include "DrawHelper.h"
#include "DefaultCurDrawHelper.h"

#include "LinkedGE.h"
#include "TagGE.h"
#include "ModelGE.h"

#include <ArxHelper/HelperClass.h>
#include <MineGEDraw/MineGEDrawSystem.h>

/* 全局函数(实现在EdgeJunctionClosure.cpp) */
extern void LinkedGEJunctionClosure_Helper( const AcGePoint3d& junctionPt );

static MineGE* CreateGEByType( const CString& geType )
{
    AcRxObject* pClass = acrxClassDictionary->at( geType );
    if( pClass == 0 ) return 0;

    AcRxObject* pObj = AcRxClass::cast( pClass )->create();
    MineGE* pGE = MineGE::cast( pObj );
    if( pGE == 0 )
    {
        delete pObj;
        return 0;
    }
    return pGE;
}

void DrawHelper::LinkedGEJunctionClosure( const AcGePoint3d& junctionPt )
{
    LinkedGEJunctionClosure_Helper( junctionPt );
}

static void UpdateLinkedGE( const AcDbObjectIdArray& objIds )
{
    int len = objIds.length();
    for( int i = 0; i < len; i++ )
    {
        DrawHelper::LinkedGEJunctionClosure2( objIds[i] );
    }
}

// 使用事务
static void UpdateEntity1( const AcDbObjectId& objId )
{
	AcTransaction* pTrans = actrTransactionManager->startTransaction();
	if(pTrans == 0) return;

	AcDbObject* pObj;
	if( Acad::eOk != pTrans->getObject( pObj, objId, AcDb::kForWrite ) ) // 打开图元失败
	{
		actrTransactionManager->abortTransaction();
		return;
	}
	MineGE* pEnt = MineGE::cast( pObj );
	if( pEnt == 0 )
	{
		actrTransactionManager->abortTransaction();
		return;
	}
	pEnt->recordGraphicsModified( true ); // 标签图元状态已修改，需要更新图形
	pEnt->updateDraw(); // 更新可视化参数及效果
	actrTransactionManager->endTransaction();
}

// 使用常规的Open/Close机制
static void UpdateEntity2( const AcDbObjectId& objId )
{
	AcDbObject* pObj;
	if( Acad::eOk != acdbOpenObject( pObj, objId, AcDb::kForWrite ) ) return;
	MineGE* pEnt = MineGE::cast( pObj );
	if( pEnt != 0 )
	{
		pEnt->recordGraphicsModified( true ); // 标签图元状态已修改，需要更新图形
		pEnt->updateDraw(); // 更新可视化参数及效果
	}
	pEnt->close();
}

void DrawHelper::Update(const AcDbObjectId& objId)
{
    if( objId.isNull() ) return;
    /*
     * 使用常规的Open/Close机制更新实体
     * 注：使用事务机制更新实体有时候好使, 有时候不好使
     *      原因暂时不明
     */
    UpdateEntity2( objId );
}

void DrawHelper::SwitchDraw(const AcDbObjectId& objId, const CString& drawName)
{
	AcTransaction* pTrans = actrTransactionManager->startTransaction();
	if( pTrans == 0 ) return;

	AcDbObject* pObj;
	if( Acad::eOk != pTrans->getObject( pObj, objId, AcDb::kForWrite ) )
	{
		actrTransactionManager->abortTransaction();
		return;
	}

	MineGE* pGE = MineGE::cast( pObj );
	if( pGE == 0 )
	{
		actrTransactionManager->abortTransaction();
		return;
	}

	pGE->switchDraw(drawName);

	actrTransactionManager->endTransaction();
}

/*
bool DrawHelper::GetCurrentDraw( const CString& type, CString& draw )
{
    return GetDefaultCurDraw( type, draw );
}

void DrawHelper::SwitchDraw( const CString& geType, const CString& drawName )
{
    // 设置当前可视化效果
    if( !SetDefaultCurDraw( geType, drawName ) ) return;

    // 更新所有指定类型的图元
    AcDbObjectIdArray objIds;
    ArxDataTool::GetEntsByType( geType, objIds, false );
    if( objIds.isEmpty() ) return; // dwg图形中没有任何MineGE类型图元

    // 将所有geType类型图元的绘制效果更新
    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    int len = objIds.length();
    for( int i = 0; i < len; i++ )
    {
        AcDbObject* pObj;
        if( Acad::eOk != pTrans->getObject( pObj, objIds.at( i ), AcDb::kForWrite ) ) continue;

        MineGE* pGE = MineGE::cast( pObj );
        if( pGE == 0 ) continue;

        pGE->updateDraw();             // 更细可视化效果指针
        //pGE->recordGraphicsModified(true);  // 更新图形
    }

    actrTransactionManager->endTransaction();

    AcRxClass* pClass = AcRxClass::cast( acrxClassDictionary->at( geType ) );
    if( pClass != 0 && pClass->isDerivedFrom( LinkedGE::desc() ) )
    {
        UpdateLinkedGE( objIds );
    }
}

void DrawHelper::ConfigDraw( const CString& geType, const CString& drawName )
{
    MineGEDraw* pDraw = MineGEDrawSystem::GetInstance()->getGEDraw( geType, drawName );
    if( pDraw == 0 ) return; // 该绘制效果不存在

    pDraw->configExtraParams(); // 配置附加参数

    AcDbObjectIdArray objIds;
    ArxDataTool::GetEntsByType( geType, objIds, false );
    if( objIds.isEmpty() ) return; // dwg图形中没有任何geType类型图元

    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    int len = objIds.length();
    for( int i = 0; i < len; i++ )
    {
        AcDbObject* pObj;
        if( Acad::eOk != pTrans->getObject( pObj, objIds.at( i ), AcDb::kForWrite ) ) continue;

        MineGE* pGE = MineGE::cast( pObj );
        if( pGE == 0 ) continue;

        pGE->configDraw( pDraw->isA()->name() ); // 更新extra param
        pGE->recordGraphicsModified( true );   // 更新图形
    }
    actrTransactionManager->endTransaction();

    AcRxClass* pClass = AcRxClass::cast( acrxClassDictionary->at( geType ) );
    if( pClass != 0 && pClass->isDerivedFrom( LinkedGE::desc() ) )
    {
        UpdateLinkedGE( objIds );
    }
}
*/

void DrawHelper::LinkedGEJunctionClosure2( const AcDbObjectId& objId )
{
    AcDbEntity* pEnt;
    if( Acad::eOk != acdbOpenAcDbEntity( pEnt, objId, AcDb::kForRead ) ) return;

    LinkedGE* pEdge = LinkedGE::cast( pEnt );
    if( pEdge == 0 )
    {
        pEdge->close();
        return;
    }
    pEdge->close();

    AcGePoint3d startPt, endPt;
    pEdge->getSEPoint( startPt, endPt );

    DrawHelper::LinkedGEJunctionClosure( startPt );
    DrawHelper::LinkedGEJunctionClosure( endPt );
}

void DrawHelper::GetAllRegGETypesForDraw( AcStringArray& allGETypes )
{
    ArxClassHelper::GetArxClassTypes( _T( "MineGE" ), allGETypes, false );
}

//static void printId(const CString& msg, const AcDbObjectIdArray& objIds)
//{
//	acutPrintf(_T("%s\n"), msg);
//	int len=objIds.length();
//	for(int i=0;i<len;i++)
//	{
//		acutPrintf(_T("\t--%d\n"), objIds[i]);
//	}
//	acutPrintf(_T("\n"));
//}

void DrawHelper::FindMineGEs( const CString& geType, AcDbObjectIdArray& objIds )
{
    AcRxClass* pClass = AcRxClass::cast( acrxClassDictionary->at( geType ) );
    if( pClass == 0 ) return; // 该类型图元尚未在CAD中注册

    // 查找所有geType及派生类的图元
    ArxDataTool::GetEntsByType( geType, objIds, true );
}

static void GetAllTagGEById_Helper( const AcDbObjectId& objId, const AcDbObjectIdArray& tagObjIds, AcDbObjectIdArray& objIds )
{
    if( tagObjIds.isEmpty() ) return;

    //acutPrintf(_T("\n找到%d个图元，进行比较判断..."), tagObjIds.length());
    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    int len = tagObjIds.length();
    for( int i = 0; i < len; i++ )
    {
        AcDbObject* pObj;
        if( Acad::eOk != pTrans->getObject( pObj, tagObjIds[i], AcDb::kForRead ) ) continue;

        TagGE* pTag = TagGE::cast( pObj );
        if( pTag == 0 ) continue;

        if( pTag->getRelatedGE() == objId )
        {
            objIds.append( tagObjIds[i] );
        }
    }
    actrTransactionManager->endTransaction();
}

void DrawHelper::GetAllTagGEById( const AcDbObjectId& objId, AcDbObjectIdArray& objIds )
{
    if( objId.isNull() ) return;

    //acutPrintf(_T("\n查找图元..."));
    AcDbObjectIdArray tagObjIds;
    ArxDataTool::GetEntsByType( _T( "TagGE" ), tagObjIds, true );

    // 筛选过滤出与ObjId关联的tag
    GetAllTagGEById_Helper( objId, tagObjIds, objIds );

    //acutPrintf(_T("\n剩余%d个图元..."), objIds.length());
}

static void GetTagGEById2_Helper( const CString& geType, const AcDbObjectIdArray& allObjIds, AcDbObjectIdArray& objIds )
{
    AcRxClass* pClass = AcRxClass::cast( acrxClassDictionary->at( geType ) );
    if( pClass == 0 ) return;

    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    int len = allObjIds.length();
    for( int i = 0; i < len; i++ )
    {
        AcDbObject* pObj;
        if( Acad::eOk != pTrans->getObject( pObj, allObjIds[i], AcDb::kForRead ) ) continue;

        if( pObj->isKindOf( pClass ) )
        {
            objIds.append( allObjIds[i] );
        }
    }
    actrTransactionManager->endTransaction();
}

void DrawHelper::GetTagGEById2( const AcDbObjectId& objId, const CString& geType, AcDbObjectIdArray& objIds )
{
    // 查找图元ObjId关联所有的标签
    AcDbObjectIdArray allObjIds;
    DrawHelper::GetAllTagGEById( objId, allObjIds );
    if( allObjIds.isEmpty() ) return;

    // 筛选出类型为geType的tag
    GetTagGEById2_Helper( geType, allObjIds, objIds );
}

static void GetModelGEById_Helper( const AcDbObjectId& objId, const AcDbObjectIdArray& modelObjIds, AcDbObjectIdArray& objIds )
{
    if( modelObjIds.isEmpty() ) return;

    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    int len = modelObjIds.length();
    for( int i = 0; i < len; i++ )
    {
        AcDbObject* pObj;
        if( Acad::eOk != pTrans->getObject( pObj, modelObjIds[i], AcDb::kForRead ) ) continue;

        ModelGE* pModel = ModelGE::cast( pObj );
        if( pModel == 0 ) continue;

        if( pModel->getDataObject() == objId )
        {
            objIds.append( modelObjIds[i] );
        }
    }
    actrTransactionManager->endTransaction();
}

void DrawHelper::GetModelGEById( const AcDbObjectId& objId, AcDbObjectIdArray& objIds )
{
    if( objId.isNull() ) return;

    // 查找所有模型图元ModelGE
    AcDbObjectIdArray modelObjIds;
    ArxDataTool::GetEntsByType( _T( "ModelGE" ), modelObjIds, true );

    // 筛选出图元关联的模型图元ModelGE
    GetModelGEById_Helper( objId, modelObjIds, objIds );
}

void DrawHelper::GetHosts( const AcDbObjectIdArray& objIds, AcDbObjectIdArray& hosts )
{
    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    int len = objIds.length();
    for( int i = 0; i < len; i++ )
    {
        AcDbObject* pObj;
        if( Acad::eOk != pTrans->getObject( pObj, objIds[i], AcDb::kForRead ) ) continue;

        TagGE* pTag = TagGE::cast( pObj );
        if( pTag == 0 ) continue;

        AcDbObjectId host = pTag->getRelatedGE();
        /*if( !host.isNull() ) */
        hosts.append( host );
    }
    actrTransactionManager->endTransaction();
}

bool DrawHelper::IsGETypeHasDrawJig( const CString& geType )
{
    MineGEDrawSystem* pInstance = MineGEDrawSystem::GetInstance();
    CString drawName = pInstance->getDefaultGEDrawName( geType );
    if( drawName.GetLength() == 0 ) return false; // 该图元没有注册和实现任何可视化效果

    return ( pInstance->getGEDraw_Jig( geType, drawName ) != 0 );
}

void DrawHelper::ReverseDirection( const AcDbObjectId& objId )
{
    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return;

    AcDbObject* pObj;
    if( Acad::eOk != pTrans->getObject( pObj, objId, AcDb::kForWrite ) )
    {
        actrTransactionManager->abortTransaction();
        return;
    }

    LinkedGE* pEdge = LinkedGE::cast( pObj );
    if( pEdge == 0 )
    {
        actrTransactionManager->abortTransaction();
        return;
    }

    pEdge->reverse();  // 交换始末点坐标

    double angle = pEdge->getAngle(); // 反向后的角度


    // 调整所有方向类图元方向，包括风流方向
    AcDbObjectIdArray objIds;
    DrawHelper::GetTagGEById2( objId, _T( "DirectionTagGE" ), objIds );
    int len = objIds.length();
    for( int i = 0; i < len; i++ )
    {
        if( Acad::eOk != pTrans->getObject( pObj, objIds[i], AcDb::kForWrite ) ) continue;

        DirectionTagGE* pDir = DirectionTagGE::cast( pObj );

        pDir->setDirectionAngle( angle );
    }

    actrTransactionManager->endTransaction();
}

bool DrawHelper::GetHostGE( const AcDbObjectId& objId, AcDbObjectId& host )
{
    AcTransaction* pTrans = actrTransactionManager->startTransaction();
    if( pTrans == 0 ) return false;

    AcDbObject* pObj;
    if( Acad::eOk != pTrans->getObject( pObj, objId, AcDb::kForRead ) )
    {
        actrTransactionManager->abortTransaction();
        return false;
    }
    TagGE* pTag = TagGE::cast( pObj );
    if( pTag == 0 )
    {
        actrTransactionManager->abortTransaction();
        return false;
    }

    host = pTag->getRelatedGE();
    actrTransactionManager->endTransaction();

    return true;
}

static void PrintMsg( int n )
{
    CString msg;
    msg.Format( _T( "该图元包含%d个标签图元" ), n );
    AfxMessageBox( msg );
}

void DrawHelper::ShowAllTagGE( const AcDbObjectId& objId, unsigned short colorIndex )
{
    AcDbObjectIdArray objIds;
    DrawHelper::GetAllTagGEById( objId, objIds );

    PrintMsg( objIds.length() );

    if( objIds.isEmpty() ) return;

    // 记录原来的颜色
    AcArray<Adesk::UInt16> colors;
    if( !ArxEntityHelper::GetEntitiesColor( objIds, colors ) ) return;

    // 用黄色高亮显示标签图元
    ArxEntityHelper::SetEntitiesColor( objIds, colorIndex );

    // 中断
    ArxUtilHelper::Pause();

    // 恢复原有颜色
    ArxEntityHelper::SetEntitiesColor2( objIds, colors );
}

void DrawHelper::ShowHostGE( const AcDbObjectId& objId, unsigned short colorIndex )
{
    // 获取标签图元关联的宿主
    AcDbObjectId host;
    if( !GetHostGE( objId, host ) ) return;

    AcDbObjectIdArray objIds;
    objIds.append( host );

    // 记录宿主图元的原颜色
    AcArray<Adesk::UInt16> colors;
    if( !ArxEntityHelper::GetEntitiesColor( objIds, colors ) ) return;

    // 用黄色高亮显示宿主图元
    ArxEntityHelper::SetEntitiesColor( objIds, colorIndex );

    // 中断
    ArxUtilHelper::Pause();

    // 恢复宿主的原有颜色
    ArxEntityHelper::SetEntitiesColor2( objIds, colors );
}

static void GetSEPointById( const AcDbObjectId& objId, AcGePoint3d& spt, AcGePoint3d& ept )
{
    AcTransaction* pTran = actrTransactionManager->startTransaction();
    if ( 0 == pTran ) return;

    AcDbObject* pObj;
    if ( Acad::eOk != pTran->getObject( pObj, objId, AcDb::kForRead ) ) return;

    LinkedGE* pEdge = LinkedGE::cast( pObj );
    pEdge->getSEPoint( spt, ept );

    actrTransactionManager->endTransaction();

}

void DrawHelper::HighLightShowGE( const AcDbObjectId& objId, unsigned short colorIndex )
{
    AcDbObjectIdArray objIds;
    objIds.append( objId );

    // 记录图元的原颜色
    AcArray<Adesk::UInt16> colors;
    if( !ArxEntityHelper::GetEntitiesColor( objIds, colors ) ) return;

    // 高亮显示图元
    ArxEntityHelper::SetEntitiesColor( objIds, colorIndex );

    // 中断
    ArxUtilHelper::Pause();

    // 恢复原有颜色
    ArxEntityHelper::SetEntitiesColor2( objIds, colors );
}
