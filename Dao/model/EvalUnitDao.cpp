#include "EvalUnitDao.h"

namespace cbm {

EvalUnitDao::EvalUnitDao() : ModelDao()
{
}

EvalUnitDao::~EvalUnitDao()
{
}

long EvalUnitDao::insert(EvalUnit& obj)
{
	return dao->insert(obj);
}

bool EvalUnitDao::update(EvalUnit& obj)
{
	return dao->update(obj);
}

bool EvalUnitDao::remove(EvalUnit& obj)
{
	return dao->remove(obj);
}

EvalUnitPtr EvalUnitDao::getEvalUnitById(long id)
{
	EvalUnitList list = dao->select<EvalUnit>("cbm_eval_unit", "*", "where id="+to_string(id));
	EvalUnitPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

EvalUnitList EvalUnitDao::getEvalUnitList()
{
	return dao->select<EvalUnit>("cbm_eval_unit", "*", "order by EvalUnit_id desc");
}

} // namespace cbm
