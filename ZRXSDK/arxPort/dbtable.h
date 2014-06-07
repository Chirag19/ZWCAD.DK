
#ifndef _ARXPORT_AD_DBTALBE_H_
#define _ARXPORT_AD_DBTALBE_H_ 1

#include "dbmain.h"
#include "dbents.h"
#include "AcField.h"
#include "DbLinkedTableData.h"
#include "dbformattedtabledata.h"

class ZcDbTableIterator;
class ZcDbTableTemplate;

typedef ZcDbTableIterator AcDbTableIterator ;
typedef ZcDbTableTemplate AcDbTableTemplate ;
#include "..\inc\zdbtable.h"

typedef ZcSubentPathArray			AcSubentPathArray;
typedef ZcDbTable					AcDbTable;
#endif