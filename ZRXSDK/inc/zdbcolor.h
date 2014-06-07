
#ifndef ZD_DBCOLOR_H
#define ZD_DBCOLOR_H 1

#include "zdesk.h"
#include "zcadstrc.h"
#include <assert.h>

#pragma pack (push, 8)


class ZcCmEntityColor;



class ZcCmEntityColor
{
public:
    enum Color { kRed,
                 kGreen,
                 kBlue
    };


    enum ColorMethod {   kByLayer =0xC0, 
                         kByBlock,
                         kByColor,
                         kByACI,
                         kByPen,
                         kForeground,
                         kLayerOff,
                         kLayerFrozen,
                         kNone
    };

    enum ACIcolorMethod {kACIbyBlock    = 0,
                         kACIforeground = 7,
                         kACIbyLayer    = 256,
                         kACIclear      = 0,    
                         kACIstandard   = 7,
                         kACImaximum    = 255,
                         kACInone       = 257,
                         kACIminimum    = -255,
                         kACIfrozenLayer= -32700
    };

    union RGBM {
        Zdesk::UInt32    whole;
        Zdesk::Int16     indirect;
        struct {
            Zdesk::UInt8 blue, 
                         green, 
                         red, 
                         colorMethod;
        };
    };

    ZcCmEntityColor     ();
    ZcCmEntityColor     (const ZcCmEntityColor & color);
    ZcCmEntityColor     (const ColorMethod eColorMethod);
    ZcCmEntityColor     (const Zdesk::UInt8 red, 
                         const Zdesk::UInt8 green, 
                         const Zdesk::UInt8 blue);

    ZcCmEntityColor&    operator =  (const ZcCmEntityColor& color);
    bool                operator == (const ZcCmEntityColor& color) const;
    bool                operator != (const ZcCmEntityColor& color) const;



    Zcad::ErrorStatus   setColorMethod  (const ColorMethod eColorMethod);
    ColorMethod         colorMethod     () const;

    Zcad::ErrorStatus   setColor        (const Zdesk::UInt32 color);
    Zdesk::UInt32       color           () const;   

    Zcad::ErrorStatus   setColorIndex   (const Zdesk::Int16 colorIndex);
    Zdesk::Int16        colorIndex      () const;

    Zcad::ErrorStatus   setLayerIndex   (const Zdesk::Int16 layerIndex);
    Zdesk::Int16        layerIndex      () const;   

    Zcad::ErrorStatus   setPenIndex     (const Zdesk::UInt16 penIndex);
    Zdesk::UInt16       penIndex        () const;   


    Zcad::ErrorStatus   setRGB  (const Zdesk::UInt8 red, 
                                 const Zdesk::UInt8 green, 
                                 const Zdesk::UInt8 blue);
    Zcad::ErrorStatus   setRed  (const Zdesk::UInt8 red);
    Zcad::ErrorStatus   setGreen(const Zdesk::UInt8 green);
    Zcad::ErrorStatus   setBlue (const Zdesk::UInt8 blue);
    Zdesk::UInt8        red     () const;
    Zdesk::UInt8        green   () const;
    Zdesk::UInt8        blue    () const;


    bool                isByColor   () const;
    bool                isByLayer   () const;
    bool                isByBlock   () const;
    bool                isByACI     ()   const;
    bool                isByPen     ()  const;
    bool                isForeground() const;
    bool                isLayerOff  () const;

    bool                isLayerFrozen() const;
    bool                isNone      ()   const;
    bool                isLayerFrozenOrOff() const;


    Zdesk::UInt32       trueColor () const;
    Zdesk::UInt8        trueColorMethod () const;
    Zcad::ErrorStatus   setTrueColor ();
    Zcad::ErrorStatus   setTrueColorMethod ();




    static  Zcad::ErrorStatus   setColorMethod(RGBM* rgbm, const ColorMethod eColorMethod);
    static  ColorMethod         colorMethod   (const RGBM* rgbm);

    static  Zcad::ErrorStatus   setColor      (RGBM* rgbm, const Zdesk::UInt32 color);
    static  Zdesk::UInt32       color         (const RGBM* rgbm);   

    static  Zcad::ErrorStatus   setColorIndex (RGBM* rgbm, const Zdesk::Int16 colorIndex);
    static  Zdesk::Int16        colorIndex    (const RGBM* rgbm);

    static  Zcad::ErrorStatus   setLayerIndex (RGBM* rgbm, const Zdesk::Int16 layerIndex);
    static  Zdesk::Int16        layerIndex    (const RGBM* rgbm);   

    static  Zcad::ErrorStatus   setPenIndex   (RGBM* rgbm, const Zdesk::UInt16 penIndex);
    static  Zdesk::UInt16       penIndex      (const RGBM* rgbm);   


