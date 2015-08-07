#pragma once

#include "dlimexp.h"

#include <vector>
typedef std::vector<CString> StringArray;

class ARXDAO_DLLIMPEXP DaoHelper
{
public:
	static void ConfigureDao(const CString&  url, const CString&  user, const CString&  password, const CString&  dataBase);
	static void TestDao();

	static int VerifyMineAccount(const CString& username, const CString& pwd);
	static void GetAllMineBases(StringArray& bases);
	static void GetAllMineRegions(const CString& baseName, StringArray& regions);
};
