#ifndef _ARXPORT_AD_MGDINTEROP_H_
#define _ARXPORT_AD_MGDINTEROP_H_ 1

class ZcGeVector2d;
class ZcGeVector3d;
class ZcGeMatrix2d;
class ZcGeMatrix3d;
class ZcGePoint2d;
class ZcGePoint3d;
class ZcGeScale2d;
class ZcGeScale3d;
class ZcGeTol;
class ZcDbObjectId;
class ZcDbExtents;

typedef ZcGeVector2d			AcGeVector2d;
typedef ZcGeVector3d			AcGeVector3d;
typedef ZcGeMatrix2d			AcGeMatrix2d;
typedef ZcGeMatrix3d			AcGeMatrix3d;
typedef ZcGePoint2d				AcGePoint2d;
typedef ZcGePoint3d				AcGePoint3d;
typedef ZcGeScale2d				AcGeScale2d;
typedef ZcGeScale3d				AcGeScale3d;
typedef ZcGeTol					AcGeTol;
typedef ZcDbObjectId			AcDbObjectId;
typedef ZcDbExtents				AcDbExtents;

#define ZCDBMGD
#define ACDBMGD					ZCDBMGD

#include "..\inc\zmgdinterop.h"

typedef ZcMgObjectFactoryBase		AcMgObjectFactoryBase;
#define AcMgObjectFactory			ZcMgObjectFactory

#endif
