#include "stdafx.h"
#include "Entity.h"

namespace cbm {

CString AdjLayer::Table()
{
	return _T("cbm_adj_layer");
}

orm::RecordPtr AdjLayer::Create()
{
	return orm::RecordPtr(new AdjLayer());
}

AdjLayer::AdjLayer() : orm::Record(AdjLayer::Table())
{
	id = 0;
	layer_num = 0;
	layer_h = 0.0;
	layer_hp = 0.0;
	layer_cave_zone = 0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(layer_num, layer_num);
	REG_ATTRIB(layer_h, layer_h);
	REG_ATTRIB(layer_hp, layer_hp);
	REG_ATTRIB(layer_cave_zone, layer_cave_zone);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &AdjLayer::Create);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &AdjLayer::Create);
}

CString Coal::Table()
{
	return _T("cbm_coal");
}

orm::RecordPtr Coal::Create()
{
	return orm::RecordPtr(new Coal());
}

Coal::Coal() : orm::Record(Coal::Table())
{
	id = 0;
	coal_name = _T("");
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
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(coal_name, coal_name);
	REG_ATTRIB(coal_minable, coal_minable);
	REG_ATTRIB(coal_thick, coal_thick);
	REG_ATTRIB(coal_rank, coal_rank);
	REG_ATTRIB(coal_quality, coal_quality);
	REG_ATTRIB(layer_pressure, layer_pressure);
	REG_ATTRIB(gas_content, gas_content);
	REG_ATTRIB(gas_penetration, gas_penetration);
	REG_ATTRIB(f_value, f_value);
	REG_ATTRIB(res_abundance, res_abundance);
	REG_ATTRIB(const_complexity, const_complexity);
	REG_ATTRIB(mine_index, mine_index);
	REG_ATTRIB(var_coeff, var_coeff);
	REG_ATTRIB(coal_stability, coal_stability);
	REG_ATTRIB(dip_angle, dip_angle);
	REG_ATTRIB(caving_zone_height, caving_zone_height);
	REG_ATTRIB(layer_gap, layer_gap);
	REG_ATTRIB(influence_factor, influence_factor);
	REG_ATTRIB(res_a1, res_a1);
	REG_ATTRIB(gas_x1, gas_x1);
	REG_ATTRIB(res_a2, res_a2);
	REG_ATTRIB(gas_x2, gas_x2);
	REG_ATTRIB(gas_wc, gas_wc);
	REG_ATTRIB(coal_r, coal_r);
	REG_ATTRIB(coal_vr, coal_vr);
	REG_ATTRIB(gas_w0, gas_w0);
	REG_ATTRIB(gas_wc2, gas_wc2);
	REG_ATTRIB(gas_eta, gas_eta);
	REG_ATTRIB(q_r, q_r);
	REG_ATTRIB(q0, q0);
	REG_ATTRIB(eval_method, eval_method);
	REG_ATTRIB(q0_alpha, q0_alpha);
	REG_ATTRIB(qt_alpha, qt_alpha);
	REG_ATTRIB(t_alpha, t_alpha);
	REG_ATTRIB(q_lambda, q_lambda);
	REG_ATTRIB(r_lambda, r_lambda);
	REG_ATTRIB(p0_lambda, p0_lambda);
	REG_ATTRIB(p1_lambda, p1_lambda);
	REG_ATTRIB(t_lambda, t_lambda);
	REG_ATTRIB(a_lambda, a_lambda);
	REG_ATTRIB(p1_k, p1_k);
	REG_ATTRIB(p2_k, p2_k);
	REG_ATTRIB(gas_q, gas_q);
	REG_ATTRIB(core_height, core_height);
	REG_ATTRIB(core_area, core_area);
	REG_ATTRIB(gas_viscosity, gas_viscosity);
	REG_ATTRIB(decay_alpha, decay_alpha);
	REG_ATTRIB(permeability_lambda, permeability_lambda);
	REG_ATTRIB(permeability_k, permeability_k);
	REG_ATTRIB(eval_difficult, eval_difficult);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mine_id, mine, &Coal::Create);
}

