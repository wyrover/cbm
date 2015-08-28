#include "StdAfx.h"
#include "DefGEPlugin.h"

// 双线巷道
#include "DoubleTunnelDraw.h"
// 多段线箭头
#include "PolyLineDirectionDraw.h"
//钻孔
#include "SimplePoreDraw.h"
//钻场
#include "SimpleDrillSiteDraw.h"
//煤层面
#include "SimpleCoalSurfaceDraw.h"

void DefGEPlugin::initialize( MineGEDrawManager* pGEDrawManager )
{
    BEGIN_REGISTER_MINEGE_DRAW( MineGEDrawManager, pGEDrawManager )
    // 巷道
    REGISTER_MINEGE_DRAW( Tunnel, DoubleTunnelDraw )
    //风流方向
    REGISTER_MINEGE_DRAW( WindDirection, PolyLineDirectionDraw )
    //钻孔
    REGISTER_MINEGE_DRAW( Pore, SimplePoreDraw );
    //钻场
    REGISTER_MINEGE_DRAW( DrillSite, SimpleDrillSiteDraw );
    //煤层面
    REGISTER_MINEGE_DRAW( CoalSurface, SimpleCoalSurfaceDraw );
    END_REGISTER_MINEGE_DRAW
}

void DefGEPlugin::unInitialize( MineGEDrawManager* pGEDrawManager )
{
    BEGIN_UNREGISTER_MINEGE_DRAW( MineGEDrawManager, pGEDrawManager )
    // 巷道
    UNREGISTER_MINEGE_DRAW( Tunnel, DoubleTunnelDraw )
    // 风流方向
    UNREGISTER_MINEGE_DRAW( WindDirection, PolyLineDirectionDraw )
    //钻孔
    UNREGISTER_MINEGE_DRAW( Pore, SimplePoreDraw );
    //钻场
    UNREGISTER_MINEGE_DRAW( DrillSite, SimpleDrillSiteDraw );
    //煤层面
    UNREGISTER_MINEGE_DRAW( CoalSurface, SimpleCoalSurfaceDraw );
    END_UNREGISTER_MINEGE_DRAW
}

// 插件创建函数定义实现并导出
MINEGE_PLUGIN_CREATE_FUNC_IMPL( DefGEPlugin )
