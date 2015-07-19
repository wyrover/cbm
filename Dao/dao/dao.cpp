#include "dao.h"
#include <mysql/soci-mysql.h>

DaoPrt Dao::instance;

Dao::Dao(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
{
	try
	{
		sql.open(soci::mysql, "host="+host+" db="+database+" user="+user+" password=\'"+password+"\'");
	}
	catch(soci::soci_error const &)
	{
		//something
		//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
	}
	catch (std::exception const & e)
	{
		//cerr << "Some other error: " << e.what() << endl;
	}
}

DaoPrt Dao::getInstance(const std::string& url, const std::string& user, const std::string& password, const std::string& database)
{
    if( ! instance ){
        if(!url.empty() && !user.empty())
            instance.reset(new Dao(url, user, password, database));
        else
            throw std::runtime_error("Passe a URL, Usuario e Senha na primeira vez que chamar: Dao::getInstance");
    }
    return instance;
}

Dao::~Dao()
{
}


soci::session* Dao::getConnection()
{
    return &sql;
}

ResultSet Dao::executeQuery(const std::string &sql)
{
	soci::session* connection = getConnection();
	//执行一句什么也得不到的sql语句(前提mine表必须存在!!!)
    ResultSet rs = connection->prepare << "select * from mine where 0";
    try
    {
		ResultSet temp_rs = connection->prepare << sql;
        rs = temp_rs;
    }
    catch(soci::soci_error const &)
    {
		//something
		//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
    }
	catch (std::exception const & e)
	{
		//cerr << "Some other error: " << e.what() << endl;
	}
    return rs;
}

void Dao::executeUpdate(const std::string& sql)
{
    try
    {
        soci::session* connection = getConnection();

        *connection << sql;
        connection->commit();
    }
    catch(soci::soci_error const &)
    {
		//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
    }
	catch (std::exception const & e)
	{
		//cerr << "Some other error: " << e.what() << endl;
	}
}