    static Zcad::ErrorStatus    setRGB  (RGBM* rgbm,
                                         const Zdesk::UInt8 red, 
                                         const Zdesk::UInt8 green, 
                                         const Zdesk::UInt8 blue);
    static Zcad::ErrorStatus    setRed  (RGBM* rgbm, const Zdesk::UInt8 red);
    static Zcad::ErrorStatus    setGreen(RGBM* rgbm, const Zdesk::UInt8 green);
    static Zcad::ErrorStatus    setBlue (RGBM* rgbm, const Zdesk::UInt8 blue);
    static Zdesk::UInt8         red     (const RGBM* rgbm);
    static Zdesk::UInt8         green   (const RGBM* rgbm);
    static Zdesk::UInt8         blue    (const RGBM* rgbm);


    static  bool                isByColor   (const RGBM* rgbm);
    static  bool                isByLayer   (const RGBM* rgbm);
    static  bool                isByBlock   (const RGBM* rgbm);
    static  bool                isByACI     (const RGBM* rgbm);
    static  bool                isByPen     (const RGBM* rgbm);
    static  bool                isForeground(const RGBM* rgbm);
    static  bool                isLayerOff  (const RGBM* rgbm);

    static  bool                isLayerFrozen(const RGBM* rgbm);
    static  bool                isNone      (const RGBM* rgbm);




    static Zdesk::UInt32        trueColor       (const RGBM* rgbm);
    static Zdesk::UInt8         trueColorMethod (const Zdesk::Int16);
    static Zcad::ErrorStatus    setTrueColor    (RGBM* rgbm);
    static Zcad::ErrorStatus    setTrueColorMethod (RGBM* rgbm);

    static Zdesk::UInt32        lookUpRGB       (const Zdesk::UInt8 colorIndex);
    static Zdesk::UInt8         lookUpACI       (const Zdesk::UInt8 red,
                                                 const Zdesk::UInt8 green,
                                                 const Zdesk::UInt8 blue); 

protected:
    Zcad::ErrorStatus           setIndirect (const Zdesk::Int16 Indirect);
    Zdesk::Int16                indirect() const;   
    RGBM mRGBM;

public:
    static const Zdesk::UInt8 mLUT[256][3]; 
};

#pragma pack (pop)


class ZDESK_NO_VTABLE ZcCmColorBase
{
public:

    virtual ~ZcCmColorBase() {}

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const = 0;;
    virtual Zcad::ErrorStatus   setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod) = 0;

    virtual bool                isByColor() const = 0;
    virtual bool                isByLayer() const = 0;
    virtual bool                isByBlock() const = 0;
    virtual bool                isByACI()   const = 0;
    virtual bool                isByPen () const = 0;
    virtual bool                isForeground()   const = 0;

    virtual Zdesk::UInt32       color() const = 0;
    virtual Zcad::ErrorStatus   setColor(Zdesk::UInt32 color) = 0;

    virtual Zcad::ErrorStatus   setRGB  (Zdesk::UInt8 red, 
                                         Zdesk::UInt8 green, 
                                         Zdesk::UInt8 blue) = 0;
    virtual Zcad::ErrorStatus   setRed  (Zdesk::UInt8 red) = 0;
    virtual Zcad::ErrorStatus   setGreen(Zdesk::UInt8 green) = 0;
    virtual Zcad::ErrorStatus   setBlue (Zdesk::UInt8 blue) = 0;
    virtual Zdesk::UInt8        red  () const = 0;
    virtual Zdesk::UInt8        green() const = 0;
    virtual Zdesk::UInt8        blue () const = 0;

    virtual Zdesk::UInt16       colorIndex() const = 0;
    virtual Zcad::ErrorStatus   setColorIndex(Zdesk::UInt16 colorIndex) = 0;
    virtual Zdesk::UInt16       penIndex() const = 0;
    virtual Zcad::ErrorStatus   setPenIndex (Zdesk::UInt16 penIndex) = 0;

    virtual Zcad::ErrorStatus   setNames(const ZCHAR *colorName,
                                         const ZCHAR *bookName = NULL) = 0;
    virtual const ZCHAR *       colorName(void) const = 0;
    virtual const ZCHAR *       bookName(void) const = 0;
    virtual const ZCHAR *       colorNameForDisplay(void) = 0;
    virtual bool                hasColorName(void) const = 0;
    virtual bool                hasBookName(void) const = 0;

};


class ZcCmTransparency {
public:

    enum transparencyMethod {
                kByLayer = 0,
                kByBlock,
                kByAlpha,


                kErrorValue     
            };


    enum {  kTransparencyByLayer    = (unsigned long)kByLayer,
            kTransparencyByBlock    = (unsigned long)kByBlock,
            kTransparencySolid      = ((unsigned long)(kByAlpha | (0xff << 24))),
            kTransparencyClear      = (unsigned long)kByAlpha
    };

