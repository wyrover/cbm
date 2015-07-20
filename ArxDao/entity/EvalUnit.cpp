#include "stdafx.h"
#include "EvalUnit.h"
#include "WorkSurf.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

EvalUnit::EvalUnit()
{
	eval_unit_id = 0;
	unit_l = 0.0;
	unit_t = 0.0;
}

EvalUnit::EvalUnit(long id)
{
	eval_unit_id = id;
	unit_l = 0.0;
	unit_t = 0.0;
}

EvalUnit::EvalUnit(soci::row &rs)
{
	eval_unit_id = rs.get<long>(0);
	long work_surf_id = rs.get<long>(1);
	if(work_surf_id > -1) {
		work_surf = WorkSurfPtr(new WorkSurf(work_surf_id));
	}
	unit_l = rs.get<double>(2);
	unit_t = rs.get<double>(3);
}

std::string EvalUnit::getTableName() const
{
	return "cbm_eval_unit";
}

std::string EvalUnit::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_eval_unit values("
		<<"NULL"<<","
		<<work_surf->getId()<<","
		<<unit_l<<","
		<<unit_t<<");";
	return sql.str();
}

std::string EvalUnit::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_eval_unit set"
		<<" work_surf_id="<<work_surf->getId()<<","
		<<" unit_l="<<unit_l<<","
		<<" unit_t="<<unit_t
		<<" where eval_unit_id="<<eval_unit_id
		<<" ;";
	return sql.str();
}

std::string EvalUnit::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_eval_unit"
		<<" where eval_unit_id="<<eval_unit_id
		<<" ;";
	return sql.str();
}

long EvalUnit::getId() const
{
	return eval_unit_id;
}

void EvalUnit::setId(const long& value)
{
	this->eval_unit_id = value;
}

WorkSurfPtr EvalUnit::getWorkSurf() const
{
	return work_surf;
}

void EvalUnit::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

double EvalUnit::getUnitL() const
{
	return unit_l;
}

void EvalUnit::setUnitL(const double& value)
{
	this->unit_l = value;
}

double EvalUnit::getUnitT() const
{
	return unit_t;
}

void EvalUnit::setUnitT(const double& value)
{
	this->unit_t = value;
}

} // namespace cbm
