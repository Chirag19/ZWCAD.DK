#ifndef _zrxdict_h
#define _zrxdict_h 1

#include "zrxobject.h"
#include "ZdZChar.h"

#pragma pack (push, 8)

class ZcRxDictionaryIterator;

class ZcRxDictionary: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxDictionary);

    virtual ZcRxObject*    at      (const ZCHAR* key) const = 0;
    virtual ZcRxObject*    at      (Zdesk::UInt32 id) const = 0;

    ZcRxObject*            atPut   (const ZCHAR* key, ZcRxObject* pObject);
    virtual ZcRxObject*    atPut   (const ZCHAR* key, ZcRxObject* pObject,
        Zdesk::UInt32& retId) = 0;
    virtual ZcRxObject*    atPut   (Zdesk::UInt32 id, ZcRxObject* pObject) = 0;

    virtual Zdesk::Boolean resetKey(const ZCHAR* oldKey, const ZCHAR* newKey) = 0;
    virtual Zdesk::Boolean resetKey(Zdesk::UInt32 id, const ZCHAR* newKey) = 0;

    virtual Zdesk::Boolean atKeyAndIdPut(const ZCHAR* newKey, Zdesk::UInt32 id,
        ZcRxObject* pObject) = 0;

    virtual ZcRxObject*    remove  (const ZCHAR* key) = 0;
    virtual ZcRxObject*    remove  (Zdesk::UInt32 id) = 0;

    virtual Zdesk::Boolean has     (const ZCHAR* entryName) const = 0;
    virtual Zdesk::Boolean has     (Zdesk::UInt32 id) const = 0;

    virtual Zdesk::UInt32  idAt    (const ZCHAR* key) const = 0;

    virtual const ZCHAR*    keyAt   (Zdesk::UInt32 id) const = 0;

    virtual Zdesk::UInt32  numEntries() const = 0;

    virtual ZcRxDictionaryIterator* newIterator(
        ZcRx::DictIterType type = ZcRx::kDictSorted) = 0;

    virtual Zdesk::Boolean deletesObjects() const = 0;
    virtual Zdesk::Boolean isCaseSensitive() const = 0;
    virtual Zdesk::Boolean isSorted() const = 0;
};

extern "C" ZcRxDictionary* zcrxSysRegistry();

inline ZcRxObject* ZcRxDictionary::atPut(const ZCHAR* key, ZcRxObject* pObj)
{ Zdesk::UInt32 temp; return atPut(key, pObj, temp); }

#define zcrxClassDictionary \
ZcRxDictionary::cast(zcrxSysRegistry()->at(ZCRX_CLASS_DICTIONARY))

#define zcrxServiceDictionary \
ZcRxDictionary::cast(zcrxSysRegistry()->at(ZCRX_SERVICE_DICTIONARY))

#pragma pack (pop)
#endif
