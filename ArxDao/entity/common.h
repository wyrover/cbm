#ifndef CBM_COMMON_H
#define CBM_COMMON_H

#include <vector>
#include <boost/shared_ptr.hpp>

namespace cbm {

class Coal;
typedef boost::shared_ptr<Coal> CoalPtr;
typedef boost::shared_ptr< std::vector<CoalPtr> > CoalList;

class CoalLayer;
typedef boost::shared_ptr<CoalLayer> CoalLayerPtr;
typedef boost::shared_ptr< std::vector<CoalLayerPtr> > CoalLayerList;

class DrillingRadius;
typedef boost::shared_ptr<DrillingRadius> DrillingRadiusPtr;
typedef boost::shared_ptr< std::vector<DrillingRadiusPtr> > DrillingRadiusList;

class DrillingSurf;
typedef boost::shared_ptr<DrillingSurf> DrillingSurfPtr;
typedef boost::shared_ptr< std::vector<DrillingSurfPtr> > DrillingSurfList;

class EvalUnit;
typedef boost::shared_ptr<EvalUnit> EvalUnitPtr;
typedef boost::shared_ptr< std::vector<EvalUnitPtr> > EvalUnitList;

class Help;
typedef boost::shared_ptr<Help> HelpPtr;
typedef boost::shared_ptr< std::vector<HelpPtr> > HelpList;

class HighDrillingPore;
typedef boost::shared_ptr<HighDrillingPore> HighDrillingPorePtr;
typedef boost::shared_ptr< std::vector<HighDrillingPorePtr> > HighDrillingPoreList;

class HighDrillingTunnel;
typedef boost::shared_ptr<HighDrillingTunnel> HighDrillingTunnelPtr;
typedef boost::shared_ptr< std::vector<HighDrillingTunnelPtr> > HighDrillingTunnelList;

class HydrGeo;
typedef boost::shared_ptr<HydrGeo> HydrGeoPtr;
typedef boost::shared_ptr< std::vector<HydrGeoPtr> > HydrGeoList;

class KeyLayer;
typedef boost::shared_ptr<KeyLayer> KeyLayerPtr;
typedef boost::shared_ptr< std::vector<KeyLayerPtr> > KeyLayerList;

class Mine;
typedef boost::shared_ptr<Mine> MinePtr;
typedef boost::shared_ptr< std::vector<MinePtr> > MineList;

class MineBase;
typedef boost::shared_ptr<MineBase> MineBasePtr;
typedef boost::shared_ptr< std::vector<MineBasePtr> > MineBaseList;

class MiningArea;
typedef boost::shared_ptr<MiningArea> MiningAreaPtr;
typedef boost::shared_ptr< std::vector<MiningAreaPtr> > MiningAreaList;

class PoreFlow;
typedef boost::shared_ptr<PoreFlow> PoreFlowPtr;
typedef boost::shared_ptr< std::vector<PoreFlowPtr> > PoreFlowList;

class PoreSize;
typedef boost::shared_ptr<PoreSize> PoreSizePtr;
typedef boost::shared_ptr< std::vector<PoreSizePtr> > PoreSizeList;

class ReadyTunnel;
typedef boost::shared_ptr<ReadyTunnel> ReadyTunnelPtr;
typedef boost::shared_ptr< std::vector<ReadyTunnelPtr> > ReadyTunnelList;

class ResAbundance;
typedef boost::shared_ptr<ResAbundance> ResAbundancePtr;
typedef boost::shared_ptr< std::vector<ResAbundancePtr> > ResAbundanceList;

class TechMode;
typedef boost::shared_ptr<TechMode> TechModePtr;
typedef boost::shared_ptr< std::vector<TechModePtr> > TechModeList;

class Technology;
typedef boost::shared_ptr<Technology> TechnologyPtr;
typedef boost::shared_ptr< std::vector<TechnologyPtr> > TechnologyList;

class TopoGeo;
typedef boost::shared_ptr<TopoGeo> TopoGeoPtr;
typedef boost::shared_ptr< std::vector<TopoGeoPtr> > TopoGeoList;

class Tunnel;
typedef boost::shared_ptr<Tunnel> TunnelPtr;
typedef boost::shared_ptr< std::vector<TunnelPtr> > TunnelList;

class WorkSurf;
typedef boost::shared_ptr<WorkSurf> WorkSurfPtr;
typedef boost::shared_ptr< std::vector<WorkSurfPtr> > WorkSurfList;

class MineRegion;
typedef boost::shared_ptr<MineRegion> MineRegionPtr;
typedef boost::shared_ptr< std::vector<MineRegionPtr> > MineRegionList;

} // namespace cbm

#endif // CBM_COMMON_H
