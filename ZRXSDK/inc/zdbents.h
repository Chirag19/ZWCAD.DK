#ifndef ZD_DBENTS_H
#define ZD_DBENTS_H


#include "zdbmain.h"
#include "zdbcurve.h"
#include "zgescl3d.h"
#include "zgepnt2d.h"
#include "zdbmtext.h"
#include "zdbbackground.h"
#include "zdbdim.h"
#include "zgept2dar.h"
#include "zgedblar.h"
#include "zdbsymtb.h"
#include "zgemat3d.h"
#include "zcdbxref.h"
#include "zcgi.h"
#include "zcgiviewport.h"
#include "zcgivisualstyle.h"

#pragma pack(push, 8)

class ZcDbAttribute;
class ZcDbSequenceEnd;
class ZcDb3dPolylineVertex;
class ZcDb2dVertex;
class ZcDbMText;
class ZcDbAnnotationScale;

class ZcDbText: public ZcDbEntity
{
public:
    ZcDbText();
    ZcDbText(
        const ZcGePoint3d&  position,
        const ZCHAR*        text,
        ZcDbObjectId        style = ZcDbObjectId::kNull,
        double              height = 0,
        double              rotation = 0);
    ~ZcDbText();
    ZCDB_DECLARE_MEMBERS(ZcDbText);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

    ZcGePoint3d         alignmentPoint() const;
    Zcad::ErrorStatus   setAlignmentPoint(const ZcGePoint3d&);
    Zdesk::Boolean      isDefaultAlignment() const;

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zdesk::Boolean    isPlanar() const;
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);

    double              rotation() const; 
    Zcad::ErrorStatus   setRotation(double);

    double              height() const; 
    Zcad::ErrorStatus   setHeight(double);

    double              widthFactor() const; 
    Zcad::ErrorStatus   setWidthFactor(double);

    ZCHAR*              textString() const;
    const ZCHAR*        textStringConst() const;
    Zcad::ErrorStatus   setTextString(const ZCHAR*);
     
    ZcDbObjectId        textStyle() const;
    Zcad::ErrorStatus   setTextStyle(ZcDbObjectId);
    
    Zdesk::Boolean      isMirroredInX() const;
    Zcad::ErrorStatus   mirrorInX(Zdesk::Boolean);
     
    Zdesk::Boolean      isMirroredInY() const;
    Zcad::ErrorStatus   mirrorInY(Zdesk::Boolean);
     
    ZcDb::TextHorzMode  horizontalMode() const;
    Zcad::ErrorStatus   setHorizontalMode(ZcDb::TextHorzMode);
     
    ZcDb::TextVertMode  verticalMode() const;
    Zcad::ErrorStatus   setVerticalMode(ZcDb::TextVertMode);

    int                 correctSpelling();
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual Zdesk::UInt32       setAttributes(ZcGiDrawableTraits* pTraits);

    virtual Zcad::ErrorStatus   adjustAlignment(
        const ZcDbDatabase* pDb = NULL);

    Zcad::ErrorStatus   setField(const ZCHAR* pszPropName, ZcDbField* pField,
                                 ZcDbObjectId& fieldId);

    Zcad::ErrorStatus   removeField(ZcDbObjectId fieldId);
    Zcad::ErrorStatus   removeField(const ZCHAR* pszPropName, ZcDbObjectId& returnId);
    Zcad::ErrorStatus   removeField(const ZCHAR* pszPropName);

    Zcad::ErrorStatus   convertFieldToText();

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;

	virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

	virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* pWd);
    virtual void                viewportDraw(ZcGiViewportDraw* pVd);

	virtual Zcad::ErrorStatus   getGripPoints(
		ZcGePoint3dArray&  gripPoints,
		ZcDbIntArray &     osnapModes,
		ZcDbIntArray &  geomIds) const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual  Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray & indices,
        const ZcGeVector3d& offset);

	virtual Zcad::ErrorStatus getStretchPoints(
		ZcGePoint3dArray& stretchPoints) const;

	virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray & indices,
		const ZcGeVector3d& offset);

	Zcad::ErrorStatus getTransformedCopy(const ZcGeMatrix3d& xform,
		ZcDbEntity*& pEnt) const;
};

class ZcDbAttributeDefinition: public ZcDbText
{
public:
    ZcDbAttributeDefinition();
    ZcDbAttributeDefinition(
        const ZcGePoint3d& position,
        const ZCHAR*       text,
        const ZCHAR*       tag,
        const ZCHAR*       prompt,
        ZcDbObjectId       style = ZcDbObjectId::kNull);
    ~ZcDbAttributeDefinition();
    ZCDB_DECLARE_MEMBERS(ZcDbAttributeDefinition);

    ZCHAR*              prompt() const;
    const ZCHAR*        promptConst() const;
    Zcad::ErrorStatus   setPrompt(const ZCHAR*);
     
    ZCHAR*              tag() const;
    const ZCHAR*        tagConst() const;
    Zcad::ErrorStatus   setTag(const ZCHAR*);
 
    Zdesk::Boolean      isInvisible() const;
    Zcad::ErrorStatus   setInvisible(Zdesk::Boolean);
 
    Zdesk::Boolean      isConstant() const;
    Zcad::ErrorStatus   setConstant(Zdesk::Boolean);
 
    Zdesk::Boolean      isVerifiable() const;
    Zcad::ErrorStatus   setVerifiable(Zdesk::Boolean);
 
    Zdesk::Boolean      isPreset() const;
    Zcad::ErrorStatus   setPreset(Zdesk::Boolean);
     
    Zdesk::UInt16       fieldLength() const;
    Zcad::ErrorStatus   setFieldLength(Zdesk::UInt16);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus   adjustAlignment(
        const ZcDbDatabase* pDb = NULL);
 
    bool lockPositionInBlock() const;
    Zcad::ErrorStatus setLockPositionInBlock(bool bValue);


