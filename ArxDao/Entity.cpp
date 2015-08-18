#include "stdafx.h"
#include "Entity.h"

namespace cbm {

CString Account::Table()
{
	return _T("cbm_account");
}

orm::RecordPtr Account::Create()
{
	return orm::RecordPtr(new Account());
}

Account::Account() : orm::Record(Account::Table())
{
	username = _T("");
	password = _T("");
	comment = _T("");
	REG_ATTRIB(username, username);
	REG_ATTRIB(password, password);
	REG_ATTRIB(comment, comment);
}

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
	num = 0;
	h = 0.0;
	hp = 0.0;
	cave_zone = 0;
	comment = _T("");
	REG_ATTRIB(num, num);
	REG_ATTRIB(h, h);
	REG_ATTRIB(hp, hp);
	REG_ATTRIB(cave_zone, cave_zone);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &WorkSurf::Create);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &Coal::Create);
}

CString Base::Table()
{
	return _T("cbm_base");
}

orm::RecordPtr Base::Create()
{
	return orm::RecordPtr(new Base());
}

Base::Base() : orm::Record(Base::Table())
{
	name = _T("");
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
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
	name = _T("");
	minable = 0;
	thick = 0.0;
	hw = 0.0;
	qr = 0.0;
	rank = 0;
	quality = 0;
	pressure = 0.0;
	gas_content = 0.0;
	gas_penetration = 0.0;
	f_value = 0.0;
	res_abundance = 0;
	complexity = 0;
	mine_index = 0.0;
	var_coeff = 0.0;
	stability = 0;
	dip_angle = 0.0;
	czh = 0.0;
	czk = 0.0;
	czw = 0.0;
	layer_gap = 0.0;
	influence_factor = 0.0;
	res_a1 = 0.0;
	gas_x1 = 0.0;
	res_a2 = 0.0;
	gas_x2 = 0.0;
	gas_wc = 0.0;
	rho = 0.0;
	vr = 0.0;
	gas_w0 = 0.0;
	gas_wc2 = 0.0;
	gas_wc3 = 0.0;
	gas_eta = 0.0;
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
	REG_ATTRIB(name, name);
	REG_ATTRIB(minable, minable);
	REG_ATTRIB(thick, thick);
	REG_ATTRIB(hw, hw);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(rank, rank);
	REG_ATTRIB(quality, quality);
	REG_ATTRIB(pressure, pressure);
	REG_ATTRIB(gas_content, gas_content);
	REG_ATTRIB(gas_penetration, gas_penetration);
	REG_ATTRIB(f_value, f_value);
	REG_ATTRIB(res_abundance, res_abundance);
	REG_ATTRIB(complexity, complexity);
	REG_ATTRIB(mine_index, mine_index);
	REG_ATTRIB(var_coeff, var_coeff);
	REG_ATTRIB(stability, stability);
	REG_ATTRIB(dip_angle, dip_angle);
	REG_ATTRIB(czh, czh);
	REG_ATTRIB(czk, czk);
	REG_ATTRIB(czw, czw);
	REG_ATTRIB(layer_gap, layer_gap);
	REG_ATTRIB(influence_factor, influence_factor);
	REG_ATTRIB(res_a1, res_a1);
	REG_ATTRIB(gas_x1, gas_x1);
	REG_ATTRIB(res_a2, res_a2);
	REG_ATTRIB(gas_x2, gas_x2);
	REG_ATTRIB(gas_wc, gas_wc);
	REG_ATTRIB(rho, rho);
	REG_ATTRIB(vr, vr);
	REG_ATTRIB(gas_w0, gas_w0);
	REG_ATTRIB(gas_wc2, gas_wc2);
	REG_ATTRIB(gas_wc3, gas_wc3);
	REG_ATTRIB(gas_eta, gas_eta);
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
	REG_FOREGIN_KEY(cbm_mine_id, mine, &Mine::Create);
}

CString CoalPore::Table()
{
	return _T("cbm_coal_pore");
}

orm::RecordPtr CoalPore::Create()
{
	return orm::RecordPtr(new CoalPore());
}

