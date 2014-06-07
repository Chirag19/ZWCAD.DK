#ifndef _ARXPORT_AC_DBLSTATE_H_
#define _ARXPORT_AC_DBLSTATE_H_ 1

#include "dbmain.h"
#include "acarray.h"
#include "acstring.h"

class ZcDbImpLayerStateManager;
class ZcDbLayerStateManagerReactor;

typedef ZcDbImpLayerStateManager AcDbImpLayerStateManager ;
typedef ZcDbLayerStateManagerReactor AcDbLayerStateManagerReactor ;
#include "..\inc\zdblstate.h"

typedef ZcDbLayerStateManager				AcDbLayerStateManager;
typedef ZcDbLayerStateManagerReactor		AcDbLayerStateManagerReactor;
#endif