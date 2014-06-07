#ifndef _ARXPORT_DBACIS_H_
#define _ARXPORT_DBACIS_H_ 1

#include "acdb.h"
class ZcDbDwgFiler;
class ZcDbDxfFiler;

typedef ZcDbDwgFiler AcDbDwgFiler;
typedef ZcDbDxfFiler AcDbDxfFiler;

#include "..\inc\zdbacis.h"

#define acdbModelerStart					zcdbModelerStart
#define acdbIsModelerStarted				zcdbIsModelerStarted
#define acdbAcisSaveEntityToDwgFiler		zcdbAcisSaveEntityToDwgFiler
#define acdbAcisRestoreEntityFromDwgFiler	zcdbAcisRestoreEntityFromDwgFiler
#define acdbAcisSaveEntityToDxfFiler		zcdbAcisSaveEntityToDxfFiler
#define acdbAcisRestoreEntityFromDxfFiler	zcdbAcisRestoreEntityFromDxfFiler
#define acdbAcisSetDeleteBulletins			zcdbAcisSetDeleteBulletins
#define acdbAcisGetDeleteBulletins			zcdbAcisGetDeleteBulletins
#define acdbSetAcisDwgVer					zcdbSetAcisDwgVer
#define acdbAcisDeleteModelerBulletins		zcdbAcisDeleteModelerBulletins
#define acdbSaveAcisEntityToDwgFiler		zcdbSaveAcisEntityToDwgFiler
#define acdbRestoreAcisEntityFromDwgFiler	zcdbRestoreAcisEntityFromDwgFiler
#define acdbModelerEnd						zcdbModelerEnd

#endif
