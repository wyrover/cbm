#include "stdafx.h"
#include "ReportHelper.h"
#include "EncodeHelper.h"
#include <fstream>

static void GetDocPath( CString& defaultPath )
{
	TCHAR pPath[MAX_PATH]={0};
	SHGetSpecialFolderPath(NULL,pPath,CSIDL_PERSONAL,0);

	defaultPath.Format(_T("%s"),pPath);
}

static CString GetAppPathDir()
{
	TCHAR szModulePath[_MAX_PATH];
	GetModuleFileName( NULL, szModulePath, _MAX_PATH );

	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[_MAX_DIR];
	_tsplitpath( szModulePath, drive, dir, NULL, NULL );

	TCHAR szPath[_MAX_PATH] = {0};
	_tmakepath( szPath, drive, dir, NULL, NULL );

	return CString( szPath );
}

static CString GetHeaderName(CString& tableName)
{
	int pos = tableName.Find(_T("_"));
	CString headeName = tableName.Left(pos);
	headeName.Append(_T("_header"));
	return headeName;
}

static CString BuildPath( const CString& dir, const CString& fileName )
{
	CString path;
	path.Format( _T( "%s%s" ), dir, fileName );
	return path;
}

static void GetTableJsonTest(Json::Value& root)
{
	Json::Value::Members member = root.getMemberNames();
	typedef Json::Value::Members::iterator JsonMemberIterator;
	for (JsonMemberIterator itr = member.begin(); itr != member.end(); itr++)
	{
		std::string str_temp = *itr;
		if (root[*itr].type() == Json::arrayValue)
		{
			std::cout<< std::endl;
			int cnt = root[*itr].size();
			for (int i = 0; i < cnt; i++)
			{
				GetTableJsonTest(root[*itr][i]);
				//std::cout << root[*itr][i].size() <<std::endl;
			}
		}
		else
		{
			if(str_temp == "" || root[str_temp].isNull()) continue;
			std::cout<<str_temp<< ":\t" <<root[str_temp]<<std::endl; 
		}
	}
}

bool WordHelper::replaceValue(const CString& jsonPath)
{
	if(jsonPath.IsEmpty()) return false;
	std::string jsonFile = W2C((LPCTSTR)jsonPath);
	std::ifstream inFile(jsonFile.c_str()); 
	if(!inFile) return false; 

	Json::Reader reader; 
	Json::Value root; 
	if (!reader.parse(inFile, root, false)) 
	{ 
		return false; 
	}
	inFile.close();

	Json::Value::Members member = root.getMemberNames();
	typedef Json::Value::Members::iterator JsonMemberIterator;
	for (JsonMemberIterator itr = member.begin(); itr != member.end(); itr++)
	{
		std::string str_temp = *itr;
		if(str_temp == "" || root[str_temp].isNull()) continue;
		CString findW = C2W(str_temp);
		if(-1 != findW.Find(_T("$*")) && -1 != findW.Find(_T("*$")))
		{
			CString relW = C2W(root[str_temp].asString());
			m_word->FindWord(findW,relW);
		}
		//std::cout<<str_temp<< ":\t" <<root[str_temp]<<std::endl; 
	}
	return true;
}

static bool GetTableHeader(Json::Value& root,const CString& headerKey,CStringArray& headers)
{
	headers.RemoveAll();
	std::string jsKey = W2C((LPCTSTR)headerKey);
	if(root[jsKey.c_str()].isNull()) return false;
	//std::string headerName = root[jsKey.c_str()].asCString();
	Json::Value val_array = root[jsKey.c_str()];  
	int iSize = val_array.size();  
	for ( int nIndex = 0;nIndex < iSize;++ nIndex )  
	{  
		//std::cout<<val_array[nIndex]<<std::endl;  
		std::string header = val_array[nIndex].asString();
		headers.Add(C2W(header));
	}  
	return true;
}

static bool GetJsonValueByKey(const CString& jsonPath, const CString& jsonKey, CString& jsonValue)
{
	if(jsonPath.IsEmpty()) return false;
	std::string jsonFile = W2C((LPCTSTR)jsonPath);
	std::ifstream inFile(jsonFile.c_str()); 
	//std::ifstream inFile((LPCTSTR)path); 
	if(!inFile) return false; 

	Json::Reader reader; 
	Json::Value root; 
	if (!reader.parse(inFile, root, false)) 
	{ 
		return false; 
	}
	inFile.close();
	std::string jsKey = W2C((LPCTSTR)jsonKey);
	if(jsKey.c_str() == "" || root[jsKey.c_str()].isNull()) return false;
	std::string jsValuestr = root[jsKey.c_str()].asString();
	jsonValue = C2W(jsValuestr);
	return true;
}

