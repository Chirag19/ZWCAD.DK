#ifndef ZC_GEOFFSF_H
#define ZC_GEOFFSF_H

#include "zgegbl.h"
#include "zgepnt3d.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGePlane;
class ZcGeBoundedPlane;
class ZcGeCylinder;
class ZcGeCone;
class ZcGeSphere;
class ZcGeTorus;

class
GX_DLLEXPIMPORT
ZcGeOffsetSurface : public ZcGeSurface
{
public:
    ZcGeOffsetSurface();
    ZcGeOffsetSurface(ZcGeSurface* baseSurface,
                      double offsetDist,
                      Zdesk::Boolean makeCopy = Zdesk::kTrue);
    ZcGeOffsetSurface(const ZcGeOffsetSurface& offset);

    Zdesk::Boolean    isPlane        () const;
    Zdesk::Boolean    isBoundedPlane () const;
    Zdesk::Boolean    isSphere       () const;
    Zdesk::Boolean    isCylinder     () const;
    Zdesk::Boolean    isCone         () const;
    Zdesk::Boolean    isTorus        () const;

    Zdesk::Boolean    getSurface(ZcGeSurface*&) const;

    void              getConstructionSurface (ZcGeSurface*& base) const;

    double            offsetDist     () const;

    ZcGeOffsetSurface& set        (ZcGeSurface*, double offsetDist,
                                    Zdesk::Boolean makeCopy = Zdesk::kTrue);

    ZcGeOffsetSurface& operator =  (const ZcGeOffsetSurface& offset);
};

#pragma pack (pop)
#endif
