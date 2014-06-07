#include "StdAfx.h"
#include "HDataTable.h"
#include "ZwInteFuncts.h"
#include <map>

#pragma comment(lib,"Shlwapi.lib")


bool addEntityToDb( ZcDbEntity* pEntity, ZcDbObjectId& objId ,ZcDbDatabase * pDb)
{
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

	if (Zcad::eOk != pTblRec->appendZcDbEntity(objId, pEntity))
	{
		pTblRec->close();
		return false;
	}

	pTblRec->close();

	return true;
}

bool addEntityToDb( ZcDbEntity* pEntity ,ZcDbDatabase * pDb)
{
	ZcDbObjectId objId;
	return addEntityToDb( pEntity, objId ,pDb);
}

bool InsertBmpFile(LPCTSTR insBmpPath,double fHeight,double fWidth,ZcGePoint3d posCentPt,ZcDbDatabase* pDb)
{
	if(!PathFileExists(insBmpPath))
	{
		return false;
	}
	// Open the Image Dictionary 
	ZcDbObjectId imageDictId = ZcDbRasterImageDef::imageDictionary(pDb);
	if(imageDictId.isNull())
	{

		ZcDbRasterImageDef::createImageDictionary(pDb,imageDictId);
	}

	ZcDbDictionary* pImageDict;
	zcdbOpenObject(pImageDict,imageDictId,ZcDb::kForWrite);
	// Create ImageDef Object
	ZcDbRasterImageDef* pInsImgDef = new ZcDbRasterImageDef();
	ZcDbObjectId imageDefId;
	pImageDict->setAt(_T("IMGE"), pInsImgDef,imageDefId);
	pInsImgDef->setSourceFileName(insBmpPath);	

	// Create an Image object                         
	ZcDbRasterImage* pImage = new ZcDbRasterImage();
	pImage->setDatabaseDefaults(pDb);

	ZcGePoint3d originPt;
	originPt.x = posCentPt.x - fWidth/2;
	originPt.y = posCentPt.y - fHeight/2;
	// Set some parameters 
	pImage->setImageDefId(imageDefId);
	pImage->setOrientation(originPt, ZcGeVector3d(fWidth, 0, 0), ZcGeVector3d(0.0, fHeight, 0));
	pImage->setDisplayOpt(ZcDbRasterImage::kShow, true);
	pImage->setDisplayOpt(ZcDbRasterImage::kShowUnAligned, true);

	if(!addEntityToDb(pImage,pDb)) return false;
	pImageDict->objectClosed(imageDictId);

	pInsImgDef->objectClosed(pInsImgDef->objectId());
	pImage->close();
	pInsImgDef->close();

	return true;
}

bool InsertDwgFile(LPCTSTR insDwgPath,double fHeight,double fWidth,ZcGePoint3d posCentPt,ZcDbDatabase* pDb)
{
	if(!PathFileExists(insDwgPath))
	{
		return false;
	}

	ZcDbDatabase* pInsDwgDb = new ZcDbDatabase(false);
	pInsDwgDb->readDwgFile(insDwgPath);
	ZcDbObjectId blkId;
	pDb->insert(blkId,"*U",pInsDwgDb);
	if(blkId.isNull())
	{
		delete pInsDwgDb;
		return false;
	}

	ZcGePoint3d originPt;
	originPt.x = posCentPt.x - fWidth/2;
	originPt.y = posCentPt.y - fHeight/2;

	ZcDbBlockReference* pBlkRef = new ZcDbBlockReference();
	pBlkRef->setBlockTableRecord(blkId);

	ZcDbObjectId entId;
	if(!addEntityToDb(pBlkRef,entId,pDb))
	{
		delete pInsDwgDb;
		delete pBlkRef;
		return false;
	}

	// Set some parameters 
	pBlkRef->setPosition(originPt);
	pBlkRef->setRotation(0);
	ZcDbExtents ent;
	pBlkRef->getGeomExtents(ent);
	double h = ent.maxPoint().y - ent.minPoint().y;
	double w = ent.maxPoint().x - ent.minPoint().x;
    ZcGeScale3d XrefScale(fWidth/w,fHeight/h,1);
	pBlkRef->setScaleFactors( XrefScale);	
	pBlkRef->close();
	delete pInsDwgDb;

	return true;
}


