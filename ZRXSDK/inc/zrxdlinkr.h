

#ifndef _zrxdlinkr_h
#define _zrxdlinkr_h 1

class ZcRxDLinkerReactor;
class ZcRxService;

#include "zrxobject.h"
#include "ZdZChar.h"
#pragma pack (push, 8)

struct ZcadApp
{
    enum LoadReasons {
        kOnProxyDetection       = 0x01,
        kOnAutoCADStartup       = 0x02,
        kOnCommandInvocation    = 0x04,
        kOnLoadRequest          = 0x08,
        kLoadDisabled           = 0x10,
        kTransparentlyLoadable  = 0x20,
        kOnIdleLoad             = 0x40
    };

    enum ErrorStatus {
        eOk             = 0,
        eInvalidKey     = 1,
        eInvalidSubKey  = 2,
        eKeyNotFound    = 3,
        eOutOfMemory    = 4,
        eInvalidValue   = 5,
        eValueNotFound  = 6,
        eKeyExists      = 7,
        eRegAccessDenied= 8,
        eRejected       = 9,
        eUnknownError   = 10
    };
};





class ZDESK_NO_VTABLE ZcRxDynamicLinker: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxDynamicLinker);

    virtual void*          getSymbolAddress (const ZCHAR * serviceName,
                                             const char * symbol) const = 0;
#ifdef AD_UNICODE
  
    virtual void*          getSymbolAddress (const ZCHAR * serviceName,
                                             const ZCHAR * symbol) const = 0;
#endif

    virtual bool           initListedModules(const ZCHAR * fileName) = 0;

    virtual bool           loadModule       (const ZCHAR * fileName, 
                                             bool printit,
                                             bool asCmd=false) = 0;
    virtual bool           loadApp          (const ZCHAR  * appName,
                                             ZcadApp::LoadReasons al,
                                             bool printit,
                                             bool asCmd=false) = 0;

    virtual ZcRxObject*    registerService  (const ZCHAR * serviceName,
                                             ZcRxService* serviceObj) = 0;

    virtual bool           unloadModule     (const ZCHAR * fileName,
                                            bool asCmd=false) = 0;
    virtual bool           unloadApp        (const ZCHAR * appName,
                                            bool asCmd=false) = 0;

    virtual void           addReactor       (ZcRxDLinkerReactor* newReactor) =0;

    virtual void           removeReactor    (ZcRxDLinkerReactor* oldReactor) =0;

    virtual bool           isApplicationLocked(const ZCHAR * modulename) const =0;
    virtual bool           lockApplication  (void* appId) const = 0;
    virtual bool           unlockApplication(void* appId) const = 0;

    virtual bool           isAppMDIAware(const ZCHAR * modulename) const =0;
    virtual bool           registerAppMDIAware(void* appId) const =0;
    virtual bool           registerAppNotMDIAware(void* appId) const =0;
 
    virtual bool           isAppBusy(const ZCHAR * modulename) const =0;
    virtual void           setAppBusy(const ZCHAR * modulename, bool bBusyFlag) const =0;

    virtual const ZCHAR    *ProductKey      () const = 0;
    virtual Zdesk::UInt32  ProductLcid() const =0;

};



#define zcrxDynamicLinker                                               \
ZcRxDynamicLinker::cast(zcrxSysRegistry()->at(ZCRX_DYNAMIC_LINKER))

class ZDESK_NO_VTABLE ZcRxDLinkerReactor: public ZcRxObject

{
  public:
    ZCRX_DECLARE_MEMBERS(ZcRxDLinkerReactor);

    virtual void zrxAppWillBeLoaded(const ZCHAR  * moduleName);
    virtual void zrxAppLoaded(const ZCHAR  * moduleName);
    virtual void zrxAppLoadAborted(const ZCHAR  * moduleName);

    virtual void zrxAppWillBeUnloaded(const ZCHAR  * moduleName);
    virtual void zrxAppUnloaded(const ZCHAR  * moduleName);
    virtual void zrxAppUnloadAborted(const ZCHAR  * moduleName);
};


#pragma pack (pop)
#endif
