#include "StdAfx.h"
#include "ArxDictTool.h"
#include "ArxEntityHelper.h"
#include "DictEntryManager.h"

static AcDbDictionary* GetDictObject( const CString& dictName )
{
    AcDbDictionary* pNameObjDict;
    if( Acad::eOk != acdbHostApplicationServices()->workingDatabase()->getNamedObjectsDictionary( pNameObjDict, AcDb::kForRead ) )
    {
        return 0;
    }

    AcDbObject* pObj;
    Acad::ErrorStatus es = pNameObjDict->getAt( dictName, pObj, AcDb::kForWrite );
    pNameObjDict->close();

    AcDbDictionary* pDict = 0;
    if( es == Acad::eOk )
    {
        pDict = AcDbDictionary::cast( pObj );
    }
    return pDict;
}

static DictEntryManager* GetDictEntryManager( const CString& dictName, const CString& key, bool createNewKey = false )
{
    //acutPrintf(_T("\n注册: %s"), dictName);

    AcDbDictionary* pDict = GetDictObject( dictName );
    if( pDict == 0 ) return 0;

    AcDbXrecord* pXrec = 0;
    // key不存在或者其它原因
    Acad::ErrorStatus es = pDict->getAt( key, ( AcDbObject*& ) pXrec, AcDb::kForWrite );
    if( Acad::eOk != es && Acad::eKeyNotFound != es )
    {
        pDict->close();
        return 0;
    }

    if( Acad::eKeyNotFound == es )
    {
        if( createNewKey )
        {
            pXrec = new AcDbXrecord();
            AcDbObjectId xrecObjId;
            pDict->setAt( key, pXrec, xrecObjId );
        }
        else
        {
            pDict->close();
            return 0;
        }
    }
    pDict->close();
    return new DictEntryManager( pXrec );
}

static bool FindDictKey( const CString& dictName, const CString& key )
{
    AcDbDictionary* pDict = GetDictObject( dictName );
    if( pDict == 0 ) return false;

    bool ret = pDict->has( key );
    pDict->close();
    return ret;
}

static void RemoveDictKey( const CString& dictName, const CString& key )
{
    AcDbDictionary* pDict = GetDictObject( dictName );
    if( pDict == 0 ) return;

    AcDbObjectId objId;
    pDict->remove( key, objId );
    ArxEntityHelper::EraseObject2( objId, true ); // 删除对象
    pDict->close();
}

ArxDictTool::ArxDictTool( const CString& dictName ) : m_dictName( dictName )
{

}

bool ArxDictTool::findKey( const CString& key )
{
    return FindDictKey( m_dictName, key );
}

void ArxDictTool::removeKey( const CString& key )
{
    RemoveDictKey( m_dictName, key );
}

void ArxDictTool::getAllKeys( AcStringArray& keys )
{
    AcDbDictionary* pDict = GetDictObject( m_dictName );
    if( pDict == 0 ) return;

    AcDbDictionaryIterator* pIter = pDict->newIterator();
    for ( ; !pIter->done(); pIter->next() )
    {
        keys.append( pIter->name() );
    }
    delete pIter;
    pDict->close();
}

int ArxDictTool::addEntry( const CString& key, const CString& entry )
{
    // 1、获取图元对应的AcDbXrecord
    //    并封装成DataFieldManager对象
    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key, true );
    if( pDEM == 0 ) return INVALID_ENTRY;

    // 2、添加字段
    int index = pDEM->addEntry( entry );
    delete pDEM;

    return index;
}

int ArxDictTool::removeEntry( const CString& key, const CString& entry )
{
    // 1、获取图元对应的AcDbXrecord
    //    并封装成DataFieldManager对象
    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key );
    if( pDEM == 0 ) return INVALID_ENTRY;

    // 2、删除字段
    int index = pDEM->removeEntry( entry );
    delete pDEM;

    return index;
}

int ArxDictTool::countEntries( const CString& key )
{
    // 1、获取图元对应的AcDbXrecord
    //    并封装成DataFieldManager对象
    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key );
    if( pDEM == 0 ) return INVALID_ENTRY;

    int count = pDEM->countEntries();
    delete pDEM;

    return count;
}

int ArxDictTool::findEntry( const CString& key, const CString& entry )
{
    // 1、获取图元对应的AcDbXrecord
    //    并封装成DataFieldManager对象
    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key );
    if( pDEM == 0 ) return INVALID_ENTRY;

    // 2、查找字段索引位置
    int index = pDEM->findEntry( entry );
    delete pDEM;

    return index;
}

void ArxDictTool::getAllEntries( const CString& key, AcStringArray& entries )
{
    // 1、获取图元对应的AcDbXrecord
    //    并封装成DataFieldManager对象
    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key );
    if( pDEM == 0 ) return;

    pDEM->getAllEntries( entries );
    delete pDEM;
}

