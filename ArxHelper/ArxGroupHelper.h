#pragma once

#include "dlimexp.h"

class ARXHELPER_DLLIMPEXP ArxGroupHelper
{
public:
	static AcDbObjectId CreateGroup(const CString& groupName, const AcDbObjectIdArray& objIds);
	static AcDbObjectId GetGroup(const CString& groupName);
	static void SetGroupName(const AcDbObjectId& groupId, const CString& groupName);
	static void GetObjectIds(const AcDbObjectId& groupId, AcDbObjectIdArray& objIds);
	static void GetObjectIds(const CString& groupName, AcDbObjectIdArray& objIds);
};
