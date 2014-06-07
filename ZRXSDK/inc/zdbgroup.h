#ifndef ZCDB_DBGROUP_H
#define ZCDB_DBGROUP_H


#include "zdbmain.h"
#include "zdbapserv.h"

#pragma pack(push, 8)

class ZcDbGroupIterator;

class ZcDbGroup: public  ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbGroup);
    ZcDbGroup();
    ZcDbGroup(const ZCHAR * grpDesc, bool selectable = true);
    virtual ~ZcDbGroup();

    ZcDbGroupIterator*  newIterator();

    const ZCHAR *       description() const;
    Zcad::ErrorStatus   setDescription(const ZCHAR * grpDesc);

    bool                isSelectable() const;
    Zcad::ErrorStatus   setSelectable(bool selectable);

    const ZCHAR *       name() const;    
    Zcad::ErrorStatus   getName(ZCHAR *& name) const;
    Zcad::ErrorStatus   setName(const ZCHAR * newName);

    bool                isNotAccessible() const;

    bool                isAnonymous() const;
    Zcad::ErrorStatus   setAnonymous();

    Zcad::ErrorStatus   append(ZcDbObjectId id);
    Zcad::ErrorStatus   append(ZcDbObjectIdArray ids);
    Zcad::ErrorStatus   prepend(ZcDbObjectId id);
    Zcad::ErrorStatus   prepend(ZcDbObjectIdArray ids);
    Zcad::ErrorStatus   insertAt(Zdesk::UInt32 idx, ZcDbObjectId id);
    Zcad::ErrorStatus   insertAt(Zdesk::UInt32 idx, ZcDbObjectIdArray ids);
    Zcad::ErrorStatus   remove(ZcDbObjectId id);
    Zcad::ErrorStatus   removeAt(Zdesk::UInt32 idx);
    Zcad::ErrorStatus   remove(ZcDbObjectIdArray ids);
    Zcad::ErrorStatus   removeAt(Zdesk::UInt32 idx, ZcDbObjectIdArray ids);
    Zcad::ErrorStatus   replace(ZcDbObjectId oldId, ZcDbObjectId newId);
    Zcad::ErrorStatus   transfer(Zdesk::UInt32 fromIndex, 
                                 Zdesk::UInt32 toIndex, 
                                 Zdesk::UInt32 numItems);

    Zcad::ErrorStatus   clear();
    Zdesk::UInt32       numEntities() const;
    bool                has(const ZcDbEntity* pEntity) const;
    Zdesk::UInt32       allEntityIds(ZcDbObjectIdArray& ids) const;
    Zcad::ErrorStatus   getIndex(ZcDbObjectId id, Zdesk::UInt32& idx) const;
    Zcad::ErrorStatus   reverse();

    Zcad::ErrorStatus   setColor(const ZcCmColor& color);
    Zcad::ErrorStatus   setColorIndex(Zdesk::UInt16 color);
    Zcad::ErrorStatus   setLayer(const ZCHAR * newVal);
    Zcad::ErrorStatus   setLayer(ZcDbObjectId newVal);
    Zcad::ErrorStatus   setLinetype(const ZCHAR * newVal);
    Zcad::ErrorStatus   setLinetype(ZcDbObjectId newVal);
    Zcad::ErrorStatus   setLinetypeScale(double newval);
    Zcad::ErrorStatus   setVisibility(ZcDb::Visibility newVal);
    Zcad::ErrorStatus   setHighlight(bool newVal);

    Zcad::ErrorStatus   setMaterial(const ZCHAR * newVal);
    Zcad::ErrorStatus   setMaterial(ZcDbObjectId newVal);

    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* undoFiler,
                                               ZcRxClass*    classObj);

    virtual Zcad::ErrorStatus subClose();
    virtual Zcad::ErrorStatus subErase(Zdesk::Boolean erasing = true);

    virtual void              erased(const ZcDbObject* dbObj,
                                     Zdesk::Boolean erasing = true);
    virtual void              goodbye(const ZcDbObject* dbObj);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
	virtual void copied (const ZcDbObject* pObject, const ZcDbObject* pNewObject);
};



class ZDESK_NO_VTABLE ZcDbGroupIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGroupIterator);
    virtual ~ZcDbGroupIterator();

    virtual Zcad::ErrorStatus getObject(ZcDbObject*& pObject,
        ZcDb::OpenMode) = 0;
    virtual ZcDbObjectId      objectId () const = 0;

    virtual bool              done     () const = 0;
    virtual bool              next     () = 0;

protected:
    ZcDbGroupIterator();
};

#pragma pack(pop)

#endif
