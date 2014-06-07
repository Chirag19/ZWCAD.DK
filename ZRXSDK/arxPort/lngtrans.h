#ifndef _ARXPORT_AD_LNGTRANS_H_
#define _ARXPORT_AD_LNGTRANS_H_ 1


#include "rxnames.h"
#include "dbidar.h"

class ZcDbLongTransaction;
class ZcDbDatabase;
class ZcDbIdMapping;
class ZcApDocument;

class ZcApImpLongTransactionReactor;

typedef ZcDbLongTransaction					AcDbLongTransaction;
typedef ZcDbDatabase						AcDbDatabase;
typedef ZcDbIdMapping						AcDbIdMapping;
typedef ZcApDocument						AcApDocument;

typedef ZcApImpLongTransactionReactor		AcApImpLongTransactionReactor;

#include "..\inc\zlngtrans.h"

#define AC_LONG_TRANSACTION_MANAGER_OBJ		ZC_LONG_TRANSACTION_MANAGER_OBJ
typedef ZcApLongTransactionReactor			AcApLongTransactionReactor;
typedef ZcApLongTransactionManager			AcApLongTransactionManager;

#define acapLongTransactionManager			zcapLongTransactionManager
#define acapLongTransactionManagerPtr		zcapLongTransactionManagerPtr

#endif