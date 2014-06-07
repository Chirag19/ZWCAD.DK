
#ifndef _ARXPORT_AD_DBID_H_
#define _ARXPORT_AD_DBID_H_ 1

#include "adesk.h"
#include "dbhandle.h"

class ZcDbDatabase;
class ZcDbStub;

typedef ZcDbDatabase AcDbDatabase ;
typedef ZcDbStub AcDbStub ;

#include "..\inc\zdbid.h"

typedef ZcDbObjectId			AcDbObjectId;
typedef ZcDbHardOwnershipId		AcDbHardOwnershipId;
typedef ZcDbSoftOwnershipId		AcDbSoftOwnershipId;
typedef ZcDbHardPointerId		AcDbHardPointerId;
typedef ZcDbSoftPointerId		AcDbSoftPointerId;

#endif
