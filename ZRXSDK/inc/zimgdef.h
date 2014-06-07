
#ifndef __ZIMGDEF_H
#define __ZIMGDEF_H    1

#include "zdbmain.h"
#include "zcgi.h"
#include "zgept2dar.h"
#include "zgemat2d.h"
#include "ZdzChar.h"
#pragma pack (push, 8)


class  RasterImageDefImp;                
class  ZcDbImpRasterImageDefReactor;    
namespace Atil
{
    class  Image;
    class  FileReadDescriptor;
};

enum ClassVersion
{
    kVersion1   = 0,    // S039 Oct 21, 1996
    kVersion2   = 1,    // S052 Jan 16, 1996
    kVersion3   = 2     // S061 Mar 21, 1997
};



#pragma warning( disable : 4275 ) 

#ifdef ISMDLLACCESS
#undef ISMDLLACCESS
#endif
#ifdef ISMDLLACCESSDATA
#undef ISMDLLACCESSDATA
#endif
#ifdef ISM_OBJ 
#define ISMDLLACCESS __declspec(dllexport)
#define ISMDLLACCESSDATA
#else
#define ISMDLLACCESS 
#define ISMDLLACCESSDATA __declspec(dllimport)
#endif



class ISMDLLACCESS ZcDbRasterImageDef : public ZcDbObject 
{
public:

    static ClassVersion         classVersion();

    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDef);

    ZcDbRasterImageDef();
    virtual  ~ZcDbRasterImageDef();

    RasterImageDefImp*          ptrImp() const;
    RasterImageDefImp*          setPtrImp(RasterImageDefImp* pImp);

    
    virtual Zcad::ErrorStatus   subErase(Zdesk::Boolean erasing);
    virtual Zcad::ErrorStatus   subClose();

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* filer) const;

   
    virtual ZcGiSentScanLines*  makeScanLines(
                                    const ZcGiRequestScanLines* pReq,
                                    const ZcGeMatrix2d& pixToScreen,
                                    ZcGePoint2dArray* pZctiveClipBndy = 0,     
                                    Zdesk::Boolean draftQuality = false,
                                    Zdesk::Boolean isTransparent = false,
                                    const double brightness = 50.0,
                                    const double contrast = 50.0,
                                    const double fade = 0.0
                                ) const;

    virtual Zcad::ErrorStatus   setSourceFileName(const ZCHAR * pPathName);
    virtual Zcad::ErrorStatus   setActiveFileName(const ZCHAR * pPathName);
    virtual const ZCHAR *       searchForActivePath();

    virtual const ZCHAR *       sourceFileName() const;
    virtual const ZCHAR *       activeFileName() const;

    virtual Zcad::ErrorStatus   embed();
    virtual Zdesk::Boolean      isEmbedded() const;

    virtual Zcad::ErrorStatus   load();
    virtual Zcad::ErrorStatus   unload(Zdesk::Boolean modifyDatabase = true);
    virtual Zdesk::Boolean      isLoaded() const;

    virtual ZcGeVector2d        size() const;

    
    virtual ZcGiImageOrg        organization() const;
    virtual int                 colorDepth() const;

    virtual const ZCHAR *       fileType() const;
    virtual int                 entityCount(
                                 Zdesk::Boolean* pbLocked = 0
                                        ) const;
    virtual void                updateEntities() const;

    enum Units 
    {
        kNone           = 0,
        kMillimeter     = 1,
        kCentimeter     = 2,
        kMeter          = 3,
        kKilometer      = 4,
        kInch           = 5,
        kFoot           = 6,
        kYard           = 7,
        kMile           = 8,
        kMicroinches    = 9,
        kMils           = 10,
        kAngstroms      = 11,
        kNanometers     = 12,
        kMicrons        = 13,
        kDecimeters     = 14,
        kDekameters     = 15,
        kHectometers    = 16,
        kGigameters     = 17,
        kAstronomical   = 18,
        kLightYears     = 19,
        kParsecs        = 20
    };

    virtual Zcad::ErrorStatus   setResolutionMMPerPixel(
                                    const ZcGeVector2d& resMMPerPixel);
    virtual ZcGeVector2d        resolutionMMPerPixel() const;
    virtual void                setResolutionUnits(
                                    ZcDbRasterImageDef::Units units);
    virtual Units               resolutionUnits() const;

    
    virtual Zcad::ErrorStatus   loadThumbnail(
                                        Zdesk::UInt16& maxWidth,
                                        Zdesk::UInt16& maxHeight,
                                        Zdesk::UInt8* pPalette = 0,
                                        int nPaletteEntries = 0
                                        );
    virtual Zcad::ErrorStatus   unloadThumbnail();
    virtual void*               createThumbnailBitmap(
                                        BITMAPINFO*& pBitmapInfo,
                                        Zdesk::UInt8 brightness = 50,
                                        Zdesk::UInt8 contrast = 50,
                                        Zdesk::UInt8 fade = 0
                                        );

    
    virtual Atil::Image* imageCopy(Zdesk::Boolean bForceImageLoad = true) const;
    virtual Atil::FileReadDescriptor* fileDescCopy() const;

    
    virtual Zcad::ErrorStatus   openImage(Atil::Image*& pImage);

    
    virtual Zcad::ErrorStatus   closeImage();

    
    virtual Zcad::ErrorStatus   setImage(const Atil::Image* pImage, 
                                    const Atil::FileReadDescriptor* pFileDesc, 
                                    Zdesk::Boolean modifyDatabase = true);

    
    virtual Zcad::ErrorStatus   setUndoStoreSize(
                                        unsigned int maxImages = 10
                                        );
    virtual unsigned int        undoStoreSize() const;

    
    virtual Zdesk::Boolean       imageModified() const;
    virtual Zcad::ErrorStatus    setImageModified(Zdesk::Boolean modified);

    
    static Zcad::ErrorStatus     createImageDictionary(ZcDbDatabase* pDb, ZcDbObjectId& dictId);
    static ZcDbObjectId          imageDictionary(ZcDbDatabase* pDb); 

    
    enum { kMaxSuggestNameSize = 2049 };
    static Zcad::ErrorStatus     suggestName(
                                     ZcDbDictionary* pImageDictionary, 
                                        const ZCHAR* pNewImagePathName, 
                                        ZCHAR* newImageName
                                 );

