#include "stdafx.h"
#include "XDataAndXDict.h"

bool selectEntity(ZcDbEntity*& pSelEntity, zds_point& epnt, ZcDb::OpenMode openMode)
{
	zds_name ename;
	if (RTNORM != zcedEntSel("\nSelect an entity:", ename, epnt))
	{
		zcutPrintf("\nError selecting the entity!");
		return false;
	}

	ZcDbObjectId eid;
	zcdbGetObjectId(eid, ename);

	if (Zcad::eOk != zcdbOpenObject(pSelEntity, eid, openMode))
	{
		zcutPrintf("\nError opening the entity!");
		return false;
	}	
	
	return true;
}


void attachXDataToEntity()
{
	zds_point pt;
	ZcDbEntity* pEnt = NULL;
	if (selectEntity(pEnt, pt, ZcDb::kForWrite))
	{
		resbuf* pRb = NULL;
		CHAR* appName ="ZW_XData"; 
		zcdbRegApp(appName);
		pRb = zcutBuildList(			-3,
			ZcDb::kDxfRegAppName,		appName,
			ZcDb::kDxfXdAsciiString,	"ZRX XData Example:",
			ZcDb::kDxfXdControlString,	"{",
			ZcDb::kDxfXdAsciiString,	"ZWCAD-ZRX",
			ZcDb::kDxfXdInteger16,		2011,
			ZcDb::kDxfXdReal,			1.1,
			ZcDb::kDxfXdWorldXCoord,	pt,
			ZcDb::kDxfXdControlString,	"}", 
			0);

		pEnt->setXData(pRb);

		zcutRelRb(pRb);
		pEnt->close();
	}
}

void attachXRecordToEntity()
{	
	zds_point pt;
	ZcDbEntity* pEnt = NULL;
	if (selectEntity(pEnt, pt, ZcDb::kForWrite)) 
	{
		pEnt->createExtensionDictionary();
		ZcDbObjectId dictObjId;
		dictObjId = pEnt->extensionDictionary();
		int intColorIndex = pEnt->colorIndex();
		pEnt->close();

		ZcDbDictionary* pDict = NULL;
		if (Zcad::eOk != zcdbOpenObject(pDict, dictObjId, ZcDb::kForWrite))
		{
			return;
		}
		
		ZcDbObjectId xrecObjId;
		ZcDbXrecord* pXRec = new ZcDbXrecord;	
		pDict->setAt("ZW_XRecord", pXRec, xrecObjId);
		pDict->close();

		resbuf* pRb = NULL;
		pRb = zcutBuildList(
			ZcDb::kDxfText,				"ZRX Xrecord Example:",	
			ZcDb::kDxfControlString,	"{",
			ZcDb::kDxfXTextString,		"ZWCAD ZRX",	
			ZcDb::kDxfInt16,			2011,
			ZcDb::kDxfReal,				1.1,
			ZcDb::kDxfXCoord,			pt,	
			ZcDb::kDxfControlString,	"}",
			0);

		pXRec->setFromRbChain(*pRb);
		pXRec->close();
		zcutRelRb(pRb);
	}
}

void listXDataFromEntity()
{	
	zds_point pt;
	ZcDbEntity *pEnt = NULL;

	if (!selectEntity(pEnt, pt, ZcDb::kForRead)) 
	{
		return;
	}

	resbuf* pRb = NULL;
	pRb = pEnt->xData("ZW_XData");
	pEnt->close();

	if (NULL == pRb)
	{
		zcutPrintf("\n This entity have not Xdata!");
		return;
	}

	resbuf*  pHead = pRb;

	while (pRb)
	{
		short intResType = pRb->restype;
		switch (intResType) 
		{
		case 1000:
		case 1001:
		case 1002:
		case 1003:
			zcutPrintf("\n%d: %s", intResType, pRb->resval.rstring);
			break;
		case 1070:
		case 1071:
			zcutPrintf("\n%d: %d", intResType, pRb->resval.rint);
			break;
		case 1040:
		case 1041:
		case 1042:
			zcutPrintf("\n%d: %.1f", intResType, pRb->resval.rreal);
			break;
		case 1010:
		case 1020:
		case 1030:
		case 1011:
		case 1021:
		case 1031:
			zcutPrintf("\n%d: %.3f,%.3f,%.3f", intResType, pRb->resval.rpoint[X], pRb->resval.rpoint[Y], pRb->resval.rpoint[Z]);
			break;
		default:
			break;
		}
		pRb = pRb->rbnext;
	}	
	
	zcutRelRb(pHead);
}


void listXRecordFromEntity()
{
	zds_point pt;
	ZcDbEntity *pEnt = NULL;
	
	if (!selectEntity(pEnt, pt, ZcDb::kForRead)) 
	{
		return;
	}
    
	ZcDbObjectId DicId = pEnt->extensionDictionary();
	pEnt->close();
	if(ZcDbObjectId::kNull == DicId)
	{
		zcutPrintf("\n This entity have not extension Dictionary!");
		return;
	}

	ZcDbDictionary* pDic = NULL;
	if (Zcad::eOk != zcdbOpenObject(pDic, DicId, ZcDb::kForRead))
	{
		zcutPrintf("\n Error opening the entity!");
		return;
	}

	ZcDbXrecord* pXrec = NULL;
	pDic->getAt("ZW_XRecord", (ZcDbObject*&)pXrec, ZcDb::kForRead);
	pDic->close();

	resbuf* pRb = NULL;
	pXrec->rbChain(&pRb);
	pXrec->close();

	if (NULL == pRb)
	{
		zcutPrintf("\nThis entity have not Xrecord!");
	}

	resbuf* pHead = pRb;

	while (pRb)
	{
		int intResType = pRb->restype;
		switch (intResType)
		{
		case 1:
		case 102:
		case 300:
			zcutPrintf("\n%d: %s", intResType, pRb->resval.rstring);
			break;
		case 70:
			zcutPrintf("\n%d: %d", intResType, pRb->resval.rint);
			break;
		case 40:
			zcutPrintf("\n%d: %.1f", intResType, pRb->resval.rreal);
			break;
		case 10:
		case 20:
		case 30:
			zcutPrintf("\n%d: %.3f, %.3f, %.3f", intResType, pRb->resval.rpoint[X], pRb->resval.rpoint[Y], pRb->resval.rpoint[Z]);
			break;
		default:
			break;
		}

		pRb = pRb->rbnext;
	}

	zcutRelRb(pHead);
}