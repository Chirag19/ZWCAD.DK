#ifndef _ARXPORT_AC_DBNAMEDPATH_H_
#define _ARXPORT_AC_DBNAMEDPATH_H_ 1

#include "dbmain.h"

class ZcDbImpNamedPath;

typedef ZcDbImpNamedPath AcDbImpNamedPath ;

#include "..\inc\zdbNamedPath.h"

#define ACDB_NAMEDPATH_DICTIONARY		ZCDB_NAMEDPATH_DICTIONARY
#define acdbGetNamedPathDictionary		zcdbGetNamedPathDictionary

typedef ZcDbNamedPath		AcDbNamedPath;
typedef ZcDbCurvePath		AcDbCurvePath;
typedef ZcDbPointPath		AcDbPointPath;

#endif