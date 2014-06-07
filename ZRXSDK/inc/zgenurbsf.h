#ifndef ZC_GENURBSF_H
#define ZC_GENURBSF_H

#include "zgegbl.h"
#include "zgesurf.h"
#include "zgept3dar.h"
#include "zgedblar.h"
#pragma pack (push, 8)

class ZcGeKnotVector;

class
GX_DLLEXPIMPORT
ZcGeNurbSurface : public ZcGeSurface
{
public:
   ZcGeNurbSurface();
   ZcGeNurbSurface(int degreeU, int degreeV, int propsInU, int propsInV,
                   int numControlPointsInU, int numControlPointsInV,
                   const ZcGePoint3d controlPoints[],
                   const double weights[],
                   const ZcGeKnotVector& uKnots,
                   const ZcGeKnotVector& vKnots,
                   const ZcGeTol& tol = ZcGeContext::gTol);
   ZcGeNurbSurface(const ZcGeNurbSurface& nurb);

   ZcGeNurbSurface& operator = (const ZcGeNurbSurface& nurb);

   Zdesk::Boolean   isRationalInU      () const;
   Zdesk::Boolean   isPeriodicInU      (double&) const;
   Zdesk::Boolean   isRationalInV      () const;
   Zdesk::Boolean   isPeriodicInV      (double&) const;

   int singularityInU () const;
   int singularityInV () const;

   int            degreeInU            () const;
   int            numControlPointsInU  () const;
   int            degreeInV            () const;
   int            numControlPointsInV  () const;
   void           getControlPoints     (ZcGePoint3dArray& points) const;
   Zdesk::Boolean getWeights           (ZcGeDoubleArray& weights) const;

   int       numKnotsInU    () const;
   void      getUKnots      (ZcGeKnotVector& uKnots) const;

   int       numKnotsInV    () const;
   void      getVKnots      (ZcGeKnotVector& vKnots) const;

   void      getDefinition  (int& degreeU, int& degreeV,
                             int& propsInU,	int& propsInV,
                             int& numControlPointsInU,
                             int& numControlPointsInV,
                             ZcGePoint3dArray& controlPoints,
                             ZcGeDoubleArray& weights,
                             ZcGeKnotVector& uKnots,
                             ZcGeKnotVector& vKnots) const;

   ZcGeNurbSurface& set     (int degreeU, int degreeV,
                             int propsInU, int propsInV,
                             int numControlPointsInU,
                             int numControlPointsInV,
                             const ZcGePoint3d controlPoints[],
                             const double weights[],
                             const ZcGeKnotVector& uKnots,
                             const ZcGeKnotVector& vKnots,
                             const ZcGeTol& tol = ZcGeContext::gTol);

};

#pragma pack (pop)
#endif
