#ifndef _ARXPORT_AC_DBRENDER_H_
#define _ARXPORT_AC_DBRENDER_H_ 1


#include "AcGiEnvironment.h"

class ZcDbImpRenderSettings;
class ZcDbImpRenderEnvironment;
class ZcDbImpRenderGlobal;
class ZcDbImpMentalRayRenderSettings;


typedef ZcDbImpRenderSettings AcDbImpRenderSettings ;
typedef ZcDbImpRenderEnvironment AcDbImpRenderEnvironment ;
typedef ZcDbImpRenderGlobal AcDbImpRenderGlobal ;
typedef ZcDbImpMentalRayRenderSettings AcDbImpMentalRayRenderSettings ;
#include "..\inc\zdbRender.h"

typedef	ZcDbRenderSettings			AcDbRenderSettings;
typedef ZcDbMentalRayRenderSettings	AcDbMentalRayRenderSettings;
typedef ZcDbRenderEnvironment		AcDbRenderEnvironment;
typedef ZcDbRenderGlobal			AcDbRenderGlobal;
#endif