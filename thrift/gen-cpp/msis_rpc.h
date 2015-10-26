#ifndef MSIS_RPC_H
#define MSIS_RPC_H

#include "../thrift/gen-cpp/msis_types.h"

class RpcHelper
{
public:
	static bool UpdateEnt(msis::Entity& ent);
};


#endif // MSIS_RPC_H