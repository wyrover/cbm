#include "stdafx.h"
#include "DummyDao.h"

namespace cbm {

DummyDao::DummyDao() : ModelDao()
{
}

DummyDao::~DummyDao()
{
}

long DummyDao::insert(Dummy& obj)
{
	return dao->insert(obj);
}

bool DummyDao::update(Dummy& obj)
{
	return dao->update(obj);
}

bool DummyDao::remove(Dummy& obj)
{
	return dao->remove(obj);
}

DummyPtr DummyDao::getDummyById(long id)
{
	DummyList list = dao->select<Dummy>("cbm_dummy", "*", "where id="+to_string(id));
	DummyPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

DummyList DummyDao::getDummyList()
{
	return dao->select<Dummy>("cbm_dummy", "*", "order by Dummy_id desc");
}

} // namespace cbm
