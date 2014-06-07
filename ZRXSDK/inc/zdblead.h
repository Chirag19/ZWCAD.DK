#ifndef ZD_DBLEAD_H
#define ZD_DBLEAD_H 1


#include "zdbmain.h"
#include "zdbcurve.h"
#include "zgescl3d.h"
#include "zgepnt2d.h"
#include "zgeplane.h"

#pragma pack(push, 8)

class ZcDbLeader: public  ZcDbCurve
{
public:
    ZcDbLeader();
    ~ZcDbLeader();
    ZCDB_DECLARE_MEMBERS(ZcDbLeader);
    DBCURVE_METHODS


    virtual void              setPlane          (const ZcGePlane&);
    virtual ZcGeVector3d      normal            () const;

    virtual  int numVertices() const;
    virtual  Zdesk::Boolean appendVertex(const ZcGePoint3d&);
    virtual  void              removeLastVertex  ();
    virtual  ZcGePoint3d firstVertex() const;
    virtual  ZcGePoint3d lastVertex() const;
    virtual  ZcGePoint3d vertexAt(int) const;
    virtual  Zdesk::Boolean setVertexAt(int, const ZcGePoint3d&);

    virtual Zdesk::Boolean    hasArrowHead      () const;
    virtual void              enableArrowHead   ();
    virtual void              disableArrowHead  ();
    virtual Zdesk::Boolean    hasHookLine       () const;
 
    virtual void              setToSplineLeader ();
    virtual void              setToStraightLeader();
    virtual Zdesk::Boolean    isSplined         () const;

    virtual ZcDbHardPointerId dimensionStyle    () const;
    virtual void              setDimensionStyle (const ZcDbHardPointerId&);
    
    Zcad::ErrorStatus   getDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;
    Zcad::ErrorStatus   setDimstyleData(ZcDbDimStyleTableRecord* pNewData);
    Zcad::ErrorStatus   setDimstyleData(ZcDbObjectId newDataId);
        

    virtual Zcad::ErrorStatus attachAnnotation  (const ZcDbObjectId& annoId);
    virtual Zcad::ErrorStatus detachAnnotation  ();
    virtual ZcDbObjectId      annotationObjId   () const;
    virtual Zcad::ErrorStatus evaluateLeader    ();
   
    virtual ZcGeVector3d      annotationOffset   () const;
    virtual Zcad::ErrorStatus setAnnotationOffset(const ZcGeVector3d& offset);

    enum AnnoType { 
        kMText = 0,
        kFcf,
        kBlockRef,
        kNoAnno 
    };
    AnnoType annoType()   const;
    double   annoHeight() const;
    double   annoWidth()  const;

 
    virtual  Zcad::ErrorStatus intersectWith    (const ZcDbEntity*,
                                                 ZcDb::Intersect, 
                                                 ZcGePoint3dArray&,
                                                 Zdesk::GsMarker thisGsMarker = 0,
                                                 Zdesk::GsMarker otherGsMarker = 0) const;
    virtual  Zcad::ErrorStatus intersectWith    (const ZcDbEntity*,
                                                 ZcDb::Intersect, 
                                                 const ZcGePlane& projPlane, 
                                                 ZcGePoint3dArray&,
                                                 Zdesk::GsMarker thisGsMarker = 0, 
                                                 Zdesk::GsMarker otherGsMarker = 0) const;


    virtual Zcad::ErrorStatus explode           (ZcDbVoidPtrArray& entitySet) const;

    virtual double           dimasz   () const;
    virtual ZcCmColor        dimclrd  () const;
    virtual double           dimgap   () const;
    virtual ZcDb::LineWeight dimlwd   () const;
    virtual ZcDbObjectId     dimldrblk() const;
    virtual bool             dimsah   () const;
    virtual double           dimscale () const;
    virtual int              dimtad   () const;
    virtual ZcDbObjectId     dimtxsty () const;
    virtual double           dimtxt   () const;

 
    virtual Zcad::ErrorStatus setDimasz   (double         val);
    virtual Zcad::ErrorStatus setDimclrd  (ZcCmColor&     val);
    virtual Zcad::ErrorStatus setDimgap   (double         val);
    virtual Zcad::ErrorStatus setDimldrblk(ZcDbObjectId   val);
    virtual Zcad::ErrorStatus setDimldrblk(const ZCHAR *  val);
    virtual Zcad::ErrorStatus setDimlwd   (ZcDb::LineWeight v);  // new to R15
    virtual Zcad::ErrorStatus setDimsah   (bool           val);
    virtual Zcad::ErrorStatus setDimscale (double         val);
    virtual Zcad::ErrorStatus setDimtad   (int            val);
    virtual Zcad::ErrorStatus setDimtxsty (ZcDbObjectId   val);
    virtual Zcad::ErrorStatus setDimtxt   (double         val);

  
    virtual void              modified          (const ZcDbObject*);
    virtual void              erased            (const ZcDbObject*,
                                                 Zdesk::Boolean = Zdesk::kTrue);
    virtual void              goodbye           (const ZcDbObject*);
    virtual void              copied            (const ZcDbObject*,
                                                 const ZcDbObject*);

 
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual void              setDimVars        ();
    virtual Zcad::ErrorStatus setColorIndex     (Zdesk::UInt16,
                                 Zdesk::Boolean doSubents = Zdesk::kTrue);

	virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;

virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
    virtual Zdesk::Boolean worldDraw(ZcGiWorldDraw* mode);
    virtual void viewportDraw(ZcGiViewportDraw* mode);

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& indices,const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus getOsnapPoints(
	 ZcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const ZcGePoint3d& pickPoint,
		const ZcGePoint3d& lastPoint,
		const ZcGeMatrix3d& xWorldToEye,
		ZcGePoint3dArray& snapPoints ) const;

};



#pragma pack(pop)

#endif

