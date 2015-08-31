#include "StdAfx.h"
#include "SystemHelper.h"
#include "HelperClass.h"
#include "config.h"

void SystemHelper::Start()
{
	// ×¢²ádictionaryºÍregAppName
	ArxDictTool::RegDict( PROPERTY_DATA_FIELD_DICT );
	ArxDictTool::RegDict( PROPERTY_DATA_FIELD_INFO_DICT );
	ArxDictTool::RegDict( FUNC_FIELD_DICT );

	//ArxDataTool::RegAppName( acdbHostApplicationServices()->workingDatabase(), DRAW_PARAMS_XDATA_GROUP );
}

void SystemHelper::ShutDown()
{

}
