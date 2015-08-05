#ifndef DAO_H
#define DAO_H

#include <vector>
#include <iostream>
#include <soci.h>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
using std::vector;

#include <Util/HelperClass.h>

class DaoManager;
typedef boost::shared_ptr<DaoManager> DaoManagerPrt;
typedef soci::rowset<soci::row> ResultSet;

class DaoManager
{
public:
    static DaoManagerPrt GetInstance();
	static bool Configure(const CString& url, const CString& user, const CString& password, const CString& database);

public:
	~DaoManager();
    bool isConnected();
    soci::session* getConnection();

    void executeUpdate(const CString& sql);
    ResultSet executeQuery(const CString& sql);

    template<typename type>
    bool update(type& obj)
    {
        bool ret = true;
        try
        {
            soci::session* connection = getConnection();

            CString sql = obj.getSqlUpdate();
			LOG_DEBUG_FMT(_T("update sql: %s"), sql);

            *connection << EncodeHelper::UnicodeToANSI((LPCTSTR)sql);
        }
        catch(soci::soci_error const & e)
        {
            ret = false;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行update语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
        }
		catch (std::exception const & e)
		{
			ret = false;
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
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

            CString sql = obj.getSqlDelete();
			LOG_DEBUG_FMT(_T("delete sql: %s"), sql);

            *connection << EncodeHelper::UnicodeToANSI((LPCTSTR)sql);
        }
        catch(soci::soci_error const & e)
        {
            ret = false;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行delete语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
        }
		catch (std::exception const & e)
		{
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
			ret = false;
		}
        return ret;
    }

    template<typename type>
    shared_ptr< vector< shared_ptr<type> > > select(const CString& table, const CString& columns=_T(""), const CString& options=_T(""))
    {
        shared_ptr< vector< shared_ptr<type> > > vec(new vector< shared_ptr<type> >);
        try
        {
            soci::session* connection = getConnection();

			CString sql;
			sql.Format(_T("select %s from %s %s;"), columns.IsEmpty()?_T("*"):columns, table, options.IsEmpty()?_T(""):options);            
			LOG_DEBUG_FMT(_T("select语句: %s"), sql);

			ResultSet linhas = (connection->prepare << EncodeHelper::UnicodeToANSI((LPCTSTR)sql));
            for (ResultSet::const_iterator it = linhas.begin(); it != linhas.end(); ++it) {
                soci::row& linha = *it;
                vec->push_back( shared_ptr<type>(new type(linha) ) );
            }
        }
        catch(soci::soci_error const & e)
        {
            vec.reset();
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行select语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
        }
		catch (std::exception const & e)
		{
			vec.reset();
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
		}
        return vec;
    }

    template<typename type>
    long insert(type& obj)
    {
        long id = 0;
        try
        {                
            soci::session* connection = getConnection();

            CString sql = obj.getSqlInsert();
			LOG_DEBUG_FMT(_T("insert sql: %s"), sql);

			*connection << EncodeHelper::UnicodeToANSI((LPCTSTR)sql);
            *connection << "SELECT LAST_INSERT_ID()", soci::into(id);
        }
        catch(soci::soci_error const & e)
        {
			CString err_msg = e.what();

            id = 0;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
			LOG_DEBUG_FMT(_T("执行insert语句异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
        }
		catch (std::exception const & e)
		{
			id = 0;
			//cerr << "Some other error: " << e.what() << endl;
			LOG_DEBUG_FMT(_T("其它异常:%s"), EncodeHelper::ANSIToUnicode(e.what()).c_str());
		}
        return id;
    }

private:
	soci::session sql;
	static DaoManagerPrt instance;
	DaoManager(const CString& host, const CString& user, const CString& password, const CString& database);
};

#endif // DAO_H
