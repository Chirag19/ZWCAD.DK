#ifndef   _ZCDB_LAYOUT_MANAGER_REACTOR_H
#define   _ZCDB_LAYOUT_MANAGER_REACTOR_H

#include "zrxobject.h"
#include "zdbid.h"
#include "ZdZChar.h"
#pragma pack (push, 8)

class ZcDbImpLayoutManagerReactor;	

class ZcDbLayoutManagerReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLayoutManagerReactor);

	ZcDbLayoutManagerReactor();
	virtual ~ZcDbLayoutManagerReactor();

    virtual void layoutCreated(const ZCHAR * newLayoutName,
                               const ZcDbObjectId& layoutId);
    virtual void layoutToBeRemoved(const ZCHAR * layoutName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutRemoved(const ZCHAR * layoutName,
                               const ZcDbObjectId& layoutId);
    virtual void abortLayoutRemoved(const ZCHAR * layoutName,
                                    const ZcDbObjectId& layoutId);
    virtual void layoutToBeCopied(const ZCHAR * layoutName,
                                  const ZcDbObjectId& oldLayoutId);
    virtual void layoutCopied(const ZCHAR * oldLayoutName,
                              const ZcDbObjectId& oldLayoutId,
                              const ZCHAR * newLayoutname,
                              const ZcDbObjectId& newLayoutId);
    virtual void abortLayoutCopied(const ZCHAR * layoutName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutToBeRenamed(const ZCHAR * oldName,
                                   const ZCHAR * newName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutRenamed(const ZCHAR * oldName,
                               const ZCHAR * newName,
                               const ZcDbObjectId& layoutId);
    virtual void abortLayoutRename(const ZCHAR * oldName,
                                   const ZCHAR * newName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutSwitched(const ZCHAR * newLayoutname,
                                const ZcDbObjectId& newLayoutId);
    virtual void plotStyleTableChanged(const ZCHAR * newTableName,
                                       const ZcDbObjectId& layoutId);
    virtual void layoutsReordered();

public:
	ZcDbImpLayoutManagerReactor* mpImp;
};

#pragma pack (pop)
#endif 
