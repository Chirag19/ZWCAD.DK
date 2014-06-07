
#ifndef _ARXPORT_AC_GEINTARR_H_
#define _ARXPORT_AC_GEINTARR_H_ 1

#include "adesk.h"
#include "assert.h"

#include "acarray.h"
#include "..\inc\zgeintarr.h"

typedef ZcGeIntArray		AcGeIntArray;
typedef ZcGeIntPtrArray		AcGeIntPtrArray;

#if GE_LOCATED_NEW
#define AcGeGetMetaTypeIndex  ZcGeGetMetaTypeIndex;
#endif
#endif 
