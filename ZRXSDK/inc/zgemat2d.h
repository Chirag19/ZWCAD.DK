#ifndef ZC_GEMAT2D_H
#define ZC_GEMAT2D_H


#include "zgegbl.h"
#include "zgepnt2d.h"
#pragma pack (push, 8)

class ZcGeVector2d;
class ZcGeLine2d;
class ZcGeTol;

class 
GE_DLLEXPIMPORT
ZcGeMatrix2d
{
public:
    ZcGeMatrix2d();
    ZcGeMatrix2d(const ZcGeMatrix2d& src);

  
    static const   ZcGeMatrix2d   kIdentity;

  
    ZcGeMatrix2d&  setToIdentity();

 
    ZcGeMatrix2d   operator *   (const ZcGeMatrix2d& mat) const;
    ZcGeMatrix2d&  operator *=  (const ZcGeMatrix2d& mat);
    ZcGeMatrix2d&  preMultBy    (const ZcGeMatrix2d& leftSide);
    ZcGeMatrix2d&  postMultBy   (const ZcGeMatrix2d& rightSide);
    ZcGeMatrix2d&  setToProduct (const ZcGeMatrix2d& mat1, const ZcGeMatrix2d& mat2);


    ZcGeMatrix2d&  invert       ();
    ZcGeMatrix2d   inverse      () const;

   
	Zdesk::Boolean isSingular   (const ZcGeTol& tol = ZcGeContext::gTol) const;


    ZcGeMatrix2d&  transposeIt  ();
    ZcGeMatrix2d   transpose    () const;

   
    bool operator ==  (const ZcGeMatrix2d& mat) const;
    bool operator !=  (const ZcGeMatrix2d& mat) const;
    bool isEqualTo    (const ZcGeMatrix2d& mat,
                       const ZcGeTol& tol = ZcGeContext::gTol) const;

 
    Zdesk::Boolean isUniScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
    Zdesk::Boolean isScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
	double		   scale(void);

   
    double         det          () const;

   
    ZcGeMatrix2d&  setTranslation(const ZcGeVector2d& vec);
    ZcGeVector2d   translation  () const;

   
    Zdesk::Boolean isConformal (double& scale, double& angle,
                                Zdesk::Boolean& isMirror, ZcGeVector2d& reflex) const;


  
    ZcGeMatrix2d&  setCoordSystem(const ZcGePoint2d& origin,
                                 const ZcGeVector2d& e0,
                                 const ZcGeVector2d& e1);
    void           getCoordSystem(ZcGePoint2d& origin,
                                 ZcGeVector2d& e0,
                                 ZcGeVector2d& e1) const;

 
    ZcGeMatrix2d& setToTranslation(const ZcGeVector2d& vec);
    ZcGeMatrix2d& setToRotation (double angle,
                                 const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    ZcGeMatrix2d& setToScaling  (double scaleAll,
                                 const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    ZcGeMatrix2d& setToMirroring(const ZcGePoint2d& pnt);
    ZcGeMatrix2d& setToMirroring(const ZcGeLine2d& line);
    ZcGeMatrix2d& setToAlignCoordSys(const ZcGePoint2d&  fromOrigin,
                                 const ZcGeVector2d& fromE0,
                                 const ZcGeVector2d& fromE1,
                                 const ZcGePoint2d&  toOrigin,
                                 const ZcGeVector2d& toE0,
                                 const ZcGeVector2d& toE1);

   
    static
    ZcGeMatrix2d translation    (const ZcGeVector2d& vec);
    static
    ZcGeMatrix2d rotation       (double angle, const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    static
    ZcGeMatrix2d scaling        (double scaleAll, const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    static
    ZcGeMatrix2d mirroring      (const ZcGePoint2d& pnt);
    static
    ZcGeMatrix2d mirroring      (const ZcGeLine2d& line);
    static
    ZcGeMatrix2d alignCoordSys  (const ZcGePoint2d& fromOrigin,
                                 const ZcGeVector2d& fromE0,
                                 const ZcGeVector2d& fromE1,
                                 const ZcGePoint2d&  toOrigin,
                                 const ZcGeVector2d& toE0,
                                 const ZcGeVector2d& toE1);

    
    double         operator ()  (unsigned int, unsigned int) const;
    double&        operator ()  (unsigned int, unsigned int);

	const double*  operator[] (int row) const { return entry[row]; }
	double*		   operator[] (int row)		  { return entry[row]; }

    
    double         entry[3][3]; 
};


#pragma pack (pop)
#endif
