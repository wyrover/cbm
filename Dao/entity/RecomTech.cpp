#include "RecomTech.h"
#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

RecomTech::RecomTech()
{
	recom_tech_id = 0;
	name = "";
	is_key = 0;
	doc = "";
	video = "";
}

RecomTech::RecomTech(long id)
{
	recom_tech_id = id;
	name = "";
	is_key = 0;
	doc = "";
	video = "";
}

RecomTech::RecomTech(soci::row &rs)
{
	recom_tech_id = rs.get<long>(0);
	long mine_id = rs.get<long>(1);
	if(mine_id > -1) {
		mine = MinePtr(new Mine(mine_id));
	}
	name = rs.get<std::string>(2);
	is_key = rs.get<long>(3);
	doc = rs.get<std::string>(4);
	video = rs.get<std::string>(5);
}

std::string RecomTech::getTableName() const
{
	return "cbm_recom_tech";
}

std::string RecomTech::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_recom_tech values("
		<<"NULL"<<","
		<<mine->getId()<<","
		<<"'"<<name<<"'"<<","
		<<is_key<<","
		<<"'"<<doc<<"'"<<","
		<<"'"<<video<<"'"<<");";
	return sql.str();
}

std::string RecomTech::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_recom_tech set"
		<<" mine_id="<<mine->getId()<<","
		<<" name="<<"'"<<name<<"'"<<","
		<<" is_key="<<is_key<<","
		<<" doc="<<"'"<<doc<<"'"<<","
		<<" video="<<"'"<<video<<"'"
		<<" where recom_tech_id="<<recom_tech_id
		<<" ;";
	return sql.str();
}

std::string RecomTech::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_recom_tech"
		<<" where recom_tech_id="<<recom_tech_id
		<<" ;";
	return sql.str();
}

long RecomTech::getId() const
{
	return recom_tech_id;
}

void RecomTech::setId(const long& value)
{
	this->recom_tech_id = value;
}

MinePtr RecomTech::getMine() const
{
	return mine;
}

void RecomTech::setMine(const MinePtr& value)
{
	this->mine = value;
}

std::string RecomTech::getName() const
{
	return name;
}

void RecomTech::setName(const std::string& value)
{
	this->name = value;
}

long RecomTech::getIsKey() const
{
	return is_key;
}

void RecomTech::setIsKey(const long& value)
{
	this->is_key = value;
}

std::string RecomTech::getDoc() const
{
	return doc;
}

void RecomTech::setDoc(const std::string& value)
{
	this->doc = value;
}

std::string RecomTech::getVideo() const
{
	return video;
}

void RecomTech::setVideo(const std::string& value)
{
	this->video = value;
}

} // namespace cbm
