#include "stdafx.h"
#include "GasReserve.h"
#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

GasReserve::GasReserve()
{
	gas_reserve_id = 0;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	reserve_gas = 0.0;
}

GasReserve::GasReserve(long id)
{
	gas_reserve_id = id;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	reserve_gas = 0.0;
}

GasReserve::GasReserve(soci::row &rs)
{
	gas_reserve_id = rs.get<long>(0);
	long mine_id = rs.get<long>(1);
	if(mine_id > -1) {
		mine = MinePtr(new Mine(mine_id));
	}
	reserve_w1 = rs.get<double>(2);
	reserve_w2 = rs.get<double>(3);
	reserve_w3 = rs.get<double>(4);
	reserve_gas = rs.get<double>(5);
}

std::string GasReserve::getTableName() const
{
	return "cbm_gas_reserve";
}

std::string GasReserve::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_gas_reserve values("
		<<"NULL"<<","
		<<mine->getId()<<","
		<<reserve_w1<<","
		<<reserve_w2<<","
		<<reserve_w3<<","
		<<reserve_gas<<");";
	return sql.str();
}

std::string GasReserve::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_gas_reserve set"
		<<" mine_id="<<mine->getId()<<","
		<<" reserve_w1="<<reserve_w1<<","
		<<" reserve_w2="<<reserve_w2<<","
		<<" reserve_w3="<<reserve_w3<<","
		<<" reserve_gas="<<reserve_gas
		<<" where gas_reserve_id="<<gas_reserve_id
		<<" ;";
	return sql.str();
}

std::string GasReserve::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_gas_reserve"
		<<" where gas_reserve_id="<<gas_reserve_id
		<<" ;";
	return sql.str();
}

long GasReserve::getId() const
{
	return gas_reserve_id;
}

void GasReserve::setId(const long& value)
{
	this->gas_reserve_id = value;
}

MinePtr GasReserve::getMine() const
{
	return mine;
}

void GasReserve::setMine(const MinePtr& value)
{
	this->mine = value;
}

double GasReserve::getReserveW1() const
{
	return reserve_w1;
}

void GasReserve::setReserveW1(const double& value)
{
	this->reserve_w1 = value;
}

double GasReserve::getReserveW2() const
{
	return reserve_w2;
}

void GasReserve::setReserveW2(const double& value)
{
	this->reserve_w2 = value;
}

double GasReserve::getReserveW3() const
{
	return reserve_w3;
}

void GasReserve::setReserveW3(const double& value)
{
	this->reserve_w3 = value;
}

double GasReserve::getReserveGas() const
{
	return reserve_gas;
}

void GasReserve::setReserveGas(const double& value)
{
	this->reserve_gas = value;
}

} // namespace cbm
