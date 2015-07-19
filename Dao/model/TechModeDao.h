#ifndef CBM_TECH_MODE_DAO_H
#define CBM_TECH_MODE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/TechMode.h"

namespace cbm {

class TechModeDao : public ModelDao
{
public:
	TechModeDao();
	~TechModeDao();
	long insert(TechMode& obj);;
	bool update(TechMode& obj);
	bool remove(TechMode& obj);
	TechModePtr getTechModeById(long id);
	TechModeList getTechModeList();

}; // class TechModeDao

} // namespace cbm

#endif // CBM_TECH_MODE_DAO_H
