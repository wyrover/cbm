#ifndef CBM_ALL_ENTITIES_H
#define CBM_ALL_ENTITIES_H

#include "Record.h"

#include <vector>
#include <boost/shared_ptr.hpp>
using namespace boost;

namespace cbm {

class Account;
class AdjLayer;
class Coal;
class Complexity;
class DesignDrillingSurfTechnology;
class DesignGoafTechnology;
class DesignPore;
class DesignSite;
class DesignTechnology;
class DesignWorkSurfTechnology;
class DrillingRadiusParam;
class DrillingSurf;
class EvalUnit;
class HighDrillingPore;
class HighDrillingPoreParam;
class HighDrillingSiteParam;
class HighDrillingTunnel;
class HydrGeo;
class Mine;
class MineBase;
class MineRegion;
class PoreFlow;
class PoreSize;
class ResAbundance;
class Rock;
class SysInfo;
class TechMode;
class Technology;
class TopoGeo;
class Tunnel;
class WorkArea;
class WorkSurf;

typedef boost::shared_ptr<Account> AccountPtr;
typedef boost::shared_ptr<AdjLayer> AdjLayerPtr;
typedef boost::shared_ptr<Coal> CoalPtr;
typedef boost::shared_ptr<Complexity> ComplexityPtr;
typedef boost::shared_ptr<DesignDrillingSurfTechnology> DesignDrillingSurfTechnologyPtr;
typedef boost::shared_ptr<DesignGoafTechnology> DesignGoafTechnologyPtr;
typedef boost::shared_ptr<DesignPore> DesignPorePtr;
typedef boost::shared_ptr<DesignSite> DesignSitePtr;
typedef boost::shared_ptr<DesignTechnology> DesignTechnologyPtr;
typedef boost::shared_ptr<DesignWorkSurfTechnology> DesignWorkSurfTechnologyPtr;
typedef boost::shared_ptr<DrillingRadiusParam> DrillingRadiusParamPtr;
typedef boost::shared_ptr<DrillingSurf> DrillingSurfPtr;
typedef boost::shared_ptr<EvalUnit> EvalUnitPtr;
typedef boost::shared_ptr<HighDrillingPore> HighDrillingPorePtr;
typedef boost::shared_ptr<HighDrillingPoreParam> HighDrillingPoreParamPtr;
typedef boost::shared_ptr<HighDrillingSiteParam> HighDrillingSiteParamPtr;
typedef boost::shared_ptr<HighDrillingTunnel> HighDrillingTunnelPtr;
typedef boost::shared_ptr<HydrGeo> HydrGeoPtr;
typedef boost::shared_ptr<Mine> MinePtr;
typedef boost::shared_ptr<MineBase> MineBasePtr;
typedef boost::shared_ptr<MineRegion> MineRegionPtr;
typedef boost::shared_ptr<PoreFlow> PoreFlowPtr;
typedef boost::shared_ptr<PoreSize> PoreSizePtr;
typedef boost::shared_ptr<ResAbundance> ResAbundancePtr;
typedef boost::shared_ptr<Rock> RockPtr;
typedef boost::shared_ptr<SysInfo> SysInfoPtr;
typedef boost::shared_ptr<TechMode> TechModePtr;
typedef boost::shared_ptr<Technology> TechnologyPtr;
typedef boost::shared_ptr<TopoGeo> TopoGeoPtr;
typedef boost::shared_ptr<Tunnel> TunnelPtr;
typedef boost::shared_ptr<WorkArea> WorkAreaPtr;
typedef boost::shared_ptr<WorkSurf> WorkSurfPtr;

class DAO_DLLIMPEXP Account : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Account();
	CString username;
	CString password;
	CString comment;

}; // class Account

class DAO_DLLIMPEXP AdjLayer : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	AdjLayer();
	orm::RecordPtr work_surf;
	orm::RecordPtr coal;
	CString name;
	int num;
	double h;
	double hp;
	int in_cz;
	CString comment;

}; // class AdjLayer

class DAO_DLLIMPEXP Coal : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Coal();
	orm::RecordPtr mine;
	CString name;
	int minable;
	double thick;
	double hw;
	double qa;
	double qr;
	double fore_qr;
	double fore_qa;
	int rank;
	int quality;
	double pressure;
	double gas_content;
	double gas_penetration;
	double f_value;
	int res_abundance;
	int complexity;
	double mine_index;
	double var_coeff;
	int stability;
	double dip_angle;
	double czh;
	double czk;
	double czw;
	double hw_sum;
	int rock;
	double hhh;
	double layer_gap;
	double influence_factor;
	double res_a1;
	double gas_x1;
	double res_a2;
	double gas_x2;
	double pump_wc;
	double pump_k;
	double pump_k2;
	double pump_k3;
	double pump_k4;
	double pump_k1;
	CString pore_datas;
	double rho;
	double vr;
	double gas_w0;
	double gas_wc2;
	double gas_wc3;
	double gas_eta;
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

