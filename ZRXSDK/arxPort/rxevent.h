
#ifndef _ARXPORT_AD_RXEVENT_H_
#define _ARXPORT_AD_RXEVENT_H_ 1

#include "acarray.h"
#include "rxobject.h"
#include "AdAChar.h"

class ZcDbDatabase;
class ZcGeMatrix3d;
class ZcDbIdMapping;
class ZcGePoint3d;
class ZcDbObjectId;
class ZcRxImpEventReactor;


typedef ZcDbDatabase  AcDbDatabase;
typedef ZcGeMatrix3d  AcGeMatrix3d;
typedef ZcDbIdMapping AcDbIdMapping;
typedef ZcGePoint3d   AcGePoint3d;
typedef ZcDbObjectId  AcDbObjectId;
typedef ZcRxImpEventReactor  AcRxImpEventReactor;


#include "..\inc\zrxevent.h"

#define AcXrefSubCommand	ZcXrefSubCommand
#define acrxEvent			zcrxEvent

typedef ZcRxEventReactor	AcRxEventReactor;
typedef ZcRxEvent			AcRxEvent;

#endif
