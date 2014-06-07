
#ifndef _ARXPORT_AD_ACPLHOSTAPPSERVICES_H_
#define _ARXPORT_AD_ACPLHOSTAPPSERVICES_H_ 1

class ZcPlPlotLogger;
class ZcadPlotInternalServices;

typedef ZcPlPlotLogger				AcPlPlotLogger;
typedef ZcadPlotInternalServices	AcadPlotInternalServices;

#include "..\inc\ZcPlHostAppServices.h"

typedef ZcPlHostAppServices		AcPlHostAppServices;

#define AcPlSetHostAppServices		ZcPlSetHostAppServices
#define AcPlGetHostAppServices		ZcPlGetHostAppServices

#endif