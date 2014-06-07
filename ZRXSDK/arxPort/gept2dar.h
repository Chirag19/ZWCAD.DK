
#ifndef _ARXPORT_AC_GEPT2DAR_H_
#define _ARXPORT_AC_GEPT2DAR_H_ 1

#include "adesk.h"
#include "assert.h"
#include "gepnt2d.h"

#include "acarray.h"
#include "..\inc\zgept2dar.h"

typedef ZcGePoint2dArray AcGePoint2dArray;

#if GE_LOCATED_NEW
#define AcGeGetMetaTypeIndex ZcGeGetMetaTypeIndex
#endif

#endif
