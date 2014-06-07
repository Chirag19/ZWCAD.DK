
#ifndef _ARXPORT_AD_DBAUDITA_H_
#define _ARXPORT_AD_DBAUDITA_H_ 1

#include "AdAChar.h"

class ZcDbDatabase;
class ZcDbObject;

typedef ZcDbDatabase  AcDbDatabase;
typedef ZcDbObject    AcDbObject;

#include "..\inc\zdbaudita.h"

typedef ZcDbAuditInfo		AcDbAuditInfo;
typedef ZcDbRecover			AcDbRecover;
typedef ZcDbRecoverCallBack AcDbRecoverCallBack;

#define ACDB_AUDIT_RETURN	ZCDB_AUDIT_RETURN

#endif