CoalPore::CoalPore() : orm::Record(CoalPore::Table())
{
	thick = 0.0;
	comment = _T("");
	REG_ATTRIB(thick, thick);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &Coal::Create);
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
	r = 0.0;
	l = 0.0;
	k1 = 0.0;
	rho = 0.0;
	q0 = 0.0;
	a = 0.0;
	t = 0.0;
	qm = 0.0;
	qsum = 0.0;
	eta = 0.0;
	REG_ATTRIB(r, r);
	REG_ATTRIB(l, l);
	REG_ATTRIB(k1, k1);
	REG_ATTRIB(rho, rho);
	REG_ATTRIB(q0, q0);
	REG_ATTRIB(a, a);
	REG_ATTRIB(t, t);
	REG_ATTRIB(qm, qm);
	REG_ATTRIB(qsum, qsum);
	REG_ATTRIB(eta, eta);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &Coal::Create);
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
	qr = 0.0;
	qa = 0.0;
	q4 = 0.0;
	comment = _T("");
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(q4, q4);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mining_area_id, mining_area, &MiningArea::Create);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &Tunnel::Create);
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
	l = 0.0;
	t = 0.0;
	comment = _T("");
	REG_ATTRIB(l, l);
	REG_ATTRIB(t, t);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &WorkSurf::Create);
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
	field = _T("");
	type = 0;
	value = _T("");
	comment = _T("");
	REG_ATTRIB(field, field);
	REG_ATTRIB(type, type);
	REG_ATTRIB(value, value);
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
	l1 = 0.0;
	l2 = 0.0;
	lg = 0.0;
	lk = 0.0;
	lc = 0.0;
	lw = 0.0;
	n = 0.0;
	beta = 0.0;
	ld = 0.0;
	lzi = 0.0;
	lzj = 0.0;
	comment = _T("");
	REG_ATTRIB(l1, l1);
	REG_ATTRIB(l2, l2);
	REG_ATTRIB(lg, lg);
	REG_ATTRIB(lk, lk);
	REG_ATTRIB(lc, lc);
	REG_ATTRIB(lw, lw);
	REG_ATTRIB(n, n);
	REG_ATTRIB(beta, beta);
	REG_ATTRIB(ld, ld);
	REG_ATTRIB(lzi, lzi);
	REG_ATTRIB(lzj, lzj);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &WorkSurf::Create);
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
	k = 0.0;
	rock = 0;
	hz_min = 0.0;
	hz_max = 0.0;
	comment = _T("");
	REG_ATTRIB(k, k);
	REG_ATTRIB(rock, rock);
	REG_ATTRIB(hz_min, hz_min);
	REG_ATTRIB(hz_max, hz_max);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &WorkSurf::Create);
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
	type = _T("");
	x1 = 0;
	x2 = 0.0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = _T("");
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
	h = 0.0;
	theta = 0.0;
	q = 0.0;
	rt = 0.0;
	sum_h = 0.0;
	comment = _T("");
	REG_ATTRIB(h, h);
	REG_ATTRIB(theta, theta);
	REG_ATTRIB(q, q);
	REG_ATTRIB(rt, rt);
	REG_ATTRIB(sum_h, sum_h);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_high_drilling_pore_id, high_drilling_pore, &HighDrillingPore::Create);
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
	name = _T("");
	province = _T("");
	city = _T("");
	capacity = 0.0;
	topo_geo = 0;
	hydr_geo = 0;
	ground_condition = 0;
	q_r = 0.0;
	gas_k1 = 0.0;
	gas_k2 = 0.0;
	stereo_schem_diagram = _T("");
	rock_gas_k2 = 0.0;
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
	REG_ATTRIB(name, name);
	REG_ATTRIB(province, province);
	REG_ATTRIB(city, city);
	REG_ATTRIB(capacity, capacity);
	REG_ATTRIB(topo_geo, topo_geo);
	REG_ATTRIB(hydr_geo, hydr_geo);
	REG_ATTRIB(ground_condition, ground_condition);
	REG_ATTRIB(q_r, q_r);
	REG_ATTRIB(gas_k1, gas_k1);
	REG_ATTRIB(gas_k2, gas_k2);
	REG_ATTRIB(stereo_schem_diagram, stereo_schem_diagram);
	REG_ATTRIB(rock_gas_k2, rock_gas_k2);
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
	REG_FOREGIN_KEY(cbm_tech_mode_id, tech_mode, &TechMode::Create);
	REG_FOREGIN_KEY(cbm_region_id, region, &Region::Create);
	REG_FOREGIN_KEY(cbm_account_id, account, &Account::Create);
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
	mode = 0;
	a = 0.0;
	qr = 0.0;
	comment = _T("");
	REG_ATTRIB(mode, mode);
	REG_ATTRIB(a, a);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &Coal::Create);
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
	t = 0.0;
	a0 = 0.0;
	d = 0.0;
	d1 = 0.0;
	m = 0.0;
	k = 0.0;
	delta_t = 0.0;
	x = 0.0;
	p_test = 0.0;
	p_cur = 0.0;
	b = 0.0;
	pt = 0.0;
	delta_p = 0.0;
	dh = 0.0;
	q_hun = 0.0;
	q_chun = 0.0;
	REG_ATTRIB(t, t);
	REG_ATTRIB(a0, a0);
	REG_ATTRIB(d, d);
	REG_ATTRIB(d1, d1);
	REG_ATTRIB(m, m);
	REG_ATTRIB(k, k);
	REG_ATTRIB(delta_t, delta_t);
	REG_ATTRIB(x, x);
	REG_ATTRIB(p_test, p_test);
	REG_ATTRIB(p_cur, p_cur);
	REG_ATTRIB(b, b);
	REG_ATTRIB(pt, pt);
	REG_ATTRIB(delta_p, delta_p);
	REG_ATTRIB(dh, dh);
	REG_ATTRIB(q_hun, q_hun);
	REG_ATTRIB(q_chun, q_chun);
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
	q = 0.0;
	v = 0.0;
	d = 0.0;
	p = 0.0;
	sigma = 0.0;
	delta = 0.0;
	comment = _T("");
	REG_ATTRIB(q, q);
	REG_ATTRIB(v, v);
	REG_ATTRIB(d, d);
	REG_ATTRIB(p, p);
	REG_ATTRIB(sigma, sigma);
	REG_ATTRIB(delta, delta);
	REG_ATTRIB(comment, comment);
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
	comment = _T("");
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mining_area_id, mining_area, &MiningArea::Create);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &Tunnel::Create);
}

