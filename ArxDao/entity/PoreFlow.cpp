#include "stdafx.h"
#include "PoreFlow.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

PoreFlow::PoreFlow()
{
	pore_flow_id = 0;
	flow_t = 0.0;
	flow_a0 = 0.0;
	flow_d = 0.0;
	flow_d1 = 0.0;
	flow_m = 0.0;
	flow_k = 0.0;
	flow_delta_t = 0.0;
	flow_x = 0.0;
	flow_p_test = 0.0;
	flow_p_cur = 0.0;
	flow_b = 0.0;
	flow_pt = 0.0;
	flow_delta_p = 0.0;
	flow_dh = 0.0;
	flow_q_hun = 0.0;
	flow_q_chun = 0.0;
}

PoreFlow::PoreFlow(long id)
{
	pore_flow_id = id;
	flow_t = 0.0;
	flow_a0 = 0.0;
	flow_d = 0.0;
	flow_d1 = 0.0;
	flow_m = 0.0;
	flow_k = 0.0;
	flow_delta_t = 0.0;
	flow_x = 0.0;
	flow_p_test = 0.0;
	flow_p_cur = 0.0;
	flow_b = 0.0;
	flow_pt = 0.0;
	flow_delta_p = 0.0;
	flow_dh = 0.0;
	flow_q_hun = 0.0;
	flow_q_chun = 0.0;
}

PoreFlow::PoreFlow(soci::row &rs)
{
	pore_flow_id = rs.get<long>(0);
	flow_t = rs.get<double>(1);
	flow_a0 = rs.get<double>(2);
	flow_d = rs.get<double>(3);
	flow_d1 = rs.get<double>(4);
	flow_m = rs.get<double>(5);
	flow_k = rs.get<double>(6);
	flow_delta_t = rs.get<double>(7);
	flow_x = rs.get<double>(8);
	flow_p_test = rs.get<double>(9);
	flow_p_cur = rs.get<double>(10);
	flow_b = rs.get<double>(11);
	flow_pt = rs.get<double>(12);
	flow_delta_p = rs.get<double>(13);
	flow_dh = rs.get<double>(14);
	flow_q_hun = rs.get<double>(15);
	flow_q_chun = rs.get<double>(16);
}

std::string PoreFlow::getTableName() const
{
	return "cbm_pore_flow";
}

std::string PoreFlow::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_pore_flow values("
		<<"NULL"<<","
		<<flow_t<<","
		<<flow_a0<<","
		<<flow_d<<","
		<<flow_d1<<","
		<<flow_m<<","
		<<flow_k<<","
		<<flow_delta_t<<","
		<<flow_x<<","
		<<flow_p_test<<","
		<<flow_p_cur<<","
		<<flow_b<<","
		<<flow_pt<<","
		<<flow_delta_p<<","
		<<flow_dh<<","
		<<flow_q_hun<<","
		<<flow_q_chun<<");";
	return sql.str();
}

std::string PoreFlow::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_pore_flow set"
		<<" flow_t="<<flow_t<<","
		<<" flow_a0="<<flow_a0<<","
		<<" flow_d="<<flow_d<<","
		<<" flow_d1="<<flow_d1<<","
		<<" flow_m="<<flow_m<<","
		<<" flow_k="<<flow_k<<","
		<<" flow_delta_t="<<flow_delta_t<<","
		<<" flow_x="<<flow_x<<","
		<<" flow_p_test="<<flow_p_test<<","
		<<" flow_p_cur="<<flow_p_cur<<","
		<<" flow_b="<<flow_b<<","
		<<" flow_pt="<<flow_pt<<","
		<<" flow_delta_p="<<flow_delta_p<<","
		<<" flow_dh="<<flow_dh<<","
		<<" flow_q_hun="<<flow_q_hun<<","
		<<" flow_q_chun="<<flow_q_chun
		<<" where pore_flow_id="<<pore_flow_id
		<<" ;";
	return sql.str();
}

std::string PoreFlow::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_pore_flow"
		<<" where pore_flow_id="<<pore_flow_id
		<<" ;";
	return sql.str();
}

long PoreFlow::getId() const
{
	return pore_flow_id;
}

void PoreFlow::setId(const long& value)
{
	this->pore_flow_id = value;
}

double PoreFlow::getFlowT() const
{
	return flow_t;
}

void PoreFlow::setFlowT(const double& value)
{
	this->flow_t = value;
}

double PoreFlow::getFlowA0() const
{
	return flow_a0;
}

void PoreFlow::setFlowA0(const double& value)
{
	this->flow_a0 = value;
}

double PoreFlow::getFlowD() const
{
	return flow_d;
}

void PoreFlow::setFlowD(const double& value)
{
	this->flow_d = value;
}

double PoreFlow::getFlowD1() const
{
	return flow_d1;
}

void PoreFlow::setFlowD1(const double& value)
{
	this->flow_d1 = value;
}

double PoreFlow::getFlowM() const
{
	return flow_m;
}

void PoreFlow::setFlowM(const double& value)
{
	this->flow_m = value;
}

double PoreFlow::getFlowK() const
{
	return flow_k;
}

void PoreFlow::setFlowK(const double& value)
{
	this->flow_k = value;
}

double PoreFlow::getFlowDeltaT() const
{
	return flow_delta_t;
}

void PoreFlow::setFlowDeltaT(const double& value)
{
	this->flow_delta_t = value;
}

double PoreFlow::getFlowX() const
{
	return flow_x;
}

void PoreFlow::setFlowX(const double& value)
{
	this->flow_x = value;
}

double PoreFlow::getFlowPTest() const
{
	return flow_p_test;
}

void PoreFlow::setFlowPTest(const double& value)
{
	this->flow_p_test = value;
}

double PoreFlow::getFlowPCur() const
{
	return flow_p_cur;
}

void PoreFlow::setFlowPCur(const double& value)
{
	this->flow_p_cur = value;
}

double PoreFlow::getFlowB() const
{
	return flow_b;
}

void PoreFlow::setFlowB(const double& value)
{
	this->flow_b = value;
}

double PoreFlow::getFlowPt() const
{
	return flow_pt;
}

void PoreFlow::setFlowPt(const double& value)
{
	this->flow_pt = value;
}

double PoreFlow::getFlowDeltaP() const
{
	return flow_delta_p;
}

void PoreFlow::setFlowDeltaP(const double& value)
{
	this->flow_delta_p = value;
}

double PoreFlow::getFlowDh() const
{
	return flow_dh;
}

void PoreFlow::setFlowDh(const double& value)
{
	this->flow_dh = value;
}

double PoreFlow::getFlowQHun() const
{
	return flow_q_hun;
}

void PoreFlow::setFlowQHun(const double& value)
{
	this->flow_q_hun = value;
}

double PoreFlow::getFlowQChun() const
{
	return flow_q_chun;
}

void PoreFlow::setFlowQChun(const double& value)
{
	this->flow_q_chun = value;
}

} // namespace cbm