    bool              isMTextAttributeDefinition          () const;
    ZcDbMText *       getMTextAttributeDefinition         () const;
    const ZcDbMText * getMTextAttributeDefinitionConst    () const;
    Zcad::ErrorStatus setMTextAttributeDefinition         (ZcDbMText*);
    Zcad::ErrorStatus convertIntoMTextAttributeDefinition (Zdesk::Boolean val = Zdesk::kTrue);
    Zcad::ErrorStatus updateMTextAttributeDefinition      ();

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* pWd);
    virtual void                viewportDraw(ZcGiViewportDraw* pVd);
};

class ZcDbAttribute: public ZcDbText
{
public:
    ZcDbAttribute();
    ZcDbAttribute(
        const ZcGePoint3d& position,
        const ZCHAR*       text,
        const ZCHAR*       tag,
        ZcDbObjectId       style = ZcDbObjectId::kNull);
    ~ZcDbAttribute();
    ZCDB_DECLARE_MEMBERS(ZcDbAttribute);

    ZCHAR*              tag() const;
    const ZCHAR*        tagConst() const;
    Zcad::ErrorStatus   setTag(const ZCHAR* newTag);

    Zdesk::Boolean      isInvisible() const;
    Zcad::ErrorStatus   setInvisible(Zdesk::Boolean);

    Zdesk::Boolean      isConstant() const;
    Zdesk::Boolean      isVerifiable() const;
    Zdesk::Boolean      isPreset() const;

    Zdesk::UInt16       fieldLength() const;
    Zcad::ErrorStatus   setFieldLength(Zdesk::UInt16);

    Zcad::ErrorStatus setAttributeFromBlock(const ZcGeMatrix3d& blkXform);
    Zcad::ErrorStatus setAttributeFromBlock(
        const ZcDbAttributeDefinition *pAttdef,
        const ZcGeMatrix3d& blkXform);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    bool lockPositionInBlock() const;
    Zcad::ErrorStatus setLockPositionInBlock(bool bValue);


    bool              isMTextAttribute          ()                        const;
    ZcDbMText *       getMTextAttribute         ()                        const;
    const ZcDbMText * getMTextAttributeConst    ()                        const;
    Zcad::ErrorStatus setMTextAttribute         (ZcDbMText *);
    Zcad::ErrorStatus convertIntoMTextAttribute (Zdesk::Boolean val = Zdesk::kTrue);
    Zcad::ErrorStatus updateMTextAttribute      ();
    bool              isReallyLocked            ()                        const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* pWd);
    virtual void                viewportDraw(ZcGiViewportDraw* pVd);
};

class ZcDbBlockReference: public ZcDbEntity
{
public:
            ZcDbBlockReference();
            ZcDbBlockReference(const ZcGePoint3d&  position,
                                     ZcDbObjectId  blockTableRec);
            ~ZcDbBlockReference();
    ZCDB_DECLARE_MEMBERS(ZcDbBlockReference);

            ZcDbObjectId      blockTableRecord() const;
    virtual Zcad::ErrorStatus setBlockTableRecord(ZcDbObjectId);

            ZcGePoint3d       position() const;
    virtual Zcad::ErrorStatus setPosition(const ZcGePoint3d&);

            ZcGeScale3d       scaleFactors() const;
            ZcGeScale3d       nonAnnotationScaleFactors() const;
    virtual Zcad::ErrorStatus setScaleFactors(const ZcGeScale3d& scale);
 
            double            rotation() const;
    virtual Zcad::ErrorStatus setRotation(double newVal);
 
            ZcGeVector3d      normal() const;
    virtual Zcad::ErrorStatus setNormal(const ZcGeVector3d& newVal);

    virtual Zdesk::Boolean    isPlanar() const { return Zdesk::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

            ZcGeMatrix3d      blockTransform() const;
            ZcGeMatrix3d      nonAnnotationBlockTransform() const;
    virtual Zcad::ErrorStatus setBlockTransform(const ZcGeMatrix3d&);

            Zcad::ErrorStatus appendAttribute(ZcDbAttribute*);
            Zcad::ErrorStatus appendAttribute(ZcDbObjectId&, ZcDbAttribute*);

            Zcad::ErrorStatus openAttribute(ZcDbAttribute*&, ZcDbObjectId,
                                            ZcDb::OpenMode,
                                            bool openErasedOne = false);

            Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

            ZcDbObjectIterator*  attributeIterator() const;

    virtual Zdesk::Boolean    treatAsZcDbBlockRefForExplode() const;


    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                  ZcDb::SubentType,
                                  Zdesk::GsMarker       gsMark,
                                  const ZcGePoint3d&    pickPoint,
                                  const ZcGeMatrix3d&   viewXform,
                                  int&                  numPaths,
                                  ZcDbFullSubentPath*&  subentPaths,
                                  int                   numInserts = 0,
                                  ZcDbObjectId*         entAndInsertStack = NULL) const;

    virtual  Zcad::ErrorStatus getGsMarkersAtSubentPath(
                                  const ZcDbFullSubentPath& subPath,
                                  ZcArray<Zdesk::GsMarker>& gsMarkers) const;

    virtual Zcad::ErrorStatus highlight  (const ZcDbFullSubentPath&
                                          = kNullSubent, const Zdesk::Boolean highlightAll = Zdesk::kFalse) const;

    virtual Zcad::ErrorStatus unhighlight(const ZcDbFullSubentPath&
                                          = kNullSubent, const Zdesk::Boolean highlightAll = Zdesk::kFalse) const;

    virtual ZcDbEntity*       subentPtr  (const ZcDbFullSubentPath&) const;

    virtual Zdesk::Boolean    worldDraw(ZcGiWorldDraw* mode);
    virtual void              viewportDraw(ZcGiViewportDraw* mode);

            Zcad::ErrorStatus geomExtentsBestFit( 
                                        ZcDbExtents& extents, 
                                        const ZcGeMatrix3d& parentXform = 
                                            ZcGeMatrix3d::kIdentity) const;

    virtual Zcad::ErrorStatus explodeToOwnerSpace() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);


	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray & geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
	Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

};

class ZcDbMInsertBlock: public ZcDbBlockReference
{
public:
    ZcDbMInsertBlock();
    ZcDbMInsertBlock(
        const ZcGePoint3d&  position,
        ZcDbObjectId        blockTableRec,
        Zdesk::UInt16       columns,
        Zdesk::UInt16       rows,
        double              colSpacing,
        double              rowSpacing);
    ~ZcDbMInsertBlock();
    ZCDB_DECLARE_MEMBERS(ZcDbMInsertBlock);

