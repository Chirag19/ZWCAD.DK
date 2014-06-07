#ifndef ZD_DBDICTDFLT_H
#define ZD_DBDICTDFLT_H


#include "zdbdict.h"

#pragma pack(push, 8)

class ZcDbImpDictionaryWithDefault;

class ZcDbDictionaryWithDefault : public ZcDbDictionary
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDictionaryWithDefault);
    ZcDbDictionaryWithDefault();
    virtual ~ZcDbDictionaryWithDefault();

    Zcad::ErrorStatus setDefaultId(const ZcDbObjectId& newId);
    ZcDbObjectId defaultId() const;

    virtual Zcad::ErrorStatus getObjectBirthVersion(
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);

    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;
};

#pragma pack(pop)

#endif
