#include "StdAfx.h"
#include "DaoHelper.h"

#include "Db.h"
using namespace orm;

#include "Entity.h"
using namespace cbm;

#include <ArxHelper/HelperClass.h>
#include <Util/HelperClass.h>

bool DaoHelper::ConfigureFromFile(const CString& cfgFile)
{
	std::string strfile = W2C((LPCTSTR)cfgFile);

	////从配置文件中读取数据
	//ConfigParser setting(strfile);
	//std::string host="localhost",username="root",password="", database="cbm";
	//int port = 3306;
	////主机或url
	//host = setting.Read("host", host);
	////端口
	//port = setting.Read("port", port);
	////用户名
	//username = setting.Read("username", username);
	////密码
	//password = setting.Read("password", password);
	
	return false;
}

bool DaoHelper::ConfigureDao( const CString& user, const CString& password, const CString& database, const CString& host/*=_T("localhost")*/, const CString& port/*=_T("3306")*/ )
{
    return Db::Instance()->config( user, password, database, host, port );
}

void DaoHelper::TestDao()
{
    MinePtr mine( new Mine );
    //mine->username = _T("dlj");
    //mine->password = _T("123");
    mine->name = _T( "晋煤集团" );
    mine->region = Query::FindById<Region>( 1 );
    mine->set( FIELD( name ), _T( "xxx煤集团公司" ) );
    mine->region->set( FIELD( name ), _T( "华北地区" ) );
    mine->region->setID( _T( "2" ), true );
    mine->save();

    RegionPtr region = DYNAMIC_POINTER_CAST( Region, mine->region );
    acutPrintf( _T( "矿区名称:%s" ), region->name );

    MinePtr mine2( new Mine );
    mine->clone( mine2 );
    acutPrintf( _T( "\n矿井名称:%s" ), mine2->name );
}

int DaoHelper::VerifyMineAccount( const CString& username, const CString& pwd )
{
    QueryPtr query( Query::From<Account>() );
    RecordPtr account = query->where( FIELD( username ), username )
                        ->find_one<Account>();
    if( account == 0 )
        return 0; // 用户名不存在
    else if( account->get( FIELD( password ) ) != pwd )
        return 1; // 密码错误
    else
        return 2; // 用户名已注册
}

void DaoHelper::GetAllMineBases( StringArray& bases )
{
    QueryPtr query( Query::From<Base>() );
    RecordPtrListPtr lists = query->find_many<Base>();
    if( lists == 0 ) return;

    for( int i = 0; i < lists->size(); i++ )
    {
        bases.push_back( lists->at( i )->get( FIELD( name ) ) );
    }
}

void DaoHelper::GetAllMineRegions( const CString& baseName, StringArray& regions )
{
    QueryPtr query( Query::From<Base>() );
    RecordPtr base = query->where( FIELD( name ), baseName )
                     ->find_one<Base>();
    if( base == 0 ) return;

    query.reset( Query::From<Region>() );
    RecordPtrListPtr lists = query->where( FKEY( Base ), base->getStringID() )
                             ->find_many<Region>();
    if( lists == 0 ) return;

    for( int i = 0; i < lists->size(); i++ )
    {
        regions.push_back( lists->at( i )->get( FIELD( name ) ) );
    }
}

CString DaoHelper::GetBaeByRegion( const CString& regionName )
{
    RegionPtr region = FIND_ONE( Region, FIELD( name ), regionName );
    if( region == 0 ) return _T( "" );

    return region->base->get( FIELD( name ) );
}

MinePtr DaoHelper::GetSampleMine( const CString& regionName )
{
    RecordPtr region = FIND_ONE( Region, FIELD( name ), regionName );
    if( region == 0 ) return MinePtr();

    //根据id查询对应的矿井
    return FIND_ONE( Mine, FKEY( Region ), region->getStringID() );
}

CoalPtr DaoHelper::GetSampleCoal( const CString& regionName )
{
    MinePtr mine = DaoHelper::GetSampleMine( regionName );
    if( mine == 0 ) return CoalPtr();

    return FIND_ONE( Coal, FKEY( Mine ), mine->getStringID() );
}

void DaoHelper::GetCoalNames( int mine_id, StringArray& coals )
{
    RecordPtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    RecordPtrListPtr lists = FIND_MANY( Coal, FKEY( Mine ), mine->getStringID() );
    if( lists == 0 ) return;

    for( int i = 0; i < lists->size(); i++ )
    {
        coals.push_back( lists->at( i )->get( FIELD( name ) ) );
    }
}

void DaoHelper::GetCoalIds( int mine_id, IntArray& coals )
{
    RecordPtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    RecordPtrListPtr lists = FIND_MANY( Coal, FKEY( Mine ), mine->getStringID() );
    if( lists == 0 ) return;

    for( int i = 0; i < lists->size(); i++ )
    {
        coals.push_back( lists->at( i )->getID() );
    }
}

int DaoHelper::GetOnlineAccountId()
{
    SysInfoPtr sys_info = FIND_FIRST( SysInfo );
    if( sys_info == 0 ) return 0;

    return sys_info->account->getID();
}

