#include "ModelDao.h"

ModelDao::~ModelDao()
{

}

ModelDao::ModelDao()
{
    dao = Dao::GetInstance();
}
