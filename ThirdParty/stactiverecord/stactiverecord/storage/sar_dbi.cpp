#include "../stactive_record.h"

#ifdef HAVE_SQLITE3
#include "sqlite_storage.h"
#endif

#ifdef HAVE_POSTGRESQL
#include "postgresql_storage.h"
#endif

#ifdef HAVE_MYSQL
#include "mysql_storage.h"
#endif

namespace stactiverecord
{

    Sar_Dbi* Sar_Dbi::makeStorage( tstring config, tstring prefix )
    {
        std::vector<tstring> configparts = explode( config, SAR_TEXT("://") );
        if( configparts.size() != 2 )
            throw Sar_InvalidConfigurationException( SAR_TEXT("Invalid database configuration string: ") + config );

#ifdef HAVE_MYSQL
        if( configparts[0] == SAR_TEXT("mysql") )
            return new MySQLStorage( configparts[1], prefix );
#endif

#ifdef HAVE_SQLITE3
        if( configparts[0] == SAR_TEXT("sqlite") )
            return new SQLiteStorage( configparts[1], prefix );
#endif

#ifdef HAVE_POSTGRESQL
        if( configparts[0] == SAR_TEXT("postgres") )
            return new PostgreSQLStorage( configparts[1], prefix );
#endif

        throw Sar_InvalidConfigurationException( SAR_TEXT("DB type of \"") + configparts[0] + SAR_TEXT("\" not recognized.") );
    };

    /** @param config The db configuration - "scheme://[user[:password]@host[:port]/]database"
        \returns A hashmap that can contain the following keys: user, password, host, port, database
    */
    SarMap<tstring> Sar_Dbi::parseconfig( tstring config )
    {
        SarMap<tstring> result;
        std::vector<tstring> parts = explode( config, SAR_TEXT("/") );
        if( parts.size() == 1 )
        {
            result[SAR_TEXT("database")] = parts[0];
            return result;
        }
        result[SAR_TEXT("database")] = parts[1];
        parts = explode( parts[0], SAR_TEXT("@") );
        if( parts.size() == 1 )
            throw Sar_InvalidConfigurationException( SAR_TEXT("If you specify a user you must also specify a host") );
        tstring user = parts[0];
        tstring host = parts[1];
        parts = explode( user, SAR_TEXT(":") );
        if( parts.size() == 1 )
        {
            result[SAR_TEXT("user")] = user;
        }
        else
        {
            result[SAR_TEXT("user")] = parts[0];
            result[SAR_TEXT("password")] = parts[1];
        }

        parts = explode( host, SAR_TEXT(":") );
        if( parts.size() == 1 )
        {
            result[SAR_TEXT("host")] = host;
        }
        else
        {
            result[SAR_TEXT("host")] = parts[0];
            result[SAR_TEXT("port")] = parts[1];
        }
        return result;
    };

