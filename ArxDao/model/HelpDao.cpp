#include "stdafx.h"
#include "HelpDao.h"

namespace cbm {

HelpDao::HelpDao() : ModelDao()
{
}

HelpDao::~HelpDao()
{
}

long HelpDao::insert(Help& obj)
{
	return dao->insert(obj);
}

bool HelpDao::update(Help& obj)
{
	return dao->update(obj);
}

bool HelpDao::remove(Help& obj)
{
	return dao->remove(obj);
}

HelpPtr HelpDao::getHelpById(long id)
{
	HelpList list = dao->select<Help>("cbm_help", "*", "where id="+to_string(id));
	HelpPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

HelpList HelpDao::getHelpList()
{
	return dao->select<Help>("cbm_help", "*", "order by Help_id desc");
}

} // namespace cbm
