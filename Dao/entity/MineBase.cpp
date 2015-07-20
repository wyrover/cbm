#include "MineBase.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

MineBase::MineBase()
{
	mine_base_id = 0;
	base_name = "";
	base_mine = "";
}

MineBase::MineBase(long id)
{
	mine_base_id = id;
	base_name = "";
	base_mine = "";
}

MineBase::MineBase(soci::row &rs)
{
	mine_base_id = rs.get<long>(0);
	base_name = rs.get<std::string>(1);
	base_mine = rs.get<std::string>(2);
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
		<<"'"<<base_name<<"'"<<","
		<<"'"<<base_mine<<"'"<<");";
	return sql.str();
}

std::string MineBase::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_mine_base set"
		<<" base_name="<<"'"<<base_name<<"'"<<","
		<<" base_mine="<<"'"<<base_mine<<"'"
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

std::string MineBase::getBaseName() const
{
	return base_name;
}

void MineBase::setBaseName(const std::string& value)
{
	this->base_name = value;
}

std::string MineBase::getBaseMine() const
{
	return base_mine;
}

void MineBase::setBaseMine(const std::string& value)
{
	this->base_mine = value;
}

} // namespace cbm
