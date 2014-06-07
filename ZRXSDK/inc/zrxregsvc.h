#ifndef   _ZRXREGSVC_H
#define   _ZRXREGSVC_H 1

#include "zrxdlinkr.h"
#include "zdesk.h"
#pragma pack (push, 8)


bool zcrxLoadModule(const ZCHAR * moduleName, bool printit, bool asCmd=false);


bool zcrxLoadApp(const ZCHAR * appname, bool asCmd=false);


bool zcrxUnloadModule(const ZCHAR * moduleName, bool asCmd=false);


bool zcrxUnloadApp(const ZCHAR * appName, bool asCmd=false);


void *zcrxLoadedApps();


bool /*ZDESK_STDCALL*/ zcrxAppIsLoaded(const ZCHAR  *pAppName);


const ZCHAR * zcrxProductKey();


const ZCHAR * zcrxObjectDBXRegistryKey();


unsigned long zcrxProductLCID();


ZcadApp::ErrorStatus zcrxRegisterApp(ZcadApp::LoadReasons alr,
        const ZCHAR  *logicalName, bool bDwgU = false);


ZcadApp::ErrorStatus zcrxUnregisterApp(const ZCHAR  *logicalname, 
                                       bool bDwgU = false);


void * zcrxGetServiceSymbolAddr(const ZCHAR * serviceName, const ZCHAR * symbol);


void* zcrxRegisterService(const ZCHAR * serviceName);


bool zcrxServiceIsRegistered(const ZCHAR * serviceName);



bool zcrxUnlockApplication(void* appId);


bool zcrxApplicationIsLocked(const ZCHAR * modulename);


bool zcrxLockApplication(void* appId);


bool zcrxIsAppMDIAware(const ZCHAR  * moduleName);


bool zcrxRegisterAppMDIAware(void* appId);


bool zcrxRegisterAppNotMDIAware(void* appId);


#pragma pack (pop)
#endif
