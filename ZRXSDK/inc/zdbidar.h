#ifndef ZC_DBIDAR_H
#define ZC_DBIDAR_H


#include "zdesk.h"
#include "assert.h"

#ifdef ZDESK_OBJID_INLINE_INTERNAL
#include "zdbidinln.h"
#else
#include "zdbidapps.h"
#endif
#include "zcarray.h"
typedef ZcArray<ZcDbObjectId> ZcDbObjectIdArray;
#endif
