#include "TechMode.h"
#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

TechMode::TechMode()
{
}

TechMode::TechMode(long id)
{
	this->tech_mode_id = id;
}

TechMode::TechMode(soci::row &rs)
{
	tech_mode_id = rs.get<long>(0);
	long mine_id = rs.get<long>(1);
	if(mine_id > -1) {
		mine = MinePtr(new Mine(mine_id));
	}
	mode_name = rs.get<std::string>(2);
	mode_type = rs.get<long>(3);
}

std::string TechMode::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_tech_mode values("
		<<"NULL"<<","
		<<mine->getId()<<","
		<<"'"<<mode_name<<"'"<<","
		<<mode_type<<");";
	return sql.str();
}

std::string TechMode::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_tech_mode set"
		<<" mine_id="<<mine->getId()<<","
		<<" mode_name="<<"'"<<mode_name<<"'"<<","
		<<" mode_type="<<mode_type
		<<" where tech_mode_id="<<tech_mode_id
		<<" ;";
	return sql.str();
}

std::string TechMode::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_tech_mode"
		<<" where tech_mode_id="<<tech_mode_id
		<<" ;";
	return sql.str();
}

long TechMode::getId() const
{
	return tech_mode_id;
}

void TechMode::setId(const long& value)
{
	this->tech_mode_id = value;
}

MinePtr TechMode::getMine() const
{
	return mine;
}

void TechMode::setMine(const MinePtr& value)
{
	this->mine = value;
}

std::string TechMode::getModeName() const
{
	return mode_name;
}

void TechMode::setModeName(const std::string& value)
{
	this->mode_name = value;
}

long TechMode::getModeType() const
{
	return mode_type;
}

void TechMode::setModeType(const long& value)
{
	this->mode_type = value;
}

} // namespace cbm
