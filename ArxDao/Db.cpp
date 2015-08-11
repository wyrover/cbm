#include "stdafx.h"
#include "Db.h"
#include "SociDb.h"

namespace orm
{
	DbPrt Db::instance;

	DbPrt Db::Instance()
	{
		if(!instance)
		{
			instance.reset(new soci_Db());
		}
		return instance;
	}

	DbPrt get_db()
	{
		return Db::Instance();
	}
}