BOOL  InsertBmpToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef, bool IsPaperSpace)
{
	bool bIsCurDwgDb = false;
	ZcDbDatabase* pFileDb = NULL;
	if (strcmp(strDwgPath,"") == 0)
	{
		pFileDb = zcdbHostApplicationServices()->workingDatabase();
		bIsCurDwgDb = true;

	}
	else
	{
		if(!PathFileExists(strDwgPath)) 
		{
			return FALSE;
		}
		pFileDb = new ZcDbDatabase(false);
		pFileDb->readDwgFile(strDwgPath);
	}

	ZcDbBlockTable* pTbl = NULL;
	pFileDb->getBlockTable(pTbl, ZcDb::kForRead);

	ZcDbBlockTableRecord* pBlkTblRec=NULL;
	if(IsPaperSpace == true)
	{
		pTbl->getAt(ZCDB_PAPER_SPACE, pBlkTblRec, ZcDb::kForWrite);
	}
	else
	{
		pTbl->getAt(ZCDB_MODEL_SPACE, pBlkTblRec, ZcDb::kForWrite);
	}

	pTbl->close();
	ZcGePoint3d btlRbPt;
	double fPlotScale = 1;
	ZcDbBlockTableRecordIterator* pEntIter;
	pBlkTblRec->newIterator(pEntIter);
	ZcDbEntity* pEnt;
	pBlkTblRec->close();

	for (pEntIter->start(); !pEntIter->done(); pEntIter->step())
	{
		pEntIter->getEntity(pEnt, ZcDb::kForRead); 
		if (!pEnt)
		{
			continue;
		}

		if (!pEnt->isKindOf(ZcDbBlockReference::desc()))
		{
			pEnt->close();
			continue;
		}
		ZcDbBlockReference* pBlkRef = (ZcDbBlockReference*)pEnt;
		ZcDbObjectId blkRecId = pBlkRef->blockTableRecord();
		ZcDbBlockTableRecord* pBlkRec;
		if (Zcad::eOk != zcdbOpenObject(pBlkRec,blkRecId,ZcDb::kForRead))
		{
			pEnt->close();
			continue;
		}

		ZcString zcsBlkName;
		pBlkRec->getName(zcsBlkName);
	
		if( zcsBlkName == "ZW_BTL_BLK" )
		{
			ZcGeScale3d blkScale =pBlkRef->scaleFactors();
			fPlotScale = 1.0/blkScale.sx;
			btlRbPt = pBlkRef->position();
			break;

		}

	}
	delete pEntIter;

	CString strVal;
	strVal = strTitleDef;
	CString bmpFilePath;
	int pos = strVal.Find("{");
	bmpFilePath = (const char *)strVal.Left(pos);
	bmpFilePath.TrimLeft();

	ZcGeVector3d posCenPt;
	double h,w;
	CString strPosition = strVal.Mid(pos+1);
	pos = strPosition.Find(",");
	w = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	pos = strPosition.Find(",");
	h = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	pos = strPosition.Find(",");
	posCenPt.x = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	posCenPt.y = atof(strPosition)/fPlotScale;

	if( !InsertBmpFile(bmpFilePath,h,w,btlRbPt+posCenPt,pFileDb) )
	{
		if(!bIsCurDwgDb) delete pFileDb;
		return FALSE;
	}

	if(!bIsCurDwgDb) 
	{
		pFileDb->saveAs((CString)strDwgPath);
		delete pFileDb;
	}

	return TRUE;
}

