#include "stdafx.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/THttpClient.h>
#include <thrift/transport/TTransportUtils.h>

#include "../thrift/gen-cpp/MsisService.h"
#include "msis_rpc.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

bool RpcHelper::UpdateEnt(msis::Entity& ent)
{
	TSocket t("localhost", 80);
	//boost::shared_ptr<TTransport> socket(new THttpClient("localhost", 80, "/tt/msis_server.php"));
	//boost::shared_ptr<TTransport> socket(new TSocket("localhost", 80));
	//boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	//boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	bool ret = false;
	//try 
	//{
	//	transport->open();

	//	msis::MsisServiceClient client(protocol);
	//	client.ping();
	//	//ret = client.update(ent);

	//	transport->close();
	//} 
	//catch (TException &tx) 
	//{
	//	//printf("ERROR: %s\n", tx.what());
	//}
	return ret;
}
