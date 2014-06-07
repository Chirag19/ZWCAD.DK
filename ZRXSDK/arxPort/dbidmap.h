
#ifndef _ARXPORT_AC_DBIDMAP_H_
#define _ARXPORT_AC_DBIDMAP_H_ 1

#include "acdb.h"
#include "rxobject.h"

class ZcDbDatabase;
class ZcDbIdMappingIter;
class ZcDbImpIdMapping;
class ZcDbImpIdMappingIter;

typedef ZcDbDatabase AcDbDatabase ;
typedef ZcDbIdMappingIter AcDbIdMappingIter ;
typedef ZcDbImpIdMapping AcDbImpIdMapping ;
typedef ZcDbImpIdMappingIter AcDbImpIdMappingIter ;

#include "..\inc\zdbidmap.h"

typedef ZcDbIdPair			AcDbIdPair;
typedef ZcDbIdMapping		AcDbIdMapping;
typedef ZcDbIdMappingIter	AcDbIdMappingIter;

#endif
