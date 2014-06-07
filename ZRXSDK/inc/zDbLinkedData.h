

#pragma once

#include "ZcValue.h"
#include "ZDbDataLink.h"


class ZcDbLinkedData : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinkedData);

    ZCDB_PORT ZcDbLinkedData(void);
    ZCDB_PORT virtual ~ZcDbLinkedData(void);

    ZCDB_PORT virtual Zcad::ErrorStatus clear(void);
    ZCDB_PORT virtual bool isEmpty          (void) const;

    ZCDB_PORT virtual const ZCHAR* name     (void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setName(const ZCHAR* pszName);
    ZCDB_PORT virtual const ZCHAR* description(void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setDescription(const ZCHAR* pszDescription);

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};

typedef ZcArray<ZcDbLinkedData*> ZcDbDataArray;
