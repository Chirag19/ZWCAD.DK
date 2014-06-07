#ifndef _ZSUMMINFO_H_
#define _ZSUMMINFO_H_

#include "zdesk.h"

#pragma pack (push, 8)


class ZDESK_NO_VTABLE ZcDbDatabaseSummaryInfo : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabaseSummaryInfo);

    virtual Zcad::ErrorStatus getTitle(ZCHAR*& title) const = 0;
    virtual Zcad::ErrorStatus setTitle(const ZCHAR* title) = 0;

    virtual Zcad::ErrorStatus getSubject(ZCHAR*& subject) const = 0;
    virtual Zcad::ErrorStatus setSubject(const ZCHAR* subject) = 0;

    virtual Zcad::ErrorStatus getAuthor(ZCHAR*& author) const = 0;
    virtual Zcad::ErrorStatus setAuthor(const ZCHAR* author) = 0;

    virtual Zcad::ErrorStatus getKeywords(ZCHAR*& keywordlist) const = 0;
    virtual Zcad::ErrorStatus setKeywords(const ZCHAR* keywordlist) = 0;

    virtual Zcad::ErrorStatus getComments(ZCHAR*& comments) const = 0;
    virtual Zcad::ErrorStatus setComments(const ZCHAR* comments) = 0;

    virtual Zcad::ErrorStatus getLastSavedBy(ZCHAR*& lastSavedBy) const = 0;
    virtual Zcad::ErrorStatus setLastSavedBy(const ZCHAR* lastSavedBy) = 0;

    virtual Zcad::ErrorStatus getRevisionNumber(ZCHAR*& revisionNumber) const = 0;
    virtual Zcad::ErrorStatus setRevisionNumber(const ZCHAR* revisionNumber) = 0;

    virtual Zcad::ErrorStatus getHyperlinkBase(ZCHAR*& HyperlinkBase) const = 0;
    virtual Zcad::ErrorStatus setHyperlinkBase(const ZCHAR* HyperlinkBase) = 0;

    virtual int numCustomInfo() const = 0;

    virtual Zcad::ErrorStatus addCustomSummaryInfo(const ZCHAR* key, const ZCHAR* value ) = 0;

    virtual Zcad::ErrorStatus deleteCustomSummaryInfo(const int index) = 0;
    virtual Zcad::ErrorStatus deleteCustomSummaryInfo(const ZCHAR* key) = 0;

    virtual Zcad::ErrorStatus getCustomSummaryInfo(const int index, ZCHAR*& key,
                               ZCHAR *& value ) const = 0;

    virtual Zcad::ErrorStatus setCustomSummaryInfo (const int index, const ZCHAR* key,
                               const ZCHAR *value ) = 0;

    virtual Zcad::ErrorStatus getCustomSummaryInfo(const ZCHAR *customInfoKey,
                               ZCHAR *& value ) const = 0;

    virtual Zcad::ErrorStatus setCustomSummaryInfo (const ZCHAR *customInfoKey,
                               const ZCHAR *value ) = 0;

   
    virtual ZcDbDatabase* database() const = 0; 
    virtual void setDatabase(ZcDbDatabase *pDb) = 0; 

    virtual ~ZcDbDatabaseSummaryInfo() {};
  protected:
    ZcDbDatabaseSummaryInfo();
};

Zcad::ErrorStatus ZDESK_STDCALL zcdbGetSummaryInfo(
                                 ZcDbDatabase* pDb, 
                                 ZcDbDatabaseSummaryInfo*& pInfo);

Zcad::ErrorStatus ZDESK_STDCALL zcdbPutSummaryInfo(
                                const ZcDbDatabaseSummaryInfo* pInfo,
                                ZcDbDatabase *pDb);


inline Zcad::ErrorStatus zcdbPutSummaryInfo(
                                const ZcDbDatabaseSummaryInfo* pInfo)
{
    return ::zcdbPutSummaryInfo(pInfo, pInfo->database());
}


class ZDESK_NO_VTABLE ZcDbSummaryInfoReactor {
public:
    virtual void summaryInfoHasChanged(
                     const ZcDbDatabase* pDb, 
                     const ZcDbDatabaseSummaryInfo* pDbProp) {};
    virtual ~ZcDbSummaryInfoReactor() {};
};

class ZDESK_NO_VTABLE ZcDbSummaryInfoManager {
public:
    virtual void  addReactor(ZcDbSummaryInfoReactor* pReact) = 0;
    virtual void  removeReactor(ZcDbSummaryInfoReactor* pReact) = 0;
};


ZcDbSummaryInfoManager* ZDESK_STDCALL zcdbSummaryInfoManager();


inline void initZcDbSummaryInfoManager() {};
inline void deleteZcDbSummaryInfoManager() {};

#pragma pack (pop)
#endif 


