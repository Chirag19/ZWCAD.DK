#ifndef ZC_GEGBL_H
#define ZC_GEGBL_H

#include <stdlib.h>
#include "zgedll.h"
#include "zdesk.h"
#include "zgetol.h"

#include "zgegblge.h"
#pragma pack (push, 8)

class ZcGeVector3d;

struct
GE_DLLEXPIMPORT
ZcGeContext
{
    static ZcGeTol      gTol;

    static void (*gErrorFunc)();

#ifndef ZGELIB2D
    static void (*gOrthoVector)(const ZcGeVector3d&,ZcGeVector3d&);
#endif

#ifndef zunix
    static void* (*gAllocMem)(size_t);
#ifdef MEM_DEBUG
    static void* (*gAllocMemLeak)(size_t, const char *, int);
#endif
    static void  (*gFreeMem)(void*);
#endif
#ifdef GE_LOCATED_NEW
    static void* (*gAllocMemNear) (size_t, ZcGe::metaTypeIndex, const void* );
    static void* (*gAllocMemNearVector) (size_t, ZcGe::metaTypeIndex, unsigned int, const void* );
    static void (*gSetExternalStore) (const void* );
#endif
#ifndef NDEBUG
    static void (*gAssertFunc)(const ZCHAR *condition, const ZCHAR *filename,
                                    int lineNumber, const ZCHAR *status);
#endif
};


#pragma pack (pop)
#endif // ZC_GEGBL_H
