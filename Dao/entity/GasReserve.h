#ifndef CBM_GAS_RESERVE_H
#define CBM_GAS_RESERVE_H

#include "common.h"
#include <row.h>

namespace cbm {

class GasReserve
{
public:
	GasReserve();
	GasReserve(long id);
	GasReserve(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MinePtr getMine() const;
	void setMine(const MinePtr& value);
	double getReserveW1() const;
	void setReserveW1(const double& value);
	double getReserveW2() const;
	void setReserveW2(const double& value);
	double getReserveW3() const;
	void setReserveW3(const double& value);
	double getReserveGas() const;
	void setReserveGas(const double& value);

private:
	long gas_reserve_id;
	MinePtr mine;
	double reserve_w1;
	double reserve_w2;
	double reserve_w3;
	double reserve_gas;

}; // class GasReserve

} // namespace cbm

#endif // CBM_GAS_RESERVE_H
