#pragma once

#include "Db.h"
#include <soci.h>

namespace orm
{
	class soci_Db : public Db
	{
	public:
		virtual bool config(const CString& user, const CString& password, const CString& database, const CString& host=_T("localhost"), const CString& port=_T("3306"));
		virtual bool execute(const CString& sql);
		virtual bool query(const CString& sql, RowSet& rs);

	protected:
		soci::session* getConnection();
		soci::session sql;
	};

}