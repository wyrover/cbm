#include "StdAfx.h"
#include "Query.h"

using namespace std;

namespace orm
{

	/** Split a CString s into parts by value e */
	static std::vector<std::string> explode(std::string s, std::string e) 
	{
		std::vector<std::string> ret;
		int iPos = s.find(e, 0);
		int iPit = e.length();
		while(iPos>-1) {
			if(iPos!=0)
				ret.push_back(s.substr(0,iPos));
			s.erase(0,iPos+iPit);
			iPos = s.find(e, 0);
		}
		if(s!="")
			ret.push_back(s);
		return ret;
	}

	static CString join( vector<CString> vec, CString delim )
	{
		if( vec.empty() )
			return "";

		CString result;
		for( vector<CString>::iterator it = vec.begin(); it != vec.end() - 1; ++it )
		{
			result += ( *it ) + delim;
		}
		return result +	( *vec.rbegin() );
	}

	static CString cstring_join( vector<CString> vec, CString delim )
	{
		CString result;

		if( vec.empty() )
			return _T("");

		for( vector<CString>::iterator it = vec.begin(); it != vec.end() - 1; ++it )
		{
			result +=
				( *it ) + delim;
		}
		return result +	( *vec.rbegin() );
	}

	static void cstring_explode(const CString& str, const CString& tokens, CStringArray& values)
	{
		int nTokenPos = 0;
		CString strToken = str.Tokenize(tokens, nTokenPos);
		while (!strToken.IsEmpty())
		{
			values.Add(strToken);
			strToken = str.Tokenize(tokens, nTokenPos);
		}
	}

    Query::Query() :
        n_limit( 0 ),
        currupted( false )
    {
    }
    Query::~Query()
    {
    }

    void Query::set_with_no_dirt( const CString& key, const CString& value )
    {
        fields[key] = value;
    }

    void Query::set_table( const CString& _table )
    {
        table = _table;
    }
    void Query::set_limit( int _n_limit )
    {
        n_limit = _n_limit;
    }

    void Query::add_result_column( const CString& col )
    {
        results.push_back( col );
    }
    void Query::add_condition( const CString& col, const CString& op, const CString& value )
    {

        conditions.push_back(
            col + _T(" ") + op + _T(" \'") +
            /*escape*/( value ) + _T("\'") );
    }
    void Query::add_condition( const CString& query )
    {
        conditions.push_back( query );
    }
    void Query::add_order_by( const CString& col, const CString& order )
    {
        order_by.push_back(
            col + _T(" ") + order );
    }
    void Query::add_group_by( const CString& col )
    {
        group_by.push_back( col );
    }

    void Query::dirt_field( const CString& field_name )
    {
        dirty_fields.push_back( field_name );
    }
    void Query::clean_dirty_fields()
    {
        dirty_fields.clear();
    }

    CString Query::build_result_columns()
    {
        if( results.empty() )
            return _T("*");
        else
            return cstring_join( results, _T(",") );
    }
    CString Query::build_conditions()
    {
        CString query = _T("WHERE ");
        return query + cstring_join( conditions, _T(" AND ") );
    }
    CString Query::build_field_keys()
    {
        CString keys;
        map<CString, CString>::iterator it = fields.begin();

        while( it != fields.end() )
        {
            keys += ( *it ).first;

            if( ++it != fields.end() )
                keys += _T(",");
        }

        return keys;
    }
    CString Query::build_field_values()
    {
        CString values;
        map<CString, CString>::iterator it = fields.begin();

        while( it != fields.end() )
        {
            values += _T("\'") +
                      /*escape*/( ( *it ).second ) + _T("\'");

            if( ++it != fields.end() )
                values += _T(",");
        }

        return values;
    }
    CString Query::build_changes()
    {
        if( dirty_fields.empty() )
            return _T("");

		CString changes;
        for( vector<CString>::iterator itr = dirty_fields.begin(); itr != dirty_fields.end(); ++itr )
        {
            CString field_name = *itr;
            changes +=
                field_name + _T("=\'") +
                /*escape*/( fields[field_name] ) + _T("\',");
        }
		//ɾ�����һ���ַ�
        if( changes.IsEmpty() == false ) changes.Delete( changes.GetLength() - 1 );

        return changes;
    }
    CString Query::build_order_by()
    {
        CString orders = _T("ORDER BY ");

        orders += cstring_join( order_by, _T(",") );

        return orders;
    }
    CString Query::build_group_by()
    {
        CString groups = _T("GROUP BY ");
        groups += cstring_join( group_by, _T(",") );
        return groups;
    }

