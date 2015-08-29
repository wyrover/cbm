#include "StdAfx.h"
#include "DefGEPlugin.h"

//巷道
#include "TunnelDraw.h"
//钻孔
#include "DrillPoreDraw.h"
//钻场
#include "DrillSiteDraw.h"
//煤层面
#include "CoalSurfaceDraw.h"

void DefGEPlugin::initialize( MineGEDrawManager* pGEDrawManager )
{
    BEGIN_REGISTER_MINEGE_DRAW( MineGEDrawManager, pGEDrawManager )
    // 巷道
    REGISTER_MINEGE_DRAW( Tunnel, TunnelDraw )
    //钻孔
    REGISTER_MINEGE_DRAW( Pore, DrillPoreDraw );
    //钻场
    REGISTER_MINEGE_DRAW( DrillSite, DrillSiteDraw );
    //煤层面
    REGISTER_MINEGE_DRAW( CoalSurface, CoalSurfaceDraw );
    END_REGISTER_MINEGE_DRAW
}

void DefGEPlugin::unInitialize( MineGEDrawManager* pGEDrawManager )
{
    BEGIN_UNREGISTER_MINEGE_DRAW( MineGEDrawManager, pGEDrawManager )
    // 巷道
    UNREGISTER_MINEGE_DRAW( Tunnel, TunnelDraw )
    //钻孔
    UNREGISTER_MINEGE_DRAW( Pore, DrillPoreDraw );
    //钻场
    UNREGISTER_MINEGE_DRAW( DrillSite, DrillSiteDraw );
    //煤层面
    UNREGISTER_MINEGE_DRAW( CoalSurface, CoalSurfaceDraw );
    END_UNREGISTER_MINEGE_DRAW
}

// 插件创建函数定义实现并导出
MINEGE_PLUGIN_CREATE_FUNC_IMPL( DefGEPlugin )
