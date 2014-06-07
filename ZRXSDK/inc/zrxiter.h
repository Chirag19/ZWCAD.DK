

#ifndef _Zrxiter_h
#define _Zrxiter_h 1

#include "zrxobject.h"
#pragma pack (push, 8)

class ZcRxIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxIterator);

    virtual Zdesk::Boolean done() const = 0;
    virtual Zdesk::Boolean next() = 0;
    virtual ZcRxObject*    object() const = 0;
};

#pragma pack (pop)
#endif
