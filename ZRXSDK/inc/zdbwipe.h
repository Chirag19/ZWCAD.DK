
#ifndef __ZDBWIPE_H__
#define __ZDBWIPE_H__

#ifdef _DBWIPEOBJ_
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP __declspec(dllimport)
#endif

#include "windows.h"
#include "zimgdef.h"
#include "zimgent.h"

namespace Atil
{
    class Image;
};

#define WIPEOUTOBJSERVICE	ZCRX_T("WipeOut")


#pragma warning(push)
#pragma warning( disable : 4275 ) 
class DLLIMPEXP ZcDbWipeout : public ZcDbRasterImage
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbWipeout);

                                ZcDbWipeout();

    virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* mode);
    virtual void    	        viewportDraw(ZcGiViewportDraw* mode);

    virtual void				list() const;
    virtual Zcad::ErrorStatus	moveGripPointsAt(
								   const ZcDbIntArray& indices,
								   const ZcGeVector3d&     offset);
    virtual Zcad::ErrorStatus   transformBy(
                                    const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   getTransformedCopy(
                                    const ZcGeMatrix3d& xform,
						            ZcDbEntity*& ent
                                ) const;
    virtual ZcRxObject*         clone() const;


    virtual ZcGeVector2d        imageSize(Zdesk::Boolean bGetCachedValue = Zdesk::kFalse) const;
    ZcGiSentScanLines*          getScanLines(const ZcGiRequestScanLines& req) const;
	Zdesk::Boolean				isClipped() const;
	virtual void				setDisplayOpt(
                                    ImageDisplayOpt option, 
                                    Zdesk::Boolean bValue
                                );
	virtual Zdesk::Boolean		isSetDisplayOpt(ImageDisplayOpt option) const;

	virtual Zcad::ErrorStatus	setBrightness( Zdesk::Int8 value );
	virtual Zdesk::Int8			brightness() const;
	
	virtual Zcad::ErrorStatus	setContrast( Zdesk::Int8 value );
	virtual Zdesk::Int8			contrast() const;

	virtual Zcad::ErrorStatus	setFade( Zdesk::Int8 value );
	virtual Zdesk::Int8			fade() const;

    virtual ZcGeVector2d        scale() const;


    Zcad::ErrorStatus           append(ZcDbObjectId& id);
    static Zcad::ErrorStatus    createImageDefinition();
    static Zcad::ErrorStatus    fitPointsToImage(
                                    ZcGePoint2dArray& pointArray,
                                    ZcGePoint2d& minPoint,
                                    double& scale,
                                    Zdesk::Boolean bFlipY = Zdesk::kFalse);
    Zdesk::Boolean        frame() const;
    Zdesk::Boolean        setFrame(Zdesk::Boolean bFrame);

private:
    Zdesk::Boolean              isHighlighted() const;

    void                        getPlane(ZcGeBoundedPlane& boundedPlane) const;
    ZcGeMatrix2d                fastMatrixInvert(const ZcGeMatrix2d& m) const;
    void                        drawFrame(
                                    ZcGiViewportDraw* mode,
                                    const ZcGePoint3dArray& verts) const;
    Zcad::ErrorStatus           setDcToScreen(
                                    const ZcGePoint2d& lowerLeft,
                                    const ZcGePoint2d& upperRight,
                                    int width,
                                    int height,
                                    ZcGeMatrix2d& dcToScreen) const;
    void                        setFrameExtents(
                                    ZcGiWorldDraw* mode,
                                    const ZcGePoint3dArray& verts) const;

public:
    static long                 mImageData;
private:
    Zdesk::Boolean              mHighlight;

   
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
};
#pragma warning(pop)
#endif 
