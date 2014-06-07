
#ifndef _ARXPORT_AC_GEOFFSF_H_
#define _ARXPORT_AC_GEOFFSF_H_ 1

#include "gegbl.h"
#include "gepnt3d.h"
#include "gesurf.h"

class ZcGePlane;
class ZcGeBoundedPlane;
class ZcGeCylinder;
class ZcGeCone;
class ZcGeSphere;
class ZcGeTorus;

typedef ZcGePlane			AcGePlane;
typedef ZcGeBoundedPlane	AcGeBoundedPlane;
typedef ZcGeCylinder		AcGeCylinder;
typedef ZcGeCone			AcGeCone;
typedef ZcGeSphere			AcGeSphere;
typedef ZcGeTorus			AcGeTorus;

#include "..\inc\zgeoffsf.h"

typedef ZcGeOffsetSurface AcGeOffsetSurface;

#endif
