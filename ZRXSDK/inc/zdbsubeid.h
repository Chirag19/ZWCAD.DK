#ifndef ZGEOMENT_DBSUBEID_H
#define ZGEOMENT_DBSUBEID_H


#include "zcdb.h"
#include "zdbidar.h"

#pragma pack (push, 8)

class ZcDbSubentId
{
public:
    ZcDbSubentId();
    ZcDbSubentId(ZcDb::SubentType type, Zdesk::GsMarker index);
    ZcDbSubentId(ZcRxClass* pTypeClass, Zdesk::GsMarker index);

    bool               operator ==(const ZcDbSubentId& id) const;
    bool               operator !=(const ZcDbSubentId& id) const;

    ZcDb::SubentType   type () const;
    void               setType(ZcDb::SubentType);
    ZcRxClass*         typeClass () const;
    void               setTypeClass(ZcRxClass* pClass);
    Zdesk::GsMarker    index() const;
    void               setIndex(Zdesk::GsMarker);
    
private:
    ZcDb::SubentType mType;
    Zdesk::GsMarker  mIndex;
    ZcRxClass*       mpTypeClass;
};

extern const ZcDbSubentId zNullSubentId;

const Zdesk::GsMarker zNullSubentIndex = 0;

class ZcDbFullSubentPath
{
public:
    ZcDbFullSubentPath();
    ZcDbFullSubentPath(ZcDb::SubentType type, Zdesk::GsMarker index);
    ZcDbFullSubentPath(ZcDbObjectId entId, ZcDb::SubentType type, Zdesk::GsMarker index);
    ZcDbFullSubentPath(ZcDbObjectId entId, ZcDbSubentId subId);
    ZcDbFullSubentPath(ZcDbObjectIdArray objectIds, ZcDbSubentId subId);
    ZcDbFullSubentPath(const ZcDbFullSubentPath&);
    ~ZcDbFullSubentPath();

    ZcDbFullSubentPath&     operator =  (const ZcDbFullSubentPath&);


    bool           operator ==(const ZcDbFullSubentPath& id) const;
    bool           operator !=(const ZcDbFullSubentPath& id) const;

    void                objectIds(ZcDbObjectIdArray& objectIds) const;
    ZcDbObjectIdArray&  objectIds();
    const ZcDbObjectIdArray&  objectIds() const;
    const ZcDbSubentId  subentId () const;
    ZcDbSubentId&       subentId ();
    
private:                            
    ZcDbObjectIdArray mObjectIds;
    ZcDbSubentId      mSubentId;
};



#pragma pack (pop)

#endif