CString DrillingRadius::Table()
{
	return _T("cbm_drilling_radius");
}

orm::RecordPtr DrillingRadius::Create()
{
	return orm::RecordPtr(new DrillingRadius());
}

DrillingRadius::DrillingRadius() : orm::Record(DrillingRadius::Table())
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
	REG_ATTRIB(id, id);
	REG_ATTRIB(radius_r, radius_r);
	REG_ATTRIB(radius_l, radius_l);
	REG_ATTRIB(radius_k1, radius_k1);
	REG_ATTRIB(radius_rho, radius_rho);
	REG_ATTRIB(radius_q0, radius_q0);
	REG_ATTRIB(radius_a, radius_a);
	REG_ATTRIB(radius_t, radius_t);
	REG_ATTRIB(radius_qm1, radius_qm1);
	REG_ATTRIB(radius_qm2, radius_qm2);
	REG_ATTRIB(radius_qsum, radius_qsum);
	REG_ATTRIB(radius_eta, radius_eta);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &DrillingRadius::Create);
}

CString DrillingSurf::Table()
{
	return _T("cbm_drilling_surf");
}

orm::RecordPtr DrillingSurf::Create()
{
	return orm::RecordPtr(new DrillingSurf());
}

DrillingSurf::DrillingSurf() : orm::Record(DrillingSurf::Table())
{
	id = 0;
	q_r = 0.0;
	q_a = 0.0;
	tw_q4 = 0.0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(q_r, q_r);
	REG_ATTRIB(q_a, q_a);
	REG_ATTRIB(tw_q4, tw_q4);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &DrillingSurf::Create);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &DrillingSurf::Create);
}

CString EvalUnit::Table()
{
	return _T("cbm_eval_unit");
}

orm::RecordPtr EvalUnit::Create()
{
	return orm::RecordPtr(new EvalUnit());
}

EvalUnit::EvalUnit() : orm::Record(EvalUnit::Table())
{
	id = 0;
	unit_l = 0.0;
	unit_t = 0.0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(unit_l, unit_l);
	REG_ATTRIB(unit_t, unit_t);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &EvalUnit::Create);
}

CString Help::Table()
{
	return _T("cbm_help");
}

orm::RecordPtr Help::Create()
{
	return orm::RecordPtr(new Help());
}

Help::Help() : orm::Record(Help::Table())
{
	id = 0;
	help_field = _T("");
	help_type = 0;
	help_value = _T("");
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(help_field, help_field);
	REG_ATTRIB(help_type, help_type);
	REG_ATTRIB(help_value, help_value);
	REG_ATTRIB(comment, comment);
}

CString HighDrillingPore::Table()
{
	return _T("cbm_high_drilling_pore");
}

orm::RecordPtr HighDrillingPore::Create()
{
	return orm::RecordPtr(new HighDrillingPore());
}

HighDrillingPore::HighDrillingPore() : orm::Record(HighDrillingPore::Table())
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
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(hdp_l1, hdp_l1);
	REG_ATTRIB(hdp_l2, hdp_l2);
	REG_ATTRIB(hdp_lg, hdp_lg);
	REG_ATTRIB(hdp_hz, hdp_hz);
	REG_ATTRIB(hdp_lk, hdp_lk);
	REG_ATTRIB(hdp_lc, hdp_lc);
	REG_ATTRIB(hdp_lw, hdp_lw);
	REG_ATTRIB(hdp_n, hdp_n);
	REG_ATTRIB(hdp_beta, hdp_beta);
	REG_ATTRIB(hdp_ld, hdp_ld);
	REG_ATTRIB(hdp_lzi, hdp_lzi);
	REG_ATTRIB(hdp_lzj, hdp_lzj);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &HighDrillingPore::Create);
}

