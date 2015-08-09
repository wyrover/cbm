#pragma once

#include "dlimexp.h"

#include <vector>
typedef std::vector<CString> StringArray;

class ARXDAO_DLLIMPEXP DaoHelper
{
public:
	static void TestDao();

	static int VerifyMineAccount(const CString& username, const CString& pwd);
	static void GetAllMineBases(StringArray& bases);
	static void GetAllMineRegions(const CString& baseName, StringArray& regions);
};
