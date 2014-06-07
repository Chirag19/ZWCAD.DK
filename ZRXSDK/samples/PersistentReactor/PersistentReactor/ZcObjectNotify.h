#pragma once

class ZcObjectNotify: public ZcDbObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcObjectNotify);

	ZcObjectNotify() {};

	virtual Zcad::ErrorStatus deepClone(ZcDbObject* pOwnerObject, ZcDbObject*& pClonedObject, ZcDbIdMapping& idMap, Zdesk::Boolean isPrimary=true) const;
	virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject, ZcDbObject*& pClonedObject, ZcDbIdMapping& idMap, Zdesk::Boolean isPrimary=true) const;

	Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler*);
	Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const;
	Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler*);
	Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const;

	virtual void openedForModify (const ZcDbObject* pDbObj);
	virtual void erased (const ZcDbObject* pDbObj, Zdesk::Boolean bErasing =true);
	virtual void modified (const ZcDbObject* pDbObj) ;

	void eLinkage(ZcDbObjectId i){ mId=i; }

private:
	ZcDbObjectId mId;
};
