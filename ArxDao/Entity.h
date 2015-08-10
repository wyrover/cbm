#ifndef CBM_ALL_ENTITIES_H
#define CBM_ALL_ENTITIES_H

#include "Record.h"

namespace cbm {

class AdjLayer;
class Coal;
class DrillingRadius;
class DrillingSurf;
class EvalUnit;
class Help;
class HighDrillingPore;
class HighDrillingTunnel;
class HydrGeo;
class KeyLayer;
class Mine;
class MineBase;
class MineRegion;
class MiningArea;
class PoreFlow;
class PoreSize;
class ReadyTunnel;
class ResAbundance;
class TechMode;
class Technology;
class TopoGeo;
class Tunnel;
class WorkSurf;

class ARXDAO_DLLIMPEXP AdjLayer : public orm::Record
{
	WorkSurf work_surf;
	Coal coal;
	int layer_num;
	double layer_h;
	double layer_hp;
	int layer_cave_zone;
	CString comment;

}; // class AdjLayer

class ARXDAO_DLLIMPEXP Coal : public orm::Record
{
	Mine mine;
	CString coal_name;
	int coal_minable;
	double coal_thick;
	int coal_rank;
	int coal_quality;
	double layer_pressure;
	double gas_content;
	double gas_penetration;
	double f_value;
	int res_abundance;
	int const_complexity;
	int mine_index;
	double var_coeff;
	double coal_stability;
	double dip_angle;
	double caving_zone_height;
	double layer_gap;
	double influence_factor;
	double res_a1;
	double gas_x1;
	double res_a2;
	double gas_x2;
	double gas_wc;
	double coal_r;
	double coal_vr;
	double gas_w0;
	double gas_wc2;
	double gas_eta;
	double q_r;
	double q0;
	int eval_method;
	double q0_alpha;
	double qt_alpha;
	double t_alpha;
	double q_lambda;
	double r_lambda;
	double p0_lambda;
	double p1_lambda;
	double t_lambda;
	double a_lambda;
	double p1_k;
	double p2_k;
	double gas_q;
	double core_height;
	double core_area;
	double gas_viscosity;
	double decay_alpha;
	double permeability_lambda;
	double permeability_k;
	int eval_difficult;
	CString comment;

}; // class Coal

class ARXDAO_DLLIMPEXP DrillingRadius : public orm::Record
{
	Coal coal;
	double radius_r;
	double radius_l;
	double radius_k1;
	double radius_rho;
	double radius_q0;
	double radius_a;
	double radius_t;
	double radius_qm1;
	double radius_qm2;
	double radius_qsum;
	double radius_eta;

}; // class DrillingRadius

class ARXDAO_DLLIMPEXP DrillingSurf : public orm::Record
{
	Coal coal;
	Tunnel tunnel;
	double q_r;
	double q_a;
	double tw_q4;
	CString comment;

}; // class DrillingSurf

class ARXDAO_DLLIMPEXP EvalUnit : public orm::Record
{
	WorkSurf work_surf;
	double unit_l;
	double unit_t;
	CString comment;

}; // class EvalUnit

class ARXDAO_DLLIMPEXP Help : public orm::Record
{
	CString help_field;
	int help_type;
	CString help_value;
	CString comment;

}; // class Help

class ARXDAO_DLLIMPEXP HighDrillingPore : public orm::Record
{
	WorkSurf work_surf;
	double hdp_l1;
	double hdp_l2;
	double hdp_lg;
	double hdp_hz;
	double hdp_lk;
	double hdp_lc;
	double hdp_lw;
	double hdp_n;
	double hdp_beta;
	double hdp_ld;
	double hdp_lzi;
	double hdp_lzj;
	CString comment;

}; // class HighDrillingPore

class ARXDAO_DLLIMPEXP HighDrillingTunnel : public orm::Record
{
	WorkSurf work_surf;
	double hdt_k;
	int hdt_rock;
	double hdt_hz_min;
	double hdt_hz_max;
	CString comment;

}; // class HighDrillingTunnel

class ARXDAO_DLLIMPEXP HydrGeo : public orm::Record
{
	CString type;
	int x1;
	double x2;
	int x3;
	double x4;
	double x5;
	double x6;
	double x7;
	CString x8;

}; // class HydrGeo

class ARXDAO_DLLIMPEXP KeyLayer : public orm::Record
{
	HighDrillingPore high_drilling_pore;
	double key_hn;
	double key_thetan;
	double key_qn;
	double key_rtn;
	double key_sum_hn;
	CString comment;

}; // class KeyLayer

class ARXDAO_DLLIMPEXP Mine : public orm::Record
{
	MineRegion mine_region;
	CString username;
	CString password;
	CString mine_name;
	CString province;
	CString city;
	double capacity;
	int topo_geo;
	int hydr_geo;
	int ground_condition;
	double q_r;
	CString stereo_schem_diagram;
	double k_gas;
	double reserve_w1;
	double reserve_w2;
	double reserve_w3;
	double reserve_gas;
	double pump_kd;
	double pump_k1;
	double pump_k2;
	double pump_k3;
	double pump_k4;
	double pump_wc;
	CString comment;

}; // class Mine

class ARXDAO_DLLIMPEXP MineBase : public orm::Record
{
	CString name;
	CString comment;

}; // class MineBase

class ARXDAO_DLLIMPEXP MineRegion : public orm::Record
{
	MineBase mine_base;
	CString name;
	CString comment;

}; // class MineRegion

class ARXDAO_DLLIMPEXP MiningArea : public orm::Record
{
	Coal coal;
	int area_mode;
	double area_k;
	double a;
	double q_r;
	CString comment;

}; // class MiningArea

class ARXDAO_DLLIMPEXP PoreFlow : public orm::Record
{
	double flow_t;
	double flow_a0;
	double flow_d;
	double flow_d1;
	double flow_m;
	double flow_k;
	double flow_delta_t;
	double flow_x;
	double flow_p_test;
	double flow_p_cur;
	double flow_b;
	double flow_pt;
	double flow_delta_p;
	double flow_dh;
	double flow_q_hun;
	double flow_q_chun;

}; // class PoreFlow

class ARXDAO_DLLIMPEXP PoreSize : public orm::Record
{
	double size_q;
	double size_v;
	double size_d;
	double size_p;
	double size_sigma;
	double size_delta;

}; // class PoreSize

class ARXDAO_DLLIMPEXP ReadyTunnel : public orm::Record
{
	MiningArea mining_area;
	Tunnel tunnel;
	CString comment;

}; // class ReadyTunnel

class ARXDAO_DLLIMPEXP ResAbundance : public orm::Record
{
	CString type;
	double min_abundance;
	double max_abundance;

}; // class ResAbundance

class ARXDAO_DLLIMPEXP TechMode : public orm::Record
{
	MineRegion mine_region;
	CString name;
	int type;
	CString comment;

}; // class TechMode

class ARXDAO_DLLIMPEXP Technology : public orm::Record
{
	MineRegion mine_region;
	CString name;
	int iskey;
	CString doc;
	CString video;
	CString comment;

}; // class Technology

class ARXDAO_DLLIMPEXP TopoGeo : public orm::Record
{
	CString type;
	CString feature;
	CString comment;

}; // class TopoGeo

class ARXDAO_DLLIMPEXP Tunnel : public orm::Record
{
	double b;
	double l;
	double s;
	double d;
	double wh;
	double v;
	double qa;
	CString comment;

}; // class Tunnel

class ARXDAO_DLLIMPEXP WorkSurf : public orm::Record
{
	Tunnel tunnel;
	Coal coal;
	double a;
	double q_r;
	double q_a;
	double ws_l;
	int ws_layerable;
	double ws_k1;
	double ws_k2;
	double ws_k3;
	double ws_kf;
	double ws_h;
	int ws_method;
	double last_t;
	CString comment;

}; // class WorkSurf

} // namespace cbm

#endif // CBM_ALL_ENTITIES_H
