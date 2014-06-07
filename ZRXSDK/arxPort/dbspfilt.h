#ifndef _ARXPORT_AC_DBSPFILT_H_
#define _ARXPORT_AC_DBSPFILT_H_ 1


#include "dbfilter.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#include "gept2dar.h"

class ZcDbExtents;

typedef ZcDbExtents AcDbExtents ;
#include "..\inc\zdbspfilt.h"

typedef	ZcDbSpatialFilter			AcDbSpatialFilter;

#define ACDB_INFINITE_XCLIP_DEPTH	ZCDB_INFINITE_XCLIP_DEPTH

#endif