    Zdesk::UInt16      columns() const;
    Zcad::ErrorStatus  setColumns(Zdesk::UInt16);
 
    Zdesk::UInt16      rows() const;
    Zcad::ErrorStatus  setRows(Zdesk::UInt16);
 
    double             columnSpacing() const;
    Zcad::ErrorStatus  setColumnSpacing(double);
 
    double             rowSpacing() const;
    Zcad::ErrorStatus  setRowSpacing(double);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
	Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
};

class ZcDbBlockBegin: public ZcDbEntity
{
public:
    ZcDbBlockBegin();
    ~ZcDbBlockBegin();
    ZCDB_DECLARE_MEMBERS(ZcDbBlockBegin);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

class ZcDbBlockEnd: public ZcDbEntity
{
public:
    ZcDbBlockEnd();
    ~ZcDbBlockEnd();
    ZCDB_DECLARE_MEMBERS(ZcDbBlockEnd);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

class ZcDbSequenceEnd: public ZcDbEntity
{
public:
    ZcDbSequenceEnd();
    ~ZcDbSequenceEnd();
    ZCDB_DECLARE_MEMBERS(ZcDbSequenceEnd);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

	Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
	Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

};

class ZcDbVertex: public ZcDbEntity
{
public:
    ZcDbVertex();
    ~ZcDbVertex();
    ZCDB_DECLARE_MEMBERS(ZcDbVertex);

	Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
	Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
	Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

};



class ZcDb2dVertex: public ZcDbVertex
{
public:
    ZcDb2dVertex();
    ~ZcDb2dVertex();
    ZCDB_DECLARE_MEMBERS(ZcDb2dVertex);
    ZcDb2dVertex(
        const ZcGePoint3d&  position,
        double   bulge      = 0,
        double   startWidth = 0,
        double   endWidth   = 0,
        double   tangent    = 0);

    ZcDb::Vertex2dType vertexType() const;

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&); 

    double              startWidth() const; 
    Zcad::ErrorStatus   setStartWidth(double newVal);

    double              endWidth() const; 
    Zcad::ErrorStatus   setEndWidth(double newVal);

    double              bulge() const; 
    Zcad::ErrorStatus   setBulge(double newVal);

    Zdesk::Boolean      isTangentUsed() const;
    Zcad::ErrorStatus   useTangent();
    Zcad::ErrorStatus   ignoreTangent();

    double              tangent() const; 
    Zcad::ErrorStatus   setTangent(double newVal);

	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

};

class ZcDb3dPolylineVertex: public ZcDbVertex
{
public:
    ZcDb3dPolylineVertex();
    ~ZcDb3dPolylineVertex();
    ZCDB_DECLARE_MEMBERS(ZcDb3dPolylineVertex);
    ZcDb3dPolylineVertex(const ZcGePoint3d&);

    ZcDb::Vertex3dType vertexType() const;


    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&); 

	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

};

class ZcDbPolygonMeshVertex: public ZcDbVertex
{
public:
    ZcDbPolygonMeshVertex();
    ZcDbPolygonMeshVertex(const ZcGePoint3d&  position);
    ~ZcDbPolygonMeshVertex();
    ZCDB_DECLARE_MEMBERS(ZcDbPolygonMeshVertex);

    ZcDb::Vertex3dType vertexType() const;

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&); 

	Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;


};

class ZcDbPolyFaceMeshVertex: public ZcDbVertex
{
public:
    ZcDbPolyFaceMeshVertex();
    ZcDbPolyFaceMeshVertex(const ZcGePoint3d&  position);
    ~ZcDbPolyFaceMeshVertex();
    ZCDB_DECLARE_MEMBERS(ZcDbPolyFaceMeshVertex);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&); 

	Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;


};

class ZcDbFaceRecord: public ZcDbVertex
{
public:
	ZcDbFaceRecord();

	ZcDbFaceRecord(Zdesk::Int16 vtx0, Zdesk::Int16 vtx1,
		Zdesk::Int16 vtx2, Zdesk::Int16 vtx3);
	~ZcDbFaceRecord();
	ZCDB_DECLARE_MEMBERS(ZcDbFaceRecord);


	Zcad::ErrorStatus getVertexAt(Zdesk::UInt16 faceIdx,
		Zdesk::Int16& vtxIdx) const;
	Zcad::ErrorStatus setVertexAt(Zdesk::UInt16 faceIdx,
		Zdesk::Int16  vtxIdx);

	Zcad::ErrorStatus isEdgeVisibleAt(Zdesk::UInt16 faceIndex,
		Zdesk::Boolean& visible) const;

	Zcad::ErrorStatus makeEdgeVisibleAt(Zdesk::UInt16 faceIndex);
	Zcad::ErrorStatus makeEdgeInvisibleAt(Zdesk::UInt16 faceIndex);

	Zcad::ErrorStatus ZcDbFaceRecord::getGeomExtents(ZcDbExtents& extents) const;
	Zcad::ErrorStatus ZcDbFaceRecord::dwgInFields(ZcDbDwgFiler* filer);
	Zcad::ErrorStatus ZcDbFaceRecord::dwgOutFields(ZcDbDwgFiler* filer) const;
	Zcad::ErrorStatus ZcDbFaceRecord::dxfInFields(ZcDbDxfFiler* filer);
	Zcad::ErrorStatus ZcDbFaceRecord::dxfOutFields(ZcDbDxfFiler* filer) const;

};

class ZcDb2dPolyline: public ZcDbCurve
{
public:
    ZcDb2dPolyline();
    ~ZcDb2dPolyline();
    ZCDB_DECLARE_MEMBERS(ZcDb2dPolyline);
    ZcDb2dPolyline (
        ZcDb::Poly2dType  type,
        ZcGePoint3dArray& vertices,
        double            elevation     = 0,
        Zdesk::Boolean    closed        = Zdesk::kFalse,
        double            defStartWidth = 0,
        double            defEndWidth   = 0,
        ZcGeDoubleArray*  bulges        = NULL);