CString HighDrillingTunnel::Table()
{
	return _T("cbm_high_drilling_tunnel");
}

orm::RecordPtr HighDrillingTunnel::Create()
{
	return orm::RecordPtr(new HighDrillingTunnel());
}

HighDrillingTunnel::HighDrillingTunnel() : orm::Record(HighDrillingTunnel::Table())
{
	id = 0;
	hdt_k = 0.0;
	hdt_rock = 0;
	hdt_hz_min = 0.0;
	hdt_hz_max = 0.0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(hdt_k, hdt_k);
	REG_ATTRIB(hdt_rock, hdt_rock);
	REG_ATTRIB(hdt_hz_min, hdt_hz_min);
	REG_ATTRIB(hdt_hz_max, hdt_hz_max);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &HighDrillingTunnel::Create);
}

CString HydrGeo::Table()
{
	return _T("cbm_hydr_geo");
}

orm::RecordPtr HydrGeo::Create()
{
	return orm::RecordPtr(new HydrGeo());
}

HydrGeo::HydrGeo() : orm::Record(HydrGeo::Table())
{
	id = 0;
	type = _T("");
	x1 = 0;
	x2 = 0.0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(type, type);
	REG_ATTRIB(x1, x1);
	REG_ATTRIB(x2, x2);
	REG_ATTRIB(x3, x3);
	REG_ATTRIB(x4, x4);
	REG_ATTRIB(x5, x5);
	REG_ATTRIB(x6, x6);
	REG_ATTRIB(x7, x7);
	REG_ATTRIB(x8, x8);
}

CString KeyLayer::Table()
{
	return _T("cbm_key_layer");
}

orm::RecordPtr KeyLayer::Create()
{
	return orm::RecordPtr(new KeyLayer());
}

KeyLayer::KeyLayer() : orm::Record(KeyLayer::Table())
{
	id = 0;
	key_hn = 0.0;
	key_thetan = 0.0;
	key_qn = 0.0;
	key_rtn = 0.0;
	key_sum_hn = 0.0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(key_hn, key_hn);
	REG_ATTRIB(key_thetan, key_thetan);
	REG_ATTRIB(key_qn, key_qn);
	REG_ATTRIB(key_rtn, key_rtn);
	REG_ATTRIB(key_sum_hn, key_sum_hn);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_high_drilling_pore_id, high_drilling_pore, &KeyLayer::Create);
}

CString Mine::Table()
{
	return _T("cbm_mine");
}

orm::RecordPtr Mine::Create()
{
	return orm::RecordPtr(new Mine());
}

Mine::Mine() : orm::Record(Mine::Table())
{
	id = 0;
	username = _T("");
	password = _T("");
	mine_name = _T("");
	province = _T("");
	city = _T("");
	capacity = 0.0;
	topo_geo = 0;
	hydr_geo = 0;
	ground_condition = 0;
	q_r = 0.0;
	stereo_schem_diagram = _T("");
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
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(username, username);
	REG_ATTRIB(password, password);
	REG_ATTRIB(mine_name, mine_name);
	REG_ATTRIB(province, province);
	REG_ATTRIB(city, city);
	REG_ATTRIB(capacity, capacity);
	REG_ATTRIB(topo_geo, topo_geo);
	REG_ATTRIB(hydr_geo, hydr_geo);
	REG_ATTRIB(ground_condition, ground_condition);
	REG_ATTRIB(q_r, q_r);
	REG_ATTRIB(stereo_schem_diagram, stereo_schem_diagram);
	REG_ATTRIB(k_gas, k_gas);
	REG_ATTRIB(reserve_w1, reserve_w1);
	REG_ATTRIB(reserve_w2, reserve_w2);
	REG_ATTRIB(reserve_w3, reserve_w3);
	REG_ATTRIB(reserve_gas, reserve_gas);
	REG_ATTRIB(pump_kd, pump_kd);
	REG_ATTRIB(pump_k1, pump_k1);
	REG_ATTRIB(pump_k2, pump_k2);
	REG_ATTRIB(pump_k3, pump_k3);
	REG_ATTRIB(pump_k4, pump_k4);
	REG_ATTRIB(pump_wc, pump_wc);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mine_region_id, mine_region, &Mine::Create);
}

