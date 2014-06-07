
#ifndef _ARXPORT_AC_GEPT3DAR_H_
#define _ARXPORT_AC_GEPT3DAR_H_ 1

#include "adesk.h"
#include "assert.h"
#include "gepnt3d.h"

#include "acarray.h"
#include "..\inc\zgept3dar.h"

typedef ZcGePoint3dArray AcGePoint3dArray;

#if GE_LOCATED_NEW
#define AcGeGetMetaTypeIndex ZcGeGetMetaTypeIndex
#endif

#endif