    DBCURVE_METHODS

    ZcDb::Poly2dType    polyType() const;
    Zcad::ErrorStatus   setPolyType(ZcDb::Poly2dType);
    Zcad::ErrorStatus   convertToPolyType(ZcDb::Poly2dType newVal);

    Zcad::ErrorStatus   makeClosed();
    Zcad::ErrorStatus   makeOpen();
 
    double              defaultStartWidth() const;
    Zcad::ErrorStatus   setDefaultStartWidth(double);

    double              defaultEndWidth() const;
    Zcad::ErrorStatus   setDefaultEndWidth(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    double              elevation() const;
    Zcad::ErrorStatus   setElevation(double);

    Zdesk::Boolean      isLinetypeGenerationOn() const;
    Zcad::ErrorStatus   setLinetypeGenerationOn();
    Zcad::ErrorStatus   setLinetypeGenerationOff();

    Zcad::ErrorStatus   straighten();
    Zcad::ErrorStatus   splineFit();
    Zcad::ErrorStatus   splineFit(ZcDb::Poly2dType splineType,
                                  Zdesk::Int16   splineSegs);
    Zcad::ErrorStatus   curveFit();

    Zcad::ErrorStatus appendVertex(ZcDb2dVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDb2dVertex*);

    Zcad::ErrorStatus insertVertexAt(const ZcDb2dVertex* pIndexVert,
        ZcDb2dVertex* pNewVertex); 
    Zcad::ErrorStatus insertVertexAt(ZcDbObjectId& newVertId,
        const ZcDbObjectId& indexVertId, ZcDb2dVertex* pNewVertex);
    
    Zcad::ErrorStatus openVertex(ZcDb2dVertex*&, ZcDbObjectId    vertId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false) const;
    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator*  vertexIterator() const;

    ZcGePoint3d       vertexPosition(const ZcDb2dVertex& vert) const;


    virtual Zdesk::Boolean    worldDraw   (ZcGiWorldDraw* pWd);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray & geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

};

class ZcDb3dPolyline: public ZcDbCurve
{
public:
    ZcDb3dPolyline();
    ~ZcDb3dPolyline();
    ZCDB_DECLARE_MEMBERS(ZcDb3dPolyline);
    ZcDb3dPolyline(ZcDb::Poly3dType, ZcGePoint3dArray& vertices,
                   Zdesk::Boolean closed = Zdesk::kFalse);

    DBCURVE_METHODS

    Zcad::ErrorStatus   makeClosed();
    Zcad::ErrorStatus   makeOpen();
 
    ZcDb::Poly3dType    polyType() const;
    Zcad::ErrorStatus   setPolyType(ZcDb::Poly3dType);
    Zcad::ErrorStatus   convertToPolyType(ZcDb::Poly3dType newVal);

    Zcad::ErrorStatus   straighten();
    Zcad::ErrorStatus   splineFit();
    Zcad::ErrorStatus   splineFit(ZcDb::Poly3dType splineType,
                                  Zdesk::Int16   splineSegs);


    Zcad::ErrorStatus appendVertex(ZcDb3dPolylineVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDb3dPolylineVertex*);

    Zcad::ErrorStatus insertVertexAt(const ZcDb3dPolylineVertex* pIndexVert,
        ZcDb3dPolylineVertex* pNewVertex); 
    Zcad::ErrorStatus insertVertexAt(ZcDbObjectId& newVertId,
        const ZcDbObjectId& indexVertId, ZcDb3dPolylineVertex* pNewVertex);
    
    Zcad::ErrorStatus openVertex(ZcDb3dPolylineVertex*&, ZcDbObjectId vertId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false);

    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator* vertexIterator() const;


    virtual Zdesk::Boolean    worldDraw   (ZcGiWorldDraw* pWd);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray & geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

};




class ZcDbArc: public ZcDbCurve
{
public:
    ZcDbArc();
    ZcDbArc(const ZcGePoint3d& center, double radius,
            double startAngle, double endAngle);
    ZcDbArc(const ZcGePoint3d& center, const ZcGeVector3d& normal,
            double radius, double startAngle, double endAngle);
    ~ZcDbArc();
    ZCDB_DECLARE_MEMBERS(ZcDbArc);

    DBCURVE_METHODS

    Zcad::ErrorStatus getTransformedCopy(
                      const ZcGeMatrix3d& xform, 
                      ZcDbEntity*& ent) const;

    ZcGePoint3d         center() const;
    Zcad::ErrorStatus   setCenter(const ZcGePoint3d&); 

    double              radius() const;
    Zcad::ErrorStatus   setRadius(double);

    double              startAngle() const;
    Zcad::ErrorStatus   setStartAngle(double);

