#ifndef ZDOUBLECLICKEDIT_H
#define ZDOUBLECLICKEDIT_H

#include "zcdb.h"
#include "zdbmain.h"

#pragma pack (push, 8)

class ZDESK_NO_VTABLE ZcDbDoubleClickEdit : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDoubleClickEdit);

    virtual void startEdit(ZcDbEntity *pEnt, ZcGePoint3d pt) = 0; 
    virtual void finishEdit(void) = 0;
};

#pragma pack (pop)

#endif