    bool Sar_Dbi::exists( tstring classname, int id )
    {
        tstring tablename = table_prefix + classname + SAR_TEXT("_e");
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("id"), INTEGER );
        return select( tablename, cols, Q( SAR_TEXT("id"), id ) ).size() != 0;
    };

    void Sar_Dbi::make_existing( tstring classname, int id )
    {
        tstring tablename = table_prefix + classname + SAR_TEXT("_e");
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("id"), id );
        insert( tablename, cols );
    };

    void Sar_Dbi::update( tstring table, SarVector<KVT> cols, Q qwhere )
    {
        tstring where;
        qwhere.to_string( where );
        update( table, cols, where );
    };

    void Sar_Dbi::remove( tstring table, Q qwhere )
    {
        tstring where = SAR_TEXT("");
        qwhere.to_string( where );
        remove( table, where );
    };

    SarVector<Row> Sar_Dbi::select( tstring table, SarVector<KVT> cols, Q qwhere, bool distinct )
    {
        tstring where;
        qwhere.to_string( where );
        return select( table, cols, where, distinct );
    };

    bool Sar_Dbi::table_is_initialized( tstring tablename )
    {
        return initialized_tables.includes( tablename );
    };

    int Sar_Dbi::next_id( tstring classname )
    {
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("id"), INTEGER );
        SarVector<Row> row = select( table_prefix + SAR_TEXT("id_maximums"), cols, Q( SAR_TEXT("classname"), classname ) );
        SarVector<KVT> values;
        if( row.size() == 0 )
        {
            debug( SAR_TEXT("could not find max id int for ") + classname + SAR_TEXT(" - starting at 0") );
            values << KVT( SAR_TEXT("id"), 0 );
            values << KVT( SAR_TEXT("classname"), classname );
            insert( table_prefix + SAR_TEXT("id_maximums"), values );
            return 0;
        }
        int maxid = row[0].get_int( 0 ) + 1;
        values << KVT( SAR_TEXT("id"), maxid );
        update( table_prefix + SAR_TEXT("id_maximums"), values, Q( SAR_TEXT("classname"), classname ) );
        return maxid;
    };

    int Sar_Dbi::current_id( tstring classname )
    {
        SarVector<KVT> values;
        values << KVT( SAR_TEXT("id"), INTEGER );
        SarVector<Row> rows = select( table_prefix + SAR_TEXT("id_maximums"), values, Q( SAR_TEXT("classname"), classname ) );
        if( rows.size() == 0 )
            return -1;
        return rows[0].get_int( 0 );
    };

    void Sar_Dbi::get( int id, tstring classname, SarMap<tstring>& values )
    {
        values.clear();
        tstring tablename = table_prefix + classname + SAR_TEXT("_s");
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("keyname"), STRING );
        cols << KVT( SAR_TEXT("value"), STRING );
        SarVector<Row> rows = select( tablename, cols, Q( SAR_TEXT("id"), id ) );
        tstring key, value;
        for ( unsigned int i = 0; i < rows.size(); i++ )
        {
            rows[i].get_string( 0, key );
            rows[i].get_string( 1, value );
            values[key] = value;
        }
    };

    void Sar_Dbi::get( int id, tstring classname, SarMap<int>& values )
    {
        values.clear();
        tstring tablename = table_prefix + classname + SAR_TEXT("_i");
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("keyname"), STRING );
        cols << KVT( SAR_TEXT("value"), INTEGER );
        SarVector<Row> rows = select( tablename, cols, Q( SAR_TEXT("id"), id ) );
        tstring key;
        int value;
        for ( unsigned int i = 0; i < rows.size(); i++ )
        {
			if(rows[i].ints.empty()) continue;
            rows[i].get_string( 0, key );
            value = rows[i].get_int( 0 );
            values[key] = value;
        }
    };

	void Sar_Dbi::get( int id, tstring classname, SarMap<double>& values )
	{
		values.clear();
		tstring tablename = table_prefix + classname + SAR_TEXT("_f");
		SarVector<KVT> cols;
		cols << KVT( SAR_TEXT("keyname"), STRING );
		cols << KVT( SAR_TEXT("value"), INTEGER );
		SarVector<Row> rows = select( tablename, cols, Q( SAR_TEXT("id"), id ) );
		tstring key;
		double value;
		for ( unsigned int i = 0; i < rows.size(); i++ )
		{
			if(rows[i].decimals.empty()) continue;
			rows[i].get_string( 0, key );
			value = rows[i].get_decimal( 0 );
			values[key] = value;
		}
	};

    void Sar_Dbi::get( int id, tstring classname, SarMap<DateTime>& values )
    {
        values.clear();
        tstring tablename = table_prefix + classname + SAR_TEXT("_dt");
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("keyname"), STRING );
        cols << KVT( SAR_TEXT("value"), INTEGER );
        SarVector<Row> rows = select( tablename, cols, Q( SAR_TEXT("id"), id ) );
        tstring key;
        for ( unsigned int i = 0; i < rows.size(); i++ )
        {
			if(rows[i].strings.empty()) continue;
            rows[i].get_string( 0, key );
            DateTime dt;
            dt.from_int( rows[i].get_int( 0 ) );
            values[key] = dt;
        }
    };

    void Sar_Dbi::set( int id, tstring classname, SarMap<tstring> values, bool isinsert )
    {
        tstring tablename = table_prefix + classname + SAR_TEXT("_s");
        for( std::map<tstring, tstring>::iterator i = values.begin(); i != values.end(); ++i )
        {
            SarVector<KVT> values;
            values << KVT( SAR_TEXT("value"), tstring( ( *i ).second ) );
            if( isinsert )
            {
                values << KVT( SAR_TEXT("id"), id );
                values << KVT( SAR_TEXT("keyname"), tstring( ( *i ).first ) );
                insert( tablename, values );
            }
            else
            {
                update( tablename, values, Q( SAR_TEXT("id"), id ) && Q( SAR_TEXT("keyname"), ( *i ).first ) );
            }
        }
    };

    void Sar_Dbi::set( int id, tstring classname, SarMap<int> values, bool isinsert )
    {
        tstring tablename = table_prefix + classname + SAR_TEXT("_i");
        for( std::map<tstring, int>::iterator i = values.begin(); i != values.end(); ++i )
        {
            SarVector<KVT> values;
            values << KVT( SAR_TEXT("value"), ( *i ).second );
            if( isinsert )
            {
                values << KVT( SAR_TEXT("id"), id );
                values << KVT( SAR_TEXT("keyname"), tstring( ( *i ).first ) );
                insert( tablename, values );
            }
            else
            {
                update( tablename, values, Q( SAR_TEXT("id"), id ) && Q( SAR_TEXT("keyname"), tstring( ( *i ).first ) ) );
            }
        }
    };

	void Sar_Dbi::set( int id, tstring classname, SarMap<double> values, bool isinsert )
	{
		tstring tablename = table_prefix + classname + SAR_TEXT("_f");
		for( std::map<tstring, double>::iterator i = values.begin(); i != values.end(); ++i )
		{
			SarVector<KVT> values;
			values << KVT( SAR_TEXT("value"), ( *i ).second );
			if( isinsert )
			{
				values << KVT( SAR_TEXT("id"), id );
				values << KVT( SAR_TEXT("keyname"), tstring( ( *i ).first ) );
				insert( tablename, values );
			}
			else
			{
				update( tablename, values, Q( SAR_TEXT("id"), id ) && Q( SAR_TEXT("keyname"), tstring( ( *i ).first ) ) );
			}
		}
	};

    void Sar_Dbi::set( int id, tstring classname, SarMap<DateTime> values, bool isinsert )
    {
        tstring tablename = table_prefix + classname + SAR_TEXT("_dt");
        for( std::map<tstring, DateTime>::iterator i = values.begin(); i != values.end(); ++i )
        {
            SarVector<KVT> values;
            values << KVT( SAR_TEXT("value"), ( ( *i ).second ).to_int() );
            if( isinsert )
            {
                values << KVT( SAR_TEXT("id"), id );
                values << KVT( SAR_TEXT("keyname"), tstring( ( *i ).first ) );
                insert( tablename, values );
            }
            else
            {
                update( tablename, values, Q( SAR_TEXT("id"), id ) && Q( SAR_TEXT("keyname"), tstring( ( *i ).first ) ) );
            }
        }
    };

    void Sar_Dbi::del( int id, tstring classname, SarVector<tstring> keys, coltype ct )
    {
        tstring tablename = table_prefix + classname;
		if( ct == STRING )
		{
			tablename += SAR_TEXT("_s");
		}
		else if(ct == INTEGER)
		{
			tablename += SAR_TEXT("_i");
		}
		else if(ct == DECIMAL)
		{
			tablename += SAR_TEXT("_f");
		}
        for( unsigned int i = 0; i < keys.size(); i++ )
            remove( tablename, Q( SAR_TEXT("id"), id ) && Q( SAR_TEXT("keyname"), keys[i] ) );
    };

    void Sar_Dbi::delete_record( int id, tstring classname )
    {
        tstring tablename = table_prefix + classname + SAR_TEXT("_s");
        remove( tablename, Q( SAR_TEXT("id"), id ) );

        tablename = table_prefix + classname + SAR_TEXT("_i");
        remove( tablename, Q( SAR_TEXT("id"), id ) );

		tablename = table_prefix + classname + SAR_TEXT("_f");
		remove( tablename, Q( SAR_TEXT("id"), id ) );

        tablename = table_prefix + classname + SAR_TEXT("_e");
        remove( tablename, Q( SAR_TEXT("id"), id ) );

        tablename = table_prefix + SAR_TEXT("relationships");
        remove( tablename, Q( SAR_TEXT("class_one"), classname ) && Q( SAR_TEXT("class_one_id"), id ) );
        remove( tablename, Q( SAR_TEXT("class_two"), classname ) && Q( SAR_TEXT("class_two_id "), id ) );
    };

    void Sar_Dbi::delete_records( tstring classname )
    {
        // delete string values table
        tstring tablename = table_prefix + classname + SAR_TEXT("_s");
        remove( tablename );

        // delete int values table
        tablename = table_prefix + classname + SAR_TEXT("_i");
        remove( tablename );

		// delete decimal values table
		tablename = table_prefix + classname + SAR_TEXT("_f");
		remove( tablename );

        // delete existing values table
        tablename = table_prefix + classname + SAR_TEXT("_e");
        remove( tablename );

        tstring sclassname_where;
        tablename = table_prefix + SAR_TEXT("relationships");
        Where* classname_where = equals( classname );
        where_to_string( classname_where, sclassname_where );

        // delete entries from relationships
        remove( tablename, Q( SAR_TEXT("class_one"), classname ) || Q( SAR_TEXT("class_two"), classname ) );

        // delete max id
        tablename = table_prefix + SAR_TEXT("id_maximums");
        remove( tablename, Q( SAR_TEXT("classname"), classname ) );
    };

    void Sar_Dbi::set( int id, tstring classname, SarVector<int> related, tstring related_classname )
    {
        tstring tablename = table_prefix + SAR_TEXT("relationships");
        bool swap = ( strcmp( SAR_T2S(classname).c_str(), SAR_T2S(related_classname).c_str() ) > 0 ) ? true : false;
        debug( SAR_TEXT("Adding related ") + related_classname + SAR_TEXT("s to a ") + classname );
        for( SarVector<int>::size_type i = 0; i < related.size(); i++ )
        {
            SarVector<KVT> values;
            if( swap )
            {
                values << KVT( SAR_TEXT("class_one"), related_classname );
                values << KVT( SAR_TEXT("class_one_id"), related[i] );
                values << KVT( SAR_TEXT("class_two"), classname );
                values << KVT( SAR_TEXT("class_two_id"), id );
            }
            else
            {
                values << KVT( SAR_TEXT("class_one"), classname );
                values << KVT( SAR_TEXT("class_one_id"), id );
                values << KVT( SAR_TEXT("class_two"), related_classname );
                values << KVT( SAR_TEXT("class_two_id"), related[i] );
            }
            insert( tablename, values );
        }
    };

    void Sar_Dbi::get( int id, tstring classname, tstring related_classname, SarVector<int>& related )
    {
        related.clear();
        tstring tablename = table_prefix + SAR_TEXT("relationships");
        debug( SAR_TEXT("Getting related ") + related_classname + SAR_TEXT("s to a ") + classname );
        bool swap = ( strcmp( SAR_T2S(classname).c_str(), SAR_T2S(related_classname).c_str() ) > 0 ) ? true : false;
        SarVector<KVT> cols;
        SarVector<Row> rows;

        if( swap )
        {
            cols << KVT( SAR_TEXT("class_one_id"), INTEGER );
            rows = select( tablename, cols, Q( SAR_TEXT("class_one"), related_classname ) && Q( SAR_TEXT("class_two_id"), id ) && Q( SAR_TEXT("class_two"), classname ) );
        }
        else
        {
            cols << KVT( SAR_TEXT("class_two_id"), INTEGER );
            rows = select( tablename, cols, Q( SAR_TEXT("class_one"), classname ) && Q( SAR_TEXT("class_one_id"), id ) && Q( SAR_TEXT("class_two"), related_classname ) );
        }

        for( unsigned int i = 0; i < rows.size(); i++ )
            related << rows[i].get_int( 0 );
    };

    void Sar_Dbi::get( int id, tstring classname, SarMap< SarVector<int> >& sm )
    {
        sm.clear();
        debug( SAR_TEXT("Getting all related objects to a ") + classname );
        tstring tablename = table_prefix + SAR_TEXT("relationships");
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("class_one"), STRING );
        cols << KVT( SAR_TEXT("class_one_id"), INTEGER );
        SarVector<Row> rows = select( tablename, cols, Q( SAR_TEXT("class_two"), classname ) && Q( SAR_TEXT("class_two_id"), id ) );
        for( unsigned int i = 0; i < rows.size(); i++ )
        {
            tstring key;
            rows[i].get_string( 0, key );
            if( !sm.has_key( key ) )
                sm[key] = SarVector<int>();
            sm[key] << rows[i].get_int( 0 );
        }

        cols.clear();
        cols << KVT( SAR_TEXT("class_two"), STRING );
        cols << KVT( SAR_TEXT("class_two_id"), INTEGER );
        rows = select( tablename, cols, Q( SAR_TEXT("class_one"), classname ) && Q( SAR_TEXT("class_one_id"), id ) );
        for( unsigned int i = 0; i < rows.size(); i++ )
        {
            tstring key;
            rows[i].get_string( 0, key );
            if( !sm.has_key( key ) )
                sm[key] = SarVector<int>();
            sm[key] << rows[i].get_int( 0 );
        }
    };

    void Sar_Dbi::del( int id, tstring classname, SarVector<int> related, tstring related_classname )
    {
        if( related.size() == 0 )
            return;
        tstring tablename = table_prefix + SAR_TEXT("relationships");
        debug( SAR_TEXT("Deleting some related ") + related_classname + SAR_TEXT("s to a ") + classname );
        bool swap = ( strcmp( SAR_T2S(classname).c_str(), SAR_T2S(related_classname).c_str() ) > 0 ) ? true : false;
        if( swap )
            remove( tablename, Q( SAR_TEXT("class_two"), classname ) && Q( SAR_TEXT("class_two_id"), id ) && Q( SAR_TEXT("class_one"), related_classname ) && Q( SAR_TEXT("class_one_id"), in( related ) ) );
        else
            remove( tablename, Q( SAR_TEXT("class_one"), classname ) && Q( SAR_TEXT("class_one_id"), id ) && Q( SAR_TEXT("class_two"), related_classname ) && Q( SAR_TEXT("class_two_id"), in( related ) ) );
    };

    void Sar_Dbi::get( tstring classname, SarVector<int>& results )
    {
        results.clear();
        tstring tablename = table_prefix + classname + SAR_TEXT("_s");
        debug( SAR_TEXT("Getting all objects of type ") + classname );
        SarVector<KVT> cols;
        cols << KVT( SAR_TEXT("id"), INTEGER );
        SarVector<Row> rows = select( tablename, cols, SAR_TEXT(""), true );

        tablename = table_prefix + classname + SAR_TEXT("_i");
        rows.unionize( select( tablename, cols, SAR_TEXT(""), true ) );

		tablename = table_prefix + classname + SAR_TEXT("_f");
		rows.unionize( select( tablename, cols, SAR_TEXT(""), true ) );

        tablename = table_prefix + SAR_TEXT("relationships");
        cols.clear();
        cols << KVT( SAR_TEXT("class_one_id"), INTEGER );
        rows.unionize( select( tablename, cols, Q( SAR_TEXT("class_one"), classname ), true ) );

        cols.clear();
        cols << KVT( SAR_TEXT("class_two_id"), INTEGER );
        rows.unionize( select( tablename, cols, Q( SAR_TEXT("class_two"), classname ), true ) );

        for( unsigned int i = 0; i < rows.size(); i++ )
            results << rows[i].get_int( 0 );
    };

    void Sar_Dbi::get_where( tstring classname, tstring key, Where* where, SarVector<int>& results )
    {
        results.clear();
        bool isnot = where->isnot;
        SarVector<Row> rows;
        SarVector<KVT> cols;
        tstring tablename;
        if( where->ct == INTEGER )
        {
            tablename = table_prefix + classname + SAR_TEXT("_i");
            cols << KVT( SAR_TEXT("id"), INTEGER );
            rows = select( tablename, cols, Q( SAR_TEXT("keyname"), key ) && Q( SAR_TEXT("value"), where ) );
        }
		else if( where->ct == DECIMAL )
		{
			tablename = table_prefix + classname + SAR_TEXT("_f");
			cols << KVT( SAR_TEXT("id"), INTEGER );
			rows = select( tablename, cols, Q( SAR_TEXT("keyname"), key ) && Q( SAR_TEXT("value"), where ) );
		}
        else if( where->ct == DATETIME )
        {
            tablename = table_prefix + classname + SAR_TEXT("_dt");
            cols << KVT( SAR_TEXT("id"), INTEGER );
            rows = select( tablename, cols, Q( SAR_TEXT("keyname"), key ) && Q( SAR_TEXT("value"), where ) );
        }
        else if( where->ct == STRING )
        {
            tablename = table_prefix + classname + SAR_TEXT("_s");
            cols << KVT( SAR_TEXT("id"), INTEGER );
            rows = select( tablename, cols, Q( SAR_TEXT("keyname"), key ) && Q( SAR_TEXT("value"), where ) );
        }
        else if( where->ct == ALL )   // special case - can't just do one select
        {
            // if we're testing isnull() type of where
            if( where->type == ISNULL )
            {
                cols << KVT( SAR_TEXT("id"), INTEGER );
                if( where->isnot )
                {
                    tablename = table_prefix + classname + SAR_TEXT("_s");
                    rows = select( tablename, cols, Q( SAR_TEXT("keyname"), key ), true );
                    tablename = table_prefix + classname + SAR_TEXT("_i");
                    rows.unionize( select( tablename, cols, Q( SAR_TEXT("keyname"), key ), true ) );
					tablename = table_prefix + classname + SAR_TEXT("_f");
					rows.unionize( select( tablename, cols, Q( SAR_TEXT("keyname"), key ), true ) );
                }
                else
                {
                    // terribly inefficient
                    tablename = table_prefix + classname + SAR_TEXT("_s");
                    rows = select( tablename, cols, Q( SAR_TEXT("keyname"), key ), true );
                    SarVector<int> ids;
                    for( unsigned int i = 0; i < rows.size(); i++ )
                        ids << rows[i].get_int( 0 );

                    tablename = table_prefix + classname + SAR_TEXT("_e");
                    rows = ( ids.size() > 0 ) ? select( tablename, cols, Q( SAR_TEXT("id"), nin( ids ) ) ) : select( tablename, cols );

                    tablename = table_prefix + classname + SAR_TEXT("_i");
                    SarVector<Row> tmp = select( tablename, cols, Q( SAR_TEXT("keyname"), key ), true );
                    ids.clear();
                    for( unsigned int i = 0; i < tmp.size(); i++ )
                        ids << tmp[i].get_int( 0 );

                    tablename = table_prefix + classname + SAR_TEXT("_e");
                    SarVector<Row> otherrows = ( ids.size() > 0 ) ? select( tablename, cols, Q( SAR_TEXT("id"), nin( ids ) ) ) : select( tablename, cols );
                    rows = rows.intersects( otherrows );
                }
            }
        }
        else     //RECORD
        {
            tablename = table_prefix + SAR_TEXT("relationships");
            bool swap = ( strcmp( SAR_T2S(classname).c_str(), SAR_T2S(where->svalue).c_str() ) > 0 ) ? true : false;
            if( swap )
            {
                cols << KVT( SAR_TEXT("class_two_id"), INTEGER );
                rows = select( tablename, cols, Q( SAR_TEXT("class_two"), classname ) && Q( SAR_TEXT("class_one_id"), where->ivalue ) && Q( SAR_TEXT("class_one"), where->svalue ) );
            }
            else
            {
                cols << KVT( SAR_TEXT("class_one_id"), INTEGER );
                rows = select( tablename, cols, Q( SAR_TEXT("class_one"), classname ) && Q( SAR_TEXT("class_two_id"), where->ivalue ) && Q( SAR_TEXT("class_two"), where->svalue ) );
                // in the case in which the two classnames are the same, we need to try both (swap will be false, so try them swapped as well)
                if( classname == where->svalue )
                {
                    cols.clear();
                    cols << KVT( SAR_TEXT("class_two_id"), INTEGER );
                    rows.unionize( select( tablename, cols, Q( SAR_TEXT("class_two"), classname ) && Q( SAR_TEXT("class_one_id"), where->ivalue ) && Q( SAR_TEXT("class_one"), where->svalue ) ) );
                }
            }
        }

        for( unsigned int i = 0; i < rows.size(); i++ )
            results << rows[i].get_int( 0 );
    };

    /** Most SQL db's will use the following - kids can overwrite if necessary (like postgres) **/
    void Sar_Dbi::where_to_string( Where* where, tstring& swhere )
    {
        bool isnot = where->isnot;
        if( where->ct == INTEGER || where->ct == DATETIME )
        {
            tstring sint, second_sint;
            int_to_string( where->ivalue, sint );
            switch( where->type )
            {
            case GREATERTHAN:
                swhere = ( ( isnot ) ? SAR_TEXT("<= ") : SAR_TEXT("> ") ) + sint ;
                break;
            case LESSTHAN:
                swhere = ( ( isnot ) ? SAR_TEXT(">= ") : SAR_TEXT("< ") ) + sint;
                break;
            case EQUALS:
                swhere = ( ( isnot ) ? SAR_TEXT("!= ") : SAR_TEXT("= ") ) + sint;
                break;
            case BETWEEN:
                int_to_string( where->ivaluetwo, second_sint );
                swhere = ( ( isnot ) ? SAR_TEXT("NOT BETWEEN ") : SAR_TEXT("BETWEEN ") ) + sint + SAR_TEXT(" AND ") + second_sint;
                break;
            case ISIN:
                tstring idlist = SAR_TEXT("(");
                for( std::vector<int>::size_type i = 0; i < where->ivalues.size(); i++ )
                {
                    int_to_string( where->ivalues[i], sint );
                    idlist += sint;
                    if( i != ( where->ivalues.size() - 1 ) )
                        idlist += SAR_TEXT(",");
                }
                idlist += SAR_TEXT(")");
                swhere = ( ( isnot ) ? SAR_TEXT("NOT IN ") : SAR_TEXT("IN ") ) + idlist;
                break;
            }
        }
		else if( where->ct == DECIMAL )
		{
			tstring sint, second_sint;
			double_to_string( where->fvalue, sint );
			switch( where->type )
			{
			case GREATERTHAN:
				swhere = ( ( isnot ) ? SAR_TEXT("<= ") : SAR_TEXT("> ") ) + sint ;
				break;
			case LESSTHAN:
				swhere = ( ( isnot ) ? SAR_TEXT(">= ") : SAR_TEXT("< ") ) + sint;
				break;
			case EQUALS:
				swhere = ( ( isnot ) ? SAR_TEXT("!= ") : SAR_TEXT("= ") ) + sint;
				break;
			case BETWEEN:
				double_to_string( where->fvaluetwo, second_sint );
				swhere = ( ( isnot ) ? SAR_TEXT("NOT BETWEEN ") : SAR_TEXT("BETWEEN ") ) + sint + SAR_TEXT(" AND ") + second_sint;
				break;
			//case ISIN:
			//	tstring idlist = SAR_TEXT("(");
			//	for( std::vector<int>::size_type i = 0; i < where->fvalues.size(); i++ )
			//	{
			//		int_to_string( where->fvalues[i], sint );
			//		idlist += sint;
			//		if( i != ( where->ivalues.size() - 1 ) )
			//			idlist += SAR_TEXT(",");
			//	}
			//	idlist += SAR_TEXT(")");
			//	swhere = ( ( isnot ) ? SAR_TEXT("NOT IN ") : SAR_TEXT("IN ") ) + idlist;
			//	break;
			}
		}
        else if( where->ct == STRING )
        {
            switch( where->type )
            {
            case STARTSWITH:
                swhere = ( ( isnot ) ? SAR_TEXT("NOT LIKE \"") : SAR_TEXT("LIKE \"") ) + where->svalue + SAR_TEXT("%\"");
                break;
            case ENDSWITH:
                swhere = ( ( isnot ) ? SAR_TEXT("NOT LIKE \"%") : SAR_TEXT("LIKE \"%") ) + where->svalue + SAR_TEXT("\"");
                break;
            case EQUALS:
                swhere = ( ( isnot ) ? SAR_TEXT("!= \"") : SAR_TEXT("= \"") ) + where->svalue + SAR_TEXT("\"");
                break;
            case CONTAINS:
                swhere = ( ( isnot ) ? SAR_TEXT("NOT LIKE \"%") : SAR_TEXT("LIKE \"%") ) + where->svalue + SAR_TEXT("%\"");
            }
        }
    };

};