BOOL  InsertTextToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef, bool IsPaperSpace)
{
	bool bIsCurDwgDb = false;
	ZcDbDatabase* pFileDb = NULL;
	if (strcmp(strDwgPath,"") == 0)
	{
		pFileDb = zcdbHostApplicationServices()->workingDatabase();
		bIsCurDwgDb = true;

	}
	else
	{
		if(!PathFileExists(strDwgPath)) 
		{
			return FALSE;
		}
		pFileDb = new ZcDbDatabase(false);
		pFileDb->readDwgFile(strDwgPath);
	}

	ZcDbBlockTable* pTbl = NULL;
	pFileDb->getBlockTable(pTbl, ZcDb::kForRead);

	ZcDbBlockTableRecord* pBlkTblRec=NULL;
	if(IsPaperSpace == true)
	{
		pTbl->getAt(ZCDB_PAPER_SPACE, pBlkTblRec, ZcDb::kForWrite);
	}
	else
	{
		pTbl->getAt(ZCDB_MODEL_SPACE, pBlkTblRec, ZcDb::kForWrite);
	}

	pTbl->close();
	bool bHasBtlBlk = false;
	ZcGePoint3d btlRbPt;
	double fPlotScale = 1;
	ZcDbBlockTableRecordIterator *pEntIter;
	pBlkTblRec->newIterator(pEntIter);
	ZcDbEntity* pEnt;
	pBlkTblRec->close();

	for (pEntIter->start(); !pEntIter->done(); pEntIter->step())
	{
		pEntIter->getEntity(pEnt, ZcDb::kForRead); 
		if (!pEnt)
		{
			continue;
		}
		//获取图元类型
		if (!pEnt->isKindOf(ZcDbBlockReference::desc()))
		{
			pEnt->close();
			continue;
		}
		ZcDbBlockReference* pBlkRef = (ZcDbBlockReference*)pEnt;
		ZcDbObjectId blkRecId = pBlkRef->blockTableRecord();
		ZcDbBlockTableRecord* pBlkRec;
		if (Zcad::eOk != zcdbOpenObject(pBlkRec,blkRecId,ZcDb::kForRead))
		{
			pEnt->close();
			continue;
		}

		ZcString zcsBlkName;
		pBlkRec->getName(zcsBlkName);
		pBlkRec->close();
		if( zcsBlkName == "ZW_BTL_BLK" )
		{
			ZcGeScale3d blkScale =pBlkRef->scaleFactors();
			fPlotScale = 1.0/blkScale.sx;
			btlRbPt = pBlkRef->position();
			bHasBtlBlk = true;
			break;

		}

		pEnt->close();
	}

	delete pEntIter;
	//解析定义
	CString strVal;
	strVal = strTitleDef;
	CString strText;
	int pos = strVal.Find("{");
	strText = strVal.Left(pos);

	ZcGeVector3d posCenPt;
	double h,w;
	CString strPosition = strVal.Mid(pos+1);
	pos = strPosition.Find(",");
	w = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	pos = strPosition.Find(",");
	h = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	pos = strPosition.Find(",");
	posCenPt.x = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	posCenPt.y = atof(strPosition)/fPlotScale;

	//生成文本
	ZcDbText* pText = new ZcDbText();
	pText->setTextString(strText);
	pText->setHeight(h);
	pText->setHorizontalMode(ZcDb::kTextMid);
	pText->setVerticalMode(ZcDb::kTextTop);
	pText->setPosition(btlRbPt+posCenPt);
	pText->setAlignmentPoint(btlRbPt+posCenPt);
	pText->setWidthFactor(1);

	if (!addEntityToDb(pText,pFileDb))
	{
		if (!bIsCurDwgDb) delete pFileDb;
		return FALSE;
	}
	pText->close();

	if (!bIsCurDwgDb)
	{
		pFileDb->saveAs((CString)strDwgPath);
		delete pFileDb;
	}

	return TRUE;

}

