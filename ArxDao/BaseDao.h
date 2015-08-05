#ifndef MODEL_DAO_H
#define MODEL_DAO_H

#include "DaoManager.h"

class BaseDao
{
public:
	virtual ~BaseDao();
	static DaoManagerPrt Dao();

protected:
	BaseDao();
};

#endif // MODEL_DAO_H
