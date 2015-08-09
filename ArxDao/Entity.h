#ifndef CBM_ALL_ENTITIES_H
#define CBM_ALL_ENTITIES_H

#include "BaseRecord.h"

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

class ARXDAO_DLLIMPEXP AdjLayer : public BaseRecord<AdjLayer>
{
public:
	SAR_INIT();
	AdjLayer() : BaseRecord<AdjLayer>() {}
	AdjLayer(int id) : BaseRecord<AdjLayer>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<WorkSurf>() ) getOne<WorkSurf>( work_surf );
		if( isset<Coal>() ) getOne<Coal>( coal );
		get( SAR_TEXT("layer_num"), layer_num, 0);
		get( SAR_TEXT("layer_h"), layer_h, 0.0);
		get( SAR_TEXT("layer_hp"), layer_hp, 0.0);
		get( SAR_TEXT("layer_cave_zone"), layer_cave_zone, 0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( work_surf.has_been_saved() ) setOne<WorkSurf>( work_surf );
		if( coal.has_been_saved() ) setOne<Coal>( coal );
		set( SAR_TEXT("layer_num"), layer_num );
		set( SAR_TEXT("layer_h"), layer_h );
		set( SAR_TEXT("layer_hp"), layer_hp );
		set( SAR_TEXT("layer_cave_zone"), layer_cave_zone );
		set( SAR_TEXT("comment"), comment );
	}

public:
	WorkSurf work_surf;
	Coal coal;
	int layer_num;
	double layer_h;
	double layer_hp;
	int layer_cave_zone;
	tstring comment;

}; // class AdjLayer

