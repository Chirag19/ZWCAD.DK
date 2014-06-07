#ifndef _ARXPORT_AD_ACAPLMGR_H_
#define _ARXPORT_AD_ACAPLMGR_H_ 1


#include "AcDbLMgr.h"

class ZcDbObjectId;
class ZcGePoint2d;
class ZcGePoint3d;

typedef ZcDbObjectId					AcDbObjectId;
typedef ZcGePoint2d						AcGePoint2d;
typedef ZcGePoint3d						AcGePoint3d;

#include "..\inc\zcaplmgr.h"

#define AcArrayMemCopyReallocator  ZcArrayMemCopyReallocator 
#define AcArray                    ZcArray                   

typedef ZcGePoint2dArray				AcGePoint2dArray;
typedef ZcApLayoutManager				AcApLayoutManager;

#endif