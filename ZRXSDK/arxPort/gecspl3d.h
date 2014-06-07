#ifndef _ARXPORT_AC_GECSPL3D_H_
#define _ARXPORT_AC_GECSPL3D_H_ 1

class ZcGePointOnCurve3d;
class ZcGeCurve3dIntersection;
class ZcGeInterval;
class ZcGePlane;

typedef ZcGePointOnCurve3d			AcGePointOnCurve3d;
typedef ZcGeCurve3dIntersection		AcGeCurve3dIntersection;
typedef ZcGeInterval				AcGeInterval;
typedef ZcGePlane					AcGePlane;

#include "gesent3d.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gevec3d.h"
#include "gekvec.h"

#include "..\inc\zgecspl3d.h"

typedef ZcGeCubicSplineCurve3d	AcGeCubicSplineCurve3d;

#endif