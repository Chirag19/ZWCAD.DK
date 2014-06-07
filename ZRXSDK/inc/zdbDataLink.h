
#pragma once

#include "ZcString.h"


class ZcValue;
class ZcDbLinkedData;
class ZcDbDataLink;
class ZcDbDataLinkManager;
class ZcDbImpDataLinkManager;
class ZcDbDataAdapter;
class ZcTableSystemInternals;


#define ZCDB_DATA_ADAPTER_EXCEL         ZCRX_T("ZcExcel")



class ZcDbDataLink : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDataLink);

    ZcDbDataLink(void);
    virtual ~ZcDbDataLink(void);

    ZcString name                 (void) const;
    Zcad::ErrorStatus setName     (const ZCHAR* pszName);
    const ZCHAR* description      (void) const;
    Zcad::ErrorStatus setDescription(const ZCHAR* pszDescription);
    ZcString getToolTip           (void) const;
    Zcad::ErrorStatus setToolTip  (const ZCHAR* pszToolTip);
    const ZCHAR* dataAdapterId    (void) const;
    Zcad::ErrorStatus setDataAdapterId(const ZCHAR* pszAdapterId);
    const ZCHAR* connectionString (void) const;
    Zcad::ErrorStatus setConnectionString(const ZCHAR* pszConnectionString);
    ZcDb::DataLinkOption option   (void) const;
    Zcad::ErrorStatus setOption   (ZcDb::DataLinkOption nOption);
    int   updateOption            (void) const;
    Zcad::ErrorStatus setUpdateOption(int nOption);
     Zcad::ErrorStatus update      (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);
     Zcad::ErrorStatus getUpdateStatus(ZcDb::UpdateDirection* pDir, 
                                             SYSTEMTIME* pTime, 
                                             ZcString* pErrMessage) const;
     Zcad::ErrorStatus setUpdateStatus(const ZCHAR* pszErrMessage);
     bool  isValid                 (void) const;
     int   getTargets              (ZcDbObjectIdArray& targetIds) const;
     Zcad::ErrorStatus getSourceFiles(ZcDb::DataLinkGetSourceContext nContext, 
                                             ZcStringArray& files) const;
     Zcad::ErrorStatus repathSourceFiles(LPCTSTR pszBasePath, 
                                             ZcDb::PathOption nOption);
     Zcad::ErrorStatus getCustomData(const ZCHAR* pszKey, 
                                             ZcValue* pData) const;
     Zcad::ErrorStatus setCustomData(const ZCHAR* pszKey, 
                                             const ZcValue* pData);

     virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
     virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
     virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
     virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};

typedef ZcArray<ZcDbDataLink*> ZcDbDataLinkArray;



class ZcDbDataLinkManager : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDataLinkManager);

    ZCDB_PORT virtual ~ZcDbDataLinkManager(void);

    ZCDB_PORT Zcad::ErrorStatus createDataLink(const ZCHAR* pszAdapterId, 
                                             const ZCHAR* pszName, 
                                             const ZCHAR* pszDescription, 
                                             const ZCHAR* pszConnectionString, 
                                             ZcDbObjectId& idDataLink);
    ZCDB_PORT Zcad::ErrorStatus getDataLink (const ZCHAR* pszName, 
                                             ZcDbObjectId& idDataLink) const;
    ZCDB_PORT Zcad::ErrorStatus getDataLink (const ZCHAR* pszName, 
                                             ZcDbDataLink*& pDataLink, 
                                             ZcDb::OpenMode mode) const;
    ZCDB_PORT int   dataLinkCount           (void) const;
    ZCDB_PORT int   getDataLink             (ZcDbObjectIdArray& dataLinks) const;
    ZCDB_PORT Zcad::ErrorStatus addDataLink (ZcDbDataLink* pDataLink);
    ZCDB_PORT Zcad::ErrorStatus addDataLink (ZcDbDataLink* pDataLink, 
                                             ZcDbObjectId& idDataLink);
    ZCDB_PORT Zcad::ErrorStatus removeDataLink        (const ZCHAR* pszKey, 
                                             ZcDbObjectId& idDataLink);
    ZCDB_PORT Zcad::ErrorStatus removeDataLink(const ZcDbObjectId& idDataLink);

    ZCDB_PORT Zcad::ErrorStatus update      (const ZcDbObjectIdArray& dataIds, 
                                             ZcDb::UpdateDirection nDir,
                                             ZcDb::UpdateOption nOption);
    ZCDB_PORT Zcad::ErrorStatus update      (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);

protected:
    ZCDB_PORT ZcDbDataLinkManager(void);

private:
    void        *   mpImpObj;
    friend ZcTableSystemInternals;
    friend ZcDbImpDataLinkManager;
};
