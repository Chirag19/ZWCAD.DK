#ifndef _ARXPORT_AD_XREFLOCK_H_
#define _ARXPORT_AD_XREFLOCK_H_ 1

#include "rxnames.h"
#include "dbidar.h"

class ZcDbDatabase;
class ZcDbIdMapping;
class ZcDwgFileHandle;

typedef ZcDbDatabase			AcDbDatabase;
typedef ZcDbIdMapping			AcDbIdMapping;
typedef ZcDwgFileHandle			AcDwgFileHandle;

#include "..\inc\zxreflock.h"

typedef ZcEdXrefFileLock			AcEdXrefFileLock;


#endif