static BOOL CheckDocIsUsing(const CString& fileName,CmyWord& myWord)
{
	if (myWord.isUsing(fileName))
	{
		CString msg;
		msg.Format(_T("\"%s\"\n文档已经打开，请先关闭。。。"),fileName);
		AfxMessageBox(msg,MB_OK|MB_ICONSTOP);
		return TRUE;
	}
	return FALSE;
}

static BOOL SaveReport(CString savePath,CmyWord& myWord)
{
	return myWord.SaveDocumentAs(savePath);
}

WordHelper::WordHelper()
{

}

WordHelper::~WordHelper()
{

}

bool WordHelper::Initword()
{
	if(FAILED(CoInitialize(NULL)))
		//if(CoInitialize(NULL)!=S_OK) // 错误的判断方法!!!
	{
		_tprintf(_T("错误: 初始化com库失败\n"));
		return false;
	}
	m_word = new CmyWord;
	return true;
}

void WordHelper::Uninitword()
{
	delete m_word;
	m_word = 0;
	CoUninitialize();
}

bool WordHelper::ReadAndWriteDatas(const CString& jsonPath,const CString& savePath)
{
	CString tplPath;
	GetJsonValueByKey(jsonPath,_T("tplPath"),tplPath);
	if(CheckDocIsUsing(tplPath,*m_word)) return false;
	m_word->CreateApp();
	m_word->ShowApp();
	if(!m_word->Open(/*strPath*/tplPath))
	{
		m_word->CloseApp();
		return false;
	}
	CStringArray bookMks;
	if(!m_word->GetBookMarks(bookMks)) return false;
	for(int i = 0; i < bookMks.GetSize(); i++)
	{
		CString bookMk =bookMks.GetAt(i);
		CString mkValue;
		if(!m_word->Goto(bookMk)) continue;
		if (-1 != bookMk.Find(_T("_tbl")))
		{
			//AfxMessageBox(_T("创建表格吧"));
			dealJsonArrayValue(jsonPath,bookMk);
			//std::cout << "创建表格" << std::endl;
		}
		else
		{
			if(!GetJsonValueByKey(jsonPath,bookMk,mkValue)) continue;
			m_word->WriteText(mkValue);
		}
	}

	replaceValue(jsonPath);
	//m_word->UpdateField(_T("CONT_UPDATE"));
	//m_word->ShowBookmarks(FALSE);
	m_word->MoveToFirst();
	bool ret = true;
	if(!SaveReport(savePath,*m_word)) ret = false;
	m_word->CloseDocument();
	m_word->CloseApp();
	return ret;
}

void WordHelper::OpenWordDocument(const CString& filePath ,bool isDoc)
{
	if(isDoc)
	{
		ShellExecute( NULL, _T( "open" ), filePath, NULL, NULL, SW_SHOWNORMAL );
	}
}

void WordHelper::creatTable(const CStringArray& headers, int row, int col)
{
	if(row <= 0) return;
	//写表头
	m_word->CreateTable(row+1,col);
	for (int j = 0; j < col; j++)
	{
		m_word->SetTableText(1,j+1,headers[j]);
	}
}

bool WordHelper::writeTableDatas(Json::Value& tableArray,const CStringArray& headers)
{
	//GetTableHeader(root,_T("钻孔表头"),headers);
	int row = tableArray.size();
	int col = (int)headers.GetSize();
	if(col < 1) return false;
	creatTable(headers,row,col);
	for ( int i = 0;i < row;++ i )  
	{  
		//std::cout<<val_array[nIndex]<<std::endl;  
		Json::Value value = tableArray[i];
		for(int j = 0; j < col; j++)
		{
			std::string jsKey = W2C((LPCTSTR)headers.GetAt(j));
			if(value[jsKey.c_str()].isNull()) return false;
			std::string jsValuestr = value[jsKey.c_str()].asString();
			CString jsValue = C2W(jsValuestr);
			m_word->SetTableText(i+2,j+1,jsValue);
		}
	} 

	//for ( int i = 0;i < row;++ i )  
	//{  
	//	if(i+3 <= row && i%2 ==0)
	//		m_word->MergeTable(i+2,1,i+3,1);
	//} 

	
	//m_word->MergeTable(2,2,3,2);

	return true;
}

