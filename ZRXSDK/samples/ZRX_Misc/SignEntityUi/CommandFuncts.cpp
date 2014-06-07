#include "StdAfx.h"
#include "CommandFuncts.h"
#include "SignJig.h"
#include "..\SignEntityDb\SignEntity.h"


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

	Zcad::ErrorStatus es = pTblRec->appendZcDbEntity(entId, pEnt);
	if (Zcad::eOk != es)
	{
		pTblRec->close();
		return false;
	}

	pTblRec->close();

	return true;
}

void cmdCreateSign()
{
	SignEntity* pSignEnt = new SignEntity;

	SignJig jig;
	jig.startJig(pSignEnt);

	pSignEnt->close();
}