private:

    
#ifdef ZMEM_DEBUG
#undef new
#undef delete
#endif
    void *operator new[](size_t nSize) { return 0;}
    void operator delete[](void *p) {};
    
    void *operator new[](size_t nSize, const char *file, int line) { return 0;}
#ifdef MEM_DEBUG
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif

    
    RasterImageDefImp*          mpImp;
    static ClassVersion         mVersion;
};


inline RasterImageDefImp*
ZcDbRasterImageDef::ptrImp() const
{
    return mpImp;
}


inline RasterImageDefImp*             
ZcDbRasterImageDef::setPtrImp(RasterImageDefImp* pImp)
{
    RasterImageDefImp* oldImp=mpImp;
    mpImp=pImp;
    return oldImp;
}



class ISMDLLACCESS ZcDbRasterImageDefReactor : public ZcDbObject 
{
public:

    static ClassVersion         classVersion();

    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDefReactor);

        ZcDbRasterImageDefReactor();
    virtual                     ~ZcDbRasterImageDefReactor();


    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    
    virtual void                erased(const ZcDbObject* dbObj,
                                        Zdesk::Boolean pErasing = true
                                );
    virtual void                modified(const ZcDbObject* dbObj);

    
    enum DeleteImageEvent
    {
        kUnload     = 1,
        kErase      = 2,
    };

    virtual Zdesk::Boolean      onDeleteImage(
                                    const ZcDbRasterImageDef* pImageDef, 
                                    Atil::Image* pImage,
                                    DeleteImageEvent event,
                                    Zdesk::Boolean cancelAllowed);

    
    static void                 setEnable(Zdesk::Boolean enable);

private:

    
#ifdef ZMEM_DEBUG
#undef new
#undef delete
#endif
    void *operator new[](size_t nSize) { return 0;}
    void operator delete[](void *p) {};
    
    void *operator new[](size_t nSize, const char *file, int line) { return 0;}
#ifdef MEM_DEBUG
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif

    
    ZcDbImpRasterImageDefReactor*   mpImp;
    static ClassVersion             mVersion;
};



class ISMDLLACCESS ZcDbRasterImageDefTransReactor : public ZcDbObjectReactor 
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDefTransReactor);

    virtual     ~ZcDbRasterImageDefTransReactor();

    
    virtual Zdesk::Boolean      onDeleteImage(const ZcDbRasterImageDef* pImageDef, 
                                              Atil::Image* pImage,
                        ZcDbRasterImageDefReactor::DeleteImageEvent event,
                                          Zdesk::Boolean cancelAllowed) = 0;

};

class ISMDLLACCESS ZcDbRasterImageDefFileAccessReactor : public ZcDbObjectReactor 
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDefFileAccessReactor);

    virtual     ~ZcDbRasterImageDefFileAccessReactor();

    virtual void                onAttach(
                                    const ZcDbRasterImageDef*, 
                                    const ZCHAR * pPath) = 0;
    virtual void                onDetach(
                                    const ZcDbRasterImageDef*, 
                                    const ZCHAR * pPath) = 0;
    virtual Zdesk::Boolean      onOpen(
                                    const ZcDbRasterImageDef*,
                                    const ZCHAR * pPath, 
                                    const ZCHAR * pActivePath,
                                    Zdesk::Boolean& replacePath,
                                    ZCHAR *& replacementPath) = 0;
    virtual Zdesk::Boolean      onPathChange(
                                    const ZcDbRasterImageDef*,
                                    const ZCHAR * pPath, 
                                    const ZCHAR * pActivePath,
                                    Zdesk::Boolean& replacePath,
                                    ZCHAR *& replacementPath) = 0;
    virtual void                onClose(
                                    const ZcDbRasterImageDef*,
                                    const ZCHAR * pPath) = 0;

    virtual void                onDialog(
                                     ZcDbRasterImageDef*,
                                     const ZCHAR * pCaption, 
                                     const ZCHAR * pFileExtensions
                                 ) = 0;
};





#pragma warning( default : 4275 ) 

#pragma pack (pop)
#endif 
