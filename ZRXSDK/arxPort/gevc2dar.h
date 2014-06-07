
#ifndef _ARXPORT_AC_GEVC2DAR_H_
#define _ARXPORT_AC_GEVC2DAR_H_ 1

#include "adesk.h"
#include "assert.h"
#include "gevec2d.h"

#include "acarray.h"
#include "..\inc\zgevc2dar.h"

typedef ZcGeVector2dArray AcGeVector2dArray;

#if GE_LOCATED_NEW
#define AcGeGetMetaTypeIndex  ZcGeGetMetaTypeIndex
#endif

#endif
