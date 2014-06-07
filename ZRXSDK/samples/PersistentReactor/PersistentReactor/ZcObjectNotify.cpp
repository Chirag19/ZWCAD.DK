#include "StdAfx.h"
#include "ZcObjectNotify.h"


ZCRX_DXF_DEFINE_MEMBERS(ZcObjectNotify, ZcDbObject, ZcDb::kDHL_CURRENT, ZcDb::kMReleaseCurrent, 0, ZCOBJECTNOTIFY, PersistReactor);

void ZcObjectNotify::modified(const ZcDbObject* pObj)
{
	ZcDbCircle *pCircle = ZcDbCircle::cast(pObj);

	if (!pCircle) 
	{
		return;
	}

	zcutPrintf("\nReactor attached to %lx calling %lx.\n", pCircle->objectId(), mId);

	ZcDbCircle *pCircle2;
	if (zcdbOpenObject((ZcDbObject*&)pCircle2, mId,	ZcDb::kForWrite) == Zcad::eOk)
	{
		ZcGePoint3d centerPt3d = pCircle->center();
		pCircle2->setCenter(centerPt3d);
		pCircle2->close();
	}
}

void ZcObjectNotify::erased(const ZcDbObject* pObj,Zdesk::Boolean pErasing)
{
	ZcDbCircle *pCircle = ZcDbCircle::cast(pObj);

	if (!pCircle) 
	{
		return;
	}

	zcutPrintf("\nReactor attached to %lx calling %lx.\n", pCircle->objectId(), mId);

	ZcDbCircle *pCircle2;
	if (zcdbOpenObject((ZcDbObject*&)pCircle2, mId,	ZcDb::kForWrite) == Zcad::eOk)
	{
		pCircle2->erase();
		pCircle2->close();
	}
	return;
}

void ZcObjectNotify::openedForModify(const ZcDbObject* pObj)
{
	zcutPrintf("\nOpenedForModify is called successfully.\n");
	return;
}

Zcad::ErrorStatus ZcObjectNotify::deepClone (ZcDbObject *pOwnerObject, ZcDbObject *&pClonedObject, ZcDbIdMapping &idMap, Zdesk::Boolean isPrimary) const 
{
	return (ZcDbObject::deepClone (pOwnerObject, pClonedObject, idMap, isPrimary)) ;
}

Zcad::ErrorStatus ZcObjectNotify::wblockClone (ZcRxObject *pOwnerObject, ZcDbObject *&pClonedObject, ZcDbIdMapping &idMap, Zdesk::Boolean isPrimary) const
{
	return (ZcDbObject::wblockClone (pOwnerObject, pClonedObject, idMap, isPrimary)) ;
}


Zcad::ErrorStatus ZcObjectNotify::dwgInFields(ZcDbDwgFiler* filer)
{
	assertWriteEnabled();

	ZcDbObject::dwgInFields(filer);
	filer->readItem((ZcDbSoftPointerId*) &mId);
	return filer->filerStatus();
}



Zcad::ErrorStatus ZcObjectNotify::dwgOutFields(ZcDbDwgFiler* filer) const
{
	assertReadEnabled();

	ZcDbObject::dwgOutFields(filer);
	filer->writeItem((ZcDbSoftPointerId&)mId);
	return filer->filerStatus();
}


Zcad::ErrorStatus ZcObjectNotify::dxfInFields(ZcDbDxfFiler* filer)
{
	assertWriteEnabled();

	Zcad::ErrorStatus es;
	if ((es = ZcDbObject::dxfInFields(filer))
		!= Zcad::eOk)
	{
		return es;
	}

	if(!filer->atSubclassData("ZcObjectNotify"))
	{
		return Zcad::eBadDxfSequence;
	}

	struct resbuf rbIn;

	while (es == Zcad::eOk)
	{
		if ((es = filer->readItem(&rbIn)) == Zcad::eOk) 
		{
			if (rbIn.restype == ZcDb::kDxfSoftPointerId)
			{
				zcdbGetObjectId(mId, rbIn.resval.rlname);
			}
			else
			{   
				return(filer->pushBackItem());
			}
		}
	}
	return filer->filerStatus();
}

Zcad::ErrorStatus ZcObjectNotify::dxfOutFields(ZcDbDxfFiler* filer) const
{
	assertReadEnabled();

	ZcDbObject::dxfOutFields(filer);
	filer->writeItem(ZcDb::kDxfSubclass, "ZcObjectNotify");
	filer->writeItem(ZcDb::kDxfSoftPointerId, mId);
	return filer->filerStatus();
}
