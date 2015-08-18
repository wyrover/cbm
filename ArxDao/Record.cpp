#include "stdafx.h"
#include "Record.h"
#include "Row.h"
#include "ForeignKey.h"

namespace orm
{
	Record::Record(const CString& table) 
		: m_isNewlyRecord(true), m_table(table), m_id(0)
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
		//获取外键(无论外键是否有变化,都要进行更新提交到数据库)
		fk->attributes(fields, true);
	}
	CString Record::get(const CString& name) const
	{
		CString v;
		this->get(name, v);
		return v;
	}
	bool Record::get(const CString& name, int& v) const
	{
		if(isPrimaryKey(name))
		{
			v = getID();
			return true;
		}
		else if(isForeignKey(name))
		{
			v = fk->get(name);
			return true;
		}
		else
		{
			return row->get(name, v);
		}
	}
	bool Record::get(const CString& name, double& v) const
	{
		return row->get(name, v);
	}
	bool Record::get(const CString& name, CString& v) const
	{
		if(isPrimaryKey(name))
		{
			v = Utils::int_to_cstring(getID());
			return true;
		}
		else if(isForeignKey(name))
		{
			v = Utils::int_to_cstring(fk->get(name));
			return true;
		}
		else
		{
			return row->get(name, v);
		}
	}
	bool Record::isForeignKey(const CString& name) const
	{
		return fk->has(name);
	}
	bool Record::isPrimaryKey(const CString& name) const
	{
		return (name.CompareNoCase(PKEY(this->getTable())) == 0);
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
		if(isPrimaryKey(name))
		{
			this->m_id = v;
		}
		else if(!isForeignKey(name))
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
		if(isPrimaryKey(name))
		{
			int i = 0;
			if(Utils::cstring_to_int(v, i) && i > 0)
			{
				this->m_id = i;
			}
		}
		else if(!isForeignKey(name))
		{
			row->set(name, v);
		}
	}
	void Record::map_field(const CString& name, int& v)
	{
		//特殊情况:不注册主键id变量(主键由基类Record负责)
		if(isPrimaryKey(name)) return;
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
		return this->m_id;
	}
	CString Record::getStringID() const
	{
		return Utils::int_to_cstring(getID());
	}
	bool Record::setID(int id, bool fetch/*=false*/)
	{
		bool ret = false;
		if(id > 0)
		{
			this->m_id = id;
			ret = true;
			if(fetch)
			{
				ret = fetchById(this->getID());
			}
		}
		return ret;
	}
	bool Record::setID(const CString& id, bool fetch/*=false*/)
	{
		int i = 0;
		Utils::cstring_to_int(id, i);
		return this->setID(i, fetch);
	}
	bool Record::save()
	{
		QueryPtr query(Query::From(this->m_table));
		
		//获取修改过的字段及值
		KVMap fields;
		this->attributes(fields, false);
		for(KVMap::iterator itr=fields.begin(); itr!=fields.end();++itr)
		{
			if(this->isPrimaryKey(itr->first)) continue;
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
				this->setID(id, false);
			}
		}
		else
		{
			query->where(PKEY(this->getTable()), Utils::int_to_cstring(this->getID()));
			ret = get_db()->execute(query->build_update());
		}
		return ret;
	}
	bool Record::remove()
	{
		QueryPtr query(Query::From(this->m_table));
		query->where(PKEY(this->getTable()), Utils::int_to_cstring(this->getID()));
		return get_db()->execute(query->build_delete());
	}
	bool Record::fetchByRow(RowPtr& row)
	{
		KVMap fields;
		row->attributes(fields, true);

		bool ret = false;
		for(KVMap::iterator kv_itr=fields.begin(); kv_itr!=fields.end(); ++kv_itr)
		{
			if(this->isPrimaryKey(kv_itr->first))
			{
				int id = 0;
				kv_itr->second.get(id);
				this->setID(id, false);
			}
			//该字段是外键
			else if(this->isForeignKey(kv_itr->first))
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
	bool Record::fetchById(int id)
	{
		if(id <= 0) return false;

		QueryPtr query(Query::From(this->getTable()));
		query->where(PKEY(this->getTable()), Utils::int_to_cstring(id))->limit(1);

		RowSet rs;
		if(!get_db()->query(query->build_select(), rs) || rs.empty()) {
			return false;
		}
		else {
			return fetchByRow(rs[0]);
		}
	}

	bool Record::clone(RecordPtr ptr)
	{
		if(ptr == 0) return false;

		KVMap fields;
		this->attributes(fields, true);

		RowPtr row(new Row);
		for(KVMap::iterator kv_itr=fields.begin(); kv_itr!=fields.end(); ++kv_itr)
		{
			Attribute& attrib = kv_itr->second;
			switch(attrib.getType())
			{
			case 1:
				{
					int v = 0;
					attrib.get(v);
					row->set(kv_itr->first, v);
				}
				break;
			case 2:
				{
					double v = 0;
					attrib.get(v);
					row->set(kv_itr->first, v);
				}
				break;
			case 3:
				{
					CString v;
					attrib.get(v);
					row->set(kv_itr->first, v);
				}
				break;
			}
		}
		bool ret = ptr->fetchByRow(row);
		if(ret)
		{
			ptr->setNewlyRecord(this->isNewlyRecord());
		}
		return ret;
	}
}