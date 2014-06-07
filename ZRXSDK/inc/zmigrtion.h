#ifndef ZDB_MIGRATION_H
#define ZDB_MIGRATION_H


#include "zdsmigr.h"
#include "zcutmigr.h"

#define zcdbSetCurrentVPort zcedSetCurrentVPort
//#define zcdbGetCurrentSelectionSet zcedGetCurrentSelectionSet


#define zcdbCurDwg zcdbHostApplicationServices()->workingDatabase

#define  zcdbGetRGB zcedGetRGB

#define zcdbGetCurViewportObjectId zcedGetCurViewportObjectId

#define getCurDwgXrefGraph zcedGetCurDwgXrefGraph

#endif
