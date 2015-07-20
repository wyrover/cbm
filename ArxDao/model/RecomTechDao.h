#ifndef CBM_RECOM_TECH_DAO_H
#define CBM_RECOM_TECH_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/RecomTech.h"

namespace cbm {

class RecomTechDao : public ModelDao
{
public:
	RecomTechDao();
	~RecomTechDao();
	long insert(RecomTech& obj);;
	bool update(RecomTech& obj);
	bool remove(RecomTech& obj);
	RecomTechPtr getRecomTechById(long id);
	RecomTechList getRecomTechList();

}; // class RecomTechDao

} // namespace cbm

#endif // CBM_RECOM_TECH_DAO_H
