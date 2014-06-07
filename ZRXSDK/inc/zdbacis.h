#ifndef ZDB_API_DBACIS_H
#define ZDB_API_DBACIS_H

#include "zcdb.h"
#pragma pack (push, 8)

class ZcDbDwgFiler;
class ZcDbDxfFiler;
class ENTITY;

extern "C"
{
	void zcdbModelerStart();
	void zcdbModelerEnd();
	Zdesk::Boolean zcdbIsModelerStarted();

    Zcad::ErrorStatus zcdbAcisSaveEntityToDwgFiler     (ZcDbDwgFiler* filer, 
							ENTITY*       ent);
    Zcad::ErrorStatus zcdbAcisRestoreEntityFromDwgFiler(ZcDbDwgFiler* filer, 
							ENTITY*&      ent);
    Zcad::ErrorStatus zcdbAcisSaveEntityToDxfFiler     (ZcDbDxfFiler* filer, 
                            ENTITY*       ent); 
    Zcad::ErrorStatus zcdbAcisRestoreEntityFromDxfFiler(ZcDbDxfFiler* filer, 
                            ENTITY*&      ent); 


    void           zcdbAcisSetDeleteBulletins(Zdesk::Boolean onOff);
    Zdesk::Boolean zcdbAcisGetDeleteBulletins();

	Zdesk::Boolean zcdbSetAcisDwgVer(int version);

    void           zcdbAcisDeleteModelerBulletins(void);
}


#define zcdbSaveAcisEntityToDwgFiler      zcdbAcisSaveEntityToDwgFiler
#define zcdbRestoreAcisEntityFromDwgFiler zcdbAcisRestoreEntityFromDwgFiler

#pragma pack (pop)
#endif
