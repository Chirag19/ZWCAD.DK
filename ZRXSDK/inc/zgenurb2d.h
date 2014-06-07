#ifndef ZC_GENURB2d_H
#define ZC_GENURB2d_H

#include "zgecurv2d.h"
#include "zgeintrvl.h"
#include "zgekvec.h"
#include "zgept2dar.h"
#include "zgevec2d.h"
#include "zgepnt2d.h"
#include "zgesent2d.h"
#include "zgeplin2d.h"
#include "zgedblar.h"
#include "zgept2dar.h"
#include "zgevc2dar.h"
#pragma pack (push, 8)

class ZcGeEllipArc2d;
class ZcGeLineSeg2d;

class 
GE_DLLEXPIMPORT
ZcGeNurbCurve2d : public ZcGeSplineEnt2d
{
public:
    ZcGeNurbCurve2d ();
    ZcGeNurbCurve2d (const ZcGeNurbCurve2d& src );
    ZcGeNurbCurve2d (int degree, const ZcGeKnotVector& knots,
                     const ZcGePoint2dArray& cntrlPnts, 
                     Zdesk::Boolean isPeriodic = Zdesk::kFalse );
    ZcGeNurbCurve2d (int degree, const ZcGeKnotVector& knots,
                     const ZcGePoint2dArray& cntrlPnts, 
                     const ZcGeDoubleArray&  weights,
                     Zdesk::Boolean isPeriodic = Zdesk::kFalse );

    ZcGeNurbCurve2d (int degree, const ZcGePolyline2d& fitPolyline,
                     Zdesk::Boolean isPeriodic = Zdesk::kFalse );
    ZcGeNurbCurve2d (const ZcGePoint2dArray& fitPoints, 
				     const ZcGeVector2d& startTangent, 
				     const ZcGeVector2d& endTangent,
				     Zdesk::Boolean startTangentDefined = Zdesk::kTrue,
					 Zdesk::Boolean endTangentDefined   = Zdesk::kTrue,
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol);
    ZcGeNurbCurve2d (const ZcGePoint2dArray& fitPoints, 
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol);
    ZcGeNurbCurve2d (const ZcGePoint2dArray& fitPoints, 
                     const ZcGeVector2dArray& fitTangents,
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol,
				     Zdesk::Boolean isPeriodic = Zdesk::kFalse);

	ZcGeNurbCurve2d (const ZcGeEllipArc2d&  ellipse);

	ZcGeNurbCurve2d (const ZcGeLineSeg2d& linSeg);

    int             numFitPoints      () const;
    Zdesk::Boolean  getFitPointAt     (int index, ZcGePoint2d& point) const;
    Zdesk::Boolean  getFitTolerance   (ZcGeTol& fitTolerance) const;
    Zdesk::Boolean  getFitTangents    (ZcGeVector2d& startTangent, 
				                       ZcGeVector2d& endTangent) const;
    Zdesk::Boolean  getFitData        (ZcGePoint2dArray& fitPoints,
		                               ZcGeTol& fitTolerance,
				                       Zdesk::Boolean& tangentsExist,
				                       ZcGeVector2d& startTangent, 
				                       ZcGeVector2d& endTangent) const;
    void            getDefinitionData (int& degree, Zdesk::Boolean& rational,
								       Zdesk::Boolean& periodic,
			                           ZcGeKnotVector& knots,
			                           ZcGePoint2dArray& controlPoints,
			                           ZcGeDoubleArray& weights) const;
    int             numWeights        () const;
    double          weightAt          (int idx) const;
    Zdesk::Boolean  evalMode          () const;        
	Zdesk::Boolean  getParamsOfC1Discontinuity (ZcGeDoubleArray& params,
				                                const ZcGeTol& tol 
					                            = ZcGeContext::gTol) const;
	Zdesk::Boolean	getParamsOfG1Discontinuity (ZcGeDoubleArray& params,
					                            const ZcGeTol& tol 
					                            = ZcGeContext::gTol) const;

    Zdesk::Boolean   setFitPointAt    (int index, const ZcGePoint2d& point);
    Zdesk::Boolean   addFitPointAt    (int index, const ZcGePoint2d& point);
    Zdesk::Boolean   deleteFitPointAt (int index);
    Zdesk::Boolean   setFitTolerance  (const ZcGeTol& fitTol=ZcGeContext::gTol);
    Zdesk::Boolean   setFitTangents   (const ZcGeVector2d& startTangent, 
	                        	       const ZcGeVector2d& endTangent);
    ZcGeNurbCurve2d& setFitData       (const ZcGePoint2dArray& fitPoints,                                             
				                       const ZcGeVector2d& startTangent, 
				                       const ZcGeVector2d& endTangent,
				                       const ZcGeTol& fitTol=ZcGeContext::gTol);
    ZcGeNurbCurve2d& setFitData       (const ZcGeKnotVector& fitKnots,
		                               const ZcGePoint2dArray& fitPoints,
				                       const ZcGeVector2d& startTangent, 
				                       const ZcGeVector2d& endTangent,										 
                        			   const ZcGeTol& fitTol=ZcGeContext::gTol,
				                       Zdesk::Boolean isPeriodic=Zdesk::kFalse);
    ZcGeNurbCurve2d&  setFitData      (int degree, 
                                       const ZcGePoint2dArray& fitPoints,
				                       const ZcGeTol& fitTol=ZcGeContext::gTol);
    Zdesk::Boolean    purgeFitData    ();
    ZcGeNurbCurve2d&  addKnot         (double newKnot);
    ZcGeNurbCurve2d&  insertKnot      (double newKnot);
    ZcGeSplineEnt2d&  setWeightAt     (int idx, double val);
    ZcGeNurbCurve2d&  setEvalMode     (Zdesk::Boolean evalMode=Zdesk::kFalse );
	ZcGeNurbCurve2d&  joinWith        (const ZcGeNurbCurve2d& curve);
	ZcGeNurbCurve2d&  hardTrimByParams(double newStartParam, 
		                               double newEndParam);
    ZcGeNurbCurve2d&  makeRational    (double weight = 1.0);
    ZcGeNurbCurve2d&  makeClosed      ();
    ZcGeNurbCurve2d&  makePeriodic    ();
    ZcGeNurbCurve2d&  makeNonPeriodic ();
    ZcGeNurbCurve2d&  makeOpen        ();
    ZcGeNurbCurve2d&  elevateDegree   (int plusDegree);

    ZcGeNurbCurve2d&  operator =      (const ZcGeNurbCurve2d& spline);
};

#pragma pack (pop)
#endif
