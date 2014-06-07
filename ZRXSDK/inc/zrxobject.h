
#ifndef ZD_RXOBJECT_H
#define ZD_RXOBJECT_H 1



#include "zrxdefs.h"
#include "zrxboiler.h"
#include "zcadstrc.h"

#pragma pack (push, 8)

#ifdef  ZCDB_API
    #  define   ZCDB_PORT __declspec(dllexport)
#else
    #  define   ZCDB_PORT
#endif

class ZcRxClass;

class ZDESK_NO_VTABLE ZcRxObject
{
public:
    virtual ~ZcRxObject();

    static ZcRxClass*         desc();
    static ZcRxObject*        cast(const ZcRxObject * inPtr);

    inline bool               isKindOf(const ZcRxClass * aClass) const;

    ZcRxObject*               queryX(const ZcRxClass* protocolClass) const;


    ZcRxObject*               x(const ZcRxClass* protocolClass) const;
    virtual ZcRxClass*        isA() const;

    virtual ZcRxObject*       clone() const;
    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);
    virtual Zdesk::Boolean    isEqualTo(const ZcRxObject * other) const;
    virtual ZcRx::Ordering    comparedTo(const ZcRxObject * other) const;

protected:
    ZcRxObject();
};


#pragma pack (pop)

#include "zrxclass.h"

#define ZCRX_PE_PTR(ZRxObj,PEClass) PEClass::cast(ZRxObj-> \
                                            queryX(PEClass::desc()))


#define ZCRX_X_CALL(ZRxObj,PEClass) PEClass::cast(ZRxObj->x(PEClass::desc()))

#include "zrxdict.h"

#endif

