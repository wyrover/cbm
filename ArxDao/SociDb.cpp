#include "StdAfx.h"
#include "SociDb.h"

#include <mysql/soci-mysql.h>
typedef soci::row SociRow;
typedef soci::rowset<soci::row> SociRowSet;

#include <Util/HelperClass.h>

namespace orm
{
    soci::session* soci_Db::getConnection()
    {
        return &sql;
    }

    bool soci_Db::config( const CString& user, const CString& password, const CString& database, const CString& host/*=_T("localhost")*/, const CString& port/*=_T("3306")*/ )
    {
        bool ret = true;
        try
        {
            if( !host.IsEmpty() && !user.IsEmpty() )
            {
                std::string c_host = EncodeHelper::UnicodeToANSI( ( LPCTSTR )host );
                std::string c_port = EncodeHelper::UnicodeToANSI( ( LPCTSTR )port );
                std::string c_user = EncodeHelper::UnicodeToANSI( ( LPCTSTR )user );
                std::string c_password = EncodeHelper::UnicodeToANSI( ( LPCTSTR )password );
                std::string c_database = EncodeHelper::UnicodeToANSI( ( LPCTSTR )database );

                //对soci而言,host、port、user等数据的顺序并不重要，只要有这些关键词，用空格分开即可
                std::string conn_string = "host=" + c_host +
                                          " port=" + c_port +
                                          " db=" + c_database +
                                          " user=" + c_user +
                                          " password=\'" + c_password + "\'";
                LOG_DEBUG_FMT( _T( "数据连接字符串:%s" ), C2W( conn_string ) );
                sql.open( soci::mysql, conn_string );
                //解决mysql中文乱码问题
                ret = this->execute( _T( "set names 'gbk';" ) );
                //this->execute("set character_set_client=utf8;");
                //this->execute("set character_set_results=utf8;");
                //this->execute("set character_set_connection=utf8;");
            }
            else
            {
                throw std::runtime_error( "Passe a URL, Usuario e Senha na primeira vez que chamar: Dao::getInstance" );
            }
        }
        catch( soci::soci_error const& e )
        {
            ret = false;
            instance.reset();
            LOG_DEBUG_FMT( _T( "连接数据库异常:%s" ), C2W( e.what() ) );
        }
        catch ( std::exception const& e )
        {
            ret = false;
            instance.reset();
            LOG_DEBUG_FMT( _T( "Runtime异常:%s" ), C2W( e.what() ) );
        }
        return ret;
    }

    bool soci_Db::execute( const CString& sql )
    {
        bool ret = true;
        try
        {
            LOG_DEBUG_FMT( _T( "sql语句:%s" ), sql );
            soci::session* conn = getConnection();

            *conn << W2C( ( LPCTSTR )sql );
            conn->commit();
        }
        catch( soci::soci_error const& e )
        {
            ret = false;
            LOG_DEBUG_FMT( _T( "调用execute()异常:%s" ), C2W( e.what() ) );
        }
        catch ( std::exception const& e )
        {
            ret = false;
            LOG_DEBUG_FMT( _T( "Runtime异常:%s" ), C2W( e.what() ) );
        }
        return ret;
    }

    bool soci_Db::query( const CString& sql, RowSet& rs )
    {
        LOG_DEBUG_FMT( _T( "sql语句:%s" ), sql );
        bool ret = true;
        try
        {
            soci::session* conn = getConnection();
            SociRowSet linhas = ( conn->prepare << W2C( ( LPCTSTR )sql ) );
            for ( SociRowSet::const_iterator it = linhas.begin(); it != linhas.end(); ++it )
            {
                RowPtr row( new Row() );
                SociRow& soci_row = *it;
                for( int i = 0; i < soci_row.size(); i++ )
                {
                    const soci::column_properties& customProp = soci_row.get_properties( i );
                    std::string name = customProp.get_name();
                    switch( customProp.get_data_type() )
                    {
                    case soci::dt_date:
                    case soci::dt_string:
                    {
                        row->set( C2W( name ), C2W( soci_row.get<std::string>( i, "" ) ) );
                    }
                    break;
                    case soci::dt_double:
                    {
                        row->set( C2W( name ), soci_row.get<double>( i, 0.0 ) );
                    }
                    break;
                    default:
                    {
                        row->set( C2W( name ), soci_row.get<int>( i, 0 ) );
                    }
                    break;
                    }
                }
                rs.push_back( row );
            }
        }
        catch( soci::soci_error const& e )
        {
            ret = false;
            rs.clear();
            LOG_DEBUG_FMT( _T( "调用select()异常:%s" ), C2W( e.what() ) );
        }
        catch ( std::exception const& e )
        {
            ret = false;
            rs.clear();
            LOG_DEBUG_FMT( _T( "Runtime异常:%s" ), C2W( e.what() ) );
        }
        return ret;
    }

    int soci_Db::lastInsertId( const CString& table )
    {
        using namespace soci;
        int id = 0;
        try
        {
            soci::session* conn = getConnection();
            long long_id = 0;
            std::string backed_name = conn->get_backend_name();
            if( backed_name == "odbc" )
            {
                conn->get_last_insert_id( W2C( ( LPCTSTR )table ), long_id );
            }
            else if( backed_name == "mysql" )
            {
                *conn << "select last_insert_id()", into( long_id );
            }
            else if( backed_name == "sqlite3" )
            {
                *conn << "select last_insert_rowid()", into( long_id );
            }
            id = ( int )long_id; // 可能存在精度损失
        }
        catch( soci::soci_error const& e )
        {
            id = 0;
            LOG_DEBUG_FMT( _T( "调用lastInsertId()异常:%s" ), C2W( e.what() ) );
        }
        catch ( std::exception const& e )
        {
            id = 0;
            LOG_DEBUG_FMT( _T( "Runtime异常:%s" ), C2W( e.what() ) );
        }
        return id;
    }
}