class ARXDAO_DLLIMPEXP Coal : public BaseRecord<Coal>
{
public:
	SAR_INIT();
	Coal() : BaseRecord<Coal>() {}
	Coal(int id) : BaseRecord<Coal>( id ) {}

protected:
	void subUpdate()
	{
		adj_layers = getMany<AdjLayer>();
		drilling_radius = getMany<DrillingRadius>();
		drilling_surves = getMany<DrillingSurf>();
		mining_areas = getMany<MiningArea>();
		work_surves = getMany<WorkSurf>();
		if( isset<Mine>() ) getOne<Mine>( mine );
		get( SAR_TEXT("coal_name"), coal_name, SAR_TEXT("NULL"));
		get( SAR_TEXT("coal_minable"), coal_minable, 0);
		get( SAR_TEXT("coal_thick"), coal_thick, 0.0);
		get( SAR_TEXT("coal_rank"), coal_rank, 0);
		get( SAR_TEXT("coal_quality"), coal_quality, 0);
		get( SAR_TEXT("layer_pressure"), layer_pressure, 0.0);
		get( SAR_TEXT("gas_content"), gas_content, 0.0);
		get( SAR_TEXT("gas_penetration"), gas_penetration, 0.0);
		get( SAR_TEXT("f_value"), f_value, 0.0);
		get( SAR_TEXT("res_abundance"), res_abundance, 0);
		get( SAR_TEXT("const_complexity"), const_complexity, 0);
		get( SAR_TEXT("mine_index"), mine_index, 0);
		get( SAR_TEXT("var_coeff"), var_coeff, 0.0);
		get( SAR_TEXT("coal_stability"), coal_stability, 0.0);
		get( SAR_TEXT("dip_angle"), dip_angle, 0.0);
		get( SAR_TEXT("caving_zone_height"), caving_zone_height, 0.0);
		get( SAR_TEXT("layer_gap"), layer_gap, 0.0);
		get( SAR_TEXT("influence_factor"), influence_factor, 0.0);
		get( SAR_TEXT("res_a1"), res_a1, 0.0);
		get( SAR_TEXT("gas_x1"), gas_x1, 0.0);
		get( SAR_TEXT("res_a2"), res_a2, 0.0);
		get( SAR_TEXT("gas_x2"), gas_x2, 0.0);
		get( SAR_TEXT("gas_wc"), gas_wc, 0.0);
		get( SAR_TEXT("coal_r"), coal_r, 0.0);
		get( SAR_TEXT("coal_vr"), coal_vr, 0.0);
		get( SAR_TEXT("gas_w0"), gas_w0, 0.0);
		get( SAR_TEXT("gas_wc2"), gas_wc2, 0.0);
		get( SAR_TEXT("gas_eta"), gas_eta, 0.0);
		get( SAR_TEXT("q_r"), q_r, 0.0);
		get( SAR_TEXT("q0"), q0, 0.0);
		get( SAR_TEXT("eval_method"), eval_method, 0);
		get( SAR_TEXT("q0_alpha"), q0_alpha, 0.0);
		get( SAR_TEXT("qt_alpha"), qt_alpha, 0.0);
		get( SAR_TEXT("t_alpha"), t_alpha, 0.0);
		get( SAR_TEXT("q_lambda"), q_lambda, 0.0);
		get( SAR_TEXT("r_lambda"), r_lambda, 0.0);
		get( SAR_TEXT("p0_lambda"), p0_lambda, 0.0);
		get( SAR_TEXT("p1_lambda"), p1_lambda, 0.0);
		get( SAR_TEXT("t_lambda"), t_lambda, 0.0);
		get( SAR_TEXT("a_lambda"), a_lambda, 0.0);
		get( SAR_TEXT("p1_k"), p1_k, 0.0);
		get( SAR_TEXT("p2_k"), p2_k, 0.0);
		get( SAR_TEXT("gas_q"), gas_q, 0.0);
		get( SAR_TEXT("core_height"), core_height, 0.0);
		get( SAR_TEXT("core_area"), core_area, 0.0);
		get( SAR_TEXT("gas_viscosity"), gas_viscosity, 0.0);
		get( SAR_TEXT("decay_alpha"), decay_alpha, 0.0);
		get( SAR_TEXT("permeability_lambda"), permeability_lambda, 0.0);
		get( SAR_TEXT("permeability_k"), permeability_k, 0.0);
		get( SAR_TEXT("eval_difficult"), eval_difficult, 0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<AdjLayer>( adj_layers );
		setMany<DrillingRadius>( drilling_radius );
		setMany<DrillingSurf>( drilling_surves );
		setMany<MiningArea>( mining_areas );
		setMany<WorkSurf>( work_surves );
		if( mine.has_been_saved() ) setOne<Mine>( mine );
		set( SAR_TEXT("coal_name"), coal_name );
		set( SAR_TEXT("coal_minable"), coal_minable );
		set( SAR_TEXT("coal_thick"), coal_thick );
		set( SAR_TEXT("coal_rank"), coal_rank );
		set( SAR_TEXT("coal_quality"), coal_quality );
		set( SAR_TEXT("layer_pressure"), layer_pressure );
		set( SAR_TEXT("gas_content"), gas_content );
		set( SAR_TEXT("gas_penetration"), gas_penetration );
		set( SAR_TEXT("f_value"), f_value );
		set( SAR_TEXT("res_abundance"), res_abundance );
		set( SAR_TEXT("const_complexity"), const_complexity );
		set( SAR_TEXT("mine_index"), mine_index );
		set( SAR_TEXT("var_coeff"), var_coeff );
		set( SAR_TEXT("coal_stability"), coal_stability );
		set( SAR_TEXT("dip_angle"), dip_angle );
		set( SAR_TEXT("caving_zone_height"), caving_zone_height );
		set( SAR_TEXT("layer_gap"), layer_gap );
		set( SAR_TEXT("influence_factor"), influence_factor );
		set( SAR_TEXT("res_a1"), res_a1 );
		set( SAR_TEXT("gas_x1"), gas_x1 );
		set( SAR_TEXT("res_a2"), res_a2 );
		set( SAR_TEXT("gas_x2"), gas_x2 );
		set( SAR_TEXT("gas_wc"), gas_wc );
		set( SAR_TEXT("coal_r"), coal_r );
		set( SAR_TEXT("coal_vr"), coal_vr );
		set( SAR_TEXT("gas_w0"), gas_w0 );
		set( SAR_TEXT("gas_wc2"), gas_wc2 );
		set( SAR_TEXT("gas_eta"), gas_eta );
		set( SAR_TEXT("q_r"), q_r );
		set( SAR_TEXT("q0"), q0 );
		set( SAR_TEXT("eval_method"), eval_method );
		set( SAR_TEXT("q0_alpha"), q0_alpha );
		set( SAR_TEXT("qt_alpha"), qt_alpha );
		set( SAR_TEXT("t_alpha"), t_alpha );
		set( SAR_TEXT("q_lambda"), q_lambda );
		set( SAR_TEXT("r_lambda"), r_lambda );
		set( SAR_TEXT("p0_lambda"), p0_lambda );
		set( SAR_TEXT("p1_lambda"), p1_lambda );
		set( SAR_TEXT("t_lambda"), t_lambda );
		set( SAR_TEXT("a_lambda"), a_lambda );
		set( SAR_TEXT("p1_k"), p1_k );
		set( SAR_TEXT("p2_k"), p2_k );
		set( SAR_TEXT("gas_q"), gas_q );
		set( SAR_TEXT("core_height"), core_height );
		set( SAR_TEXT("core_area"), core_area );
		set( SAR_TEXT("gas_viscosity"), gas_viscosity );
		set( SAR_TEXT("decay_alpha"), decay_alpha );
		set( SAR_TEXT("permeability_lambda"), permeability_lambda );
		set( SAR_TEXT("permeability_k"), permeability_k );
		set( SAR_TEXT("eval_difficult"), eval_difficult );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<AdjLayer> adj_layers;
	ObjGroup<DrillingRadius> drilling_radius;
	ObjGroup<DrillingSurf> drilling_surves;
	ObjGroup<MiningArea> mining_areas;
	ObjGroup<WorkSurf> work_surves;
	Mine mine;
	tstring coal_name;
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
	tstring comment;

}; // class Coal

class ARXDAO_DLLIMPEXP DrillingRadius : public BaseRecord<DrillingRadius>
{
public:
	SAR_INIT();
	DrillingRadius() : BaseRecord<DrillingRadius>() {}
	DrillingRadius(int id) : BaseRecord<DrillingRadius>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<Coal>() ) getOne<Coal>( coal );
		get( SAR_TEXT("radius_r"), radius_r, 0.0);
		get( SAR_TEXT("radius_l"), radius_l, 0.0);
		get( SAR_TEXT("radius_k1"), radius_k1, 0.0);
		get( SAR_TEXT("radius_rho"), radius_rho, 0.0);
		get( SAR_TEXT("radius_q0"), radius_q0, 0.0);
		get( SAR_TEXT("radius_a"), radius_a, 0.0);
		get( SAR_TEXT("radius_t"), radius_t, 0.0);
		get( SAR_TEXT("radius_qm1"), radius_qm1, 0.0);
		get( SAR_TEXT("radius_qm2"), radius_qm2, 0.0);
		get( SAR_TEXT("radius_qsum"), radius_qsum, 0.0);
		get( SAR_TEXT("radius_eta"), radius_eta, 0.0);
	}
	void subSave()
	{
		if( coal.has_been_saved() ) setOne<Coal>( coal );
		set( SAR_TEXT("radius_r"), radius_r );
		set( SAR_TEXT("radius_l"), radius_l );
		set( SAR_TEXT("radius_k1"), radius_k1 );
		set( SAR_TEXT("radius_rho"), radius_rho );
		set( SAR_TEXT("radius_q0"), radius_q0 );
		set( SAR_TEXT("radius_a"), radius_a );
		set( SAR_TEXT("radius_t"), radius_t );
		set( SAR_TEXT("radius_qm1"), radius_qm1 );
		set( SAR_TEXT("radius_qm2"), radius_qm2 );
		set( SAR_TEXT("radius_qsum"), radius_qsum );
		set( SAR_TEXT("radius_eta"), radius_eta );
	}

public:
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

class ARXDAO_DLLIMPEXP DrillingSurf : public BaseRecord<DrillingSurf>
{
public:
	SAR_INIT();
	DrillingSurf() : BaseRecord<DrillingSurf>() {}
	DrillingSurf(int id) : BaseRecord<DrillingSurf>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<Coal>() ) getOne<Coal>( coal );
		if( isset<Tunnel>() ) getOne<Tunnel>( tunnel );
		get( SAR_TEXT("q_r"), q_r, 0.0);
		get( SAR_TEXT("q_a"), q_a, 0.0);
		get( SAR_TEXT("tw_q4"), tw_q4, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( coal.has_been_saved() ) setOne<Coal>( coal );
		if( tunnel.has_been_saved() ) setOne<Tunnel>( tunnel );
		set( SAR_TEXT("q_r"), q_r );
		set( SAR_TEXT("q_a"), q_a );
		set( SAR_TEXT("tw_q4"), tw_q4 );
		set( SAR_TEXT("comment"), comment );
	}

public:
	Coal coal;
	Tunnel tunnel;
	double q_r;
	double q_a;
	double tw_q4;
	tstring comment;

}; // class DrillingSurf