    ZcCmTransparency() { mAM.method = kByLayer; }
    ZcCmTransparency(const ZcCmTransparency& other) { mAM.whole = other.mAM.whole; }
    ~ZcCmTransparency() {}

    ZcCmTransparency& operator=(const ZcCmTransparency& other);
    bool operator==(const ZcCmTransparency& other) const;
    bool operator!=(const ZcCmTransparency& other) const;

    void setAlpha(Zdesk::UInt8 alpha);
    void setMethod(transparencyMethod method);

    Zdesk::UInt8 alpha(void) const;
    bool isByAlpha(void) const { return (mAM.method == kByAlpha); }
    bool isByBlock(void) const { return (mAM.method == kByBlock); }
    bool isByLayer(void) const { return (mAM.method == kByLayer); }
    bool isClear(void) const;
    bool isSolid(void) const;

    Zdesk::UInt32   serializeOut(void) const { return mAM.whole; }
    void            serializeIn(Zdesk::UInt32);

private: 

    union AM {
        struct {
            Zdesk::UInt8    alpha;          // low byte
            Zdesk::UInt8    reserved1;    
            Zdesk::UInt8    reserved2;
            Zdesk::UInt8    method;         // high byte
        };
        Zdesk::UInt32       whole;
    };

    AM mAM;
};


class ZcCmDialogColor : public ZcCmColorBase
{
public:

    ZcCmDialogColor();
    ZcCmDialogColor(const ZcCmDialogColor& other);
    ZcCmDialogColor(const ZcCmColorBase& other);
    virtual ~ZcCmDialogColor();

    ZcCmDialogColor& operator=(const ZcCmDialogColor& inputColor);
    ZcCmDialogColor& operator=(const ZcCmColorBase& inputColor);

    bool operator ==(const ZcCmDialogColor& color) const;
    bool operator !=(const ZcCmDialogColor& color) const;
    bool operator ==(const ZcCmColorBase& color) const;
    bool operator !=(const ZcCmColorBase& color) const;

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const;
    virtual Zcad::ErrorStatus   setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod);

    virtual bool                isByColor() const;
    virtual bool                isByLayer() const;
    virtual bool                isByBlock() const;
    virtual bool                isByACI() const;
    virtual bool                isByPen () const;
    virtual bool                isForeground() const;

    virtual Zdesk::UInt32       color() const;
    virtual Zcad::ErrorStatus   setColor(Zdesk::UInt32 color);

    virtual Zcad::ErrorStatus   setRGB  (Zdesk::UInt8 red, 
                                         Zdesk::UInt8 green, 
                                         Zdesk::UInt8 blue);
    virtual Zcad::ErrorStatus   setRed  (Zdesk::UInt8 red);
    virtual Zcad::ErrorStatus   setGreen(Zdesk::UInt8 green);
    virtual Zcad::ErrorStatus   setBlue (Zdesk::UInt8 blue);
    virtual Zdesk::UInt8        red  () const;
    virtual Zdesk::UInt8        green() const;
    virtual Zdesk::UInt8        blue () const;

    virtual Zdesk::UInt16       colorIndex() const;
    virtual Zcad::ErrorStatus   setColorIndex(Zdesk::UInt16 colorIndex);
    virtual Zdesk::UInt16       penIndex() const;
    virtual Zcad::ErrorStatus   setPenIndex (Zdesk::UInt16 penIndex);

    virtual Zcad::ErrorStatus   setNames(const ZCHAR *colorName,
                                         const ZCHAR *bookName = NULL);
    virtual const ZCHAR *       colorName(void) const;
    virtual const ZCHAR *       bookName(void) const;
    virtual const ZCHAR *       colorNameForDisplay(void);
    virtual bool                hasColorName(void) const;
    virtual bool                hasBookName(void) const;


private:

    enum NameFlags {    kNoNames            = 0x00,
                        kHasColorName       = 0x01,
                        kHasBookName        = 0x02
                    };

    ZcCmEntityColor::RGBM   mRGBM;
    ZCHAR *                 mColorName;
    ZCHAR *                 mBookName;
    Zdesk::UInt8            mNameFlags;
};

namespace ZcCm
{
    enum DialogTabs
    {   
        //these flags can be OR-ed 
        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4,
    };

    enum ACIColors
    {   
        kACIByBlock     = 0,
        kACIRed         = 1,
        kACIYellow      = 2,
        kACIGreen       = 3,
        kACICyan        = 4,
        kACIBlue        = 5,
        kACIMagenta     = 6,
        kACIForeground  = 7,
        kACIByLayer     = 256,
    };
}



#endif 
