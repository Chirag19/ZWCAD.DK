#ifndef ZCDB_DBUNDERLAYREF_H
#define ZCDB_DBUNDERLAYREF_H
#pragma once


#include "zdbmain.h"
#include "zcstring.h"

#pragma pack (push, 8)

class ZcUnderlayLayer;


class ZDESK_NO_VTABLE ZcDbUnderlayReference: public ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUnderlayReference);


	ZcDbUnderlayReference()
	{

	}

    virtual ~ZcDbUnderlayReference() = 0;

    ZcGePoint3d       position() const;

    Zcad::ErrorStatus setPosition(const ZcGePoint3d& position);

    ZcGeScale3d       scaleFactors() const;

    Zcad::ErrorStatus setScaleFactors(const ZcGeScale3d& scale);

    double            rotation() const;

    Zcad::ErrorStatus setRotation(double rotation);

    ZcGeVector3d      normal() const;

    Zcad::ErrorStatus setNormal(const ZcGeVector3d& normal);

    ZcGeMatrix3d transform() const;

    Zcad::ErrorStatus setTransform(const ZcGeMatrix3d& transform);

    ZcDbObjectId      definitionId() const;

    Zcad::ErrorStatus setDefinitionId(ZcDbObjectId id);

    const ZcGePoint2dArray&  clipBoundary() const;

    Zcad::ErrorStatus        setClipBoundary(const ZcGePoint2dArray& clipBoundary);

	bool                     isClipped() const;

    Zcad::ErrorStatus        setIsClipped(bool value);

    Zdesk::UInt8      contrast() const;

    Zcad::ErrorStatus setContrast(Zdesk::UInt8 value);

    Zdesk::UInt8      fade() const;

    Zcad::ErrorStatus setFade(Zdesk::UInt8 value);

    bool              isOn() const;

    Zcad::ErrorStatus setIsOn(bool value);

    bool              isMonochrome() const;

    Zcad::ErrorStatus setIsMonochrome(bool value);

    bool              isAdjustedForBackground() const;

    Zcad::ErrorStatus setIsAdjustedForBackground(bool value);

    virtual bool isFrameVisible() const;

    virtual bool isFramePlottable() const;

    virtual bool isContentSnappable() const;

    Zdesk::UInt32 underlayLayerCount() const;

    Zcad::ErrorStatus getUnderlayLayer(int index, ZcUnderlayLayer& layer) const;

    Zcad::ErrorStatus setUnderlayLayer(int index, const ZcUnderlayLayer& layer);

    static Zdesk::UInt8 contrastLowerLimit();

    static Zdesk::UInt8 contrastUpperLimit();

    static Zdesk::UInt8 contrastDefault();

    static Zdesk::UInt8 fadeLowerLimit();

    static Zdesk::UInt8 fadeUpperLimit();

    static Zdesk::UInt8 fadeDefault();
};


class ZcDbDwfReference: public ZcDbUnderlayReference
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDwfReference);

    ZcDbDwfReference();

    virtual ~ZcDbDwfReference();

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};


class ZcDbDgnReference: public ZcDbUnderlayReference
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDgnReference);

    ZcDbDgnReference();

    virtual ~ZcDbDgnReference();

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    void setXrefDepth(int depth);
};

#pragma pack (pop)

#endif