CString MineBase::Table()
{
	return _T("cbm_mine_base");
}

orm::RecordPtr MineBase::Create()
{
	return orm::RecordPtr(new MineBase());
}

MineBase::MineBase() : orm::Record(MineBase::Table())
{
	id = 0;
	name = _T("");
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
}

CString MineRegion::Table()
{
	return _T("cbm_mine_region");
}

orm::RecordPtr MineRegion::Create()
{
	return orm::RecordPtr(new MineRegion());
}

MineRegion::MineRegion() : orm::Record(MineRegion::Table())
{
	id = 0;
	name = _T("");
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mine_base_id, mine_base, &MineRegion::Create);
}

CString MiningArea::Table()
{
	return _T("cbm_mining_area");
}

orm::RecordPtr MiningArea::Create()
{
	return orm::RecordPtr(new MiningArea());
}

MiningArea::MiningArea() : orm::Record(MiningArea::Table())
{
	id = 0;
	area_mode = 0;
	area_k = 0.0;
	a = 0.0;
	q_r = 0.0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(area_mode, area_mode);
	REG_ATTRIB(area_k, area_k);
	REG_ATTRIB(a, a);
	REG_ATTRIB(q_r, q_r);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &MiningArea::Create);
}

CString PoreFlow::Table()
{
	return _T("cbm_pore_flow");
}

orm::RecordPtr PoreFlow::Create()
{
	return orm::RecordPtr(new PoreFlow());
}

PoreFlow::PoreFlow() : orm::Record(PoreFlow::Table())
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
	REG_ATTRIB(id, id);
	REG_ATTRIB(flow_t, flow_t);
	REG_ATTRIB(flow_a0, flow_a0);
	REG_ATTRIB(flow_d, flow_d);
	REG_ATTRIB(flow_d1, flow_d1);
	REG_ATTRIB(flow_m, flow_m);
	REG_ATTRIB(flow_k, flow_k);
	REG_ATTRIB(flow_delta_t, flow_delta_t);
	REG_ATTRIB(flow_x, flow_x);
	REG_ATTRIB(flow_p_test, flow_p_test);
	REG_ATTRIB(flow_p_cur, flow_p_cur);
	REG_ATTRIB(flow_b, flow_b);
	REG_ATTRIB(flow_pt, flow_pt);
	REG_ATTRIB(flow_delta_p, flow_delta_p);
	REG_ATTRIB(flow_dh, flow_dh);
	REG_ATTRIB(flow_q_hun, flow_q_hun);
	REG_ATTRIB(flow_q_chun, flow_q_chun);
}

CString PoreSize::Table()
{
	return _T("cbm_pore_size");
}

orm::RecordPtr PoreSize::Create()
{
	return orm::RecordPtr(new PoreSize());
}

PoreSize::PoreSize() : orm::Record(PoreSize::Table())
{
	id = 0;
	size_q = 0.0;
	size_v = 0.0;
	size_d = 0.0;
	size_p = 0.0;
	size_sigma = 0.0;
	size_delta = 0.0;
	REG_ATTRIB(id, id);
	REG_ATTRIB(size_q, size_q);
	REG_ATTRIB(size_v, size_v);
	REG_ATTRIB(size_d, size_d);
	REG_ATTRIB(size_p, size_p);
	REG_ATTRIB(size_sigma, size_sigma);
	REG_ATTRIB(size_delta, size_delta);
}

CString ReadyTunnel::Table()
{
	return _T("cbm_ready_tunnel");
}

orm::RecordPtr ReadyTunnel::Create()
{
	return orm::RecordPtr(new ReadyTunnel());
}

