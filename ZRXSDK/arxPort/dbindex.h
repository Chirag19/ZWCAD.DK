
#ifndef _ARXPORT_AC_DBINDEX_H_
#define _ARXPORT_AC_DBINDEX_H_ 1

#include "dbmain.h"

class ZcDbIndexIterator;
class ZcDbFilter;
class ZcDbIndexUpdateData;
class ZcDbBlockChangeIterator;
class ZcDbFilteredBlockIterator;
class ZcDbFilter;
class ZcDbImpDatabase;
class ZcDbBlockTableRecord;
class ZcDbBlockChangeIterator;
class ZcDbIndexUpdateData;

typedef ZcDbIndexIterator AcDbIndexIterator ;
typedef ZcDbFilter AcDbFilter ;
typedef ZcDbIndexUpdateData AcDbIndexUpdateData ;
typedef ZcDbBlockChangeIterator AcDbBlockChangeIterator ;
typedef ZcDbFilteredBlockIterator AcDbFilteredBlockIterator ;
typedef ZcDbFilter AcDbFilter ;
typedef ZcDbImpDatabase AcDbImpDatabase ;
typedef ZcDbBlockTableRecord AcDbBlockTableRecord ;
typedef ZcDbBlockChangeIterator AcDbBlockChangeIterator ;
typedef ZcDbIndexUpdateData AcDbIndexUpdateData ;
#include "..\inc\zdbindex.h"

typedef ZcDbIndex							AcDbIndex;
typedef ZcDbFilteredBlockIterator			AcDbFilteredBlockIterator;
typedef ZcDbCompositeFilteredBlockIterator	AcDbCompositeFilteredBlockIterator;
typedef ZcDbIndexUpdateData					AcDbIndexUpdateData;
typedef ZcDbIndexUpdateDataIterator			AcDbIndexUpdateDataIterator;
typedef ZcDbBlockChangeIterator				AcDbBlockChangeIterator;


#define AcDbIndexFilterManager	ZcDbIndexFilterManager
#endif
