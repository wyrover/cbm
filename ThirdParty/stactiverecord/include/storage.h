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

#pragma once

namespace stactiverecord
{

    class KVT
    {
    public:
        tstring key, svalue;
        int ivalue;
        coltype type;
        KVT( tstring _key, tstring _value ) : key( _key ), svalue( _value ), type( STRING ) {};
        KVT( tstring _key, int _value ) : key( _key ), ivalue( _value ), type( INTEGER ) {};
        KVT( tstring _key, coltype ct ) : key( _key ), type( ct ) {};
    };

    class Row
    {
    public:
        SarVector<int> ints;
        SarVector<tstring> strings;
        SarVector<DateTime> dts;
        void operator<<( int i )
        {
            ints << i;
        };
        void operator<<( tstring s )
        {
            strings << s;
        };
        bool operator!=( Row& other )
        {
            return !( *this == other );
        };
        bool operator==( Row& other )
        {
            return ints == other.ints && strings == other.strings && dts == other.dts;
        };
        void get_string( int position, tstring& s )
        {
            if( position > ( int )strings.size() - 1 )
                throw Sar_ColumnNotFoundException( SAR_TEXT("String column not found.") );
            s = strings[position];
        };
        int get_int( int position )
        {
            if( position > ( int )ints.size() - 1 )
                throw Sar_ColumnNotFoundException( SAR_TEXT("Int column not found.") );
            return ints[position];
        };
        //void dump()
        //{
        //    std::cout << "Ints:\n";
        //    ints.dump();
        //    std::cout << "Strings:\n";
        //    strings.dump();
        //};
    };


    class Sar_Dbi
    {
    public:
        // config is in form scheme://[user[:password]@]host[:port]/database
        static Sar_Dbi* makeStorage( tstring config, tstring prefix = SAR_TEXT("") );
        static Sar_Dbi* dbi;
        static SarMap<tstring> parseconfig( tstring config );
        tstring table_prefix;
        SarVector<tstring> initialized_tables;
        Sar_Dbi( tstring prefix = SAR_TEXT("") ) : initialized_tables(), table_prefix( prefix ) {};

        virtual void initialize_tables( tstring classname ) = 0;
        int next_id( tstring classname );
        bool exists( tstring classname, int id );
        void make_existing( tstring classname, int id );
        int current_id( tstring classname );
        void delete_record( int id, tstring classname );
        void delete_records( tstring classname );

        // get tstring values
        void get( int id, tstring classname, SarMap<tstring>& values );
        // get int values
        void get( int id, tstring classname, SarMap<int>& values );
        // get datetime values
        void get( int id, tstring classname, SarMap<DateTime>& values );
        // get record relations (of a specific class)
        void get( int id, tstring classname, tstring related_classname, SarVector<int>& related );
        // get all related classes
        void get( int id, tstring classname, SarMap< SarVector<int> >& sm );

        // insert/modify tstring values
        void set( int id, tstring classname, SarMap<tstring> values, bool isinsert );
        // insert/modify int values
        void set( int id, tstring classname, SarMap<int> values, bool isinsert );
        // insert/modify datetime values
        void set( int id, tstring classname, SarMap<DateTime> values, bool isinsert );
        // insert record relations
        void set( int id, tstring classname, SarVector<int> related, tstring related_classname );

        // delete tstring / int / datetime value
        void del( int id, tstring classname, SarVector<tstring> keys, coltype ct );
        // delete record relations
        void del( int id, tstring classname, SarVector<int> related, tstring related_classname );

        // Some searching/static stuff
        // get all objects of a type
        void get( tstring classname, SarVector<int>& results );
        // using a query with a conditional "where"
        void get_where( tstring classname, tstring key, Where* where, SarVector<int>& results );

        // Convert a where object to a string value for a query
        virtual void where_to_string( Where* where, tstring& swhere );

        SarVector<Row> select( tstring table, SarVector<KVT> cols, Q qwhere, bool distinct = false );
        virtual SarVector<Row> select( tstring table, SarVector<KVT> cols, tstring where = SAR_TEXT(""), bool distinct = false ) = 0;
        void update( tstring table, SarVector<KVT> cols, Q qwhere );
        virtual void update( tstring table, SarVector<KVT> cols, tstring where = SAR_TEXT("") ) = 0;
        void remove( tstring table, Q qwhere );
        virtual void remove( tstring table, tstring where = SAR_TEXT("") ) = 0;
        virtual void insert( tstring table, SarVector<KVT> cols ) = 0;
        virtual void execute( tstring query ) = 0;

        bool table_is_initialized( tstring tablename );
    };
};
