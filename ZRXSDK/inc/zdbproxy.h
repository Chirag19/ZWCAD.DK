#ifndef ZD_DBPROXY_H
#define ZD_DBPROXY_H 1

#include "zdbmain.h"
#include "zdbintar.h"

#pragma pack (push, 8)

class ZDESK_NO_VTABLE ZcDbProxyObject : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbProxyObject);
    
    virtual ~ZcDbProxyObject();
    
    virtual int   proxyFlags() const = 0;
    virtual const ZCHAR * originalClassName() const = 0;
    virtual const ZCHAR * originalDxfName() const = 0;
    virtual const ZCHAR * applicationDescription() const = 0;
    virtual Zcad::ErrorStatus getReferences(ZcDbObjectIdArray&,
        ZcDbIntArray&) const = 0;

    virtual ZcDb::DuplicateRecordCloning mergeStyle() const = 0;

    enum {kNoOperation          = 0,
          kEraseAllowed         = 0x01,
          kCloningAllowed       = 0x80,
          kAllButCloningAllowed = 0x01,
          kAllAllowedBits       = 0x81,
          kMergeIgnore          = 0,      
          kMergeReplace         = 0x100,  
          kMergeMangleName      = 0x200,  
          kDisableProxyWarning  = 0x400
           };
};

class ZDESK_NO_VTABLE ZcDbProxyEntity : public ZcDbEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbProxyEntity);
    
    virtual ~ZcDbProxyEntity();
    
    virtual int   proxyFlags() const = 0;
    virtual const ZCHAR * originalClassName() const = 0;
    virtual const ZCHAR * originalDxfName() const = 0;
    virtual const ZCHAR * applicationDescription() const = 0;
    virtual Zcad::ErrorStatus getReferences(ZcDbObjectIdArray&,
        ZcDbIntArray&) const = 0;

    enum GraphicsMetafileType {
        kNoMetafile   = 0,
        kBoundingBox  = 1,
        kFullGraphics = 2 };

    virtual ZcDbProxyEntity::GraphicsMetafileType graphicsMetafileType()
        const = 0;

    virtual Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   getGeomExtents(ZcDbExtents& extents) const;
	virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* pfiler);
	virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* pFiler) const;
	virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* pfiler);
	virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* pFiler) const;
	virtual Zcad::ErrorStatus	setColor(const ZcCmColor &color,Zdesk::Boolean dosubent = true);
	virtual Zcad::ErrorStatus	setColorIndex(Zdesk::UInt16 colorIndex,Zdesk::Boolean dosubents = true);
	virtual Zcad::ErrorStatus	setColorId(ZcDbObjectId colorId,Zdesk::Boolean dosubents = true);
	virtual Zcad::ErrorStatus	setPlotStyleName(const ZcString& plotStyleName,Zdesk::Boolean doSubents = true);
	virtual Zcad::ErrorStatus	setPlotStyleName(ZcDb::PlotStyleNameType,
                                ZcDbObjectId newId = ZcDbObjectId::kNull,
                                Zdesk::Boolean doSubents = true);
	virtual Zcad::ErrorStatus   setLayer(const ZCHAR* newVal,
                                  Zdesk::Boolean doSubents = true,
                                  bool allowHiddenLayer = false);
    virtual Zcad::ErrorStatus   setLayer(ZcDbObjectId newVal,
                                  Zdesk::Boolean doSubents = true,
                                  bool allowHiddenLayer = false);
	virtual Zcad::ErrorStatus   setLinetype(const ZCHAR* newVal,
                                  Zdesk::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setLinetype(ZcDbObjectId newVal,
                                  Zdesk::Boolean doSubents = true);
	virtual Zcad::ErrorStatus   setLinetypeScale(double newval,
                                  Zdesk::Boolean doSubents = true);
	virtual Zcad::ErrorStatus   setVisibility(ZcDb::Visibility newVal,
                                  Zdesk::Boolean doSubents = true);
	virtual Zcad::ErrorStatus   setLineWeight(ZcDb::LineWeight newVal,
                                  Zdesk::Boolean doSubents = true);
	virtual Zcad::ErrorStatus   subErase(Zdesk::Boolean erasing);
    enum  {kNoOperation                = 0,
           kEraseAllowed               = 0x1,
           kTransformAllowed           = 0x2,
           kColorChangeAllowed         = 0x4,
           kLayerChangeAllowed         = 0x8,
           kLinetypeChangeAllowed      = 0x10,
           kLinetypeScaleChangeAllowed = 0x20,
           kVisibilityChangeAllowed    = 0x40,
           kCloningAllowed             = 0x80,
           kLineWeightChangeAllowed    = 0x100,
           kPlotStyleNameChangeAllowed = 0x200,
           kAllButCloningAllowed       = 0x37F,
           kAllAllowedBits             = 0xBFF,
           kDisableProxyWarning        = 0x400,
           kMaterialChangeAllowed      = 0x800,
            };
};

#pragma pack (pop)

#endif // ZD_DBPROXY_H
