include "entity.thrift"
include "cbm.thrift"

namespace cpp cbm
namespace php cbm
namespace py cbm

service ControlService {
	void shutdown();
}