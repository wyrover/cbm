#ifndef CBM_RES_ABUNDANCE_DAO_H
#define CBM_RES_ABUNDANCE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/ResAbundance.h"

namespace cbm {

class ResAbundanceDao : public ModelDao
{
public:
	ResAbundanceDao();
	~ResAbundanceDao();
	long insert(ResAbundance& obj);;
	bool update(ResAbundance& obj);
	bool remove(ResAbundance& obj);
	ResAbundancePtr getResAbundanceById(long id);
	ResAbundanceList getResAbundanceList();

}; // class ResAbundanceDao

} // namespace cbm

#endif // CBM_RES_ABUNDANCE_DAO_H
