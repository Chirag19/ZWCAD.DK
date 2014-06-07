#ifndef ZD_XGRAPH_H
#define ZD_XGRAPH_H 1

#include "Zgraph.h"
#include "ZdZChar.h"

#pragma pack (push, 8)

class ZcDbXrefGraphNode : public ZcDbGraphNode
{
public:
    ZcDbXrefGraphNode(const ZCHAR * pName = NULL,
        const ZcDbObjectId& btrId = ZcDbObjectId::kNull,
        ZcDbDatabase* pDb = NULL,
        ZcDb::XrefStatus status = ZcDb::kXrfResolved);
    virtual ~ZcDbXrefGraphNode();

    const ZCHAR * name() const;
    ZcDbObjectId btrId() const;
    ZcDbDatabase* database() const;

    Zcad::ErrorStatus setName(const ZCHAR * pName);
    void setBtrId(const ZcDbObjectId& id);
    void setDatabase(ZcDbDatabase* pDb);

    bool isNested() const;

    ZcDb::XrefStatus xrefStatus() const;
    void setXrefStatus(ZcDb::XrefStatus stat);

    ZcDb::XrefNotificationStatus xrefNotificationStatus() const;
    void setXrefNotificationStatus(ZcDb::XrefNotificationStatus stat);

    void*   xData() { return mpxdata; }
    void    setxData(void *pXData) { mpxdata = pXData; }

    Zcad::ErrorStatus xrefReadSubstatus() const;

private:
    void* mpxdata; 
    ZCHAR * mpName;
    ZcDbObjectId mBtrId;
	ZcDb::XrefStatus mStatus;
    ZcDb::XrefNotificationStatus mNotifyStatus;
};


class ZcDbXrefGraph : public ZcDbGraph
{
public:
    ZcDbXrefGraph(ZcDbXrefGraphNode* pHostDwg = NULL);
    virtual ~ZcDbXrefGraph();

    ZcDbXrefGraphNode* xrefNode(const ZCHAR * pName) const;
    ZcDbXrefGraphNode* xrefNode(ZcDbObjectId btrId) const;
    ZcDbXrefGraphNode* xrefNode(const ZcDbDatabase* pDb) const;

    ZcDbXrefGraphNode* xrefNode(int idx) const;
    ZcDbXrefGraphNode*  hostDwg() const;

    Zdesk::Boolean markUnresolvedTrees ();

    
    virtual Zdesk::Boolean findCycles(ZcDbGraphNode* pStart = NULL);
};




Zcad::ErrorStatus zcedGetCurDwgXrefGraph(ZcDbXrefGraph&,
    Zdesk::Boolean includeGhosts = Zdesk::kFalse);



#pragma pack (pop)

#endif

