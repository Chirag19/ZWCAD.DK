#ifndef _zrxkernel_h
#define _zrxkernel_h 1


#include "zrxsrvice.h"
#pragma pack (push, 8)

class ZcRxClass;
class ZcRxDictionary;

class ZDESK_NO_VTABLE ZcRxKernel : public ZcRxService
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxKernel);
    ZcRxKernel();
    virtual ~ZcRxKernel();

    virtual
    ZcRxDictionary* newZcRxDictionary(Zdesk::Boolean sorted = Zdesk::kTrue,
                                      Zdesk::Boolean ignoreCase
                                                           = Zdesk::kFalse) = 0;

    virtual
    ZcRxDictionary* newZcRxDictionary(unsigned long length,
                                      Zdesk::Boolean delObjects,
                                      Zdesk::Boolean sorted = Zdesk::kTrue,
                                      Zdesk::Boolean ignoreCase
                                                           = Zdesk::kFalse) = 0;

    virtual
    ZcRxDictionary* newZcRxDictionary(const ZcRxClass * filter) = 0;
};

#define zcrxKernel \
    ZcRxKernel::cast(ZcRxDictionary::cast(\
    zcrxSysRegistry()->at(ZCRX_SERVICE_DICTIONARY))->at(ZCRX_KERNEL_SERVICES))

#pragma pack (pop)
#endif
