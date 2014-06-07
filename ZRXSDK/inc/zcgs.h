
#ifndef _ZCGS_H
#define _ZCGS_H

#include "Zdesk.h"
#include "stdlib.h"
#include "ZdZChar.h"

#pragma pack (push, 8)

Zdesk::Boolean zcgsGetDisplayInfo           (int & drawingWidth,    
                                             int & drawingHeight,     
                                             int & aspectWidth,
                                             int & aspectHeight);

Zdesk::Boolean zcgsGetViewportInfo          (int   viewportNumber,
                                             int & left,    
                                             int & bottom,
                                             int & right,    
                                             int & top);    


class ZcGsScreenShot {   
    public:
    virtual Zdesk::Boolean getSize          (int & width,             
                                             int & height,
                                             int & depth) const = 0; 

    virtual Zdesk::Boolean getColorMap      (int             index,
                                             Zdesk::UInt8 & red,
                                             Zdesk::UInt8 & green,
                                             Zdesk::UInt8 & blue) const = 0;

    virtual void const * getScanline        (int offsetFromLeft,
                                             int offsetFromTop) const = 0;

#ifdef new
#define DISABLING_LEAK_CHECK
#undef new
#endif
    void * operator new (size_t size); 

    void operator delete (void * p);  

#ifndef ZPRODUCTION
        void * operator new (size_t size, const char *, int) { return operator new(size); }
#if _MSC_VER >= 1200

        void operator delete (void * p, const char *, int) { delete p; }
#endif 
#endif 

#ifdef DISABLING_LEAK_CHECK
#define new DEBUG_NEW
#undef DISABLING_LEAK_CHECK
#endif

    ZcGsScreenShot();
    virtual ~ZcGsScreenShot () = 0;
};

#define ScreenShot ZcGsScreenShot

ZcGsScreenShot * zcgsGetScreenShot          (int          viewportNumber);

void zcgsSetViewportRenderFlag              (int          viewportNumber);

Zdesk::Boolean zcgsDisplayImage             (int          viewportNumber,
                                             long         originLeft,    
                                             long         originTop,    
                                             int          imageWidth,    
                                             int          imageHeight,    
                                             void const * imageData,        
                                             int          hasTransparency);

Zdesk::Boolean zcgsRemoveAnonymousGraphics  (int viewportNumber);


typedef void (*zcgsCustomUpdateMethod)      (void * pParm, int left, int right, int bottom, int top);
Zdesk::Boolean zcgsSetCustomUpdateMethod    (zcgsCustomUpdateMethod custom_update_method, void * pParm);

void zcgsRedrawShortTermGraphics            (short minx, short miny, short maxx, short maxy);


struct ZcGs
{
    enum LinePattern      { eSolid                         = 0,
                            eDashed                        = 1,
                            eDotted                        = 2,
                            eDashDot                       = 3,
                            eShortDash                     = 4,
                            eMediumDash                    = 5,
                            eLongDash                      = 6,
                            eDoubleShortDash               = 7,
                            eDoubleMediumDash              = 8,
                            eDoubleLongDash                = 9,
                            eMediumLongDash                = 10,
                            eMediumDashShortDashShortDash  = 11,
                            eLongDashShortDash             = 12,
                            eLongDashDotDot                = 13,
                            eLongDashDot                   = 14,
                            eMediumDashDotShortDashDot     = 15,
                            eSparseDot                     = 16,
                            eDefaultLinePattern            = eDotted };
};

void              zcgsSetHighlightColor       (Zdesk::UInt16 colorIndex);
Zdesk::UInt16     zcgsGetHighlightColor       (void);
void              zcgsSetHighlightLinePattern (ZcGs::LinePattern pattern);
ZcGs::LinePattern zcgsGetHighlightLinePattern (void);
void              zcgsSetHighlightLineWeight  (Zdesk::UInt16 weight);
Zdesk::UInt16     zcgsGetHighlightLineWeight  (void);

class ZcGsView;
class ZcGsManager;

Zdesk::Boolean  zcgsSetViewParameters         (int viewportNumber, const ZcGsView * pView,
                                               bool bRegenRequired, bool bRescaleRequired,
                                               bool bSyncRequired = false);
Zdesk::Boolean  zcgsGetViewParameters         (int viewportNumber, ZcGsView * pView);
Zdesk::Boolean  zcgsSetLensLength             (int viewportNumber, const double & lensLength);
Zdesk::Boolean  zcgsGetLensLength             (int viewportNumber, double & lensLength);
void            zcgsWriteViewToUndoController (int viewportNumber);
Zdesk::Boolean  zcgsSetView2D                 (int viewportNumber);


class CView;

ZcGsView *      zcgsGetGsView               (int viewportNumber, bool bCreateIfNone);

ZcGsManager *   zcgsGetGsManager            (CView * pView = NULL); 

class ZcGeVector3d;
Zdesk::Boolean  zcgsGetOrthoViewParameters  (int viewportNumber, 
                                             ZcDb::OrthographicView view,
                                             ZcGeVector3d * pViewDir,
                                             ZcGeVector3d * pUpVector);

class ZcGs2DViewLimitManager 
{      
public:
    virtual                ~ZcGs2DViewLimitManager  (void) { }
    virtual bool            testView                (ZcGePoint3d const & target,
                                                     double              dFieldHeight)  = 0;
};

ZcGs2DViewLimitManager *    zcgsCreate2DViewLimitManager  (int viewportNumber);
void                        zcgsDestroy2DViewLimitManager (ZcGs2DViewLimitManager * pLimitManager);

#pragma pack (pop)
#endif
