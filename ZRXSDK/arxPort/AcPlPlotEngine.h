
#ifndef _ARXPORT_AD_ACPLPLOTENGINE_H_
#define _ARXPORT_AD_ACPLPLOTENGINE_H_ 1

#include "AdAChar.h"
#include "AcPl.h"
#include "AcPlObject.h"

class ZcViewport;
class ZcPlPlotProgress;
class ZcPlPlotInfo;
class ZcDbPlotSettings;
class ZcPlPlotConfig;

typedef ZcViewport				AcViewport;
typedef ZcPlPlotProgress		AcPlPlotProgress;
typedef ZcPlPlotInfo			AcPlPlotInfo;
typedef ZcDbPlotSettings		AcDbPlotSettings;
typedef ZcPlPlotConfig          AcPlPlotConfig;


#include "..\inc\ZcPlPlotEngine.h"

typedef ZCPL_PREVIEWENDPLOT		ACPL_PREVIEWENDPLOT;
typedef ZcPlPlotPageInfo		AcPlPlotPageInfo;
typedef ZcPlPlotEngine			AcPlPlotEngine;

#define PreviewStatus				ZPreviewStatus
#define acplPlotConfigManager		zcplPlotConfigManager

#endif