ReadyTunnel::ReadyTunnel() : orm::Record(ReadyTunnel::Table())
{
	id = 0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mining_area_id, mining_area, &ReadyTunnel::Create);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &ReadyTunnel::Create);
}

CString ResAbundance::Table()
{
	return _T("cbm_res_abundance");
}

orm::RecordPtr ResAbundance::Create()
{
	return orm::RecordPtr(new ResAbundance());
}

ResAbundance::ResAbundance() : orm::Record(ResAbundance::Table())
{
	id = 0;
	type = _T("");
	min_abundance = 0.0;
	max_abundance = 0.0;
	REG_ATTRIB(id, id);
	REG_ATTRIB(type, type);
	REG_ATTRIB(min_abundance, min_abundance);
	REG_ATTRIB(max_abundance, max_abundance);
}

CString TechMode::Table()
{
	return _T("cbm_tech_mode");
}

orm::RecordPtr TechMode::Create()
{
	return orm::RecordPtr(new TechMode());
}

TechMode::TechMode() : orm::Record(TechMode::Table())
{
	id = 0;
	name = _T("");
	type = 0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(name, name);
	REG_ATTRIB(type, type);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mine_region_id, mine_region, &TechMode::Create);
}

CString Technology::Table()
{
	return _T("cbm_technology");
}

orm::RecordPtr Technology::Create()
{
	return orm::RecordPtr(new Technology());
}

Technology::Technology() : orm::Record(Technology::Table())
{
	id = 0;
	name = _T("");
	iskey = 0;
	doc = _T("");
	video = _T("");
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(name, name);
	REG_ATTRIB(iskey, iskey);
	REG_ATTRIB(doc, doc);
	REG_ATTRIB(video, video);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mine_region_id, mine_region, &Technology::Create);
}

CString TopoGeo::Table()
{
	return _T("cbm_topo_geo");
}

orm::RecordPtr TopoGeo::Create()
{
	return orm::RecordPtr(new TopoGeo());
}

TopoGeo::TopoGeo() : orm::Record(TopoGeo::Table())
{
	id = 0;
	type = _T("");
	feature = _T("");
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(type, type);
	REG_ATTRIB(feature, feature);
	REG_ATTRIB(comment, comment);
}

CString Tunnel::Table()
{
	return _T("cbm_tunnel");
}

orm::RecordPtr Tunnel::Create()
{
	return orm::RecordPtr(new Tunnel());
}

Tunnel::Tunnel() : orm::Record(Tunnel::Table())
{
	id = 0;
	b = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	qa = 0.0;
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(b, b);
	REG_ATTRIB(l, l);
	REG_ATTRIB(s, s);
	REG_ATTRIB(d, d);
	REG_ATTRIB(wh, wh);
	REG_ATTRIB(v, v);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(comment, comment);
}

CString WorkSurf::Table()
{
	return _T("cbm_work_surf");
}

orm::RecordPtr WorkSurf::Create()
{
	return orm::RecordPtr(new WorkSurf());
}

WorkSurf::WorkSurf() : orm::Record(WorkSurf::Table())
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
	comment = _T("");
	REG_ATTRIB(id, id);
	REG_ATTRIB(a, a);
	REG_ATTRIB(q_r, q_r);
	REG_ATTRIB(q_a, q_a);
	REG_ATTRIB(ws_l, ws_l);
	REG_ATTRIB(ws_layerable, ws_layerable);
	REG_ATTRIB(ws_k1, ws_k1);
	REG_ATTRIB(ws_k2, ws_k2);
	REG_ATTRIB(ws_k3, ws_k3);
	REG_ATTRIB(ws_kf, ws_kf);
	REG_ATTRIB(ws_h, ws_h);
	REG_ATTRIB(ws_method, ws_method);
	REG_ATTRIB(last_t, last_t);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &WorkSurf::Create);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &WorkSurf::Create);
}

} // namespace cbm
