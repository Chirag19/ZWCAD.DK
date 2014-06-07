#ifndef _ARXPORT_AC_DBPLOTSETVAL_H_
#define _ARXPORT_AC_DBPLOTSETVAL_H_ 1


#include "AdAChar.h"

class ZcDbPlotSettings;

typedef ZcDbPlotSettings AcDbPlotSettings ;
#include "..\inc\zdbplotsetval.h"

typedef	ZcDbPlotSettingsValidator			AcDbPlotSettingsValidator;
typedef ZcDbPlotSettings::PlotPaperUnits	PlotPaperUnits;
typedef ZcDbPlotSettings::PlotRotation		PlotRotation;
typedef ZcDbPlotSettings::PlotType			PlotType;
typedef ZcDbPlotSettings::StdScaleType		StdScaleType;
#endif