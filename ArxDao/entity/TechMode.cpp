#include "stdafx.h"
#include "TechMode.h"
#include "MineRegion.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

TechMode::TechMode()
{
	tech_mode_id = 0;
	name = "NULL";
	type = 0;
	comment = "NULL";
}

TechMode::TechMode(long id)
{
	tech_mode_id = id;
	name = "NULL";
	type = 0;
	comment = "NULL";
}

TechMode::TechMode(soci::row &rs)
{
	tech_mode_id = rs.get<long>(0);
	long mine_region_id = rs.get<long>(1);
	if(mine_region_id > -1) {
		mine_region = MineRegionPtr(new MineRegion(mine_region_id));
	}
	name = rs.get<std::string>(2);
	type = rs.get<long>(3);
	comment = rs.get<std::string>(4);
}

std::string TechMode::getTableName() const
{
	return "cbm_tech_mode";
}

std::string TechMode::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_tech_mode values("
		<<"NULL"<<","
		<<mine_region->getId()<<","
		<<"'"<<name<<"'"<<","
		<<type<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string TechMode::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_tech_mode set"
		<<" mine_region_id="<<mine_region->getId()<<","
		<<" name="<<"'"<<name<<"'"<<","
		<<" type="<<type<<","
		<<" comment="<<"'"<<comment<<"'"
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

MineRegionPtr TechMode::getMineRegion() const
{
	return mine_region;
}

void TechMode::setMineRegion(const MineRegionPtr& value)
{
	this->mine_region = value;
}

std::string TechMode::getName() const
{
	return name;
}

void TechMode::setName(const std::string& value)
{
	this->name = value;
}

long TechMode::getType() const
{
	return type;
}

void TechMode::setType(const long& value)
{
	this->type = value;
}

std::string TechMode::getComment() const
{
	return comment;
}

void TechMode::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