bool ArxDictTool::modifyEntry( const CString& key, int index, const CString& newEntry )
{
    if( index == INVALID_ENTRY ) return false;

    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key );
    if( pDEM == 0 ) return false;

    bool flag = pDEM->modifyEntry( index, newEntry );
    delete pDEM;

    return flag;
}

bool ArxDictTool::getEntry( const CString& key, int index, CString& entry )
{
    if( index == INVALID_ENTRY ) return false;

    DictEntryManager* pDEM = GetDictEntryManager( m_dictName, key );
    if( pDEM == 0 ) return false;

    bool flag = pDEM->getEntry( index, entry );
    delete pDEM;

    return flag;
}

ArxDictTool* ArxDictTool::GetDictTool( const CString& dictName )
{
    return new ArxDictTool( dictName );
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

ArxDictTool2* ArxDictTool2::GetDictTool( const CString& dictName )
{
    return new ArxDictTool2( dictName );
}

ArxDictTool2::ArxDictTool2( const CString& dictName ) : m_dictName( dictName )
{

}

bool ArxDictTool2::addEntry( const CString& key, AcDbObject* pObj )
{
    AcDbDictionary* pDict = GetDictObject( m_dictName );
    if( pDict == 0 ) return false;

    bool ret = false;
    if( !pDict->has( key ) )
    {
        AcDbObjectId objId;
        if( Acad::eOk == pDict->setAt( key, pObj, objId ) )
        {
            pObj->close();
            ret = true;
        }
    }
    pDict->close();

    return ret;
}

bool ArxDictTool2::removeEntry( const CString& key )
{
    AcDbDictionary* pDict = GetDictObject( m_dictName );
    if( pDict == 0 ) return false;

    AcDbObjectId objId;
    bool ret = ( Acad::eOk == pDict->remove( key, objId ) );
    pDict->close();

    if( ret )
    {
        ArxEntityHelper::EraseObject2( objId, true );
    }
    return ret;
}

bool ArxDictTool2::findEntry( const CString& key, AcDbObjectId& objId )
{
    AcDbDictionary* pDict = GetDictObject( m_dictName );
    if( pDict == 0 ) return false;

    bool ret = ( Acad::eOk == pDict->getAt( key, objId ) );
    //acutPrintf(_T("\nArxDitToll->Ret:%s"),ret?_T("Y"):_T("N"));
    pDict->close();

    return ret;
}

void ArxDictTool2::getAllKeys( AcStringArray& keys )
{
    AcDbDictionary* pDict = GetDictObject( m_dictName );
    if( pDict == 0 ) return;

    AcDbDictionaryIterator* pIter = pDict->newIterator();
    for ( ; !pIter->done(); pIter->next() )
    {
        keys.append( pIter->name() );
    }
    delete pIter;
    pDict->close();
}

void ArxDictTool2::getAllEntries( AcDbObjectIdArray& objIds )
{
    AcDbDictionary* pDict = GetDictObject( m_dictName );
    if( pDict == 0 ) return;

    AcDbDictionaryIterator* pIter = pDict->newIterator();
    for ( ; !pIter->done(); pIter->next() )
    {
        objIds.append( pIter->objectId() );
    }
    delete pIter;
    pDict->close();
}

void ArxDictHelper::GetAllKeys( const CString& dictName, AcStringArray& keys )
{
    keys.removeAll();
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( dictName );
    pDictTool->getAllKeys( keys );
    delete pDictTool;
}

bool ArxDictHelper::GetAllEntries( const CString& dictName, const CString& key, AcStringArray& entries )
{
    if( key.GetLength() == 0 ) return false;

    entries.removeAll();
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( dictName );
    bool ret = pDictTool->findKey( key );
    if( ret )
    {
        pDictTool->getAllEntries( key, entries );
    }
    delete pDictTool;
    return ret;
}

void ArxDictHelper::RemoveAllEntries( const CString& dictName, const CString& key )
{
    if( key.GetLength() == 0 ) return;
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( dictName );
    pDictTool->removeKey( key );
    delete pDictTool;
}

bool ArxDictHelper::RemoveEntry( const CString& dictName, const CString& key, const CString& entry )
{
    if( key.GetLength() == 0 ) return false;
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( dictName );
    bool ret = ( INVALID_ENTRY != pDictTool->removeEntry( key, entry ) );
    delete pDictTool;
    return ret;
}

bool ArxDictHelper::AddEntry( const CString& dictName, const CString& key, const CString& entry )
{
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( dictName );
    bool ret = ( INVALID_ENTRY != pDictTool->addEntry( key, entry ) );
    delete pDictTool;
    return ret;
}
void ArxDictHelper::RemoveKey( const CString& dictName, const CString& key )
{
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( dictName );
    pDictTool->removeKey( key );
    delete pDictTool;
}
