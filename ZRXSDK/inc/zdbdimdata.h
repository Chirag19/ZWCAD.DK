#ifndef ZD_DBDIMDATA_H
#define ZD_DBDIMDATA_H


#include "zcdb.h"
#include "zcarray.h"
#include "zdbdim.h"

class ZcDbDimData;

typedef ZcArray<ZcDbDimData> ZcDbDimDataArray;
typedef ZcArray<ZcDbDimData*> ZcDbDimDataPtrArray;
typedef ZcGeVector3d (*DimDataSetValueFuncPtr) (ZcDbDimData* pThis,
                                        ZcDbEntity* pEnt, 
                                        double newValue,
                                        const ZcGeVector3d& offset);

typedef ZcGeVector3d (*DimDataSetCustomStringFuncPtr) (ZcDbDimData* pThis,
                                        ZcDbEntity* pEnt, 
                                        const ZCHAR* pCustomString,
                                        const ZcGeVector3d& offset);
class ZcDbDimData
{
public:
    enum DimDataFlags {
        kDimEditable           = 0x1,
        kDimInvisible          = 0x2,
        kDimFocal              = 0x4,
        kDimHideIfValueIsZero  = 0x8,
        kDimEmptyData          = 0x10, 
        kDimResultantLength    = 0x20,
        kDimDeltaLength        = 0x40,
        kDimResultantAngle     = 0x80,
        kDimDeltaAngle         = 0x100,
        kDimRadius             = 0x200,
        kDimCustomValue        = 0x400,
        kDimConstrained        = 0x800,
        kDimCustomString       = 0x1000

    };

    ZcDbDimData();
    ZcDbDimData(ZcDbDimension* pDim, 
                DimDataSetValueFuncPtr setDimFunc = NULL,
                unsigned int bitFlags = 0,
                void* appData = NULL,
                DimDataSetCustomStringFuncPtr setCustomStringFunc = NULL);

    ~ZcDbDimData();

    ZcDbDimData(const ZcDbDimData&);
    ZcDbDimData&  operator = (const ZcDbDimData&);
    ZcDbDimension* dimension() const;
    Zcad::ErrorStatus setDimension(ZcDbDimension* pDim);
    ZcDbObjectId ownerId() const;
    Zcad::ErrorStatus setOwnerId(const ZcDbObjectId& objId);
    unsigned int bitFlags() const;
    Zcad::ErrorStatus setBitFlags(unsigned int flags);
    bool isDimFocal() const;
    Zcad::ErrorStatus setDimFocal(bool focal);
    bool isDimEditable() const;
    Zcad::ErrorStatus setDimEditable(bool editable);
    bool isDimInvisible() const;
    Zcad::ErrorStatus setDimInvisible(bool invisible);
    bool isDimHideIfValueIsZero() const;
    Zcad::ErrorStatus setDimHideIfValueIsZero(bool hide);
    void *appData() const;
    Zcad::ErrorStatus setAppData(void* appData);
    DimDataSetValueFuncPtr dimValueFunc() const;
    Zcad::ErrorStatus setDimValueFunc(DimDataSetValueFuncPtr funcPtr);
    DimDataSetCustomStringFuncPtr customStringFunc() const;
    Zcad::ErrorStatus setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr);
    bool isDimResultantLength() const;
    Zcad::ErrorStatus setDimResultantLength(bool bValue);
    bool isDimDeltaLength() const;
    Zcad::ErrorStatus setDimDeltaLength(bool bValue);
    bool isDimResultantAngle() const;
    Zcad::ErrorStatus setDimResultantAngle(bool bValue);
    bool isDimDeltaAngle() const;
    Zcad::ErrorStatus setDimDeltaAngle(bool bValue);
    bool isDimRadius() const;
    Zcad::ErrorStatus setDimRadius(bool bValue);
    bool isCustomDimValue() const;
    Zcad::ErrorStatus setCustomDimValue(bool custom);
    bool isConstrained() const;
    Zcad::ErrorStatus setConstrain(bool bValue);
    bool isCustomString() const;
    Zcad::ErrorStatus setCustomString(bool bValue);

private:
    ZcDbDimension*      mpDim;
    ZcDbObjectId        mOwnerId;
    unsigned int        mBitFlags;
    void*               mpAppData;
    DimDataSetValueFuncPtr  mpSetDimValueFunc;
    DimDataSetCustomStringFuncPtr  mpSetCustomStringFunc;
};


#endif 



