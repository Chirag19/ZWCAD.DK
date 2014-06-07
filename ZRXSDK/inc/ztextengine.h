#ifndef _ZTEXTENGINE_H
#define _ZTEXTENGINE_H 1


#include "zcgi.h"
#include "ZdZChar.h"
#include "Zdesk.h"

#pragma pack (push, 8)

typedef void (*PolylineCallback) (int, int const *, ZcGePoint3d const *, void *);
typedef void (*UnicodeCallback) (Zdesk::LongPtr, wchar_t const *, int, void *);

class ZcGiTextEngine {

public:
    static   ZcGiTextEngine * create();
    virtual ~ZcGiTextEngine();


    virtual void getExtents (ZcGiTextStyle &    ts, 
                             ZCHAR const *      pStr,
                             int                nLength,
                             bool               bPenUp,
                             bool               bRaw,
                             ZcGePoint2d &      extents) = 0;


    virtual void tessellate (ZcGiTextStyle &    ts,
                             ZCHAR const *      pStr,
                             int                nLength,
                             bool               bRaw,
                             double             deviation,
                             void *             pVoid,
                             PolylineCallback   pPolylineCallback) = 0;


    virtual void tessellate (ZcGiTextStyle &    ts,
                             ZCHAR const *      pString,
                             int                nLength,
                             bool               bRaw,
                             void *             pVoid,
                             UnicodeCallback    pUnicodeCallback,
                             PolylineCallback   pPolylineCallback) = 0;


};

#pragma pack (pop)
#endif
