#ifndef _ARXPORT_AC_DBMOTIONPATH_H_
#define _ARXPORT_AC_DBMOTIONPATH_H_ 1

#include "dbmain.h"

class ZcDbImpMotionPath;

typedef ZcDbImpMotionPath AcDbImpMotionPath ;
#include "..\inc\zdbMotionPath.h"

#define ACDB_MOTIONPATH_DICTIONARY			ZCDB_MOTIONPATH_DICTIONARY
#define acdbGetMotionPathDictionary			zcdbGetMotionPathDictionary

typedef ZcDbMotionPath				AcDbMotionPath;

#endif