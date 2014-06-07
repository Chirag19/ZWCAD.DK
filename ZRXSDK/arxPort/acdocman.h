#ifndef _ARXPORT_AD_ACDOCMAN_H_
#define _ARXPORT_AD_ACDOCMAN_H_ 1

#include "acdb.h"

class ZcTransactionManager;
class ZcDbDatabase;
class CDocument;
class ZcEdInputPointManager;
class ZcApStatusBar;
class ZcApPlotReactor;
class ZcRxIterator;


struct IDispatch;

typedef ZcTransactionManager	AcTransactionManager;
typedef ZcDbDatabase			AcDbDatabase;
typedef ZcEdInputPointManager	AcEdInputPointManager;
typedef ZcApStatusBar			AcApStatusBar;
typedef ZcApPlotReactor			AcApPlotReactor;
typedef ZcRxIterator			AcRxIterator;

#include "..\inc\zcdocman.h"


#define AC_DOCUMENT_MANAGER_OBJ		ZC_DOCUMENT_MANAGER_OBJ
typedef ZcAp					AcAp;
typedef ZcLispAppInfo			AcLispAppInfo;
typedef ZcApDocument			AcApDocument;
typedef ZcApDocManagerReactor	AcApDocManagerReactor;
typedef ZcApDocumentIterator	AcApDocumentIterator;
typedef ZcApDocManager			AcApDocManager;
#define acDocManagerPtr			zcDocManagerPtr
#define acDocManager			zcDocManager

#define newAcApDocumentIterator newZcApDocumentIterator

#define pushAcadResourceHandle  pushZcadResourceHandle

#endif