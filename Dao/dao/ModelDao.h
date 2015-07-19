#ifndef MODEL_DAO_H
#define MODEL_DAO_H

#include "dao.h"

class ModelDao
{
public:
	virtual ~ModelDao();

protected:
	ModelDao();
    DaoPrt dao;    
};

#endif // MODEL_DAO_H
