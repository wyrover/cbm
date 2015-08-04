#include "stdafx.h"
#include "MineBase.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

MineBase::MineBase()
{
	mine_base_id = 0;
	name = "NULL";
	comment = "NULL";
}

MineBase::MineBase(long id)
{
	mine_base_id = id;
	name = "NULL";
	comment = "NULL";
}

MineBase::MineBase(soci::row &rs)
{
	mine_base_id = rs.get<long>(0);
	name = rs.get<std::string>(1);
	comment = rs.get<std::string>(2);
}

std::string MineBase::getTableName() const
{
	return "cbm_mine_base";
}

std::string MineBase::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_mine_base values("
		<<"NULL"<<","
		<<"'"<<name<<"'"<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string MineBase::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_mine_base set"
		<<" name="<<"'"<<name<<"'"<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where mine_base_id="<<mine_base_id
		<<" ;";
	return sql.str();
}

std::string MineBase::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_mine_base"
		<<" where mine_base_id="<<mine_base_id
		<<" ;";
	return sql.str();
}

long MineBase::getId() const
{
	return mine_base_id;
}

void MineBase::setId(const long& value)
{
	this->mine_base_id = value;
}

std::string MineBase::getName() const
{
	return name;
}

void MineBase::setName(const std::string& value)
{
	this->name = value;
}

std::string MineBase::getComment() const
{
	return comment;
}

void MineBase::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
