#ifndef CBM_KEY_LAYER_H
#define CBM_KEY_LAYER_H

#include "common.h"
#include <row.h>

namespace cbm {

class KeyLayer
{
public:
	KeyLayer();
	KeyLayer(long id);
	KeyLayer(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	HighDrillingPorePtr getHighDrillingPore() const;
	void setHighDrillingPore(const HighDrillingPorePtr& value);
	double getKeyHn() const;
	void setKeyHn(const double& value);
	double getKeyThetan() const;
	void setKeyThetan(const double& value);
	double getKeyQn() const;
	void setKeyQn(const double& value);
	double getKeyRtn() const;
	void setKeyRtn(const double& value);
	double getKeySumHn() const;
	void setKeySumHn(const double& value);

private:
	long key_layer_id;
	HighDrillingPorePtr high_drilling_pore;
	double key_hn;
	double key_thetan;
	double key_qn;
	double key_rtn;
	double key_sum_hn;

}; // class KeyLayer

} // namespace cbm

#endif // CBM_KEY_LAYER_H
