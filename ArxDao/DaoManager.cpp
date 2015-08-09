#include "stdafx.h"
#include "DaoManager.h"
DaoManagerPrt DaoManager::instance;

#include <stactive_record.h>
using namespace stactiverecord;
Sar_Dbi* Sar_Dbi::dbi = 0;

#include <Util/HelperClass.h>

bool DaoManager::config(const CString& host, const CString& user, const CString& password, const CString& database)
{
	bool ret = true;
	try
	{
		// config is in form scheme://[user[:password]@]host[:port]/database
		CString config;
		config.AppendFormat(_T("mysql://%s"), user);
		if(password.GetLength() > 0)
		{
			config.AppendFormat(_T(":%s"), password);
		}
		config.AppendFormat(_T("@%s"), host);
		
		CString port;
		if(port.GetLength() > 0)
		{
			config.AppendFormat(_T(":%s"), port);
		}
		config.AppendFormat(_T("/%s"), database);
		Sar_Dbi::dbi =  Sar_Dbi::dbi = Sar_Dbi::makeStorage( (LPCTSTR)config, SAR_TEXT("cbm_") );

		//解决mysql中文乱码问题
		Sar_Dbi::dbi->execute(_T("set names 'gbk';"));
		//Sar_Dbi::dbi->execute("set character_set_client=utf8;");
		//Sar_Dbi::dbi->execute("set character_set_results=utf8;");
		//Sar_Dbi::dbi->execute("set character_set_connection=utf8;");
	}
	catch (std::exception const & e)
	{
		ret = false;
		LOG_DEBUG_FMT(_T("异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
	}
	return ret;
}

DaoManagerPrt DaoManager::Instance()
{
	if( ! instance ) 
	{
		instance = new DaoManager();
	}
	return instance;
}

DaoManager::DaoManager()
{
	//为了更好的输出中文，需要设置locale为中文
	//log4cplus也有中文问题,所以这个设置和log4cplus的设置重合了
	//在vvloader已经修改过locale了,无需重复设置
	//std::locale m_origin_locale = std::locale::global(std::locale("chs"));
}

DaoManager::~DaoManager()
{
	//恢复原来的locale设置
	//std::locale::global(m_origin_locale);

	delete Sar_Dbi::dbi;
	Sar_Dbi::dbi = 0;
}
