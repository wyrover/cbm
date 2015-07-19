#pragma once

#include <string>
#include <map>

struct Data
{
	std::string type;
	void* ptr;
};

typedef std::map<std::string, Data> DataMap;

class DBManager
{
public:
	static DBManager* instance();
	void regData(const std::string& clsname, const std::string& name, const std::string& type, void* ptr);

private:
	DBManager() {}
	DataMap m_datas;
	static DBManager* _instance;
};

#define _REGISTER_DATA(clsname, name, type, ptr) DBManager::instance()->regData(#clsname, #name, #type, (void*)(type*)ptr);
#define REGISTER_STRING_DATA(clsname, name) _REGISTER_DATA(clsname, name, std::string, &name)
#define REGISTER_DOUBLE_DATA(clsname, name) _REGISTER_DATA(clsname, name, double, &name)
#define REGISTER_LONG_DATA(clsname, name) _REGISTER_DATA(clsname, name, long, &name)
#define REGISTER_INT_DATA(clsname, name) _REGISTER_DATA(clsname, name, int, &name)

struct A
{
	int a;
	double d;
};

class DbRegistry
{
public:
	static void reg(A& obj)
	{
		REGISTER_INT_DATA(A, obj.a);
		REGISTER_DOUBLE_DATA(A, obj.d);
	}
};
