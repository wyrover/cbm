/*
Copyright (C) 2007 Butterfat, LLC (http://butterfat.net)

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Created by bmuller <bmuller@butterfat.net>
*/
#include "mysql_storage.h"

namespace stactiverecord
{

    MySQLStorage::MySQLStorage( tstring location, tstring prefix ) : Sar_Dbi( prefix )
    {
        debug( SAR_TEXT("Attempting to open Mysql DB at ") + location );
        is_closed = false;
        db = mysql_init( NULL );
        SarMap<tstring> config = parseconfig( location );
		tstring host = config.has_key( SAR_TEXT("host") ) ? config[SAR_TEXT("host")] : SAR_TEXT("localhost");
		tstring user = config.has_key( SAR_TEXT("user") ) ? config[SAR_TEXT("user")] : NULL;
		tstring pwd = config.has_key( SAR_TEXT("password") ) ? config[SAR_TEXT("password")] : NULL;
		tstring database = config[SAR_TEXT("database")];
		tstring port = config.has_key( SAR_TEXT("port") ) ? config[SAR_TEXT("port")] : SAR_TEXT("0");
        mysql_real_connect( db,
                            SAR_T2S(host).c_str(),
                            SAR_T2S(user).c_str(),
                            SAR_T2S(pwd).c_str(),
                            SAR_T2S(database).c_str(),
                            string_to_int(port),
                            NULL,
                            0 );
        test_result( mysql_errno( db ), SAR_TEXT("problem opening database") );
        execute( SAR_TEXT("CREATE TABLE IF NOT EXISTS ") + table_prefix + SAR_TEXT("id_maximums (id INT, classname VARCHAR(255))") );
        execute( SAR_TEXT("CREATE TABLE IF NOT EXISTS ") + table_prefix + SAR_TEXT("relationships (class_one VARCHAR(255), class_one_id INT, class_two VARCHAR(255), class_two_id INT)") );
        debug( SAR_TEXT("Mysql database opened successfully") );
    };

    void MySQLStorage::close()
    {
        if( is_closed )
            return;
        is_closed = true;
        mysql_close( db );
    };

    void MySQLStorage::execute( tstring query )
    {
        MYSQL_STMT* stmt = mysql_stmt_init( db );
        int rc = mysql_stmt_prepare( stmt, SAR_T2S(query).c_str(), (int)query.length() );
        test_result( rc, SAR_TEXT("preparing sql query: ") + query );
        rc = mysql_stmt_execute( stmt );
        test_result( rc, SAR_TEXT("executing sql query: ") + query );
    }

    void MySQLStorage::test_result( int result, const tstring& context )
    {
        if( result != 0 )
        {
            tstring msg = SAR_TEXT("Mysql Error - ") + context + SAR_TEXT(": ") + SAR_C2T( mysql_error( db ) ) + SAR_TEXT("\n");
            mysql_close( db );
            is_closed = true;
            throw Sar_DBException( msg );
        }
    };

    void MySQLStorage::initialize_tables( tstring classname )
    {
        tstring tablename;

        // make table for string values
        tablename = table_prefix + classname + SAR_TEXT("_s");
        if( !table_is_initialized( tablename ) )
        {
            debug( SAR_TEXT("initializing table ") + tablename );
            tstring query = SAR_TEXT("CREATE TABLE IF NOT EXISTS ") + tablename + SAR_TEXT(" (id INT, keyname VARCHAR(255), value VARCHAR(") + SAR_S2T(VALUE_MAX_SIZE_S) + SAR_TEXT("))");
            execute( query );
            initialized_tables.push_back( tablename );
        }

        // make table for int values
        tablename = table_prefix + classname + SAR_TEXT("_i");
        if( !table_is_initialized( tablename ) )
        {
            debug( SAR_TEXT("initializing table ") + tablename );
            execute( SAR_TEXT("CREATE TABLE IF NOT EXISTS ") + tablename + SAR_TEXT(" (id INT, keyname VARCHAR(255), value INT)") );
            initialized_tables.push_back( tablename );
        }

        // make table for int values
        tablename = table_prefix + classname + SAR_TEXT("_dt");
        if( !table_is_initialized( tablename ) )
        {
            debug( SAR_TEXT("initializing table ") + tablename );
            execute( SAR_TEXT("CREATE TABLE IF NOT EXISTS ") + tablename + SAR_TEXT(" (id INT, keyname VARCHAR(255), value INT)") );
            initialized_tables.push_back( tablename );
        }

        // make table for exiting objects
        tablename = table_prefix + classname + SAR_TEXT("_e");
        if( !table_is_initialized( tablename ) )
        {
            debug( SAR_TEXT("initializing table ") + tablename );
            execute( SAR_TEXT("CREATE TABLE IF NOT EXISTS ") + tablename + SAR_TEXT(" (id INT)") );
            initialized_tables.push_back( tablename );
        }

        debug( SAR_TEXT("Finished initializing tables for class ") + classname );
    };

