
#ifndef _ARXPORT_AC_GEEXTSF_H_
#define _ARXPORT_AC_GEEXTSF_H_ 1

#include "gegbl.h"
#include "gesurf.h"

class ZcGePlane;
class ZcGeCylinder;
class ZcGeCone;
class ZcGeSphere;
class ZcGeTorus;
class ZcGeNurbSurface;
class Zsurface;

typedef ZcGePlane				AcGePlane;
typedef ZcGeCylinder			AcGeCylinder;
typedef ZcGeCone				AcGeCone;
typedef ZcGeSphere				AcGeSphere;
typedef ZcGeTorus				AcGeTorus;
typedef ZcGeNurbSurface			AcGeNurbSurface;
typedef Zsurface				surface;

#include "..\inc\zgeextsf.h"

typedef ZcGeExternalSurface		AcGeExternalSurface;

#endif 
