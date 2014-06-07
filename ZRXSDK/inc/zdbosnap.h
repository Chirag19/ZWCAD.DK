#ifndef _ZDBOSNAP_H
#define _ZDBOSNAP_H

#include "Zdesk.h"

#pragma warning (disable: 4786)

#pragma pack (push, 8)

class ZcDbCustomOsnapInfo : public ZcRxObject {
public:
    ZCRX_DECLARE_MEMBERS(ZcDbCustomOsnapInfo);

virtual Zcad::ErrorStatus   getOsnapInfo(
                           ZcDbEntity*           pickedObject,
                           Zdesk::GsMarker       gsSelectionMark,
                           const ZcGePoint3d&    pickPoint,
                           const ZcGePoint3d&    lastPoint,
                           const ZcGeMatrix3d&   viewXform,
                           ZcArray<ZcGePoint3d>& snapPoints,
                           ZcDbIntArray &     geomIdsForPts,
                           ZcArray<ZcGeCurve3d*>& snapCurves,
                           ZcDbIntArray &     geomIdsForLines) = 0;
};

class ZcGiGlyph : public ZcGiDrawable
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiGlyph);

    virtual Zcad::ErrorStatus setLocation(const ZcGePoint3d& dcsPoint) = 0;

    virtual Zdesk::UInt32   setAttributes(ZcGiDrawableTraits*)
                         { return 0; }

    virtual Zdesk::Boolean  worldDraw(ZcGiWorldDraw*) {return Zdesk::kFalse;};

    virtual void            viewportDraw(ZcGiViewportDraw* vportDrawContext) = 0;

    virtual Zdesk::Boolean  isPersistent() const {return Zdesk::kFalse;}
    virtual ZcDbObjectId    id() const           {return 0;}
    virtual void            setGsNode(ZcGsNode*) {  }
    virtual ZcGsNode*       gsNode() const       { return NULL; }
};

class ZcDbCustomOsnapMode {
  public:
    virtual const ZCHAR * localModeString() const = 0;
    virtual const ZCHAR * globalModeString() const = 0;

    virtual const ZcRxClass* entityOsnapClass() const = 0;

    virtual ZcGiGlyph* glyph() const = 0;

    virtual const ZCHAR *               tooltipString() const = 0;
    virtual ~ZcDbCustomOsnapMode() {}
};

class ZcDbCustomOsnapManager {
public:

    virtual Zcad::ErrorStatus addCustomOsnapMode(ZcDbCustomOsnapMode* pMode) = 0;

    virtual Zcad::ErrorStatus removeCustomOsnapMode(ZcDbCustomOsnapMode* pMode) = 0;

    virtual Zcad::ErrorStatus activateOsnapMode(const ZCHAR * modeStr) = 0;

    virtual Zcad::ErrorStatus deactivateOsnapMode(const ZCHAR * modeStr) = 0;

    virtual Zdesk::Boolean modeIsActive(const ZCHAR * modeStr) = 0;

    virtual int osnapGlyphSize() const = 0;
};


ZcDbCustomOsnapManager* zcdbCustomOsnapManager();

#pragma pack (pop)

#endif