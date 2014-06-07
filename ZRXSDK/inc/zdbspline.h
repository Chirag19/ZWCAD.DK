#ifndef ZCDB_DBSPLINE_H
#define ZCDB_DBSPLINE_H

#include "zgegbl.h"
#include "zdbmain.h"
#include "zdbcurve.h"

#pragma pack (push, 8)

class ZcDbSpline: public  ZcDbCurve
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSpline);
    ZcDbSpline();
    virtual ~ZcDbSpline();
    ZcDbSpline(
               const ZcGePoint3dArray& points,
	       int                     order = 4, 
	       double                  fitTolerance = 0.0);
    ZcDbSpline(
               const ZcGePoint3dArray& points,
	       const ZcGeVector3d&     startTangent,
	       const ZcGeVector3d&     endTangent,
	       int                     order = 4, 
	       double                  fitTolerance = 0.0);

    ZcDbSpline(
               int                     degree, 
	       Zdesk::Boolean          rational, 
	       Zdesk::Boolean          closed, 
	       Zdesk::Boolean          periodic,
	       const ZcGePoint3dArray& controlPoints, 
	       const ZcGeDoubleArray&  knots, 
	       const ZcGeDoubleArray&  weights,
	       double                  controlPtTol = 0.0, 
	       double                  knotTol = 0.0);

    ZcDbSpline(
               const ZcGePoint3d&  center,
	       const ZcGeVector3d& unitNormal,
	       const ZcGeVector3d& majorAxis,
	       double              radiusRatio,
	       double              startAngle = 0.0,
	       double              endAngle = 6.28318530717958647692);

    Zdesk::Boolean          isNull() const;

    Zdesk::Boolean          isRational() const;
    int                     degree() const;
    Zcad::ErrorStatus       elevateDegree(int newDegree);

    int               numControlPoints() const;
    Zcad::ErrorStatus getControlPointAt(int index, ZcGePoint3d& point) const;
    Zcad::ErrorStatus setControlPointAt(int index, const ZcGePoint3d& point);

    int               numFitPoints() const;
    Zcad::ErrorStatus getFitPointAt(int index, ZcGePoint3d& point) const;
    Zcad::ErrorStatus setFitPointAt(int index, const ZcGePoint3d& point);

    Zcad::ErrorStatus insertFitPointAt(int index, const ZcGePoint3d& point);
    Zcad::ErrorStatus removeFitPointAt(int index);

    double            fitTolerance() const;
    Zcad::ErrorStatus setFitTol(double tol);

    Zcad::ErrorStatus getFitTangents(ZcGeVector3d& startTangent, 
				     ZcGeVector3d& endTangent) const;
    Zcad::ErrorStatus setFitTangents(const ZcGeVector3d& startTangent, 
				     const ZcGeVector3d& endTangent);

    Zdesk::Boolean    hasFitData() const;

    Zcad::ErrorStatus getFitData(
                                 ZcGePoint3dArray&  fitPoints, 
			         int&               degree, 
				 double&            fitTolerance, 
				 Zdesk::Boolean&    tangentsExist,
                                 ZcGeVector3d&      startTangent, 
				 ZcGeVector3d&      endTangent) const;

    Zcad::ErrorStatus setFitData(
                                 const ZcGePoint3dArray&  fitPoints, 
				 int                   degree, 
				 double                fitTolerance, 
                                 const ZcGeVector3d&   startTangent, 
				 const ZcGeVector3d&   endTangent);

    Zcad::ErrorStatus purgeFitData();
    Zcad::ErrorStatus updateFitData();

    Zcad::ErrorStatus getNurbsData(
                                  int&              degree, 
		                  Zdesk::Boolean&   rational, 
				  Zdesk::Boolean&   closed, 
				  Zdesk::Boolean&   periodic,
	                          ZcGePoint3dArray& controlPoints, 
				  ZcGeDoubleArray&  knots, 
				  ZcGeDoubleArray&  weights,
				  double&           controlPtTol,
				  double&           knotTol) const;

    Zcad::ErrorStatus setNurbsData(
                                  int                  degree, 
				  Zdesk::Boolean       rational, 
				  Zdesk::Boolean       closed, 
				  Zdesk::Boolean       periodic,
	                          const ZcGePoint3dArray& controlPoints, 
				  const ZcGeDoubleArray& knots, 
				  const ZcGeDoubleArray& weights,
				  double               controlPtTol,
				  double               knotTol);

    double            weightAt(int index) const;
    Zcad::ErrorStatus setWeightAt(int index, double weight);
    Zcad::ErrorStatus insertKnot(double param);
    Zcad::ErrorStatus reverseCurve();

    DBCURVE_METHODS

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
	virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
  
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
  
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
  
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
  
	virtual bool worldDraw(ZcGiWorldDraw* pWd) const;

	virtual Zcad::ErrorStatus  getGripPoints(ZcGePoint3dArray& gripPoints,ZcDbIntArray & osnapModes, ZcDbIntArray & geomIds) const;
    virtual Zcad::ErrorStatus  moveGripPointsAt(const ZcDbIntArray & indices, const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus  getGripPoints(ZcDbGripDataPtrArray& grips, const double curViewUnitSize, const int gripSize, const ZcGeVector3d& curViewDir, const int bitflags) const;
    virtual Zcad::ErrorStatus  moveGripPointsAt(const ZcDbVoidPtrArray& gripAppData, const ZcGeVector3d& offset, const int bitflags);  
    virtual Zcad::ErrorStatus  getStretchPoints(ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus  moveStretchPointsAt(const ZcDbIntArray & indices,const ZcGeVector3d& offset);

	virtual Zcad::ErrorStatus getNormal(ZcGeVector3d& normal) const;
};

#pragma pack (pop)

#endif
