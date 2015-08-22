#pragma once

#include "dlimexp.h"

#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <functional>

#include <boost/shared_ptr.hpp>
using namespace boost;

#ifndef DISALLOW_COPY_AND_ASSIGN

//宏--禁用拷贝构造函数和赋值运算符重载
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&); \
	TypeName& operator=(const TypeName&)

#endif

//share_ptr智能指针转换
#define DYNAMIC_POINTER_CAST(DeriveClass, ptrBase) boost::dynamic_pointer_cast<DeriveClass>(ptrBase)
#define STATIC_POINTER_CAST(Class, ptr) boost::static_pointer_cast<Class>(ptr)

namespace orm
{
	#define BOOL_2_INT(condition) condition?1:0

	//id名称的一部分
	#define KEY_ID _T("id")

	//获取表table的主键id名称(table是一个字符串)
	//注:主键id的名字分为2种情况,有表前缀、无表前缀
	//    可以到Db类中设置该参数(参见Db::enableTablePrefix方法)
	#define PKEY(table) get_db()->getPrimaryKeyName(table)
	//获取外键id名称(table是一个字符串)
	//注:一般情况下外键的名字都是：表名+下划线+id，例如: mine_id
	#define _FKEY(table) get_db()->getForeignKeyName(table)
	//Klass是一个符号名称
	#define FKEY(Klass) _FKEY(Klass::Table())
	//字段名称(简化字段名的写法, name是一个符号名称)
	//注:一般情况下类的成员变量和表的字段名都是相同的)
	#define FIELD(name) _T(#name)

	//4个宏用于简化query代码写法(Klass类型名称,field和value则是字符串, id是一个整数)
	#define FIND_BY_ID(Klass, id) DYNAMIC_POINTER_CAST(Klass, Query::FindById<Klass>(id))
	#define FIND_FIRST(Klass) DYNAMIC_POINTER_CAST(Klass, Query::FindFirst<Klass>())
	#define FIND_ALL(Klass) Query::FindAll<Klass>()
	#define FIND_ONE(Klass, field, value) DYNAMIC_POINTER_CAST(Klass, QueryPtr(Query::From<Klass>())->where(field, value)->find_one<Klass>())
	#define FIND_MANY(Klass, field, value) QueryPtr(Query::From<Klass>())->where(field, value)->find_many<Klass>()

	#define FIND_ONE2(Klass, field1, value1, field2, value2) DYNAMIC_POINTER_CAST(Klass, QueryPtr(Query::From<Klass>())->where(field1, value1)->where(field2, value2)->find_one<Klass>())
	#define FIND_MANY2(Klass, field1, value1, field2, value2) QueryPtr(Query::From<Klass>())->where(field1, value1)->where(field2, value2)->find_many<Klass>()
	#define DELETE_MANY(Klass, field, value) get_db()->execute(QueryPtr(Query::From<Klass>())->where(field, value)->build_delete())

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
