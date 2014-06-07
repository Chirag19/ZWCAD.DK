
#ifndef _ARXPORT_AD_DBXRECRD_H_
#define _ARXPORT_AD_DBXRECRD_H_ 1


#include "AdAChar.h"
#include "dbmain.h"

class ZcDbImpXrecordIterator;

typedef ZcDbImpXrecordIterator AcDbImpXrecordIterator ;
#include "..\inc\zdbxrecrd.h"

#define ACDB_XRECORD_CLASS				ZCDB_XRECORD_CLASS
#define ACDB_XRECORD_ITERATOR_CLASS		ZCDB_XRECORD_ITERATOR_CLASS

typedef ZcDbXrecord			AcDbXrecord;
typedef ZcDbXrecordIterator	AcDbXrecordIterator;
#endif