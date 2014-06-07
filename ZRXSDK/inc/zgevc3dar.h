#ifndef ZC_GEVC3DAR_H
#define ZC_GEVC3DAR_H

#include "Zdesk.h"
#include "assert.h"
#include "zgevec3d.h"

#include "zcarray.h"
typedef ZcArray<ZcGeVector3d> ZcGeVector3dArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
ZcGe::metaTypeIndex ZcGeGetMetaTypeIndex(ZcGeVector3dArray* pT);
#endif

#endif
