#ifndef CBM_COAL_LAYER_H
#define CBM_COAL_LAYER_H

#include "common.h"
#include <row.h>

namespace cbm {

class CoalLayer
{
public:
	CoalLayer();
	CoalLayer(long id);
	CoalLayer(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	long getLayerNum() const;
	void setLayerNum(const long& value);
	double getLayerH() const;
	void setLayerH(const double& value);
	double getLayerHp() const;
	void setLayerHp(const double& value);
	long getLayerCaveZone() const;
	void setLayerCaveZone(const long& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long coal_layer_id;
	WorkSurfPtr work_surf;
	CoalPtr coal;
	long layer_num;
	double layer_h;
	double layer_hp;
	long layer_cave_zone;
	std::string comment;

}; // class CoalLayer

} // namespace cbm

#endif // CBM_COAL_LAYER_H
