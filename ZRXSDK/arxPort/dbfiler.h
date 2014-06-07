
#ifndef _ARXPORT_AD_FILER_H_
#define _ARXPORT_AD_FILER_H_ 1

#include "AdAChar.h"
#include "acdb.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "gescl3d.h"
#include "adsdef.h"

class ZcDbAuditInfo;
class ZcDbFilerController;
class ZcDbHandle;
class ZcDbIdRefQueue;
class ZcString;

typedef ZcDbAuditInfo AcDbAuditInfo ;
typedef ZcDbFilerController AcDbFilerController ;
typedef ZcDbHandle AcDbHandle ;
typedef ZcDbIdRefQueue AcDbIdRefQueue ;
typedef ZcString AcString ;

#include "..\inc\zdbfiler.h"

typedef ZcDbDwgFiler AcDbDwgFiler;
typedef ZcDbDxfFiler AcDbDxfFiler;
#define readAcDbHandle   readZcDbHandle 
#define writeAcDbHandle  writeZcDbHandle

#endif
