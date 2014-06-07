#ifndef   _ZCDBLMGR_H
#define   _ZCDBLMGR_H

#include "zdesk.h"
#include "zdbid.h"
#include "zdblayout.h"
#include "zdblaymgrrctr.h"
#pragma pack (push, 8)

#define  MAX_PSPACE_LAYOUTS     256

class ZcDbObjectId;

class ZcDbLayoutManager: public ZcRxObject  {
  public:

    virtual Zcad::ErrorStatus 
        setCurrentLayout        (const ZCHAR * newname) = 0;
    virtual Zcad::ErrorStatus 
        setCurrentLayoutId      (ZcDbObjectId layoutId) = 0;
    virtual const ZCHAR *      
        findActiveLayout        (bool allowModel) = 0;

    virtual ZcDbObjectId      
        getActiveLayoutBTRId    () = 0;

    virtual ZcDbLayout *      
        findLayoutNamed         (const ZCHAR * name, 
                                 bool leaveRecordOpen = false) = 0;
    virtual Zcad::ErrorStatus 
        copyLayout              (const ZCHAR * copyname, 
                                 const ZCHAR * newname) = 0;

    virtual Zcad::ErrorStatus 
        deleteLayout            (const ZCHAR * delname) = 0;

    virtual Zcad::ErrorStatus 
        createLayout            (const ZCHAR *newname,
                                 ZcDbObjectId& layoutId, 
                                 ZcDbObjectId& blockTableRecId, 
                                 ZcDbDatabase* pDatabase = NULL) = 0;
    virtual Zcad::ErrorStatus 
        renameLayout            (const ZCHAR * oldname, 
                                 const ZCHAR * newname) = 0;

    virtual Zcad::ErrorStatus 
        cloneLayout             (ZcDbLayout* pLBTR, 
                                 const ZCHAR * newname, 
                                 int newTabOrder = 0) = 0;

    virtual ZcDbObjectId  
        getNonRectVPIdFromClipId (ZcDbObjectId clipId) = 0;

    virtual bool              
        isVpnumClipped          (int index) = 0;

    virtual int               
        countLayouts            (ZcDbDatabase *useDb = NULL) = 0;

    virtual void 
        addReactor              (ZcDbLayoutManagerReactor * newObj) = 0;

    virtual void 
        removeReactor           (ZcDbLayoutManagerReactor * delObj) = 0;
};

#ifndef _WIN64

Zcad::ErrorStatus zcdbDoSetupForLayouts(ZcDbDatabase* pDatabase,
                                        unsigned int& contextHandle);

Zcad::ErrorStatus zcdbClearSetupForLayouts(unsigned int contextHandle);
#else
Zcad::ErrorStatus zcdbDoSetupForLayouts(ZcDbDatabase* pDatabase,
                                        Zdesk::ULongPtr& contextHandle);

Zcad::ErrorStatus zcdbClearSetupForLayouts(Zdesk::ULongPtr contextHandle);
#endif

Zcad::ErrorStatus zcdbDeleteLayout (const ZCHAR* delname, ZcDbDatabase* pDb = NULL);

Zcad::ErrorStatus zcdbRenameLayout (const ZCHAR* oldname, 
                                    const ZCHAR* newname,
                                    ZcDbDatabase* pDb = NULL);

Zcad::ErrorStatus zcdbCopyLayout (const ZCHAR* copyname,
                                  const ZCHAR* newname,
                                  ZcDbDatabase* pDb = NULL);

#pragma pack (pop)
#endif 
