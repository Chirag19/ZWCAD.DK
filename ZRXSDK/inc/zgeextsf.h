#ifndef ZC_GEEXTSF_H
#define ZC_GEEXTSF_H

#include "zgegbl.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGePlane;
class ZcGeCylinder;
class ZcGeCone;
class ZcGeSphere;
class ZcGeTorus;
class ZcGeNurbSurface;
class Zsurface;

class
GX_DLLEXPIMPORT
ZcGeExternalSurface : public ZcGeSurface
{
public:
   ZcGeExternalSurface();
   ZcGeExternalSurface(void* surfaceDef, ZcGe::ExternalEntityKind surfaceKind,
                       Zdesk::Boolean makeCopy = Zdesk::kTrue);
   ZcGeExternalSurface(const ZcGeExternalSurface&);

   void getExternalSurface(void*& surfaceDef) const;

   ZcGe::ExternalEntityKind  externalSurfaceKind() const;

   Zdesk::Boolean    isPlane      () const;
   Zdesk::Boolean    isSphere     () const;
   Zdesk::Boolean    isCylinder   () const;
   Zdesk::Boolean    isCone       () const;
   Zdesk::Boolean    isTorus      () const;
   Zdesk::Boolean    isNurbSurface() const;
   Zdesk::Boolean    isDefined    () const;

   Zdesk::Boolean isNativeSurface(ZcGeSurface*& nativeSurface) const;

   ZcGeExternalSurface& operator = (const ZcGeExternalSurface& src);

   ZcGeExternalSurface& set(void* surfaceDef,
                            ZcGe::ExternalEntityKind surfaceKind,
                            Zdesk::Boolean makeCopy = Zdesk::kTrue);
   Zdesk::Boolean       isOwnerOfSurface    () const;
   ZcGeExternalSurface& setToOwnSurface     ();
};

#pragma pack (pop)
#endif
