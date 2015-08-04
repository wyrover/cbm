#ifndef CBM_TECHNOLOGY_DAO_H
#define CBM_TECHNOLOGY_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/Technology.h"

namespace cbm {

class TechnologyDao : public ModelDao
{
public:
	TechnologyDao();
	~TechnologyDao();
	long insert(Technology& obj);;
	bool update(Technology& obj);
	bool remove(Technology& obj);
	TechnologyPtr getTechnologyById(long id);
	TechnologyList getTechnologyList();

}; // class TechnologyDao

} // namespace cbm

#endif // CBM_TECHNOLOGY_DAO_H
