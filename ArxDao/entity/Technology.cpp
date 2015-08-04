#include "stdafx.h"
#include "Technology.h"
#include "MineRegion.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Technology::Technology()
{
	technology_id = 0;
	name = "NULL";
	iskey = 0;
	doc = "NULL";
	video = "NULL";
	comment = "NULL";
}

Technology::Technology(long id)
{
	technology_id = id;
	name = "NULL";
	iskey = 0;
	doc = "NULL";
	video = "NULL";
	comment = "NULL";
}

Technology::Technology(soci::row &rs)
{
	technology_id = rs.get<long>(0);
	long mine_region_id = rs.get<long>(1);
	if(mine_region_id > -1) {
		mine_region = MineRegionPtr(new MineRegion(mine_region_id));
	}
	name = rs.get<std::string>(2);
	iskey = rs.get<long>(3);
	doc = rs.get<std::string>(4);
	video = rs.get<std::string>(5);
	comment = rs.get<std::string>(6);
}

std::string Technology::getTableName() const
{
	return "cbm_technology";
}

std::string Technology::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_technology values("
		<<"NULL"<<","
		<<mine_region->getId()<<","
		<<"'"<<name<<"'"<<","
		<<iskey<<","
		<<"'"<<doc<<"'"<<","
		<<"'"<<video<<"'"<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string Technology::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_technology set"
		<<" mine_region_id="<<mine_region->getId()<<","
		<<" name="<<"'"<<name<<"'"<<","
		<<" iskey="<<iskey<<","
		<<" doc="<<"'"<<doc<<"'"<<","
		<<" video="<<"'"<<video<<"'"<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where technology_id="<<technology_id
		<<" ;";
	return sql.str();
}

std::string Technology::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_technology"
		<<" where technology_id="<<technology_id
		<<" ;";
	return sql.str();
}

long Technology::getId() const
{
	return technology_id;
}

void Technology::setId(const long& value)
{
	this->technology_id = value;
}

MineRegionPtr Technology::getMineRegion() const
{
	return mine_region;
}

void Technology::setMineRegion(const MineRegionPtr& value)
{
	this->mine_region = value;
}

std::string Technology::getName() const
{
	return name;
}

void Technology::setName(const std::string& value)
{
	this->name = value;
}

long Technology::getIskey() const
{
	return iskey;
}

void Technology::setIskey(const long& value)
{
	this->iskey = value;
}

std::string Technology::getDoc() const
{
	return doc;
}

void Technology::setDoc(const std::string& value)
{
	this->doc = value;
}

std::string Technology::getVideo() const
{
	return video;
}

void Technology::setVideo(const std::string& value)
{
	this->video = value;
}

std::string Technology::getComment() const
{
	return comment;
}

void Technology::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
