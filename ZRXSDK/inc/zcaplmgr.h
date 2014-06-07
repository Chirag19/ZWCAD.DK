#ifndef   _ZCAPLMGR_H
#define   _ZCAPLMGR_H

#include "ZcDbLMgr.h"
#pragma pack (push, 8)

class ZcDbObjectId;
class ZcGePoint2d;
class ZcGePoint3d;

template <class T> class ZcArrayMemCopyReallocator;
template <class T, class R = ZcArrayMemCopyReallocator<T> > class ZcArray;
typedef ZcArray<ZcGePoint2d> ZcGePoint2dArray;


class ZcApLayoutManager : public ZcDbLayoutManager {
  public:
    
    virtual int               
    pageSetup                 (ZcDbObjectId layoutBTRId = ZcDbObjectId::kNull, 
                               void* pParent = NULL, 
                               Zdesk::Boolean isPageSetupDlg = TRUE) = 0;
    virtual void              
    updateCurrentPaper        (Zdesk::Boolean zoomToPaper = FALSE  ) = 0;

    virtual void              
    updateLayoutTabs          () = 0;

    virtual const ZCHAR *      
    findActiveTab             () = 0;
                              
    virtual Zdesk::Boolean    
    showTabs                  () = 0;

    virtual void              
    setShowTabs               (Zdesk::Boolean showTabs           ) = 0;

    virtual Zdesk::Boolean    
    showPageSetup             () = 0;

    virtual void              
    setShowPageSetup          (Zdesk::Boolean showPageSetupDlg   ) = 0;

    virtual Zdesk::Boolean    
    createViewports           () = 0;

    virtual void              
    setCreateViewports        (Zdesk::Boolean createViewports    ) = 0;

    virtual Zdesk::Boolean    
    showPaperBackground       () = 0;

    virtual void              
    setShowPaperBackground    (Zdesk::Boolean showPaperBackground) = 0;

    virtual Zdesk::Boolean    
    showPaperMargins          () = 0; 

    virtual void              
    setShowPaperMargins       (Zdesk::Boolean showPaperMargins   ) = 0;

    virtual Zdesk::Boolean    
    showPrintBorder           () = 0;

    virtual void              
    setShowPrintBorder        (Zdesk::Boolean showPrintBorder    ) = 0;

    virtual ZCHAR *            
    getNextNewLayoutName      (ZcDbDatabase* useDb = NULL) = 0;

    virtual void 
    setDefaultPlotConfig      (ZcDbObjectId layoutBTRId) = 0;

    virtual Zcad::ErrorStatus   
    getClipBoundaryElaboration(ZcDbObjectId clipId,
                               ZcGePoint2dArray *&clipBoundary) = 0;

    virtual Zcad::ErrorStatus 
    pointInViewports          (const ZcGePoint3d &pickPt, 
                               ZcDbObjectIdArray &viewports) = 0;
};
#pragma pack (pop)
#endif 

