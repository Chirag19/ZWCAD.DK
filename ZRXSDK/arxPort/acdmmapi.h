#ifndef _ARXPORT_AD_ACDMMAPI_H_
#define _ARXPORT_AD_ACDMMAPI_H_ 1

#include "AdAChar.h"
#include "AcDMMEPlotProperty.h"
#include "AcDMMEPlotProperties.h"
#include "AcDMMutils.h"
#include "AcPlPlotLogger.h"
#include "Ac3dDwfNavTree.h"
#include "..\inc\zcdmmapi.h"

typedef ZcDMMSheetReactorInfo		AcDMMSheetReactorInfo;
typedef ZcDMMEntityReactorInfo		AcDMMEntityReactorInfo;
typedef ZcDMMReactor				AcDMMReactor;

#define AcGlobalAddDMMReactor		ZcGlobalAddDMMReactor
#define AcGlobalRemoveDMMReactor	ZcGlobalRemoveDMMReactor


typedef ZCGLOBADDDMMREACTOR        ACGLOBADDDMMREACTOR;
typedef ZCGLOBREMOVEDMMREACTOR     ACGLOBREMOVEDMMREACTOR;
#endif