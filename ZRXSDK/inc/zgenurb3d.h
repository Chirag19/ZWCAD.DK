#ifndef ZC_GENURB3D_H
#define ZC_GENURB3D_H

#include "zgecurv3d.h"
#include "zgeintrvl.h"
#include "zgekvec.h"
#include "zgept3dar.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgesent3d.h"
#include "zgeplin3d.h"
#include "zgedblar.h"
#include "zgept3dar.h"
#include "zgevc3dar.h"
#pragma pack (push, 8)

class ZcGeEllipArc3d;
class ZcGeLineSeg3d;

class 
GE_DLLEXPIMPORT
ZcGeNurbCurve3d : public ZcGeSplineEnt3d
{
public:
    ZcGeNurbCurve3d ();
    ZcGeNurbCurve3d (const ZcGeNurbCurve3d& src );
    ZcGeNurbCurve3d (int degree, const ZcGeKnotVector& knots,
                     const ZcGePoint3dArray& cntrlPnts, 
                     Zdesk::Boolean isPeriodic = Zdesk::kFalse );
    ZcGeNurbCurve3d (int degree, const ZcGeKnotVector& knots,
                     const ZcGePoint3dArray& cntrlPnts, 
                     const ZcGeDoubleArray&  weights,
                     Zdesk::Boolean isPeriodic = Zdesk::kFalse );

    ZcGeNurbCurve3d (int degree, const ZcGePolyline3d& fitPolyline,
                     Zdesk::Boolean isPeriodic = Zdesk::kFalse );
    ZcGeNurbCurve3d (const ZcGePoint3dArray& fitPoints, 
				     const ZcGeVector3d& startTangent, 
				     const ZcGeVector3d& endTangent,
				     Zdesk::Boolean startTangentDefined = Zdesk::kTrue,
					 Zdesk::Boolean endTangentDefined   = Zdesk::kTrue,
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol);
    ZcGeNurbCurve3d (const ZcGePoint3dArray& fitPoints, 
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol);
    ZcGeNurbCurve3d (const ZcGePoint3dArray& fitPoints, 
                     const ZcGeVector3dArray& fitTangents,
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol,
				     Zdesk::Boolean isPeriodic = Zdesk::kFalse);

	ZcGeNurbCurve3d (const ZcGeEllipArc3d&  ellipse);

	ZcGeNurbCurve3d (const ZcGeLineSeg3d& linSeg);

    int             numFitPoints      () const;
    Zdesk::Boolean  getFitPointAt     (int index, ZcGePoint3d& point) const;
    Zdesk::Boolean  getFitTolerance   (ZcGeTol& fitTolerance) const;
    Zdesk::Boolean  getFitTangents    (ZcGeVector3d& startTangent, 
				                       ZcGeVector3d& endTangent) const;
    Zdesk::Boolean  getFitTangents    (ZcGeVector3d& startTangent, 
                                       ZcGeVector3d& endTangent,
                                       Zdesk::Boolean& startTangentDefined,
                                       Zdesk::Boolean& endTangentDefined) const;
    Zdesk::Boolean  getFitData        (ZcGePoint3dArray& fitPoints,
		                               ZcGeTol& fitTolerance,
				                       Zdesk::Boolean& tangentsExist,
				                       ZcGeVector3d& startTangent, 
				                       ZcGeVector3d& endTangent) const;
    void            getDefinitionData (int& degree, Zdesk::Boolean& rational,
								       Zdesk::Boolean& periodic,
			                           ZcGeKnotVector& knots,
			                           ZcGePoint3dArray& controlPoints,
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

    Zdesk::Boolean   setFitPointAt    (int index, const ZcGePoint3d& point);
    Zdesk::Boolean   addFitPointAt    (int index, const ZcGePoint3d& point);
    Zdesk::Boolean   deleteFitPointAt (int index);
    Zdesk::Boolean   setFitTolerance  (const ZcGeTol& fitTol=ZcGeContext::gTol);
    Zdesk::Boolean   setFitTangents   (const ZcGeVector3d& startTangent, 
	                        	       const ZcGeVector3d& endTangent);
    Zdesk::Boolean   setFitTangents   (const ZcGeVector3d& startTangent, 
                                       const ZcGeVector3d& endTangent,
                                       Zdesk::Boolean startTangentDefined,
                                       Zdesk::Boolean endTangentDefined) const;
    ZcGeNurbCurve3d& setFitData       (const ZcGePoint3dArray& fitPoints,                                             
				                       const ZcGeVector3d& startTangent, 
				                       const ZcGeVector3d& endTangent,
				                       const ZcGeTol& fitTol=ZcGeContext::gTol);
    ZcGeNurbCurve3d& setFitData       (const ZcGeKnotVector& fitKnots,
		                               const ZcGePoint3dArray& fitPoints,
				                       const ZcGeVector3d& startTangent, 
				                       const ZcGeVector3d& endTangent,										 
                        			   const ZcGeTol& fitTol=ZcGeContext::gTol,
				                       Zdesk::Boolean isPeriodic=Zdesk::kFalse);
    ZcGeNurbCurve3d&  setFitData      (int degree, 
                                       const ZcGePoint3dArray& fitPoints,
				                       const ZcGeTol& fitTol=ZcGeContext::gTol);
    Zdesk::Boolean    purgeFitData    ();
    ZcGeNurbCurve3d&  addKnot         (double newKnot);
    ZcGeNurbCurve3d&  insertKnot      (double newKnot);
    ZcGeSplineEnt3d&  setWeightAt     (int idx, double val);
    ZcGeNurbCurve3d&  setEvalMode     (Zdesk::Boolean evalMode=Zdesk::kFalse );
	ZcGeNurbCurve3d&  joinWith        (const ZcGeNurbCurve3d& curve);
	ZcGeNurbCurve3d&  hardTrimByParams(double newStartParam, 
		                               double newEndParam);
    ZcGeNurbCurve3d&  makeRational    (double weight = 1.0);
    ZcGeNurbCurve3d&  makeClosed      ();
    ZcGeNurbCurve3d&  makePeriodic    ();
    ZcGeNurbCurve3d&  makeNonPeriodic ();
    ZcGeNurbCurve3d&  makeOpen        ();
    ZcGeNurbCurve3d&  elevateDegree   (int plusDegree);

    ZcGeNurbCurve3d&  operator =      (const ZcGeNurbCurve3d& spline);
};

#pragma pack (pop)
#endif
