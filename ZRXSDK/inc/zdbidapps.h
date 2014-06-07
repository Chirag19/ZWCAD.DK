#ifndef _ZD_DBID_APPS_H
#define _ZD_DBID_APPS_H 1


#include "zdesk.h"
#include "zdbid.h"
#include "zdbid_ops.h"
#pragma pack (push, 8)



inline bool
ZcDbObjectId::operator < (const ZcDbObjectId& id) const
{ return c5ObjIdIsLessThan(*this, id); }

inline bool
ZcDbObjectId::operator > (const ZcDbObjectId& id) const
{ return c5ObjIdIsGreaterThan(*this, id); }

inline bool
ZcDbObjectId::operator <= (const ZcDbObjectId& id) const
{ return c5ObjIdLessThanOrEqual(*this, id); }

inline bool
ZcDbObjectId::operator >= (const ZcDbObjectId& id) const
{ return c5ObjIdGreaterThanOrEqual(*this, id); }

inline bool
ZcDbObjectId::operator == (const ZcDbObjectId& id) const
{ return c5ObjIdIsEqualTo(*this, id); }

inline bool
ZcDbObjectId::operator != (const ZcDbObjectId& id) const
{ return !c5ObjIdIsEqualTo(*this, id); }





inline bool
ZcDbObjectId::operator < (const ZcDbStub* pStub) const
{ return c5ObjIdIsLessThan(*this, pStub); }

inline bool
ZcDbObjectId::operator > (const ZcDbStub* pStub) const
{ return c5ObjIdIsGreaterThan(*this, pStub); }

inline bool
ZcDbObjectId::operator <= (const ZcDbStub* pStub) const
{ return c5ObjIdLessThanOrEqual(*this, pStub); }

inline bool
ZcDbObjectId::operator >= (const ZcDbStub* pStub) const
{ return c5ObjIdGreaterThanOrEqual(*this, pStub); }

inline bool
ZcDbObjectId::operator == (const ZcDbStub* pStub) const
{ return c5ObjIdIsEqualTo(*this, pStub); }

inline bool
ZcDbObjectId::operator != (const ZcDbStub* pStub) const
{ return !c5ObjIdIsEqualTo(*this, pStub); }




class ZcDbR13ObjectId : public ZcDbObjectId
{

public:

    bool operator < (const ZcDbR13ObjectId& id) const;
    bool operator > (const ZcDbR13ObjectId& id) const;
    bool operator <= (const ZcDbR13ObjectId& id) const;
    bool operator >= (const ZcDbR13ObjectId& id) const;
    bool operator == (const ZcDbR13ObjectId& id) const;
    bool operator != (const ZcDbR13ObjectId& id) const;

    bool operator < (const ZcDbStub* pStub) const;
    bool operator > (const ZcDbStub* pStub) const;
    bool operator <= (const ZcDbStub* pStub) const;
    bool operator >= (const ZcDbStub* pStub) const;
    bool operator == (const ZcDbStub* pStub) const;
    bool operator != (const ZcDbStub* pStub) const;

};


#pragma pack (pop)
#endif 
