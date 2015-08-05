#pragma once

#include <string>
using std::string;

class DaoHelper
{
public:
	static void ConfigureDao(const CString&  url, const CString&  user, const CString&  password, const CString&  dataBase);
	static void TestDao();
};
