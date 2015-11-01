#include "StdAfx.h"
#include "RpcDaoHelper.h"

#include "gen-cpp/CbmService.h"
#include "gen-cpp/ControlService.h"

#include <Util/HelperClass.h>
#include <boost/shared_ptr.hpp>
#include <thrift/Thrift.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

typedef boost::shared_ptr<TTransport> TransportPtr;
typedef boost::shared_ptr<TProtocol> ProtocolPtr;
typedef boost::shared_ptr<cbm::CbmServiceClient> ServiceClientPtr;
typedef boost::shared_ptr<ctrl::ControlServiceClient> ControlClientPtr;

template<class Service>
class RpcClient
{
public:
	RpcClient(const std::string& host="localhost", int port=9090)
	{
			this->host = host;
			this->port = port;
	}

	void start()
	{
		TransportPtr socket(new TSocket(host, port));
		TransportPtr transport(new TBufferedTransport(socket));
		ProtocolPtr protocol(new TBinaryProtocol(transport));
		boost::shared_ptr<Service> client(new Service(protocol));

		this->transport = transport;
		this->protocol = protocol;
		this->client = client;
		this->transport->open();
	}

	boost::shared_ptr<Service> get()
	{
		return this->client;
	}

	void close()
	{
		if(this->transport != 0)
		{
			this->transport->close();
		}
	}

private:
	TransportPtr transport;
	ProtocolPtr protocol;
	boost::shared_ptr<Service> client;
	std::string host;
	int port;
};

void RpcDaoHelper::QuitServer()
{
	try 
	{
		RpcClient<ctrl::ControlServiceClient> ctrl_client("localhost", 9090);
		ctrl_client.start();
		ctrl_client.get()->shutdown();
		ctrl_client.close();
	}
	catch (TException &tx) 
	{
		std::string error_msg = tx.what();
		//printf("ERROR: %s\n", tx.what());
	}
}

int RpcDaoHelper::VerifyMineAccount( const std::string& username, const std::string& pwd )
{
	int ret = -2;
	try 
	{
		RpcClient<cbm::CbmServiceClient> service_client("localhost", 9100);
		service_client.start();
		ret = service_client.get()->VerifyMineAccount(username, pwd);
		service_client.close();
	} 
	catch (TException &tx) 
	{
		std::string error_msg = tx.what();
		//printf("ERROR: %s\n", tx.what());
	}
	return ret;
}

void RpcDaoHelper::GetAllMineBases( StringArray& mine_bases )
{
}

void RpcDaoHelper::GetAllMineRegions( const std::string& mine_baseName, StringArray& regions )
{

}

std::string RpcDaoHelper::GetBaseByRegion( const std::string& regionName )
{
	return "";
}

//MinePtr DaoHelper::GetSampleMine( const std::string& regionName )
//{
//	return 0;
//}

//CoalPtr DaoHelper::GetSampleCoal( const std::string& regionName )
//{
//}

void RpcDaoHelper::GetCoalNames( int mine_id, StringArray& coals )
{

}

void RpcDaoHelper::GetCoalIds( int mine_id, IntArray& coals )
{
}

int RpcDaoHelper::GetOnlineAccountId()
{
	return 0;
}

//MinePtr DaoHelper::GetOnlineMine()
//{
//}

//RecordPtrListPtr DaoHelper::GetWorkAreas( int mine_id )
//{
//}

//RecordPtrListPtr DaoHelper::GetWorkSurfs( int mine_id )
//{
//
//}

//RecordPtrListPtr DaoHelper::GetDrillingSurfs( int mine_id )
//{
//}

//初始化示范矿区的虚拟矿井和虚拟煤层
static void InitSampleMine( int region_id, int account_id, const std::string& name )
{

}

void RpcDaoHelper::InitSampleRegion()
{

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

//int DaoHelper::DifficultEval( CoalPtr coal )
//{
//    //根据钻孔流量衰减系数 和 煤层透气性系数进行评价
//    int k1 = DifficultEval1( coal->decay_alpha );
//    int k2 = DifficultEval2( coal->permeability_lambda );
//    return DifficultEvalHelper( k1, k2 );
//}

static std::string PermeabilityString( double permeability_k )
{
    if( permeability_k < 5 )
        return "低渗煤层";
    else if( permeability_k < 20 )
        return "中渗煤层";
    else
        return "高渗煤层";
}

static std::string EvalDifficultString( int eval )
{
    static std::string ret[] =
    {
        "容易抽采",               // 1
        "可以抽采",               // 2
        "较难抽采",               // 3
        "容易抽采~可以抽采",     // 4
        "容易抽采~较难抽采",     // 5
        "可以抽采~较难抽采"      // 6
    };
    if( eval < 1 || eval > 6 )
    {
        return "NULL";
    }
    else
    {
        return ret[eval - 1];
    }
}

//std::string DaoHelper::DifficultEvalString( cbm::CoalPtr coal )
//{
//    std::string msg;
//    msg.Format( "该煤层属于:%s\\n" ), PermeabilityString( coal->permeability_k ) );
//    msg.AppendFormat( "瓦斯抽采难易程度:%s" ), EvalDifficultString( coal->eval_difficult ) );
//    return msg;
//}

//double DaoHelper::MineGasReservesW1( int mine_id )
//{
//}

//double DaoHelper::MineGasReservesW2( int mine_id )
//{
//
//}

//double DaoHelper::WorkAreaGasFlow( WorkAreaPtr work_area, double K1 )
//{
//}

//double DaoHelper::MineGasFlow( MinePtr mine )
//{
//
//}

//double DaoHelper::WorkSurfGasFlow1( CoalPtr coal, WorkAreaPtr work_area, WorkSurfPtr work_surf )
//{
//}

//double DaoHelper::WorkSurfGasFlow2( CoalPtr coal, WorkAreaPtr work_area, WorkSurfPtr work_surf )
//{
//}

//void DaoHelper::DrillingSurfGasFlow( CoalPtr coal, DrillingSurfPtr drilling_surf, TunnelPtr tunnel )
//{
//}
