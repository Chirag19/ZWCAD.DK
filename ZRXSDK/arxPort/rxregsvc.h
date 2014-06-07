#ifndef _ARXPORT_AD_RXREGSVC_H_
#define _ARXPORT_AD_RXREGSVC_H_ 1


#include "rxdlinkr.h"
#include "adesk.h"
#include "..\inc\zrxregsvc.h"

#define acrxLoadModule				zcrxLoadModule
#define acrxLoadApp					zcrxLoadApp
#define acrxUnloadModule			zcrxUnloadModule
#define acrxUnloadApp				zcrxUnloadApp
#define acrxLoadedApps				zcrxLoadedApps
#define acrxAppIsLoaded				zcrxAppIsLoaded
#define acrxProductKey				zcrxProductKey
#define acrxObjectDBXRegistryKey	zcrxObjectDBXRegistryKey
#define acrxProductLCID				zcrxProductLCID
#define acrxRegisterApp				zcrxRegisterApp
#define acrxUnregisterApp			zcrxUnregisterApp
#define acrxGetServiceSymbolAddr	zcrxGetServiceSymbolAddr
#define acrxRegisterService			zcrxRegisterService
#define acrxServiceIsRegistered		zcrxServiceIsRegistered
#define acrxUnlockApplication		zcrxUnlockApplication
#define acrxApplicationIsLocked		zcrxApplicationIsLocked
#define acrxLockApplication			zcrxLockApplication
#define acrxIsAppMDIAware			zcrxIsAppMDIAware
#define acrxRegisterAppMDIAware		zcrxRegisterAppMDIAware
#define acrxRegisterAppNotMDIAware	zcrxRegisterAppNotMDIAware

#endif