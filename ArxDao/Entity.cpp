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
	name = _T("");
	num = 0;
	h = 0.0;
	hp = 0.0;
	in_cz = 0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(num, num);
	REG_ATTRIB(h, h);
	REG_ATTRIB(hp, hp);
	REG_ATTRIB(in_cz, in_cz);
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
	qa = 0.0;
	qr = 0.0;
	fore_qr = 0.0;
	fore_qa = 0.0;
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
	hw_sum = 0.0;
	rock = 0;
	hhh = 0.0;
	layer_gap = 0.0;
	influence_factor = 0.0;
	res_a1 = 0.0;
	gas_x1 = 0.0;
	res_a2 = 0.0;
	gas_x2 = 0.0;
	pump_wc = 0.0;
	pump_k = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_k1 = 0.0;
	pore_datas = _T("");
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
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(fore_qr, fore_qr);
	REG_ATTRIB(fore_qa, fore_qa);
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
	REG_ATTRIB(hw_sum, hw_sum);
	REG_ATTRIB(rock, rock);
	REG_ATTRIB(hhh, hhh);
	REG_ATTRIB(layer_gap, layer_gap);
	REG_ATTRIB(influence_factor, influence_factor);
	REG_ATTRIB(res_a1, res_a1);
	REG_ATTRIB(gas_x1, gas_x1);
	REG_ATTRIB(res_a2, res_a2);
	REG_ATTRIB(gas_x2, gas_x2);
	REG_ATTRIB(pump_wc, pump_wc);
	REG_ATTRIB(pump_k, pump_k);
	REG_ATTRIB(pump_k2, pump_k2);
	REG_ATTRIB(pump_k3, pump_k3);
	REG_ATTRIB(pump_k4, pump_k4);
	REG_ATTRIB(pump_k1, pump_k1);
	REG_ATTRIB(pore_datas, pore_datas);
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

CString Complexity::Table()
{
	return _T("cbm_complexity");
}

orm::RecordPtr Complexity::Create()
{
	return orm::RecordPtr(new Complexity());
}

Complexity::Complexity() : orm::Record(Complexity::Table())
{
	name = _T("");
	details = _T("");
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(details, details);
	REG_ATTRIB(comment, comment);
}

CString DesignDrillingSurfTechnology::Table()
{
	return _T("cbm_design_drilling_surf_technology");
}

orm::RecordPtr DesignDrillingSurfTechnology::Create()
{
	return orm::RecordPtr(new DesignDrillingSurfTechnology());
}

DesignDrillingSurfTechnology::DesignDrillingSurfTechnology() : orm::Record(DesignDrillingSurfTechnology::Table())
{
	name = _T("");
	comment = _T("");
	v_offset = 0.0;
	h_offset = 0.0;
	dp = 0.0;
	gp = 0.0;
	leading_dist = 0.0;
	gbp = 0.0;
	l_stripe = 0.0;
	ls = 0.0;
	ws = 0.0;
	hs = 0.0;
	gs = 0.0;
	wd = 0.0;
	hd = 0.0;
	l1 = 0.0;
	l2 = 0.0;
	w = 0.0;
	h = 0.0;
	top_side = 0.0;
	bottom_side = 0.0;
	left_side = 0.0;
	right_side = 0.0;
	lm = 0.0;
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
	REG_ATTRIB(v_offset, v_offset);
	REG_ATTRIB(h_offset, h_offset);
	REG_ATTRIB(dp, dp);
	REG_ATTRIB(gp, gp);
	REG_ATTRIB(leading_dist, leading_dist);
	REG_ATTRIB(gbp, gbp);
	REG_ATTRIB(l_stripe, l_stripe);
	REG_ATTRIB(ls, ls);
	REG_ATTRIB(ws, ws);
	REG_ATTRIB(hs, hs);
	REG_ATTRIB(gs, gs);
	REG_ATTRIB(wd, wd);
	REG_ATTRIB(hd, hd);
	REG_ATTRIB(l1, l1);
	REG_ATTRIB(l2, l2);
	REG_ATTRIB(w, w);
	REG_ATTRIB(h, h);
	REG_ATTRIB(top_side, top_side);
	REG_ATTRIB(bottom_side, bottom_side);
	REG_ATTRIB(left_side, left_side);
	REG_ATTRIB(right_side, right_side);
	REG_ATTRIB(lm, lm);
	REG_FOREGIN_KEY(cbm_design_technology_id, design_technology, &DesignTechnology::Create);
}

