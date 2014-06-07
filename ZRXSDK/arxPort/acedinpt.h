#ifndef _ARXPORT_AD_ACEDIPT_H_
#define _ARXPORT_AD_ACEDIPT_H_ 1

#include "rxobject.h"
#include "dbmain.h"

class ZcEdInputPointFilter;
class ZcEdInputPointMonitor;
class ZcApDocument;
class ZcEdInputContextReactor;
class ZcDbCustomOsnapMode;
class ZcEdSubSelectFilter;


typedef  ZcEdInputPointFilter		AcEdInputPointFilter;
typedef  ZcEdInputPointMonitor		AcEdInputPointMonitor;
typedef  ZcApDocument				AcApDocument;
typedef  ZcEdInputContextReactor	AcEdInputContextReactor;
typedef  ZcDbCustomOsnapMode		AcDbCustomOsnapMode;
typedef  ZcEdSubSelectFilter		AcEdSubSelectFilter;

#include "..\inc\zcedinpt.h"

typedef ZcEdInputPointManager		AcEdInputPointManager;
typedef ZcEdInputPointFilter		AcEdInputPointFilter;
typedef ZcEdInputPointMonitor		AcEdInputPointMonitor;
typedef ZcEdInputContextReactor		AcEdInputContextReactor;
typedef ZcEdAppGripService			AcEdAppGripService;

#define acedRegisterGripService		zcedRegisterGripService
#define acedRemoveGripService		zcedRemoveGripService

#endif