CString Region::Table()
{
	return _T("cbm_region");
}

orm::RecordPtr Region::Create()
{
	return orm::RecordPtr(new Region());
}

Region::Region() : orm::Record(Region::Table())
{
	name = _T("");
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_base_id, base, &Base::Create);
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
	type = _T("");
	min_abundance = 0.0;
	max_abundance = 0.0;
	REG_ATTRIB(type, type);
	REG_ATTRIB(min_abundance, min_abundance);
	REG_ATTRIB(max_abundance, max_abundance);
}

CString SysInfo::Table()
{
	return _T("cbm_sys_info");
}

orm::RecordPtr SysInfo::Create()
{
	return orm::RecordPtr(new SysInfo());
}

SysInfo::SysInfo() : orm::Record(SysInfo::Table())
{
	REG_FOREGIN_KEY(cbm_account_id, account, &Account::Create);
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
	name = _T("");
	type = 0;
	c1 = 0;
	c2 = 0;
	c3 = 0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(type, type);
	REG_ATTRIB(c1, c1);
	REG_ATTRIB(c2, c2);
	REG_ATTRIB(c3, c3);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_region_id, region, &Region::Create);
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
	name = _T("");
	iskey = 0;
	doc = _T("");
	video = _T("");
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(iskey, iskey);
	REG_ATTRIB(doc, doc);
	REG_ATTRIB(video, video);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_region_id, region, &Region::Create);
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
	type = _T("");
	feature = _T("");
	comment = _T("");
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
	b = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	qa = 0.0;
	comment = _T("");
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
	a = 0.0;
	qr = 0.0;
	qa = 0.0;
	l = 0.0;
	layerable = 0;
	k1 = 0.0;
	k2 = 0.0;
	k3 = 0.0;
	kf = 0.0;
	method = 0;
	last_t = 0.0;
	comment = _T("");
	REG_ATTRIB(a, a);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(l, l);
	REG_ATTRIB(layerable, layerable);
	REG_ATTRIB(k1, k1);
	REG_ATTRIB(k2, k2);
	REG_ATTRIB(k3, k3);
	REG_ATTRIB(kf, kf);
	REG_ATTRIB(method, method);
	REG_ATTRIB(last_t, last_t);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_mining_area_id, mining_area, &MiningArea::Create);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &Tunnel::Create);
}

} // namespace cbm
