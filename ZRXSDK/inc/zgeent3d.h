#ifndef ZC_GEENT3D_H
#define ZC_GEENT3D_H

#include "zgegbl.h"
#include "zgepnt3d.h"
#include "zgeintrvl.h"
#include "zgegblnew.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeEntity3d
{
public:
    virtual ~ZcGeEntity3d();

    Zdesk::Boolean   isKindOf    (ZcGe::EntityId entType) const;
    ZcGe::EntityId   type        () const;

    ZcGeEntity3d*    copy        () const;
    ZcGeEntity3d&    operator =  (const ZcGeEntity3d& entity);

    Zdesk::Boolean   operator == (const ZcGeEntity3d& entity) const;
    Zdesk::Boolean   operator != (const ZcGeEntity3d& entity) const;
    Zdesk::Boolean   isEqualTo   (const ZcGeEntity3d& ent,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGeEntity3d&    transformBy (const ZcGeMatrix3d& xfm);
    ZcGeEntity3d&    translateBy (const ZcGeVector3d& translateVec);
    ZcGeEntity3d&    rotateBy    (double angle, const ZcGeVector3d& vec,
                                  const ZcGePoint3d& wrtPoint = ZcGePoint3d::kOrigin);
    ZcGeEntity3d&    mirror      (const ZcGePlane& plane);
    ZcGeEntity3d&    scaleBy     (double scaleFactor,
                                  const ZcGePoint3d& wrtPoint
                                  = ZcGePoint3d::kOrigin);
    Zdesk::Boolean   isOn        (const ZcGePoint3d& pnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

public:
	friend class ZcGeImpEntity3d;
    ZcGeImpEntity3d*	mpImpEnt;
    int					mDelEnt;
    ZcGeEntity3d ();
    ZcGeEntity3d (const ZcGeEntity3d&);
    ZcGeEntity3d (ZcGeImpEntity3d&, int);
    ZcGeEntity3d (ZcGeImpEntity3d*);
    ZcGeEntity3d* newEntity3d (ZcGeImpEntity3d*) const;
    ZcGeEntity3d* newEntity3d (ZcGeImpEntity3d&, int) const;
};


#pragma pack (pop)
#endif
