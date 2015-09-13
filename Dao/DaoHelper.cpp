#include "StdAfx.h"
#include "DaoHelper.h"
#include "IniFile.h"
#include "Db.h"
#include "Entity.h"
using namespace orm;
using namespace cbm;

#include <Util/HelperClass.h>

bool DaoHelper::ConfigureFromFile(const CString& cfgFile)
{
	CIniFile iniFile;
	if(FALSE == iniFile.SetPath( cfgFile )) return false;

	CString section = _T("mysql");
	CString host = iniFile.GetKeyValue(section, _T("host"));
	CString port = iniFile.GetKeyValue(section, _T("port"));
	CString username = iniFile.GetKeyValue(section, _T("username"));
	CString password = iniFile.GetKeyValue(section, _T("password"));
	CString database = iniFile.GetKeyValue(section, _T("database"));

	return DaoHelper::ConfigureDao(username, password, database, host, port);
}

bool DaoHelper::ConfigureDao( const CString& username, const CString& password, const CString& database, const CString& host/*=_T("localhost")*/, const CString& port/*=_T("3306")*/ )
{
    return Db::Instance()->config( username, password, database, host, port );
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
    //cout<<"矿区名称:"<<region->name;

    MinePtr mine2( new Mine );
    mine->clone( mine2 );
    //cout<<"矿井名称:%s" <<mine2->name;
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

static int DifficultEval1( double decay_alpha )
{
	if( decay_alpha < 0.003 )
		return 1;
	else if( decay_alpha < 0.05 )
		return 2;
	else
		return 3;
}

static int DifficultEval2( double permeability_lambda )
{
	if( permeability_lambda > 10 )
		return 1;
	else if( permeability_lambda > 0.1 )
		return 2;
	else
		return 3;
}

static int DifficultEvalHelper( int k1, int k2 )
{
	static int ret[] = { 1, 4, 5, 4, 2, 6, 5, 6, 3 };
	if( k1 < 1 || k1 > 3 || k2 < 1 || k2 > 3 ) return 0;
	return ret[k1 * 3 + k2 - 4];
}

int DaoHelper::DifficultEval(CoalPtr coal)
{
	//根据钻孔流量衰减系数 和 煤层透气性系数进行评价
	int k1 = DifficultEval1( coal->decay_alpha );
	int k2 = DifficultEval2( coal->permeability_lambda );
	return DifficultEvalHelper( k1, k2 );
}

static CString PermeabilityString( double permeability_k )
{
	if( permeability_k < 5 )
		return _T( "低渗煤层" );
	else if( permeability_k < 20 )
		return _T( "中渗煤层" );
	else
		return _T( "高渗煤层" );
}

static CString EvalDifficultString( int eval )
{
	static CString ret[] =
	{
		_T( "容易抽采" ),               // 1
		_T( "可以抽采" ),               // 2
		_T( "较难抽采" ),               // 3
		_T( "容易抽采~可以抽采" ),     // 4
		_T( "容易抽采~较难抽采" ),     // 5
		_T( "可以抽采~较难抽采" )      // 6
	};
	if( eval < 1 || eval > 6 )
	{
		return _T( "NULL" );
	}
	else
	{
		return ret[eval - 1];
	}
}

CString DaoHelper::DifficultEvalString(cbm::CoalPtr coal)
{
	CString msg;
	msg.Format( _T( "该煤层属于:%s\\n" ), PermeabilityString( coal->permeability_k ) );
	msg.AppendFormat( _T( "瓦斯抽采难易程度:%s" ), EvalDifficultString(coal->eval_difficult ));
	return msg;
}

double DaoHelper::MineGasReservesW1(int mine_id)
{
	//查找所有的可采煤层
	RecordPtrListPtr lists = FIND_MANY2( Coal, FKEY( Mine ), Utils::int_to_cstring( mine_id ), FIELD( minable ), _T( "1" ) );
	if( lists == 0 ) return 0;

	//计算可采煤层的瓦斯储量
	double S = 0;
	for( int i = 0; i < lists->size(); i++ )
	{
		CoalPtr coal = DYNAMIC_POINTER_CAST( Coal, lists->at( i ) );
		S += coal->res_a1 * coal->gas_x1;
	}
	return S;
}

double DaoHelper::MineGasReservesW2(int mine_id)
{
	//查找所有的可采煤层
	RecordPtrListPtr lists = FIND_MANY2( Coal, FKEY( Mine ), Utils::int_to_cstring( mine_id ), FIELD( minable ), _T( "0" ) );
	if( lists == 0 ) return 0;

	//计算可采煤层的瓦斯储量
	double S = 0;
	for( int i = 0; i < lists->size(); i++ )
	{
		CoalPtr coal = DYNAMIC_POINTER_CAST( Coal, lists->at( i ) );
		S += coal->res_a1 * coal->gas_x1;
	}
	return S;
}

double DaoHelper::WorkAreaGasFlow(WorkAreaPtr work_area, double K1)
{
	//查找所有的回采工作面
	double S1 = 0;
	RecordPtrListPtr ws_lists = FIND_MANY( WorkSurf, FKEY( WorkArea ), work_area->getStringID() );
	if( ws_lists != 0 )
	{
		for( int i = 0; i < ws_lists->size(); i++ )
		{
			WorkSurfPtr ws = DYNAMIC_POINTER_CAST( WorkSurf, ws_lists->at( i ) );
			if( ws == 0 ) continue;

			double qr = ws->qr;
			double A = ws->a;
			S1 += A * qr;
		}
	}
	//查找所有的掘进面
	double S2 = 0;
	RecordPtrListPtr tws_lists = FIND_MANY( DrillingSurf, FKEY( WorkArea ), work_area->getStringID() );
	if( tws_lists != 0 )
	{
		for( int i = 0; i < tws_lists->size(); i++ )
		{
			DrillingSurfPtr tws = DYNAMIC_POINTER_CAST( DrillingSurf, tws_lists->at( i ) );
			if( tws == 0 ) continue;

			double qr = tws->qa;
			S2 += qr;
		}
	}
	//采区平均日产量
	double A0 = work_area->a;
	if( A0 <= 0 )
	{
		return -1;
	}
	else
	{
		return K1 * ( S1 + S2 ) / A0;
	}
}

double DaoHelper::MineGasFlow(MinePtr mine)
{
	//查找该矿所有的采区
	RecordPtrListPtr lists = DaoHelper::GetWorkAreas( mine->getID() );
	if( lists == 0 ) return 0;

	double S1 = 0, S2 = 0;
	for( int i = 0; i < lists->size(); i++ )
	{
		WorkAreaPtr work_area = DYNAMIC_POINTER_CAST( WorkArea, lists->at( i ) );
		double qr = work_area->qr;
		double A0 = work_area->a;
		S1 += qr * A0;
		S2 += A0;
	}
	if( S2 <= 0 )
	{
		return -1;
	}
	else
	{
		double K2 = mine->gas_k2;;
		//计算并更新矿井的瓦斯涌出量
		return K2 * S1 / S2;
	}
}
