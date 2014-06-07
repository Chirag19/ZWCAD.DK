

#ifndef _ZDBSELECTGRIP_H
#define _ZDBSELECTGRIP_H

#include "zcdb.h"
#include "zdbmain.h"

#pragma pack (push, 8)


class ZDESK_NO_VTABLE ZcDbSelectGrip : public ZcRxObject {
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSelectGrip);


    virtual bool SelectGrip(const ZcDbEntity * pEnt, 
		                    const ZcGiViewportDraw* pVd,
							const void * pAppData) = 0;
};

#pragma pack (pop)

#endif  // _ZDBSELECTGRIP_H