CString DesignGoafTechnology::Table()
{
	return _T("cbm_design_goaf_technology");
}

orm::RecordPtr DesignGoafTechnology::Create()
{
	return orm::RecordPtr(new DesignGoafTechnology());
}

DesignGoafTechnology::DesignGoafTechnology() : orm::Record(DesignGoafTechnology::Table())
{
	name = _T("");
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_design_technology_id, design_technology, &DesignTechnology::Create);
}

CString DesignPore::Table()
{
	return _T("cbm_design_pore");
}

orm::RecordPtr DesignPore::Create()
{
	return orm::RecordPtr(new DesignPore());
}

DesignPore::DesignPore() : orm::Record(DesignPore::Table())
{
	name = _T("");
	d = 0.0;
	x1 = 0.0;
	y1 = 0.0;
	z1 = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	z2 = 0.0;
	length = 0.0;
	angle1 = 0.0;
	angle2 = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(d, d);
	REG_ATTRIB(x1, x1);
	REG_ATTRIB(y1, y1);
	REG_ATTRIB(z1, z1);
	REG_ATTRIB(x2, x2);
	REG_ATTRIB(y2, y2);
	REG_ATTRIB(z2, z2);
	REG_ATTRIB(length, length);
	REG_ATTRIB(angle1, angle1);
	REG_ATTRIB(angle2, angle2);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_design_site_id, design_site, &DesignSite::Create);
}

CString DesignSite::Table()
{
	return _T("cbm_design_site");
}

orm::RecordPtr DesignSite::Create()
{
	return orm::RecordPtr(new DesignSite());
}

DesignSite::DesignSite() : orm::Record(DesignSite::Table())
{
	name = _T("");
	w = 0.0;
	h = 0.0;
	x = 0.0;
	y = 0.0;
	z = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(w, w);
	REG_ATTRIB(h, h);
	REG_ATTRIB(x, x);
	REG_ATTRIB(y, y);
	REG_ATTRIB(z, z);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_design_technology_id, design_technology, &DesignTechnology::Create);
}

CString DesignTechnology::Table()
{
	return _T("cbm_design_technology");
}

orm::RecordPtr DesignTechnology::Create()
{
	return orm::RecordPtr(new DesignTechnology());
}

DesignTechnology::DesignTechnology() : orm::Record(DesignTechnology::Table())
{
	name = _T("");
	region = 0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(region, region);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &Coal::Create);
}

CString DesignWorkSurfTechnology::Table()
{
	return _T("cbm_design_work_surf_technology");
}

orm::RecordPtr DesignWorkSurfTechnology::Create()
{
	return orm::RecordPtr(new DesignWorkSurfTechnology());
}

