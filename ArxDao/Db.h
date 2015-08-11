#pragma once

#include "Row.h"

namespace orm 
{
	class ARXDAO_DLLIMPEXP Db
	{
	public:
		static DbPrt Instance();

	public:	
		virtual ~Db() {}
		virtual bool config(const CString& user, const CString& password, const CString& database, const CString& host=_T("localhost"), const CString& port=_T("3306") ) = 0;
		virtual bool execute(const CString& sql) = 0;
		virtual bool query(const CString& sql, RowSet& rs) = 0;
		virtual int lastInsertId(const CString& table) = 0;

	protected:
		static DbPrt instance;
		Db() {}
	private:
		DISALLOW_COPY_AND_ASSIGN(Db);
	};

	//È«¾Öº¯Êý
	extern ARXDAO_DLLIMPEXP DbPrt get_db();
}
