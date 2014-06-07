
#ifndef _ARXPORT_AD_DBTRANS_H_
#define _ARXPORT_AD_DBTRANS_H_ 1

#include "dbapserv.h"

class ZcTransaction;
class ZcTransactionReactor;

typedef ZcTransaction AcTransaction ;
typedef ZcTransactionReactor AcTransactionReactor ;
#include "..\inc\zdbtrans.h"

typedef ZcDbTransactionManager			AcDbTransactionManager;
typedef ZcTransaction					AcTransaction;
typedef ZcTransactionReactor			AcTransactionReactor;

#define acdbTransactionManagerPtr		zcdbTransactionManagerPtr
#define acdbTransactionManager			zcdbTransactionManager

#endif
