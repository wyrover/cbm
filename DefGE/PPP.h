#pragma once

#include "PointGE.h"

// 动力现象点
// PPP ==> Power Phenomenon Point
class DEFGE_EXPORT_API PPP : public PointGE
{
public:
	ACRX_DECLARE_MEMBERS(PPP) ;

protected:
	static Adesk::UInt32 kCurrentVersionNumber ;

public:
	PPP();
	PPP(const AcGePoint3d& insertPt);
};

#ifdef DEFGE_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(PPP)
#endif
