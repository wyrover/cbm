#pragma once

// http://blog.csdn.net/sunnyboychina/archive/2006/04/13/661763.aspx
class CIniFile
{
public:
	CIniFile();
	virtual ~CIniFile();

	//    设置ini文件路径
	//    成功返回TRUE;否则返回FALSE
	BOOL         SetPath(const CString& strPath);

	//    检查section是否存在
	//    存在返回TRUE;否则返回FALSE
	BOOL SectionExist(const CString& strSection);

	//    从指定的Section和Key读取KeyValue
	//    返回KeyValue
	CString GetKeyValue(const CString& strSection, const CString& strKey);        

	//    设置Section、Key以及KeyValue，若Section或者Key不存在则创建

	void SetKeyValue(const CString&    strSection,
		             const CString&    strKey,
					 const CString&    strKeyValue);

	//    删除指定Section下的一个Key
	void DeleteKey(const CString& strSection, const CString& strKey);

	//    删除指定的Section以及其下的所有Key
	void DeleteSection(const CString& strSection);

	//    获得所有的Section
	//    返回Section数目
	int  GetAllSections(CStringArray& strArrSection);

	//    根据指定Section得到其下的所有Key和KeyValue
	//    返回Key的数目

	int GetAllKeysAndValues(const CString& strSection,
		                    CStringArray& strArrKey,
							CStringArray& strArrKeyValue);

	// 删除所有Section
	void DeleteAllSections();

private:
	// ini文件路径
	CString m_strPath;
};