#ifndef CBM_COMMON_H
#define CBM_COMMON_H

#include <vector>
#include <boost/shared_ptr.hpp>

namespace cbm {

class AdjLayer;
typedef boost::shared_ptr<AdjLayer> AdjLayerPtr;
typedef boost::shared_ptr< std::vector<AdjLayerPtr> > AdjLayerList;

class Coal;
typedef boost::shared_ptr<Coal> CoalPtr;
typedef boost::shared_ptr< std::vector<CoalPtr> > CoalList;

class DrillingRadius;
typedef boost::shared_ptr<DrillingRadius> DrillingRadiusPtr;
typedef boost::shared_ptr< std::vector<DrillingRadiusPtr> > DrillingRadiusList;

class DrillingSurf;
typedef boost::shared_ptr<DrillingSurf> DrillingSurfPtr;
typedef boost::shared_ptr< std::vector<DrillingSurfPtr> > DrillingSurfList;

class EvalUnit;
typedef boost::shared_ptr<EvalUnit> EvalUnitPtr;
typedef boost::shared_ptr< std::vector<EvalUnitPtr> > EvalUnitList;

class GasPump;
typedef boost::shared_ptr<GasPump> GasPumpPtr;
typedef boost::shared_ptr< std::vector<GasPumpPtr> > GasPumpList;

class GasReserve;
typedef boost::shared_ptr<GasReserve> GasReservePtr;
typedef boost::shared_ptr< std::vector<GasReservePtr> > GasReserveList;

class Help;
typedef boost::shared_ptr<Help> HelpPtr;
typedef boost::shared_ptr< std::vector<HelpPtr> > HelpList;

class HighDrillingPore;
typedef boost::shared_ptr<HighDrillingPore> HighDrillingPorePtr;
typedef boost::shared_ptr< std::vector<HighDrillingPorePtr> > HighDrillingPoreList;

class HighDrillingTunnel;
typedef boost::shared_ptr<HighDrillingTunnel> HighDrillingTunnelPtr;
typedef boost::shared_ptr< std::vector<HighDrillingTunnelPtr> > HighDrillingTunnelList;

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

class PumpDegree;
typedef boost::shared_ptr<PumpDegree> PumpDegreePtr;
typedef boost::shared_ptr< std::vector<PumpDegreePtr> > PumpDegreeList;

class ReadyTunnel;
typedef boost::shared_ptr<ReadyTunnel> ReadyTunnelPtr;
typedef boost::shared_ptr< std::vector<ReadyTunnelPtr> > ReadyTunnelList;

class RecomTech;
typedef boost::shared_ptr<RecomTech> RecomTechPtr;
typedef boost::shared_ptr< std::vector<RecomTechPtr> > RecomTechList;

class TechMode;
typedef boost::shared_ptr<TechMode> TechModePtr;
typedef boost::shared_ptr< std::vector<TechModePtr> > TechModeList;

class WorkSurf;
typedef boost::shared_ptr<WorkSurf> WorkSurfPtr;
typedef boost::shared_ptr< std::vector<WorkSurfPtr> > WorkSurfList;

} // namespace cbm

#endif // CBM_COMMON_H
