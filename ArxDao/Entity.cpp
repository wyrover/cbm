#include "stdafx.h"
#include "Entity.h"
#include <Util/HelperClass.h>

namespace cbm {

CString AdjLayer::GetTableName()
{
	return _T("cbm_adj_layer");
}

AdjLayerPtr AdjLayer::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	AdjLayerList objList = Dao()->select<AdjLayer>(_T("cbm_adj_layer"), _T("*"), options);
	AdjLayerPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

AdjLayerList AdjLayer::findAll()
{
	return Dao()->select<AdjLayer>(_T("cbm_adj_layer"), _T("*"), _T("order by AdjLayer_id desc"));
}

int AdjLayer::insert()
{
	if(work_surf == 0) return 0;
	if(coal == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool AdjLayer::update()
{
	if(work_surf == 0) return false;
	if(coal == 0) return false;
	return Dao()->update(*this);
}

bool AdjLayer::remove()
{
	return Dao()->remove(*this);
}

AdjLayer::AdjLayer()
{
	id = 0;
	layer_num = 0;
	layer_h = 0.0;
	layer_hp = 0.0;
	layer_cave_zone = 0;
	comment = _T("NULL");
}

AdjLayer::AdjLayer(int id)
{
	id = 0;
	layer_num = 0;
	layer_h = 0.0;
	layer_hp = 0.0;
	layer_cave_zone = 0;
	comment = _T("NULL");
}

AdjLayer::AdjLayer(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_work_surf_id = rs.get<int>("cbm_work_surf_id", (int)0);
	if(cbm_work_surf_id > 0) {
		work_surf = WorkSurfPtr(new WorkSurf(cbm_work_surf_id));
	}
	int cbm_coal_id = rs.get<int>("cbm_coal_id", (int)0);
	if(cbm_coal_id > 0) {
		coal = CoalPtr(new Coal(cbm_coal_id));
	}
	layer_num = rs.get<int>("layer_num", (int)0);
	layer_h = rs.get<double>("layer_h", (double)0);
	layer_hp = rs.get<double>("layer_hp", (double)0);
	layer_cave_zone = rs.get<int>("layer_cave_zone", (int)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString AdjLayer::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_adj_layer values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), work_surf->getId());
	sql.AppendFormat(_T(", %d"), coal->getId());
	sql.AppendFormat(_T(", %d"), layer_num);
	sql.AppendFormat(_T(", %lf"), layer_h);
	sql.AppendFormat(_T(", %lf"), layer_hp);
	sql.AppendFormat(_T(", %d"), layer_cave_zone);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString AdjLayer::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_adj_layer set"));
	sql.AppendFormat(_T("  cbm_work_surf_id=%d"), work_surf->getId());
	sql.AppendFormat(_T(", cbm_coal_id=%d"), coal->getId());
	sql.AppendFormat(_T(", layer_num=%d"), layer_num);
	sql.AppendFormat(_T(", layer_h=%lf"), layer_h);
	sql.AppendFormat(_T(", layer_hp=%lf"), layer_hp);
	sql.AppendFormat(_T(", layer_cave_zone=%d"), layer_cave_zone);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString AdjLayer::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_adj_layer where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int AdjLayer::getId() const
{
	return id;
}

void AdjLayer::setId(const int& value)
{
	this->id = value;
}

WorkSurfPtr AdjLayer::getWorkSurf() const
{
	return work_surf;
}

void AdjLayer::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

CoalPtr AdjLayer::getCoal() const
{
	return coal;
}

void AdjLayer::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

int AdjLayer::getLayerNum() const
{
	return layer_num;
}

void AdjLayer::setLayerNum(const int& value)
{
	this->layer_num = value;
}

double AdjLayer::getLayerH() const
{
	return layer_h;
}

void AdjLayer::setLayerH(const double& value)
{
	this->layer_h = value;
}

double AdjLayer::getLayerHp() const
{
	return layer_hp;
}

void AdjLayer::setLayerHp(const double& value)
{
	this->layer_hp = value;
}

int AdjLayer::getLayerCaveZone() const
{
	return layer_cave_zone;
}

void AdjLayer::setLayerCaveZone(const int& value)
{
	this->layer_cave_zone = value;
}

CString AdjLayer::getComment() const
{
	return comment;
}

void AdjLayer::setComment(const CString& value)
{
	this->comment = value;
}

CString Coal::GetTableName()
{
	return _T("cbm_coal");
}

CoalPtr Coal::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	CoalList objList = Dao()->select<Coal>(_T("cbm_coal"), _T("*"), options);
	CoalPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

CoalList Coal::findAll()
{
	return Dao()->select<Coal>(_T("cbm_coal"), _T("*"), _T("order by Coal_id desc"));
}

int Coal::insert()
{
	if(mine == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool Coal::update()
{
	if(mine == 0) return false;
	return Dao()->update(*this);
}

bool Coal::remove()
{
	return Dao()->remove(*this);
}

Coal::Coal()
{
	id = 0;
	coal_name = _T("NULL");
	coal_minable = 0;
	coal_thick = 0.0;
	coal_rank = 0;
	coal_quality = 0;
	layer_pressure = 0.0;
	gas_content = 0.0;
	gas_penetration = 0.0;
	f_value = 0.0;
	res_abundance = 0;
	const_complexity = 0;
	mine_index = 0;
	var_coeff = 0.0;
	coal_stability = 0.0;
	dip_angle = 0.0;
	caving_zone_height = 0.0;
	layer_gap = 0.0;
	influence_factor = 0.0;
	res_a1 = 0.0;
	gas_x1 = 0.0;
	res_a2 = 0.0;
	gas_x2 = 0.0;
	gas_wc = 0.0;
	coal_r = 0.0;
	coal_vr = 0.0;
	gas_w0 = 0.0;
	gas_wc2 = 0.0;
	gas_eta = 0.0;
	q_r = 0.0;
	q0 = 0.0;
	eval_method = 0;
	q0_alpha = 0.0;
	qt_alpha = 0.0;
	t_alpha = 0.0;
	q_lambda = 0.0;
	r_lambda = 0.0;
	p0_lambda = 0.0;
	p1_lambda = 0.0;
	t_lambda = 0.0;
	a_lambda = 0.0;
	p1_k = 0.0;
	p2_k = 0.0;
	gas_q = 0.0;
	core_height = 0.0;
	core_area = 0.0;
	gas_viscosity = 0.0;
	decay_alpha = 0.0;
	permeability_lambda = 0.0;
	permeability_k = 0.0;
	eval_difficult = 0;
	comment = _T("NULL");
}

Coal::Coal(int id)
{
	id = 0;
	coal_name = _T("NULL");
	coal_minable = 0;
	coal_thick = 0.0;
	coal_rank = 0;
	coal_quality = 0;
	layer_pressure = 0.0;
	gas_content = 0.0;
	gas_penetration = 0.0;
	f_value = 0.0;
	res_abundance = 0;
	const_complexity = 0;
	mine_index = 0;
	var_coeff = 0.0;
	coal_stability = 0.0;
	dip_angle = 0.0;
	caving_zone_height = 0.0;
	layer_gap = 0.0;
	influence_factor = 0.0;
	res_a1 = 0.0;
	gas_x1 = 0.0;
	res_a2 = 0.0;
	gas_x2 = 0.0;
	gas_wc = 0.0;
	coal_r = 0.0;
	coal_vr = 0.0;
	gas_w0 = 0.0;
	gas_wc2 = 0.0;
	gas_eta = 0.0;
	q_r = 0.0;
	q0 = 0.0;
	eval_method = 0;
	q0_alpha = 0.0;
	qt_alpha = 0.0;
	t_alpha = 0.0;
	q_lambda = 0.0;
	r_lambda = 0.0;
	p0_lambda = 0.0;
	p1_lambda = 0.0;
	t_lambda = 0.0;
	a_lambda = 0.0;
	p1_k = 0.0;
	p2_k = 0.0;
	gas_q = 0.0;
	core_height = 0.0;
	core_area = 0.0;
	gas_viscosity = 0.0;
	decay_alpha = 0.0;
	permeability_lambda = 0.0;
	permeability_k = 0.0;
	eval_difficult = 0;
	comment = _T("NULL");
}

Coal::Coal(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_mine_id = rs.get<int>("cbm_mine_id", (int)0);
	if(cbm_mine_id > 0) {
		mine = MinePtr(new Mine(cbm_mine_id));
	}
	coal_name = EncodeHelper::ANSIToUnicode(rs.get<std::string>("coal_name", "")).c_str();
	coal_minable = rs.get<int>("coal_minable", (int)0);
	coal_thick = rs.get<double>("coal_thick", (double)0);
	coal_rank = rs.get<int>("coal_rank", (int)0);
	coal_quality = rs.get<int>("coal_quality", (int)0);
	layer_pressure = rs.get<double>("layer_pressure", (double)0);
	gas_content = rs.get<double>("gas_content", (double)0);
	gas_penetration = rs.get<double>("gas_penetration", (double)0);
	f_value = rs.get<double>("f_value", (double)0);
	res_abundance = rs.get<int>("res_abundance", (int)0);
	const_complexity = rs.get<int>("const_complexity", (int)0);
	mine_index = rs.get<int>("mine_index", (int)0);
	var_coeff = rs.get<double>("var_coeff", (double)0);
	coal_stability = rs.get<double>("coal_stability", (double)0);
	dip_angle = rs.get<double>("dip_angle", (double)0);
	caving_zone_height = rs.get<double>("caving_zone_height", (double)0);
	layer_gap = rs.get<double>("layer_gap", (double)0);
	influence_factor = rs.get<double>("influence_factor", (double)0);
	res_a1 = rs.get<double>("res_a1", (double)0);
	gas_x1 = rs.get<double>("gas_x1", (double)0);
	res_a2 = rs.get<double>("res_a2", (double)0);
	gas_x2 = rs.get<double>("gas_x2", (double)0);
	gas_wc = rs.get<double>("gas_wc", (double)0);
	coal_r = rs.get<double>("coal_r", (double)0);
	coal_vr = rs.get<double>("coal_vr", (double)0);
	gas_w0 = rs.get<double>("gas_w0", (double)0);
	gas_wc2 = rs.get<double>("gas_wc2", (double)0);
	gas_eta = rs.get<double>("gas_eta", (double)0);
	q_r = rs.get<double>("q_r", (double)0);
	q0 = rs.get<double>("q0", (double)0);
	eval_method = rs.get<int>("eval_method", (int)0);
	q0_alpha = rs.get<double>("q0_alpha", (double)0);
	qt_alpha = rs.get<double>("qt_alpha", (double)0);
	t_alpha = rs.get<double>("t_alpha", (double)0);
	q_lambda = rs.get<double>("q_lambda", (double)0);
	r_lambda = rs.get<double>("r_lambda", (double)0);
	p0_lambda = rs.get<double>("p0_lambda", (double)0);
	p1_lambda = rs.get<double>("p1_lambda", (double)0);
	t_lambda = rs.get<double>("t_lambda", (double)0);
	a_lambda = rs.get<double>("a_lambda", (double)0);
	p1_k = rs.get<double>("p1_k", (double)0);
	p2_k = rs.get<double>("p2_k", (double)0);
	gas_q = rs.get<double>("gas_q", (double)0);
	core_height = rs.get<double>("core_height", (double)0);
	core_area = rs.get<double>("core_area", (double)0);
	gas_viscosity = rs.get<double>("gas_viscosity", (double)0);
	decay_alpha = rs.get<double>("decay_alpha", (double)0);
	permeability_lambda = rs.get<double>("permeability_lambda", (double)0);
	permeability_k = rs.get<double>("permeability_k", (double)0);
	eval_difficult = rs.get<int>("eval_difficult", (int)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString Coal::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_coal values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), mine->getId());
	sql.AppendFormat(_T(", '%s'"), coal_name);
	sql.AppendFormat(_T(", %d"), coal_minable);
	sql.AppendFormat(_T(", %lf"), coal_thick);
	sql.AppendFormat(_T(", %d"), coal_rank);
	sql.AppendFormat(_T(", %d"), coal_quality);
	sql.AppendFormat(_T(", %lf"), layer_pressure);
	sql.AppendFormat(_T(", %lf"), gas_content);
	sql.AppendFormat(_T(", %lf"), gas_penetration);
	sql.AppendFormat(_T(", %lf"), f_value);
	sql.AppendFormat(_T(", %d"), res_abundance);
	sql.AppendFormat(_T(", %d"), const_complexity);
	sql.AppendFormat(_T(", %d"), mine_index);
	sql.AppendFormat(_T(", %lf"), var_coeff);
	sql.AppendFormat(_T(", %lf"), coal_stability);
	sql.AppendFormat(_T(", %lf"), dip_angle);
	sql.AppendFormat(_T(", %lf"), caving_zone_height);
	sql.AppendFormat(_T(", %lf"), layer_gap);
	sql.AppendFormat(_T(", %lf"), influence_factor);
	sql.AppendFormat(_T(", %lf"), res_a1);
	sql.AppendFormat(_T(", %lf"), gas_x1);
	sql.AppendFormat(_T(", %lf"), res_a2);
	sql.AppendFormat(_T(", %lf"), gas_x2);
	sql.AppendFormat(_T(", %lf"), gas_wc);
	sql.AppendFormat(_T(", %lf"), coal_r);
	sql.AppendFormat(_T(", %lf"), coal_vr);
	sql.AppendFormat(_T(", %lf"), gas_w0);
	sql.AppendFormat(_T(", %lf"), gas_wc2);
	sql.AppendFormat(_T(", %lf"), gas_eta);
	sql.AppendFormat(_T(", %lf"), q_r);
	sql.AppendFormat(_T(", %lf"), q0);
	sql.AppendFormat(_T(", %d"), eval_method);
	sql.AppendFormat(_T(", %lf"), q0_alpha);
	sql.AppendFormat(_T(", %lf"), qt_alpha);
	sql.AppendFormat(_T(", %lf"), t_alpha);
	sql.AppendFormat(_T(", %lf"), q_lambda);
	sql.AppendFormat(_T(", %lf"), r_lambda);
	sql.AppendFormat(_T(", %lf"), p0_lambda);
	sql.AppendFormat(_T(", %lf"), p1_lambda);
	sql.AppendFormat(_T(", %lf"), t_lambda);
	sql.AppendFormat(_T(", %lf"), a_lambda);
	sql.AppendFormat(_T(", %lf"), p1_k);
	sql.AppendFormat(_T(", %lf"), p2_k);
	sql.AppendFormat(_T(", %lf"), gas_q);
	sql.AppendFormat(_T(", %lf"), core_height);
	sql.AppendFormat(_T(", %lf"), core_area);
	sql.AppendFormat(_T(", %lf"), gas_viscosity);
	sql.AppendFormat(_T(", %lf"), decay_alpha);
	sql.AppendFormat(_T(", %lf"), permeability_lambda);
	sql.AppendFormat(_T(", %lf"), permeability_k);
	sql.AppendFormat(_T(", %d"), eval_difficult);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString Coal::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_coal set"));
	sql.AppendFormat(_T("  cbm_mine_id=%d"), mine->getId());
	sql.AppendFormat(_T(", coal_name='%s'"), coal_name);
	sql.AppendFormat(_T(", coal_minable=%d"), coal_minable);
	sql.AppendFormat(_T(", coal_thick=%lf"), coal_thick);
	sql.AppendFormat(_T(", coal_rank=%d"), coal_rank);
	sql.AppendFormat(_T(", coal_quality=%d"), coal_quality);
	sql.AppendFormat(_T(", layer_pressure=%lf"), layer_pressure);
	sql.AppendFormat(_T(", gas_content=%lf"), gas_content);
	sql.AppendFormat(_T(", gas_penetration=%lf"), gas_penetration);
	sql.AppendFormat(_T(", f_value=%lf"), f_value);
	sql.AppendFormat(_T(", res_abundance=%d"), res_abundance);
	sql.AppendFormat(_T(", const_complexity=%d"), const_complexity);
	sql.AppendFormat(_T(", mine_index=%d"), mine_index);
	sql.AppendFormat(_T(", var_coeff=%lf"), var_coeff);
	sql.AppendFormat(_T(", coal_stability=%lf"), coal_stability);
	sql.AppendFormat(_T(", dip_angle=%lf"), dip_angle);
	sql.AppendFormat(_T(", caving_zone_height=%lf"), caving_zone_height);
	sql.AppendFormat(_T(", layer_gap=%lf"), layer_gap);
	sql.AppendFormat(_T(", influence_factor=%lf"), influence_factor);
	sql.AppendFormat(_T(", res_a1=%lf"), res_a1);
	sql.AppendFormat(_T(", gas_x1=%lf"), gas_x1);
	sql.AppendFormat(_T(", res_a2=%lf"), res_a2);
	sql.AppendFormat(_T(", gas_x2=%lf"), gas_x2);
	sql.AppendFormat(_T(", gas_wc=%lf"), gas_wc);
	sql.AppendFormat(_T(", coal_r=%lf"), coal_r);
	sql.AppendFormat(_T(", coal_vr=%lf"), coal_vr);
	sql.AppendFormat(_T(", gas_w0=%lf"), gas_w0);
	sql.AppendFormat(_T(", gas_wc2=%lf"), gas_wc2);
	sql.AppendFormat(_T(", gas_eta=%lf"), gas_eta);
	sql.AppendFormat(_T(", q_r=%lf"), q_r);
	sql.AppendFormat(_T(", q0=%lf"), q0);
	sql.AppendFormat(_T(", eval_method=%d"), eval_method);
	sql.AppendFormat(_T(", q0_alpha=%lf"), q0_alpha);
	sql.AppendFormat(_T(", qt_alpha=%lf"), qt_alpha);
	sql.AppendFormat(_T(", t_alpha=%lf"), t_alpha);
	sql.AppendFormat(_T(", q_lambda=%lf"), q_lambda);
	sql.AppendFormat(_T(", r_lambda=%lf"), r_lambda);
	sql.AppendFormat(_T(", p0_lambda=%lf"), p0_lambda);
	sql.AppendFormat(_T(", p1_lambda=%lf"), p1_lambda);
	sql.AppendFormat(_T(", t_lambda=%lf"), t_lambda);
	sql.AppendFormat(_T(", a_lambda=%lf"), a_lambda);
	sql.AppendFormat(_T(", p1_k=%lf"), p1_k);
	sql.AppendFormat(_T(", p2_k=%lf"), p2_k);
	sql.AppendFormat(_T(", gas_q=%lf"), gas_q);
	sql.AppendFormat(_T(", core_height=%lf"), core_height);
	sql.AppendFormat(_T(", core_area=%lf"), core_area);
	sql.AppendFormat(_T(", gas_viscosity=%lf"), gas_viscosity);
	sql.AppendFormat(_T(", decay_alpha=%lf"), decay_alpha);
	sql.AppendFormat(_T(", permeability_lambda=%lf"), permeability_lambda);
	sql.AppendFormat(_T(", permeability_k=%lf"), permeability_k);
	sql.AppendFormat(_T(", eval_difficult=%d"), eval_difficult);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString Coal::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_coal where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int Coal::getId() const
{
	return id;
}

void Coal::setId(const int& value)
{
	this->id = value;
}

MinePtr Coal::getMine() const
{
	return mine;
}

void Coal::setMine(const MinePtr& value)
{
	this->mine = value;
}

CString Coal::getCoalName() const
{
	return coal_name;
}

void Coal::setCoalName(const CString& value)
{
	this->coal_name = value;
}

int Coal::getCoalMinable() const
{
	return coal_minable;
}

void Coal::setCoalMinable(const int& value)
{
	this->coal_minable = value;
}

double Coal::getCoalThick() const
{
	return coal_thick;
}

void Coal::setCoalThick(const double& value)
{
	this->coal_thick = value;
}

int Coal::getCoalRank() const
{
	return coal_rank;
}

void Coal::setCoalRank(const int& value)
{
	this->coal_rank = value;
}

int Coal::getCoalQuality() const
{
	return coal_quality;
}

void Coal::setCoalQuality(const int& value)
{
	this->coal_quality = value;
}

double Coal::getLayerPressure() const
{
	return layer_pressure;
}

void Coal::setLayerPressure(const double& value)
{
	this->layer_pressure = value;
}

double Coal::getGasContent() const
{
	return gas_content;
}

void Coal::setGasContent(const double& value)
{
	this->gas_content = value;
}

double Coal::getGasPenetration() const
{
	return gas_penetration;
}

void Coal::setGasPenetration(const double& value)
{
	this->gas_penetration = value;
}

double Coal::getFValue() const
{
	return f_value;
}

void Coal::setFValue(const double& value)
{
	this->f_value = value;
}

int Coal::getResAbundance() const
{
	return res_abundance;
}

void Coal::setResAbundance(const int& value)
{
	this->res_abundance = value;
}

int Coal::getConstComplexity() const
{
	return const_complexity;
}

void Coal::setConstComplexity(const int& value)
{
	this->const_complexity = value;
}

int Coal::getMineIndex() const
{
	return mine_index;
}

void Coal::setMineIndex(const int& value)
{
	this->mine_index = value;
}

double Coal::getVarCoeff() const
{
	return var_coeff;
}

void Coal::setVarCoeff(const double& value)
{
	this->var_coeff = value;
}

double Coal::getCoalStability() const
{
	return coal_stability;
}

void Coal::setCoalStability(const double& value)
{
	this->coal_stability = value;
}

double Coal::getDipAngle() const
{
	return dip_angle;
}

void Coal::setDipAngle(const double& value)
{
	this->dip_angle = value;
}

double Coal::getCavingZoneHeight() const
{
	return caving_zone_height;
}

void Coal::setCavingZoneHeight(const double& value)
{
	this->caving_zone_height = value;
}

double Coal::getLayerGap() const
{
	return layer_gap;
}

void Coal::setLayerGap(const double& value)
{
	this->layer_gap = value;
}

double Coal::getInfluenceFactor() const
{
	return influence_factor;
}

void Coal::setInfluenceFactor(const double& value)
{
	this->influence_factor = value;
}

double Coal::getResA1() const
{
	return res_a1;
}

void Coal::setResA1(const double& value)
{
	this->res_a1 = value;
}

double Coal::getGasX1() const
{
	return gas_x1;
}

void Coal::setGasX1(const double& value)
{
	this->gas_x1 = value;
}

double Coal::getResA2() const
{
	return res_a2;
}

void Coal::setResA2(const double& value)
{
	this->res_a2 = value;
}

double Coal::getGasX2() const
{
	return gas_x2;
}

void Coal::setGasX2(const double& value)
{
	this->gas_x2 = value;
}

double Coal::getGasWc() const
{
	return gas_wc;
}

void Coal::setGasWc(const double& value)
{
	this->gas_wc = value;
}

double Coal::getCoalR() const
{
	return coal_r;
}

void Coal::setCoalR(const double& value)
{
	this->coal_r = value;
}

double Coal::getCoalVr() const
{
	return coal_vr;
}

void Coal::setCoalVr(const double& value)
{
	this->coal_vr = value;
}

double Coal::getGasW0() const
{
	return gas_w0;
}

void Coal::setGasW0(const double& value)
{
	this->gas_w0 = value;
}

double Coal::getGasWc2() const
{
	return gas_wc2;
}

void Coal::setGasWc2(const double& value)
{
	this->gas_wc2 = value;
}

double Coal::getGasEta() const
{
	return gas_eta;
}

void Coal::setGasEta(const double& value)
{
	this->gas_eta = value;
}

double Coal::getQR() const
{
	return q_r;
}

void Coal::setQR(const double& value)
{
	this->q_r = value;
}

double Coal::getQ0() const
{
	return q0;
}

void Coal::setQ0(const double& value)
{
	this->q0 = value;
}

int Coal::getEvalMethod() const
{
	return eval_method;
}

void Coal::setEvalMethod(const int& value)
{
	this->eval_method = value;
}

double Coal::getQ0Alpha() const
{
	return q0_alpha;
}

void Coal::setQ0Alpha(const double& value)
{
	this->q0_alpha = value;
}

double Coal::getQtAlpha() const
{
	return qt_alpha;
}

void Coal::setQtAlpha(const double& value)
{
	this->qt_alpha = value;
}

double Coal::getTAlpha() const
{
	return t_alpha;
}

void Coal::setTAlpha(const double& value)
{
	this->t_alpha = value;
}

double Coal::getQLambda() const
{
	return q_lambda;
}

void Coal::setQLambda(const double& value)
{
	this->q_lambda = value;
}

double Coal::getRLambda() const
{
	return r_lambda;
}

void Coal::setRLambda(const double& value)
{
	this->r_lambda = value;
}

double Coal::getP0Lambda() const
{
	return p0_lambda;
}

void Coal::setP0Lambda(const double& value)
{
	this->p0_lambda = value;
}

double Coal::getP1Lambda() const
{
	return p1_lambda;
}

void Coal::setP1Lambda(const double& value)
{
	this->p1_lambda = value;
}

double Coal::getTLambda() const
{
	return t_lambda;
}

void Coal::setTLambda(const double& value)
{
	this->t_lambda = value;
}

double Coal::getALambda() const
{
	return a_lambda;
}

void Coal::setALambda(const double& value)
{
	this->a_lambda = value;
}

double Coal::getP1K() const
{
	return p1_k;
}

void Coal::setP1K(const double& value)
{
	this->p1_k = value;
}

double Coal::getP2K() const
{
	return p2_k;
}

void Coal::setP2K(const double& value)
{
	this->p2_k = value;
}

double Coal::getGasQ() const
{
	return gas_q;
}

void Coal::setGasQ(const double& value)
{
	this->gas_q = value;
}

double Coal::getCoreHeight() const
{
	return core_height;
}

void Coal::setCoreHeight(const double& value)
{
	this->core_height = value;
}

double Coal::getCoreArea() const
{
	return core_area;
}

void Coal::setCoreArea(const double& value)
{
	this->core_area = value;
}

double Coal::getGasViscosity() const
{
	return gas_viscosity;
}

void Coal::setGasViscosity(const double& value)
{
	this->gas_viscosity = value;
}

double Coal::getDecayAlpha() const
{
	return decay_alpha;
}

void Coal::setDecayAlpha(const double& value)
{
	this->decay_alpha = value;
}

double Coal::getPermeabilityLambda() const
{
	return permeability_lambda;
}

void Coal::setPermeabilityLambda(const double& value)
{
	this->permeability_lambda = value;
}

double Coal::getPermeabilityK() const
{
	return permeability_k;
}

void Coal::setPermeabilityK(const double& value)
{
	this->permeability_k = value;
}

int Coal::getEvalDifficult() const
{
	return eval_difficult;
}

void Coal::setEvalDifficult(const int& value)
{
	this->eval_difficult = value;
}

CString Coal::getComment() const
{
	return comment;
}

void Coal::setComment(const CString& value)
{
	this->comment = value;
}

CString DrillingRadius::GetTableName()
{
	return _T("cbm_drilling_radius");
}

DrillingRadiusPtr DrillingRadius::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	DrillingRadiusList objList = Dao()->select<DrillingRadius>(_T("cbm_drilling_radius"), _T("*"), options);
	DrillingRadiusPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

DrillingRadiusList DrillingRadius::findAll()
{
	return Dao()->select<DrillingRadius>(_T("cbm_drilling_radius"), _T("*"), _T("order by DrillingRadius_id desc"));
}

int DrillingRadius::insert()
{
	if(coal == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool DrillingRadius::update()
{
	if(coal == 0) return false;
	return Dao()->update(*this);
}

bool DrillingRadius::remove()
{
	return Dao()->remove(*this);
}

DrillingRadius::DrillingRadius()
{
	id = 0;
	radius_r = 0.0;
	radius_l = 0.0;
	radius_k1 = 0.0;
	radius_rho = 0.0;
	radius_q0 = 0.0;
	radius_a = 0.0;
	radius_t = 0.0;
	radius_qm1 = 0.0;
	radius_qm2 = 0.0;
	radius_qsum = 0.0;
	radius_eta = 0.0;
}

DrillingRadius::DrillingRadius(int id)
{
	id = 0;
	radius_r = 0.0;
	radius_l = 0.0;
	radius_k1 = 0.0;
	radius_rho = 0.0;
	radius_q0 = 0.0;
	radius_a = 0.0;
	radius_t = 0.0;
	radius_qm1 = 0.0;
	radius_qm2 = 0.0;
	radius_qsum = 0.0;
	radius_eta = 0.0;
}

DrillingRadius::DrillingRadius(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_coal_id = rs.get<int>("cbm_coal_id", (int)0);
	if(cbm_coal_id > 0) {
		coal = CoalPtr(new Coal(cbm_coal_id));
	}
	radius_r = rs.get<double>("radius_r", (double)0);
	radius_l = rs.get<double>("radius_l", (double)0);
	radius_k1 = rs.get<double>("radius_k1", (double)0);
	radius_rho = rs.get<double>("radius_rho", (double)0);
	radius_q0 = rs.get<double>("radius_q0", (double)0);
	radius_a = rs.get<double>("radius_a", (double)0);
	radius_t = rs.get<double>("radius_t", (double)0);
	radius_qm1 = rs.get<double>("radius_qm1", (double)0);
	radius_qm2 = rs.get<double>("radius_qm2", (double)0);
	radius_qsum = rs.get<double>("radius_qsum", (double)0);
	radius_eta = rs.get<double>("radius_eta", (double)0);
}

CString DrillingRadius::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_drilling_radius values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), coal->getId());
	sql.AppendFormat(_T(", %lf"), radius_r);
	sql.AppendFormat(_T(", %lf"), radius_l);
	sql.AppendFormat(_T(", %lf"), radius_k1);
	sql.AppendFormat(_T(", %lf"), radius_rho);
	sql.AppendFormat(_T(", %lf"), radius_q0);
	sql.AppendFormat(_T(", %lf"), radius_a);
	sql.AppendFormat(_T(", %lf"), radius_t);
	sql.AppendFormat(_T(", %lf"), radius_qm1);
	sql.AppendFormat(_T(", %lf"), radius_qm2);
	sql.AppendFormat(_T(", %lf"), radius_qsum);
	sql.AppendFormat(_T(", %lf"), radius_eta);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString DrillingRadius::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_drilling_radius set"));
	sql.AppendFormat(_T("  cbm_coal_id=%d"), coal->getId());
	sql.AppendFormat(_T(", radius_r=%lf"), radius_r);
	sql.AppendFormat(_T(", radius_l=%lf"), radius_l);
	sql.AppendFormat(_T(", radius_k1=%lf"), radius_k1);
	sql.AppendFormat(_T(", radius_rho=%lf"), radius_rho);
	sql.AppendFormat(_T(", radius_q0=%lf"), radius_q0);
	sql.AppendFormat(_T(", radius_a=%lf"), radius_a);
	sql.AppendFormat(_T(", radius_t=%lf"), radius_t);
	sql.AppendFormat(_T(", radius_qm1=%lf"), radius_qm1);
	sql.AppendFormat(_T(", radius_qm2=%lf"), radius_qm2);
	sql.AppendFormat(_T(", radius_qsum=%lf"), radius_qsum);
	sql.AppendFormat(_T(", radius_eta=%lf"), radius_eta);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString DrillingRadius::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_drilling_radius where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int DrillingRadius::getId() const
{
	return id;
}

void DrillingRadius::setId(const int& value)
{
	this->id = value;
}

CoalPtr DrillingRadius::getCoal() const
{
	return coal;
}

void DrillingRadius::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

double DrillingRadius::getRadiusR() const
{
	return radius_r;
}

void DrillingRadius::setRadiusR(const double& value)
{
	this->radius_r = value;
}

double DrillingRadius::getRadiusL() const
{
	return radius_l;
}

void DrillingRadius::setRadiusL(const double& value)
{
	this->radius_l = value;
}

double DrillingRadius::getRadiusK1() const
{
	return radius_k1;
}

void DrillingRadius::setRadiusK1(const double& value)
{
	this->radius_k1 = value;
}

double DrillingRadius::getRadiusRho() const
{
	return radius_rho;
}

void DrillingRadius::setRadiusRho(const double& value)
{
	this->radius_rho = value;
}

double DrillingRadius::getRadiusQ0() const
{
	return radius_q0;
}

void DrillingRadius::setRadiusQ0(const double& value)
{
	this->radius_q0 = value;
}

double DrillingRadius::getRadiusA() const
{
	return radius_a;
}

void DrillingRadius::setRadiusA(const double& value)
{
	this->radius_a = value;
}

double DrillingRadius::getRadiusT() const
{
	return radius_t;
}

void DrillingRadius::setRadiusT(const double& value)
{
	this->radius_t = value;
}

double DrillingRadius::getRadiusQm1() const
{
	return radius_qm1;
}

void DrillingRadius::setRadiusQm1(const double& value)
{
	this->radius_qm1 = value;
}

double DrillingRadius::getRadiusQm2() const
{
	return radius_qm2;
}

void DrillingRadius::setRadiusQm2(const double& value)
{
	this->radius_qm2 = value;
}

double DrillingRadius::getRadiusQsum() const
{
	return radius_qsum;
}

void DrillingRadius::setRadiusQsum(const double& value)
{
	this->radius_qsum = value;
}

double DrillingRadius::getRadiusEta() const
{
	return radius_eta;
}

void DrillingRadius::setRadiusEta(const double& value)
{
	this->radius_eta = value;
}

CString DrillingSurf::GetTableName()
{
	return _T("cbm_drilling_surf");
}

DrillingSurfPtr DrillingSurf::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	DrillingSurfList objList = Dao()->select<DrillingSurf>(_T("cbm_drilling_surf"), _T("*"), options);
	DrillingSurfPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

DrillingSurfList DrillingSurf::findAll()
{
	return Dao()->select<DrillingSurf>(_T("cbm_drilling_surf"), _T("*"), _T("order by DrillingSurf_id desc"));
}

int DrillingSurf::insert()
{
	if(coal == 0) return 0;
	if(tunnel == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool DrillingSurf::update()
{
	if(coal == 0) return false;
	if(tunnel == 0) return false;
	return Dao()->update(*this);
}

bool DrillingSurf::remove()
{
	return Dao()->remove(*this);
}

DrillingSurf::DrillingSurf()
{
	id = 0;
	q_r = 0.0;
	q_a = 0.0;
	tw_q4 = 0.0;
	comment = _T("NULL");
}

DrillingSurf::DrillingSurf(int id)
{
	id = 0;
	q_r = 0.0;
	q_a = 0.0;
	tw_q4 = 0.0;
	comment = _T("NULL");
}

DrillingSurf::DrillingSurf(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_coal_id = rs.get<int>("cbm_coal_id", (int)0);
	if(cbm_coal_id > 0) {
		coal = CoalPtr(new Coal(cbm_coal_id));
	}
	int cbm_tunnel_id = rs.get<int>("cbm_tunnel_id", (int)0);
	if(cbm_tunnel_id > 0) {
		tunnel = TunnelPtr(new Tunnel(cbm_tunnel_id));
	}
	q_r = rs.get<double>("q_r", (double)0);
	q_a = rs.get<double>("q_a", (double)0);
	tw_q4 = rs.get<double>("tw_q4", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString DrillingSurf::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_drilling_surf values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), coal->getId());
	sql.AppendFormat(_T(", %d"), tunnel->getId());
	sql.AppendFormat(_T(", %lf"), q_r);
	sql.AppendFormat(_T(", %lf"), q_a);
	sql.AppendFormat(_T(", %lf"), tw_q4);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString DrillingSurf::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_drilling_surf set"));
	sql.AppendFormat(_T("  cbm_coal_id=%d"), coal->getId());
	sql.AppendFormat(_T(", cbm_tunnel_id=%d"), tunnel->getId());
	sql.AppendFormat(_T(", q_r=%lf"), q_r);
	sql.AppendFormat(_T(", q_a=%lf"), q_a);
	sql.AppendFormat(_T(", tw_q4=%lf"), tw_q4);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString DrillingSurf::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_drilling_surf where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int DrillingSurf::getId() const
{
	return id;
}

void DrillingSurf::setId(const int& value)
{
	this->id = value;
}

CoalPtr DrillingSurf::getCoal() const
{
	return coal;
}

void DrillingSurf::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

TunnelPtr DrillingSurf::getTunnel() const
{
	return tunnel;
}

void DrillingSurf::setTunnel(const TunnelPtr& value)
{
	this->tunnel = value;
}

double DrillingSurf::getQR() const
{
	return q_r;
}

void DrillingSurf::setQR(const double& value)
{
	this->q_r = value;
}

double DrillingSurf::getQA() const
{
	return q_a;
}

void DrillingSurf::setQA(const double& value)
{
	this->q_a = value;
}

double DrillingSurf::getTwQ4() const
{
	return tw_q4;
}

void DrillingSurf::setTwQ4(const double& value)
{
	this->tw_q4 = value;
}

CString DrillingSurf::getComment() const
{
	return comment;
}

void DrillingSurf::setComment(const CString& value)
{
	this->comment = value;
}

CString EvalUnit::GetTableName()
{
	return _T("cbm_eval_unit");
}

EvalUnitPtr EvalUnit::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	EvalUnitList objList = Dao()->select<EvalUnit>(_T("cbm_eval_unit"), _T("*"), options);
	EvalUnitPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

EvalUnitList EvalUnit::findAll()
{
	return Dao()->select<EvalUnit>(_T("cbm_eval_unit"), _T("*"), _T("order by EvalUnit_id desc"));
}

int EvalUnit::insert()
{
	if(work_surf == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool EvalUnit::update()
{
	if(work_surf == 0) return false;
	return Dao()->update(*this);
}

bool EvalUnit::remove()
{
	return Dao()->remove(*this);
}

EvalUnit::EvalUnit()
{
	id = 0;
	unit_l = 0.0;
	unit_t = 0.0;
	comment = _T("NULL");
}

EvalUnit::EvalUnit(int id)
{
	id = 0;
	unit_l = 0.0;
	unit_t = 0.0;
	comment = _T("NULL");
}

EvalUnit::EvalUnit(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_work_surf_id = rs.get<int>("cbm_work_surf_id", (int)0);
	if(cbm_work_surf_id > 0) {
		work_surf = WorkSurfPtr(new WorkSurf(cbm_work_surf_id));
	}
	unit_l = rs.get<double>("unit_l", (double)0);
	unit_t = rs.get<double>("unit_t", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString EvalUnit::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_eval_unit values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), work_surf->getId());
	sql.AppendFormat(_T(", %lf"), unit_l);
	sql.AppendFormat(_T(", %lf"), unit_t);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString EvalUnit::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_eval_unit set"));
	sql.AppendFormat(_T("  cbm_work_surf_id=%d"), work_surf->getId());
	sql.AppendFormat(_T(", unit_l=%lf"), unit_l);
	sql.AppendFormat(_T(", unit_t=%lf"), unit_t);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString EvalUnit::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_eval_unit where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int EvalUnit::getId() const
{
	return id;
}

void EvalUnit::setId(const int& value)
{
	this->id = value;
}

WorkSurfPtr EvalUnit::getWorkSurf() const
{
	return work_surf;
}

void EvalUnit::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

double EvalUnit::getUnitL() const
{
	return unit_l;
}

void EvalUnit::setUnitL(const double& value)
{
	this->unit_l = value;
}

double EvalUnit::getUnitT() const
{
	return unit_t;
}

void EvalUnit::setUnitT(const double& value)
{
	this->unit_t = value;
}

CString EvalUnit::getComment() const
{
	return comment;
}

void EvalUnit::setComment(const CString& value)
{
	this->comment = value;
}

CString Help::GetTableName()
{
	return _T("cbm_help");
}

HelpPtr Help::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	HelpList objList = Dao()->select<Help>(_T("cbm_help"), _T("*"), options);
	HelpPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

HelpList Help::findAll()
{
	return Dao()->select<Help>(_T("cbm_help"), _T("*"), _T("order by Help_id desc"));
}

int Help::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool Help::update()
{
	return Dao()->update(*this);
}

bool Help::remove()
{
	return Dao()->remove(*this);
}

Help::Help()
{
	id = 0;
	help_field = _T("NULL");
	help_type = 0;
	help_value = _T("NULL");
	comment = _T("NULL");
}

Help::Help(int id)
{
	id = 0;
	help_field = _T("NULL");
	help_type = 0;
	help_value = _T("NULL");
	comment = _T("NULL");
}

Help::Help(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	help_field = EncodeHelper::ANSIToUnicode(rs.get<std::string>("help_field", "")).c_str();
	help_type = rs.get<int>("help_type", (int)0);
	help_value = EncodeHelper::ANSIToUnicode(rs.get<std::string>("help_value", "")).c_str();
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString Help::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_help values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", '%s'"), help_field);
	sql.AppendFormat(_T(", %d"), help_type);
	sql.AppendFormat(_T(", '%s'"), help_value);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString Help::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_help set"));
	sql.AppendFormat(_T("  help_field='%s'"), help_field);
	sql.AppendFormat(_T(", help_type=%d"), help_type);
	sql.AppendFormat(_T(", help_value='%s'"), help_value);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString Help::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_help where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int Help::getId() const
{
	return id;
}

void Help::setId(const int& value)
{
	this->id = value;
}

CString Help::getHelpField() const
{
	return help_field;
}

void Help::setHelpField(const CString& value)
{
	this->help_field = value;
}

int Help::getHelpType() const
{
	return help_type;
}

void Help::setHelpType(const int& value)
{
	this->help_type = value;
}

CString Help::getHelpValue() const
{
	return help_value;
}

void Help::setHelpValue(const CString& value)
{
	this->help_value = value;
}

CString Help::getComment() const
{
	return comment;
}

void Help::setComment(const CString& value)
{
	this->comment = value;
}

CString HighDrillingPore::GetTableName()
{
	return _T("cbm_high_drilling_pore");
}

HighDrillingPorePtr HighDrillingPore::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	HighDrillingPoreList objList = Dao()->select<HighDrillingPore>(_T("cbm_high_drilling_pore"), _T("*"), options);
	HighDrillingPorePtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

HighDrillingPoreList HighDrillingPore::findAll()
{
	return Dao()->select<HighDrillingPore>(_T("cbm_high_drilling_pore"), _T("*"), _T("order by HighDrillingPore_id desc"));
}

int HighDrillingPore::insert()
{
	if(work_surf == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool HighDrillingPore::update()
{
	if(work_surf == 0) return false;
	return Dao()->update(*this);
}

bool HighDrillingPore::remove()
{
	return Dao()->remove(*this);
}

HighDrillingPore::HighDrillingPore()
{
	id = 0;
	hdp_l1 = 0.0;
	hdp_l2 = 0.0;
	hdp_lg = 0.0;
	hdp_hz = 0.0;
	hdp_lk = 0.0;
	hdp_lc = 0.0;
	hdp_lw = 0.0;
	hdp_n = 0.0;
	hdp_beta = 0.0;
	hdp_ld = 0.0;
	hdp_lzi = 0.0;
	hdp_lzj = 0.0;
	comment = _T("NULL");
}

HighDrillingPore::HighDrillingPore(int id)
{
	id = 0;
	hdp_l1 = 0.0;
	hdp_l2 = 0.0;
	hdp_lg = 0.0;
	hdp_hz = 0.0;
	hdp_lk = 0.0;
	hdp_lc = 0.0;
	hdp_lw = 0.0;
	hdp_n = 0.0;
	hdp_beta = 0.0;
	hdp_ld = 0.0;
	hdp_lzi = 0.0;
	hdp_lzj = 0.0;
	comment = _T("NULL");
}

HighDrillingPore::HighDrillingPore(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_work_surf_id = rs.get<int>("cbm_work_surf_id", (int)0);
	if(cbm_work_surf_id > 0) {
		work_surf = WorkSurfPtr(new WorkSurf(cbm_work_surf_id));
	}
	hdp_l1 = rs.get<double>("hdp_l1", (double)0);
	hdp_l2 = rs.get<double>("hdp_l2", (double)0);
	hdp_lg = rs.get<double>("hdp_lg", (double)0);
	hdp_hz = rs.get<double>("hdp_hz", (double)0);
	hdp_lk = rs.get<double>("hdp_lk", (double)0);
	hdp_lc = rs.get<double>("hdp_lc", (double)0);
	hdp_lw = rs.get<double>("hdp_lw", (double)0);
	hdp_n = rs.get<double>("hdp_n", (double)0);
	hdp_beta = rs.get<double>("hdp_beta", (double)0);
	hdp_ld = rs.get<double>("hdp_ld", (double)0);
	hdp_lzi = rs.get<double>("hdp_lzi", (double)0);
	hdp_lzj = rs.get<double>("hdp_lzj", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString HighDrillingPore::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_high_drilling_pore values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), work_surf->getId());
	sql.AppendFormat(_T(", %lf"), hdp_l1);
	sql.AppendFormat(_T(", %lf"), hdp_l2);
	sql.AppendFormat(_T(", %lf"), hdp_lg);
	sql.AppendFormat(_T(", %lf"), hdp_hz);
	sql.AppendFormat(_T(", %lf"), hdp_lk);
	sql.AppendFormat(_T(", %lf"), hdp_lc);
	sql.AppendFormat(_T(", %lf"), hdp_lw);
	sql.AppendFormat(_T(", %lf"), hdp_n);
	sql.AppendFormat(_T(", %lf"), hdp_beta);
	sql.AppendFormat(_T(", %lf"), hdp_ld);
	sql.AppendFormat(_T(", %lf"), hdp_lzi);
	sql.AppendFormat(_T(", %lf"), hdp_lzj);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString HighDrillingPore::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_high_drilling_pore set"));
	sql.AppendFormat(_T("  cbm_work_surf_id=%d"), work_surf->getId());
	sql.AppendFormat(_T(", hdp_l1=%lf"), hdp_l1);
	sql.AppendFormat(_T(", hdp_l2=%lf"), hdp_l2);
	sql.AppendFormat(_T(", hdp_lg=%lf"), hdp_lg);
	sql.AppendFormat(_T(", hdp_hz=%lf"), hdp_hz);
	sql.AppendFormat(_T(", hdp_lk=%lf"), hdp_lk);
	sql.AppendFormat(_T(", hdp_lc=%lf"), hdp_lc);
	sql.AppendFormat(_T(", hdp_lw=%lf"), hdp_lw);
	sql.AppendFormat(_T(", hdp_n=%lf"), hdp_n);
	sql.AppendFormat(_T(", hdp_beta=%lf"), hdp_beta);
	sql.AppendFormat(_T(", hdp_ld=%lf"), hdp_ld);
	sql.AppendFormat(_T(", hdp_lzi=%lf"), hdp_lzi);
	sql.AppendFormat(_T(", hdp_lzj=%lf"), hdp_lzj);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString HighDrillingPore::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_high_drilling_pore where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int HighDrillingPore::getId() const
{
	return id;
}

void HighDrillingPore::setId(const int& value)
{
	this->id = value;
}

WorkSurfPtr HighDrillingPore::getWorkSurf() const
{
	return work_surf;
}

void HighDrillingPore::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

double HighDrillingPore::getHdpL1() const
{
	return hdp_l1;
}

void HighDrillingPore::setHdpL1(const double& value)
{
	this->hdp_l1 = value;
}

double HighDrillingPore::getHdpL2() const
{
	return hdp_l2;
}

void HighDrillingPore::setHdpL2(const double& value)
{
	this->hdp_l2 = value;
}

double HighDrillingPore::getHdpLg() const
{
	return hdp_lg;
}

void HighDrillingPore::setHdpLg(const double& value)
{
	this->hdp_lg = value;
}

double HighDrillingPore::getHdpHz() const
{
	return hdp_hz;
}

void HighDrillingPore::setHdpHz(const double& value)
{
	this->hdp_hz = value;
}

double HighDrillingPore::getHdpLk() const
{
	return hdp_lk;
}

void HighDrillingPore::setHdpLk(const double& value)
{
	this->hdp_lk = value;
}

double HighDrillingPore::getHdpLc() const
{
	return hdp_lc;
}

void HighDrillingPore::setHdpLc(const double& value)
{
	this->hdp_lc = value;
}

double HighDrillingPore::getHdpLw() const
{
	return hdp_lw;
}

void HighDrillingPore::setHdpLw(const double& value)
{
	this->hdp_lw = value;
}

double HighDrillingPore::getHdpN() const
{
	return hdp_n;
}

void HighDrillingPore::setHdpN(const double& value)
{
	this->hdp_n = value;
}

double HighDrillingPore::getHdpBeta() const
{
	return hdp_beta;
}

void HighDrillingPore::setHdpBeta(const double& value)
{
	this->hdp_beta = value;
}

double HighDrillingPore::getHdpLd() const
{
	return hdp_ld;
}

void HighDrillingPore::setHdpLd(const double& value)
{
	this->hdp_ld = value;
}

double HighDrillingPore::getHdpLzi() const
{
	return hdp_lzi;
}

void HighDrillingPore::setHdpLzi(const double& value)
{
	this->hdp_lzi = value;
}

double HighDrillingPore::getHdpLzj() const
{
	return hdp_lzj;
}

void HighDrillingPore::setHdpLzj(const double& value)
{
	this->hdp_lzj = value;
}

CString HighDrillingPore::getComment() const
{
	return comment;
}

void HighDrillingPore::setComment(const CString& value)
{
	this->comment = value;
}

CString HighDrillingTunnel::GetTableName()
{
	return _T("cbm_high_drilling_tunnel");
}

HighDrillingTunnelPtr HighDrillingTunnel::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	HighDrillingTunnelList objList = Dao()->select<HighDrillingTunnel>(_T("cbm_high_drilling_tunnel"), _T("*"), options);
	HighDrillingTunnelPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

HighDrillingTunnelList HighDrillingTunnel::findAll()
{
	return Dao()->select<HighDrillingTunnel>(_T("cbm_high_drilling_tunnel"), _T("*"), _T("order by HighDrillingTunnel_id desc"));
}

int HighDrillingTunnel::insert()
{
	if(work_surf == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool HighDrillingTunnel::update()
{
	if(work_surf == 0) return false;
	return Dao()->update(*this);
}

bool HighDrillingTunnel::remove()
{
	return Dao()->remove(*this);
}

HighDrillingTunnel::HighDrillingTunnel()
{
	id = 0;
	hdt_k = 0.0;
	hdt_rock = 0;
	hdt_hz_min = 0.0;
	hdt_hz_max = 0.0;
	comment = _T("NULL");
}

HighDrillingTunnel::HighDrillingTunnel(int id)
{
	id = 0;
	hdt_k = 0.0;
	hdt_rock = 0;
	hdt_hz_min = 0.0;
	hdt_hz_max = 0.0;
	comment = _T("NULL");
}

HighDrillingTunnel::HighDrillingTunnel(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_work_surf_id = rs.get<int>("cbm_work_surf_id", (int)0);
	if(cbm_work_surf_id > 0) {
		work_surf = WorkSurfPtr(new WorkSurf(cbm_work_surf_id));
	}
	hdt_k = rs.get<double>("hdt_k", (double)0);
	hdt_rock = rs.get<int>("hdt_rock", (int)0);
	hdt_hz_min = rs.get<double>("hdt_hz_min", (double)0);
	hdt_hz_max = rs.get<double>("hdt_hz_max", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString HighDrillingTunnel::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_high_drilling_tunnel values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), work_surf->getId());
	sql.AppendFormat(_T(", %lf"), hdt_k);
	sql.AppendFormat(_T(", %d"), hdt_rock);
	sql.AppendFormat(_T(", %lf"), hdt_hz_min);
	sql.AppendFormat(_T(", %lf"), hdt_hz_max);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString HighDrillingTunnel::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_high_drilling_tunnel set"));
	sql.AppendFormat(_T("  cbm_work_surf_id=%d"), work_surf->getId());
	sql.AppendFormat(_T(", hdt_k=%lf"), hdt_k);
	sql.AppendFormat(_T(", hdt_rock=%d"), hdt_rock);
	sql.AppendFormat(_T(", hdt_hz_min=%lf"), hdt_hz_min);
	sql.AppendFormat(_T(", hdt_hz_max=%lf"), hdt_hz_max);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString HighDrillingTunnel::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_high_drilling_tunnel where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int HighDrillingTunnel::getId() const
{
	return id;
}

void HighDrillingTunnel::setId(const int& value)
{
	this->id = value;
}

WorkSurfPtr HighDrillingTunnel::getWorkSurf() const
{
	return work_surf;
}

void HighDrillingTunnel::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

double HighDrillingTunnel::getHdtK() const
{
	return hdt_k;
}

void HighDrillingTunnel::setHdtK(const double& value)
{
	this->hdt_k = value;
}

int HighDrillingTunnel::getHdtRock() const
{
	return hdt_rock;
}

void HighDrillingTunnel::setHdtRock(const int& value)
{
	this->hdt_rock = value;
}

double HighDrillingTunnel::getHdtHzMin() const
{
	return hdt_hz_min;
}

void HighDrillingTunnel::setHdtHzMin(const double& value)
{
	this->hdt_hz_min = value;
}

double HighDrillingTunnel::getHdtHzMax() const
{
	return hdt_hz_max;
}

void HighDrillingTunnel::setHdtHzMax(const double& value)
{
	this->hdt_hz_max = value;
}

CString HighDrillingTunnel::getComment() const
{
	return comment;
}

void HighDrillingTunnel::setComment(const CString& value)
{
	this->comment = value;
}

CString HydrGeo::GetTableName()
{
	return _T("cbm_hydr_geo");
}

HydrGeoPtr HydrGeo::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	HydrGeoList objList = Dao()->select<HydrGeo>(_T("cbm_hydr_geo"), _T("*"), options);
	HydrGeoPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

HydrGeoList HydrGeo::findAll()
{
	return Dao()->select<HydrGeo>(_T("cbm_hydr_geo"), _T("*"), _T("order by HydrGeo_id desc"));
}

int HydrGeo::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool HydrGeo::update()
{
	return Dao()->update(*this);
}

bool HydrGeo::remove()
{
	return Dao()->remove(*this);
}

HydrGeo::HydrGeo()
{
	id = 0;
	type = _T("NULL");
	x1 = 0;
	x2 = 0.0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = _T("NULL");
}

HydrGeo::HydrGeo(int id)
{
	id = 0;
	type = _T("NULL");
	x1 = 0;
	x2 = 0.0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = _T("NULL");
}

HydrGeo::HydrGeo(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	type = EncodeHelper::ANSIToUnicode(rs.get<std::string>("type", "")).c_str();
	x1 = rs.get<int>("x1", (int)0);
	x2 = rs.get<double>("x2", (double)0);
	x3 = rs.get<int>("x3", (int)0);
	x4 = rs.get<double>("x4", (double)0);
	x5 = rs.get<double>("x5", (double)0);
	x6 = rs.get<double>("x6", (double)0);
	x7 = rs.get<double>("x7", (double)0);
	x8 = EncodeHelper::ANSIToUnicode(rs.get<std::string>("x8", "")).c_str();
}

CString HydrGeo::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_hydr_geo values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", '%s'"), type);
	sql.AppendFormat(_T(", %d"), x1);
	sql.AppendFormat(_T(", %lf"), x2);
	sql.AppendFormat(_T(", %d"), x3);
	sql.AppendFormat(_T(", %lf"), x4);
	sql.AppendFormat(_T(", %lf"), x5);
	sql.AppendFormat(_T(", %lf"), x6);
	sql.AppendFormat(_T(", %lf"), x7);
	sql.AppendFormat(_T(", '%s'"), x8);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString HydrGeo::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_hydr_geo set"));
	sql.AppendFormat(_T("  type='%s'"), type);
	sql.AppendFormat(_T(", x1=%d"), x1);
	sql.AppendFormat(_T(", x2=%lf"), x2);
	sql.AppendFormat(_T(", x3=%d"), x3);
	sql.AppendFormat(_T(", x4=%lf"), x4);
	sql.AppendFormat(_T(", x5=%lf"), x5);
	sql.AppendFormat(_T(", x6=%lf"), x6);
	sql.AppendFormat(_T(", x7=%lf"), x7);
	sql.AppendFormat(_T(", x8='%s'"), x8);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString HydrGeo::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_hydr_geo where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int HydrGeo::getId() const
{
	return id;
}

void HydrGeo::setId(const int& value)
{
	this->id = value;
}

CString HydrGeo::getType() const
{
	return type;
}

void HydrGeo::setType(const CString& value)
{
	this->type = value;
}

int HydrGeo::getX1() const
{
	return x1;
}

void HydrGeo::setX1(const int& value)
{
	this->x1 = value;
}

double HydrGeo::getX2() const
{
	return x2;
}

void HydrGeo::setX2(const double& value)
{
	this->x2 = value;
}

int HydrGeo::getX3() const
{
	return x3;
}

void HydrGeo::setX3(const int& value)
{
	this->x3 = value;
}

double HydrGeo::getX4() const
{
	return x4;
}

void HydrGeo::setX4(const double& value)
{
	this->x4 = value;
}

double HydrGeo::getX5() const
{
	return x5;
}

void HydrGeo::setX5(const double& value)
{
	this->x5 = value;
}

double HydrGeo::getX6() const
{
	return x6;
}

void HydrGeo::setX6(const double& value)
{
	this->x6 = value;
}

double HydrGeo::getX7() const
{
	return x7;
}

void HydrGeo::setX7(const double& value)
{
	this->x7 = value;
}

CString HydrGeo::getX8() const
{
	return x8;
}

void HydrGeo::setX8(const CString& value)
{
	this->x8 = value;
}

CString KeyLayer::GetTableName()
{
	return _T("cbm_key_layer");
}

KeyLayerPtr KeyLayer::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	KeyLayerList objList = Dao()->select<KeyLayer>(_T("cbm_key_layer"), _T("*"), options);
	KeyLayerPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

KeyLayerList KeyLayer::findAll()
{
	return Dao()->select<KeyLayer>(_T("cbm_key_layer"), _T("*"), _T("order by KeyLayer_id desc"));
}

int KeyLayer::insert()
{
	if(high_drilling_pore == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool KeyLayer::update()
{
	if(high_drilling_pore == 0) return false;
	return Dao()->update(*this);
}

bool KeyLayer::remove()
{
	return Dao()->remove(*this);
}

KeyLayer::KeyLayer()
{
	id = 0;
	key_hn = 0.0;
	key_thetan = 0.0;
	key_qn = 0.0;
	key_rtn = 0.0;
	key_sum_hn = 0.0;
	comment = _T("NULL");
}

KeyLayer::KeyLayer(int id)
{
	id = 0;
	key_hn = 0.0;
	key_thetan = 0.0;
	key_qn = 0.0;
	key_rtn = 0.0;
	key_sum_hn = 0.0;
	comment = _T("NULL");
}

KeyLayer::KeyLayer(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_high_drilling_pore_id = rs.get<int>("cbm_high_drilling_pore_id", (int)0);
	if(cbm_high_drilling_pore_id > 0) {
		high_drilling_pore = HighDrillingPorePtr(new HighDrillingPore(cbm_high_drilling_pore_id));
	}
	key_hn = rs.get<double>("key_hn", (double)0);
	key_thetan = rs.get<double>("key_thetan", (double)0);
	key_qn = rs.get<double>("key_qn", (double)0);
	key_rtn = rs.get<double>("key_rtn", (double)0);
	key_sum_hn = rs.get<double>("key_sum_hn", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString KeyLayer::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_key_layer values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), high_drilling_pore->getId());
	sql.AppendFormat(_T(", %lf"), key_hn);
	sql.AppendFormat(_T(", %lf"), key_thetan);
	sql.AppendFormat(_T(", %lf"), key_qn);
	sql.AppendFormat(_T(", %lf"), key_rtn);
	sql.AppendFormat(_T(", %lf"), key_sum_hn);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString KeyLayer::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_key_layer set"));
	sql.AppendFormat(_T("  cbm_high_drilling_pore_id=%d"), high_drilling_pore->getId());
	sql.AppendFormat(_T(", key_hn=%lf"), key_hn);
	sql.AppendFormat(_T(", key_thetan=%lf"), key_thetan);
	sql.AppendFormat(_T(", key_qn=%lf"), key_qn);
	sql.AppendFormat(_T(", key_rtn=%lf"), key_rtn);
	sql.AppendFormat(_T(", key_sum_hn=%lf"), key_sum_hn);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString KeyLayer::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_key_layer where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int KeyLayer::getId() const
{
	return id;
}

void KeyLayer::setId(const int& value)
{
	this->id = value;
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

CString KeyLayer::getComment() const
{
	return comment;
}

void KeyLayer::setComment(const CString& value)
{
	this->comment = value;
}

CString Mine::GetTableName()
{
	return _T("cbm_mine");
}

MinePtr Mine::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	MineList objList = Dao()->select<Mine>(_T("cbm_mine"), _T("*"), options);
	MinePtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

MineList Mine::findAll()
{
	return Dao()->select<Mine>(_T("cbm_mine"), _T("*"), _T("order by Mine_id desc"));
}

int Mine::insert()
{
	if(mine_region == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool Mine::update()
{
	if(mine_region == 0) return false;
	return Dao()->update(*this);
}

bool Mine::remove()
{
	return Dao()->remove(*this);
}

Mine::Mine()
{
	id = 0;
	username = _T("NULL");
	password = _T("NULL");
	mine_name = _T("NULL");
	mine_address = _T("NULL");
	coal_capacity = 0.0;
	topo_geo = 0;
	hydr_geo = 0;
	ground_condition = 0;
	q_r = 0.0;
	stereo_schem_diagram = _T("NULL");
	k_gas = 0.0;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	reserve_gas = 0.0;
	pump_kd = 0.0;
	pump_k1 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_wc = 0.0;
	comment = _T("NULL");
}

Mine::Mine(int id)
{
	id = 0;
	username = _T("NULL");
	password = _T("NULL");
	mine_name = _T("NULL");
	mine_address = _T("NULL");
	coal_capacity = 0.0;
	topo_geo = 0;
	hydr_geo = 0;
	ground_condition = 0;
	q_r = 0.0;
	stereo_schem_diagram = _T("NULL");
	k_gas = 0.0;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	reserve_gas = 0.0;
	pump_kd = 0.0;
	pump_k1 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_wc = 0.0;
	comment = _T("NULL");
}

Mine::Mine(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_mine_region_id = rs.get<int>("cbm_mine_region_id", (int)0);
	if(cbm_mine_region_id > 0) {
		mine_region = MineRegionPtr(new MineRegion(cbm_mine_region_id));
	}
	username = EncodeHelper::ANSIToUnicode(rs.get<std::string>("username", "")).c_str();
	password = EncodeHelper::ANSIToUnicode(rs.get<std::string>("password", "")).c_str();
	mine_name = EncodeHelper::ANSIToUnicode(rs.get<std::string>("mine_name", "")).c_str();
	mine_address = EncodeHelper::ANSIToUnicode(rs.get<std::string>("mine_address", "")).c_str();
	coal_capacity = rs.get<double>("coal_capacity", (double)0);
	topo_geo = rs.get<int>("topo_geo", (int)0);
	hydr_geo = rs.get<int>("hydr_geo", (int)0);
	ground_condition = rs.get<int>("ground_condition", (int)0);
	q_r = rs.get<double>("q_r", (double)0);
	stereo_schem_diagram = EncodeHelper::ANSIToUnicode(rs.get<std::string>("stereo_schem_diagram", "")).c_str();
	k_gas = rs.get<double>("k_gas", (double)0);
	reserve_w1 = rs.get<double>("reserve_w1", (double)0);
	reserve_w2 = rs.get<double>("reserve_w2", (double)0);
	reserve_w3 = rs.get<double>("reserve_w3", (double)0);
	reserve_gas = rs.get<double>("reserve_gas", (double)0);
	pump_kd = rs.get<double>("pump_kd", (double)0);
	pump_k1 = rs.get<double>("pump_k1", (double)0);
	pump_k2 = rs.get<double>("pump_k2", (double)0);
	pump_k3 = rs.get<double>("pump_k3", (double)0);
	pump_k4 = rs.get<double>("pump_k4", (double)0);
	pump_wc = rs.get<double>("pump_wc", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString Mine::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_mine values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), mine_region->getId());
	sql.AppendFormat(_T(", '%s'"), username);
	sql.AppendFormat(_T(", '%s'"), password);
	sql.AppendFormat(_T(", '%s'"), mine_name);
	sql.AppendFormat(_T(", '%s'"), mine_address);
	sql.AppendFormat(_T(", %lf"), coal_capacity);
	sql.AppendFormat(_T(", %d"), topo_geo);
	sql.AppendFormat(_T(", %d"), hydr_geo);
	sql.AppendFormat(_T(", %d"), ground_condition);
	sql.AppendFormat(_T(", %lf"), q_r);
	sql.AppendFormat(_T(", '%s'"), stereo_schem_diagram);
	sql.AppendFormat(_T(", %lf"), k_gas);
	sql.AppendFormat(_T(", %lf"), reserve_w1);
	sql.AppendFormat(_T(", %lf"), reserve_w2);
	sql.AppendFormat(_T(", %lf"), reserve_w3);
	sql.AppendFormat(_T(", %lf"), reserve_gas);
	sql.AppendFormat(_T(", %lf"), pump_kd);
	sql.AppendFormat(_T(", %lf"), pump_k1);
	sql.AppendFormat(_T(", %lf"), pump_k2);
	sql.AppendFormat(_T(", %lf"), pump_k3);
	sql.AppendFormat(_T(", %lf"), pump_k4);
	sql.AppendFormat(_T(", %lf"), pump_wc);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString Mine::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_mine set"));
	sql.AppendFormat(_T("  cbm_mine_region_id=%d"), mine_region->getId());
	sql.AppendFormat(_T(", username='%s'"), username);
	sql.AppendFormat(_T(", password='%s'"), password);
	sql.AppendFormat(_T(", mine_name='%s'"), mine_name);
	sql.AppendFormat(_T(", mine_address='%s'"), mine_address);
	sql.AppendFormat(_T(", coal_capacity=%lf"), coal_capacity);
	sql.AppendFormat(_T(", topo_geo=%d"), topo_geo);
	sql.AppendFormat(_T(", hydr_geo=%d"), hydr_geo);
	sql.AppendFormat(_T(", ground_condition=%d"), ground_condition);
	sql.AppendFormat(_T(", q_r=%lf"), q_r);
	sql.AppendFormat(_T(", stereo_schem_diagram='%s'"), stereo_schem_diagram);
	sql.AppendFormat(_T(", k_gas=%lf"), k_gas);
	sql.AppendFormat(_T(", reserve_w1=%lf"), reserve_w1);
	sql.AppendFormat(_T(", reserve_w2=%lf"), reserve_w2);
	sql.AppendFormat(_T(", reserve_w3=%lf"), reserve_w3);
	sql.AppendFormat(_T(", reserve_gas=%lf"), reserve_gas);
	sql.AppendFormat(_T(", pump_kd=%lf"), pump_kd);
	sql.AppendFormat(_T(", pump_k1=%lf"), pump_k1);
	sql.AppendFormat(_T(", pump_k2=%lf"), pump_k2);
	sql.AppendFormat(_T(", pump_k3=%lf"), pump_k3);
	sql.AppendFormat(_T(", pump_k4=%lf"), pump_k4);
	sql.AppendFormat(_T(", pump_wc=%lf"), pump_wc);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString Mine::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_mine where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int Mine::getId() const
{
	return id;
}

void Mine::setId(const int& value)
{
	this->id = value;
}

MineRegionPtr Mine::getMineRegion() const
{
	return mine_region;
}

void Mine::setMineRegion(const MineRegionPtr& value)
{
	this->mine_region = value;
}

CString Mine::getUsername() const
{
	return username;
}

void Mine::setUsername(const CString& value)
{
	this->username = value;
}

CString Mine::getPassword() const
{
	return password;
}

void Mine::setPassword(const CString& value)
{
	this->password = value;
}

CString Mine::getMineName() const
{
	return mine_name;
}

void Mine::setMineName(const CString& value)
{
	this->mine_name = value;
}

CString Mine::getMineAddress() const
{
	return mine_address;
}

void Mine::setMineAddress(const CString& value)
{
	this->mine_address = value;
}

double Mine::getCoalCapacity() const
{
	return coal_capacity;
}

void Mine::setCoalCapacity(const double& value)
{
	this->coal_capacity = value;
}

int Mine::getTopoGeo() const
{
	return topo_geo;
}

void Mine::setTopoGeo(const int& value)
{
	this->topo_geo = value;
}

int Mine::getHydrGeo() const
{
	return hydr_geo;
}

void Mine::setHydrGeo(const int& value)
{
	this->hydr_geo = value;
}

int Mine::getGroundCondition() const
{
	return ground_condition;
}

void Mine::setGroundCondition(const int& value)
{
	this->ground_condition = value;
}

double Mine::getQR() const
{
	return q_r;
}

void Mine::setQR(const double& value)
{
	this->q_r = value;
}

CString Mine::getStereoSchemDiagram() const
{
	return stereo_schem_diagram;
}

void Mine::setStereoSchemDiagram(const CString& value)
{
	this->stereo_schem_diagram = value;
}

double Mine::getKGas() const
{
	return k_gas;
}

void Mine::setKGas(const double& value)
{
	this->k_gas = value;
}

double Mine::getReserveW1() const
{
	return reserve_w1;
}

void Mine::setReserveW1(const double& value)
{
	this->reserve_w1 = value;
}

double Mine::getReserveW2() const
{
	return reserve_w2;
}

void Mine::setReserveW2(const double& value)
{
	this->reserve_w2 = value;
}

double Mine::getReserveW3() const
{
	return reserve_w3;
}

void Mine::setReserveW3(const double& value)
{
	this->reserve_w3 = value;
}

double Mine::getReserveGas() const
{
	return reserve_gas;
}

void Mine::setReserveGas(const double& value)
{
	this->reserve_gas = value;
}

double Mine::getPumpKd() const
{
	return pump_kd;
}

void Mine::setPumpKd(const double& value)
{
	this->pump_kd = value;
}

double Mine::getPumpK1() const
{
	return pump_k1;
}

void Mine::setPumpK1(const double& value)
{
	this->pump_k1 = value;
}

double Mine::getPumpK2() const
{
	return pump_k2;
}

void Mine::setPumpK2(const double& value)
{
	this->pump_k2 = value;
}

double Mine::getPumpK3() const
{
	return pump_k3;
}

void Mine::setPumpK3(const double& value)
{
	this->pump_k3 = value;
}

double Mine::getPumpK4() const
{
	return pump_k4;
}

void Mine::setPumpK4(const double& value)
{
	this->pump_k4 = value;
}

double Mine::getPumpWc() const
{
	return pump_wc;
}

void Mine::setPumpWc(const double& value)
{
	this->pump_wc = value;
}

CString Mine::getComment() const
{
	return comment;
}

void Mine::setComment(const CString& value)
{
	this->comment = value;
}

CString MineBase::GetTableName()
{
	return _T("cbm_mine_base");
}

MineBasePtr MineBase::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	MineBaseList objList = Dao()->select<MineBase>(_T("cbm_mine_base"), _T("*"), options);
	MineBasePtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

MineBaseList MineBase::findAll()
{
	return Dao()->select<MineBase>(_T("cbm_mine_base"), _T("*"), _T("order by MineBase_id desc"));
}

int MineBase::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool MineBase::update()
{
	return Dao()->update(*this);
}

bool MineBase::remove()
{
	return Dao()->remove(*this);
}

MineBase::MineBase()
{
	id = 0;
	name = _T("NULL");
	comment = _T("NULL");
}

MineBase::MineBase(int id)
{
	id = 0;
	name = _T("NULL");
	comment = _T("NULL");
}

MineBase::MineBase(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	name = EncodeHelper::ANSIToUnicode(rs.get<std::string>("name", "")).c_str();
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString MineBase::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_mine_base values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", '%s'"), name);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString MineBase::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_mine_base set"));
	sql.AppendFormat(_T("  name='%s'"), name);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString MineBase::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_mine_base where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int MineBase::getId() const
{
	return id;
}

void MineBase::setId(const int& value)
{
	this->id = value;
}

CString MineBase::getName() const
{
	return name;
}

void MineBase::setName(const CString& value)
{
	this->name = value;
}

CString MineBase::getComment() const
{
	return comment;
}

void MineBase::setComment(const CString& value)
{
	this->comment = value;
}

CString MineRegion::GetTableName()
{
	return _T("cbm_mine_region");
}

MineRegionPtr MineRegion::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	MineRegionList objList = Dao()->select<MineRegion>(_T("cbm_mine_region"), _T("*"), options);
	MineRegionPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

MineRegionList MineRegion::findAll()
{
	return Dao()->select<MineRegion>(_T("cbm_mine_region"), _T("*"), _T("order by MineRegion_id desc"));
}

int MineRegion::insert()
{
	if(mine_base == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool MineRegion::update()
{
	if(mine_base == 0) return false;
	return Dao()->update(*this);
}

bool MineRegion::remove()
{
	return Dao()->remove(*this);
}

MineRegion::MineRegion()
{
	id = 0;
	name = _T("NULL");
	comment = _T("NULL");
}

MineRegion::MineRegion(int id)
{
	id = 0;
	name = _T("NULL");
	comment = _T("NULL");
}

MineRegion::MineRegion(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_mine_base_id = rs.get<int>("cbm_mine_base_id", (int)0);
	if(cbm_mine_base_id > 0) {
		mine_base = MineBasePtr(new MineBase(cbm_mine_base_id));
	}
	name = EncodeHelper::ANSIToUnicode(rs.get<std::string>("name", "")).c_str();
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString MineRegion::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_mine_region values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), mine_base->getId());
	sql.AppendFormat(_T(", '%s'"), name);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString MineRegion::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_mine_region set"));
	sql.AppendFormat(_T("  cbm_mine_base_id=%d"), mine_base->getId());
	sql.AppendFormat(_T(", name='%s'"), name);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString MineRegion::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_mine_region where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int MineRegion::getId() const
{
	return id;
}

void MineRegion::setId(const int& value)
{
	this->id = value;
}

MineBasePtr MineRegion::getMineBase() const
{
	return mine_base;
}

void MineRegion::setMineBase(const MineBasePtr& value)
{
	this->mine_base = value;
}

CString MineRegion::getName() const
{
	return name;
}

void MineRegion::setName(const CString& value)
{
	this->name = value;
}

CString MineRegion::getComment() const
{
	return comment;
}

void MineRegion::setComment(const CString& value)
{
	this->comment = value;
}

CString MiningArea::GetTableName()
{
	return _T("cbm_mining_area");
}

MiningAreaPtr MiningArea::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	MiningAreaList objList = Dao()->select<MiningArea>(_T("cbm_mining_area"), _T("*"), options);
	MiningAreaPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

MiningAreaList MiningArea::findAll()
{
	return Dao()->select<MiningArea>(_T("cbm_mining_area"), _T("*"), _T("order by MiningArea_id desc"));
}

int MiningArea::insert()
{
	if(coal == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool MiningArea::update()
{
	if(coal == 0) return false;
	return Dao()->update(*this);
}

bool MiningArea::remove()
{
	return Dao()->remove(*this);
}

MiningArea::MiningArea()
{
	id = 0;
	area_mode = 0;
	area_k = 0.0;
	a = 0.0;
	q_r = 0.0;
	comment = _T("NULL");
}

MiningArea::MiningArea(int id)
{
	id = 0;
	area_mode = 0;
	area_k = 0.0;
	a = 0.0;
	q_r = 0.0;
	comment = _T("NULL");
}

MiningArea::MiningArea(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_coal_id = rs.get<int>("cbm_coal_id", (int)0);
	if(cbm_coal_id > 0) {
		coal = CoalPtr(new Coal(cbm_coal_id));
	}
	area_mode = rs.get<int>("area_mode", (int)0);
	area_k = rs.get<double>("area_k", (double)0);
	a = rs.get<double>("a", (double)0);
	q_r = rs.get<double>("q_r", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString MiningArea::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_mining_area values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), coal->getId());
	sql.AppendFormat(_T(", %d"), area_mode);
	sql.AppendFormat(_T(", %lf"), area_k);
	sql.AppendFormat(_T(", %lf"), a);
	sql.AppendFormat(_T(", %lf"), q_r);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString MiningArea::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_mining_area set"));
	sql.AppendFormat(_T("  cbm_coal_id=%d"), coal->getId());
	sql.AppendFormat(_T(", area_mode=%d"), area_mode);
	sql.AppendFormat(_T(", area_k=%lf"), area_k);
	sql.AppendFormat(_T(", a=%lf"), a);
	sql.AppendFormat(_T(", q_r=%lf"), q_r);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString MiningArea::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_mining_area where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int MiningArea::getId() const
{
	return id;
}

void MiningArea::setId(const int& value)
{
	this->id = value;
}

CoalPtr MiningArea::getCoal() const
{
	return coal;
}

void MiningArea::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

int MiningArea::getAreaMode() const
{
	return area_mode;
}

void MiningArea::setAreaMode(const int& value)
{
	this->area_mode = value;
}

double MiningArea::getAreaK() const
{
	return area_k;
}

void MiningArea::setAreaK(const double& value)
{
	this->area_k = value;
}

double MiningArea::getA() const
{
	return a;
}

void MiningArea::setA(const double& value)
{
	this->a = value;
}

double MiningArea::getQR() const
{
	return q_r;
}

void MiningArea::setQR(const double& value)
{
	this->q_r = value;
}

CString MiningArea::getComment() const
{
	return comment;
}

void MiningArea::setComment(const CString& value)
{
	this->comment = value;
}

CString PoreFlow::GetTableName()
{
	return _T("cbm_pore_flow");
}

PoreFlowPtr PoreFlow::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	PoreFlowList objList = Dao()->select<PoreFlow>(_T("cbm_pore_flow"), _T("*"), options);
	PoreFlowPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

PoreFlowList PoreFlow::findAll()
{
	return Dao()->select<PoreFlow>(_T("cbm_pore_flow"), _T("*"), _T("order by PoreFlow_id desc"));
}

int PoreFlow::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool PoreFlow::update()
{
	return Dao()->update(*this);
}

bool PoreFlow::remove()
{
	return Dao()->remove(*this);
}

PoreFlow::PoreFlow()
{
	id = 0;
	flow_t = 0.0;
	flow_a0 = 0.0;
	flow_d = 0.0;
	flow_d1 = 0.0;
	flow_m = 0.0;
	flow_k = 0.0;
	flow_delta_t = 0.0;
	flow_x = 0.0;
	flow_p_test = 0.0;
	flow_p_cur = 0.0;
	flow_b = 0.0;
	flow_pt = 0.0;
	flow_delta_p = 0.0;
	flow_dh = 0.0;
	flow_q_hun = 0.0;
	flow_q_chun = 0.0;
}

PoreFlow::PoreFlow(int id)
{
	id = 0;
	flow_t = 0.0;
	flow_a0 = 0.0;
	flow_d = 0.0;
	flow_d1 = 0.0;
	flow_m = 0.0;
	flow_k = 0.0;
	flow_delta_t = 0.0;
	flow_x = 0.0;
	flow_p_test = 0.0;
	flow_p_cur = 0.0;
	flow_b = 0.0;
	flow_pt = 0.0;
	flow_delta_p = 0.0;
	flow_dh = 0.0;
	flow_q_hun = 0.0;
	flow_q_chun = 0.0;
}

PoreFlow::PoreFlow(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	flow_t = rs.get<double>("flow_t", (double)0);
	flow_a0 = rs.get<double>("flow_a0", (double)0);
	flow_d = rs.get<double>("flow_d", (double)0);
	flow_d1 = rs.get<double>("flow_d1", (double)0);
	flow_m = rs.get<double>("flow_m", (double)0);
	flow_k = rs.get<double>("flow_k", (double)0);
	flow_delta_t = rs.get<double>("flow_delta_t", (double)0);
	flow_x = rs.get<double>("flow_x", (double)0);
	flow_p_test = rs.get<double>("flow_p_test", (double)0);
	flow_p_cur = rs.get<double>("flow_p_cur", (double)0);
	flow_b = rs.get<double>("flow_b", (double)0);
	flow_pt = rs.get<double>("flow_pt", (double)0);
	flow_delta_p = rs.get<double>("flow_delta_p", (double)0);
	flow_dh = rs.get<double>("flow_dh", (double)0);
	flow_q_hun = rs.get<double>("flow_q_hun", (double)0);
	flow_q_chun = rs.get<double>("flow_q_chun", (double)0);
}

CString PoreFlow::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_pore_flow values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %lf"), flow_t);
	sql.AppendFormat(_T(", %lf"), flow_a0);
	sql.AppendFormat(_T(", %lf"), flow_d);
	sql.AppendFormat(_T(", %lf"), flow_d1);
	sql.AppendFormat(_T(", %lf"), flow_m);
	sql.AppendFormat(_T(", %lf"), flow_k);
	sql.AppendFormat(_T(", %lf"), flow_delta_t);
	sql.AppendFormat(_T(", %lf"), flow_x);
	sql.AppendFormat(_T(", %lf"), flow_p_test);
	sql.AppendFormat(_T(", %lf"), flow_p_cur);
	sql.AppendFormat(_T(", %lf"), flow_b);
	sql.AppendFormat(_T(", %lf"), flow_pt);
	sql.AppendFormat(_T(", %lf"), flow_delta_p);
	sql.AppendFormat(_T(", %lf"), flow_dh);
	sql.AppendFormat(_T(", %lf"), flow_q_hun);
	sql.AppendFormat(_T(", %lf"), flow_q_chun);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString PoreFlow::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_pore_flow set"));
	sql.AppendFormat(_T("  flow_t=%lf"), flow_t);
	sql.AppendFormat(_T(", flow_a0=%lf"), flow_a0);
	sql.AppendFormat(_T(", flow_d=%lf"), flow_d);
	sql.AppendFormat(_T(", flow_d1=%lf"), flow_d1);
	sql.AppendFormat(_T(", flow_m=%lf"), flow_m);
	sql.AppendFormat(_T(", flow_k=%lf"), flow_k);
	sql.AppendFormat(_T(", flow_delta_t=%lf"), flow_delta_t);
	sql.AppendFormat(_T(", flow_x=%lf"), flow_x);
	sql.AppendFormat(_T(", flow_p_test=%lf"), flow_p_test);
	sql.AppendFormat(_T(", flow_p_cur=%lf"), flow_p_cur);
	sql.AppendFormat(_T(", flow_b=%lf"), flow_b);
	sql.AppendFormat(_T(", flow_pt=%lf"), flow_pt);
	sql.AppendFormat(_T(", flow_delta_p=%lf"), flow_delta_p);
	sql.AppendFormat(_T(", flow_dh=%lf"), flow_dh);
	sql.AppendFormat(_T(", flow_q_hun=%lf"), flow_q_hun);
	sql.AppendFormat(_T(", flow_q_chun=%lf"), flow_q_chun);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString PoreFlow::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_pore_flow where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int PoreFlow::getId() const
{
	return id;
}

void PoreFlow::setId(const int& value)
{
	this->id = value;
}

double PoreFlow::getFlowT() const
{
	return flow_t;
}

void PoreFlow::setFlowT(const double& value)
{
	this->flow_t = value;
}

double PoreFlow::getFlowA0() const
{
	return flow_a0;
}

void PoreFlow::setFlowA0(const double& value)
{
	this->flow_a0 = value;
}

double PoreFlow::getFlowD() const
{
	return flow_d;
}

void PoreFlow::setFlowD(const double& value)
{
	this->flow_d = value;
}

double PoreFlow::getFlowD1() const
{
	return flow_d1;
}

void PoreFlow::setFlowD1(const double& value)
{
	this->flow_d1 = value;
}

double PoreFlow::getFlowM() const
{
	return flow_m;
}

void PoreFlow::setFlowM(const double& value)
{
	this->flow_m = value;
}

double PoreFlow::getFlowK() const
{
	return flow_k;
}

void PoreFlow::setFlowK(const double& value)
{
	this->flow_k = value;
}

double PoreFlow::getFlowDeltaT() const
{
	return flow_delta_t;
}

void PoreFlow::setFlowDeltaT(const double& value)
{
	this->flow_delta_t = value;
}

double PoreFlow::getFlowX() const
{
	return flow_x;
}

void PoreFlow::setFlowX(const double& value)
{
	this->flow_x = value;
}

double PoreFlow::getFlowPTest() const
{
	return flow_p_test;
}

void PoreFlow::setFlowPTest(const double& value)
{
	this->flow_p_test = value;
}

double PoreFlow::getFlowPCur() const
{
	return flow_p_cur;
}

void PoreFlow::setFlowPCur(const double& value)
{
	this->flow_p_cur = value;
}

double PoreFlow::getFlowB() const
{
	return flow_b;
}

void PoreFlow::setFlowB(const double& value)
{
	this->flow_b = value;
}

double PoreFlow::getFlowPt() const
{
	return flow_pt;
}

void PoreFlow::setFlowPt(const double& value)
{
	this->flow_pt = value;
}

double PoreFlow::getFlowDeltaP() const
{
	return flow_delta_p;
}

void PoreFlow::setFlowDeltaP(const double& value)
{
	this->flow_delta_p = value;
}

double PoreFlow::getFlowDh() const
{
	return flow_dh;
}

void PoreFlow::setFlowDh(const double& value)
{
	this->flow_dh = value;
}

double PoreFlow::getFlowQHun() const
{
	return flow_q_hun;
}

void PoreFlow::setFlowQHun(const double& value)
{
	this->flow_q_hun = value;
}

double PoreFlow::getFlowQChun() const
{
	return flow_q_chun;
}

void PoreFlow::setFlowQChun(const double& value)
{
	this->flow_q_chun = value;
}

CString PoreSize::GetTableName()
{
	return _T("cbm_pore_size");
}

PoreSizePtr PoreSize::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	PoreSizeList objList = Dao()->select<PoreSize>(_T("cbm_pore_size"), _T("*"), options);
	PoreSizePtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

PoreSizeList PoreSize::findAll()
{
	return Dao()->select<PoreSize>(_T("cbm_pore_size"), _T("*"), _T("order by PoreSize_id desc"));
}

int PoreSize::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool PoreSize::update()
{
	return Dao()->update(*this);
}

bool PoreSize::remove()
{
	return Dao()->remove(*this);
}

PoreSize::PoreSize()
{
	id = 0;
	size_q = 0.0;
	size_v = 0.0;
	size_d = 0.0;
	size_p = 0.0;
	size_sigma = 0.0;
	size_delta = 0.0;
}

PoreSize::PoreSize(int id)
{
	id = 0;
	size_q = 0.0;
	size_v = 0.0;
	size_d = 0.0;
	size_p = 0.0;
	size_sigma = 0.0;
	size_delta = 0.0;
}

PoreSize::PoreSize(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	size_q = rs.get<double>("size_q", (double)0);
	size_v = rs.get<double>("size_v", (double)0);
	size_d = rs.get<double>("size_d", (double)0);
	size_p = rs.get<double>("size_p", (double)0);
	size_sigma = rs.get<double>("size_sigma", (double)0);
	size_delta = rs.get<double>("size_delta", (double)0);
}

CString PoreSize::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_pore_size values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %lf"), size_q);
	sql.AppendFormat(_T(", %lf"), size_v);
	sql.AppendFormat(_T(", %lf"), size_d);
	sql.AppendFormat(_T(", %lf"), size_p);
	sql.AppendFormat(_T(", %lf"), size_sigma);
	sql.AppendFormat(_T(", %lf"), size_delta);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString PoreSize::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_pore_size set"));
	sql.AppendFormat(_T("  size_q=%lf"), size_q);
	sql.AppendFormat(_T(", size_v=%lf"), size_v);
	sql.AppendFormat(_T(", size_d=%lf"), size_d);
	sql.AppendFormat(_T(", size_p=%lf"), size_p);
	sql.AppendFormat(_T(", size_sigma=%lf"), size_sigma);
	sql.AppendFormat(_T(", size_delta=%lf"), size_delta);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString PoreSize::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_pore_size where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int PoreSize::getId() const
{
	return id;
}

void PoreSize::setId(const int& value)
{
	this->id = value;
}

double PoreSize::getSizeQ() const
{
	return size_q;
}

void PoreSize::setSizeQ(const double& value)
{
	this->size_q = value;
}

double PoreSize::getSizeV() const
{
	return size_v;
}

void PoreSize::setSizeV(const double& value)
{
	this->size_v = value;
}

double PoreSize::getSizeD() const
{
	return size_d;
}

void PoreSize::setSizeD(const double& value)
{
	this->size_d = value;
}

double PoreSize::getSizeP() const
{
	return size_p;
}

void PoreSize::setSizeP(const double& value)
{
	this->size_p = value;
}

double PoreSize::getSizeSigma() const
{
	return size_sigma;
}

void PoreSize::setSizeSigma(const double& value)
{
	this->size_sigma = value;
}

double PoreSize::getSizeDelta() const
{
	return size_delta;
}

void PoreSize::setSizeDelta(const double& value)
{
	this->size_delta = value;
}

CString ReadyTunnel::GetTableName()
{
	return _T("cbm_ready_tunnel");
}

ReadyTunnelPtr ReadyTunnel::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	ReadyTunnelList objList = Dao()->select<ReadyTunnel>(_T("cbm_ready_tunnel"), _T("*"), options);
	ReadyTunnelPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

ReadyTunnelList ReadyTunnel::findAll()
{
	return Dao()->select<ReadyTunnel>(_T("cbm_ready_tunnel"), _T("*"), _T("order by ReadyTunnel_id desc"));
}

int ReadyTunnel::insert()
{
	if(mining_area == 0) return 0;
	if(tunnel == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool ReadyTunnel::update()
{
	if(mining_area == 0) return false;
	if(tunnel == 0) return false;
	return Dao()->update(*this);
}

bool ReadyTunnel::remove()
{
	return Dao()->remove(*this);
}

ReadyTunnel::ReadyTunnel()
{
	id = 0;
	comment = _T("NULL");
}

ReadyTunnel::ReadyTunnel(int id)
{
	id = 0;
	comment = _T("NULL");
}

ReadyTunnel::ReadyTunnel(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_mining_area_id = rs.get<int>("cbm_mining_area_id", (int)0);
	if(cbm_mining_area_id > 0) {
		mining_area = MiningAreaPtr(new MiningArea(cbm_mining_area_id));
	}
	int cbm_tunnel_id = rs.get<int>("cbm_tunnel_id", (int)0);
	if(cbm_tunnel_id > 0) {
		tunnel = TunnelPtr(new Tunnel(cbm_tunnel_id));
	}
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString ReadyTunnel::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_ready_tunnel values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), mining_area->getId());
	sql.AppendFormat(_T(", %d"), tunnel->getId());
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString ReadyTunnel::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_ready_tunnel set"));
	sql.AppendFormat(_T("  cbm_mining_area_id=%d"), mining_area->getId());
	sql.AppendFormat(_T(", cbm_tunnel_id=%d"), tunnel->getId());
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString ReadyTunnel::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_ready_tunnel where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int ReadyTunnel::getId() const
{
	return id;
}

void ReadyTunnel::setId(const int& value)
{
	this->id = value;
}

MiningAreaPtr ReadyTunnel::getMiningArea() const
{
	return mining_area;
}

void ReadyTunnel::setMiningArea(const MiningAreaPtr& value)
{
	this->mining_area = value;
}

TunnelPtr ReadyTunnel::getTunnel() const
{
	return tunnel;
}

void ReadyTunnel::setTunnel(const TunnelPtr& value)
{
	this->tunnel = value;
}

CString ReadyTunnel::getComment() const
{
	return comment;
}

void ReadyTunnel::setComment(const CString& value)
{
	this->comment = value;
}

CString ResAbundance::GetTableName()
{
	return _T("cbm_res_abundance");
}

ResAbundancePtr ResAbundance::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	ResAbundanceList objList = Dao()->select<ResAbundance>(_T("cbm_res_abundance"), _T("*"), options);
	ResAbundancePtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

ResAbundanceList ResAbundance::findAll()
{
	return Dao()->select<ResAbundance>(_T("cbm_res_abundance"), _T("*"), _T("order by ResAbundance_id desc"));
}

int ResAbundance::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool ResAbundance::update()
{
	return Dao()->update(*this);
}

bool ResAbundance::remove()
{
	return Dao()->remove(*this);
}

ResAbundance::ResAbundance()
{
	id = 0;
	type = _T("NULL");
	min_abundance = 0.0;
	max_abundance = 0.0;
}

ResAbundance::ResAbundance(int id)
{
	id = 0;
	type = _T("NULL");
	min_abundance = 0.0;
	max_abundance = 0.0;
}

ResAbundance::ResAbundance(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	type = EncodeHelper::ANSIToUnicode(rs.get<std::string>("type", "")).c_str();
	min_abundance = rs.get<double>("min_abundance", (double)0);
	max_abundance = rs.get<double>("max_abundance", (double)0);
}

CString ResAbundance::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_res_abundance values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", '%s'"), type);
	sql.AppendFormat(_T(", %lf"), min_abundance);
	sql.AppendFormat(_T(", %lf"), max_abundance);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString ResAbundance::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_res_abundance set"));
	sql.AppendFormat(_T("  type='%s'"), type);
	sql.AppendFormat(_T(", min_abundance=%lf"), min_abundance);
	sql.AppendFormat(_T(", max_abundance=%lf"), max_abundance);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString ResAbundance::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_res_abundance where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int ResAbundance::getId() const
{
	return id;
}

void ResAbundance::setId(const int& value)
{
	this->id = value;
}

CString ResAbundance::getType() const
{
	return type;
}

void ResAbundance::setType(const CString& value)
{
	this->type = value;
}

double ResAbundance::getMinAbundance() const
{
	return min_abundance;
}

void ResAbundance::setMinAbundance(const double& value)
{
	this->min_abundance = value;
}

double ResAbundance::getMaxAbundance() const
{
	return max_abundance;
}

void ResAbundance::setMaxAbundance(const double& value)
{
	this->max_abundance = value;
}

CString TechMode::GetTableName()
{
	return _T("cbm_tech_mode");
}

TechModePtr TechMode::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	TechModeList objList = Dao()->select<TechMode>(_T("cbm_tech_mode"), _T("*"), options);
	TechModePtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

TechModeList TechMode::findAll()
{
	return Dao()->select<TechMode>(_T("cbm_tech_mode"), _T("*"), _T("order by TechMode_id desc"));
}

int TechMode::insert()
{
	if(mine_region == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool TechMode::update()
{
	if(mine_region == 0) return false;
	return Dao()->update(*this);
}

bool TechMode::remove()
{
	return Dao()->remove(*this);
}

TechMode::TechMode()
{
	id = 0;
	name = _T("NULL");
	type = 0;
	comment = _T("NULL");
}

TechMode::TechMode(int id)
{
	id = 0;
	name = _T("NULL");
	type = 0;
	comment = _T("NULL");
}

TechMode::TechMode(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_mine_region_id = rs.get<int>("cbm_mine_region_id", (int)0);
	if(cbm_mine_region_id > 0) {
		mine_region = MineRegionPtr(new MineRegion(cbm_mine_region_id));
	}
	name = EncodeHelper::ANSIToUnicode(rs.get<std::string>("name", "")).c_str();
	type = rs.get<int>("type", (int)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString TechMode::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_tech_mode values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), mine_region->getId());
	sql.AppendFormat(_T(", '%s'"), name);
	sql.AppendFormat(_T(", %d"), type);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString TechMode::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_tech_mode set"));
	sql.AppendFormat(_T("  cbm_mine_region_id=%d"), mine_region->getId());
	sql.AppendFormat(_T(", name='%s'"), name);
	sql.AppendFormat(_T(", type=%d"), type);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString TechMode::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_tech_mode where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int TechMode::getId() const
{
	return id;
}

void TechMode::setId(const int& value)
{
	this->id = value;
}

MineRegionPtr TechMode::getMineRegion() const
{
	return mine_region;
}

void TechMode::setMineRegion(const MineRegionPtr& value)
{
	this->mine_region = value;
}

CString TechMode::getName() const
{
	return name;
}

void TechMode::setName(const CString& value)
{
	this->name = value;
}

int TechMode::getType() const
{
	return type;
}

void TechMode::setType(const int& value)
{
	this->type = value;
}

CString TechMode::getComment() const
{
	return comment;
}

void TechMode::setComment(const CString& value)
{
	this->comment = value;
}

CString Technology::GetTableName()
{
	return _T("cbm_technology");
}

TechnologyPtr Technology::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	TechnologyList objList = Dao()->select<Technology>(_T("cbm_technology"), _T("*"), options);
	TechnologyPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

TechnologyList Technology::findAll()
{
	return Dao()->select<Technology>(_T("cbm_technology"), _T("*"), _T("order by Technology_id desc"));
}

int Technology::insert()
{
	if(mine_region == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool Technology::update()
{
	if(mine_region == 0) return false;
	return Dao()->update(*this);
}

bool Technology::remove()
{
	return Dao()->remove(*this);
}

Technology::Technology()
{
	id = 0;
	name = _T("NULL");
	iskey = 0;
	doc = _T("NULL");
	video = _T("NULL");
	comment = _T("NULL");
}

Technology::Technology(int id)
{
	id = 0;
	name = _T("NULL");
	iskey = 0;
	doc = _T("NULL");
	video = _T("NULL");
	comment = _T("NULL");
}

Technology::Technology(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_mine_region_id = rs.get<int>("cbm_mine_region_id", (int)0);
	if(cbm_mine_region_id > 0) {
		mine_region = MineRegionPtr(new MineRegion(cbm_mine_region_id));
	}
	name = EncodeHelper::ANSIToUnicode(rs.get<std::string>("name", "")).c_str();
	iskey = rs.get<int>("iskey", (int)0);
	doc = EncodeHelper::ANSIToUnicode(rs.get<std::string>("doc", "")).c_str();
	video = EncodeHelper::ANSIToUnicode(rs.get<std::string>("video", "")).c_str();
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString Technology::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_technology values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), mine_region->getId());
	sql.AppendFormat(_T(", '%s'"), name);
	sql.AppendFormat(_T(", %d"), iskey);
	sql.AppendFormat(_T(", '%s'"), doc);
	sql.AppendFormat(_T(", '%s'"), video);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString Technology::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_technology set"));
	sql.AppendFormat(_T("  cbm_mine_region_id=%d"), mine_region->getId());
	sql.AppendFormat(_T(", name='%s'"), name);
	sql.AppendFormat(_T(", iskey=%d"), iskey);
	sql.AppendFormat(_T(", doc='%s'"), doc);
	sql.AppendFormat(_T(", video='%s'"), video);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString Technology::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_technology where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int Technology::getId() const
{
	return id;
}

void Technology::setId(const int& value)
{
	this->id = value;
}

MineRegionPtr Technology::getMineRegion() const
{
	return mine_region;
}

void Technology::setMineRegion(const MineRegionPtr& value)
{
	this->mine_region = value;
}

CString Technology::getName() const
{
	return name;
}

void Technology::setName(const CString& value)
{
	this->name = value;
}

int Technology::getIskey() const
{
	return iskey;
}

void Technology::setIskey(const int& value)
{
	this->iskey = value;
}

CString Technology::getDoc() const
{
	return doc;
}

void Technology::setDoc(const CString& value)
{
	this->doc = value;
}

CString Technology::getVideo() const
{
	return video;
}

void Technology::setVideo(const CString& value)
{
	this->video = value;
}

CString Technology::getComment() const
{
	return comment;
}

void Technology::setComment(const CString& value)
{
	this->comment = value;
}

CString TopoGeo::GetTableName()
{
	return _T("cbm_topo_geo");
}

TopoGeoPtr TopoGeo::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	TopoGeoList objList = Dao()->select<TopoGeo>(_T("cbm_topo_geo"), _T("*"), options);
	TopoGeoPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

TopoGeoList TopoGeo::findAll()
{
	return Dao()->select<TopoGeo>(_T("cbm_topo_geo"), _T("*"), _T("order by TopoGeo_id desc"));
}

int TopoGeo::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool TopoGeo::update()
{
	return Dao()->update(*this);
}

bool TopoGeo::remove()
{
	return Dao()->remove(*this);
}

TopoGeo::TopoGeo()
{
	id = 0;
	type = _T("NULL");
	feature = _T("NULL");
	comment = _T("NULL");
}

TopoGeo::TopoGeo(int id)
{
	id = 0;
	type = _T("NULL");
	feature = _T("NULL");
	comment = _T("NULL");
}

TopoGeo::TopoGeo(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	type = EncodeHelper::ANSIToUnicode(rs.get<std::string>("type", "")).c_str();
	feature = EncodeHelper::ANSIToUnicode(rs.get<std::string>("feature", "")).c_str();
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString TopoGeo::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_topo_geo values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", '%s'"), type);
	sql.AppendFormat(_T(", '%s'"), feature);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString TopoGeo::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_topo_geo set"));
	sql.AppendFormat(_T("  type='%s'"), type);
	sql.AppendFormat(_T(", feature='%s'"), feature);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString TopoGeo::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_topo_geo where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int TopoGeo::getId() const
{
	return id;
}

void TopoGeo::setId(const int& value)
{
	this->id = value;
}

CString TopoGeo::getType() const
{
	return type;
}

void TopoGeo::setType(const CString& value)
{
	this->type = value;
}

CString TopoGeo::getFeature() const
{
	return feature;
}

void TopoGeo::setFeature(const CString& value)
{
	this->feature = value;
}

CString TopoGeo::getComment() const
{
	return comment;
}

void TopoGeo::setComment(const CString& value)
{
	this->comment = value;
}

CString Tunnel::GetTableName()
{
	return _T("cbm_tunnel");
}

TunnelPtr Tunnel::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	TunnelList objList = Dao()->select<Tunnel>(_T("cbm_tunnel"), _T("*"), options);
	TunnelPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

TunnelList Tunnel::findAll()
{
	return Dao()->select<Tunnel>(_T("cbm_tunnel"), _T("*"), _T("order by Tunnel_id desc"));
}

int Tunnel::insert()
{
	this->id = Dao()->insert(*this);
	return this->id;
}

bool Tunnel::update()
{
	return Dao()->update(*this);
}

bool Tunnel::remove()
{
	return Dao()->remove(*this);
}

Tunnel::Tunnel()
{
	id = 0;
	b = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	qa = 0.0;
	comment = _T("NULL");
}

Tunnel::Tunnel(int id)
{
	id = 0;
	b = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	qa = 0.0;
	comment = _T("NULL");
}

Tunnel::Tunnel(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	b = rs.get<double>("b", (double)0);
	l = rs.get<double>("l", (double)0);
	s = rs.get<double>("s", (double)0);
	d = rs.get<double>("d", (double)0);
	wh = rs.get<double>("wh", (double)0);
	v = rs.get<double>("v", (double)0);
	qa = rs.get<double>("qa", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString Tunnel::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_tunnel values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %lf"), b);
	sql.AppendFormat(_T(", %lf"), l);
	sql.AppendFormat(_T(", %lf"), s);
	sql.AppendFormat(_T(", %lf"), d);
	sql.AppendFormat(_T(", %lf"), wh);
	sql.AppendFormat(_T(", %lf"), v);
	sql.AppendFormat(_T(", %lf"), qa);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString Tunnel::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_tunnel set"));
	sql.AppendFormat(_T("  b=%lf"), b);
	sql.AppendFormat(_T(", l=%lf"), l);
	sql.AppendFormat(_T(", s=%lf"), s);
	sql.AppendFormat(_T(", d=%lf"), d);
	sql.AppendFormat(_T(", wh=%lf"), wh);
	sql.AppendFormat(_T(", v=%lf"), v);
	sql.AppendFormat(_T(", qa=%lf"), qa);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString Tunnel::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_tunnel where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int Tunnel::getId() const
{
	return id;
}

void Tunnel::setId(const int& value)
{
	this->id = value;
}

double Tunnel::getB() const
{
	return b;
}

void Tunnel::setB(const double& value)
{
	this->b = value;
}

double Tunnel::getL() const
{
	return l;
}

void Tunnel::setL(const double& value)
{
	this->l = value;
}

double Tunnel::getS() const
{
	return s;
}

void Tunnel::setS(const double& value)
{
	this->s = value;
}

double Tunnel::getD() const
{
	return d;
}

void Tunnel::setD(const double& value)
{
	this->d = value;
}

double Tunnel::getWh() const
{
	return wh;
}

void Tunnel::setWh(const double& value)
{
	this->wh = value;
}

double Tunnel::getV() const
{
	return v;
}

void Tunnel::setV(const double& value)
{
	this->v = value;
}

double Tunnel::getQa() const
{
	return qa;
}

void Tunnel::setQa(const double& value)
{
	this->qa = value;
}

CString Tunnel::getComment() const
{
	return comment;
}

void Tunnel::setComment(const CString& value)
{
	this->comment = value;
}

CString WorkSurf::GetTableName()
{
	return _T("cbm_work_surf");
}

WorkSurfPtr WorkSurf::findOne(int id)
{
	CString options;
	options.Format(_T("where id=%d"), id);
	WorkSurfList objList = Dao()->select<WorkSurf>(_T("cbm_work_surf"), _T("*"), options);
	WorkSurfPtr obj;
	if(objList != 0 && objList->size() > 0) {
		obj = objList->at(0);
	}
	return obj;
}

WorkSurfList WorkSurf::findAll()
{
	return Dao()->select<WorkSurf>(_T("cbm_work_surf"), _T("*"), _T("order by WorkSurf_id desc"));
}

int WorkSurf::insert()
{
	if(tunnel == 0) return 0;
	if(coal == 0) return 0;
	this->id = Dao()->insert(*this);
	return this->id;
}

bool WorkSurf::update()
{
	if(tunnel == 0) return false;
	if(coal == 0) return false;
	return Dao()->update(*this);
}

bool WorkSurf::remove()
{
	return Dao()->remove(*this);
}

WorkSurf::WorkSurf()
{
	id = 0;
	a = 0.0;
	q_r = 0.0;
	q_a = 0.0;
	ws_l = 0.0;
	ws_layerable = 0;
	ws_k1 = 0.0;
	ws_k2 = 0.0;
	ws_k3 = 0.0;
	ws_kf = 0.0;
	ws_h = 0.0;
	ws_method = 0;
	last_t = 0.0;
	comment = _T("NULL");
}

WorkSurf::WorkSurf(int id)
{
	id = 0;
	a = 0.0;
	q_r = 0.0;
	q_a = 0.0;
	ws_l = 0.0;
	ws_layerable = 0;
	ws_k1 = 0.0;
	ws_k2 = 0.0;
	ws_k3 = 0.0;
	ws_kf = 0.0;
	ws_h = 0.0;
	ws_method = 0;
	last_t = 0.0;
	comment = _T("NULL");
}

WorkSurf::WorkSurf(soci::row &rs)
{
	id = rs.get<int>("id", (int)0);
	int cbm_tunnel_id = rs.get<int>("cbm_tunnel_id", (int)0);
	if(cbm_tunnel_id > 0) {
		tunnel = TunnelPtr(new Tunnel(cbm_tunnel_id));
	}
	int cbm_coal_id = rs.get<int>("cbm_coal_id", (int)0);
	if(cbm_coal_id > 0) {
		coal = CoalPtr(new Coal(cbm_coal_id));
	}
	a = rs.get<double>("a", (double)0);
	q_r = rs.get<double>("q_r", (double)0);
	q_a = rs.get<double>("q_a", (double)0);
	ws_l = rs.get<double>("ws_l", (double)0);
	ws_layerable = rs.get<int>("ws_layerable", (int)0);
	ws_k1 = rs.get<double>("ws_k1", (double)0);
	ws_k2 = rs.get<double>("ws_k2", (double)0);
	ws_k3 = rs.get<double>("ws_k3", (double)0);
	ws_kf = rs.get<double>("ws_kf", (double)0);
	ws_h = rs.get<double>("ws_h", (double)0);
	ws_method = rs.get<int>("ws_method", (int)0);
	last_t = rs.get<double>("last_t", (double)0);
	comment = EncodeHelper::ANSIToUnicode(rs.get<std::string>("comment", "")).c_str();
}

CString WorkSurf::getSqlInsert() const
{
	CString sql;
	sql.AppendFormat(_T("insert into cbm_work_surf values("));
	sql.AppendFormat(_T("NULL"));
	sql.AppendFormat(_T(", %d"), tunnel->getId());
	sql.AppendFormat(_T(", %d"), coal->getId());
	sql.AppendFormat(_T(", %lf"), a);
	sql.AppendFormat(_T(", %lf"), q_r);
	sql.AppendFormat(_T(", %lf"), q_a);
	sql.AppendFormat(_T(", %lf"), ws_l);
	sql.AppendFormat(_T(", %d"), ws_layerable);
	sql.AppendFormat(_T(", %lf"), ws_k1);
	sql.AppendFormat(_T(", %lf"), ws_k2);
	sql.AppendFormat(_T(", %lf"), ws_k3);
	sql.AppendFormat(_T(", %lf"), ws_kf);
	sql.AppendFormat(_T(", %lf"), ws_h);
	sql.AppendFormat(_T(", %d"), ws_method);
	sql.AppendFormat(_T(", %lf"), last_t);
	sql.AppendFormat(_T(", '%s'"), comment);
	sql.AppendFormat(_T(");"));
	return sql;
}

CString WorkSurf::getSqlUpdate() const
{
	CString sql;
	sql.AppendFormat(_T("update cbm_work_surf set"));
	sql.AppendFormat(_T("  cbm_tunnel_id=%d"), tunnel->getId());
	sql.AppendFormat(_T(", cbm_coal_id=%d"), coal->getId());
	sql.AppendFormat(_T(", a=%lf"), a);
	sql.AppendFormat(_T(", q_r=%lf"), q_r);
	sql.AppendFormat(_T(", q_a=%lf"), q_a);
	sql.AppendFormat(_T(", ws_l=%lf"), ws_l);
	sql.AppendFormat(_T(", ws_layerable=%d"), ws_layerable);
	sql.AppendFormat(_T(", ws_k1=%lf"), ws_k1);
	sql.AppendFormat(_T(", ws_k2=%lf"), ws_k2);
	sql.AppendFormat(_T(", ws_k3=%lf"), ws_k3);
	sql.AppendFormat(_T(", ws_kf=%lf"), ws_kf);
	sql.AppendFormat(_T(", ws_h=%lf"), ws_h);
	sql.AppendFormat(_T(", ws_method=%d"), ws_method);
	sql.AppendFormat(_T(", last_t=%lf"), last_t);
	sql.AppendFormat(_T(", comment='%s'"), comment);
	sql.AppendFormat(_T(";"));
	return sql;
}

CString WorkSurf::getSqlDelete() const
{
	CString sql;
	sql.AppendFormat(_T("delete from cbm_work_surf where"));
	sql.AppendFormat(_T("  id=%d"), id);
	sql.AppendFormat(_T(";"));
	return sql;
}

int WorkSurf::getId() const
{
	return id;
}

void WorkSurf::setId(const int& value)
{
	this->id = value;
}

TunnelPtr WorkSurf::getTunnel() const
{
	return tunnel;
}

void WorkSurf::setTunnel(const TunnelPtr& value)
{
	this->tunnel = value;
}

CoalPtr WorkSurf::getCoal() const
{
	return coal;
}

void WorkSurf::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

double WorkSurf::getA() const
{
	return a;
}

void WorkSurf::setA(const double& value)
{
	this->a = value;
}

double WorkSurf::getQR() const
{
	return q_r;
}

void WorkSurf::setQR(const double& value)
{
	this->q_r = value;
}

double WorkSurf::getQA() const
{
	return q_a;
}

void WorkSurf::setQA(const double& value)
{
	this->q_a = value;
}

double WorkSurf::getWsL() const
{
	return ws_l;
}

void WorkSurf::setWsL(const double& value)
{
	this->ws_l = value;
}

int WorkSurf::getWsLayerable() const
{
	return ws_layerable;
}

void WorkSurf::setWsLayerable(const int& value)
{
	this->ws_layerable = value;
}

double WorkSurf::getWsK1() const
{
	return ws_k1;
}

void WorkSurf::setWsK1(const double& value)
{
	this->ws_k1 = value;
}

double WorkSurf::getWsK2() const
{
	return ws_k2;
}

void WorkSurf::setWsK2(const double& value)
{
	this->ws_k2 = value;
}

double WorkSurf::getWsK3() const
{
	return ws_k3;
}

void WorkSurf::setWsK3(const double& value)
{
	this->ws_k3 = value;
}

double WorkSurf::getWsKf() const
{
	return ws_kf;
}

void WorkSurf::setWsKf(const double& value)
{
	this->ws_kf = value;
}

double WorkSurf::getWsH() const
{
	return ws_h;
}

void WorkSurf::setWsH(const double& value)
{
	this->ws_h = value;
}

int WorkSurf::getWsMethod() const
{
	return ws_method;
}

void WorkSurf::setWsMethod(const int& value)
{
	this->ws_method = value;
}

double WorkSurf::getLastT() const
{
	return last_t;
}

void WorkSurf::setLastT(const double& value)
{
	this->last_t = value;
}

CString WorkSurf::getComment() const
{
	return comment;
}

void WorkSurf::setComment(const CString& value)
{
	this->comment = value;
}

} // namespace cbm
