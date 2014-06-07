#ifndef _ZCSYMUTL_H
#define _ZCSYMUTL_H

#include <assert.h>
#include "zcadstrc.h"
#include "zdbsymutl.h"
#pragma pack (push, 8)

#define ZCEDSYMUTIL_SERVICES_CURRENT_VERSION 100

class ZcDbDatabase;

namespace ZcEdSymbolUtilities
{

enum CrSpMode {
    kCrEndsInput = true
  , kCrSpEndsInput = false
};

enum NameCaseMode {
    kPreserveCase = true
  , kForceToUpper = false
};

class Services
{
public:
    enum { kCurrentVersion = ZCEDSYMUTIL_SERVICES_CURRENT_VERSION };
    virtual unsigned version() const = 0;

    virtual Zcad::PromptStatus getCompatibleSymbolString(
                                      ZCHAR*&        pResponse,
                                      const ZCHAR*   prompt,
                                      ZcDbDatabase * pDb) const = 0;

    virtual Zcad::PromptStatus getSymbolString(
                                      ZCHAR*&      pResponse,
                                      const ZCHAR* prompt,
                                      bool         onlyCrEndsInput,
                                      bool         preserveCase) const = 0;

};

#define ZCEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v) n ## v
#define ZCEDSYMUTIL_SERVICESNAME_WITH_VERSION(n,v) \
        ZCEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v)
#define ZCEDSYMUTIL_SERVICES_NAME \
        ZCEDSYMUTIL_SERVICESNAME_WITH_VERSION( \
            servicesPtr, \
            ZCEDSYMUTIL_SERVICES_CURRENT_VERSION)
extern const Services * ZCEDSYMUTIL_SERVICES_NAME();


inline const Services *
servicesPtr()
{
    const Services * pSymUtil = ZCEDSYMUTIL_SERVICES_NAME();
    assert(pSymUtil != 0);
//    assert(pSymUtil->version() == Services::kCurrentVersion); //Removed by Chinaweal WangTao 2009/12/21_1 for ZCEDSYMUTIL_SERVICES_NAME()为空实现，返回NULL导致Debug版死机。
    return pSymUtil;
}

} 

namespace ZcEdSymUtil = ZcEdSymbolUtilities;

typedef ZcEdSymbolUtilities::Services ZcEdSymUtilServices;

inline const ZcEdSymUtilServices *
zcedSymUtil()
{
    return ZcEdSymbolUtilities::servicesPtr();
}

#pragma pack (pop)
#endif // _ZCSYMUTL_H