    double              endAngle() const;
    Zcad::ErrorStatus   setEndAngle(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize, 
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
    virtual Zdesk::Boolean worldDraw(ZcGiWorldDraw* mode);

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



class ZcDbCircle: public ZcDbCurve
{
public:
    ZcDbCircle();
    ZcDbCircle(const ZcGePoint3d& cntr, const ZcGeVector3d& nrm, double radius);
    ~ZcDbCircle();
    ZCDB_DECLARE_MEMBERS(ZcDbCircle);

    DBCURVE_METHODS

    Zcad::ErrorStatus getTransformedCopy(
                         const ZcGeMatrix3d& xform, 
                         ZcDbEntity*& ent) const;

    ZcGePoint3d         center() const;
    Zcad::ErrorStatus   setCenter(const ZcGePoint3d&); 

    double              radius() const;
    Zcad::ErrorStatus   setRadius(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void        gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize, 
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
    virtual Zdesk::Boolean worldDraw(ZcGiWorldDraw* mode);

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

class ZcDbLine: public ZcDbCurve
{
public:
    ZcDbLine();
    ZcDbLine(const ZcGePoint3d& start, const ZcGePoint3d& end);
    ~ZcDbLine();
    ZCDB_DECLARE_MEMBERS(ZcDbLine);
 
    DBCURVE_METHODS

    Zcad::ErrorStatus getTransformedCopy(
                            const ZcGeMatrix3d& xform, 
                            ZcDbEntity*& ent) const;

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const;
    
    ZcGePoint3d         startPoint() const;
    Zcad::ErrorStatus   setStartPoint(const ZcGePoint3d&); 

    ZcGePoint3d         endPoint() const;
    Zcad::ErrorStatus   setEndPoint(const ZcGePoint3d&); 

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize, 
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
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

class ZcDbPoint: public ZcDbEntity
{
public:
    ZcDbPoint();
    ZcDbPoint(const ZcGePoint3d&   position);
    ~ZcDbPoint();
    ZCDB_DECLARE_MEMBERS(ZcDbPoint);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    double              ecsRotation() const;
    Zcad::ErrorStatus   setEcsRotation(double);


    virtual Zdesk::Boolean    isPlanar() const;
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    virtual Zdesk::UInt32     setAttributes(ZcGiDrawableTraits* pTraits);
    virtual Zdesk::Boolean worldDraw(ZcGiWorldDraw* mode);
    virtual void viewportDraw(ZcGiViewportDraw* pVpDraw);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& indices,const ZcGeVector3d& offset);
	virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
};

class ZcDbFace: public ZcDbEntity
{
public:                
    ZcDbFace();
    ZcDbFace(const ZcGePoint3d&   pt0,
             const ZcGePoint3d&   pt1,
             const ZcGePoint3d&   pt2,
             const ZcGePoint3d&   pt3,
                   Zdesk::Boolean e0vis = Zdesk::kTrue,
                   Zdesk::Boolean e1vis = Zdesk::kTrue,
                   Zdesk::Boolean e2vis = Zdesk::kTrue,
                   Zdesk::Boolean e3vis = Zdesk::kTrue);
    ZcDbFace(const ZcGePoint3d&   pt0,
             const ZcGePoint3d&   pt1,
             const ZcGePoint3d&   pt2,
                   Zdesk::Boolean e0vis = Zdesk::kTrue,
                   Zdesk::Boolean e1vis = Zdesk::kTrue,
                   Zdesk::Boolean e2vis = Zdesk::kTrue,
                   Zdesk::Boolean e3vis = Zdesk::kTrue);
    ~ZcDbFace();
    ZCDB_DECLARE_MEMBERS(ZcDbFace);

    Zcad::ErrorStatus getVertexAt(Zdesk::UInt16, ZcGePoint3d&) const;
    Zcad::ErrorStatus setVertexAt(Zdesk::UInt16, const ZcGePoint3d&);

    Zcad::ErrorStatus isEdgeVisibleAt(Zdesk::UInt16, Zdesk::Boolean&) const;
    Zcad::ErrorStatus makeEdgeVisibleAt(Zdesk::UInt16);
    Zcad::ErrorStatus makeEdgeInvisibleAt(Zdesk::UInt16);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   transformBy(const ZcGeFastTransform& xform);

    virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw*        mode);
    virtual void                viewportDraw(ZcGiViewportDraw*  mode);

	virtual Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const;

    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 Zdesk::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray &   geomIds) const;

    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray &     osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual  Zcad::ErrorStatus  moveGripPointsAt(const ZcDbIntArray & indices, const ZcGeVector3d& offset);
    
    virtual Zcad::ErrorStatus   getStretchPoints( ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus   moveStretchPointsAt(const ZcDbIntArray & indices,  const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;
};

class ZcDbPolyFaceMesh: public ZcDbEntity
{
public:
    ZcDbPolyFaceMesh();
    ~ZcDbPolyFaceMesh();
    ZCDB_DECLARE_MEMBERS(ZcDbPolyFaceMesh);

    Zdesk::Int16 numVertices() const;
    Zdesk::Int16 numFaces() const;

    Zcad::ErrorStatus appendVertex(ZcDbPolyFaceMeshVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDbPolyFaceMeshVertex*);

    Zcad::ErrorStatus appendFaceRecord(ZcDbFaceRecord*);
    Zcad::ErrorStatus appendFaceRecord(ZcDbObjectId&, ZcDbFaceRecord*);

    Zcad::ErrorStatus openVertex(ZcDbVertex*&, ZcDbObjectId subObjId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false);

    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator*  vertexIterator() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray & geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
	Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

};

class ZcDbPolygonMesh: public ZcDbEntity
{
public:
    ZcDbPolygonMesh();
    ZcDbPolygonMesh(ZcDb::PolyMeshType pType,
                    Zdesk::Int16       mSize,
                    Zdesk::Int16       nSize,
                    const ZcGePoint3dArray& vertices,
                    Zdesk::Boolean     mClosed = Zdesk::kTrue,
                    Zdesk::Boolean     nClosed = Zdesk::kTrue);
    ~ZcDbPolygonMesh();
    ZCDB_DECLARE_MEMBERS(ZcDbPolygonMesh);

    ZcDb::PolyMeshType  polyMeshType() const;
    Zcad::ErrorStatus   setPolyMeshType(ZcDb::PolyMeshType);
    Zcad::ErrorStatus   convertToPolyMeshType(ZcDb::PolyMeshType newVal);

    Zdesk::Int16        mSize() const;
    Zcad::ErrorStatus   setMSize(Zdesk::Int16);

    Zdesk::Int16        nSize() const;
    Zcad::ErrorStatus   setNSize(Zdesk::Int16);
 
    Zdesk::Boolean      isMClosed() const;
    Zcad::ErrorStatus   makeMClosed();
    Zcad::ErrorStatus   makeMOpen();
 
    Zdesk::Boolean      isNClosed() const;
    Zcad::ErrorStatus   makeNClosed();
    Zcad::ErrorStatus   makeNOpen();
 
    Zdesk::Int16        mSurfaceDensity() const;
    Zcad::ErrorStatus   setMSurfaceDensity(Zdesk::Int16);

    Zdesk::Int16        nSurfaceDensity() const;
    Zcad::ErrorStatus   setNSurfaceDensity(Zdesk::Int16);

    Zcad::ErrorStatus   straighten();
    Zcad::ErrorStatus   surfaceFit();
    Zcad::ErrorStatus   surfaceFit(ZcDb::PolyMeshType surfType,
                                   Zdesk::Int16 surfu, Zdesk::Int16 surfv);


    Zcad::ErrorStatus appendVertex(ZcDbPolygonMeshVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDbPolygonMeshVertex*);

    Zcad::ErrorStatus openVertex(ZcDbPolygonMeshVertex*&, ZcDbObjectId vertId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false);

    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator*  vertexIterator() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

	Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray & geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

};

class ZcDbSolid: public ZcDbEntity
{
public:
    ZcDbSolid();
    ZcDbSolid(const ZcGePoint3d&    pt0,
              const ZcGePoint3d&    pt1,
              const ZcGePoint3d&    pt2,
              const ZcGePoint3d&    pt3);
    ZcDbSolid(const ZcGePoint3d&    pt0,
              const ZcGePoint3d&    pt1,
              const ZcGePoint3d&    pt2);
    ~ZcDbSolid();
    ZCDB_DECLARE_MEMBERS(ZcDbSolid);

    Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& pXform);
    Zcad::ErrorStatus getTransformedCopy(
              const ZcGeMatrix3d& xform,
              ZcDbEntity*&  pEnt) const;

    Zcad::ErrorStatus getPointAt(Zdesk::UInt16 idx, ZcGePoint3d& pntRes) const;
    Zcad::ErrorStatus setPointAt(Zdesk::UInt16 idx, const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

	virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* pWd);
	virtual Zcad::ErrorStatus   getPlane(ZcGePlane&, ZcDb::Planarity&) const;
                                    
	virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray &     osnapModes,
                                   ZcDbIntArray &  geomIds) const;
	virtual  Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray & indices,
        const ZcGeVector3d& offset);
	virtual Zcad::ErrorStatus getStretchPoints(
        ZcGePoint3dArray& stretchPoints) const;
	virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray & indices,
        const ZcGeVector3d& offset);

};

class ZcDbTrace: public ZcDbEntity
{
public:
    ZcDbTrace();
    ZcDbTrace(const ZcGePoint3d&    pt0,
              const ZcGePoint3d&    pt1,
              const ZcGePoint3d&    pt2,
              const ZcGePoint3d&    pt3);
    ~ZcDbTrace();
    ZCDB_DECLARE_MEMBERS(ZcDbTrace);


