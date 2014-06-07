
#ifndef _ARXPORT_AD_DBDYNBLK_H_
#define _ARXPORT_AD_DBDYNBLK_H_ 1 

#include "dbeval.h"
#include "acstring.h"

class ZcDbDynBlockReference;
class ZcDbDynBlockReferenceProperty;
class ZcDbImpDynBlockReference;
class ZcDbImpDynBlockReferenceProperty;

typedef ZcDbDynBlockReference AcDbDynBlockReference ;
typedef ZcDbDynBlockReferenceProperty AcDbDynBlockReferenceProperty ;
typedef ZcDbImpDynBlockReference AcDbImpDynBlockReference ;
typedef ZcDbImpDynBlockReferenceProperty AcDbImpDynBlockReferenceProperty ;

#include "..\inc\zdbdynblk.h"

typedef ZcDbDynBlockReferenceProperty		AcDbDynBlockReferenceProperty;
typedef ZcDbDynBlockReferencePropertyArray	AcDbDynBlockReferencePropertyArray;
typedef	ZcDbDynBlockReference				AcDbDynBlockReference;
#endif