#include "stdafx.h"
#include "Record.h"

namespace orm
{
	Record::Record() : m_isNewlyRecord(true)
	{
		row = new Row; 
	}
	Record::~Record() 
	{ 
		delete row; 
	}
	void Record::attributes(KVMap& fields, bool all/*=false*/)
	{
		row->attributes(fields, all);
	}
	bool Record::get(const CString& name, int& v)
	{
		return row->get(name, v);
	}
	bool Record::get(const CString& name, double& v)
	{
		return row->get(name, v);
	}
	bool Record::get(const CString& name, CString& v)
	{
		return row->get(name, v);
	}
	void Record::set(const CString& name, int v)
	{
		row->set(name, v);
	}
	void Record::set(const CString& name, double v)
	{
		row->set(name, v);
	}
	void Record::set(const CString& name, CString v)
	{
		row->set(name, v);
	}
	void Record::link(const CString& name, int* v)
	{
		(*row)[name] = Attribute(v);
	}
	void Record::link(const CString& name, double* v)
	{
		(*row)[name] = Attribute(v);
	}
	void Record::link(const CString& name, CString* v)
	{
		(*row)[name] = Attribute(v);
	}

	void Record::setNewlyRecord(bool isNew) 
	{ 
		this->m_isNewlyRecord = isNew; 
	}
	bool Record::isNewlyRecord() const 
	{ 
		return this->m_isNewlyRecord; 
	}
	void Record::setTable( const CString& table )
	{
		this->m_table = table;
	}
	CString Record::getTable() const
	{
		return this->m_table;
	}
	bool Record::save()
	{
		Query* query = Query::from(this->m_table);
		
		KVMap fields;
		this->attributes(fields);
		for(KVMap::iterator itr=fields.begin(); itr!=fields.end();++itr)
		{
			if(itr->first == "id") continue;
			query->set(itr->first, itr->second.toString());
		}
		bool ret = false;
		if(isNewlyRecord())
		{
			ret = get_db()->execute(query->build_insert());
			setNewlyRecord(!ret);
		}
		else
		{
			ret = get_db()->execute(query->build_update());
		}

		query->clean_dirty_fields();
		delete query;
		return ret;
	}
	bool Record::remove()
	{
		Query* query = Query::from(this->m_table);
		CString idStr;
		this->get(_T("id"), idStr);
		query->where(_T("id"), idStr);
		return get_db()->execute(query->build_delete());
	}
}