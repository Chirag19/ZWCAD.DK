
#ifndef _ARXPORT_AD_RXCLASS_H_
#define _ARXPORT_AD_RXCLASS_H_ 1

#include "rxobject.h"
#include "AdAChar.h"
#include "..\inc\zrxclass.h"

typedef ZcRxClass				AcRxClass;

#define newAcRxClass			newZcRxClass
#define deleteAcRxClass			deleteZcRxClass
#define acrxBuildClassHierarchy	zcrxBuildClassHierarchy

#endif