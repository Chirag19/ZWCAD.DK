#ifndef _ARXPORT_AC_DBMPOLYGON_H_
#define _ARXPORT_AC_DBMPOLYGON_H_ 1

#include "dbhatch.h"


class ZcDbCircle;
class ZcDb2dPolyline;
class ZcDbPolyline;
class ZcDbMPolygonCrossingArray;
class ZcDbMPolygonNode;



typedef ZcDbCircle                  AcDbCircle;
typedef ZcDb2dPolyline              AcDb2dPolyline;
typedef ZcDbPolyline                AcDbPolyline;
typedef ZcDbMPolygonCrossingArray   AcDbMPolygonCrossingArray;
typedef ZcDbMPolygonNode            AcDbMPolygonNode;

#include "..\inc\zdbMPolygon.h"

#define AcDbMPolygonCrossingFuzz			ZcDbMPolygonCrossingFuzz

typedef ZcDbMPolygon				AcDbMPolygon;
typedef ZcDbMpolygonLoops			AcDbMpolygonLoops;
typedef ZcDbMPolygonCrossing		AcDbMPolygonCrossing;



#endif