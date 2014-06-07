#ifndef ZD_DBMTEXT_H
#define ZD_DBMTEXT_H

#include "zdbmain.h"

#pragma pack(push, 8)

struct ZcDbMTextFragment
{
    ZcGePoint3d  location;
    ZcGeVector3d normal;
    ZcGeVector3d direction;

    ZCHAR*        text;

    ZCHAR*        font;
    ZCHAR*        bigfont;

    ZcGePoint2d  extents;
    double       capsHeight;
    double       widthFactor;
    double       obliqueAngle;
    double       trackingFactor;
    ZcCmEntityColor color;

    unsigned stackTop:1;
    unsigned stackBottom:1;

    unsigned    underlined:1;
    unsigned    overlined:1;
    ZcGePoint3d underPoints[2];
    ZcGePoint3d overPoints[2];

    ZCHAR *  fontname;
    bool    bold;
    bool    italic;
};

typedef int (*ZcDbMTextEnum)(ZcDbMTextFragment *, void *);

class ZcDbText;

class ZcDbMText: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbMText);
    ZcDbMText();
    ~ZcDbMText();

    ZcGePoint3d     location() const;
    Zcad::ErrorStatus   setLocation(const ZcGePoint3d&);

    ZcGeVector3d    normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    ZcGeVector3d    direction() const;
    Zcad::ErrorStatus   setDirection(const ZcGeVector3d&);

    double      rotation() const;
    Zcad::ErrorStatus   setRotation(double);

    double      width() const;
    Zcad::ErrorStatus   setWidth(double);

    double      ascent() const;
    double      descent() const;

    ZcDbObjectId        textStyle() const;
    Zcad::ErrorStatus   setTextStyle(ZcDbObjectId);

    double      textHeight() const;
    Zcad::ErrorStatus   setTextHeight(double);

    enum AttachmentPoint {
    kTopLeft    = 1,
    kTopCenter  = 2,
    kTopRight   = 3,
    kMiddleLeft = 4,
    kMiddleCenter   = 5,
    kMiddleRight    = 6,
    kBottomLeft = 7,
    kBottomCenter   = 8,
    kBottomRight    = 9,
    kBaseLeft       = 10,
    kBaseCenter     = 11,
    kBaseRight      = 12,
    kBaseAlign      = 13,
    kBottomAlign    = 14,
    kMiddleAlign    = 15,
    kTopAlign       = 16,
    kBaseFit        = 17,
    kBottomFit      = 18,
    kMiddleFit      = 19,
    kTopFit         = 20,
    kBaseMid        = 21,
    kBottomMid      = 22,
    kMiddleMid      = 23,
    kTopMid         = 24,
    };
    AttachmentPoint attachment() const;
    Zcad::ErrorStatus   setAttachment(AttachmentPoint);
    Zcad::ErrorStatus   setAttachmentMovingLocation(AttachmentPoint);

    enum FlowDirection {
    kLtoR       = 1,
    kRtoL       = 2,
    kTtoB       = 3,
    kBtoT       = 4,
    kByStyle    = 5
    };
    FlowDirection   flowDirection() const;
    Zcad::ErrorStatus   setFlowDirection(FlowDirection);

    ZCHAR        *contents() const;
    int         setContents(const ZCHAR *);
    int         setContentsRTF(const ZCHAR *);

    ZCHAR        *text() const;

    double      actualHeight(ZcGiWorldDraw *ctxt = NULL) const;
    double      actualWidth() const;

    int         correctSpelling();

    void        getBoundingPoints(ZcGePoint3dArray&) const;

    void        explodeFragments(ZcDbMTextEnum, void *, ZcGiWorldDraw *ctxt = NULL) const;

    static const ZCHAR* const nonBreakSpace();
    static const ZCHAR* const overlineOn();
    static const ZCHAR* const overlineOff();
    static const ZCHAR* const underlineOn();
    static const ZCHAR* const underlineOff();
    static const ZCHAR* const colorChange();
    static const ZCHAR* const fontChange();
    static const ZCHAR* const heightChange();
    static const ZCHAR* const widthChange();
    static const ZCHAR* const obliqueChange();
    static const ZCHAR* const trackChange();
    static const ZCHAR* const lineBreak();
    static const ZCHAR* const paragraphBreak();
    static const ZCHAR* const stackStart();
    static const ZCHAR* const alignChange();
    static const ZCHAR* const blockBegin();
    static const ZCHAR* const blockEnd();

    Zcad::ErrorStatus   setLineSpacingStyle(ZcDb::LineSpacingStyle eStyle);
    ZcDb::LineSpacingStyle lineSpacingStyle() const;

    Zcad::ErrorStatus   setLineSpacingFactor(double dFactor);
    double              lineSpacingFactor() const;
    
    void                getEcs(ZcGeMatrix3d& retVal) const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    bool backgroundFillOn() const;
    Zcad::ErrorStatus setBackgroundFill(bool enable);

    Zcad::ErrorStatus getBackgroundFillColor(ZcCmColor& color) const;
    Zcad::ErrorStatus setBackgroundFillColor(const ZcCmColor& color);

    Zcad::ErrorStatus getBackgroundScaleFactor(double& scale) const;
    Zcad::ErrorStatus setBackgroundScaleFactor(const double scale);

    Zcad::ErrorStatus getBackgroundTransparency(ZcCmTransparency& transp) const;
    Zcad::ErrorStatus setBackgroundTransparency(const ZcCmTransparency& transp);

    bool useBackgroundColorOn() const;
    Zcad::ErrorStatus setUseBackgroundColor(bool enable);
    
    Zcad::ErrorStatus   setField(const ZCHAR* pszPropName, ZcDbField* pField,
                                 ZcDbObjectId& fieldId);

    Zcad::ErrorStatus   removeField(ZcDbObjectId fieldId);
    Zcad::ErrorStatus   removeField(const ZCHAR* pszPropName, ZcDbObjectId& returnId);
    Zcad::ErrorStatus   removeField(const ZCHAR* pszPropName);

    Zcad::ErrorStatus   convertFieldToText();

    enum ColumnType {
        kNoColumns,
        kStaticColumns,
        kDynamicColumns,
    };

    Zcad::ErrorStatus setDynamicColumns(double width, double gutter, bool auto_height);
    Zcad::ErrorStatus setStaticColumns(double width, double gutter, int count);
    Zcad::ErrorStatus getColumnType(ColumnType&) const;
    Zcad::ErrorStatus setColumnType(ColumnType);
    Zcad::ErrorStatus getColumnAutoHeight(bool&) const;
    Zcad::ErrorStatus setColumnAutoHeight(bool);
    Zcad::ErrorStatus getColumnCount(int&) const;
    Zcad::ErrorStatus setColumnCount(int);
    Zcad::ErrorStatus getColumnWidth(double&) const;
    Zcad::ErrorStatus setColumnWidth(double);
    Zcad::ErrorStatus getColumnGutterWidth(double&) const;
    Zcad::ErrorStatus setColumnGutterWidth(double);
    Zcad::ErrorStatus getColumnFlowReversed(bool&) const;
    Zcad::ErrorStatus setColumnFlowReversed(bool);
    Zcad::ErrorStatus getColumnHeight(int, double&) const;
    Zcad::ErrorStatus setColumnHeight(int, double);

    Zcad::ErrorStatus   setUseWordBreak(bool bEnable);
    bool useWordBreak() const;
    double      height() const;
    Zcad::ErrorStatus   setHeight(double);

    virtual Zcad::ErrorStatus   getGripPoints(
	ZcGePoint3dArray&  gripPoints,
	ZcDbIntArray &     osnapModes,
	ZcDbIntArray &  geomIds) const;
	
};

#pragma pack(pop)

#endif