#ifndef _ARXPORT_ACDBXREF_H_
#define _ARXPORT_ACDBXREF_H_ 1

#include "AdAChar.h"
#include "xgraph.h"
#include "..\inc\zcdbxref.h"

#define acdbReleaseHostDwg	zcdbReleaseHostDwg

#define acdbResolveCurrentXRefs		zcdbResolveCurrentXRefs
#define acdbAttachXref				zcdbAttachXref
#define acdbOverlayXref				zcdbOverlayXref
#define acdbDetachXref				zcdbDetachXref
#define acdbUnloadXrefs				zcdbUnloadXrefs
#define acdbReloadXrefs				zcdbReloadXrefs
#define acdbBindXrefs				zcdbBindXrefs
#define acdbXBindXrefs				zcdbXBindXrefs
#define acdbGetHostDwgXrefGraph		zcdbGetHostDwgXrefGraph
typedef ZcDbXrefObjectId	AcDbXrefObjectId;

#endif