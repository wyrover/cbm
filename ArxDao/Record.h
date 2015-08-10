#pragma once

#include "dlimexp.h"
#include "Row.h"
#include "Db.h"
#include "Query.h"

#include <vector>
using namespace std;

#include <boost/shared_ptr.hpp>
using namespace boost;

namespace orm 
{
	namespace helper
	{
		template<typename Klass>
		static shared_ptr<std::vector<shared_ptr<Klass> > > find_many(Query* q)
		{
			typedef shared_ptr<Klass> KlassPtr;
			typedef std::vector<KlassPtr> KlassPtrList;
			typedef shared_ptr<KlassPtrList> KlassPtrListPtr;

			RowSet rs;
			if(get_db()->query(q->build_select(), rs) && !rs.empty())
			{
				KlassPtrListPtr objs(new KlassPtrList);
				for(RowSet::iterator itr=rs.begin();itr!=rs.end();++itr)
				{
					KlassPtr obj(new Klass());
					KVMap fields;
					itr->attributes(fields, true);
					for(KVMap::iterator kv_itr=fields.begin(); kv_itr!=fields.end(); ++kv_itr)
					{
						switch(kv_itr->second.getType())
						{
						case 1:
							{
								int v;
								kv_itr->second.get(v);
								obj->set(kv_itr->first, v);
							}
							break;
						case 2:
							{
								double v;
								kv_itr->second.get(v);
								obj->set(kv_itr->first, v);
							}
							break;
						case 3:
							{
								CString v;
								kv_itr->second.get(v);
								obj->set(kv_itr->first, v);
							}
							break;
						default:
							obj.reset();
							break;
						}
					}
					if(obj != 0)
					{
						objs->push_back(obj);
					}
				}
				if(objs->empty())
				{
					objs.reset();
					return 0;
				}
				else 
				{
					return objs;
				}
			}
			else
			{
				return 0;
			}
		}
	}

	class ARXDAO_DLLIMPEXP Record
	{
	public:
		template<typename Klass>
		static shared_ptr<Klass> find_one(Query* q)
		{
			typedef shared_ptr<Klass> KlassPtr;
			typedef std::vector<KlassPtr> KlassPtrList;
			typedef shared_ptr<KlassPtrList> KlassPtrListPtr;

			q->set_limit(1);
			KlassPtrListPtr objs = helper::find_many(q);
			if(objs == 0 || objs->empty()) 
				return 0;
			else 
				return objs[0];
		}
		template<typename Klass>
		static shared_ptr<Klass> find_many(Query* q)
		{
			typedef shared_ptr<Klass> KlassPtr;
			typedef std::vector<KlassPtr> KlassPtrList;
			typedef shared_ptr<KlassPtrList> KlassPtrListPtr;

			KlassPtrListPtr objs = helper::find_many(q);
			if(objs == 0 || objs->empty()) 
				return 0;
			else 
				return objs;
		}

		bool save();
		bool remove();

		void setTable( const CString& table );
		CString getTable() const;
		void setNewlyRecord(bool isNew);
		bool isNewlyRecord() const;

		void set(const CString& name, int v);
		void set(const CString& name, double v);
		void set(const CString& name, CString v);
		bool get(const CString& name, int& v);
		bool get(const CString& name, double& v);
		bool get(const CString& name, CString& v);
		void attributes(KVMap& fields, bool all=false);

		virtual ~Record();
	protected:
		Record();
		void link(const CString& name, int* v);
		void link(const CString& name, double* v);
		void link(const CString& name, CString* v);
		class Row* row;
		bool m_isNewlyRecord;
		CString m_table;
	};
}

#define REG_ATTRIB(name) this->link(#name, &name)

class Person : public orm::Record
{
public:
	static CString GetTableName() { return _T("person"); }
public:
	Person()
	{
		REG_ATTRIB(id);
		REG_ATTRIB(name);
		REG_ATTRIB(score);
		REG_ATTRIB(age);
	}
	int id;
	CString name;
	double score;
	int age;
};

