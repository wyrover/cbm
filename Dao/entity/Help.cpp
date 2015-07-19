#include "Help.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Help::Help()
{
}

Help::Help(long id)
{
	this->help_id = id;
}

Help::Help(soci::row &rs)
{
	help_id = rs.get<long>(0);
	help_field = rs.get<std::string>(1);
	help_type = rs.get<long>(2);
	help_value = rs.get<std::string>(3);
}

std::string Help::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_help values("
		<<"NULL"<<","
		<<"'"<<help_field<<"'"<<","
		<<help_type<<","
		<<"'"<<help_value<<"'"<<");";
	return sql.str();
}

std::string Help::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_help set"
		<<" help_field="<<"'"<<help_field<<"'"<<","
		<<" help_type="<<help_type<<","
		<<" help_value="<<"'"<<help_value<<"'"
		<<" where help_id="<<help_id
		<<" ;";
	return sql.str();
}

std::string Help::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_help"
		<<" where help_id="<<help_id
		<<" ;";
	return sql.str();
}

long Help::getId() const
{
	return help_id;
}

void Help::setId(const long& value)
{
	this->help_id = value;
}

std::string Help::getHelpField() const
{
	return help_field;
}

void Help::setHelpField(const std::string& value)
{
	this->help_field = value;
}

long Help::getHelpType() const
{
	return help_type;
}

void Help::setHelpType(const long& value)
{
	this->help_type = value;
}

std::string Help::getHelpValue() const
{
	return help_value;
}

void Help::setHelpValue(const std::string& value)
{
	this->help_value = value;
}

} // namespace cbm
