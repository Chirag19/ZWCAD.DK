#ifndef ZC_GEVEC2D_H
#define ZC_GEVEC2D_H

#include "Zdesk.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;

class 
GE_DLLEXPIMPORT
ZcGeVector2d
{
public:
    ZcGeVector2d();
    ZcGeVector2d(const ZcGeVector2d& vec);
    ZcGeVector2d(double x, double y);

    static const   ZcGeVector2d kIdentity;
    static const   ZcGeVector2d kXAxis;
    static const   ZcGeVector2d kYAxis;

    friend
GE_DLLEXPIMPORT
    ZcGeVector2d   operator *  (const ZcGeMatrix2d& mat, const ZcGeVector2d& vec);
    ZcGeVector2d&  setToProduct(const ZcGeMatrix2d& mat, const ZcGeVector2d& vec);
    ZcGeVector2d&  transformBy (const ZcGeMatrix2d& leftSide);
    ZcGeVector2d&  rotateBy    (double angle);
    ZcGeVector2d&  mirror      (const ZcGeVector2d& line );


    ZcGeVector2d   operator *  (double scl) const;
    friend
 GE_DLLEXPIMPORT
    ZcGeVector2d   operator *  (double scl, const ZcGeVector2d& vec);
    ZcGeVector2d&  operator *= (double scl);
    ZcGeVector2d&  setToProduct(const ZcGeVector2d& vec, double scl);
    ZcGeVector2d   operator /  (double scl) const;
    ZcGeVector2d&  operator /= (double scl);

    ZcGeVector2d   operator +  (const ZcGeVector2d& vec) const;
    ZcGeVector2d&  operator += (const ZcGeVector2d& vec);
    ZcGeVector2d   operator -  (const ZcGeVector2d& vec) const;
    ZcGeVector2d&  operator -= (const ZcGeVector2d& vec);
    ZcGeVector2d&  setToSum    (const ZcGeVector2d& vec1, const ZcGeVector2d& vec2);
    ZcGeVector2d   operator -  () const;
    ZcGeVector2d&  negate      ();

    // Perpendicular vector
    //
    ZcGeVector2d   perpVector  () const;

    double         angle       () const;
    double         angleTo     (const ZcGeVector2d& vec) const;

    ZcGeVector2d   normal      (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGeVector2d&  normalize   (const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeVector2d&  normalize   (const ZcGeTol& tol, ZcGeError& flag);
    double         length      () const;
    double         lengthSqrd  () const;
    Zdesk::Boolean isUnitLength(const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isZeroLength(const ZcGeTol& tol = ZcGeContext::gTol) const;

    Zdesk::Boolean isParallelTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isParallelTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol, ZcGeError& flag) const;
    Zdesk::Boolean isCodirectionalTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isCodirectionalTo(const ZcGeVector2d& vec,
                        const ZcGeTol& tol, ZcGeError& flag) const;
    Zdesk::Boolean isPerpendicularTo(const ZcGeVector2d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isPerpendicularTo(const ZcGeVector2d& vec,
                        const ZcGeTol& tol, ZcGeError& flag) const;
    double         dotProduct  (const ZcGeVector2d& vec) const;

    bool operator == (const ZcGeVector2d& vec) const;
    bool operator != (const ZcGeVector2d& vec) const;
    bool isEqualTo   (const ZcGeVector2d& vec,
                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int i) ;
    ZcGeVector2d&  set         (double x, double y);

    operator       ZcGeMatrix2d() const;

    double         x, y;
};


#pragma pack (pop)
#endif
