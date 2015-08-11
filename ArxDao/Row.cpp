#include "stdafx.h"
#include "Row.h"

namespace orm
{
	void Attribute::update()
	{
		switch(att_type)
		{
		case 1:
			ivalue.update();
			break;
		case 2:
			fvalue.update();
			break;
		case 3:
			svalue.update();
			break;
		}
	}
	CString Attribute::toString() const
	{
		CString value = _T("");
		switch(att_type)
		{
		case 1:
			value = Utils::int_to_cstring(ivalue.new_value());
			break;
		case 2:
			value = Utils::double_to_cstring(fvalue.new_value());
			break;
		case 3:
			value = svalue.new_value();
			break;
		}
		return value;
	}
	bool Attribute::hasChanged() const
	{
		bool ret = false;
		switch(att_type)
		{
		case 1:
			ret = ivalue.hasChanged();
			break;
		case 2:
			ret = fvalue.hasChanged();
			break;
		case 3:
			ret = svalue.hasChanged();
			break;
		}
		return ret;
	}
	int Attribute::getType() const
	{
		return this->att_type; 
	}
	void Attribute::setType(int type)
	{
		if(type > 0 && type < 4 && this->att_type == 0)
		{
			this->att_type = type;
		}
	}
	void Attribute::set(const int& v)
	{
		if(getType() == 2)
		{
			fvalue = v*1.0;
		}
		else
		{
			ivalue = v;
			setType(1);
		}
		
	}
	void Attribute::set(const double& v)
	{
		fvalue = v;
		setType(2);
	}
	void Attribute::set(const CString& v)
	{
		if(getType() == 1)
		{
			int i;
			if(Utils::cstring_to_int(v, i))
			{
				ivalue = i;
			}
		}
		else if(getType() == 2)
		{
			double f;
			if(Utils::cstring_to_double(v, f))
			{
				fvalue = f;
			}
		}
		else
		{
			svalue = v;
			setType(3);
		}
	}
	bool Attribute::get(int& v) const
	{
		if(att_type != 1) return false;
		v = ivalue.new_value();
		return true;
	}
	bool Attribute::get(double& v) const
	{
		if(att_type != 2) return false;
		v = fvalue.new_value();
		return true;
	}
	bool Attribute::get(CString& v) const
	{
		bool ret = true;
		if(att_type == 1)
		{
			v = Utils::int_to_cstring(ivalue.new_value());
		}
		else if(att_type == 2)
		{
			v = Utils::double_to_cstring(fvalue.new_value());
		}
		else if(att_type == 3)
		{
			v = svalue.new_value();
		}
		else
		{
			ret = false;
		}
		return ret;
	}

	struct RowPrivate
	{
		KVMap m_attribs;
	};
	Row::Row()
	{
		d = new RowPrivate;
	}
	Row::~Row()
	{
		delete d; d = 0;
	}
	void Row::set(const CString& name, int v)
	{
		//if(d->m_attribs.find(name) != d->m_attribs.end())
		{
			d->m_attribs[name] = v;
		}
	}
	void Row::set(const CString& name, double v)
	{
		//if(d->m_attribs.find(name) != d->m_attribs.end())
		{
			d->m_attribs[name] = v;
		}
	}
	void Row::set(const CString& name, CString v)
	{
		//if(d->m_attribs.find(name) != d->m_attribs.end())
		{
			d->m_attribs[name].set(v);
		}
	}
	bool Row::get(const CString& name, int& v) const
	{
		if(d->m_attribs.find(name) != d->m_attribs.end())
		{
			return d->m_attribs[name].get(v);
		}
		else
		{
			return false;
		}
	}
	bool Row::get(const CString& name, double& v) const
	{
		if(d->m_attribs.find(name) != d->m_attribs.end())
		{
			return d->m_attribs[name].get(v);
		}
		else
		{
			return false;
		}
	}
	bool Row::get(const CString& name, CString& v) const
	{
		if(d->m_attribs.find(name) != d->m_attribs.end())
		{
			return d->m_attribs[name].get(v);
		}
		else
		{
			return false;
		}
	}
	Attribute& Row::operator[](const CString& name)
	{
		return d->m_attribs[name];
	}

	void Row::attributes(KVMap& fields, bool all/*=false*/)
	{
		for(KVMap::iterator itr=d->m_attribs.begin();itr!=d->m_attribs.end();++itr)
		{
			if(all || itr->second.hasChanged())
			{
				fields[itr->first] = itr->second;
				itr->second.update();
			}
		}
	}

}