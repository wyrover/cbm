#ifndef CBM_ALL_ENTITIES_H
#define CBM_ALL_ENTITIES_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include <row.h>

#include "BaseDao.h"

namespace cbm {

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
typedef boost::shared_ptr<MineBase> MineBasePtr;
typedef boost::shared_ptr<MineRegion> MineRegionPtr;
typedef boost::shared_ptr<MiningArea> MiningAreaPtr;
typedef boost::shared_ptr<PoreFlow> PoreFlowPtr;
typedef boost::shared_ptr<PoreSize> PoreSizePtr;
typedef boost::shared_ptr<ReadyTunnel> ReadyTunnelPtr;
typedef boost::shared_ptr<ResAbundance> ResAbundancePtr;
typedef boost::shared_ptr<TechMode> TechModePtr;
typedef boost::shared_ptr<Technology> TechnologyPtr;
typedef boost::shared_ptr<TopoGeo> TopoGeoPtr;
typedef boost::shared_ptr<Tunnel> TunnelPtr;
typedef boost::shared_ptr<WorkSurf> WorkSurfPtr;

typedef boost::shared_ptr< std::vector<CoalPtr> > CoalList;
typedef boost::shared_ptr< std::vector<DrillingRadiusPtr> > DrillingRadiusList;
typedef boost::shared_ptr< std::vector<DrillingSurfPtr> > DrillingSurfList;
typedef boost::shared_ptr< std::vector<EvalUnitPtr> > EvalUnitList;
typedef boost::shared_ptr< std::vector<HelpPtr> > HelpList;
typedef boost::shared_ptr< std::vector<HighDrillingPorePtr> > HighDrillingPoreList;
typedef boost::shared_ptr< std::vector<HighDrillingTunnelPtr> > HighDrillingTunnelList;
typedef boost::shared_ptr< std::vector<HydrGeoPtr> > HydrGeoList;
typedef boost::shared_ptr< std::vector<KeyLayerPtr> > KeyLayerList;
typedef boost::shared_ptr< std::vector<MinePtr> > MineList;
typedef boost::shared_ptr< std::vector<MineBasePtr> > MineBaseList;
typedef boost::shared_ptr< std::vector<MineRegionPtr> > MineRegionList;
typedef boost::shared_ptr< std::vector<MiningAreaPtr> > MiningAreaList;
typedef boost::shared_ptr< std::vector<PoreFlowPtr> > PoreFlowList;
typedef boost::shared_ptr< std::vector<PoreSizePtr> > PoreSizeList;
typedef boost::shared_ptr< std::vector<ReadyTunnelPtr> > ReadyTunnelList;
typedef boost::shared_ptr< std::vector<ResAbundancePtr> > ResAbundanceList;
typedef boost::shared_ptr< std::vector<TechModePtr> > TechModeList;
typedef boost::shared_ptr< std::vector<TechnologyPtr> > TechnologyList;
typedef boost::shared_ptr< std::vector<TopoGeoPtr> > TopoGeoList;
typedef boost::shared_ptr< std::vector<TunnelPtr> > TunnelList;
typedef boost::shared_ptr< std::vector<WorkSurfPtr> > WorkSurfList;

class ARXDAO_DLLIMPEXP Coal : public BaseDao
{
public:
	static CString GetTableName();
	static CoalPtr findOne(int id);
	static CoalList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	Coal();
	Coal(int id);
	Coal(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	MinePtr getMine() const;
	void setMine(const MinePtr& value);
	CString getCoalName() const;
	void setCoalName(const CString& value);
	int getCoalMinable() const;
	void setCoalMinable(const int& value);
	double getCoalThick() const;
	void setCoalThick(const double& value);
	int getCoalRank() const;
	void setCoalRank(const int& value);
	int getCoalQuality() const;
	void setCoalQuality(const int& value);
	double getLayerPressure() const;
	void setLayerPressure(const double& value);
	double getGasContent() const;
	void setGasContent(const double& value);
	double getGasPenetration() const;
	void setGasPenetration(const double& value);
	double getFValue() const;
	void setFValue(const double& value);
	int getResAbundance() const;
	void setResAbundance(const int& value);
	int getConstComplexity() const;
	void setConstComplexity(const int& value);
	int getMineIndex() const;
	void setMineIndex(const int& value);
	double getVarCoeff() const;
	void setVarCoeff(const double& value);
	double getCoalStability() const;
	void setCoalStability(const double& value);
	double getDipAngle() const;
	void setDipAngle(const double& value);
	double getCavingZoneHeight() const;
	void setCavingZoneHeight(const double& value);
	double getLayerGap() const;
	void setLayerGap(const double& value);
	double getInfluenceFactor() const;
	void setInfluenceFactor(const double& value);
	double getResA1() const;
	void setResA1(const double& value);
	double getGasX1() const;
	void setGasX1(const double& value);
	double getResA2() const;
	void setResA2(const double& value);
	double getGasX2() const;
	void setGasX2(const double& value);
	double getGasWc() const;
	void setGasWc(const double& value);
	double getCoalR() const;
	void setCoalR(const double& value);
	double getCoalVr() const;
	void setCoalVr(const double& value);
	double getGasW0() const;
	void setGasW0(const double& value);
	double getGasWc2() const;
	void setGasWc2(const double& value);
	double getGasEta() const;
	void setGasEta(const double& value);
	double getQR() const;
	void setQR(const double& value);
	double getQ0() const;
	void setQ0(const double& value);
	int getEvalMethod() const;
	void setEvalMethod(const int& value);
	double getQ0Alpha() const;
	void setQ0Alpha(const double& value);
	double getQtAlpha() const;
	void setQtAlpha(const double& value);
	double getTAlpha() const;
	void setTAlpha(const double& value);
	double getQLambda() const;
	void setQLambda(const double& value);
	double getRLambda() const;
	void setRLambda(const double& value);
	double getP0Lambda() const;
	void setP0Lambda(const double& value);
	double getP1Lambda() const;
	void setP1Lambda(const double& value);
	double getTLambda() const;
	void setTLambda(const double& value);
	double getALambda() const;
	void setALambda(const double& value);
	double getP1K() const;
	void setP1K(const double& value);
	double getP2K() const;
	void setP2K(const double& value);
	double getGasQ() const;
	void setGasQ(const double& value);
	double getCoreHeight() const;
	void setCoreHeight(const double& value);
	double getCoreArea() const;
	void setCoreArea(const double& value);
	double getGasViscosity() const;
	void setGasViscosity(const double& value);
	double getDecayAlpha() const;
	void setDecayAlpha(const double& value);
	double getPermeabilityLambda() const;
	void setPermeabilityLambda(const double& value);
	double getPermeabilityK() const;
	void setPermeabilityK(const double& value);
	int getEvalDifficult() const;
	void setEvalDifficult(const int& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	MinePtr mine;
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

class ARXDAO_DLLIMPEXP DrillingRadius : public BaseDao
{
public:
	static CString GetTableName();
	static DrillingRadiusPtr findOne(int id);
	static DrillingRadiusList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	DrillingRadius();
	DrillingRadius(int id);
	DrillingRadius(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	double getRadiusR() const;
	void setRadiusR(const double& value);
	double getRadiusL() const;
	void setRadiusL(const double& value);
	double getRadiusK1() const;
	void setRadiusK1(const double& value);
	double getRadiusRho() const;
	void setRadiusRho(const double& value);
	double getRadiusQ0() const;
	void setRadiusQ0(const double& value);
	double getRadiusA() const;
	void setRadiusA(const double& value);
	double getRadiusT() const;
	void setRadiusT(const double& value);
	double getRadiusQm1() const;
	void setRadiusQm1(const double& value);
	double getRadiusQm2() const;
	void setRadiusQm2(const double& value);
	double getRadiusQsum() const;
	void setRadiusQsum(const double& value);
	double getRadiusEta() const;
	void setRadiusEta(const double& value);

private:
	int id;
	CoalPtr coal;
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

class ARXDAO_DLLIMPEXP DrillingSurf : public BaseDao
{
public:
	static CString GetTableName();
	static DrillingSurfPtr findOne(int id);
	static DrillingSurfList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	DrillingSurf();
	DrillingSurf(int id);
	DrillingSurf(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	TunnelPtr getTunnel() const;
	void setTunnel(const TunnelPtr& value);
	double getQR() const;
	void setQR(const double& value);
	double getQA() const;
	void setQA(const double& value);
	double getTwQ4() const;
	void setTwQ4(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	CoalPtr coal;
	TunnelPtr tunnel;
	double q_r;
	double q_a;
	double tw_q4;
	CString comment;

}; // class DrillingSurf

class ARXDAO_DLLIMPEXP EvalUnit : public BaseDao
{
public:
	static CString GetTableName();
	static EvalUnitPtr findOne(int id);
	static EvalUnitList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	EvalUnit();
	EvalUnit(int id);
	EvalUnit(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	double getUnitL() const;
	void setUnitL(const double& value);
	double getUnitT() const;
	void setUnitT(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	WorkSurfPtr work_surf;
	double unit_l;
	double unit_t;
	CString comment;

}; // class EvalUnit

class ARXDAO_DLLIMPEXP Help : public BaseDao
{
public:
	static CString GetTableName();
	static HelpPtr findOne(int id);
	static HelpList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	Help();
	Help(int id);
	Help(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CString getHelpField() const;
	void setHelpField(const CString& value);
	int getHelpType() const;
	void setHelpType(const int& value);
	CString getHelpValue() const;
	void setHelpValue(const CString& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	CString help_field;
	int help_type;
	CString help_value;
	CString comment;

}; // class Help

class ARXDAO_DLLIMPEXP HighDrillingPore : public BaseDao
{
public:
	static CString GetTableName();
	static HighDrillingPorePtr findOne(int id);
	static HighDrillingPoreList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	HighDrillingPore();
	HighDrillingPore(int id);
	HighDrillingPore(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	double getHdpL1() const;
	void setHdpL1(const double& value);
	double getHdpL2() const;
	void setHdpL2(const double& value);
	double getHdpLg() const;
	void setHdpLg(const double& value);
	double getHdpHz() const;
	void setHdpHz(const double& value);
	double getHdpLk() const;
	void setHdpLk(const double& value);
	double getHdpLc() const;
	void setHdpLc(const double& value);
	double getHdpLw() const;
	void setHdpLw(const double& value);
	double getHdpN() const;
	void setHdpN(const double& value);
	double getHdpBeta() const;
	void setHdpBeta(const double& value);
	double getHdpLd() const;
	void setHdpLd(const double& value);
	double getHdpLzi() const;
	void setHdpLzi(const double& value);
	double getHdpLzj() const;
	void setHdpLzj(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	WorkSurfPtr work_surf;
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

class ARXDAO_DLLIMPEXP HighDrillingTunnel : public BaseDao
{
public:
	static CString GetTableName();
	static HighDrillingTunnelPtr findOne(int id);
	static HighDrillingTunnelList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	HighDrillingTunnel();
	HighDrillingTunnel(int id);
	HighDrillingTunnel(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	double getHdtK() const;
	void setHdtK(const double& value);
	int getHdtRock() const;
	void setHdtRock(const int& value);
	double getHdtHzMin() const;
	void setHdtHzMin(const double& value);
	double getHdtHzMax() const;
	void setHdtHzMax(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	WorkSurfPtr work_surf;
	double hdt_k;
	int hdt_rock;
	double hdt_hz_min;
	double hdt_hz_max;
	CString comment;

}; // class HighDrillingTunnel

class ARXDAO_DLLIMPEXP HydrGeo : public BaseDao
{
public:
	static CString GetTableName();
	static HydrGeoPtr findOne(int id);
	static HydrGeoList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	HydrGeo();
	HydrGeo(int id);
	HydrGeo(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CString getType() const;
	void setType(const CString& value);
	int getX1() const;
	void setX1(const int& value);
	double getX2() const;
	void setX2(const double& value);
	int getX3() const;
	void setX3(const int& value);
	double getX4() const;
	void setX4(const double& value);
	double getX5() const;
	void setX5(const double& value);
	double getX6() const;
	void setX6(const double& value);
	double getX7() const;
	void setX7(const double& value);
	CString getX8() const;
	void setX8(const CString& value);

private:
	int id;
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

class ARXDAO_DLLIMPEXP KeyLayer : public BaseDao
{
public:
	static CString GetTableName();
	static KeyLayerPtr findOne(int id);
	static KeyLayerList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	KeyLayer();
	KeyLayer(int id);
	KeyLayer(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	HighDrillingPorePtr getHighDrillingPore() const;
	void setHighDrillingPore(const HighDrillingPorePtr& value);
	double getKeyHn() const;
	void setKeyHn(const double& value);
	double getKeyThetan() const;
	void setKeyThetan(const double& value);
	double getKeyQn() const;
	void setKeyQn(const double& value);
	double getKeyRtn() const;
	void setKeyRtn(const double& value);
	double getKeySumHn() const;
	void setKeySumHn(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	HighDrillingPorePtr high_drilling_pore;
	double key_hn;
	double key_thetan;
	double key_qn;
	double key_rtn;
	double key_sum_hn;
	CString comment;

}; // class KeyLayer

class ARXDAO_DLLIMPEXP Mine : public BaseDao
{
public:
	static CString GetTableName();
	static MinePtr findOne(int id);
	static MineList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	Mine();
	Mine(int id);
	Mine(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	MineRegionPtr getMineRegion() const;
	void setMineRegion(const MineRegionPtr& value);
	CString getUsername() const;
	void setUsername(const CString& value);
	CString getPassword() const;
	void setPassword(const CString& value);
	CString getMineName() const;
	void setMineName(const CString& value);
	CString getMineAddress() const;
	void setMineAddress(const CString& value);
	double getCoalCapacity() const;
	void setCoalCapacity(const double& value);
	int getTopoGeo() const;
	void setTopoGeo(const int& value);
	int getHydrGeo() const;
	void setHydrGeo(const int& value);
	int getGroundCondition() const;
	void setGroundCondition(const int& value);
	double getQR() const;
	void setQR(const double& value);
	CString getStereoSchemDiagram() const;
	void setStereoSchemDiagram(const CString& value);
	double getKGas() const;
	void setKGas(const double& value);
	double getReserveW1() const;
	void setReserveW1(const double& value);
	double getReserveW2() const;
	void setReserveW2(const double& value);
	double getReserveW3() const;
	void setReserveW3(const double& value);
	double getReserveGas() const;
	void setReserveGas(const double& value);
	double getPumpKd() const;
	void setPumpKd(const double& value);
	double getPumpK1() const;
	void setPumpK1(const double& value);
	double getPumpK2() const;
	void setPumpK2(const double& value);
	double getPumpK3() const;
	void setPumpK3(const double& value);
	double getPumpK4() const;
	void setPumpK4(const double& value);
	double getPumpWc() const;
	void setPumpWc(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	MineRegionPtr mine_region;
	CString username;
	CString password;
	CString mine_name;
	CString mine_address;
	double coal_capacity;
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

class ARXDAO_DLLIMPEXP MineBase : public BaseDao
{
public:
	static CString GetTableName();
	static MineBasePtr findOne(int id);
	static MineBaseList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	MineBase();
	MineBase(int id);
	MineBase(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CString getName() const;
	void setName(const CString& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	CString name;
	CString comment;

}; // class MineBase

class ARXDAO_DLLIMPEXP MineRegion : public BaseDao
{
public:
	static CString GetTableName();
	static MineRegionPtr findOne(int id);
	static MineRegionList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	MineRegion();
	MineRegion(int id);
	MineRegion(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	MineBasePtr getMineBase() const;
	void setMineBase(const MineBasePtr& value);
	CString getName() const;
	void setName(const CString& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	MineBasePtr mine_base;
	CString name;
	CString comment;

}; // class MineRegion

class ARXDAO_DLLIMPEXP MiningArea : public BaseDao
{
public:
	static CString GetTableName();
	static MiningAreaPtr findOne(int id);
	static MiningAreaList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	MiningArea();
	MiningArea(int id);
	MiningArea(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	int getAreaMode() const;
	void setAreaMode(const int& value);
	double getAreaK() const;
	void setAreaK(const double& value);
	double getA() const;
	void setA(const double& value);
	double getQR() const;
	void setQR(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	CoalPtr coal;
	int area_mode;
	double area_k;
	double a;
	double q_r;
	CString comment;

}; // class MiningArea

class ARXDAO_DLLIMPEXP PoreFlow : public BaseDao
{
public:
	static CString GetTableName();
	static PoreFlowPtr findOne(int id);
	static PoreFlowList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	PoreFlow();
	PoreFlow(int id);
	PoreFlow(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	double getFlowT() const;
	void setFlowT(const double& value);
	double getFlowA0() const;
	void setFlowA0(const double& value);
	double getFlowD() const;
	void setFlowD(const double& value);
	double getFlowD1() const;
	void setFlowD1(const double& value);
	double getFlowM() const;
	void setFlowM(const double& value);
	double getFlowK() const;
	void setFlowK(const double& value);
	double getFlowDeltaT() const;
	void setFlowDeltaT(const double& value);
	double getFlowX() const;
	void setFlowX(const double& value);
	double getFlowPTest() const;
	void setFlowPTest(const double& value);
	double getFlowPCur() const;
	void setFlowPCur(const double& value);
	double getFlowB() const;
	void setFlowB(const double& value);
	double getFlowPt() const;
	void setFlowPt(const double& value);
	double getFlowDeltaP() const;
	void setFlowDeltaP(const double& value);
	double getFlowDh() const;
	void setFlowDh(const double& value);
	double getFlowQHun() const;
	void setFlowQHun(const double& value);
	double getFlowQChun() const;
	void setFlowQChun(const double& value);

private:
	int id;
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

class ARXDAO_DLLIMPEXP PoreSize : public BaseDao
{
public:
	static CString GetTableName();
	static PoreSizePtr findOne(int id);
	static PoreSizeList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	PoreSize();
	PoreSize(int id);
	PoreSize(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	double getSizeQ() const;
	void setSizeQ(const double& value);
	double getSizeV() const;
	void setSizeV(const double& value);
	double getSizeD() const;
	void setSizeD(const double& value);
	double getSizeP() const;
	void setSizeP(const double& value);
	double getSizeSigma() const;
	void setSizeSigma(const double& value);
	double getSizeDelta() const;
	void setSizeDelta(const double& value);

private:
	int id;
	double size_q;
	double size_v;
	double size_d;
	double size_p;
	double size_sigma;
	double size_delta;

}; // class PoreSize

class ARXDAO_DLLIMPEXP ReadyTunnel : public BaseDao
{
public:
	static CString GetTableName();
	static ReadyTunnelPtr findOne(int id);
	static ReadyTunnelList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	ReadyTunnel();
	ReadyTunnel(int id);
	ReadyTunnel(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	MiningAreaPtr getMiningArea() const;
	void setMiningArea(const MiningAreaPtr& value);
	TunnelPtr getTunnel() const;
	void setTunnel(const TunnelPtr& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	MiningAreaPtr mining_area;
	TunnelPtr tunnel;
	CString comment;

}; // class ReadyTunnel

class ARXDAO_DLLIMPEXP ResAbundance : public BaseDao
{
public:
	static CString GetTableName();
	static ResAbundancePtr findOne(int id);
	static ResAbundanceList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	ResAbundance();
	ResAbundance(int id);
	ResAbundance(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CString getType() const;
	void setType(const CString& value);
	double getMinAbundance() const;
	void setMinAbundance(const double& value);
	double getMaxAbundance() const;
	void setMaxAbundance(const double& value);

private:
	int id;
	CString type;
	double min_abundance;
	double max_abundance;

}; // class ResAbundance

class ARXDAO_DLLIMPEXP TechMode : public BaseDao
{
public:
	static CString GetTableName();
	static TechModePtr findOne(int id);
	static TechModeList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	TechMode();
	TechMode(int id);
	TechMode(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	MineRegionPtr getMineRegion() const;
	void setMineRegion(const MineRegionPtr& value);
	CString getName() const;
	void setName(const CString& value);
	int getType() const;
	void setType(const int& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	MineRegionPtr mine_region;
	CString name;
	int type;
	CString comment;

}; // class TechMode

class ARXDAO_DLLIMPEXP Technology : public BaseDao
{
public:
	static CString GetTableName();
	static TechnologyPtr findOne(int id);
	static TechnologyList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	Technology();
	Technology(int id);
	Technology(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	MineRegionPtr getMineRegion() const;
	void setMineRegion(const MineRegionPtr& value);
	CString getName() const;
	void setName(const CString& value);
	int getIskey() const;
	void setIskey(const int& value);
	CString getDoc() const;
	void setDoc(const CString& value);
	CString getVideo() const;
	void setVideo(const CString& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	MineRegionPtr mine_region;
	CString name;
	int iskey;
	CString doc;
	CString video;
	CString comment;

}; // class Technology

class ARXDAO_DLLIMPEXP TopoGeo : public BaseDao
{
public:
	static CString GetTableName();
	static TopoGeoPtr findOne(int id);
	static TopoGeoList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	TopoGeo();
	TopoGeo(int id);
	TopoGeo(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	CString getType() const;
	void setType(const CString& value);
	CString getFeature() const;
	void setFeature(const CString& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	CString type;
	CString feature;
	CString comment;

}; // class TopoGeo

class ARXDAO_DLLIMPEXP Tunnel : public BaseDao
{
public:
	static CString GetTableName();
	static TunnelPtr findOne(int id);
	static TunnelList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	Tunnel();
	Tunnel(int id);
	Tunnel(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	double getB() const;
	void setB(const double& value);
	double getL() const;
	void setL(const double& value);
	double getS() const;
	void setS(const double& value);
	double getD() const;
	void setD(const double& value);
	double getWh() const;
	void setWh(const double& value);
	double getV() const;
	void setV(const double& value);
	double getQa() const;
	void setQa(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	double b;
	double l;
	double s;
	double d;
	double wh;
	double v;
	double qa;
	CString comment;

}; // class Tunnel

class ARXDAO_DLLIMPEXP WorkSurf : public BaseDao
{
public:
	static CString GetTableName();
	static WorkSurfPtr findOne(int id);
	static WorkSurfList findAll();
	int insert();;
	bool update();
	bool remove();

public:
	WorkSurf();
	WorkSurf(int id);
	WorkSurf(soci::row& rs);
	CString getSqlInsert() const;
	CString getSqlUpdate() const;
	CString getSqlDelete() const;
	int getId() const;
	void setId(const int& value);
	TunnelPtr getTunnel() const;
	void setTunnel(const TunnelPtr& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	double getA() const;
	void setA(const double& value);
	double getQR() const;
	void setQR(const double& value);
	double getQA() const;
	void setQA(const double& value);
	double getWsL() const;
	void setWsL(const double& value);
	int getWsLayerable() const;
	void setWsLayerable(const int& value);
	double getWsK1() const;
	void setWsK1(const double& value);
	double getWsK2() const;
	void setWsK2(const double& value);
	double getWsK3() const;
	void setWsK3(const double& value);
	double getWsKf() const;
	void setWsKf(const double& value);
	double getWsH() const;
	void setWsH(const double& value);
	int getWsMethod() const;
	void setWsMethod(const int& value);
	double getLastT() const;
	void setLastT(const double& value);
	CString getComment() const;
	void setComment(const CString& value);

private:
	int id;
	TunnelPtr tunnel;
	CoalPtr coal;
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