DesignWorkSurfTechnology::DesignWorkSurfTechnology() : orm::Record(DesignWorkSurfTechnology::Table())
{
	name = _T("");
	comment = _T("");
	top_side = 0.0;
	bottom_side = 0.0;
	right_side = 0.0;
	l1 = 0.0;
	w = 0.0;
	h = 0.0;
	l2 = 0.0;
	left_side = 0.0;
	v_offset = 0.0;
	h_offset = 0.0;
	p_offset = 0.0;
	wd = 0.0;
	hd = 0.0;
	lm = 0.0;
	ws = 0.0;
	ls = 0.0;
	gs = 0.0;
	hs = 0.0;
	dp = 0.0;
	gp = 0.0;
	single_rock_tunnel = 0;
	d_offset = 0.0;
	pore_stubble = 0.0;
	pore_angle = 0.0;
	pore_type = 0;
	REG_ATTRIB(name, name);
	REG_ATTRIB(comment, comment);
	REG_ATTRIB(top_side, top_side);
	REG_ATTRIB(bottom_side, bottom_side);
	REG_ATTRIB(right_side, right_side);
	REG_ATTRIB(l1, l1);
	REG_ATTRIB(w, w);
	REG_ATTRIB(h, h);
	REG_ATTRIB(l2, l2);
	REG_ATTRIB(left_side, left_side);
	REG_ATTRIB(v_offset, v_offset);
	REG_ATTRIB(h_offset, h_offset);
	REG_ATTRIB(p_offset, p_offset);
	REG_ATTRIB(wd, wd);
	REG_ATTRIB(hd, hd);
	REG_ATTRIB(lm, lm);
	REG_ATTRIB(ws, ws);
	REG_ATTRIB(ls, ls);
	REG_ATTRIB(gs, gs);
	REG_ATTRIB(hs, hs);
	REG_ATTRIB(dp, dp);
	REG_ATTRIB(gp, gp);
	REG_ATTRIB(single_rock_tunnel, single_rock_tunnel);
	REG_ATTRIB(d_offset, d_offset);
	REG_ATTRIB(pore_stubble, pore_stubble);
	REG_ATTRIB(pore_angle, pore_angle);
	REG_ATTRIB(pore_type, pore_type);
	REG_FOREGIN_KEY(cbm_design_technology_id, design_technology, &DesignTechnology::Create);
}

CString DrillingRadiusParam::Table()
{
	return _T("cbm_drilling_radius_param");
}

orm::RecordPtr DrillingRadiusParam::Create()
{
	return orm::RecordPtr(new DrillingRadiusParam());
}

DrillingRadiusParam::DrillingRadiusParam() : orm::Record(DrillingRadiusParam::Table())
{
	name = _T("");
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
	REG_ATTRIB(name, name);
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
	name = _T("");
	qr = 0.0;
	qa = 0.0;
	fore_qr = 0.0;
	fore_qa = 0.0;
	q4 = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(fore_qr, fore_qr);
	REG_ATTRIB(fore_qa, fore_qa);
	REG_ATTRIB(q4, q4);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_area_id, work_area, &WorkArea::Create);
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
	name = _T("");
	l = 0.0;
	t = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(l, l);
	REG_ATTRIB(t, t);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &WorkSurf::Create);
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
	num = 0;
	length = 0.0;
	angle = 0.0;
	type = 0;
	comment = _T("");
	REG_ATTRIB(num, num);
	REG_ATTRIB(length, length);
	REG_ATTRIB(angle, angle);
	REG_ATTRIB(type, type);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_high_drilling_pore_param_id, high_drilling_pore_param, &HighDrillingPoreParam::Create);
}

CString HighDrillingPoreParam::Table()
{
	return _T("cbm_high_drilling_pore_param");
}

orm::RecordPtr HighDrillingPoreParam::Create()
{
	return orm::RecordPtr(new HighDrillingPoreParam());
}

HighDrillingPoreParam::HighDrillingPoreParam() : orm::Record(HighDrillingPoreParam::Table())
{
	name = _T("");
	lk = 0.0;
	lc = 0.0;
	lw = 0.0;
	n1 = 0;
	n2 = 0;
	beta = 0.0;
	ld = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(lk, lk);
	REG_ATTRIB(lc, lc);
	REG_ATTRIB(lw, lw);
	REG_ATTRIB(n1, n1);
	REG_ATTRIB(n2, n2);
	REG_ATTRIB(beta, beta);
	REG_ATTRIB(ld, ld);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_surf_id, work_surf, &WorkSurf::Create);
}

CString HighDrillingSiteParam::Table()
{
	return _T("cbm_high_drilling_site_param");
}

orm::RecordPtr HighDrillingSiteParam::Create()
{
	return orm::RecordPtr(new HighDrillingSiteParam());
}