MinePtr DaoHelper::GetOnlineMine()
{
    int account_id = DaoHelper::GetOnlineAccountId();
    if( account_id == 0 ) return MinePtr();

    return FIND_ONE( Mine, FKEY( Account ), Utils::int_to_cstring( account_id ) );
}

RecordPtrListPtr DaoHelper::GetWorkAreas( int mine_id )
{
    //查找矿井所有的煤层
    IntArray ids;
    DaoHelper::GetCoalIds( mine_id, ids );

    RecordPtrListPtr lists( new RecordPtrList );
    for( int i = 0; i < ids.size(); i++ )
    {
        //查找煤层上布置所有的采区
        RecordPtrListPtr wa_lists = FIND_MANY( WorkArea, FKEY( Coal ), Utils::int_to_cstring( ids[i] ) );
        if( wa_lists == 0 ) continue;;

        for( int j = 0; j < wa_lists->size(); j++ )
        {
            lists->push_back( wa_lists->at( j ) );
        }
    }
    if( lists->empty() ) lists.reset();
    return lists;
}

RecordPtrListPtr DaoHelper::GetWorkSurfs( int mine_id )
{
    //查询所有的采区
    RecordPtrListPtr work_areas = DaoHelper::GetWorkAreas( mine_id );
    if( work_areas == 0 ) return RecordPtrListPtr();

    RecordPtrListPtr lists( new RecordPtrList );
    for( int i = 0; i < work_areas->size(); i++ )
    {
        //查询每个采区上的回采工作面
        RecordPtrListPtr ws_lists = FIND_MANY( WorkSurf, FKEY( WorkArea ), work_areas->at( i )->getStringID() );
        if( ws_lists == 0 ) continue;;

        for( int j = 0; j < ws_lists->size(); j++ )
        {
            lists->push_back( ws_lists->at( j ) );
        }
    }
    if( lists->empty() ) lists.reset();
    return lists;
}

RecordPtrListPtr DaoHelper::GetDrillingSurfs( int mine_id )
{
    //查询所有的采区
    RecordPtrListPtr work_areas = DaoHelper::GetWorkAreas( mine_id );
    if( work_areas == 0 ) return RecordPtrListPtr();

    RecordPtrListPtr lists( new RecordPtrList );
    for( int i = 0; i < work_areas->size(); i++ )
    {
        //查询每个采区上的掘进工作面
        RecordPtrListPtr tws_lists = FIND_MANY( DrillingSurf, FKEY( WorkArea ), work_areas->at( i )->getStringID() );
        if( tws_lists == 0 ) continue;;

        for( int j = 0; j < tws_lists->size(); j++ )
        {
            lists->push_back( tws_lists->at( j ) );
        }
    }
    if( lists->empty() ) lists.reset();
    return lists;
}

//初始化示范矿区的虚拟矿井和虚拟煤层
static void InitSampleMine( int region_id, int account_id, const CString& name )
{
    MinePtr mine = FIND_ONE2( Mine, FKEY( Region ), Utils::int_to_cstring( region_id ), FKEY( Account ), Utils::int_to_cstring( account_id ) );
    if( mine == 0 )
    {
        CString mineName;
        mineName.Format( _T( "示范矿区矿井-%s" ), name );
        //创建矿井
        mine.reset( new Mine );
        mine->name = mineName;
        mine->region = FIND_BY_ID( Region, region_id );
        mine->account = FIND_BY_ID( Account, account_id );
        mine->save();

        CString coalName;
        coalName.Format( _T( "示范矿区煤层-%s" ), name );
        //创建煤层
        CoalPtr coal( new Coal );
        coal->mine = mine;
        coal->name = coalName;
        coal->save();
    }
}

void DaoHelper::InitSampleRegion()
{
    //查找管理员帐户
    AccountPtr admin = FIND_ONE( Account, FIELD( username ), _T( "admin" ) );
    if( admin == 0 )
    {
        admin.reset( new Account );
        admin->username = _T( "admin" );
        admin->password = _T( "123" );
        admin->comment = _T( "超级管理员账户" );
        if( !admin->save() ) return;
    }

    //查找三个示范矿区
    RegionPtr jincheng = FIND_ONE( Region, FIELD( name ), _T( "晋城" ) );
    if( jincheng == 0 ) return;
    RegionPtr lianghuai = FIND_ONE( Region, FIELD( name ), _T( "两淮" ) );
    if( lianghuai == 0 ) return;
    RegionPtr songzao = FIND_ONE( Region, FIELD( name ), _T( "松藻" ) );
    if( songzao == 0 ) return;

    //根据id依次初始化示范矿区的数据
    InitSampleMine( jincheng->getID(), admin->getID(), _T( "晋城" ) );
    InitSampleMine( lianghuai->getID(), admin->getID(), _T( "两淮" ) );
    InitSampleMine( songzao->getID(), admin->getID(), _T( "松藻" ) );
}
