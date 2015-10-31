
namespace cpp cbm
namespace php cbm
namespace py cbm

struct Account {
	1: i32 id
	2: string username
	3: string password
	4: string comment
}

struct AdjLayer {
	1: i32 id
	2: i32 work_surf_id
	3: i32 coal_id
	4: string name
	5: i32 num
	6: double h
	7: double hp
	8: i32 in_cz
	9: string comment
}

struct Coal {
	1: i32 id
	2: i32 mine_id
	3: string name
	4: i32 minable
	5: double thick
	6: double hw
	7: double qa
	8: double qr
	9: double fore_qr
	10: double fore_qa
	11: i32 rank
	12: i32 quality
	13: double pressure
	14: double gas_content
	15: double gas_penetration
	16: double f_value
	17: i32 res_abundance
	18: i32 complexity
	19: double mine_index
	20: double var_coeff
	21: i32 stability
	22: double dip_angle
	23: double czh
	24: double czk
	25: double czw
	26: double hw_sum
	27: i32 rock
	28: double hhh
	29: double layer_gap
	30: double influence_factor
	31: double res_a1
	32: double gas_x1
	33: double res_a2
	34: double gas_x2
	35: double pump_wc
	36: double pump_k
	37: double pump_k2
	38: double pump_k3
	39: double pump_k4
	40: double pump_k1
	41: string pore_datas
	42: double rho
	43: double vr
	44: double gas_w0
	45: double gas_wc2
	46: double gas_wc3
	47: double gas_eta
	48: double q0
	49: i32 eval_method
	50: double q0_alpha
	51: double qt_alpha
	52: double t_alpha
	53: double q_lambda
	54: double r_lambda
	55: double p0_lambda
	56: double p1_lambda
	57: double t_lambda
	58: double a_lambda
	59: double p1_k
	60: double p2_k
	61: double gas_q
	62: double core_height
	63: double core_area
	64: double gas_viscosity
	65: double decay_alpha
	66: double permeability_lambda
	67: double permeability_k
	68: i32 eval_difficult
	69: string comment
}

struct Complexity {
	1: i32 id
	2: string name
	3: string details
	4: string comment
}

struct DesignDrillingSurfTechnology {
	1: i32 id
	2: i32 design_technology_id
	3: string name
	4: string comment
	5: double v_offset
	6: double h_offset
	7: double dp
	8: double gp
	9: double leading_dist
	10: double gbp
	11: double l_stripe
	12: double ls
	13: double ws
	14: double hs
	15: double gs
	16: double wd
	17: double hd
	18: double l1
	19: double l2
	20: double w
	21: double h
	22: double top_side
	23: double bottom_side
	24: double left_side
	25: double right_side
	26: double lm
}

struct DesignGoafTechnology {
	1: i32 id
	2: i32 design_technology_id
	3: string name
	4: string comment
}

struct DesignPore {
	1: i32 id
	2: i32 design_site_id
	3: string name
	4: double d
	5: double x1
	6: double y1
	7: double z1
	8: double x2
	9: double y2
	10: double z2
	11: double length
	12: double angle1
	13: double angle2
	14: string comment
}

struct DesignSite {
	1: i32 id
	2: i32 design_technology_id
	3: string name
	4: double w
	5: double h
	6: double x
	7: double y
	8: double z
	9: string comment
}

struct DesignTechnology {
	1: i32 id
	2: i32 coal_id
	3: string name
	4: i32 mine_region
	5: string comment
}

struct DesignWorkSurfTechnology {
	1: i32 id
	2: i32 design_technology_id
	3: string name
	4: string comment
	5: double top_side
	6: double bottom_side
	7: double right_side
	8: double l1
	9: double w
	10: double h
	11: double l2
	12: double left_side
	13: double v_offset
	14: double h_offset
	15: double p_offset
	16: double wd
	17: double hd
	18: double lm
	19: double ws
	20: double ls
	21: double gs
	22: double hs
	23: double dp
	24: double gp
	25: i32 single_rock_tunnel
	26: double d_offset
	27: double pore_stubble
	28: double pore_angle
	29: i32 pore_type
}

struct DrillingRadiusParam {
	1: i32 id
	2: i32 coal_id
	3: string name
	4: double r
	5: double l
	6: double k1
	7: double rho
	8: double q0
	9: double a
	10: double t
	11: double qm
	12: double qsum
	13: double eta
}

struct DrillingSurf {
	1: i32 id
	2: i32 work_area_id
	3: i32 tunnel_id
	4: string name
	5: double qr
	6: double qa
	7: double fore_qr
	8: double fore_qa
	9: double q4
	10: string comment
}

struct EvalUnit {
	1: i32 id
	2: i32 work_surf_id
	3: string name
	4: double l
	5: double t
	6: string comment
}

