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

class Dao;
typedef boost::shared_ptr<Dao> DaoPrt;
typedef soci::rowset<soci::row> ResultSet;

class Dao
{

public:
    static DaoPrt GetInstance(const std::string& url="" /*tcp://127.0.0.1:3306*/, const std::string& user="", const std::string& password="", const string& database="");
	static void Configure(const string& url, const string& user, const string& password, const string& dataBase);

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
            *connection << sql;
        }
        catch(soci::soci_error const &)
        {
            ret = false;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
        }
		catch (std::exception const &)
		{
			ret = false;
			//cerr << "Some other error: " << e.what() << endl;
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
            *connection << sql;
        }
        catch(soci::soci_error const &)
        {
            ret = false;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
        }
		catch (std::exception const &)
		{
			//cerr << "Some other error: " << e.what() << endl;
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

            ResultSet linhas = (connection->prepare << sql);
            for (ResultSet::const_iterator it = linhas.begin(); it != linhas.end(); ++it) {
                soci::row& linha = *it;
                vec->push_back( shared_ptr<type>(new type(linha) ) );
            }
        }
        catch(soci::soci_error const &)
        {
            vec.reset();
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
        }
		catch (std::exception const &)
		{
			vec.reset();
			//cerr << "Some other error: " << e.what() << endl;
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

            *connection << sql;
            *connection << "SELECT LAST_INSERT_ID()", soci::into(id);
        }
        catch(soci::soci_error const & e)
        {
			std::string err_msg = e.what();

            id = -1;
			//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
        }
		catch (std::exception const &)
		{
			id = -1;
			//cerr << "Some other error: " << e.what() << endl;
		}
        return id;
    }

private:
	soci::session sql;
	static DaoPrt instance;
	Dao(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
};

#endif // DAO_H
