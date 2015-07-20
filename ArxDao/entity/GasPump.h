#ifndef CBM_GAS_PUMP_H
#define CBM_GAS_PUMP_H

#include "common.h"
#include <row.h>

namespace cbm {

class GasPump
{
public:
	GasPump();
	GasPump(long id);
	GasPump(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MinePtr getMine() const;
	void setMine(const MinePtr& value);
	double getPumpKd() const;
	void setPumpKd(const double& value);
	double getPumpK1() const;
	void setPumpK1(const double& value);
	double getPumpK2() const;
	void setPumpK2(const double& value);
	double getPumpK3() const;
	void setPumpK3(const double& value);
	double getPumpK4() const;
	void setPumpK4(const double& value);
	double getPumpMy() const;
	void setPumpMy(const double& value);
	double getPumpMc() const;
	void setPumpMc(const double& value);
	double getPumpWc() const;
	void setPumpWc(const double& value);

private:
	long gas_pump_id;
	MinePtr mine;
	double pump_kd;
	double pump_k1;
	double pump_k2;
	double pump_k3;
	double pump_k4;
	double pump_my;
	double pump_mc;
	double pump_wc;

}; // class GasPump

} // namespace cbm

#endif // CBM_GAS_PUMP_H
