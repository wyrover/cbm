#ifndef CBM_DUMMY_DAO_H
#define CBM_DUMMY_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/Dummy.h"

namespace cbm {

class DummyDao : public ModelDao
{
public:
	DummyDao();
	~DummyDao();
	long insert(Dummy& obj);;
	bool update(Dummy& obj);
	bool remove(Dummy& obj);
	DummyPtr getDummyById(long id);
	DummyList getDummyList();

}; // class DummyDao

} // namespace cbm

#endif // CBM_DUMMY_DAO_H
