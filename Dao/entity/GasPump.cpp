#include "GasPump.h"
#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

GasPump::GasPump()
{
	gas_pump_id = 0;
	pump_kd = 0.0;
	pump_k1 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_my = 0.0;
	pump_mc = 0.0;
	pump_wc = 0.0;
}

GasPump::GasPump(long id)
{
	gas_pump_id = id;
	pump_kd = 0.0;
	pump_k1 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_my = 0.0;
	pump_mc = 0.0;
	pump_wc = 0.0;
}

GasPump::GasPump(soci::row &rs)
{
	gas_pump_id = rs.get<long>(0);
	long mine_id = rs.get<long>(1);
	if(mine_id > -1) {
		mine = MinePtr(new Mine(mine_id));
	}
	pump_kd = rs.get<double>(2);
	pump_k1 = rs.get<double>(3);
	pump_k2 = rs.get<double>(4);
	pump_k3 = rs.get<double>(5);
	pump_k4 = rs.get<double>(6);
	pump_my = rs.get<double>(7);
	pump_mc = rs.get<double>(8);
	pump_wc = rs.get<double>(9);
}

std::string GasPump::getTableName() const
{
	return "cbm_gas_pump";
}

std::string GasPump::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_gas_pump values("
		<<"NULL"<<","
		<<mine->getId()<<","
		<<pump_kd<<","
		<<pump_k1<<","
		<<pump_k2<<","
		<<pump_k3<<","
		<<pump_k4<<","
		<<pump_my<<","
		<<pump_mc<<","
		<<pump_wc<<");";
	return sql.str();
}

std::string GasPump::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_gas_pump set"
		<<" mine_id="<<mine->getId()<<","
		<<" pump_kd="<<pump_kd<<","
		<<" pump_k1="<<pump_k1<<","
		<<" pump_k2="<<pump_k2<<","
		<<" pump_k3="<<pump_k3<<","
		<<" pump_k4="<<pump_k4<<","
		<<" pump_my="<<pump_my<<","
		<<" pump_mc="<<pump_mc<<","
		<<" pump_wc="<<pump_wc
		<<" where gas_pump_id="<<gas_pump_id
		<<" ;";
	return sql.str();
}

std::string GasPump::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_gas_pump"
		<<" where gas_pump_id="<<gas_pump_id
		<<" ;";
	return sql.str();
}

long GasPump::getId() const
{
	return gas_pump_id;
}

void GasPump::setId(const long& value)
{
	this->gas_pump_id = value;
}

MinePtr GasPump::getMine() const
{
	return mine;
}

void GasPump::setMine(const MinePtr& value)
{
	this->mine = value;
}

double GasPump::getPumpKd() const
{
	return pump_kd;
}

void GasPump::setPumpKd(const double& value)
{
	this->pump_kd = value;
}

double GasPump::getPumpK1() const
{
	return pump_k1;
}

void GasPump::setPumpK1(const double& value)
{
	this->pump_k1 = value;
}

double GasPump::getPumpK2() const
{
	return pump_k2;
}

void GasPump::setPumpK2(const double& value)
{
	this->pump_k2 = value;
}

double GasPump::getPumpK3() const
{
	return pump_k3;
}

void GasPump::setPumpK3(const double& value)
{
	this->pump_k3 = value;
}

double GasPump::getPumpK4() const
{
	return pump_k4;
}

void GasPump::setPumpK4(const double& value)
{
	this->pump_k4 = value;
}

double GasPump::getPumpMy() const
{
	return pump_my;
}

void GasPump::setPumpMy(const double& value)
{
	this->pump_my = value;
}

double GasPump::getPumpMc() const
{
	return pump_mc;
}

void GasPump::setPumpMc(const double& value)
{
	this->pump_mc = value;
}

double GasPump::getPumpWc() const
{
	return pump_wc;
}

void GasPump::setPumpWc(const double& value)
{
	this->pump_wc = value;
}

} // namespace cbm
