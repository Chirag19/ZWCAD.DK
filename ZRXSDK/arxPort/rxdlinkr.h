
#ifndef _ARXPORT_RXDLINKR_H_
#define _ARXPORT_RXDLINKR_H_ 1

#include "rxobject.h"

class ZcRxDLinkerReactor;
class ZcRxService;

typedef ZcRxDLinkerReactor		AcRxDLinkerReactor;
typedef ZcRxService				AcRxService;

#include "..\inc\zrxdlinkr.h"

typedef ZcadApp				AcadApp;
typedef ZcRxDynamicLinker	AcRxDynamicLinker;
typedef ZcRxDLinkerReactor	AcRxDLinkerReactor;

#define acrxDynamicLinker	zcrxDynamicLinker
#define rxAppWillBeLoaded   zrxAppWillBeLoaded
#define rxAppLoaded         zrxAppLoaded
#define rxAppLoadAborted    zrxAppLoadAborted
#define rxAppWillBeUnloaded zrxAppWillBeUnloaded
#define rxAppUnloaded       zrxAppUnloaded
#define rxAppUnloadAborted  zrxAppUnloadAborted

#endif