class DAO_DLLIMPEXP Complexity : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Complexity();
	CString name;
	CString details;
	CString comment;

}; // class Complexity

class DAO_DLLIMPEXP DesignDrillingSurfTechnology : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DesignDrillingSurfTechnology();
	orm::RecordPtr design_technology;
	CString name;
	CString comment;
	double v_offset;
	double h_offset;
	double dp;
	double gp;
	double leading_dist;
	double gbp;
	double l_stripe;
	double ls;
	double ws;
	double hs;
	double gs;
	double wd;
	double hd;
	double l1;
	double l2;
	double w;
	double h;
	double top_side;
	double bottom_side;
	double left_side;
	double right_side;
	double lm;

}; // class DesignDrillingSurfTechnology

class DAO_DLLIMPEXP DesignGoafTechnology : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DesignGoafTechnology();
	orm::RecordPtr design_technology;
	CString name;
	CString comment;

}; // class DesignGoafTechnology

class DAO_DLLIMPEXP DesignPore : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DesignPore();
	orm::RecordPtr design_site;
	CString name;
	double d;
	double x1;
	double y1;
	double z1;
	double x2;
	double y2;
	double z2;
	double length;
	double angle1;
	double angle2;
	CString comment;

}; // class DesignPore

class DAO_DLLIMPEXP DesignSite : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DesignSite();
	orm::RecordPtr design_technology;
	CString name;
	double w;
	double h;
	double x;
	double y;
	double z;
	CString comment;

}; // class DesignSite

class DAO_DLLIMPEXP DesignTechnology : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DesignTechnology();
	orm::RecordPtr coal;
	CString name;
	int mine_region;
	CString comment;

}; // class DesignTechnology

class DAO_DLLIMPEXP DesignWorkSurfTechnology : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DesignWorkSurfTechnology();
	orm::RecordPtr design_technology;
	CString name;
	CString comment;
	double top_side;
	double bottom_side;
	double right_side;
	double l1;
	double w;
	double h;
	double l2;
	double left_side;
	double v_offset;
	double h_offset;
	double p_offset;
	double wd;
	double hd;
	double lm;
	double ws;
	double ls;
	double gs;
	double hs;
	double dp;
	double gp;
	int single_rock_tunnel;
	double d_offset;
	double pore_stubble;
	double pore_angle;
	int pore_type;

}; // class DesignWorkSurfTechnology

class DAO_DLLIMPEXP DrillingRadiusParam : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DrillingRadiusParam();
	orm::RecordPtr coal;
	CString name;
	double r;
	double l;
	double k1;
	double rho;
	double q0;
	double a;
	double t;
	double qm;
	double qsum;
	double eta;

}; // class DrillingRadiusParam

class DAO_DLLIMPEXP DrillingSurf : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DrillingSurf();
	orm::RecordPtr work_area;
	orm::RecordPtr tunnel;
	CString name;
	double qr;
	double qa;
	double fore_qr;
	double fore_qa;
	double q4;
	CString comment;

}; // class DrillingSurf

class DAO_DLLIMPEXP EvalUnit : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	EvalUnit();
	orm::RecordPtr work_surf;
	CString name;
	double l;
	double t;
	CString comment;

}; // class EvalUnit

class DAO_DLLIMPEXP HighDrillingPore : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HighDrillingPore();
	orm::RecordPtr high_drilling_pore_param;
	int num;
	double length;
	double angle;
	int pore_type;
	CString comment;

}; // class HighDrillingPore

class DAO_DLLIMPEXP HighDrillingPoreParam : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HighDrillingPoreParam();
	orm::RecordPtr work_surf;
	CString name;
	double lk;
	double lc;
	double lw;
	int n1;
	int n2;
	double beta;
	double ld;
	CString comment;

}; // class HighDrillingPoreParam

class DAO_DLLIMPEXP HighDrillingSiteParam : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HighDrillingSiteParam();
	orm::RecordPtr work_surf;
	CString name;
	double l1;
	double l2;
	double lg;
	double hn;
	double theta;
	double q;
	double rtn;
	double hs;
	CString comment;

}; // class HighDrillingSiteParam