class ARXDAO_DLLIMPEXP EvalUnit : public BaseRecord<EvalUnit>
{
public:
	SAR_INIT();
	EvalUnit() : BaseRecord<EvalUnit>() {}
	EvalUnit(int id) : BaseRecord<EvalUnit>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<WorkSurf>() ) getOne<WorkSurf>( work_surf );
		get( SAR_TEXT("unit_l"), unit_l, 0.0);
		get( SAR_TEXT("unit_t"), unit_t, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( work_surf.has_been_saved() ) setOne<WorkSurf>( work_surf );
		set( SAR_TEXT("unit_l"), unit_l );
		set( SAR_TEXT("unit_t"), unit_t );
		set( SAR_TEXT("comment"), comment );
	}

public:
	WorkSurf work_surf;
	double unit_l;
	double unit_t;
	tstring comment;

}; // class EvalUnit

class ARXDAO_DLLIMPEXP Help : public BaseRecord<Help>
{
public:
	SAR_INIT();
	Help() : BaseRecord<Help>() {}
	Help(int id) : BaseRecord<Help>( id ) {}

protected:
	void subUpdate()
	{
		get( SAR_TEXT("help_field"), help_field, SAR_TEXT("NULL"));
		get( SAR_TEXT("help_type"), help_type, 0);
		get( SAR_TEXT("help_value"), help_value, SAR_TEXT("NULL"));
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		set( SAR_TEXT("help_field"), help_field );
		set( SAR_TEXT("help_type"), help_type );
		set( SAR_TEXT("help_value"), help_value );
		set( SAR_TEXT("comment"), comment );
	}

public:
	tstring help_field;
	int help_type;
	tstring help_value;
	tstring comment;

}; // class Help

