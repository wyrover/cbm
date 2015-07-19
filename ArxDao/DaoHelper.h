#pragma once

#include <string>
using std::string;

class DaoHelper
{
public:
	static void ConfigureDao(const string& url, const string& user, const string& password, const string& dataBase);
	static void TestDao();
};
