#include "StdAfx.h"
#include "ArxGroupHelper.h"

AcDbObjectId ArxGroupHelper::CreateGroup(const CString& groupName, const AcDbObjectIdArray& objIds)
{
	// Put the group in the group dictionary which resides
	// in the named object dictionary.
	//
	AcDbDictionary *pGroupDict;
	Acad::ErrorStatus es = 
		acdbHostApplicationServices()->workingDatabase()->getGroupDictionary(pGroupDict, AcDb::kForWrite);
	
	if(es != Acad::eOk) return AcDbObjectId::kNull;

	AcDbGroup *pGroup = new AcDbGroup(groupName);
	AcDbObjectId pGroupId;
	es = pGroupDict->setAt(groupName, pGroup, pGroupId);
	pGroupDict->close();

	if(es != Acad::eOk) return AcDbObjectId::kNull;

	// Now that the group has been added, it has an ObjectID.
	// This is important since the group will become a persistent
	// reactor for the added entities...
	for (int i = 0; i < objIds.length(); i++) {
		if(objIds[i].isNull()) continue;
		pGroup->append(objIds[i]);
	}

	//默认情况AcDbGroup是全部选择的
	pGroup->setSelectable(true);
	pGroup->close();

	return pGroupId;
}

void ArxGroupHelper::GetObjectIds(const AcDbObjectId& groupId, AcDbObjectIdArray& objIds)
{
	AcTransaction* pTrans = actrTransactionManager->startTransaction();
	if( pTrans == 0 ) return;

	//AcDb::OpenMode om = ( save ? ( AcDb::kForWrite ) : ( AcDb::kForRead ) );
	AcDbObject* pObj;
	if( Acad::eOk != pTrans->getObject( pObj, groupId, AcDb::kForRead ) )
	{
		actrTransactionManager->abortTransaction();
		return;
	}
	AcDbGroup* pGroup = AcDbGroup::cast(pObj);
	if(pGroup == 0)
	{
		actrTransactionManager->abortTransaction();
		return;
	}

	AcDbGroupIterator *pIter = pGroup->newIterator();
	for (; !pIter->done(); pIter->next()) {
		objIds.append(pIter->objectId());
	}
	delete pIter;

	actrTransactionManager->endTransaction();
}

void ArxGroupHelper::GetObjectIds(const CString& groupName, AcDbObjectIdArray& objIds)
{
	AcDbObjectId groupId = ArxGroupHelper::GetGroup(groupName);
	if(groupId.isNull()) return;

	ArxGroupHelper::GetObjectIds(groupId, objIds);
}

AcDbObjectId ArxGroupHelper::GetGroup(const CString& groupName)
{
	AcDbDictionary *pGroupDict;
	Acad::ErrorStatus es = 
		acdbHostApplicationServices()->workingDatabase()->getGroupDictionary(pGroupDict, AcDb::kForRead);

	if(es != Acad::eOk) return AcDbObjectId::kNull;

	AcDbObjectId groupId;
	es = pGroupDict->getAt(groupName, groupId);
	pGroupDict->close();

	return groupId;
}

void ArxGroupHelper::SetGroupName(const AcDbObjectId& groupId, const CString& groupName)
{
	AcTransaction* pTrans = actrTransactionManager->startTransaction();
	if( pTrans == 0 ) return;

	//AcDb::OpenMode om = ( save ? ( AcDb::kForWrite ) : ( AcDb::kForRead ) );
	AcDbObject* pObj;
	if( Acad::eOk != pTrans->getObject( pObj, groupId, AcDb::kForRead ) )
	{
		actrTransactionManager->abortTransaction();
		return;
	}
	AcDbGroup* pGroup = AcDbGroup::cast(pObj);
	if(pGroup == 0)
	{
		actrTransactionManager->abortTransaction();
		return;
	}

	pGroup->setName(groupName);

	actrTransactionManager->endTransaction();
}
