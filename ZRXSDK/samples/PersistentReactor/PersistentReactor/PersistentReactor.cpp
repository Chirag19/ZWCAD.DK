#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <string.h>
#include <stdlib.h>
#include "ZcObjectNotify.h"


bool addEntityToDb(ZcDbObjectId& entId, ZcDbEntity * pEnt)
{
	ZcDbDatabase * pDb = zcdbHostApplicationServices()->workingDatabase();

	if (!pDb) return false;

	ZcDbBlockTable* pTbl = NULL;
	if (Zcad::eOk != pDb->getBlockTable(pTbl, ZcDb::kForRead) )
		return false;

	ZcDbBlockTableRecord* pTblRec = NULL;
	if (Zcad::eOk != pTbl->getAt(ZCDB_MODEL_SPACE, pTblRec, ZcDb::kForWrite))
	{
		pTbl->close();
		return false;
	}

	pTbl->close();

	if (Zcad::eOk != pTblRec->appendZcDbEntity(entId, pEnt))
	{
		pTblRec->close();
		return false;
	}

	pTblRec->close();

	return true;
}



void assocCircles()
{
	ZcDbDatabase *pDb = zcdbHostApplicationServices()->workingDatabase();
	ZcDbObjectId aId, bId;

	ZcDbCircle *pCircleA = new ZcDbCircle;
	pCircleA->setDatabaseDefaults(pDb);
	pCircleA->setCenter(ZcGePoint3d(1, 1, 0));
	pCircleA->setRadius(10);
	addEntityToDb(aId, pCircleA);

	zds_printf( "Circle A is %lx.\n", pCircleA->objectId());

	ZcDbCircle *pCircleB = new ZcDbCircle;
	pCircleB->setDatabaseDefaults(pDb);
	pCircleB->setCenter(ZcGePoint3d(1, 1, 0));
	pCircleB->setRadius(20);
	addEntityToDb(bId, pCircleB);

	zds_printf("Circle B is %lx.\n", pCircleB->objectId());

	ZcDbDictionary *pNamedObj;
	ZcDbDictionary *pNameList;
	pDb->getNamedObjectsDictionary(pNamedObj,ZcDb::kForWrite);
	if (pNamedObj->getAt("OBJ_NOTIFY_DICT", (ZcDbObject*&)pNameList, ZcDb::kForWrite) == Zcad::eKeyNotFound)
	{
		pNameList = new ZcDbDictionary;
		ZcDbObjectId DictId;
		pNamedObj->setAt("OBJ_NOTIFY_DICT", pNameList, DictId);
	}

	pNamedObj->close();

	ZcObjectNotify *pObj = new ZcObjectNotify();
	pObj->eLinkage(bId);

	ZcDbObjectId objId;
	if ((pNameList->getAt("object_notify_A", objId))	== Zcad::eKeyNotFound)
	{
		pNameList->setAt("object_notify_A", pObj, objId);
		pObj->close();
		pCircleA->addPersistentReactor(objId);
		
	} 
	else
	{
		delete pObj;
		zds_printf("object_notify_A already exists\n");
	}
	pCircleA->close();
	

	pObj = new ZcObjectNotify();
	pObj->eLinkage(aId);

	if ((pNameList->getAt("object_notify_B", objId))	== Zcad::eKeyNotFound)
	{
		pNameList->setAt("object_notify_B", pObj, objId);
		pObj->close();
		pCircleB->addPersistentReactor(objId);
	}
	else
	{
		delete pObj;
		zds_printf("object_notify_B already exists\n");
	}
	pNameList->close();

	pCircleB->close();

	

	
	
}



void initApp()
{
	zcedRegCmds->addCommand("AssocCmdGroup", "AssocCircle",	"AssocCircle", ZCRX_CMD_MODAL, assocCircles);

	ZcObjectNotify::rxInit();
	zcrxBuildClassHierarchy();
}


void unloadApp()
{
	zcedRegCmds->removeGroup("AssocCmdGroup");

	deleteZcRxClass(ZcObjectNotify::desc());
}


// entry point
ZcRx::AppRetCode zcrxEntryPoint(ZcRx::AppMsgCode msg, void* appId)
{
	switch (msg)
	{
	case ZcRx::kInitAppMsg:
		zcrxDynamicLinker->unlockApplication(appId);
		zcrxDynamicLinker->registerAppMDIAware(appId);
		initApp();
		break;
	case ZcRx::kUnloadAppMsg:
		unloadApp();
	}
	return ZcRx::kRetOK;
}