    Zcad::ErrorStatus getPointAt(Zdesk::UInt16 idx, ZcGePoint3d& PntRes) const;
    Zcad::ErrorStatus setPointAt(Zdesk::UInt16 idx, const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zdesk::Boolean    isPlanar() const { return Zdesk::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
	virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

	virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* pWd);
	virtual void                viewportDraw(ZcGiViewportDraw*  mode);

	virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray &     osnapModes,
                                   ZcDbIntArray &  geomIds) const;
	virtual  Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray & indices,
        const ZcGeVector3d& offset);
	virtual Zcad::ErrorStatus getStretchPoints(
        ZcGePoint3dArray& stretchPoints) const;
	virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray & indices,
        const ZcGeVector3d& offset);
};

class ZcDbShape: public ZcDbEntity
{
public:
    ZcDbShape();
    ZcDbShape(const ZcGePoint3d&  position,
                    double        size,
                    double        rotation    = 0,
                    double        widthFactor = 0);
    ~ZcDbShape();
    ZCDB_DECLARE_MEMBERS(ZcDbShape);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&); 
    
    double              size() const;
    Zcad::ErrorStatus   setSize(double);
    
    ZCHAR*              name() const;
    Zcad::ErrorStatus   setName(const ZCHAR*); 
    
    double              rotation() const;
    Zcad::ErrorStatus   setRotation(double);
    
    double              widthFactor() const;
    Zcad::ErrorStatus   setWidthFactor(double);
    
    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zdesk::Boolean    isPlanar() const;
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    Zdesk::Int16      shapeNumber() const;
    Zcad::ErrorStatus setShapeNumber(Zdesk::Int16);
 
    ZcDbObjectId        styleId() const;
    Zcad::ErrorStatus   setStyleId(ZcDbObjectId id);


    ZcDbObjectId        shapeIndex() const;
    Zcad::ErrorStatus   setShapeIndex(ZcDbObjectId id);
                                 

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* pWd);

	virtual Zcad::ErrorStatus   getGripPoints(
		ZcGePoint3dArray&  gripPoints,
		ZcDbIntArray &     osnapModes,
		ZcDbIntArray &  geomIds) const;
};

class ZcDbViewport: public ZcDbEntity
{
public:
                      ZcDbViewport();
                      ~ZcDbViewport();
    ZCDB_DECLARE_MEMBERS(ZcDbViewport);



    Zcad::ErrorStatus setModelView      (const ZcDbXrefObjectId &xrefObjId);
    Zcad::ErrorStatus getModelView      (ZcDbXrefObjectId &xrefObjId) const;
    Zcad::ErrorStatus removeModelView   (void);

    Zcad::ErrorStatus setSheetView      (ZcDbObjectId objId);
    Zcad::ErrorStatus getSheetView      (ZcDbObjectId &objId)const;
    Zcad::ErrorStatus removeSheetView   (void);

    Zcad::ErrorStatus setLabelBlock     (ZcDbObjectId objId);
    Zcad::ErrorStatus getLabelBlock     (ZcDbObjectId &objId)const;
    Zcad::ErrorStatus removeLabelBlock  (void);

    Zcad::ErrorStatus syncModelView     (void);


#ifdef _WINDOWS_
    Zcad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
    Zcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
#endif
 

    double            height() const;
    Zcad::ErrorStatus setHeight(double);

    double            width() const;
    Zcad::ErrorStatus setWidth(double);

    ZcGePoint3d       centerPoint() const;
    Zcad::ErrorStatus setCenterPoint(const ZcGePoint3d&);

    Zdesk::Int16      number() const;

    bool              isOn() const;
    Zcad::ErrorStatus setOn();
    Zcad::ErrorStatus setOff();

    ZcGePoint3d       viewTarget() const;
    Zcad::ErrorStatus setViewTarget(const ZcGePoint3d&); 

    ZcGeVector3d      viewDirection() const;
    Zcad::ErrorStatus setViewDirection(const ZcGeVector3d&);


