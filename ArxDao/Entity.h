#ifndef CBM_ALL_ENTITIES_H
#define CBM_ALL_ENTITIES_H

#include "Record.h"

#include <vector>
#include <boost/shared_ptr.hpp>
using namespace boost;

namespace cbm {

class AdjLayer;
class Base;
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
class MiningArea;
class PoreFlow;
class PoreSize;
class ReadyTunnel;
class Region;
class ResAbundance;
class TechMode;
class Technology;
class TopoGeo;
class Tunnel;
class WorkSurf;

typedef boost::shared_ptr<AdjLayer> AdjLayerPtr;
typedef boost::shared_ptr<Base> BasePtr;
typedef boost::shared_ptr<Coal> CoalPtr;
typedef boost::shared_ptr<DrillingRadius> DrillingRadiusPtr;
typedef boost::shared_ptr<DrillingSurf> DrillingSurfPtr;
typedef boost::shared_ptr<EvalUnit> EvalUnitPtr;
typedef boost::shared_ptr<Help> HelpPtr;
typedef boost::shared_ptr<HighDrillingPore> HighDrillingPorePtr;
typedef boost::shared_ptr<HighDrillingTunnel> HighDrillingTunnelPtr;
typedef boost::shared_ptr<HydrGeo> HydrGeoPtr;
typedef boost::shared_ptr<KeyLayer> KeyLayerPtr;
typedef boost::shared_ptr<Mine> MinePtr;
typedef boost::shared_ptr<MiningArea> MiningAreaPtr;
typedef boost::shared_ptr<PoreFlow> PoreFlowPtr;
typedef boost::shared_ptr<PoreSize> PoreSizePtr;
typedef boost::shared_ptr<ReadyTunnel> ReadyTunnelPtr;
typedef boost::shared_ptr<Region> RegionPtr;
typedef boost::shared_ptr<ResAbundance> ResAbundancePtr;
typedef boost::shared_ptr<TechMode> TechModePtr;
typedef boost::shared_ptr<Technology> TechnologyPtr;
typedef boost::shared_ptr<TopoGeo> TopoGeoPtr;
typedef boost::shared_ptr<Tunnel> TunnelPtr;
typedef boost::shared_ptr<WorkSurf> WorkSurfPtr;

class ARXDAO_DLLIMPEXP AdjLayer : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	AdjLayer();
	orm::RecordPtr work_surf;
	orm::RecordPtr coal;
	int num;
	double h;
	double hp;
	int cave_zone;
	CString comment;

}; // class AdjLayer

class ARXDAO_DLLIMPEXP Base : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Base();
	CString name;
	CString comment;

}; // class Base

class ARXDAO_DLLIMPEXP Coal : public orm::Record
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
	int rank;
	int quality;
	double pressure;
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
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DrillingRadius();
	orm::RecordPtr coal;
	double r;
	double l;
	double k1;
	double rho;
	double q0;
	double a;
	double t;
	double qm1;
	double qm2;
	double qsum;
	double eta;

}; // class DrillingRadius

class ARXDAO_DLLIMPEXP DrillingSurf : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	DrillingSurf();
	orm::RecordPtr coal;
	orm::RecordPtr tunnel;
	double q_r;
	double q_a;
	double q4;
	CString comment;

}; // class DrillingSurf

class ARXDAO_DLLIMPEXP EvalUnit : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	EvalUnit();
	orm::RecordPtr work_surf;
	double l;
	double t;
	CString comment;

}; // class EvalUnit

class ARXDAO_DLLIMPEXP Help : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Help();
	CString field;
	int type;
	CString value;
	CString comment;

}; // class Help

class ARXDAO_DLLIMPEXP HighDrillingPore : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HighDrillingPore();
	orm::RecordPtr work_surf;
	double l1;
	double l2;
	double lg;
	double hz;
	double lk;
	double lc;
	double lw;
	double n;
	double beta;
	double ld;
	double lzi;
	double lzj;
	CString comment;

}; // class HighDrillingPore

class ARXDAO_DLLIMPEXP HighDrillingTunnel : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HighDrillingTunnel();
	orm::RecordPtr work_surf;
	double k;
	int rock;
	double hz_min;
	double hz_max;
	CString comment;

}; // class HighDrillingTunnel

class ARXDAO_DLLIMPEXP HydrGeo : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	HydrGeo();
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
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	KeyLayer();
	orm::RecordPtr high_drilling_pore;
	double hn;
	double thetan;
	double qn;
	double rtn;
	double sum_hn;
	CString comment;

}; // class KeyLayer

class ARXDAO_DLLIMPEXP Mine : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Mine();
	orm::RecordPtr region;
	CString username;
	CString password;
	CString name;
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

class ARXDAO_DLLIMPEXP MiningArea : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	MiningArea();
	orm::RecordPtr coal;
	int mode;
	double k_gas;
	double a;
	double q_r;
	CString comment;

}; // class MiningArea

class ARXDAO_DLLIMPEXP PoreFlow : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	PoreFlow();
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

class ARXDAO_DLLIMPEXP PoreSize : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	PoreSize();
	double q;
	double v;
	double d;
	double p;
	double sigma;
	double delta;

}; // class PoreSize

class ARXDAO_DLLIMPEXP ReadyTunnel : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	ReadyTunnel();
	orm::RecordPtr mining_area;
	orm::RecordPtr tunnel;
	CString comment;

}; // class ReadyTunnel

class ARXDAO_DLLIMPEXP Region : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Region();
	orm::RecordPtr base;
	CString name;
	CString comment;

}; // class Region

class ARXDAO_DLLIMPEXP ResAbundance : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	ResAbundance();
	CString type;
	double min_abundance;
	double max_abundance;

}; // class ResAbundance

class ARXDAO_DLLIMPEXP TechMode : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	TechMode();
	orm::RecordPtr region;
	CString name;
	int type;
	CString comment;

}; // class TechMode

class ARXDAO_DLLIMPEXP Technology : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Technology();
	orm::RecordPtr region;
	CString name;
	int iskey;
	CString doc;
	CString video;
	CString comment;

}; // class Technology

class ARXDAO_DLLIMPEXP TopoGeo : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	TopoGeo();
	CString type;
	CString feature;
	CString comment;

}; // class TopoGeo

class ARXDAO_DLLIMPEXP Tunnel : public orm::Record
{
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	Tunnel();
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
public:
	static CString Table();
	static orm::RecordPtr Create();

public:
	WorkSurf();
	orm::RecordPtr tunnel;
	orm::RecordPtr coal;
	double a;
	double q_r;
	double q_a;
	double l;
	int layerable;
	double k1;
	double k2;
	double k3;
	double kf;
	double h;
	int method;
	double last_t;
	CString comment;

}; // class WorkSurf

} // namespace cbm

#endif // CBM_ALL_ENTITIES_H
