#ifndef _ARXPORT_AC_GECSPL2D_H_
#define _ARXPORT_AC_GECSPL2D_H_ 1

#include "gesent2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gevec2d.h"
#include "gekvec.h"

class ZcGePointOnCurve2d;
class ZcGeCurve2dIntersection;
class ZcGeInterval;
class ZcGePlane;

typedef ZcGePointOnCurve2d			AcGePointOnCurve2d;
typedef ZcGeCurve2dIntersection		AcGeCurve2dIntersection;
typedef ZcGeInterval				AcGeInterval;
typedef ZcGePlane					AcGePlane;

#include "..\inc\zgecspl2d.h"

typedef ZcGeCubicSplineCurve2d	AcGeCubicSplineCurve2d;

#endif