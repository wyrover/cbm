#ifndef CBM_EVAL_UNIT_H
#define CBM_EVAL_UNIT_H

#include "common.h"
#include <row.h>

namespace cbm {

class EvalUnit
{
public:
	EvalUnit();
	EvalUnit(long id);
	EvalUnit(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	double getUnitL() const;
	void setUnitL(const double& value);
	double getUnitT() const;
	void setUnitT(const double& value);

private:
	long eval_unit_id;
	WorkSurfPtr work_surf;
	double unit_l;
	double unit_t;

}; // class EvalUnit

} // namespace cbm

#endif // CBM_EVAL_UNIT_H
