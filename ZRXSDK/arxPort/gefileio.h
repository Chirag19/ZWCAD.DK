
#ifndef _ARXPORT_AC_GEFILEIO_H_
#define _ARXPORT_AC_GEFILEIO_H_ 1

#include "gegbl.h"
#include "gedll.h"
#include "dbfiler.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gedblar.h"
#include "geintarr.h"

class ZcGeEntity2d;
class ZcGeEntity3d;
class ZcGePoint2d;
class ZcGeVector2d;
class ZcGeMatrix2d;
class ZcGeScale2d;
class ZcGePoint3d;
class ZcGeVector3d;
class ZcGeMatrix3d;
class ZcGeScale3d;
class ZcGeTol;
class ZcGeInterval;
class ZcGeKnotVector;
class ZcGeCurveBoundary;
class ZcGePosition2d;
class ZcGePointOnCurve2d;
class ZcGeLine2d;
class ZcGeLineSeg2d;
class ZcGeRay2d;
class ZcGeCircArc2d;
class ZcGeEllipArc2d;
class ZcGeExternalCurve2d;
class ZcGeCubicSplineCurve2d;
class ZcGeCompositeCurve2d;
class ZcGeOffsetCurve2d;
class ZcGeNurbCurve2d;
class ZcGePolyline2d;
class ZcGePosition3d;
class ZcGePointOnCurve3d;
class ZcGePointOnSurface;
class ZcGeLine3d;
class ZcGeRay3d;
class ZcGeLineSeg3d;
class ZcGePlane;
class ZcGeBoundedPlane;
class ZcGeBoundBlock2d;
class ZcGeBoundBlock3d;
class ZcGeCircArc3d;
class ZcGeEllipArc3d;
class ZcGeCubicSplineCurve3d;
class ZcGeCompositeCurve3d;
class ZcGeOffsetCurve3d;
class ZcGeNurbCurve3d;
class ZcGePolyline3d;
class ZcGeAugPolyline3d;
class ZcGeExternalCurve3d;
class ZcGeSurface;
class ZcGeCone;
class ZcGeCylinder;
class ZcGeTorus;
class ZcGeExternalSurface;
class ZcGeOffsetSurface;
class ZcGeNurbSurface;
class ZcGeExternalBoundedSurface;
class ZcGeSphere;
class ZcGeCurveCurveInt2d;
class ZcGeCurveCurveInt3d;
class ZcGeEllipCone;
     
class ZcGeFiler;
class ZcGeLibVersion;

typedef ZcGeEntity2d				AcGeEntity2d;
typedef ZcGeEntity3d				AcGeEntity3d;
typedef ZcGePoint2d					AcGePoint2d;
typedef ZcGeVector2d				AcGeVector2d;
typedef ZcGeMatrix2d				AcGeMatrix2d;
typedef ZcGeScale2d					AcGeScale2d;
typedef ZcGePoint3d					AcGePoint3d;
typedef ZcGeVector3d				AcGeVector3d;
typedef ZcGeMatrix3d				AcGeMatrix3d;
typedef ZcGeScale3d					AcGeScale3d;
typedef ZcGeTol						AcGeTol;
typedef ZcGeInterval				AcGeInterval;
typedef ZcGeKnotVector				AcGeKnotVector;
typedef ZcGeCurveBoundary			AcGeCurveBoundary;
typedef ZcGePosition2d				AcGePosition2d;
typedef ZcGePointOnCurve2d			AcGePointOnCurve2d;
typedef ZcGeLine2d					AcGeLine2d;
typedef ZcGeLineSeg2d				AcGeLineSeg2d;
typedef ZcGeRay2d					AcGeRay2d;
typedef ZcGeCircArc2d				AcGeCircArc2d;
typedef ZcGeEllipArc2d				AcGeEllipArc2d;
typedef ZcGeExternalCurve2d			AcGeExternalCurve2d;
typedef ZcGeCubicSplineCurve2d		AcGeCubicSplineCurve2d;
typedef ZcGeCompositeCurve2d		AcGeCompositeCurve2d;
typedef ZcGeOffsetCurve2d			AcGeOffsetCurve2d;
typedef ZcGeNurbCurve2d				AcGeNurbCurve2d;
typedef ZcGePolyline2d				AcGePolyline2d;
typedef ZcGePosition3d				AcGePosition3d;
typedef ZcGePointOnCurve3d			AcGePointOnCurve3d;
typedef ZcGePointOnSurface			AcGePointOnSurface;
typedef ZcGeLine3d					AcGeLine3d;
typedef ZcGeRay3d					AcGeRay3d;
typedef ZcGeLineSeg3d				AcGeLineSeg3d;
typedef ZcGePlane					AcGePlane;
typedef ZcGeBoundedPlane			AcGeBoundedPlane;
typedef ZcGeBoundBlock2d			AcGeBoundBlock2d;
typedef ZcGeBoundBlock3d			AcGeBoundBlock3d;
typedef ZcGeCircArc3d				AcGeCircArc3d;
typedef ZcGeEllipArc3d				AcGeEllipArc3d;
typedef ZcGeCubicSplineCurve3d		AcGeCubicSplineCurve3d;
typedef ZcGeCompositeCurve3d		AcGeCompositeCurve3d;
typedef ZcGeOffsetCurve3d			AcGeOffsetCurve3d;
typedef ZcGeNurbCurve3d				AcGeNurbCurve3d;
typedef ZcGePolyline3d				AcGePolyline3d;
typedef ZcGeAugPolyline3d			AcGeAugPolyline3d;
typedef ZcGeExternalCurve3d			AcGeExternalCurve3d;
typedef ZcGeSurface					AcGeSurface;
typedef ZcGeCone					AcGeCone;
typedef ZcGeCylinder				AcGeCylinder;
typedef ZcGeTorus					AcGeTorus;
typedef ZcGeExternalSurface			AcGeExternalSurface;
typedef ZcGeOffsetSurface			AcGeOffsetSurface;
typedef ZcGeNurbSurface				AcGeNurbSurface;
typedef ZcGeExternalBoundedSurface	AcGeExternalBoundedSurface;
typedef ZcGeSphere					AcGeSphere;
typedef ZcGeCurveCurveInt2d			AcGeCurveCurveInt2d;
typedef ZcGeCurveCurveInt3d			AcGeCurveCurveInt3d;
typedef ZcGeEllipCone				AcGeEllipCone;

typedef ZcGeFiler					AcGeFiler;
typedef ZcGeLibVersion				AcGeLibVersion;

#include "..\inc\zgefileio.h"

typedef ZcGeFileIO		AcGeFileIO;

#endif 
