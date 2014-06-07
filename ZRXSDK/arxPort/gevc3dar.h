
#ifndef _ARXPORT_AC_GEVC3DAR_H_
#define _ARXPORT_AC_GEVC3DAR_H_ 1

#include "adesk.h"
#include "assert.h"
#include "gevec3d.h"

#include "acarray.h"
#include "..\inc\zgevc3dar.h"

typedef ZcGeVector3dArray AcGeVector3dArray;

#if GE_LOCATED_NEW
#define AcGeGetMetaTypeIndex  ZcGeGetMetaTypeIndex
#endif

#endif
