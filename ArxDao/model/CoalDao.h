#ifndef CBM_COAL_DAO_H
#define CBM_COAL_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/Coal.h"

namespace cbm {

class CoalDao : public ModelDao
{
public:
	CoalDao();
	~CoalDao();
	long insert(Coal& obj);;
	bool update(Coal& obj);
	bool remove(Coal& obj);
	CoalPtr getCoalById(long id);
	CoalList getCoalList();

}; // class CoalDao

} // namespace cbm

#endif // CBM_COAL_DAO_H
