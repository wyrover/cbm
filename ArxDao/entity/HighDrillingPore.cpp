#include "stdafx.h"
#include "HighDrillingPore.h"
#include "WorkSurf.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

HighDrillingPore::HighDrillingPore()
{
	high_drilling_pore_id = 0;
	hdp_l1 = 0.0;
	hdp_l2 = 0.0;
	hdp_lg = 0.0;
	hdp_hz = 0.0;
	hdp_lk = 0.0;
	hdp_lc = 0.0;
	hdp_lw = 0.0;
	hdp_n = 0.0;
	hdp_beta = 0.0;
	hdp_ld = 0.0;
	hdp_lzi = 0.0;
	hdp_lzj = 0.0;
}

HighDrillingPore::HighDrillingPore(long id)
{
	high_drilling_pore_id = id;
	hdp_l1 = 0.0;
	hdp_l2 = 0.0;
	hdp_lg = 0.0;
	hdp_hz = 0.0;
	hdp_lk = 0.0;
	hdp_lc = 0.0;
	hdp_lw = 0.0;
	hdp_n = 0.0;
	hdp_beta = 0.0;
	hdp_ld = 0.0;
	hdp_lzi = 0.0;
	hdp_lzj = 0.0;
}

HighDrillingPore::HighDrillingPore(soci::row &rs)
{
	high_drilling_pore_id = rs.get<long>(0);
	long work_surf_id = rs.get<long>(1);
	if(work_surf_id > -1) {
		work_surf = WorkSurfPtr(new WorkSurf(work_surf_id));
	}
	hdp_l1 = rs.get<double>(2);
	hdp_l2 = rs.get<double>(3);
	hdp_lg = rs.get<double>(4);
	hdp_hz = rs.get<double>(5);
	hdp_lk = rs.get<double>(6);
	hdp_lc = rs.get<double>(7);
	hdp_lw = rs.get<double>(8);
	hdp_n = rs.get<double>(9);
	hdp_beta = rs.get<double>(10);
	hdp_ld = rs.get<double>(11);
	hdp_lzi = rs.get<double>(12);
	hdp_lzj = rs.get<double>(13);
}

std::string HighDrillingPore::getTableName() const
{
	return "cbm_high_drilling_pore";
}

std::string HighDrillingPore::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_high_drilling_pore values("
		<<"NULL"<<","
		<<work_surf->getId()<<","
		<<hdp_l1<<","
		<<hdp_l2<<","
		<<hdp_lg<<","
		<<hdp_hz<<","
		<<hdp_lk<<","
		<<hdp_lc<<","
		<<hdp_lw<<","
		<<hdp_n<<","
		<<hdp_beta<<","
		<<hdp_ld<<","
		<<hdp_lzi<<","
		<<hdp_lzj<<");";
	return sql.str();
}

std::string HighDrillingPore::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_high_drilling_pore set"
		<<" work_surf_id="<<work_surf->getId()<<","
		<<" hdp_l1="<<hdp_l1<<","
		<<" hdp_l2="<<hdp_l2<<","
		<<" hdp_lg="<<hdp_lg<<","
		<<" hdp_hz="<<hdp_hz<<","
		<<" hdp_lk="<<hdp_lk<<","
		<<" hdp_lc="<<hdp_lc<<","
		<<" hdp_lw="<<hdp_lw<<","
		<<" hdp_n="<<hdp_n<<","
		<<" hdp_beta="<<hdp_beta<<","
		<<" hdp_ld="<<hdp_ld<<","
		<<" hdp_lzi="<<hdp_lzi<<","
		<<" hdp_lzj="<<hdp_lzj
		<<" where high_drilling_pore_id="<<high_drilling_pore_id
		<<" ;";
	return sql.str();
}

std::string HighDrillingPore::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_high_drilling_pore"
		<<" where high_drilling_pore_id="<<high_drilling_pore_id
		<<" ;";
	return sql.str();
}

long HighDrillingPore::getId() const
{
	return high_drilling_pore_id;
}

void HighDrillingPore::setId(const long& value)
{
	this->high_drilling_pore_id = value;
}

WorkSurfPtr HighDrillingPore::getWorkSurf() const
{
	return work_surf;
}

void HighDrillingPore::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

double HighDrillingPore::getHdpL1() const
{
	return hdp_l1;
}

void HighDrillingPore::setHdpL1(const double& value)
{
	this->hdp_l1 = value;
}

double HighDrillingPore::getHdpL2() const
{
	return hdp_l2;
}

void HighDrillingPore::setHdpL2(const double& value)
{
	this->hdp_l2 = value;
}

double HighDrillingPore::getHdpLg() const
{
	return hdp_lg;
}

void HighDrillingPore::setHdpLg(const double& value)
{
	this->hdp_lg = value;
}

double HighDrillingPore::getHdpHz() const
{
	return hdp_hz;
}

void HighDrillingPore::setHdpHz(const double& value)
{
	this->hdp_hz = value;
}

double HighDrillingPore::getHdpLk() const
{
	return hdp_lk;
}

void HighDrillingPore::setHdpLk(const double& value)
{
	this->hdp_lk = value;
}

double HighDrillingPore::getHdpLc() const
{
	return hdp_lc;
}

void HighDrillingPore::setHdpLc(const double& value)
{
	this->hdp_lc = value;
}

double HighDrillingPore::getHdpLw() const
{
	return hdp_lw;
}

void HighDrillingPore::setHdpLw(const double& value)
{
	this->hdp_lw = value;
}

double HighDrillingPore::getHdpN() const
{
	return hdp_n;
}

void HighDrillingPore::setHdpN(const double& value)
{
	this->hdp_n = value;
}

double HighDrillingPore::getHdpBeta() const
{
	return hdp_beta;
}

void HighDrillingPore::setHdpBeta(const double& value)
{
	this->hdp_beta = value;
}

double HighDrillingPore::getHdpLd() const
{
	return hdp_ld;
}

void HighDrillingPore::setHdpLd(const double& value)
{
	this->hdp_ld = value;
}

double HighDrillingPore::getHdpLzi() const
{
	return hdp_lzi;
}

void HighDrillingPore::setHdpLzi(const double& value)
{
	this->hdp_lzi = value;
}

double HighDrillingPore::getHdpLzj() const
{
	return hdp_lzj;
}

void HighDrillingPore::setHdpLzj(const double& value)
{
	this->hdp_lzj = value;
}

} // namespace cbm
