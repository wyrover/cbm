#include "stdafx.h"
#include "Dummy.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Dummy::Dummy()
{
	id = 0;
}

Dummy::Dummy(long id)
{
	id = 0;
}

Dummy::Dummy(soci::row &rs)
{
	id = rs.get<long>(0);
}

std::string Dummy::getTableName() const
{
	return "cbm_dummy";
}

std::string Dummy::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_dummy values("
		<<id<<");";
	return sql.str();
}

std::string Dummy::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_dummy set"
		<<" id="<<id
		<<" where dummy_id="<<dummy_id
		<<" ;";
	return sql.str();
}

std::string Dummy::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_dummy"
		<<" where dummy_id="<<dummy_id
		<<" ;";
	return sql.str();
}

long Dummy::getId() const
{
	return id;
}

void Dummy::setId(const long& value)
{
	this->id = value;
}

} // namespace cbm
