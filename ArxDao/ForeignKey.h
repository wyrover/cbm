#pragma once

#include "QueryHelper.h"
#include "Row.h"

#define MAX_FOREIGN_KEY_NUM 10

namespace orm
{
	class ForeignKey
	{
	public:
		ForeignKey();
		~ForeignKey();
		void map_fk(const CString& name, RecordPtr* obj, CreateFunc cf);
		bool set(const CString& name, int id);
		int get(const CString& name) const;
		bool has(const CString& name) const;
		void attributes(KVMap& fields, bool all=false);

	private:
		DISALLOW_COPY_AND_ASSIGN(ForeignKey);
		struct ForeignKeyPrivate* d;
	};

}