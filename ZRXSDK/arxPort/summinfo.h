#ifndef _ARXPORT_AD_SUMMINFO_H_
#define _ARXPORT_AD_SUMMINFO_H_ 1

#include "adesk.h"
#include "..\inc\zsumminfo.h"

typedef ZcDbDatabaseSummaryInfo		AcDbDatabaseSummaryInfo;

#define acdbGetSummaryInfo		zcdbGetSummaryInfo
#define acdbPutSummaryInfo		zcdbPutSummaryInfo
#define AcDbSummaryInfoReactor	ZcDbSummaryInfoReactor
#define AcDbSummaryInfoManager	ZcDbSummaryInfoManager
#define acdbSummaryInfoManager	zcdbSummaryInfoManager
#define initAcDbSummaryInfoManager		initZcDbSummaryInfoManager
#define deleteAcDbSummaryInfoManager	deleteZcDbSummaryInfoManager	

#endif
