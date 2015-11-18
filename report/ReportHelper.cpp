#include "stdafx.h"
#include "ReportHelper.h"

bool ReportHelper::CreatReport(CString& jsonPath)
{
	WordHelper wdHelper;
	return wdHelper.creat(jsonPath);
}
