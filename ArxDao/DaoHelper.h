#pragma once

#include "dlimexp.h"
#include "Entity.h"
using namespace cbm;

#include <vector>
typedef std::vector<CString> StringArray;

class ARXDAO_DLLIMPEXP DaoHelper
{
public:
	static void ConfigureDao(const CString& user, const CString& password, const CString& database, const CString& host=_T("localhost"), const CString& port=_T("3306"));
	static void TestDao();

	static int VerifyMineAccount(const CString& username, const CString& pwd);
	static void GetAllMineBases(StringArray& bases);
	static void GetAllMineRegions(const CString& baseName, StringArray& regions);
};