HighDrillingSiteParam::HighDrillingSiteParam() : orm::Record(HighDrillingSiteParam::Table())
{
	name = _T("");
	l1 = 0.0;
	l2 = 0.0;
	lg = 0.0;
	hn = 0.0;
	theta = 0.0;
	q = 0.0;
	rtn = 0.0;
	hs = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(l1, l1);
	REG_ATTRIB(l2, l2);
	REG_ATTRIB(lg, lg);
	REG_ATTRIB(hn, hn);
	REG_ATTRIB(theta, theta);
	REG_ATTRIB(q, q);
	REG_ATTRIB(rtn, rtn);
	REG_ATTRIB(hs, hs);
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
	name = _T("");
	k = 0.0;
	rock = 0;
	hz_min = 0.0;
	hz_max = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
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
	name = _T("");
	x1 = 0;
	x2 = 0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(x1, x1);
	REG_ATTRIB(x2, x2);
	REG_ATTRIB(x3, x3);
	REG_ATTRIB(x4, x4);
	REG_ATTRIB(x5, x5);
	REG_ATTRIB(x6, x6);
	REG_ATTRIB(x7, x7);
	REG_ATTRIB(x8, x8);
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
	qr = 0.0;
	qa = 0.0;
	fore_qr = 0.0;
	fore_qa = 0.0;
	gas_k1 = 0.0;
	gas_k2 = 0.0;
	stereo_schem_diagram = _T("");
	rock_gas_k2 = 0.0;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	gas_w0 = 0.0;
	gas_wc2 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_k1 = 0.0;
	pump_k = 0.0;
	pump_wc = 0.0;
	reserve_gas = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(province, province);
	REG_ATTRIB(city, city);
	REG_ATTRIB(capacity, capacity);
	REG_ATTRIB(topo_geo, topo_geo);
	REG_ATTRIB(hydr_geo, hydr_geo);
	REG_ATTRIB(ground_condition, ground_condition);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(fore_qr, fore_qr);
	REG_ATTRIB(fore_qa, fore_qa);
	REG_ATTRIB(gas_k1, gas_k1);
	REG_ATTRIB(gas_k2, gas_k2);
	REG_ATTRIB(stereo_schem_diagram, stereo_schem_diagram);
	REG_ATTRIB(rock_gas_k2, rock_gas_k2);
	REG_ATTRIB(reserve_w1, reserve_w1);
	REG_ATTRIB(reserve_w2, reserve_w2);
	REG_ATTRIB(reserve_w3, reserve_w3);
	REG_ATTRIB(gas_w0, gas_w0);
	REG_ATTRIB(gas_wc2, gas_wc2);
	REG_ATTRIB(pump_k2, pump_k2);
	REG_ATTRIB(pump_k3, pump_k3);
	REG_ATTRIB(pump_k4, pump_k4);
	REG_ATTRIB(pump_k1, pump_k1);
	REG_ATTRIB(pump_k, pump_k);
	REG_ATTRIB(pump_wc, pump_wc);
	REG_ATTRIB(reserve_gas, reserve_gas);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_tech_mode_id, tech_mode, &TechMode::Create);
	REG_FOREGIN_KEY(cbm_region_id, region, &Region::Create);
	REG_FOREGIN_KEY(cbm_account_id, account, &Account::Create);
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
	name = _T("");
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
	REG_ATTRIB(name, name);
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
	name = _T("");
	q = 0.0;
	v = 0.0;
	d = 0.0;
	p = 0.0;
	sigma = 0.0;
	delta = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(q, q);
	REG_ATTRIB(v, v);
	REG_ATTRIB(d, d);
	REG_ATTRIB(p, p);
	REG_ATTRIB(sigma, sigma);
	REG_ATTRIB(delta, delta);
	REG_ATTRIB(comment, comment);
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
	name = _T("");
	min_abundance = 0.0;
	max_abundance = 0.0;
	REG_ATTRIB(name, name);
	REG_ATTRIB(min_abundance, min_abundance);
	REG_ATTRIB(max_abundance, max_abundance);
}

CString Rock::Table()
{
	return _T("cbm_rock");
}

orm::RecordPtr Rock::Create()
{
	return orm::RecordPtr(new Rock());
}

