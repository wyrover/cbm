#include "stdafx.h"
#include "ResAbundance.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

ResAbundance::ResAbundance()
{
	res_abundance_id = 0;
	type = "NULL";
	min_abundance = 0.0;
	max_abundance = 0.0;
}

ResAbundance::ResAbundance(long id)
{
	res_abundance_id = id;
	type = "NULL";
	min_abundance = 0.0;
	max_abundance = 0.0;
}

ResAbundance::ResAbundance(soci::row &rs)
{
	res_abundance_id = rs.get<long>(0);
	type = rs.get<std::string>(1);
	min_abundance = rs.get<double>(2);
	max_abundance = rs.get<double>(3);
}

std::string ResAbundance::getTableName() const
{
	return "cbm_res_abundance";
}

std::string ResAbundance::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_res_abundance values("
		<<"NULL"<<","
		<<"'"<<type<<"'"<<","
		<<min_abundance<<","
		<<max_abundance<<");";
	return sql.str();
}

std::string ResAbundance::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_res_abundance set"
		<<" type="<<"'"<<type<<"'"<<","
		<<" min_abundance="<<min_abundance<<","
		<<" max_abundance="<<max_abundance
		<<" where res_abundance_id="<<res_abundance_id
		<<" ;";
	return sql.str();
}

std::string ResAbundance::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_res_abundance"
		<<" where res_abundance_id="<<res_abundance_id
		<<" ;";
	return sql.str();
}

long ResAbundance::getId() const
{
	return res_abundance_id;
}

void ResAbundance::setId(const long& value)
{
	this->res_abundance_id = value;
}

std::string ResAbundance::getType() const
{
	return type;
}

void ResAbundance::setType(const std::string& value)
{
	this->type = value;
}

double ResAbundance::getMinAbundance() const
{
	return min_abundance;
}

void ResAbundance::setMinAbundance(const double& value)
{
	this->min_abundance = value;
}

double ResAbundance::getMaxAbundance() const
{
	return max_abundance;
}

void ResAbundance::setMaxAbundance(const double& value)
{
	this->max_abundance = value;
}

} // namespace cbm
