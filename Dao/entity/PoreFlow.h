#ifndef CBM_PORE_FLOW_H
#define CBM_PORE_FLOW_H

#include "common.h"
#include <row.h>

namespace cbm {

class PoreFlow
{
public:
	PoreFlow();
	PoreFlow(long id);
	PoreFlow(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	double getFlowT() const;
	void setFlowT(const double& value);
	double getFlowA0() const;
	void setFlowA0(const double& value);
	double getFlowD() const;
	void setFlowD(const double& value);
	double getFlowD1() const;
	void setFlowD1(const double& value);
	double getFlowM() const;
	void setFlowM(const double& value);
	double getFlowK() const;
	void setFlowK(const double& value);
	double getFlowDeltaT() const;
	void setFlowDeltaT(const double& value);
	double getFlowX() const;
	void setFlowX(const double& value);
	double getFlowPTest() const;
	void setFlowPTest(const double& value);
	double getFlowPCur() const;
	void setFlowPCur(const double& value);
	double getFlowB() const;
	void setFlowB(const double& value);
	double getFlowPt() const;
	void setFlowPt(const double& value);
	double getFlowDeltaP() const;
	void setFlowDeltaP(const double& value);
	double getFlowDh() const;
	void setFlowDh(const double& value);
	double getFlowQHun() const;
	void setFlowQHun(const double& value);
	double getFlowQChun() const;
	void setFlowQChun(const double& value);

private:
	long pore_flow_id;
	double flow_t;
	double flow_a0;
	double flow_d;
	double flow_d1;
	double flow_m;
	double flow_k;
	double flow_delta_t;
	double flow_x;
	double flow_p_test;
	double flow_p_cur;
	double flow_b;
	double flow_pt;
	double flow_delta_p;
	double flow_dh;
	double flow_q_hun;
	double flow_q_chun;

}; // class PoreFlow

} // namespace cbm

#endif // CBM_PORE_FLOW_H
