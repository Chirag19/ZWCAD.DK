#ifndef _ARXPORT_AD_TEXTENGINE_H_
#define _ARXPORT_AD_TEXTENGINE_H_ 1

#include "acgi.h"
#include "AdAChar.h"
#include "Adesk.h"
#include "..\inc\ztextengine.h"

typedef ZcGiTextEngine		AcGiTextEngine;

#define acdbGetSummaryInfo		zcdbGetSummaryInfo
#define acdbPutSummaryInfo		zcdbPutSummaryInfo
#define AcDbSummaryInfoReactor	ZcDbSummaryInfoReactor
#define AcDbSummaryInfoManager	ZcDbSummaryInfoManager
#define acdbSummaryInfoManager	zcdbSummaryInfoManager
#define initAcDbSummaryInfoManager		initZcDbSummaryInfoManager
#define deleteAcDbSummaryInfoManager	deleteZcDbSummaryInfoManager	

#endif
