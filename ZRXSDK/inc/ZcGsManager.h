
#ifndef __ZCGSMANAGER_H__
#define __ZCGSMANAGER_H__
#pragma pack (push, 8)

class ZcDbViewportTableRecord;
class ZcGiDrawable;
class ZcGsClassFactory;
class ZcGsView;
class ZcGsModel;
class ZcGsDevice;

class ZcGsManager
{
public:
                                ZcGsManager             (void) { }
    virtual                    ~ZcGsManager             (void) { }

    virtual ZcGsModel *         createZDESKModel      (void)                          = 0;
    virtual ZcGsView *          createZDESKViewport   (ZcDbViewportTableRecord * vp)  = 0;    
    virtual ZcGsView *          createZDESKView       (ZcGiDrawable * drawable)       = 0;    
                                                                                              
                                                                                              
    virtual ZcGsDevice *        createZDESKDevice     (HWND hWnd)                     = 0;
    virtual ZcGsDevice *        createZDESKOffScreenDevice()                          = 0;

    virtual void                destroyZDESKModel     (ZcGsModel  * model)            = 0;
    virtual void                destroyZDESKView      (ZcGsView   * view)             = 0;
    virtual void                destroyZDESKDevice    (ZcGsDevice * device)           = 0;
    
    virtual ZcGsClassFactory *  getGSClassFactory       (void)                          = 0;
    virtual ZcGsModel        *  getDBModel              (void)                          = 0;
    virtual ZcGsDevice       *  getGUIDevice            (void)                          = 0;
};


#pragma pack (pop)
#endif // __ZCGSMANAGER_H__