class ARXDAO_DLLIMPEXP HighDrillingPore : public BaseRecord<HighDrillingPore>
{
public:
	SAR_INIT();
	HighDrillingPore() : BaseRecord<HighDrillingPore>() {}
	HighDrillingPore(int id) : BaseRecord<HighDrillingPore>( id ) {}

protected:
	void subUpdate()
	{
		key_layers = getMany<KeyLayer>();
		if( isset<WorkSurf>() ) getOne<WorkSurf>( work_surf );
		get( SAR_TEXT("hdp_l1"), hdp_l1, 0.0);
		get( SAR_TEXT("hdp_l2"), hdp_l2, 0.0);
		get( SAR_TEXT("hdp_lg"), hdp_lg, 0.0);
		get( SAR_TEXT("hdp_hz"), hdp_hz, 0.0);
		get( SAR_TEXT("hdp_lk"), hdp_lk, 0.0);
		get( SAR_TEXT("hdp_lc"), hdp_lc, 0.0);
		get( SAR_TEXT("hdp_lw"), hdp_lw, 0.0);
		get( SAR_TEXT("hdp_n"), hdp_n, 0.0);
		get( SAR_TEXT("hdp_beta"), hdp_beta, 0.0);
		get( SAR_TEXT("hdp_ld"), hdp_ld, 0.0);
		get( SAR_TEXT("hdp_lzi"), hdp_lzi, 0.0);
		get( SAR_TEXT("hdp_lzj"), hdp_lzj, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<KeyLayer>( key_layers );
		if( work_surf.has_been_saved() ) setOne<WorkSurf>( work_surf );
		set( SAR_TEXT("hdp_l1"), hdp_l1 );
		set( SAR_TEXT("hdp_l2"), hdp_l2 );
		set( SAR_TEXT("hdp_lg"), hdp_lg );
		set( SAR_TEXT("hdp_hz"), hdp_hz );
		set( SAR_TEXT("hdp_lk"), hdp_lk );
		set( SAR_TEXT("hdp_lc"), hdp_lc );
		set( SAR_TEXT("hdp_lw"), hdp_lw );
		set( SAR_TEXT("hdp_n"), hdp_n );
		set( SAR_TEXT("hdp_beta"), hdp_beta );
		set( SAR_TEXT("hdp_ld"), hdp_ld );
		set( SAR_TEXT("hdp_lzi"), hdp_lzi );
		set( SAR_TEXT("hdp_lzj"), hdp_lzj );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<KeyLayer> key_layers;
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
	tstring comment;

}; // class HighDrillingPore

class ARXDAO_DLLIMPEXP HighDrillingTunnel : public BaseRecord<HighDrillingTunnel>
{
public:
	SAR_INIT();
	HighDrillingTunnel() : BaseRecord<HighDrillingTunnel>() {}
	HighDrillingTunnel(int id) : BaseRecord<HighDrillingTunnel>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<WorkSurf>() ) getOne<WorkSurf>( work_surf );
		get( SAR_TEXT("hdt_k"), hdt_k, 0.0);
		get( SAR_TEXT("hdt_rock"), hdt_rock, 0);
		get( SAR_TEXT("hdt_hz_min"), hdt_hz_min, 0.0);
		get( SAR_TEXT("hdt_hz_max"), hdt_hz_max, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( work_surf.has_been_saved() ) setOne<WorkSurf>( work_surf );
		set( SAR_TEXT("hdt_k"), hdt_k );
		set( SAR_TEXT("hdt_rock"), hdt_rock );
		set( SAR_TEXT("hdt_hz_min"), hdt_hz_min );
		set( SAR_TEXT("hdt_hz_max"), hdt_hz_max );
		set( SAR_TEXT("comment"), comment );
	}

public:
	WorkSurf work_surf;
	double hdt_k;
	int hdt_rock;
	double hdt_hz_min;
	double hdt_hz_max;
	tstring comment;

}; // class HighDrillingTunnel

class ARXDAO_DLLIMPEXP HydrGeo : public BaseRecord<HydrGeo>
{
public:
	SAR_INIT();
	HydrGeo() : BaseRecord<HydrGeo>() {}
	HydrGeo(int id) : BaseRecord<HydrGeo>( id ) {}

protected:
	void subUpdate()
	{
		get( SAR_TEXT("type"), type, SAR_TEXT("NULL"));
		get( SAR_TEXT("x1"), x1, 0);
		get( SAR_TEXT("x2"), x2, 0.0);
		get( SAR_TEXT("x3"), x3, 0);
		get( SAR_TEXT("x4"), x4, 0.0);
		get( SAR_TEXT("x5"), x5, 0.0);
		get( SAR_TEXT("x6"), x6, 0.0);
		get( SAR_TEXT("x7"), x7, 0.0);
		get( SAR_TEXT("x8"), x8, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		set( SAR_TEXT("type"), type );
		set( SAR_TEXT("x1"), x1 );
		set( SAR_TEXT("x2"), x2 );
		set( SAR_TEXT("x3"), x3 );
		set( SAR_TEXT("x4"), x4 );
		set( SAR_TEXT("x5"), x5 );
		set( SAR_TEXT("x6"), x6 );
		set( SAR_TEXT("x7"), x7 );
		set( SAR_TEXT("x8"), x8 );
	}

public:
	tstring type;
	int x1;
	double x2;
	int x3;
	double x4;
	double x5;
	double x6;
	double x7;
	tstring x8;

}; // class HydrGeo

class ARXDAO_DLLIMPEXP KeyLayer : public BaseRecord<KeyLayer>
{
public:
	SAR_INIT();
	KeyLayer() : BaseRecord<KeyLayer>() {}
	KeyLayer(int id) : BaseRecord<KeyLayer>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<HighDrillingPore>() ) getOne<HighDrillingPore>( high_drilling_pore );
		get( SAR_TEXT("key_hn"), key_hn, 0.0);
		get( SAR_TEXT("key_thetan"), key_thetan, 0.0);
		get( SAR_TEXT("key_qn"), key_qn, 0.0);
		get( SAR_TEXT("key_rtn"), key_rtn, 0.0);
		get( SAR_TEXT("key_sum_hn"), key_sum_hn, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( high_drilling_pore.has_been_saved() ) setOne<HighDrillingPore>( high_drilling_pore );
		set( SAR_TEXT("key_hn"), key_hn );
		set( SAR_TEXT("key_thetan"), key_thetan );
		set( SAR_TEXT("key_qn"), key_qn );
		set( SAR_TEXT("key_rtn"), key_rtn );
		set( SAR_TEXT("key_sum_hn"), key_sum_hn );
		set( SAR_TEXT("comment"), comment );
	}

public:
	HighDrillingPore high_drilling_pore;
	double key_hn;
	double key_thetan;
	double key_qn;
	double key_rtn;
	double key_sum_hn;
	tstring comment;

}; // class KeyLayer

class ARXDAO_DLLIMPEXP Mine : public BaseRecord<Mine>
{
public:
	SAR_INIT();
	Mine() : BaseRecord<Mine>() {}
	Mine(int id) : BaseRecord<Mine>( id ) {}

protected:
	void subUpdate()
	{
		coals = getMany<Coal>();
		if( isset<MineRegion>() ) getOne<MineRegion>( mine_region );
		get( SAR_TEXT("username"), username, SAR_TEXT("NULL"));
		get( SAR_TEXT("password"), password, SAR_TEXT("NULL"));
		get( SAR_TEXT("mine_name"), mine_name, SAR_TEXT("NULL"));
		get( SAR_TEXT("province"), province, SAR_TEXT("NULL"));
		get( SAR_TEXT("city"), city, SAR_TEXT("NULL"));
		get( SAR_TEXT("capacity"), capacity, 0.0);
		get( SAR_TEXT("topo_geo"), topo_geo, 0);
		get( SAR_TEXT("hydr_geo"), hydr_geo, 0);
		get( SAR_TEXT("ground_condition"), ground_condition, 0);
		get( SAR_TEXT("q_r"), q_r, 0.0);
		get( SAR_TEXT("stereo_schem_diagram"), stereo_schem_diagram, SAR_TEXT("NULL"));
		get( SAR_TEXT("k_gas"), k_gas, 0.0);
		get( SAR_TEXT("reserve_w1"), reserve_w1, 0.0);
		get( SAR_TEXT("reserve_w2"), reserve_w2, 0.0);
		get( SAR_TEXT("reserve_w3"), reserve_w3, 0.0);
		get( SAR_TEXT("reserve_gas"), reserve_gas, 0.0);
		get( SAR_TEXT("pump_kd"), pump_kd, 0.0);
		get( SAR_TEXT("pump_k1"), pump_k1, 0.0);
		get( SAR_TEXT("pump_k2"), pump_k2, 0.0);
		get( SAR_TEXT("pump_k3"), pump_k3, 0.0);
		get( SAR_TEXT("pump_k4"), pump_k4, 0.0);
		get( SAR_TEXT("pump_wc"), pump_wc, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<Coal>( coals );
		if( mine_region.has_been_saved() ) setOne<MineRegion>( mine_region );
		set( SAR_TEXT("username"), username );
		set( SAR_TEXT("password"), password );
		set( SAR_TEXT("mine_name"), mine_name );
		set( SAR_TEXT("province"), province );
		set( SAR_TEXT("city"), city );
		set( SAR_TEXT("capacity"), capacity );
		set( SAR_TEXT("topo_geo"), topo_geo );
		set( SAR_TEXT("hydr_geo"), hydr_geo );
		set( SAR_TEXT("ground_condition"), ground_condition );
		set( SAR_TEXT("q_r"), q_r );
		set( SAR_TEXT("stereo_schem_diagram"), stereo_schem_diagram );
		set( SAR_TEXT("k_gas"), k_gas );
		set( SAR_TEXT("reserve_w1"), reserve_w1 );
		set( SAR_TEXT("reserve_w2"), reserve_w2 );
		set( SAR_TEXT("reserve_w3"), reserve_w3 );
		set( SAR_TEXT("reserve_gas"), reserve_gas );
		set( SAR_TEXT("pump_kd"), pump_kd );
		set( SAR_TEXT("pump_k1"), pump_k1 );
		set( SAR_TEXT("pump_k2"), pump_k2 );
		set( SAR_TEXT("pump_k3"), pump_k3 );
		set( SAR_TEXT("pump_k4"), pump_k4 );
		set( SAR_TEXT("pump_wc"), pump_wc );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<Coal> coals;
	MineRegion mine_region;
	tstring username;
	tstring password;
	tstring mine_name;
	tstring province;
	tstring city;
	double capacity;
	int topo_geo;
	int hydr_geo;
	int ground_condition;
	double q_r;
	tstring stereo_schem_diagram;
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
	tstring comment;

}; // class Mine

class ARXDAO_DLLIMPEXP MineBase : public BaseRecord<MineBase>
{
public:
	SAR_INIT();
	MineBase() : BaseRecord<MineBase>() {}
	MineBase(int id) : BaseRecord<MineBase>( id ) {}

protected:
	void subUpdate()
	{
		mine_regions = getMany<MineRegion>();
		get( SAR_TEXT("name"), name, SAR_TEXT("NULL"));
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<MineRegion>( mine_regions );
		set( SAR_TEXT("name"), name );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<MineRegion> mine_regions;
	tstring name;
	tstring comment;

}; // class MineBase

class ARXDAO_DLLIMPEXP MineRegion : public BaseRecord<MineRegion>
{
public:
	SAR_INIT();
	MineRegion() : BaseRecord<MineRegion>() {}
	MineRegion(int id) : BaseRecord<MineRegion>( id ) {}

protected:
	void subUpdate()
	{
		mines = getMany<Mine>();
		tech_modes = getMany<TechMode>();
		technologies = getMany<Technology>();
		if( isset<MineBase>() ) getOne<MineBase>( mine_base );
		get( SAR_TEXT("name"), name, SAR_TEXT("NULL"));
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<Mine>( mines );
		setMany<TechMode>( tech_modes );
		setMany<Technology>( technologies );
		if( mine_base.has_been_saved() ) setOne<MineBase>( mine_base );
		set( SAR_TEXT("name"), name );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<Mine> mines;
	ObjGroup<TechMode> tech_modes;
	ObjGroup<Technology> technologies;
	MineBase mine_base;
	tstring name;
	tstring comment;

}; // class MineRegion

class ARXDAO_DLLIMPEXP MiningArea : public BaseRecord<MiningArea>
{
public:
	SAR_INIT();
	MiningArea() : BaseRecord<MiningArea>() {}
	MiningArea(int id) : BaseRecord<MiningArea>( id ) {}

protected:
	void subUpdate()
	{
		ready_tunnels = getMany<ReadyTunnel>();
		if( isset<Coal>() ) getOne<Coal>( coal );
		get( SAR_TEXT("area_mode"), area_mode, 0);
		get( SAR_TEXT("area_k"), area_k, 0.0);
		get( SAR_TEXT("a"), a, 0.0);
		get( SAR_TEXT("q_r"), q_r, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<ReadyTunnel>( ready_tunnels );
		if( coal.has_been_saved() ) setOne<Coal>( coal );
		set( SAR_TEXT("area_mode"), area_mode );
		set( SAR_TEXT("area_k"), area_k );
		set( SAR_TEXT("a"), a );
		set( SAR_TEXT("q_r"), q_r );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<ReadyTunnel> ready_tunnels;
	Coal coal;
	int area_mode;
	double area_k;
	double a;
	double q_r;
	tstring comment;

}; // class MiningArea

class ARXDAO_DLLIMPEXP PoreFlow : public BaseRecord<PoreFlow>
{
public:
	SAR_INIT();
	PoreFlow() : BaseRecord<PoreFlow>() {}
	PoreFlow(int id) : BaseRecord<PoreFlow>( id ) {}

protected:
	void subUpdate()
	{
		get( SAR_TEXT("flow_t"), flow_t, 0.0);
		get( SAR_TEXT("flow_a0"), flow_a0, 0.0);
		get( SAR_TEXT("flow_d"), flow_d, 0.0);
		get( SAR_TEXT("flow_d1"), flow_d1, 0.0);
		get( SAR_TEXT("flow_m"), flow_m, 0.0);
		get( SAR_TEXT("flow_k"), flow_k, 0.0);
		get( SAR_TEXT("flow_delta_t"), flow_delta_t, 0.0);
		get( SAR_TEXT("flow_x"), flow_x, 0.0);
		get( SAR_TEXT("flow_p_test"), flow_p_test, 0.0);
		get( SAR_TEXT("flow_p_cur"), flow_p_cur, 0.0);
		get( SAR_TEXT("flow_b"), flow_b, 0.0);
		get( SAR_TEXT("flow_pt"), flow_pt, 0.0);
		get( SAR_TEXT("flow_delta_p"), flow_delta_p, 0.0);
		get( SAR_TEXT("flow_dh"), flow_dh, 0.0);
		get( SAR_TEXT("flow_q_hun"), flow_q_hun, 0.0);
		get( SAR_TEXT("flow_q_chun"), flow_q_chun, 0.0);
	}
	void subSave()
	{
		set( SAR_TEXT("flow_t"), flow_t );
		set( SAR_TEXT("flow_a0"), flow_a0 );
		set( SAR_TEXT("flow_d"), flow_d );
		set( SAR_TEXT("flow_d1"), flow_d1 );
		set( SAR_TEXT("flow_m"), flow_m );
		set( SAR_TEXT("flow_k"), flow_k );
		set( SAR_TEXT("flow_delta_t"), flow_delta_t );
		set( SAR_TEXT("flow_x"), flow_x );
		set( SAR_TEXT("flow_p_test"), flow_p_test );
		set( SAR_TEXT("flow_p_cur"), flow_p_cur );
		set( SAR_TEXT("flow_b"), flow_b );
		set( SAR_TEXT("flow_pt"), flow_pt );
		set( SAR_TEXT("flow_delta_p"), flow_delta_p );
		set( SAR_TEXT("flow_dh"), flow_dh );
		set( SAR_TEXT("flow_q_hun"), flow_q_hun );
		set( SAR_TEXT("flow_q_chun"), flow_q_chun );
	}

public:
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

class ARXDAO_DLLIMPEXP PoreSize : public BaseRecord<PoreSize>
{
public:
	SAR_INIT();
	PoreSize() : BaseRecord<PoreSize>() {}
	PoreSize(int id) : BaseRecord<PoreSize>( id ) {}

protected:
	void subUpdate()
	{
		get( SAR_TEXT("size_q"), size_q, 0.0);
		get( SAR_TEXT("size_v"), size_v, 0.0);
		get( SAR_TEXT("size_d"), size_d, 0.0);
		get( SAR_TEXT("size_p"), size_p, 0.0);
		get( SAR_TEXT("size_sigma"), size_sigma, 0.0);
		get( SAR_TEXT("size_delta"), size_delta, 0.0);
	}
	void subSave()
	{
		set( SAR_TEXT("size_q"), size_q );
		set( SAR_TEXT("size_v"), size_v );
		set( SAR_TEXT("size_d"), size_d );
		set( SAR_TEXT("size_p"), size_p );
		set( SAR_TEXT("size_sigma"), size_sigma );
		set( SAR_TEXT("size_delta"), size_delta );
	}

public:
	double size_q;
	double size_v;
	double size_d;
	double size_p;
	double size_sigma;
	double size_delta;

}; // class PoreSize

class ARXDAO_DLLIMPEXP ReadyTunnel : public BaseRecord<ReadyTunnel>
{
public:
	SAR_INIT();
	ReadyTunnel() : BaseRecord<ReadyTunnel>() {}
	ReadyTunnel(int id) : BaseRecord<ReadyTunnel>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<MiningArea>() ) getOne<MiningArea>( mining_area );
		if( isset<Tunnel>() ) getOne<Tunnel>( tunnel );
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( mining_area.has_been_saved() ) setOne<MiningArea>( mining_area );
		if( tunnel.has_been_saved() ) setOne<Tunnel>( tunnel );
		set( SAR_TEXT("comment"), comment );
	}

public:
	MiningArea mining_area;
	Tunnel tunnel;
	tstring comment;

}; // class ReadyTunnel

class ARXDAO_DLLIMPEXP ResAbundance : public BaseRecord<ResAbundance>
{
public:
	SAR_INIT();
	ResAbundance() : BaseRecord<ResAbundance>() {}
	ResAbundance(int id) : BaseRecord<ResAbundance>( id ) {}

protected:
	void subUpdate()
	{
		get( SAR_TEXT("type"), type, SAR_TEXT("NULL"));
		get( SAR_TEXT("min_abundance"), min_abundance, 0.0);
		get( SAR_TEXT("max_abundance"), max_abundance, 0.0);
	}
	void subSave()
	{
		set( SAR_TEXT("type"), type );
		set( SAR_TEXT("min_abundance"), min_abundance );
		set( SAR_TEXT("max_abundance"), max_abundance );
	}

public:
	tstring type;
	double min_abundance;
	double max_abundance;

}; // class ResAbundance

class ARXDAO_DLLIMPEXP TechMode : public BaseRecord<TechMode>
{
public:
	SAR_INIT();
	TechMode() : BaseRecord<TechMode>() {}
	TechMode(int id) : BaseRecord<TechMode>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<MineRegion>() ) getOne<MineRegion>( mine_region );
		get( SAR_TEXT("name"), name, SAR_TEXT("NULL"));
		get( SAR_TEXT("type"), type, 0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( mine_region.has_been_saved() ) setOne<MineRegion>( mine_region );
		set( SAR_TEXT("name"), name );
		set( SAR_TEXT("type"), type );
		set( SAR_TEXT("comment"), comment );
	}

public:
	MineRegion mine_region;
	tstring name;
	int type;
	tstring comment;

}; // class TechMode

class ARXDAO_DLLIMPEXP Technology : public BaseRecord<Technology>
{
public:
	SAR_INIT();
	Technology() : BaseRecord<Technology>() {}
	Technology(int id) : BaseRecord<Technology>( id ) {}

protected:
	void subUpdate()
	{
		if( isset<MineRegion>() ) getOne<MineRegion>( mine_region );
		get( SAR_TEXT("name"), name, SAR_TEXT("NULL"));
		get( SAR_TEXT("iskey"), iskey, 0);
		get( SAR_TEXT("doc"), doc, SAR_TEXT("NULL"));
		get( SAR_TEXT("video"), video, SAR_TEXT("NULL"));
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		if( mine_region.has_been_saved() ) setOne<MineRegion>( mine_region );
		set( SAR_TEXT("name"), name );
		set( SAR_TEXT("iskey"), iskey );
		set( SAR_TEXT("doc"), doc );
		set( SAR_TEXT("video"), video );
		set( SAR_TEXT("comment"), comment );
	}

public:
	MineRegion mine_region;
	tstring name;
	int iskey;
	tstring doc;
	tstring video;
	tstring comment;

}; // class Technology

class ARXDAO_DLLIMPEXP TopoGeo : public BaseRecord<TopoGeo>
{
public:
	SAR_INIT();
	TopoGeo() : BaseRecord<TopoGeo>() {}
	TopoGeo(int id) : BaseRecord<TopoGeo>( id ) {}

protected:
	void subUpdate()
	{
		get( SAR_TEXT("type"), type, SAR_TEXT("NULL"));
		get( SAR_TEXT("feature"), feature, SAR_TEXT("NULL"));
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		set( SAR_TEXT("type"), type );
		set( SAR_TEXT("feature"), feature );
		set( SAR_TEXT("comment"), comment );
	}

public:
	tstring type;
	tstring feature;
	tstring comment;

}; // class TopoGeo

class ARXDAO_DLLIMPEXP Tunnel : public BaseRecord<Tunnel>
{
public:
	SAR_INIT();
	Tunnel() : BaseRecord<Tunnel>() {}
	Tunnel(int id) : BaseRecord<Tunnel>( id ) {}

protected:
	void subUpdate()
	{
		drilling_surves = getMany<DrillingSurf>();
		ready_tunnels = getMany<ReadyTunnel>();
		work_surves = getMany<WorkSurf>();
		get( SAR_TEXT("b"), b, 0.0);
		get( SAR_TEXT("l"), l, 0.0);
		get( SAR_TEXT("s"), s, 0.0);
		get( SAR_TEXT("d"), d, 0.0);
		get( SAR_TEXT("wh"), wh, 0.0);
		get( SAR_TEXT("v"), v, 0.0);
		get( SAR_TEXT("qa"), qa, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<DrillingSurf>( drilling_surves );
		setMany<ReadyTunnel>( ready_tunnels );
		setMany<WorkSurf>( work_surves );
		set( SAR_TEXT("b"), b );
		set( SAR_TEXT("l"), l );
		set( SAR_TEXT("s"), s );
		set( SAR_TEXT("d"), d );
		set( SAR_TEXT("wh"), wh );
		set( SAR_TEXT("v"), v );
		set( SAR_TEXT("qa"), qa );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<DrillingSurf> drilling_surves;
	ObjGroup<ReadyTunnel> ready_tunnels;
	ObjGroup<WorkSurf> work_surves;
	double b;
	double l;
	double s;
	double d;
	double wh;
	double v;
	double qa;
	tstring comment;

}; // class Tunnel

class ARXDAO_DLLIMPEXP WorkSurf : public BaseRecord<WorkSurf>
{
public:
	SAR_INIT();
	WorkSurf() : BaseRecord<WorkSurf>() {}
	WorkSurf(int id) : BaseRecord<WorkSurf>( id ) {}

protected:
	void subUpdate()
	{
		adj_layers = getMany<AdjLayer>();
		eval_units = getMany<EvalUnit>();
		high_drilling_pores = getMany<HighDrillingPore>();
		high_drilling_tunnels = getMany<HighDrillingTunnel>();
		if( isset<Tunnel>() ) getOne<Tunnel>( tunnel );
		if( isset<Coal>() ) getOne<Coal>( coal );
		get( SAR_TEXT("a"), a, 0.0);
		get( SAR_TEXT("q_r"), q_r, 0.0);
		get( SAR_TEXT("q_a"), q_a, 0.0);
		get( SAR_TEXT("ws_l"), ws_l, 0.0);
		get( SAR_TEXT("ws_layerable"), ws_layerable, 0);
		get( SAR_TEXT("ws_k1"), ws_k1, 0.0);
		get( SAR_TEXT("ws_k2"), ws_k2, 0.0);
		get( SAR_TEXT("ws_k3"), ws_k3, 0.0);
		get( SAR_TEXT("ws_kf"), ws_kf, 0.0);
		get( SAR_TEXT("ws_h"), ws_h, 0.0);
		get( SAR_TEXT("ws_method"), ws_method, 0);
		get( SAR_TEXT("last_t"), last_t, 0.0);
		get( SAR_TEXT("comment"), comment, SAR_TEXT("NULL"));
	}
	void subSave()
	{
		setMany<AdjLayer>( adj_layers );
		setMany<EvalUnit>( eval_units );
		setMany<HighDrillingPore>( high_drilling_pores );
		setMany<HighDrillingTunnel>( high_drilling_tunnels );
		if( tunnel.has_been_saved() ) setOne<Tunnel>( tunnel );
		if( coal.has_been_saved() ) setOne<Coal>( coal );
		set( SAR_TEXT("a"), a );
		set( SAR_TEXT("q_r"), q_r );
		set( SAR_TEXT("q_a"), q_a );
		set( SAR_TEXT("ws_l"), ws_l );
		set( SAR_TEXT("ws_layerable"), ws_layerable );
		set( SAR_TEXT("ws_k1"), ws_k1 );
		set( SAR_TEXT("ws_k2"), ws_k2 );
		set( SAR_TEXT("ws_k3"), ws_k3 );
		set( SAR_TEXT("ws_kf"), ws_kf );
		set( SAR_TEXT("ws_h"), ws_h );
		set( SAR_TEXT("ws_method"), ws_method );
		set( SAR_TEXT("last_t"), last_t );
		set( SAR_TEXT("comment"), comment );
	}

public:
	ObjGroup<AdjLayer> adj_layers;
	ObjGroup<EvalUnit> eval_units;
	ObjGroup<HighDrillingPore> high_drilling_pores;
	ObjGroup<HighDrillingTunnel> high_drilling_tunnels;
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
	tstring comment;

}; // class WorkSurf

} // namespace cbm

#endif // CBM_ALL_ENTITIES_H
