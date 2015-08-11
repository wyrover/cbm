#pragma once

#include "dlimexp.h"

#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <functional>

#include <boost/shared_ptr.hpp>
using namespace boost;

//定义主键的名称(所有的表都必须用这个名字,大小写也应该一样)
#define PRIMARY_KEY_ID _T("id")

//宏--禁用拷贝构造函数和赋值运算符重载
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&); \
	TypeName& operator=(const TypeName&)

namespace orm
{
	class Record;
	typedef shared_ptr<Record> RecordPtr;
	typedef std::vector<RecordPtr> RecordPtrList;
	typedef shared_ptr<RecordPtrList> RecordPtrListPtr;

	class Query;
	typedef shared_ptr<Query> QueryPtr;

	//函数指针定义
	typedef RecordPtr (*CreateFunc)();

	class Attribute;
	typedef std::map<CString, Attribute> KVMap;

	class Row;
	typedef shared_ptr<Row> RowPtr;
	typedef std::vector<RowPtr> RowSet;

	class Db;
	typedef shared_ptr<Db> DbPrt;
}
