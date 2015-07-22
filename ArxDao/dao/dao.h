#ifndef DAO_H
#define DAO_H

#include <vector>
#include <iostream>
#include <soci.h>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
using std::vector;
using std::string;

#include "util.h"

#include "../../Util/HelperClass.h"

class Dao;
typedef boost::shared_ptr<Dao> DaoPrt;
typedef soci::rowset<soci::row> ResultSet;

class Dao
{
public:
    static DaoPrt GetInstance(const std::string& url="" /*tcp://127.0.0.1:3306*/, const std::string& user="", const std::string& password="", const string& database="");
	static bool Configure(const string& url, const string& user, const string& password, const string& dataBase);

public:
	~Dao();
    bool isConnected();
    soci::session* getConnection();

    void executeUpdate(const std::string& sql);
    ResultSet executeQuery(const std::string& sql);

    template<typename type>
    bool update(type& obj)
    {
        bool ret = true;
        try
        {
            soci::session* connection = getConnection();

            std::string sql = obj.getSqlUpdate();
			LOG_DEBUG_FMT(_T("update sql: %s"), EncodeHelper::ANSIToUnicode(sql));

            *connection << sql;
        }
        catch(soci::soci_error const & e)
        {
            ret = false;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行update语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
        }
		catch (std::exception const & e)
		{
			ret = false;
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
		}

        return ret;
    }

    template<typename type>
    bool remove(type& obj)
    {
        bool ret = true;
        try
        {
            soci::session* connection = getConnection();

            std::string sql = obj.getSqlDelete();
			LOG_DEBUG_FMT(_T("delete sql: %s"), EncodeHelper::ANSIToUnicode(sql));

            *connection << sql;
        }
        catch(soci::soci_error const & e)
        {
            ret = false;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行delete语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
        }
		catch (std::exception const & e)
		{
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
			ret = false;
		}
        return ret;
    }

    template<typename type>
    shared_ptr< vector< shared_ptr<type> > > select(string table, string columns="", string options="")
    {
        shared_ptr< vector< shared_ptr<type> > > vec(new vector< shared_ptr<type> >);
        try
        {
            soci::session* connection = getConnection();

            std::string sql = "SELECT ";
            sql += columns.empty()?"*":columns;
            sql += " FROM "+table+" ";
            sql += options.empty()?"":options;

			LOG_DEBUG_FMT(_T("select sql: %s"), EncodeHelper::ANSIToUnicode(sql));

            ResultSet linhas = (connection->prepare << sql);
            for (ResultSet::const_iterator it = linhas.begin(); it != linhas.end(); ++it) {
                soci::row& linha = *it;
                vec->push_back( shared_ptr<type>(new type(linha) ) );
            }
        }
        catch(soci::soci_error const & e)
        {
            vec.reset();
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行select语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
        }
		catch (std::exception const & e)
		{
			vec.reset();
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
		}
        return vec;
    }

    template<typename type>
    long insert(type& obj)
    {
        long id = -1;
        try
        {                
            soci::session* connection = getConnection();

            std::string sql = obj.getSqlInsert();
			LOG_DEBUG_FMT(_T("insert sql: %s"), EncodeHelper::ANSIToUnicode(sql));

            *connection << sql;
            *connection << "SELECT LAST_INSERT_ID()", soci::into(id);
        }
        catch(soci::soci_error const & e)
        {
			std::string err_msg = e.what();

            id = -1;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行insert语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
        }
		catch (std::exception const & e)
		{
			id = -1;
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()));
		}
        return id;
    }

private:
	soci::session sql;
	static DaoPrt instance;
	Dao(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
};

#endif // DAO_H
