

#pragma once


#include "zdbmain.h"
#include "zcgi.h"

#pragma pack (push, 8)


const ZCHAR kszVSFlat[]                 = ZCRX_T("Flat");
const ZCHAR kszVSFlatWithEdges[]        = ZCRX_T("FlatWithEdges");
const ZCHAR kszVSGouraud[]              = ZCRX_T("Gouraud");
const ZCHAR kszVSGouraudWithEdges[]     = ZCRX_T("GouraudWithEdges");


const ZCHAR kszVS2DWireframe[]   = ZCRX_T("2dWireframe");
const ZCHAR kszVS3DWireframe[]   = ZCRX_T("3dWireframe");
const ZCHAR kszVSBasic[]         = ZCRX_T("Basic");
const ZCHAR kszVSHidden[]        = ZCRX_T("3D Hidden");
const ZCHAR kszVSRealistic[]     = ZCRX_T("Realistic");
const ZCHAR kszVSConceptual[]    = ZCRX_T("Conceptual");
const ZCHAR kszVSCustom[]        = ZCRX_T("Custom");


const ZCHAR kszVSDim[]           = ZCRX_T("Dim");
const ZCHAR kszVSBrighten[]      = ZCRX_T("Brighten");
const ZCHAR kszVSThicken[]       = ZCRX_T("Thicken");
const ZCHAR kszVSTransparent[]   = ZCRX_T("Transparent");
const ZCHAR kszVSLinePattern[]   = ZCRX_T("Linepattern");
const ZCHAR kszVSFacePattern[]   = ZCRX_T("Facepattern");
const ZCHAR kszVSColorChange[]   = ZCRX_T("ColorChange");


class ZcDbVisualStyle : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbVisualStyle);


    ZcDbVisualStyle();


    virtual ~ZcDbVisualStyle();


    Zcad::ErrorStatus   setDescription (const ZCHAR* pDescription);

    const ZCHAR*        description    (void) const;


    Zcad::ErrorStatus setType(ZcGiVisualStyle::Type type);

    ZcGiVisualStyle::Type type() const;

    void setFaceStyle(const ZcGiFaceStyle& faceStyle);

    const ZcGiFaceStyle& faceStyle() const;
    

    void setEdgeStyle(const ZcGiEdgeStyle& edgeStyle);

    const ZcGiEdgeStyle& edgeStyle() const;


    Zcad::ErrorStatus setDisplayStyle(const ZcGiDisplayStyle& displayStyle);

    const ZcGiDisplayStyle& displayStyle() const;


    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);

    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);

    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;


    virtual ZcGiDrawable*     drawable     (void);

    virtual void              setGsNode    (ZcGsNode* pNode);

    virtual ZcGsNode*         gsNode       (void) const;

    virtual Zdesk::UInt32     setAttributes (ZcGiDrawableTraits* pTraits);

    virtual bool              isInternalUseOnly() const;

    virtual void              setInternalUseOnly(bool bInternalUseOnly);


    virtual Zcad::ErrorStatus copyTo(ZcGiVisualStyle * pDest) const;

    virtual Zcad::ErrorStatus copyFrom(const ZcGiVisualStyle * pSrc);

    virtual Zcad::ErrorStatus decomposeForSave(
                                  ZcDb::ZcDbDwgVersion ver,
                                  ZcDbObject*&         replaceObj,
                                  ZcDbObjectId&        replaceId,
                                  Zdesk::Boolean&      exchangeXData);

};

#pragma pack (pop)


