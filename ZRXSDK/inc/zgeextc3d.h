#ifndef ZC_GEEXTC3D_H
#define ZC_GEEXTC3D_H

#include "zgecurv3d.h"
#include "zgearc3d.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#pragma pack (push, 8)

class ZcGeLine3d;
class ZcGeLineSeg3d;
class ZcGeRay3d;
class ZcGeEllipArc3d;
class ZcGeNurbCurve3d;
class ZcGeExternalCurve2d;
class ZcGeExternalCurve3d;

class
GX_DLLEXPIMPORT
ZcGeExternalCurve3d : public ZcGeCurve3d
{
public:
    ZcGeExternalCurve3d();
    ZcGeExternalCurve3d(const ZcGeExternalCurve3d& src);
    ZcGeExternalCurve3d(void* curveDef, ZcGe::ExternalEntityKind curveKind,
                            Zdesk::Boolean makeCopy = Zdesk::kTrue);

    Zdesk::Boolean isLine     () const;
    Zdesk::Boolean isRay      () const;
    Zdesk::Boolean isLineSeg  () const;
    Zdesk::Boolean isCircArc  () const;
    Zdesk::Boolean isEllipArc () const;
    Zdesk::Boolean isNurbCurve() const;
    Zdesk::Boolean isDefined  () const;

    Zdesk::Boolean isNativeCurve  (ZcGeCurve3d*& nativeCurve) const;
    void           getExternalCurve (void*& curveDef) const;

    ZcGe::ExternalEntityKind externalCurveKind() const;

    ZcGeExternalCurve3d& set(void* curveDef, ZcGe::ExternalEntityKind curveKind,
                             Zdesk::Boolean makeCopy = Zdesk::kTrue);
    ZcGeExternalCurve3d& operator = (const ZcGeExternalCurve3d& src);

    Zdesk::Boolean       isOwnerOfCurve   () const;
    ZcGeExternalCurve3d& setToOwnCurve    ();
};

#pragma pack (pop)
#endif
