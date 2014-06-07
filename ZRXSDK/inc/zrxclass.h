
#pragma once

#include "zrxobject.h"
#include "ZdZChar.h"
#pragma pack (push, 8)

class __declspec(novtable) ZcRxClass: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxClass);

    virtual ZcRxObject* addX(ZcRxClass*, ZcRxObject*) = 0;
    virtual ZcRxObject* getX(const ZcRxClass*) = 0;
    virtual ZcRxObject* delX(ZcRxClass*) = 0;
    virtual ZcRxObject* queryX(const ZcRxClass*) = 0;

    virtual ZcRxObject* create() = 0;
    virtual const ZCHAR* appName() const = 0;
    virtual const ZCHAR* dxfName() const = 0;
    virtual const ZCHAR* name() const = 0;
    virtual void        getClassVersion(int& dwgVer,
                            int& maintVer) const = 0;
    virtual int         proxyFlags() const = 0;

    virtual bool isDerivedFrom(const ZcRxClass*) const = 0;
    virtual ZcRxClass*     myParent() const = 0;
    virtual ZcRx::Ordering comparedTo(const ZcRxObject*) const = 0;

    virtual AppNameChangeFuncPtr appNameCallbackPtr() const = 0;
};

ZcRxClass* newZcRxClass(
    const ZCHAR* className,
    const ZCHAR* parentClassName,
    int         proxyFlags = 0,
    ZcRxObject* (*pseudoConstructor)() = NULL,
    const ZCHAR* dxfName = NULL,
    const ZCHAR* appName = NULL, 
	void (*pseudoDestructor)(void*) = NULL);

ZcRxClass* newZcRxClass(
    const ZCHAR* className,
    const ZCHAR* parentClassName,
    int         dwgVer,
    int         maintVer,
    int         proxyFlags = 0,
    ZcRxObject* (*pseudoConstructor)() = NULL,
    const ZCHAR* dxfName = NULL,
    const ZCHAR* appName = NULL,
    AppNameChangeFuncPtr func = NULL, 
	void (*pseudoDestructor)(void*) = NULL);


void zcrxBuildClassHierarchy();


void deleteZcRxClass(ZcRxClass* pClassObj);

inline bool ZcRxObject::isKindOf(const ZcRxClass* pOtherClass) const
{
    const ZcRxClass * pMyClass = this->isA();
    return pMyClass == NULL ? false : pMyClass->isDerivedFrom(pOtherClass);

}

#pragma pack (pop)

