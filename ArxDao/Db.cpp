#include "stdafx.h"
#include "Db.h"

#include <soci.h>
#include <mysql/soci-mysql.h>
typedef soci::row SociRow;
typedef soci::rowset<soci::row> SociRowSet;

#include <Util/HelperClass.h>

namespace orm
{
	class soci_Db : public Db
	{
	public:
		virtual bool config(const CString& host, const CString& user, const CString& password, const CString& database);
		virtual bool execute(const CString& sql);
		virtual bool query(const CString& sql, RowSet& rs);

	public:
		soci::session* getConnection();
		soci::session sql;
	};

	soci::session* soci_Db::getConnection()
	{
		return &sql;
	}

	bool soci_Db::config(const CString& host, const CString& user, const CString& password, const CString& database)
	{
		bool ret = true;
		try
		{
			if(!host.IsEmpty() && !user.IsEmpty()) {
				std::string c_host = EncodeHelper::UnicodeToANSI((LPCTSTR)host);
				std::string c_user = EncodeHelper::UnicodeToANSI((LPCTSTR)user);
				std::string c_password = EncodeHelper::UnicodeToANSI((LPCTSTR)password);
				std::string c_database = EncodeHelper::UnicodeToANSI((LPCTSTR)database);

				sql.open(soci::mysql, "host="+c_host+" db="+c_database+" user="+c_user+" password=\'"+c_password+"\'");
				//解决mysql中文乱码问题
				ret = this->execute(_T("set names 'gbk';"));
				//this->execute("set character_set_client=utf8;");
				//this->execute("set character_set_results=utf8;");
				//this->execute("set character_set_connection=utf8;");
			}
			else {
				throw std::runtime_error("Passe a URL, Usuario e Senha na primeira vez que chamar: Dao::getInstance");
			}
		}
		catch(soci::soci_error const & e)
		{
			ret = false;
			instance.reset();
			LOG_DEBUG_FMT(_T("连接数据库异常:%s"), C2W(e.what()));
		}
		catch (std::exception const & e)
		{
			ret = false;
			instance.reset();
			LOG_DEBUG_FMT(_T("Runtime异常:%s"), C2W(e.what()));
		}
		return ret;
	}

	bool soci_Db::execute(const CString& sql)
	{
		bool ret = true;
		try
		{
			LOG_DEBUG_FMT(_T("sql语句:%s"), sql);
			soci::session* conn = getConnection();

			*conn << W2C((LPCTSTR)sql);
			conn->commit();
		}
		catch(soci::soci_error const & e)
		{
			ret = false;
			LOG_DEBUG_FMT(_T("调用execute()异常:%s"), C2W(e.what()));
		}
		catch (std::exception const & e)
		{
			ret = false;
			LOG_DEBUG_FMT(_T("Runtime异常:%s"), C2W(e.what()));
		}
		return ret;
	}

	bool soci_Db::query(const CString& sql, RowSet& rs)
	{
		bool ret = true;
		try
		{
			soci::session* conn = getConnection();
			SociRowSet linhas = (conn->prepare << W2C((LPCTSTR)sql));
			for (SociRowSet::const_iterator it = linhas.begin(); it != linhas.end(); ++it) 
			{
				SociRow& linha = *it;
				for(int i=0;i<linha.size();i++)
				{
					const soci::column_properties& customProp = linha.get_properties(i);
					std::string name = customProp.get_name();
					switch(customProp.get_data_type())
					{
					case soci::dt_date:
					case soci::dt_string:
						{
							Row row;
							row.set(C2W(name), C2W(linha.get<std::string>(i, "")));
							rs.push_back(row);
						}
						break;
					case soci::dt_double:
						{
							Row row;
							row.set(C2W(name), linha.get<double>(i, 0.0));
							rs.push_back(row);
						}
						break;
					default:
						{
							Row row;
							row.set(C2W(name), linha.get<int>(i, 0));
							rs.push_back(row);
						}
						break;
					}
				}
			}
		}
		catch(soci::soci_error const & e)
		{
			ret = false;
			rs.clear();
			LOG_DEBUG_FMT(_T("调用select()异常:%s"), C2W(e.what()));
		}
		catch (std::exception const & e)
		{
			ret = false;
			rs.clear();
			LOG_DEBUG_FMT(_T("Runtime异常:%s"), C2W(e.what()));
		}
		return ret;
	}

	DbPrt Db::instance;

	DbPrt Db::Instance()
	{
		if(!instance)
		{
			instance.reset(new soci_Db());
		}
		return instance;
	}

	DbPrt get_db()
	{
		return Db::Instance();
	}
}
