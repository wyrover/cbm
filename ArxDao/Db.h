#ifndef DAO_H
#define DAO_H

#include "dlimexp.h"
#include "Row.h"

#include <boost/shared_ptr.hpp>
using namespace boost;

namespace orm 
{
	class Db;
	typedef shared_ptr<Db> DbPrt;

	class ARXDAO_DLLIMPEXP Db
	{
	public:
		static DbPrt Instance();

	public:	
		virtual ~Db() {}
		virtual bool config(const CString& host, const CString& user, const CString& password, const CString& database) = 0;
		virtual bool execute(const CString& sql) = 0;
		virtual bool query(const CString& sql, RowSet& rs) = 0;

	protected:
		static DbPrt instance;
		Db() {}
	};

	//È«¾Öº¯Êý
	extern ARXDAO_DLLIMPEXP DbPrt get_db();
}

#endif // DAO_H
