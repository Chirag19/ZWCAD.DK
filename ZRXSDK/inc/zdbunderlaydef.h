#ifndef ZCDB_DBUNDERLAYDEF_H
#define ZCDB_DBUNDERLAYDEF_H
#pragma once


#include "zdbmain.h"
#include "zcstring.h"

#pragma pack (push, 8)

class ZcDbUnderlayItem;
class ZcDbUnderlayHost;


class ZDESK_NO_VTABLE ZcDbUnderlayDefinition: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUnderlayDefinition);
    ZcDbUnderlayDefinition();
    virtual ~ZcDbUnderlayDefinition() = 0;
  
    Zcad::ErrorStatus setSourceFileName(const ZCHAR* file);
    const ZCHAR* getSourceFileName() const;
    Zcad::ErrorStatus getActiveFileName(const ZCHAR*& file) const;
    Zcad::ErrorStatus getActiveFileName(ZcString& file) const;
    
    Zcad::ErrorStatus setItemName(const ZCHAR* item);
    const ZCHAR* getItemName() const;
    
    Zcad::ErrorStatus setUnderlayItem(const ZCHAR* sourceFileName, const ZCHAR* activeFileName, ZcDbUnderlayItem* pItem);
    const ZcDbUnderlayItem* getUnderlayItem() const;
    
    Zcad::ErrorStatus load(const wchar_t* password);
    
    void unload();
    
    bool isLoaded() const;
    static ZcString dictionaryKey(const ZcRxClass* underlayDefinitionType);
private:
    
    virtual const ZcDbUnderlayHost* getUnderlayHost() const = 0;
};

class ZcDbDwfDefinition: public ZcDbUnderlayDefinition
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDwfDefinition);
    ZcDbDwfDefinition();
    virtual ~ZcDbDwfDefinition();
private:
    virtual  const ZcDbUnderlayHost* getUnderlayHost() const;
};

class ZcDbDgnDefinition: public ZcDbUnderlayDefinition
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDgnDefinition);
    ZcDbDgnDefinition();
    virtual ~ZcDbDgnDefinition();
   
    bool useMasterUnits() const;
    
    void setUseMasterUnits(bool useMaster);
    
    int xrefDepth() const;
    
    void setXrefDepth(int depth);
    
    bool showRasterRef() const;
    
    void setShowRasterRef(bool bShow);
private:
    virtual const ZcDbUnderlayHost* getUnderlayHost() const;

};
#pragma pack (pop)

#endif