bool WordHelper::dealJsonArrayValue(const CString& jsonPath, CString& jsonKey)
{
	if(jsonPath.IsEmpty()) return false;
	std::string jsonFile = W2C((LPCTSTR)jsonPath);
	std::ifstream inFile(jsonFile.c_str()); 
	//std::ifstream inFile((LPCTSTR)path); 
	if(!inFile) return false; 

	Json::Reader reader; 
	Json::Value root; 
	if (!reader.parse(inFile, root, false)) 
	{ 
		return false; 
	}
	inFile.close();
	std::string jsKey = W2C((LPCTSTR)jsonKey);
	if(root[jsKey.c_str()].isNull()) return false;
	//std::string jsValuestr = root[jsKey.c_str()].asCString();

	Json::Value tableArray = root[jsKey.c_str()];
	CString headeName = GetHeaderName(jsonKey);
	CStringArray headers;
	GetTableHeader(root,headeName,headers);
	writeTableDatas(tableArray,headers);
	return true;
}

static void JSTest(CString& jsonPath)
{
	std::string jsonFile = W2C((LPCTSTR)jsonPath);
	std::ifstream inFile(jsonFile.c_str()); 
	if(!inFile) return; 

	Json::Reader reader; 
	Json::Value root; 
	if (!reader.parse(inFile, root, false)) 
	{ 
		return; 
	}

	Json::Value::Members member = root.getMemberNames();
	typedef Json::Value::Members::iterator JsonMemberIterator;
	for (JsonMemberIterator itr = member.begin(); itr != member.end(); itr++)
	{
		std::string str_temp = *itr;
		std::cout<<str_temp<< ":\t" <<root[str_temp]<<std::endl; 
	}

	//std::string name;
	//name = root["name"].asCString(); 
	//int age = root["age"].asInt(); 

	//std::cout<<name<<std::endl; 
	//std::cout<<age<<std::endl; 

	//CString msg;
	//msg.Format(_T("名字:%s\n年龄:%d"), C2W(name), age);
	//AfxMessageBox(msg);
}

bool WordHelper::creat(CString& jsonPath)
{
	//JSTest(jsonPath);
	CString savePath;
	if(!SelectSavePath(savePath,jsonPath)) return false;
	//acutPrintf( _T( "\n报告生成中...\n" ) );
	if(Initword())
	{
		if(CheckDocIsUsing(savePath,*m_word)) 
		{
			Uninitword();
			return false;
		}
		if(!ReadAndWriteDatas(jsonPath,savePath)) 
		{
			Uninitword();
			return false;
		}
		//卸载com
		Uninitword();
	}
	//acutPrintf( _T( "\n报告保存到:%s" ),selectedPath);
	if(IDYES == AfxMessageBox(_T("报告生成成功!是否现在打开?"),MB_YESNO))
	{
		if(Initword())
		{
			OpenWordDocument(savePath);
			//卸载com
			Uninitword();
		}
	}
	return true;

}

bool WordHelper::SelectSavePath(CString& savePath, const CString& jsonPath)
{
	CString reportName;
	if(!GetJsonValueByKey(jsonPath,_T("reportName"),reportName))
	{
		reportName = _T("报告");
	}

	TCHAR szFileFilter[] = _T("doc文档(*.doc)|*.doc||");
	TCHAR szFileExt[] = _T("doc");
	CString defaultPath;
	GetDocPath(defaultPath);

	CFileDialog dlg(FALSE,szFileExt,defaultPath,OFN_READONLY,szFileFilter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框

	TCHAR* pFileBuf = new TCHAR[MAX_PATH * 1024];
	if (NULL == pFileBuf)
	{
		return false;
	}
	_tcscpy(pFileBuf,reportName);

	dlg.m_ofn.lpstrFile = pFileBuf;
	dlg.m_ofn.nMaxFile = MAX_PATH * 1024;
	if(IDOK == dlg.DoModal())
	{
		savePath = dlg.GetPathName();
	}

	else
	{
		return false;
	}

	delete pFileBuf;
	pFileBuf = NULL;
	return true;
}
