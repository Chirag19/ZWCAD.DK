#ifndef _ZD_DBID_OPS_H
#define _ZD_DBID_OPS_H 1


#include "zdesk.h"

class ZcDbStub;

bool
c5ObjIdIsLessThan(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdIsGreaterThan(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdLessThanOrEqual(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdGreaterThanOrEqual(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdIsEqualTo(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c4ObjIdIsLessThan(Zdesk::ULongPtr lhs, Zdesk::ULongPtr rhs); 

bool
c4ObjIdIsGreaterThan(Zdesk::ULongPtr lhs, Zdesk::ULongPtr rhs); 

bool
c4ObjIdLessThanOrEqual(Zdesk::ULongPtr lhs, Zdesk::ULongPtr rhs); 

bool
c4ObjIdGreaterThanOrEqual(Zdesk::ULongPtr lhs, Zdesk::ULongPtr rhs); 

bool
c4ObjIdIsEqualTo(Zdesk::ULongPtr lhs, Zdesk::ULongPtr rhs); 

bool
c4ObjIdNotEqualTo(Zdesk::ULongPtr lhs, Zdesk::ULongPtr rhs); 

#endif

