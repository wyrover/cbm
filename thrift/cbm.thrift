include "entity.thrift"

namespace cpp cbm
namespace php cbm
namespace py cbm

service CbmService {
	//验证用户名和密码
	i32 VerifyMineAccount(1:string username, 2:string pwd);
	//查询所有的煤炭基地
	list<string> GetAllMineBases();
}
