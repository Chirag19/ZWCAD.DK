#define VC_EXTRALEAN	

#include <afxwin.h> 
#include "zimgdef.h"
#include "zimgent.h"
#include "zimgvars.h"
#include "zdbmain.h"
#include "zdbdict.h"
#include "zdbsymtb.h"
#include "zdbapserv.h"
#include "zmigrtion.h"
#include "Image.h"


extern CString g_strImageSource;

Zcad::ErrorStatus CustomImageApp::newImageAttach(ZcDbObjectId&  parEntityId)
{
	Zcad::ErrorStatus ErrStatus;
	ZcDbObjectId ImageDefObjId;			
	
	CString	strImageName;
	CString	strImagePath;

	strImageName = "ZrxImage";
	strImagePath = g_strImageSource;

	ErrStatus = createZcDbRasterImageDef(ImageDefObjId, strImageName, strImagePath);
	if (ErrStatus != Zcad::eOk)
	{
		return ErrStatus;
	}

	ErrStatus = createZcDbRasterImage	(parEntityId, ImageDefObjId);

	if (ErrStatus != Zcad::eOk)
	{
		return ErrStatus;
	}		

	return ErrStatus;
}

Zcad::ErrorStatus CustomImageApp::createZcDbRasterImage(ZcDbObjectId& parEntityId, ZcDbObjectId parObjectId)
{	
	Zcad::ErrorStatus ErrStatus;
	ZcDbRasterImage* pZcDbRasterImage;	

	pZcDbRasterImage = new ZcDbRasterImage;

	if ( pZcDbRasterImage == NULL)
	{
		return Zcad::eNullEntityPointer;
	}

	ErrStatus = pZcDbRasterImage->setImageDefId(parObjectId);
	
	if (ErrStatus != Zcad::eOk) 
	{
		delete pZcDbRasterImage;
		return ErrStatus;
	}

	double dFactor = dHeight / dWidth;
	pZcDbRasterImage->setOrientation(ZcGePoint3d(0,0,0), ZcGeVector3d(1,0,0), ZcGeVector3d(0,dFactor,0));
	pZcDbRasterImage->setDisplayOpt(ZcDbRasterImage::kShow, true);

	ErrStatus = appendToPaperOrModelSpace ((ZcDbEntity*) pZcDbRasterImage, Zdesk::kFalse);
	
	if (ErrStatus != Zcad::eOk) 
	{
		delete pZcDbRasterImage;
		return ErrStatus;
	}

	parEntityId = pZcDbRasterImage->objectId();

	pZcDbRasterImage->close();

	return ErrStatus;
}

Zcad::ErrorStatus CustomImageApp::createZcDbRasterImageDef(ZcDbObjectId& parObjectId, CString parImageName, CString parImagePath)
{
	Zcad::ErrorStatus ErrStatus;

	ZcDbRasterImageDef* pRasterImageDef = new ZcDbRasterImageDef;			
	
	if (pRasterImageDef == NULL)
	{
		return Zcad::eNullObjectPointer;
	}

	ErrStatus = zcdbHostApplicationServices()->workingDatabase()->addZcDbObject(parObjectId, pRasterImageDef);

	ErrStatus = pRasterImageDef->setSourceFileName(g_strImageSource);
	
	if (ErrStatus != Zcad::eOk) 
	{
		zcutPrintf("\n Could not find the image file."); 
		delete pRasterImageDef;
		return ErrStatus;
	}

	ErrStatus = pRasterImageDef->load(); 

	if (ErrStatus != Zcad::eOk) 
	{
		zcutPrintf("\n Could not open the image file."); 
		delete pRasterImageDef;
		return ErrStatus;
	}

	ZcDbObjectId DictionaryId;
	DictionaryId = ZcDbRasterImageDef::imageDictionary(zcdbHostApplicationServices()->workingDatabase());
	
	if (DictionaryId.asOldId() == 0) 
	{
		ErrStatus = ZcDbRasterImageDef::createImageDictionary(zcdbHostApplicationServices()->workingDatabase(), DictionaryId);
		
		if (ErrStatus!= Zcad::eOk)
		{
			delete pRasterImageDef;
			return ErrStatus;
		}
	}

	ZcDbDictionary* pDictionary;
	ErrStatus = zcdbOpenObject((ZcDbObject*&)pDictionary, DictionaryId, ZcDb::kForWrite);
	
	if (ErrStatus != Zcad::eOk)
	{
		delete pRasterImageDef;
		return ErrStatus;
	}

	Zdesk::Boolean bNameInUse;
	bNameInUse = pDictionary->has(parImageName);
	if (!bNameInUse) 
	{
		ErrStatus = pDictionary->setAt(parImageName, pRasterImageDef, parObjectId);
	}
	else
	{
		pDictionary->close();
		delete pRasterImageDef;
		return Zcad::eHandleInUse;
	}

	pDictionary->close();
	pRasterImageDef->close();

	ZcGeVector2d imageVect;
	imageVect = pRasterImageDef->size();
	dWidth = imageVect.x;
	dHeight = imageVect.y;

	return ErrStatus;
}

Zcad::ErrorStatus CustomImageApp::appendToPaperOrModelSpace (ZcDbEntity* parEntity, Zdesk::Boolean parbToPaperSpace)
{
	Zcad::ErrorStatus	ErrStatus;

	ZcDbDatabase* pDataBase;
	pDataBase = zcdbHostApplicationServices()->workingDatabase();
	
	if (pDataBase == NULL) 
	{
		return Zcad::eNoDatabase;
	}

	ZcDbBlockTable*	pBlockTable; 
	ErrStatus = pDataBase->getSymbolTable(pBlockTable, ZcDb::kForRead);

	if (ErrStatus != Zcad::eOk) 
	{
		return ErrStatus;
	}

	ZcDbBlockTableRecord* pBlockTableRecord;
	if (parbToPaperSpace)
	{		
		ErrStatus = pBlockTable->getAt(ZCDB_PAPER_SPACE, pBlockTableRecord, ZcDb::kForWrite);
	}
	else
	{
		ErrStatus = pBlockTable->getAt(ZCDB_MODEL_SPACE, pBlockTableRecord, ZcDb::kForWrite);
	}
	
	if (ErrStatus != Zcad::eOk)
	{
		pBlockTable->close();
		return ErrStatus;
	}

	ErrStatus = pBlockTableRecord->appendZcDbEntity (parEntity);

	pBlockTableRecord->close();
	pBlockTable->close();

	return ErrStatus;
}