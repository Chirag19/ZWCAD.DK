#ifndef ZD_DBLYFILT_H
#define ZD_DBLYFILT_H

#include "zdbfilter.h"
#include "ZdZChar.h"

#pragma pack (push, 8)

class ZcDbLayerFilter: public  ZcDbFilter
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerFilter);
             ZcDbLayerFilter();
    virtual ~ZcDbLayerFilter();

    virtual ZcRxClass* indexClass() const;
    virtual Zdesk::Boolean isValid() const;

    Zcad::ErrorStatus add(const ZCHAR * pLayer);
    Zcad::ErrorStatus remove(const ZCHAR * pLayer);
    Zcad::ErrorStatus getAt(int index, const ZCHAR *& pName) const;
    int layerCount() const;
};

#pragma pack (pop)

#endif