#ifndef _ARXPORT_AC_GECURV2D_H_
#define _ARXPORT_AC_GECURV2D_H_ 1

#include "adesk.h"
#include "geent2d.h"
#include "geponc2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"

class ZcGePoint2d;
class ZcGeVector2d;
class ZcGePointOnCurve2d;
class ZcGeInterval;
class ZcGeMatrix2d;
class ZcGeLine2d;
class ZcGePointOnCurve2dData;
class ZcGeBoundBlock2d;

typedef ZcGePoint2d				AcGePoint2d;
typedef ZcGeVector2d			AcGeVector2d;
typedef ZcGePointOnCurve2d		AcGePointOnCurve2d;
typedef ZcGeInterval			AcGeInterval;
typedef ZcGeMatrix2d			AcGeMatrix2d;
typedef ZcGeLine2d				AcGeLine2d;
typedef ZcGePointOnCurve2dData	AcGePointOnCurve2dData;
typedef ZcGeBoundBlock2d		AcGeBoundBlock2d;

#include "..\inc\zgecurv2d.h"

typedef ZcGeCurve2d	AcGeCurve2d;

#endif