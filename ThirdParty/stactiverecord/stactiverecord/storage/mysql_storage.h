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

#include "../stactive_record.h"

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <mysql/mysql.h>

namespace stactiverecord
{
	class MySQLStorage : public Sar_Dbi
	{
	private:
		void close();
		MYSQL* db;
		bool is_closed;
		void test_result( int result, const tstring& context );
	public:
		MySQLStorage( tstring config, tstring prefix );
		~MySQLStorage()
		{
			close();
		};
		void execute( tstring query );
		void initialize_tables( tstring classname );
		SarVector<Row> select( tstring table, SarVector<KVT> cols, tstring where = SAR_TEXT(""), bool distinct = false );
		void update( tstring table, SarVector<KVT> cols, tstring where = SAR_TEXT("") );
		void remove( tstring table, tstring where = SAR_TEXT("") );
		void insert( tstring table, SarVector<KVT> cols );
	};

};