    double            viewHeight() const;
    Zcad::ErrorStatus setViewHeight(double ht);

    ZcGePoint2d       viewCenter() const;
    Zcad::ErrorStatus setViewCenter(const ZcGePoint2d& pt);

    double            twistAngle() const;
    Zcad::ErrorStatus setTwistAngle(double);

    double            lensLength() const;
    Zcad::ErrorStatus setLensLength(double);

    bool              isFrontClipOn() const;
    Zcad::ErrorStatus setFrontClipOn();
    Zcad::ErrorStatus setFrontClipOff();

    bool              isBackClipOn() const;
    Zcad::ErrorStatus setBackClipOn();
    Zcad::ErrorStatus setBackClipOff();

    bool              isFrontClipAtEyeOn() const;
    Zcad::ErrorStatus setFrontClipAtEyeOn();
    Zcad::ErrorStatus setFrontClipAtEyeOff();


    double            frontClipDistance() const;
    Zcad::ErrorStatus setFrontClipDistance(double newVal);


    double            backClipDistance() const;
    Zcad::ErrorStatus setBackClipDistance(double newVal);

    bool              isPerspectiveOn() const;
    Zcad::ErrorStatus setPerspectiveOn();
    Zcad::ErrorStatus setPerspectiveOff();

    bool              isUcsFollowModeOn() const;
    Zcad::ErrorStatus setUcsFollowModeOn();
    Zcad::ErrorStatus setUcsFollowModeOff();

    bool              isUcsIconVisible() const;
    Zcad::ErrorStatus setUcsIconVisible();
    Zcad::ErrorStatus setUcsIconInvisible();

    bool              isUcsIconAtOrigin() const;
    Zcad::ErrorStatus setUcsIconAtOrigin();
    Zcad::ErrorStatus setUcsIconAtCorner();

    bool              isFastZoomOn() const { return true; }
    Zcad::ErrorStatus setFastZoomOn() { return Zcad::eOk; }
    Zcad::ErrorStatus setFastZoomOff() { return Zcad::eOk; }

    Zdesk::UInt16     circleSides() const;
    Zcad::ErrorStatus setCircleSides(Zdesk::UInt16);

    bool              isSnapOn() const;
    Zcad::ErrorStatus setSnapOn();
    Zcad::ErrorStatus setSnapOff();

    bool              isSnapIsometric() const;
    Zcad::ErrorStatus setSnapIsometric();
    Zcad::ErrorStatus setSnapStandard();

    double            snapAngle() const;
    Zcad::ErrorStatus setSnapAngle(double);

    ZcGePoint2d       snapBasePoint() const;
    Zcad::ErrorStatus setSnapBasePoint(const ZcGePoint2d&); 

    ZcGeVector2d      snapIncrement() const;
    Zcad::ErrorStatus setSnapIncrement(const ZcGeVector2d&);

    Zdesk::UInt16     snapIsoPair() const;
    Zcad::ErrorStatus setSnapIsoPair(Zdesk::UInt16);

    bool              isGridOn() const;
    Zcad::ErrorStatus setGridOn();
    Zcad::ErrorStatus setGridOff();

    bool              isGridBoundToLimits() const;
    Zcad::ErrorStatus setGridBoundToLimits(bool bNewVal);

    bool              isGridAdaptive() const;
    Zcad::ErrorStatus setGridAdaptive(bool bNewVal);

    bool              isGridSubdivisionRestricted() const;
    Zcad::ErrorStatus setGridSubdivisionRestricted(bool bNewVal);

    bool              isGridFollow() const;
    Zcad::ErrorStatus setGridFollow(bool bNewVal);

    Zdesk::UInt16     gridMajor() const;
    Zcad::ErrorStatus setGridMajor(Zdesk::UInt16);

    ZcGeVector2d      gridIncrement() const;
    Zcad::ErrorStatus setGridIncrement(const ZcGeVector2d&);

    bool              hiddenLinesRemoved() const;
    Zcad::ErrorStatus showHiddenLines();
    Zcad::ErrorStatus removeHiddenLines();

    Zcad::ErrorStatus freezeLayersInViewport(const ZcDbObjectIdArray&);
    Zcad::ErrorStatus thawLayersInViewport(const ZcDbObjectIdArray&);
    Zcad::ErrorStatus thawAllLayersInViewport();
    bool              isLayerFrozenInViewport(const ZcDbObjectId& layerId) const;
    Zcad::ErrorStatus getFrozenLayerList(ZcDbObjectIdArray& ids) const;
    
    Zcad::ErrorStatus updateDisplay() const;

    ZcDbObjectId       background() const;
    Zcad::ErrorStatus  setBackground(ZcDbObjectId backgroundId);           
    ZcDbObjectId       previousBackground(ZcGiDrawable::DrawableType type
                                          = ZcGiDrawable::kGeometry) const;
    Zcad::ErrorStatus  setPreviousBackground(ZcDbObjectId backgroundId,
                                             ZcGiDrawable::DrawableType type
                                             = ZcGiDrawable::kGeometry);


    ZcDbObjectId      visualStyle() const;
    Zcad::ErrorStatus setVisualStyle(const ZcDbObjectId oidVisualStyle);


    bool                isDefaultLightingOn() const;
    Zcad::ErrorStatus   setDefaultLightingOn(bool on);
    ZcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Zcad::ErrorStatus   setDefaultLightingType(ZcGiViewportTraits::DefaultLightingType typ);


    double              brightness() const;
    Zcad::ErrorStatus   setBrightness(double);

    double              contrast() const;
    Zcad::ErrorStatus   setContrast(double);

    ZcCmColor           ambientLightColor() const;
    Zcad::ErrorStatus   setAmbientLightColor(const ZcCmColor& clr);


    ZcDbObjectId        sunId() const;
    Zcad::ErrorStatus   setSun(ZcDbObjectId& retId, ZcDbObject* pSun);


    virtual Zdesk::UInt32     setAttributes(ZcGiDrawableTraits*);
    virtual Zdesk::Boolean    worldDraw   (ZcGiWorldDraw* pWd);

