#ifndef ZDBFCF_H
#define ZDBFCF_H


#include "zdbmain.h"

#pragma pack(push, 8)

class ZcDbFcf: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbFcf);
                              ZcDbFcf();
                              ZcDbFcf(const ZCHAR *, const ZcGePoint3d&,
                              const ZcGeVector3d&, const ZcGeVector3d&);
    virtual ~ZcDbFcf();


    virtual Zcad::ErrorStatus getGripPoints   (ZcGePoint3dArray&,
                                               ZcDbIntArray&,
                                               ZcDbIntArray&) const;
    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray&,
                                               const ZcGeVector3d&);
    virtual void              list            () const;


    
    enum whichLine {kAll = -1};
    virtual void              setText          (const ZCHAR *);
    virtual ZCHAR *           text             (const int lineNo = kAll) const;
    virtual void              setLocation      (const ZcGePoint3d&);
    virtual ZcGePoint3d       location         () const;
    virtual void              setOrientation   (const ZcGeVector3d& norm,
                                                const ZcGeVector3d& dir);
    virtual ZcGeVector3d normal()    const;
    virtual ZcGeVector3d direction() const;
    
    virtual void getBoundingPoints(ZcGePoint3dArray&) const;
    virtual void getBoundingPline(ZcGePoint3dArray&)  const;
    
    virtual void              setDimensionStyle(ZcDbHardPointerId);
    virtual ZcDbHardPointerId dimensionStyle() const;
    
    Zcad::ErrorStatus   getDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;
    Zcad::ErrorStatus   setDimstyleData(ZcDbDimStyleTableRecord* pNewData);
    Zcad::ErrorStatus   setDimstyleData(ZcDbObjectId newDataId);

    virtual void        setDimVars();


    ZcCmColor      dimclrd () const;
    ZcCmColor      dimclrt () const;
    double         dimgap  () const;
    double         dimscale() const;
    ZcDbObjectId   dimtxsty() const;
    double         dimtxt  () const;


    Zcad::ErrorStatus setDimclrd (ZcCmColor&     val);
    Zcad::ErrorStatus setDimclrt (ZcCmColor&     val);
    Zcad::ErrorStatus setDimgap  (double         val);
    Zcad::ErrorStatus setDimscale(double         val);
    Zcad::ErrorStatus setDimtxsty(ZcDbObjectId   val);
    Zcad::ErrorStatus setDimtxt  (double         val);


    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

    virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw*        mode);
    virtual void                viewportDraw(ZcGiViewportDraw*  mode);

    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   transformBy(const ZcGeFastTransform& xform);


    virtual Zcad::ErrorStatus  getGripPoints( ZcDbGripDataPtrArray& grips,
                                               const double curViewUnitSize, const int gripSize, 
                                               const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual  Zcad::ErrorStatus moveGripPointsAt( const ZcDbVoidPtrArray& gripAppData,
											     const ZcGeVector3d& offset, const int bitflags);
    
    virtual Zcad::ErrorStatus  getStretchPoints( ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus  moveStretchPointsAt(const ZcDbIntArray & indices, const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;
};

#pragma pack(pop)

#endif
