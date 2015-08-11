#include "stdafx.h"
#include "Record.h"
#include "Row.h"
#include "ForeignKey.h"

namespace orm
{
	Record::Record(const CString& table) : m_isNewlyRecord(true), m_table(table)
	{
		row = new Row();
		fk = new ForeignKey;
	}
	Record::~Record() 
	{ 
		delete row; row = 0;
		delete fk; fk = 0;
	}
	void Record::attributes(KVMap& fields, bool all/*=false*/)
	{
		//获取字段属性
		row->attributes(fields, all);
		//获取外键
		fk->attributes(fields, all);
	}
	bool Record::get(const CString& name, int& v) const
	{
		return row->get(name, v);
	}
	bool Record::get(const CString& name, double& v) const
	{
		return row->get(name, v);
	}
	bool Record::get(const CString& name, CString& v) const
	{
		return row->get(name, v);
	}
	bool Record::isForeignKey(const CString& name) const
	{
		return fk->has(name);
	}
	bool Record::setForeignKey(const CString& name, const CString& str)
	{
		int id = 0;
		return Utils::cstring_to_int(str, id) ? fk->set(name, id) : false;
	}
	bool Record::setAttrib(const CString& name, const Attribute& attrib)
	{
		if(isForeignKey(name)) return false;

		bool ret = true;
		switch(attrib.getType())
		{
		case 1:
			{
				int v;
				attrib.get(v);
				this->set(name, v);
			}
			break;
		case 2:
			{
				double v;
				attrib.get(v);
				this->set(name, v);
			}
			break;
		case 3:
			{
				CString v;
				attrib.get(v);
				this->set(name, v);
			}
			break;
		default:
			ret = false;
			break;
		}
		return ret;
	}
	void Record::set(const CString& name, int v)
	{
		if(!isForeignKey(name))
		{
			row->set(name, v);
		}
	}
	void Record::set(const CString& name, double v)
	{
		if(!isForeignKey(name))
		{
			row->set(name, v);
		}
	}
	void Record::set(const CString& name, CString v)
	{
		if(!isForeignKey(name))
		{
			row->set(name, v);
		}
	}
	void Record::map_field(const CString& name, int& v)
	{
		(*row)[name] = Attribute(&v);
	}
	void Record::map_field(const CString& name, double& v)
	{
		(*row)[name] = Attribute(&v);
	}
	void Record::map_field(const CString& name, CString& v)
	{
		(*row)[name] = Attribute(&v);
	}
	void Record::map_foreign_key(const CString& name, RecordPtr& ptr, CreateFunc cf)
	{
		fk->map_fk(name, &ptr, cf);
	}
	void Record::setNewlyRecord(bool isNewly) 
	{ 
		this->m_isNewlyRecord = isNewly; 
	}
	bool Record::isNewlyRecord() const 
	{ 
		return this->m_isNewlyRecord; 
	}
	CString Record::getTable() const
	{
		return this->m_table;
	}
	int Record::getID() const
	{
		int id = 0;
		this->get(PRIMARY_KEY_ID, id);
		return id;
	}
	bool Record::save()
	{
		Query* query = Query::from(this->m_table);
		
		//获取修改过的字段及值
		KVMap fields;
		this->attributes(fields, false);
		for(KVMap::iterator itr=fields.begin(); itr!=fields.end();++itr)
		{
			if(itr->first.CompareNoCase(PRIMARY_KEY_ID) == 0) continue;
			query->set(itr->first, itr->second.toString());
		}
		bool ret = false;
		if(isNewlyRecord())
		{
			ret = get_db()->execute(query->build_insert());
			setNewlyRecord(!ret);
			if(ret)
			{
				int id = get_db()->lastInsertId(this->getTable());
				this->set(PRIMARY_KEY_ID, id);
			}
		}
		else
		{
			ret = get_db()->execute(query->build_update());
		}

		delete query;
		return ret;
	}
	bool Record::remove()
	{
		Query* query = Query::from(this->m_table);
		CString idStr;
		this->get(PRIMARY_KEY_ID, idStr);
		query->where(PRIMARY_KEY_ID, idStr);
		return get_db()->execute(query->build_delete());
	}
	bool Record::fetchByRow(RowPtr& row)
	{
		KVMap fields;
		row->attributes(fields, true);

		bool ret = false;
		for(KVMap::iterator kv_itr=fields.begin(); kv_itr!=fields.end(); ++kv_itr)
		{
			//该字段是外键
			if(this->isForeignKey(kv_itr->first))
			{
				CString idStr;
				if(kv_itr->second.get(idStr))
				{
					ret = this->setForeignKey(kv_itr->first, idStr);
				}
			}
			else 
			{
				ret = this->setAttrib(kv_itr->first, kv_itr->second);
			}
			if(!ret) break;
		}
		this->setNewlyRecord(!ret);
		return ret;
	}
	bool Record::fetch()
	{
		if(getID() == 0) return false;

		QueryPtr query(Query::from(this->getTable()));
		query->where(PRIMARY_KEY_ID, Utils::int_to_cstring(getID()))->limit(1);

		RowSet rs;
		if(!get_db()->query(query->build_select(), rs) || rs.empty()) {
			return false;
		}
		else {
			return fetchByRow(rs[0]);
		}
	}

}