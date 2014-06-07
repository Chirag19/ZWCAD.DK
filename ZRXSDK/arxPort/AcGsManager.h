#ifndef _ARXPORT_AD_ACGSMANAGER_H_
#define _ARXPORT_AD_ACGSMANAGER_H_ 1


class ZcDbViewportTableRecord;
class ZcGiDrawable;
class ZcGsClassFactory;
class ZcGsView;
class ZcGsModel;
class ZcGsDevice;


typedef ZcDbViewportTableRecord    AcDbViewportTableRecord;
typedef ZcGiDrawable               AcGiDrawable;
typedef ZcGsClassFactory           AcGsClassFactory;
typedef ZcGsView                   AcGsView;
typedef ZcGsModel                  AcGsModel;
typedef ZcGsDevice                 AcGsDevice;




#include "..\inc\ZcGsManager.h"

typedef ZcGsManager		AcGsManager;

#define createAutoCADModel            createZDESKModel
#define createAutoCADViewport         createZDESKViewport  
#define createAutoCADView             createZDESKView 
                                                                                            

#define createAutoCADDevice           createZDESKDevice
#define createAutoCADOffScreenDevice  createZDESKOffScreenDevice

#define destroyAutoCADModel           destroyZDESKModel
#define destroyAutoCADView            destroyZDESKView
#define destroyAutoCADDevice          destroyZDESKDevice
#endif