    CString Query::build_from()
    {
        CString query = _T("FROM ");
        query += table;
        return query;
    }
    CString Query::build_into()
    {
        CString query = _T("INTO ");
        query += table;
        return query;
    }
    CString Query::build_limit()
    {
		if( n_limit == 0 ) return "";
        CString query;
		query.AppendFormat(_T("LIMIT %d"), n_limit);
        return query;
    }

    CString Query::build_select()
    {
        CString query = _T("SELECT ");
        query +=
            build_result_columns() + _T(" ") +
            build_from() + _T(" ") +
            build_conditions() + _T(" ") +
            build_order_by() + _T(" ") +
            build_limit();

        return query;
    }
    CString Query::build_update()
    {
        CString query = _T("UPDATE ");

        query +=
            table + _T(" SET ") +
            build_changes() + _T(" ") +
            build_conditions();
        return query;
    }
    CString Query::build_delete()
    {
        CString query = _T("DELETE ");

        query +=
            build_from() + _T(" ") +
            build_conditions();
        return query;
    }
    CString Query::build_insert()
    {
        CString query = _T("INSERT ");
        query +=
            build_into() + _T(" (") +
            build_field_keys() + _T(") VALUES (") +
            build_field_values() + _T(")");

        return query;
    }

	Query* Query::from( const CString& table )
    {
		Query* Query = new orm::Query();

        Query->set_table( table );

        return Query;
    }

    Query* Query::where( const CString& col, const CString& value )
    {
        add_condition( col, _T("="), value );

        return this;
    }
    Query* Query::where_equal( const CString& col, const CString& value )
    {
        add_condition( col, _T("="), value );

        return this;
    }
    Query* Query::where_not_equal( const CString& col, const CString& value )
    {
        add_condition( col, _T("!="), value );

        return this;
    }
    Query* Query::where_like( const CString& col, const CString& value )
    {
        add_condition( col, _T("LIKE"), value );

        return this;
    }
    Query* Query::where_not_like( const CString& col, const CString& value )
    {
        add_condition( col, _T("NOT LIKE"), value );

        return this;
    }
    Query* Query::where_gt( const CString& col, const CString& value )
    {
        add_condition( col, _T(">"), value );

        return this;
    }
    Query* Query::where_gte( const CString& col, const CString& value )
    {
        add_condition( col, _T(">="), value );

        return this;
    }
    Query* Query::where_lt( const CString& col, const CString& value )
    {
        add_condition( col, _T("<"), value );

        return this;
    }
    Query* Query::where_lte( const CString& col, const CString& value )
    {
        add_condition( col, _T("<="), value );

        return this;
    }

    Query* Query::where_raw( const CString& query )
    {
        add_condition( query );

        return this;
    }

    Query* Query::select( const CString& col )
    {
		CStringArray values;
		cstring_explode(col, _T(", "), values);
		for(int i=0;i<values.GetCount();i++)
		{
			add_result_column(values[i]);
		}
        return this;
    }

    Query* Query::limit( int n_limit )
    {
        set_limit( n_limit );

        return this;
    }

    Query* Query::order_by_expr( const CString& expr )
    {
        add_order_by( expr, _T("") );

        return this;
    }
    Query* Query::order_by_asc( const CString& col )
    {
        add_order_by( col, _T("ASC") );

        return this;
    }
    Query* Query::order_by_desc( const CString& col )
    {
        add_order_by( col, _T("DESC") );

        return this;
    }

    Query* Query::find_min( const CString& col )
    {
        results.clear();
        add_result_column(
            _T("MIN(") + col + _T(")") );

        return this;
    }
    Query* Query::find_max( const CString& col )
    {
        results.clear();
        add_result_column(
            _T("MAX(") + col + _T(")") );

        return this;
    }
    Query* Query::find_avg( const CString& col )
    {
        results.clear();
        add_result_column(
            _T("AVG(") + col + _T(")") );

        return this;
    }
    Query* Query::find_sum( const CString& col )
    {
        results.clear();
        add_result_column(
            _T("SUM(") + col + _T(")") );
        return this;
    }

	void Query::set(const CString &key, const CString &value){
		dirt_field( key );
		fields[key] = value;
	}
	CString& Query::get(const CString &key){
		return fields[key];
	}
	CString& Query::operator[](const CString &key){
		dirt_field( key );
		return fields[key];
	}

}