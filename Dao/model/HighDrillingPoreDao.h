#ifndef CBM_HIGH_DRILLING_PORE_DAO_H
#define CBM_HIGH_DRILLING_PORE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/HighDrillingPore.h"

namespace cbm {

class HighDrillingPoreDao : public ModelDao
{
public:
	HighDrillingPoreDao();
	~HighDrillingPoreDao();
	long insert(HighDrillingPore& obj);;
	bool update(HighDrillingPore& obj);
	bool remove(HighDrillingPore& obj);
	HighDrillingPorePtr getHighDrillingPoreById(long id);
	HighDrillingPoreList getHighDrillingPoreList();

}; // class HighDrillingPoreDao

} // namespace cbm

#endif // CBM_HIGH_DRILLING_PORE_DAO_H
