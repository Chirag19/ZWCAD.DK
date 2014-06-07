#ifndef _ARXPORT_AD_MGDHOST_H_
#define _ARXPORT_AD_MGDHOST_H_ 1

#include "AdAChar.h"
#include "..\inc\zmgdhost.h"

typedef ZcDbManagedHost		AcDbManagedHost;

#define acdbGetManagedHost			zcdbGetManagedHost
#define acdbSetManagedHost			zcdbSetManagedHost
#define acdbInitializeManagedLayer	zcdbInitializeManagedLayer
#define acdbTerminateManagedLayer	zcdbTerminateManagedLayer

#endif
