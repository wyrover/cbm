#ifndef CBM_PORE_SIZE_DAO_H
#define CBM_PORE_SIZE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/PoreSize.h"

namespace cbm {

class PoreSizeDao : public ModelDao
{
public:
	PoreSizeDao();
	~PoreSizeDao();
	long insert(PoreSize& obj);;
	bool update(PoreSize& obj);
	bool remove(PoreSize& obj);
	PoreSizePtr getPoreSizeById(long id);
	PoreSizeList getPoreSizeList();

}; // class PoreSizeDao

} // namespace cbm

#endif // CBM_PORE_SIZE_DAO_H
