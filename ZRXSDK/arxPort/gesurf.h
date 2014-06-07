
#ifndef _ARXPORT_AC_GESURF_H_
#define _ARXPORT_AC_GESURF_H_ 1

#include "geent3d.h"
#include "gevc3dar.h"

class ZcGePoint2d;
class ZcGeCurve3d;
class ZcGePointOnCurve3d;
class ZcGePointOnSurface;
class ZcGePointOnSurfaceData;
class ZcGeInterval;

typedef ZcGePoint2d				AcGePoint2d;
typedef ZcGeCurve3d				AcGeCurve3d;
typedef ZcGePointOnCurve3d		AcGePointOnCurve3d;
typedef ZcGePointOnSurface		AcGePointOnSurface;
typedef ZcGePointOnSurfaceData	AcGePointOnSurfaceData;
typedef ZcGeInterval			AcGeInterval;

#include "..\inc\zgesurf.h"

typedef ZcGeSurface AcGeSurface;

#endif
