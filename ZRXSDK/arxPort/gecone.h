#ifndef _ARXPORT_AC_GECONE_H_
#define _ARXPORT_AC_GECONE_H_ 1

#include "gegbl.h"
#include "geintrvl.h"
#include "gevec3d.h"
#include "gesurf.h"
#include "gearc3d.h"

class ZcGePoint3d;
class ZcGeVector3d;
class ZcGeCircArc3d;
class ZcGeInterval;
class ZcGeLinearEnt3d;

typedef	ZcGePoint3d			AcGePoint3d;
typedef ZcGeVector3d		AcGeVector3d;
typedef ZcGeCircArc3d		AcGeCircArc3d;
typedef ZcGeInterval		AcGeInterval;
typedef ZcGeLinearEnt3d		AcGeLinearEnt3d;

#include "..\inc\zgecone.h"

typedef ZcGeCone	AcGeCone;

#endif