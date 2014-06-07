#ifndef ZD_DBXLINE_H
#define ZD_DBXLINE_H 1


#include "Zdbmain.h"
#include "Zdbcurve.h"

#pragma pack(push, 8)

class ZcGePoint3d;
class ZcGeVector3d;

class ZcDbXline: public ZcDbCurve
{
public:
    ZcDbXline();
    ~ZcDbXline();
    ZCDB_DECLARE_MEMBERS(ZcDbXline);
    DBCURVE_METHODS

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const;
    
    ZcGePoint3d  basePoint() const;
    void         setBasePoint(const ZcGePoint3d& pt); 

    ZcGeVector3d unitDir() const;
    void         setUnitDir(const ZcGeVector3d& vec);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
    virtual Zdesk::Boolean worldDraw(ZcGiWorldDraw* mode);
	virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray& gripPoints, ZcDbIntArray& osnapModes, ZcDbIntArray& geomIds) const;

	virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& indices,const ZcGeVector3d& offset);
};


#pragma pack(pop)

#endif

