#ifndef ZC_GEVEC3D_H
#define ZC_GEVEC3D_H

#include "Zdesk.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;
class ZcGeVector2d;
class ZcGePlane;
class ZcGePlanarEnt;

class 
GE_DLLEXPIMPORT
ZcGeVector3d
{
public:
    ZcGeVector3d();
    ZcGeVector3d(const ZcGeVector3d& vec);
    ZcGeVector3d(double x, double y, double z);
    ZcGeVector3d(const ZcGePlanarEnt&, const ZcGeVector2d&);

    static const   ZcGeVector3d kIdentity;
    static const   ZcGeVector3d kXAxis;
    static const   ZcGeVector3d kYAxis;
    static const   ZcGeVector3d kZAxis;

    friend
GE_DLLEXPIMPORT
    ZcGeVector3d   operator *  (const ZcGeMatrix3d& mat, const ZcGeVector3d& vec);
    ZcGeVector3d&  setToProduct(const ZcGeMatrix3d& mat, const ZcGeVector3d& vec);

    ZcGeVector3d&  transformBy (const ZcGeMatrix3d& leftSide);
    ZcGeVector3d&  rotateBy    (double ang , const ZcGeVector3d& axis );
    ZcGeVector3d&  mirror      (const ZcGeVector3d& normalToPlane);
    ZcGeVector2d   convert2d   (const ZcGePlanarEnt& pln) const;

    ZcGeVector3d   operator *  (double scl) const;
    friend
GE_DLLEXPIMPORT
    ZcGeVector3d   operator *  (double scl, const ZcGeVector3d& vec);
    ZcGeVector3d&  operator *= (double scl);
    ZcGeVector3d&  setToProduct(const ZcGeVector3d& vec, double scl);
    ZcGeVector3d   operator /  (double scl) const;
    ZcGeVector3d&  operator /= (double scl);

    ZcGeVector3d   operator +  (const ZcGeVector3d& vec) const;
    ZcGeVector3d&  operator += (const ZcGeVector3d& vec);
    ZcGeVector3d   operator -  (const ZcGeVector3d& vec) const;
    ZcGeVector3d&  operator -= (const ZcGeVector3d& vec);
    ZcGeVector3d&  setToSum    (const ZcGeVector3d& vec1, const ZcGeVector3d& vec2);
    ZcGeVector3d   operator -  () const;
    ZcGeVector3d&  negate      ();

    ZcGeVector3d   perpVector  () const;

    double         angleTo     (const ZcGeVector3d& vec) const;
    double         angleTo     (const ZcGeVector3d& vec,
                                const ZcGeVector3d& refVec) const;
    double         angleOnPlane(const ZcGePlanarEnt& pln) const;

    ZcGeVector3d   normal      (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGeVector3d&  normalize   (const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeVector3d&  normalize   (const ZcGeTol& tol, ZcGeError& flag);
    double         length      () const;
    double         lengthSqrd  () const;
    Zdesk::Boolean isUnitLength(const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isZeroLength(const ZcGeTol& tol = ZcGeContext::gTol) const;

    Zdesk::Boolean isParallelTo(const ZcGeVector3d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isParallelTo(const ZcGeVector3d& vec,
                                const ZcGeTol& tol, ZcGeError& flag) const;
    Zdesk::Boolean isCodirectionalTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isCodirectionalTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol, ZcGeError& flag) const;
    Zdesk::Boolean isPerpendicularTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isPerpendicularTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol, ZcGeError& flag) const;

    double         dotProduct  (const ZcGeVector3d& vec) const;
    ZcGeVector3d   crossProduct(const ZcGeVector3d& vec) const;

    ZcGeMatrix3d   rotateTo    (const ZcGeVector3d& vec, const ZcGeVector3d& axis
                                = ZcGeVector3d::kIdentity) const;

    ZcGeVector3d   project      (const ZcGeVector3d& planeNormal,
                                 const ZcGeVector3d& projectDirection) const;
    ZcGeVector3d   project      (const ZcGeVector3d& planeNormal,
                                 const ZcGeVector3d& projectDirection,  
                                 const ZcGeTol& tol, ZcGeError& flag) const;
    ZcGeVector3d   orthoProject (const ZcGeVector3d& planeNormal) const;
    ZcGeVector3d   orthoProject (const ZcGeVector3d& planeNormal, 
                                 const ZcGeTol& tol, ZcGeError& flag) const;
    bool operator == (const ZcGeVector3d& vec) const;
    bool operator != (const ZcGeVector3d& vec) const;
    bool isEqualTo   (const ZcGeVector3d& vec,
                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int i);
    unsigned int   largestElement() const;
    ZcGeVector3d&  set         (double x, double y, double z);
    ZcGeVector3d&  set         (const ZcGePlanarEnt& pln, const ZcGeVector2d& vec);

    operator       ZcGeMatrix3d() const;

    double         x, y, z;
};


#pragma pack (pop)
#endif
