#ifndef ZC_GEINTARR_H
#define ZC_GEINTARR_H

#ifndef unix
#include <stdlib.h>
#endif
#include "Zdesk.h"
#include "assert.h"

#include "zcarray.h"
typedef ZcArray<int> ZcGeIntArray;
typedef ZcArray<Zdesk::IntPtr> ZcGeIntPtrArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
ZcGe::metaTypeIndex ZcGeGetMetaTypeIndex(ZcGeIntArray* pT);
#endif
#endif
