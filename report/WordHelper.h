#pragma once
#include <iostream>
#include <fstream>
#include "json/json.h"
#include "CmyWord.h"
#include "AcFStream.h"

class WordHelper
{
public:
	WordHelper();
	~WordHelper();
	bool creat(CString& jsonPath);
	
private:
	bool Initword();
	void Uninitword();
	bool SelectSavePath(CString& savePath, const CString& jsonPath = NULL);
	bool ReadAndWriteDatas(const CString& jsonPath,const CString& savePath);
	void OpenWordDocument( const CString& filePath ,bool isDoc = true);
	void creatTable(const CStringArray& headers, int row, int col);
	bool writeTableDatas(Json::Value& root, const CStringArray& headers);
	bool dealJsonArrayValue(const CString& jsonPath, CString& jsonKey);
	bool replaceValue(const CString& jsonPath);
private:
	CmyWord* m_word;
};