class DAO_DLLIMPEXP HighDrillingTunnel : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HighDrillingTunnel();
	orm::RecordPtr work_surf;
	CString name;
	double k;
	int rock;
	double hz_min;
	double hz_max;
	CString comment;

}; // class HighDrillingTunnel

class DAO_DLLIMPEXP HydrGeo : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HydrGeo();
	CString name;
	int x1;
	int x2;
	int x3;
	double x4;
	double x5;
	double x6;
	double x7;
	CString x8;

}; // class HydrGeo

class DAO_DLLIMPEXP Mine : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Mine();
	orm::RecordPtr tech_mode;
	orm::RecordPtr mine_region;
	orm::RecordPtr account;
	CString name;
	CString province;
	CString city;
	double capacity;
	int topo_geo;
	int hydr_geo;
	int ground_condition;
	double qr;
	double qa;
	double fore_qr;
	double fore_qa;
	double gas_k1;
	double gas_k2;
	CString stereo_schem_diagram;
	double rock_gas_k2;
	double reserve_w1;
	double reserve_w2;
	double reserve_w3;
	double gas_w0;
	double gas_wc2;
	double pump_k2;
	double pump_k3;
	double pump_k4;
	double pump_k1;
	double pump_k;
	double pump_wc;
	double reserve_gas;
	CString comment;

}; // class Mine

class DAO_DLLIMPEXP MineBase : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	MineBase();
	CString name;
	CString comment;

}; // class MineBase

class DAO_DLLIMPEXP MineRegion : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	MineRegion();
	orm::RecordPtr mine_base;
	CString name;
	CString comment;

}; // class MineRegion

class DAO_DLLIMPEXP PoreFlow : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	PoreFlow();
	CString name;
	double t;
	double a0;
	double d;
	double d1;
	double m;
	double k;
	double delta_t;
	double x;
	double p_test;
	double p_cur;
	double b;
	double pt;
	double delta_p;
	double dh;
	double q_hun;
	double q_chun;

}; // class PoreFlow

class DAO_DLLIMPEXP PoreSize : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	PoreSize();
	CString name;
	double q;
	double v;
	double d;
	double p;
	double sigma;
	double delta;
	CString comment;

}; // class PoreSize

class DAO_DLLIMPEXP ResAbundance : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	ResAbundance();
	CString name;
	double min_abundance;
	double max_abundance;

}; // class ResAbundance

class DAO_DLLIMPEXP Rock : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Rock();
	CString name;
	double a;
	double b;
	double c;
	CString comment;

}; // class Rock

class DAO_DLLIMPEXP SysInfo : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	SysInfo();
	orm::RecordPtr account;
	CString last_login_time;
	CString comment;

}; // class SysInfo

class DAO_DLLIMPEXP TechMode : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	TechMode();
	orm::RecordPtr mine_region;
	CString name;
	int mode_type;
	int c1;
	int c2;
	int c3;
	CString comment;

}; // class TechMode

class DAO_DLLIMPEXP Technology : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Technology();
	orm::RecordPtr mine_region;
	CString name;
	int iskey;
	CString doc;
	CString video;
	CString comment;

}; // class Technology

class DAO_DLLIMPEXP TopoGeo : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	TopoGeo();
	CString name;
	CString feature;
	CString comment;

}; // class TopoGeo

class DAO_DLLIMPEXP Tunnel : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Tunnel();
	CString name;
	double b;
	double h;
	double l;
	double s;
	double d;
	double wh;
	double v;
	double q3;
	double q0;
	CString comment;
	int tunnel_type;
	double top_side;
	double bottom_side;
	double left_side;
	double right_side;
	double x1;
	double y1;
	double z1;
	double x2;
	double y2;
	double z2;

}; // class Tunnel

class DAO_DLLIMPEXP WorkArea : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	WorkArea();
	orm::RecordPtr coal;
	CString name;
	int mode;
	double a;
	double qr;
	double qa;
	double fore_qr;
	double fore_qa;
	CString comment;

}; // class WorkArea

class DAO_DLLIMPEXP WorkSurf : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	WorkSurf();
	orm::RecordPtr work_area;
	orm::RecordPtr tunnel;
	CString name;
	double a;
	double qr;
	double qa;
	double fore_qr;
	double fore_qa;
	double l1;
	double l2;
	int layerable;
	double k1;
	double k2;
	double k3;
	double kf;
	int method;
	double last_t;
	double qr1;
	double qr2;
	CString comment;

}; // class WorkSurf

} // namespace cbm

#endif // CBM_ALL_ENTITIES_H
