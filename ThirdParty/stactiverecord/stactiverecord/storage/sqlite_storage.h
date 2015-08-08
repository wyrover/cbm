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

#include "../stactive_record.h"

#include <sqlite3.h>

namespace stactiverecord
{
	class SQLiteStorage : public Sar_Dbi
	{
	private:
		void close();
		sqlite3* db;
		bool is_closed;
		void test_result( int result, const std::string& context );
	public:
		SQLiteStorage( std::string location, std::string prefix = "" );
		~SQLiteStorage()
		{
			close();
		};
		void execute( std::string query );
		void initialize_tables( std::string classname );
		SarVector<Row> select( std::string table, SarVector<KVT> cols, std::string where = "", bool distinct = false );
		void update( std::string table, SarVector<KVT> cols, std::string where = "" );
		void remove( std::string table, std::string where = "" );
		void insert( std::string table, SarVector<KVT> cols );
	};
};
