
#ifndef _ARXPORT_AD_GS_H_
#define _ARXPORT_AD_GS_H_ 1

#include "AcArray.h"
#include "AdAChar.h"
#include "gept3dar.h"
#include "dbid.h"

class ZcGiDrawable;
class ZcGeMatrix3d;
class ZcGePoint3d;
class ZcGeVector3d;
class ZcGePoint2d;

class ZcGsView;
class ZcGsModel;
class ZcGsDevice;
class ZcGsConfig;
class ZcGsReactor;
class ZcGsClassFactory;
class ZcGiVisualStyle;
class ZcGiContextualColors;

typedef ZcGiDrawable				AcGiDrawable;
typedef ZcGeMatrix3d				AcGeMatrix3d;
typedef ZcGePoint3d					AcGePoint3d;
typedef ZcGeVector3d				AcGeVector3d;
typedef ZcGePoint2d					AcGePoint2d;

typedef ZcGsView					AcGsView;
typedef ZcGsModel					AcGsModel;	
typedef ZcGsDevice					AcGsDevice;
typedef ZcGsConfig					AcGsConfig;
typedef ZcGsReactor					AcGsReactor;
typedef ZcGsClassFactory			AcGsClassFactory;
typedef ZcGiVisualStyle				AcGiVisualStyle;
typedef ZcGiContextualColors		AcGiContextualColors;

#include "..\inc\zgs.h"

namespace Atil
{
    class Image;
};



typedef ZcGsDCPoint						AcGsDCPoint;
typedef ZcGsDCRect						AcGsDCRect;
typedef ZcGsColor						AcGsColor;
typedef ZcGsWindowingSystemID			AcGsWindowingSystemID;
typedef ZcGsNode						AcGsNode;
typedef ZcGsView						AcGsView;
typedef ZcGsModel						AZcGsModel;
typedef ZcGsDevice						AcGsDevice;
typedef ZcGsConfig						AcGsConfig;
typedef ZcGsReactor						AcGsReactor;
typedef ZcGsClientViewInfo				AcGsClientViewInfo;
typedef ZcGsClassFactory				AcGsClassFactory;

typedef ZcGsClientViewInfo				AcGsClientViewInfo;
typedef ZcGsClassFactory				AcGsClassFactory;

typedef ZcGsGetInterfaceFunc			AcGsGetInterfaceFunc;
typedef ZcGsReleaseInterfaceFunc		AcGsReleaseInterfaceFunc;

#define ACGS_CREATE_CLASS_FACTORY		ZCGS_CREATE_CLASS_FACTORY
#define ACGS_DELETE_CLASS_FACTORY		ZCGS_DELETE_CLASS_FACTORY


#endif