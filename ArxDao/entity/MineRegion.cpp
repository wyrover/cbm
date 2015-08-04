#include "stdafx.h"
#include "MineRegion.h"
#include "MineBase.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

MineRegion::MineRegion()
{
	mine_region_id = 0;
	name = "NULL";
	comment = "NULL";
}

MineRegion::MineRegion(long id)
{
	mine_region_id = id;
	name = "NULL";
	comment = "NULL";
}

MineRegion::MineRegion(soci::row &rs)
{
	mine_region_id = rs.get<long>(0);
	long mine_base_id = rs.get<long>(1);
	if(mine_base_id > -1) {
		mine_base = MineBasePtr(new MineBase(mine_base_id));
	}
	name = rs.get<std::string>(2);
	comment = rs.get<std::string>(3);
}

std::string MineRegion::getTableName() const
{
	return "cmb_mine_region";
}

std::string MineRegion::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cmb_mine_region values("
		<<"NULL"<<","
		<<mine_base->getId()<<","
		<<"'"<<name<<"'"<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string MineRegion::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cmb_mine_region set"
		<<" mine_base_id="<<mine_base->getId()<<","
		<<" name="<<"'"<<name<<"'"<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where mine_region_id="<<mine_region_id
		<<" ;";
	return sql.str();
}

std::string MineRegion::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cmb_mine_region"
		<<" where mine_region_id="<<mine_region_id
		<<" ;";
	return sql.str();
}

long MineRegion::getId() const
{
	return mine_region_id;
}

void MineRegion::setId(const long& value)
{
	this->mine_region_id = value;
}

MineBasePtr MineRegion::getMineBase() const
{
	return mine_base;
}

void MineRegion::setMineBase(const MineBasePtr& value)
{
	this->mine_base = value;
}

std::string MineRegion::getName() const
{
	return name;
}

void MineRegion::setName(const std::string& value)
{
	this->name = value;
}

std::string MineRegion::getComment() const
{
	return comment;
}

void MineRegion::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
