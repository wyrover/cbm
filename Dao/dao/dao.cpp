#include "dao.h"
#include <mysql/soci-mysql.h>

DaoPrt Dao::instance;

void Dao::Configure(const string& url, const string& user, const string& password, const string& dataBase)
{
	DaoPrt dao = Dao::GetInstance(url, user, password, dataBase);
	dao->executeQuery("set names 'gbk';");
	//dao->executeQuery("set character_set_client=utf8;");
	//dao->executeQuery("set character_set_results=utf8;");
	//dao->executeQuery("set character_set_connection=utf8;");
}

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
	catch (std::exception const &)
	{
		//cerr << "Some other error: " << e.what() << endl;
	}
}

DaoPrt Dao::GetInstance(const std::string& url, const std::string& user, const std::string& password, const std::string& database)
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
	//执行一句什么也得不到的sql语句(前提cbm_dummy表必须存在!!!)
	//否则会出现运行错误!!!
    ResultSet rs = (connection->prepare << "select * from cbm_dummy where 0");
    try
    {
		ResultSet temp_rs = (connection->prepare << sql);
        rs = temp_rs;
    }
    catch(soci::soci_error const &)
    {
		//something
		//cerr << "MySQL error: " << e.err_num_<< " " << e.what() << endl;
    }
	catch (std::exception const &)
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
	catch (std::exception const &)
	{
		//cerr << "Some other error: " << e.what() << endl;
	}
}
