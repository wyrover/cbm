#include "stdafx.h"
#include "PoreSize.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

PoreSize::PoreSize()
{
	pore_size_id = 0;
	size_q = 0.0;
	size_v = 0.0;
	size_d = 0.0;
	size_p = 0.0;
	size_sigma = 0.0;
	size_delta = 0.0;
}

PoreSize::PoreSize(long id)
{
	pore_size_id = id;
	size_q = 0.0;
	size_v = 0.0;
	size_d = 0.0;
	size_p = 0.0;
	size_sigma = 0.0;
	size_delta = 0.0;
}

PoreSize::PoreSize(soci::row &rs)
{
	pore_size_id = rs.get<long>(0);
	size_q = rs.get<double>(1);
	size_v = rs.get<double>(2);
	size_d = rs.get<double>(3);
	size_p = rs.get<double>(4);
	size_sigma = rs.get<double>(5);
	size_delta = rs.get<double>(6);
}

std::string PoreSize::getTableName() const
{
	return "cbm_pore_size";
}

std::string PoreSize::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_pore_size values("
		<<"NULL"<<","
		<<size_q<<","
		<<size_v<<","
		<<size_d<<","
		<<size_p<<","
		<<size_sigma<<","
		<<size_delta<<");";
	return sql.str();
}

std::string PoreSize::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_pore_size set"
		<<" size_q="<<size_q<<","
		<<" size_v="<<size_v<<","
		<<" size_d="<<size_d<<","
		<<" size_p="<<size_p<<","
		<<" size_sigma="<<size_sigma<<","
		<<" size_delta="<<size_delta
		<<" where pore_size_id="<<pore_size_id
		<<" ;";
	return sql.str();
}

std::string PoreSize::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_pore_size"
		<<" where pore_size_id="<<pore_size_id
		<<" ;";
	return sql.str();
}

long PoreSize::getId() const
{
	return pore_size_id;
}

void PoreSize::setId(const long& value)
{
	this->pore_size_id = value;
}

double PoreSize::getSizeQ() const
{
	return size_q;
}

void PoreSize::setSizeQ(const double& value)
{
	this->size_q = value;
}

double PoreSize::getSizeV() const
{
	return size_v;
}

void PoreSize::setSizeV(const double& value)
{
	this->size_v = value;
}

double PoreSize::getSizeD() const
{
	return size_d;
}

void PoreSize::setSizeD(const double& value)
{
	this->size_d = value;
}

double PoreSize::getSizeP() const
{
	return size_p;
}

void PoreSize::setSizeP(const double& value)
{
	this->size_p = value;
}

double PoreSize::getSizeSigma() const
{
	return size_sigma;
}

void PoreSize::setSizeSigma(const double& value)
{
	this->size_sigma = value;
}

double PoreSize::getSizeDelta() const
{
	return size_delta;
}

void PoreSize::setSizeDelta(const double& value)
{
	this->size_delta = value;
}

} // namespace cbm
