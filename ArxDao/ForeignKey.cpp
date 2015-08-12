#include "StdAfx.h"
#include "ForeignKey.h"
#include "Record.h"

namespace orm
{
	struct FKPair
	{
	public:
		FKPair() : id_attr(), obj_ptr(0) {}
		Attribute id_attr;
		RecordPtr* obj_ptr;
		CreateFunc cf;

		bool hasChanged() const
		{
			//关联外键变量没有成功,所以obj_ptr=0;
			if(id_attr.getType() == 0 || obj_ptr == 0) return false;

			//外键设置有错误
			int fk_id = 0;
			id_attr.get(fk_id);
			if(fk_id == 0) {
				return false;
			}
			//派生类对象通过修改了成员变量指针,指向为空
			else if(*obj_ptr == 0) {
				return true;
			}
			else {
				RecordPtr& ptr = *obj_ptr;
				return (ptr->getID() != fk_id);
			}
		}
		void update()
		{
			if(obj_ptr != 0 && *obj_ptr!=0)
			{
				RecordPtr& ptr = *obj_ptr;
				id_attr.set(ptr->getID());
			}
		}
	};
	typedef std::map<CString, FKPair> FKMap;

	struct ForeignKeyPrivate
	{
	public:
		ForeignKeyPrivate() : m_max_id(0) {}
		void makeFKPair(const CString& name, RecordPtr* obj_ptr, CreateFunc cf)
		{
			if(m_foregin_keys.find(name) == m_foregin_keys.end())
			{
				if(m_max_id < MAX_FOREIGN_KEY_NUM)
				{
					FKPair fk;
					fk.id_attr = Attribute(&(m_foregin_key_ids[m_max_id]));
					fk.id_attr.set((int)0); // type为int类型
					fk.cf = cf;
					fk.obj_ptr = obj_ptr;
					m_foregin_keys[name] = fk;
					m_max_id++;
				}
			}
		}
		void createOrUpdateFKObject(FKPair& fk, int id)
		{
			RecordPtr& ptr = *(fk.obj_ptr);
			int fk_id = 0;
			fk.id_attr.get(fk_id);
			if(fk_id <= 0)
			{
				ptr = fk.cf();
			}
			fk.id_attr.set(id);
			ptr->setID(id, true);
		}
		bool set(const CString& name, int id)
		{
			bool ret = (id > 0 && m_foregin_keys.find(name) != m_foregin_keys.end());
			if(ret) 
			{
				createOrUpdateFKObject(m_foregin_keys[name], id);
			}
			return ret;
		}
		int get(const CString& name)
		{
			FKMap::iterator itr = m_foregin_keys.find(name);
			if(itr == m_foregin_keys.end()) return 0;

			FKPair& fk = itr->second;
			if(fk.obj_ptr == 0) return 0;

			RecordPtr ptr = *(fk.obj_ptr);
			return (ptr == 0) ? 0 : ptr->getID();
		}
		bool has_fk(const CString& name) const
		{
			return m_foregin_keys.find(name) != m_foregin_keys.end();
		}
		void attributes(KVMap& fields, bool all)
		{
			for(FKMap::iterator itr=m_foregin_keys.begin();itr!=m_foregin_keys.end();++itr)
			{
				FKPair& fk = itr->second;
				if(all || fk.hasChanged())
				{
					fields[itr->first] = fk.id_attr;
					fk.update();
				}
			}
		}

	private:
		FKMap m_foregin_keys;
		int m_max_id;
		int m_foregin_key_ids[MAX_FOREIGN_KEY_NUM]; // 一般情况一个表的外键10个就已经够用了
	};

	ForeignKey::ForeignKey()
	{
		d = new ForeignKeyPrivate();
	}
	ForeignKey::~ForeignKey()
	{
		delete d; d = 0;
	}
	void ForeignKey::map_fk(const CString& name, RecordPtr* obj, CreateFunc cf)
	{
		d->makeFKPair(name, obj, cf);
	}
	bool ForeignKey::set(const CString& name, int id)
	{
		return d->set(name, id);
	}
	int ForeignKey::get(const CString& name) const
	{
		return d->get(name);
	}
	bool ForeignKey::has(const CString& name) const
	{
		return d->has_fk(name);
	}
	void ForeignKey::attributes(KVMap& fields, bool all/*=false*/)
	{
		d->attributes(fields, all);
	}
}