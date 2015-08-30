#include "stdafx.h"

#include "DefaultCurDrawHelper.h"
#include "config.h"
#include "DrawHelper.h"

#include <ArxHelper/HelperClass.h>
#include <MineGEDraw/MineGEDrawSystem.h>

static void BuildCurDrawsDict( const AcStringArray& types )
{
    MineGEDrawSystem* pDrawSystem = MineGEDrawSystem::GetInstance();
    if( pDrawSystem == 0 ) return;

    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( CUR_DRAW_DICT );
    int len = types.length();

    for( int i = 0; i < len; i++ )
    {
        CString type = types[i].kACharPtr();
        if( !pDictTool->findKey( type ) )
        {
            pDictTool->addEntry( type, pDrawSystem->getDefaultGEDrawName( type ) );
        }
    }

    delete pDictTool;
}

// 设置当前可视化效果
void InitAllDefaultCurDraws()
{
    AcStringArray types;
    DrawHelper::GetAllRegGETypesForDraw( types );
    if( types.isEmpty() ) return;

    BuildCurDrawsDict( types );
}

bool SetDefaultCurDraw( const CString& type, const CString& draw )
{
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( CUR_DRAW_DICT );
    bool ret = pDictTool->modifyEntry( type, 1, draw );
    delete pDictTool;

    return ret;
}

bool GetDefaultCurDraw( const CString& type, CString& draw )
{
    ArxDictTool* pDictTool = ArxDictTool::GetDictTool( CUR_DRAW_DICT );
    bool ret = pDictTool->getEntry( type, 1, draw );
    delete pDictTool;

    return ret;
}

MineGEDraw* GetDefaultCurDrawPtr( const CString& type )
{
	MineGEDraw* pDraw = 0;

	CString draw;
	if( GetDefaultCurDraw( type, draw ) )
	{
		MineGEDrawSystem* pDrawSystem = MineGEDrawSystem::GetInstance();
		if( pDrawSystem != 0 )
		{
			pDraw = pDrawSystem->getGEDraw( type, draw );
		}
	}
	return pDraw;
}