    bool              isLocked() const;
    Zcad::ErrorStatus setLocked();
    Zcad::ErrorStatus setUnlocked();

    Zcad::ErrorStatus setAnnotationScale(const ZcDbAnnotationScale *pScaleObj);

    ZcDbAnnotationScale* annotationScale() const;

    bool              isTransparent() const;
    Zcad::ErrorStatus setTransparent();
    Zcad::ErrorStatus setOpaque();
    
    enum StandardScaleType {
        kScaleToFit,        // Scaled to Fit
        kCustomScale,       // Scale is not a standard scale
        k1_1,               // 1:1
        k1_2,               // 1:2
        k1_4,               // 1:4
        k1_8,               // 1:8
        k1_10,              // 1:10
        k1_16,              // 1:16
        k1_20,              // 1:20
        k1_30,              // 1:30
        k1_40,              // 1:40
        k1_50,              // 1:50
        k1_100,             // 1:100
        k2_1,               // 2:1
        k4_1,               // 4:1
        k8_1,               // 8:1
        k10_1,              // 10:1
        k100_1,             // 100:1
        k1_128in_1ft,       // 1/128"= 1'
        k1_64in_1ft,        // 1/64"= 1'
        k1_32in_1ft,        // 1/32"= 1'
        k1_16in_1ft,        // 1/16"= 1'
        k3_32in_1ft,        // 3/32"= 1'
        k1_8in_1ft,         // 1/8" = 1'
        k3_16in_1ft,        // 3/16"= 1'
        k1_4in_1ft,         // 1/4" = 1'
        k3_8in_1ft,         // 3/8" = 1'
        k1_2in_1ft,         // 1/2" = 1'
        k3_4in_1ft,         // 3/4" = 1'
        k1in_1ft,           // 1"= 1'
        k1and1_2in_1ft,     // 1 1/2"= 1'
        k3in_1ft,           // 3"= 1'
        k6in_1ft,           // 6"= 1'
        k1ft_1ft            // 1'= 1'
    };

    double            customScale() const;
    Zcad::ErrorStatus setCustomScale(double);

    StandardScaleType standardScale() const;
    Zcad::ErrorStatus setStandardScale(const StandardScaleType);

    Zcad::ErrorStatus plotStyleSheet(ZCHAR *&) const;
    Zcad::ErrorStatus plotStyleSheet(const ZCHAR *&) const;
    Zcad::ErrorStatus effectivePlotStyleSheet(const ZCHAR *&);
    Zcad::ErrorStatus setPlotStyleSheet(const ZCHAR *);

    bool              isNonRectClipOn() const;
    Zcad::ErrorStatus setNonRectClipOn();
    Zcad::ErrorStatus setNonRectClipOff();

    ZcDbObjectId      nonRectClipEntityId() const;
    Zcad::ErrorStatus setNonRectClipEntityId(ZcDbObjectId);

    virtual void      erased(const ZcDbObject* , Zdesk::Boolean);
    virtual void      modified(const ZcDbObject *);
    virtual void      copied(const ZcDbObject* pDbObj,const ZcDbObject* pNewObj);
    virtual void      subObjModified(const ZcDbObject* pDbObj, 
                            const ZcDbObject* pSubObj);


    Zcad::ErrorStatus getUcs (ZcGePoint3d& origin,
                                ZcGeVector3d& xAxis,
                                ZcGeVector3d& yAxis ) const;
    bool              isUcsOrthographic(ZcDb::OrthographicView& view) const;
    ZcDbObjectId      ucsName           () const;
    double            elevation         () const;


    Zcad::ErrorStatus setUcs(const ZcGePoint3d& origin,
                                const ZcGeVector3d& xAxis,
                                const ZcGeVector3d& yAxis);
    Zcad::ErrorStatus setUcs(ZcDb::OrthographicView view);
    Zcad::ErrorStatus setUcs(const ZcDbObjectId& ucsId);
    Zcad::ErrorStatus setUcsToWorld();
    Zcad::ErrorStatus setElevation(double elev );
 

    bool           isViewOrthographic(ZcDb::OrthographicView& view ) const;
    Zcad::ErrorStatus setViewDirection(ZcDb::OrthographicView view );


    bool           isUcsSavedWithViewport () const;
    void           setUcsPerViewport ( bool ucsvp );


    void setRenderMode(ZcDbAbstractViewTableRecord::RenderMode mode);
    ZcDbAbstractViewTableRecord::RenderMode renderMode() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;


    enum ShadePlotType {
        kAsDisplayed    = 0,
        kWireframe      = 1,
        kHidden         = 2,
        kRendered       = 3,
        kVisualStyle    = 4,
        kRenderPreset   = 5
    };

    ShadePlotType     shadePlot() const;
    Zcad::ErrorStatus setShadePlot(const ShadePlotType);

    ZcDbObjectId      shadePlotId() const;
    Zcad::ErrorStatus setShadePlot(const ShadePlotType type,
                                   const ZcDbObjectId shadePlotId);

    bool              plotWireframe() const;
    bool              plotAsRaster()  const;

    Zcad::ErrorStatus toneOperatorParameters(ZcGiToneOperatorParameters& params) const;
    Zcad::ErrorStatus setToneOperatorParameters(const ZcGiToneOperatorParameters& params);

	virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* filer) const;
	

	 virtual Zcad::ErrorStatus   getGripPoints(
                                        ZcGePoint3dArray&   gripPoints,
                                        ZcDbIntArray&       osnapModes,
                                        ZcDbIntArray &   geomIds
                                ) const;
    virtual Zcad::ErrorStatus   moveGripPointsAt(
                                        const ZcDbIntArray& indices,
                                        const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus   getStretchPoints(
                                    ZcGePoint3dArray&  stretchPoints
                                ) const;
    virtual Zcad::ErrorStatus   moveStretchPointsAt(
                                        const ZcDbIntArray& indices,
                                        const ZcGeVector3d& offset
                                );
    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);   
	 virtual Zcad::ErrorStatus   getGeomExtents(ZcDbExtents& extents) const;
	 void viewportDraw(ZcGiViewportDraw* pVpDraw);

};

#pragma pack(pop)

#endif
