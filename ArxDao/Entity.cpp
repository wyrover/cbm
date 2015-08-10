#include "stdafx.h"
#include "Entity.h"

namespace cbm {
	AdjLayer() : orm::Record()
	{
		REG_ATTRIB(work_surf);
		REG_ATTRIB(coal);
		REG_ATTRIB(layer_num);
		REG_ATTRIB(layer_h);
		REG_ATTRIB(layer_hp);
		REG_ATTRIB(layer_cave_zone);
		REG_ATTRIB(comment);
	}
	Coal() : orm::Record()
	{
		REG_ATTRIB(mine);
		REG_ATTRIB(coal_name);
		REG_ATTRIB(coal_minable);
		REG_ATTRIB(coal_thick);
		REG_ATTRIB(coal_rank);
		REG_ATTRIB(coal_quality);
		REG_ATTRIB(layer_pressure);
		REG_ATTRIB(gas_content);
		REG_ATTRIB(gas_penetration);
		REG_ATTRIB(f_value);
		REG_ATTRIB(res_abundance);
		REG_ATTRIB(const_complexity);
		REG_ATTRIB(mine_index);
		REG_ATTRIB(var_coeff);
		REG_ATTRIB(coal_stability);
		REG_ATTRIB(dip_angle);
		REG_ATTRIB(caving_zone_height);
		REG_ATTRIB(layer_gap);
		REG_ATTRIB(influence_factor);
		REG_ATTRIB(res_a1);
		REG_ATTRIB(gas_x1);
		REG_ATTRIB(res_a2);
		REG_ATTRIB(gas_x2);
		REG_ATTRIB(gas_wc);
		REG_ATTRIB(coal_r);
		REG_ATTRIB(coal_vr);
		REG_ATTRIB(gas_w0);
		REG_ATTRIB(gas_wc2);
		REG_ATTRIB(gas_eta);
		REG_ATTRIB(q_r);
		REG_ATTRIB(q0);
		REG_ATTRIB(eval_method);
		REG_ATTRIB(q0_alpha);
		REG_ATTRIB(qt_alpha);
		REG_ATTRIB(t_alpha);
		REG_ATTRIB(q_lambda);
		REG_ATTRIB(r_lambda);
		REG_ATTRIB(p0_lambda);
		REG_ATTRIB(p1_lambda);
		REG_ATTRIB(t_lambda);
		REG_ATTRIB(a_lambda);
		REG_ATTRIB(p1_k);
		REG_ATTRIB(p2_k);
		REG_ATTRIB(gas_q);
		REG_ATTRIB(core_height);
		REG_ATTRIB(core_area);
		REG_ATTRIB(gas_viscosity);
		REG_ATTRIB(decay_alpha);
		REG_ATTRIB(permeability_lambda);
		REG_ATTRIB(permeability_k);
		REG_ATTRIB(eval_difficult);
		REG_ATTRIB(comment);
	}
	DrillingRadius() : orm::Record()
	{
		REG_ATTRIB(coal);
		REG_ATTRIB(radius_r);
		REG_ATTRIB(radius_l);
		REG_ATTRIB(radius_k1);
		REG_ATTRIB(radius_rho);
		REG_ATTRIB(radius_q0);
		REG_ATTRIB(radius_a);
		REG_ATTRIB(radius_t);
		REG_ATTRIB(radius_qm1);
		REG_ATTRIB(radius_qm2);
		REG_ATTRIB(radius_qsum);
		REG_ATTRIB(radius_eta);
	}
	DrillingSurf() : orm::Record()
	{
		REG_ATTRIB(coal);
		REG_ATTRIB(tunnel);
		REG_ATTRIB(q_r);
		REG_ATTRIB(q_a);
		REG_ATTRIB(tw_q4);
		REG_ATTRIB(comment);
	}
	EvalUnit() : orm::Record()
	{
		REG_ATTRIB(work_surf);
		REG_ATTRIB(unit_l);
		REG_ATTRIB(unit_t);
		REG_ATTRIB(comment);
	}
	Help() : orm::Record()
	{
		REG_ATTRIB(help_field);
		REG_ATTRIB(help_type);
		REG_ATTRIB(help_value);
		REG_ATTRIB(comment);
	}
	HighDrillingPore() : orm::Record()
	{
		REG_ATTRIB(work_surf);
		REG_ATTRIB(hdp_l1);
		REG_ATTRIB(hdp_l2);
		REG_ATTRIB(hdp_lg);
		REG_ATTRIB(hdp_hz);
		REG_ATTRIB(hdp_lk);
		REG_ATTRIB(hdp_lc);
		REG_ATTRIB(hdp_lw);
		REG_ATTRIB(hdp_n);
		REG_ATTRIB(hdp_beta);
		REG_ATTRIB(hdp_ld);
		REG_ATTRIB(hdp_lzi);
		REG_ATTRIB(hdp_lzj);
		REG_ATTRIB(comment);
	}
	HighDrillingTunnel() : orm::Record()
	{
		REG_ATTRIB(work_surf);
		REG_ATTRIB(hdt_k);
		REG_ATTRIB(hdt_rock);
		REG_ATTRIB(hdt_hz_min);
		REG_ATTRIB(hdt_hz_max);
		REG_ATTRIB(comment);
	}
	HydrGeo() : orm::Record()
	{
		REG_ATTRIB(type);
		REG_ATTRIB(x1);
		REG_ATTRIB(x2);
		REG_ATTRIB(x3);
		REG_ATTRIB(x4);
		REG_ATTRIB(x5);
		REG_ATTRIB(x6);
		REG_ATTRIB(x7);
		REG_ATTRIB(x8);
	}
	KeyLayer() : orm::Record()
	{
		REG_ATTRIB(high_drilling_pore);
		REG_ATTRIB(key_hn);
		REG_ATTRIB(key_thetan);
		REG_ATTRIB(key_qn);
		REG_ATTRIB(key_rtn);
		REG_ATTRIB(key_sum_hn);
		REG_ATTRIB(comment);
	}
	Mine() : orm::Record()
	{
		REG_ATTRIB(mine_region);
		REG_ATTRIB(username);
		REG_ATTRIB(password);
		REG_ATTRIB(mine_name);
		REG_ATTRIB(province);
		REG_ATTRIB(city);
		REG_ATTRIB(capacity);
		REG_ATTRIB(topo_geo);
		REG_ATTRIB(hydr_geo);
		REG_ATTRIB(ground_condition);
		REG_ATTRIB(q_r);
		REG_ATTRIB(stereo_schem_diagram);
		REG_ATTRIB(k_gas);
		REG_ATTRIB(reserve_w1);
		REG_ATTRIB(reserve_w2);
		REG_ATTRIB(reserve_w3);
		REG_ATTRIB(reserve_gas);
		REG_ATTRIB(pump_kd);
		REG_ATTRIB(pump_k1);
		REG_ATTRIB(pump_k2);
		REG_ATTRIB(pump_k3);
		REG_ATTRIB(pump_k4);
		REG_ATTRIB(pump_wc);
		REG_ATTRIB(comment);
	}
	MineBase() : orm::Record()
	{
		REG_ATTRIB(name);
		REG_ATTRIB(comment);
	}
	MineRegion() : orm::Record()
	{
		REG_ATTRIB(mine_base);
		REG_ATTRIB(name);
		REG_ATTRIB(comment);
	}
	MiningArea() : orm::Record()
	{
		REG_ATTRIB(coal);
		REG_ATTRIB(area_mode);
		REG_ATTRIB(area_k);
		REG_ATTRIB(a);
		REG_ATTRIB(q_r);
		REG_ATTRIB(comment);
	}
	PoreFlow() : orm::Record()
	{
		REG_ATTRIB(flow_t);
		REG_ATTRIB(flow_a0);
		REG_ATTRIB(flow_d);
		REG_ATTRIB(flow_d1);
		REG_ATTRIB(flow_m);
		REG_ATTRIB(flow_k);
		REG_ATTRIB(flow_delta_t);
		REG_ATTRIB(flow_x);
		REG_ATTRIB(flow_p_test);
		REG_ATTRIB(flow_p_cur);
		REG_ATTRIB(flow_b);
		REG_ATTRIB(flow_pt);
		REG_ATTRIB(flow_delta_p);
		REG_ATTRIB(flow_dh);
		REG_ATTRIB(flow_q_hun);
		REG_ATTRIB(flow_q_chun);
	}
	PoreSize() : orm::Record()
	{
		REG_ATTRIB(size_q);
		REG_ATTRIB(size_v);
		REG_ATTRIB(size_d);
		REG_ATTRIB(size_p);
		REG_ATTRIB(size_sigma);
		REG_ATTRIB(size_delta);
	}
	ReadyTunnel() : orm::Record()
	{
		REG_ATTRIB(mining_area);
		REG_ATTRIB(tunnel);
		REG_ATTRIB(comment);
	}
	ResAbundance() : orm::Record()
	{
		REG_ATTRIB(type);
		REG_ATTRIB(min_abundance);
		REG_ATTRIB(max_abundance);
	}
	TechMode() : orm::Record()
	{
		REG_ATTRIB(mine_region);
		REG_ATTRIB(name);
		REG_ATTRIB(type);
		REG_ATTRIB(comment);
	}
	Technology() : orm::Record()
	{
		REG_ATTRIB(mine_region);
		REG_ATTRIB(name);
		REG_ATTRIB(iskey);
		REG_ATTRIB(doc);
		REG_ATTRIB(video);
		REG_ATTRIB(comment);
	}
	TopoGeo() : orm::Record()
	{
		REG_ATTRIB(type);
		REG_ATTRIB(feature);
		REG_ATTRIB(comment);
	}
	Tunnel() : orm::Record()
	{
		REG_ATTRIB(b);
		REG_ATTRIB(l);
		REG_ATTRIB(s);
		REG_ATTRIB(d);
		REG_ATTRIB(wh);
		REG_ATTRIB(v);
		REG_ATTRIB(qa);
		REG_ATTRIB(comment);
	}
	WorkSurf() : orm::Record()
	{
		REG_ATTRIB(tunnel);
		REG_ATTRIB(coal);
		REG_ATTRIB(a);
		REG_ATTRIB(q_r);
		REG_ATTRIB(q_a);
		REG_ATTRIB(ws_l);
		REG_ATTRIB(ws_layerable);
		REG_ATTRIB(ws_k1);
		REG_ATTRIB(ws_k2);
		REG_ATTRIB(ws_k3);
		REG_ATTRIB(ws_kf);
		REG_ATTRIB(ws_h);
		REG_ATTRIB(ws_method);
		REG_ATTRIB(last_t);
		REG_ATTRIB(comment);
	}


} // namespace cbm
