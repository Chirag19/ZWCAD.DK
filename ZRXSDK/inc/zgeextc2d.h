#ifndef ZC_GEEXTC2D_H
#define ZC_GEEXTC2D_H

#include "zgecurv2d.h"
#include "zgearc2d.h"
#include "zgevec2d.h"
#include "zgepnt2d.h"
#pragma pack (push, 8)

class ZcGeNurbCurve2d;
class ZcGeExternalCurve2d;
class ZcGeExternalCurve2d;

class
GX_DLLEXPIMPORT
ZcGeExternalCurve2d : public ZcGeCurve2d
{
public:
    ZcGeExternalCurve2d();
    ZcGeExternalCurve2d(const ZcGeExternalCurve2d&);
    ZcGeExternalCurve2d(void* curveDef, ZcGe::ExternalEntityKind curveKind,
                        Zdesk::Boolean makeCopy = Zdesk::kTrue);

    Zdesk::Boolean isNurbCurve() const;
    Zdesk::Boolean isNurbCurve(ZcGeNurbCurve2d& nurbCurve) const;
    Zdesk::Boolean isDefined  () const;

    void           getExternalCurve(void*& curveDef) const;

    ZcGe::ExternalEntityKind externalCurveKind() const;

    ZcGeExternalCurve2d& set(void* curveDef, ZcGe::ExternalEntityKind curveKind,
                             Zdesk::Boolean makeCopy = Zdesk::kTrue);
    ZcGeExternalCurve2d& operator = (const ZcGeExternalCurve2d& src);

    Zdesk::Boolean       isOwnerOfCurve() const;
    ZcGeExternalCurve2d& setToOwnCurve();
};

#pragma pack (pop)
#endif
