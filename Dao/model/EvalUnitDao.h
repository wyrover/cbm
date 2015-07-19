#ifndef CBM_EVAL_UNIT_DAO_H
#define CBM_EVAL_UNIT_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/EvalUnit.h"

namespace cbm {

class EvalUnitDao : public ModelDao
{
public:
	EvalUnitDao();
	~EvalUnitDao();
	long insert(EvalUnit& obj);;
	bool update(EvalUnit& obj);
	bool remove(EvalUnit& obj);
	EvalUnitPtr getEvalUnitById(long id);
	EvalUnitList getEvalUnitList();

}; // class EvalUnitDao

} // namespace cbm

#endif // CBM_EVAL_UNIT_DAO_H
