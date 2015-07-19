#include "DbHelper.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

DBManager* DBManager::_instance = 0;

static std::string FormatDataKey(const std::string& clsname, const std::string& name)
{
	std::stringstream ss;
	ss<<clsname<<"$"<<name;
	return ss.str();
}

void DBManager::regData(const std::string& clsname, const std::string& name, const std::string& type, void* ptr)
{
	std::string key = FormatDataKey(clsname, name);
	if(m_datas.find(type) == m_datas.end())
	{
		Data d = {type, ptr};
		m_datas[type] = d;
	}
}

DBManager* DBManager::instance()
{
	if(_instance == 0)
	{
		_instance = new DBManager();
	}
	return _instance;
}