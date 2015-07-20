#include "KeyLayer.h"
#include "HighDrillingPore.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

KeyLayer::KeyLayer()
{
	key_layer_id = 0;
	key_hn = 0.0;
	key_thetan = 0.0;
	key_qn = 0.0;
	key_rtn = 0.0;
	key_sum_hn = 0.0;
}

KeyLayer::KeyLayer(long id)
{
	key_layer_id = id;
	key_hn = 0.0;
	key_thetan = 0.0;
	key_qn = 0.0;
	key_rtn = 0.0;
	key_sum_hn = 0.0;
}

KeyLayer::KeyLayer(soci::row &rs)
{
	key_layer_id = rs.get<long>(0);
	long high_drilling_pore_id = rs.get<long>(1);
	if(high_drilling_pore_id > -1) {
		high_drilling_pore = HighDrillingPorePtr(new HighDrillingPore(high_drilling_pore_id));
	}
	key_hn = rs.get<double>(2);
	key_thetan = rs.get<double>(3);
	key_qn = rs.get<double>(4);
	key_rtn = rs.get<double>(5);
	key_sum_hn = rs.get<double>(6);
}

std::string KeyLayer::getTableName() const
{
	return "cbm_key_layer";
}

std::string KeyLayer::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_key_layer values("
		<<"NULL"<<","
		<<high_drilling_pore->getId()<<","
		<<key_hn<<","
		<<key_thetan<<","
		<<key_qn<<","
		<<key_rtn<<","
		<<key_sum_hn<<");";
	return sql.str();
}

std::string KeyLayer::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_key_layer set"
		<<" high_drilling_pore_id="<<high_drilling_pore->getId()<<","
		<<" key_hn="<<key_hn<<","
		<<" key_thetan="<<key_thetan<<","
		<<" key_qn="<<key_qn<<","
		<<" key_rtn="<<key_rtn<<","
		<<" key_sum_hn="<<key_sum_hn
		<<" where key_layer_id="<<key_layer_id
		<<" ;";
	return sql.str();
}

std::string KeyLayer::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_key_layer"
		<<" where key_layer_id="<<key_layer_id
		<<" ;";
	return sql.str();
}

long KeyLayer::getId() const
{
	return key_layer_id;
}

void KeyLayer::setId(const long& value)
{
	this->key_layer_id = value;
}

HighDrillingPorePtr KeyLayer::getHighDrillingPore() const
{
	return high_drilling_pore;
}

void KeyLayer::setHighDrillingPore(const HighDrillingPorePtr& value)
{
	this->high_drilling_pore = value;
}

double KeyLayer::getKeyHn() const
{
	return key_hn;
}

void KeyLayer::setKeyHn(const double& value)
{
	this->key_hn = value;
}

double KeyLayer::getKeyThetan() const
{
	return key_thetan;
}

void KeyLayer::setKeyThetan(const double& value)
{
	this->key_thetan = value;
}

double KeyLayer::getKeyQn() const
{
	return key_qn;
}

void KeyLayer::setKeyQn(const double& value)
{
	this->key_qn = value;
}

double KeyLayer::getKeyRtn() const
{
	return key_rtn;
}

void KeyLayer::setKeyRtn(const double& value)
{
	this->key_rtn = value;
}

double KeyLayer::getKeySumHn() const
{
	return key_sum_hn;
}

void KeyLayer::setKeySumHn(const double& value)
{
	this->key_sum_hn = value;
}

} // namespace cbm