Rock::Rock() : orm::Record(Rock::Table())
{
	name = _T("");
	a = 0.0;
	b = 0.0;
	c = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(a, a);
	REG_ATTRIB(b, b);
	REG_ATTRIB(c, c);
	REG_ATTRIB(comment, comment);
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
	last_login_time = _T("");
	comment = _T("");
	REG_ATTRIB(last_login_time, last_login_time);
	REG_ATTRIB(comment, comment);
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
	name = _T("");
	feature = _T("");
	comment = _T("");
	REG_ATTRIB(name, name);
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
	name = _T("");
	b = 0.0;
	h = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	q3 = 0.0;
	q0 = 0.0;
	comment = _T("");
	type = 0;
	top_side = 0.0;
	bottom_side = 0.0;
	left_side = 0.0;
	right_side = 0.0;
	x1 = 0.0;
	y1 = 0.0;
	z1 = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	z2 = 0.0;
	REG_ATTRIB(name, name);
	REG_ATTRIB(b, b);
	REG_ATTRIB(h, h);
	REG_ATTRIB(l, l);
	REG_ATTRIB(s, s);
	REG_ATTRIB(d, d);
	REG_ATTRIB(wh, wh);
	REG_ATTRIB(v, v);
	REG_ATTRIB(q3, q3);
	REG_ATTRIB(q0, q0);
	REG_ATTRIB(comment, comment);
	REG_ATTRIB(type, type);
	REG_ATTRIB(top_side, top_side);
	REG_ATTRIB(bottom_side, bottom_side);
	REG_ATTRIB(left_side, left_side);
	REG_ATTRIB(right_side, right_side);
	REG_ATTRIB(x1, x1);
	REG_ATTRIB(y1, y1);
	REG_ATTRIB(z1, z1);
	REG_ATTRIB(x2, x2);
	REG_ATTRIB(y2, y2);
	REG_ATTRIB(z2, z2);
}

CString WorkArea::Table()
{
	return _T("cbm_work_area");
}

orm::RecordPtr WorkArea::Create()
{
	return orm::RecordPtr(new WorkArea());
}

WorkArea::WorkArea() : orm::Record(WorkArea::Table())
{
	name = _T("");
	mode = 0;
	a = 0.0;
	qr = 0.0;
	qa = 0.0;
	fore_qr = 0.0;
	fore_qa = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(mode, mode);
	REG_ATTRIB(a, a);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(fore_qr, fore_qr);
	REG_ATTRIB(fore_qa, fore_qa);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_coal_id, coal, &Coal::Create);
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
	name = _T("");
	a = 0.0;
	qr = 0.0;
	qa = 0.0;
	fore_qr = 0.0;
	fore_qa = 0.0;
	l1 = 0.0;
	l2 = 0.0;
	layerable = 0;
	k1 = 0.0;
	k2 = 0.0;
	k3 = 0.0;
	kf = 0.0;
	method = 0;
	last_t = 0.0;
	qr1 = 0.0;
	qr2 = 0.0;
	comment = _T("");
	REG_ATTRIB(name, name);
	REG_ATTRIB(a, a);
	REG_ATTRIB(qr, qr);
	REG_ATTRIB(qa, qa);
	REG_ATTRIB(fore_qr, fore_qr);
	REG_ATTRIB(fore_qa, fore_qa);
	REG_ATTRIB(l1, l1);
	REG_ATTRIB(l2, l2);
	REG_ATTRIB(layerable, layerable);
	REG_ATTRIB(k1, k1);
	REG_ATTRIB(k2, k2);
	REG_ATTRIB(k3, k3);
	REG_ATTRIB(kf, kf);
	REG_ATTRIB(method, method);
	REG_ATTRIB(last_t, last_t);
	REG_ATTRIB(qr1, qr1);
	REG_ATTRIB(qr2, qr2);
	REG_ATTRIB(comment, comment);
	REG_FOREGIN_KEY(cbm_work_area_id, work_area, &WorkArea::Create);
	REG_FOREGIN_KEY(cbm_tunnel_id, tunnel, &Tunnel::Create);
}

} // namespace cbm