    void MySQLStorage::insert( tstring table, SarVector<KVT> cols )
    {
        tstring columns, sint;
        tstring values = SAR_TEXT("");
        SarVector<tstring> s_cols;
        for( unsigned int i = 0; i < cols.size(); i++ )
            s_cols << cols[i].key;
        join( s_cols, SAR_TEXT(","), columns );
        for( unsigned int i = 0; i < cols.size(); i++ )
        {
            if( cols[i].type == STRING )
            {
                values += SAR_TEXT("\"") + cols[i].svalue + SAR_TEXT("\"");
            }
            else if( cols[i].type == INTEGER )
            {
                int_to_string( cols[i].ivalue, sint );
                values += sint;
            }
            if( i != cols.size() - 1 )
                values += SAR_TEXT(",");
        }
        tstring query = SAR_TEXT("INSERT INTO ") + table + SAR_TEXT(" (") + columns + SAR_TEXT(") VALUES(") + values + SAR_TEXT(")");
        execute( query );
    };

    void MySQLStorage::remove( tstring table, tstring where )
    {
        execute( SAR_TEXT("DELETE FROM ") + ( ( where == SAR_TEXT("") ) ? table : table + SAR_TEXT(" WHERE ") + where ) );
    };

    void MySQLStorage::update( tstring table, SarVector<KVT> cols, tstring where )
    {
        tstring setstring = SAR_TEXT("");
        tstring sint;
        for( unsigned int i = 0; i < cols.size(); i++ )
        {
            if( cols[i].type == STRING )
            {
                setstring += cols[i].key + SAR_TEXT("=\"") + cols[i].svalue + SAR_TEXT("\"");
            }
            else if( cols[i].type == INTEGER )
            {
                int_to_string( cols[i].ivalue, sint );
                setstring += cols[i].key + SAR_TEXT("=") + sint;
            }
            if( i != cols.size() - 1 )
                setstring += SAR_TEXT(",");
        }
        execute( SAR_TEXT("UPDATE ") + table + SAR_TEXT(" SET ") + ( ( where == SAR_TEXT("") ) ? setstring : setstring + SAR_TEXT(" WHERE ") + where ) );
    };

    SarVector<Row> MySQLStorage::select( tstring table, SarVector<KVT> cols, tstring where, bool distinct )
    {
        tstring columns;
        SarVector<tstring> s_cols;
        for( unsigned int i = 0; i < cols.size(); i++ )
            s_cols << cols[i].key;

        SarVector<Row> result;
        join( s_cols, SAR_TEXT(","), columns );
        tstring query = ( distinct ? SAR_TEXT("SELECT DISTINCT ") : SAR_TEXT("SELECT ") ) + columns + SAR_TEXT(" FROM ") + ( ( where == SAR_TEXT("") ) ? table : table + SAR_TEXT(" WHERE ") + where );
        debug( query );
        int rc = mysql_real_query( db, SAR_T2S(query).c_str(), (int)query.length() );
        if( rc != 0 )
            throw Sar_DBException( SAR_TEXT("error preparing sql query: ") + query );
        MYSQL_RES* res = mysql_use_result( db );
        MYSQL_ROW row;
        while( ( row = mysql_fetch_row( res ) ) )
        {
            Row r;
            for( unsigned int i = 0; i < cols.size(); i++ )
            {
                if( cols[i].type == INTEGER )
                {
                    r << string_to_int( SAR_C2T( row[i] ) );
                }
                else if( cols[i].type == STRING )
                {
                    char c_key[255];
                    _snprintf( c_key, 255, "%s", row[i] );
					r << SAR_S2T(std::string( c_key ));
                }
            }
            result << r;
        }
        return result;
    };

};
