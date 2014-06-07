#ifndef ZC_GEXBNDSF_H
#define ZC_GEXBNDSF_H

#include "zgegbl.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGeExternalSurface;
class ZcGeCurveBoundary;

class
GX_DLLEXPIMPORT
ZcGeExternalBoundedSurface : public ZcGeSurface
{
public:
   ZcGeExternalBoundedSurface();
   ZcGeExternalBoundedSurface(void* surfaceDef, ZcGe::ExternalEntityKind surfaceKind,
                              Zdesk::Boolean makeCopy = Zdesk::kTrue);
   ZcGeExternalBoundedSurface(const ZcGeExternalBoundedSurface&);

   ZcGe::ExternalEntityKind   externalSurfaceKind  () const;
   Zdesk::Boolean             isDefined            () const;
   void                       getExternalSurface   (void*& surfaceDef) const;


    void getBaseSurface        (ZcGeSurface*& surfaceDef) const;

	void getBaseSurface        (ZcGeExternalSurface& unboundedSurfaceDef) const;

    Zdesk::Boolean isPlane() const;
    Zdesk::Boolean isSphere() const;
    Zdesk::Boolean isCylinder() const;
    Zdesk::Boolean isCone() const;
    Zdesk::Boolean isTorus() const;
    Zdesk::Boolean isNurbs() const;
    Zdesk::Boolean isExternalSurface() const;

    int          numContours  () const;
    void         getContours  (int& numContours, ZcGeCurveBoundary*& curveBoundaries) const;

    ZcGeExternalBoundedSurface& set  (void* surfaceDef,
                                      ZcGe::ExternalEntityKind surfaceKind,
                                      Zdesk::Boolean makeCopy = Zdesk::kTrue);

    ZcGeExternalBoundedSurface& operator = (const ZcGeExternalBoundedSurface&);

    Zdesk::Boolean               isOwnerOfSurface() const;
    ZcGeExternalBoundedSurface&  setToOwnSurface();
};

#pragma pack (pop)
#endif
