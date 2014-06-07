#ifndef __ZDBTABLESTYLE_H__
#define __ZDBTABLESTYLE_H__

#pragma once


#include "zdbmain.h"
#include "ZdZChar.h"
#include "ZcValue.h"
#include "ZcString.h"
#include "zDbFormattedTableData.h"

#pragma pack (push, 8)

class ZcDbTableTemplate;
class ZcDbTableStyle : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTableStyle);

    ZcDbTableStyle();
    virtual ~ZcDbTableStyle();

    virtual Zcad::ErrorStatus   getName(ZCHAR*& pszName) const;
    virtual Zcad::ErrorStatus   setName(const ZCHAR * pszName);

    virtual const ZCHAR*        description(void) const;
    virtual Zcad::ErrorStatus   setDescription(const ZCHAR * pszDescription);

    virtual Zdesk::UInt32       bitFlags() const;
    virtual Zcad::ErrorStatus   setBitFlags(Zdesk::UInt32 flags);

    virtual ZcDb::FlowDirection flowDirection(void) const; 
    virtual Zcad::ErrorStatus   setFlowDirection(ZcDb::FlowDirection flow);

    ZDESK_DEPRECATED virtual double horzCellMargin(void) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus setHorzCellMargin(double dCellMargin);

    ZDESK_DEPRECATED virtual double vertCellMargin(void) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus setVertCellMargin(double dCellMargin);

    ZDESK_DEPRECATED virtual bool isTitleSuppressed(void) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus suppressTitleRow(bool bValue);

    ZDESK_DEPRECATED virtual bool isHeaderSuppressed(void) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus suppressHeaderRow(bool bValue);

    virtual ZcDbObjectId        textStyle(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setTextStyle(const ZcDbObjectId id,
                                            int rowTypes = ZcDb::kAllRows);
    
    virtual double              textHeight(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setTextHeight(double dHeight,
                                              int rowTypes = ZcDb::kAllRows);

    virtual ZcDb::CellAlignment alignment(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setAlignment(ZcDb::CellAlignment alignment,
                                             int rowTypes = ZcDb::kAllRows);

    virtual ZcCmColor           color(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setColor(const ZcCmColor& color,
                                         int rowTypes = ZcDb::kAllRows);

    virtual ZcCmColor           backgroundColor(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setBackgroundColor(const ZcCmColor& color,
                                                   int rowTypes = ZcDb::kAllRows);

    ZDESK_DEPRECATED virtual bool isBackgroundColorNone(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus setBackgroundColorNone(bool bValue,
                                                       int rowTypes = ZcDb::kAllRows);
    virtual Zcad::ErrorStatus   getDataType(ZcValue::DataType& nDataType,
                                            ZcValue::UnitType& nUnitType) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus   getDataType(ZcValue::DataType& nDataType,
                                            ZcValue::UnitType& nUnitType,
                                            ZcDb::RowType rowType) const;
    virtual Zcad::ErrorStatus   setDataType(ZcValue::DataType nDataType,
                                            ZcValue::UnitType nUnitType);
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus   setDataType(ZcValue::DataType nDataType, 
                                            ZcValue::UnitType nUnitType,
                                            int rowTypes);

    ZDESK_DEPRECATED virtual const ZCHAR* format (void) const;
    ZDESK_DEPRECATED virtual const ZCHAR* format (ZcDb::RowType rowType) const;
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus   setFormat(const ZCHAR* pszFormat);
    ZDESK_DEPRECATED virtual Zcad::ErrorStatus   setFormat(const ZCHAR* pszFormat,
                                          int rowTypes);

    virtual ZcDb::LineWeight    gridLineWeight(ZcDb::GridLineType gridLineType, 
                                               ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setGridLineWeight(ZcDb::LineWeight lineWeight,
                                                  int gridLineTypes = ZcDb::kAllGridLines, 
                                                  int rowTypes = ZcDb::kAllRows);
    virtual ZcCmColor           gridColor(ZcDb::GridLineType gridLineType, 
                                          ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setGridColor(const ZcCmColor color,
                                             int gridLineTypes = ZcDb::kAllGridLines, 
                                             int rowTypes = ZcDb::kAllRows);
    virtual ZcDb::Visibility    gridVisibility(ZcDb::GridLineType gridLineType, 
                                               ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setGridVisibility(ZcDb::Visibility visible,
                                                  int gridLineTypes = ZcDb::kAllGridLines, 
                                                  int rowTypes = ZcDb::kAllRows);

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus   audit(ZcDbAuditInfo* pAuditInfo);

 
    virtual Zcad::ErrorStatus   postTableStyleToDb(ZcDbDatabase* pDb, 
                                                   const ZCHAR* styleName, 
                                                   ZcDbObjectId& tableStyleId);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    const ZCHAR *   createCellStyle         (void);
    Zcad::ErrorStatus createCellStyle       (const ZCHAR* pszCellStyle);
    Zcad::ErrorStatus createCellStyle       (const ZCHAR* pszCellStyle, 
                                             const ZCHAR* pszFromCellStyle);
    Zcad::ErrorStatus renameCellStyle       (const ZCHAR* pszOldName, 
                                             const ZCHAR* pszNewName);
    Zcad::ErrorStatus deleteCellStyle       (const ZCHAR* pszCellStyle);
    Zcad::ErrorStatus copyCellStyle         (const ZCHAR* pszSrcCellStyle, 
                                             const ZCHAR* pszTargetCellStyle);
    Zcad::ErrorStatus copyCellStyle         (const ZcDbTableStyle* pSrc, 
                                             const ZCHAR* pszSrcCellStyle,
                                             const ZCHAR* pszTargetCellStyle);
    Zcad::ErrorStatus getUniqueCellStyleName(const ZCHAR* pszBaseName, 
                                             ZcString& sUniqueName) const;
    bool            isCellStyleInUse        (const ZCHAR* pszCellStyle) const;
    int             numCellStyles           (void) const;
    int             getCellStyles           (ZcStringArray& cellstyles) const;

    ZcDbObjectId    textStyle               (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setTextStyle          (const ZcDbObjectId& id, 
                                             const ZCHAR* pszCellStyle);

    double          textHeight              (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setTextHeight         (double dHeight, 
                                             const ZCHAR* pszCellStyle);

    ZcDb::CellAlignment alignment           (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setAlignment          (ZcDb::CellAlignment alignment, 
                                             const ZCHAR* pszCellStyle);

    ZcCmColor       color                   (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setColor              (const ZcCmColor& color, 
                                             const ZCHAR* pszCellStyle);

    ZcCmColor       backgroundColor         (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setBackgroundColor    (const ZcCmColor& color, 
                                             const ZCHAR* pszCellStyle);

    Zcad::ErrorStatus getDataType           (ZcValue::DataType& nDataType, 
                                             ZcValue::UnitType& nUnitType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setDataType           (ZcValue::DataType nDataType, 
                                             ZcValue::UnitType nUnitType, 
                                             const ZCHAR* pszCellStyle);

    const ZCHAR *   format                  (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setFormat             (const ZCHAR* pszFormat, 
                                             const ZCHAR* pszCellStyle);

    int             cellClass               (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setCellClass          (int nClass, 
                                             const ZCHAR* pszCellStyle);

    double          rotation                (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setRotation           (double fRotation, 
                                             const ZCHAR* pszCellStyle);

    bool            isMergeAllEnabled       (const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus enableMergeAll        (bool bEnable, 
                                             const ZCHAR* pszCellStyle);

    double          margin                  (ZcDb::CellMargin nMargin,
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setMargin             (ZcDb::CellMargin nMargins, 
                                             double fMargin,
                                             const ZCHAR* pszCellStyle);

   
    ZcDb::LineWeight gridLineWeight         (ZcDb::GridLineType gridLineType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridLineWeight     (ZcDb::LineWeight lineWeight, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZCHAR* pszCellStyle);
    ZcCmColor       gridColor               (ZcDb::GridLineType gridLineType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridColor          (const ZcCmColor color, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZCHAR* pszCellStyle);
    ZcDb::Visibility gridVisibility         (ZcDb::GridLineType gridLineType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridVisibility     (ZcDb::Visibility visible, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZCHAR* pszCellStyle);
    double          gridDoubleLineSpacing   (ZcDb::GridLineType gridLineType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridDoubleLineSpacing(double fSpacing, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZCHAR* pszCellStyle);
    ZcDb::GridLineStyle gridLineStyle       (ZcDb::GridLineType gridLineType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridLineStyle      (ZcDb::GridLineStyle nLineStyle, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZCHAR* pszCellStyle);
    ZcDbObjectId    gridLinetype            (ZcDb::GridLineType gridLineType, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridLinetype       (const ZcDbObjectId& id, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZCHAR* pszCellStyle);
    Zcad::ErrorStatus getGridProperty       (ZcGridProperty& gridProp, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridProperty       (const ZcGridProperty& gridProp, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZCHAR* pszCellStyle);

    ZcDbObjectId    getTemplate             (void) const;
    Zcad::ErrorStatus getTemplate           (ZcDbTableTemplate*& pTemplate, 
                                             ZcDb::OpenMode mode);
    Zcad::ErrorStatus setTemplate           (const ZcDbObjectId& templateId, 
                                             ZcDb::MergeCellStyleOption nOption);
    Zcad::ErrorStatus setTemplate           (ZcDbTableTemplate* pTemplate, 
                                             ZcDb::MergeCellStyleOption nOption,
                                             ZcDbObjectId& templateId);
    ZcDbObjectId    removeTemplate          (void);
};

#pragma pack (pop)

#endif 