struct HighDrillingPore {
	1: i32 id
	2: i32 high_drilling_pore_param_id
	3: i32 num
	4: double length
	5: double angle
	6: i32 pore_type
	7: string comment
}

struct HighDrillingPoreParam {
	1: i32 id
	2: i32 work_surf_id
	3: string name
	4: double lk
	5: double lc
	6: double lw
	7: i32 n1
	8: i32 n2
	9: double beta
	10: double ld
	11: string comment
}

struct HighDrillingSiteParam {
	1: i32 id
	2: i32 work_surf_id
	3: string name
	4: double l1
	5: double l2
	6: double lg
	7: double hn
	8: double theta
	9: double q
	10: double rtn
	11: double hs
	12: string comment
}

struct HighDrillingTunnel {
	1: i32 id
	2: i32 work_surf_id
	3: string name
	4: double k
	5: i32 rock
	6: double hz_min
	7: double hz_max
	8: string comment
}

struct HydrGeo {
	1: i32 id
	2: string name
	3: i32 x1
	4: i32 x2
	5: i32 x3
	6: double x4
	7: double x5
	8: double x6
	9: double x7
	10: string x8
}

struct Mine {
	1: i32 id
	2: i32 tech_mode_id
	3: i32 mine_region_id
	4: i32 account_id
	5: string name
	6: string province
	7: string city
	8: double capacity
	9: i32 topo_geo
	10: i32 hydr_geo
	11: i32 ground_condition
	12: double qr
	13: double qa
	14: double fore_qr
	15: double fore_qa
	16: double gas_k1
	17: double gas_k2
	18: string stereo_schem_diagram
	19: double rock_gas_k2
	20: double reserve_w1
	21: double reserve_w2
	22: double reserve_w3
	23: double gas_w0
	24: double gas_wc2
	25: double pump_k2
	26: double pump_k3
	27: double pump_k4
	28: double pump_k1
	29: double pump_k
	30: double pump_wc
	31: double reserve_gas
	32: string comment
}

struct MineBase {
	1: i32 id
	2: string name
	3: string comment
}

struct MineRegion {
	1: i32 id
	2: i32 mine_base_id
	3: string name
	4: string comment
}

struct PoreFlow {
	1: i32 id
	2: string name
	3: double t
	4: double a0
	5: double d
	6: double d1
	7: double m
	8: double k
	9: double delta_t
	10: double x
	11: double p_test
	12: double p_cur
	13: double b
	14: double pt
	15: double delta_p
	16: double dh
	17: double q_hun
	18: double q_chun
}

struct PoreSize {
	1: i32 id
	2: string name
	3: double q
	4: double v
	5: double d
	6: double p
	7: double sigma
	8: double delta
	9: string comment
}

struct ResAbundance {
	1: i32 id
	2: string name
	3: double min_abundance
	4: double max_abundance
}

struct Rock {
	1: i32 id
	2: string name
	3: double a
	4: double b
	5: double c
	6: string comment
}

struct SysInfo {
	1: i32 id
	2: i32 account_id
	3: string last_login_time
	4: string comment
}

struct TechMode {
	1: i32 id
	2: i32 mine_region_id
	3: string name
	4: i32 mode_type
	5: i32 c1
	6: i32 c2
	7: i32 c3
	8: string comment
}

struct Technology {
	1: i32 id
	2: i32 mine_region_id
	3: string name
	4: i32 iskey
	5: string doc
	6: string video
	7: string comment
}

struct TopoGeo {
	1: i32 id
	2: string name
	3: string feature
	4: string comment
}

struct Tunnel {
	1: i32 id
	2: string name
	3: double b
	4: double h
	5: double l
	6: double s
	7: double d
	8: double wh
	9: double v
	10: double q3
	11: double q0
	12: string comment
	13: i32 tunnel_type
	14: double top_side
	15: double bottom_side
	16: double left_side
	17: double right_side
	18: double x1
	19: double y1
	20: double z1
	21: double x2
	22: double y2
	23: double z2
}

struct WorkArea {
	1: i32 id
	2: i32 coal_id
	3: string name
	4: i32 mode
	5: double a
	6: double qr
	7: double qa
	8: double fore_qr
	9: double fore_qa
	10: string comment
}

struct WorkSurf {
	1: i32 id
	2: i32 work_area_id
	3: i32 tunnel_id
	4: string name
	5: double a
	6: double qr
	7: double qa
	8: double fore_qr
	9: double fore_qa
	10: double l1
	11: double l2
	12: i32 layerable
	13: double k1
	14: double k2
	15: double k3
	16: double kf
	17: i32 method
	18: double last_t
	19: double qr1
	20: double qr2
	21: string comment
}