BOOL  InsertDwgToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef,bool IsPaperSpace )
{
	bool bIsCurDwgDb = false;
	ZcDbDatabase* pFileDb = NULL;
	if (strcmp(strDwgPath,"") == 0)
	{
		pFileDb = zcdbHostApplicationServices()->workingDatabase();
		bIsCurDwgDb = true;

	}
	else
	{
		if(!PathFileExists(strDwgPath)) 
		{
			return FALSE;
		}
		pFileDb = new ZcDbDatabase(false);
		pFileDb->readDwgFile(strDwgPath);
	}

	ZcDbBlockTable* pTbl = NULL;
	pFileDb->getBlockTable(pTbl, ZcDb::kForRead);

	ZcDbBlockTableRecord* pBlkTblRec = NULL;
	if(IsPaperSpace == true)
	{
		pTbl->getAt(ZCDB_PAPER_SPACE, pBlkTblRec, ZcDb::kForWrite);
	}
	else
	{
		pTbl->getAt(ZCDB_MODEL_SPACE, pBlkTblRec, ZcDb::kForWrite);
	}

	pTbl->close();
	ZcGePoint3d btlRbPt;
	double fPlotScale = 1;
	ZcDbBlockTableRecordIterator *pEntIter;
	pBlkTblRec->newIterator(pEntIter);
	ZcDbEntity* pEnt;
	pBlkTblRec->close();
	for (pEntIter->start(); !pEntIter->done(); pEntIter->step())
	{
		pEntIter->getEntity(pEnt, ZcDb::kForRead); 
		if (!pEnt)
		{
			continue;
		}

		if (!pEnt->isKindOf(ZcDbBlockReference::desc()))
		{
			pEnt->close();
			continue;
		}

		ZcDbBlockReference* pBlkRef = (ZcDbBlockReference*)pEnt;

		ZcDbObjectId blkRecId = pBlkRef->blockTableRecord();
		ZcDbBlockTableRecord* pBlkRec;
		if (Zcad::eOk != zcdbOpenObject(pBlkRec,blkRecId,ZcDb::kForRead))
		{
			pEnt->close();
			continue;
		}

		ZcString strBlkName = "";
		pBlkRec->getName(strBlkName);
		//标题栏
		if( strBlkName == "ZW_BTL_BLK" )
		{
			ZcGeScale3d blkScale =pBlkRef->scaleFactors();
			fPlotScale = 1.0/blkScale.sx;
			btlRbPt = pBlkRef->position();
			break;
		}
		pEnt->close();
	}
	delete pEntIter;

	CString strVal;
	strVal = strTitleDef;
	CString dwgFilePath;
	int pos = strVal.Find("{");
	dwgFilePath = (const char *)strVal.Left(pos);
	dwgFilePath.TrimLeft();

	ZcGeVector3d posCenPt;
	double h,w;
	CString strPosition = strVal.Mid(pos+1);
	pos = strPosition.Find(",");
	w = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	pos = strPosition.Find(",");
	h = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	pos = strPosition.Find(",");
	posCenPt.x = atof(strPosition.Left(pos))/fPlotScale;
	strPosition = strPosition.Mid(pos+1);
	posCenPt.y = atof(strPosition)/fPlotScale;

	if (!InsertDwgFile(dwgFilePath,h,w,btlRbPt+posCenPt,pFileDb) )
	{
		if (!bIsCurDwgDb) delete pFileDb;
		return FALSE;
	}

	if (!bIsCurDwgDb)
	{
		pFileDb->saveAs((CString)strDwgPath);
		delete pFileDb;
	}

	return TRUE;
}

bool GetTextWidthLen(const CString& strMsg, double dTextHeight, ZcDbObjectId txtstlId, double &dTextWidthLen)
{
	if (txtstlId.isNull())
	{
		return false;
	}

	ZcDbTextStyleTableRecord* pRec = NULL;
	zcdbOpenObject(pRec,txtstlId,ZcDb::kForWrite);
	double dTextHeightOld = pRec->textSize();
	double dTextWidthOld = pRec->xScale();
	pRec->setTextSize(dTextHeight);

	ZcGiTextStyle gistyle;
	fromZcDbTextStyle(gistyle, txtstlId);
	gistyle.setXScale(1.0);
	
	pRec->setTextSize(dTextHeightOld);
	pRec->setXScale(dTextWidthOld);

	ZcGePoint2d box;
	box = gistyle.extents(strMsg, FALSE, -1, FALSE);

	dTextWidthLen = box.x;
	pRec->close();
	return true;
}

double TextWidth(CString& stext,double fTxtHeight,ZcDbObjectId styleId,double fWidthFac)
{
	ZcGePoint3d pt(0,0,0);	
	ZcDbExtents extents;
	ZcDbText* pText = new ZcDbText();
	pText->setPosition(pt);
	pText->setTextString(stext);
	pText->setTextStyle(styleId);
	pText->setWidthFactor(fWidthFac);
	
	pText->getGeomExtents(extents);
	double dx = extents.maxPoint().x - extents.minPoint().x;
	delete pText;
	return dx;
}

