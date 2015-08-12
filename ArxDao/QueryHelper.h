#pragma once

#include "Types.h"

namespace orm
{
	namespace helper
	{
		namespace internal
		{
			template<typename Klass>
			RecordPtrListPtr find_many(Query* q)
			{
				RowSet rs;
				if(!get_db()->query(q->build_select(), rs) || rs.empty()) return RecordPtrListPtr();

				RecordPtrListPtr objs(new RecordPtrList());
				for(RowSet::iterator itr=rs.begin();itr!=rs.end();++itr)
				{
					RecordPtr obj(Klass::Create());
					if(obj->fetchByRow(*itr))
					{
						objs->push_back(obj);
					}
				}
				return objs->empty() ? RecordPtrListPtr() : objs;
			}
		}

		template<typename Klass>
		RecordPtr find_one(Query* q)
		{
			q->limit(1);
			RecordPtrListPtr objs = orm::helper::internal::find_many<Klass>(q);
			return (objs == 0 || objs->empty()) ? RecordPtr() : (*objs)[0];
		}
		template<typename Klass>
		RecordPtrListPtr find_many(Query* q)
		{
			RecordPtrListPtr objs = orm::helper::internal::find_many<Klass>(q);
			return (objs == 0 || objs->empty()) ? RecordPtrListPtr() : objs;
		}
		template<typename Klass>
		RecordPtr find(int id)
		{
			QueryPtr query(Query::from<Klass>());
			query->where(PKEY(Klass::Table()), Utils::int_to_cstring(id))->limit(1);
			return orm::helper::find_one<Klass>(query.get());
		}
	}

}