

#pragma once

#include "ZdZChar.h"
#include "ZcField.h"
#include "zcstring.h"

class ZcDbField;


typedef ZcArray<ZcDbField*> ZcDbFieldArray;




typedef struct ZcFd
{
 
    enum EvalFields
    {
        kEvalRecursive      = (0x1 << 0),      
    };


    enum ConvertFieldToText
    {
        kConvertFieldToTextNone         = 0,
        kEvaluateBeforeConversion       = (0x1 << 0),
        kExcludeEvaluatorsInList        = (0x1 << 1),
        kIgnoreEvaluatorVersion         = (0x1 << 2),
    };

} ZcFd;




typedef struct ZcHyperlink
{
    ZcString                msUrl;
    ZcString                msSubLocation;
    ZcString                msDescription;
    long                    mlFlag;

} ZcHyperlink;




class ZcDbField : public ZcDbObject
{
public:
    enum State
    {
        kInitialized        = (0x1 << 0),       
        kCompiled           = (0x1 << 1),       
        kModified           = (0x1 << 2),       
        kEvaluated          = (0x1 << 3),       
        kHasCache           = (0x1 << 4),       
        kHasFormattedString = (0x1 << 5),        
    };

    enum EvalOption
    {
        kDisable            = 0,                
        kOnOpen             = (0x1 << 0),       
        kOnSave             = (0x1 << 1),       
        kOnPlot             = (0x1 << 2),       
        kOnEtransmit        = (0x1 << 3),       
        kOnRegen            = (0x1 << 4),       
        kOnDemand           = (0x1 << 5),       
        kAutomatic          = (kOnOpen | kOnSave | kOnPlot | 
                               kOnEtransmit | kOnRegen | kOnDemand),    
    };

    enum EvalContext
    {
        kOpen               = (0x1 << 0),       
        kSave               = (0x1 << 1),       
        kPlot               = (0x1 << 2),       
        kEtransmit          = (0x1 << 3),       
        kRegen              = (0x1 << 4),       
        kDemand             = (0x1 << 5),       
        kPreview            = (0x1 << 6),       
        kPlotPreview        = (0x1 << 7),       
    };

    enum EvalStatus
    {
        kNotYetEvaluated    = (0x1 << 0),       
        kSuccess            = (0x1 << 1),       
        kEvaluatorNotFound  = (0x1 << 2),       
        kSyntaxError        = (0x1 << 3),       
        kInvalidCode        = (0x1 << 4),       
        kInvalidContext     = (0x1 << 5),       
        kOtherError         = (0x1 << 6),       
    };

    enum FieldCodeFlag
    {
        kFieldCode          = (0x1 << 0),       
        kEvaluatedText      = (0x1 << 1),       
        kEvaluatedChildren  = (0x1 << 2),       
        kObjectReference    = (0x1 << 3),       
                                                
        kAddMarkers         = (0x1 << 4),       
        kEscapeBackslash    = (0x1 << 5),       
        kStripOptions       = (0x1 << 6),       
        kPreserveFields     = (0x1 << 7),       
        kTextField          = (0x1 << 8),       
        kPreserveOptions    = (0x1 << 9),       
        kDetachChildren     = (0x1 << 10),      
                                                
        kChildObjectReference = (0x1 << 11),    
                                                
        kForExpression      = (0x1 << 12),      
                                                
    };

    enum FilingOption
    {
        kSkipFilingResult   = (0x1 << 0),      
    };

public:
    ZCDB_DECLARE_MEMBERS(ZcDbField);

    ZCDB_PORT ZcDbField(void);
    ZCDB_PORT ZcDbField(const ZCHAR * pszFieldCode, bool bTextField = false);
    ZCDB_PORT ~ZcDbField(void);

    ZCDB_PORT Zcad::ErrorStatus setInObject (ZcDbObject* pObj, 
                                             const ZCHAR * pszPropName);
    ZCDB_PORT Zcad::ErrorStatus postInDatabase(ZcDbDatabase* pDb);
    ZCDB_PORT ZcDbField::State state        (void) const;
    ZCDB_PORT ZcDbField::EvalStatus evaluationStatus(int* pnErrCode = NULL, 
                                             ZCHAR ** pszErrMsg = NULL) const;
    ZCDB_PORT ZcDbField::EvalOption evaluationOption(void) const;
    ZCDB_PORT Zcad::ErrorStatus setEvaluationOption(ZcDbField::EvalOption nEvalOption);
    ZCDB_PORT ZcDbField::FilingOption filingOption(void) const;
    ZCDB_PORT Zcad::ErrorStatus setFilingOption(ZcDbField::FilingOption nOption);

    ZCDB_PORT const ZCHAR  * evaluatorId    (void) const;
    ZCDB_PORT Zcad::ErrorStatus setEvaluatorId(const ZCHAR * pszEvaluatorId);
    bool            isTextField             (void) const;
    Zcad::ErrorStatus convertToTextField    (void);

    ZCDB_PORT const ZCHAR * getFieldCode     (ZcDbField::FieldCodeFlag nFlag,
                                             ZcArray<ZcDbField*>* pChildFields = NULL, 
                                             ZcDb::OpenMode mode = ZcDb::kForRead) const;
    ZCDB_PORT Zcad::ErrorStatus getFieldCode(ZCHAR*& pszFieldCode, 
                                             ZcDbField::FieldCodeFlag nFlag,
                                             ZcArray<ZcDbField*>* pChildFields = NULL, 
                                             ZcDb::OpenMode mode = ZcDb::kForRead) const;
    ZCDB_PORT Zcad::ErrorStatus setFieldCode(const ZCHAR* pszFieldCode, 
                                             ZcDbField::FieldCodeFlag nFlag = (ZcDbField::FieldCodeFlag) 0,
                                             ZcDbFieldArray* pChildFields = NULL);

    ZCDB_PORT int   childCount              (void) const;
    ZCDB_PORT Zcad::ErrorStatus getChild    (int iIndex, 
                                             ZcDbField*& pField, 
                                             ZcDb::OpenMode mode);

    ZCDB_PORT const ZCHAR * getFormat       (void) const;
    ZCDB_PORT Zcad::ErrorStatus getFormat   (ZCHAR*& pszFormat) const;
    ZCDB_PORT Zcad::ErrorStatus setFormat   (const ZCHAR* pszFormat);

    ZCDB_PORT Zcad::ErrorStatus evaluate    (int nContext, 
                                             ZcDbDatabase* pDb, 
                                             int* pNumFound     = NULL,
                                             int* pNumEvaluated = NULL);
    ZCDB_PORT ZcValue::DataType dataType    (void) const;

    ZCDB_PORT const ZCHAR * getValue        (void) const;
    ZCDB_PORT Zcad::ErrorStatus getValue    (ZCHAR*& pszValue) const;
    ZCDB_PORT Zcad::ErrorStatus getValue    (ZcValue& value) const;
    ZCDB_PORT Zcad::ErrorStatus getValue    (ZcFdFieldValue& value) const;

    ZCDB_PORT bool  hasHyperlink            (void) const;
    ZCDB_PORT Zcad::ErrorStatus getHyperlink(ZcHyperlink& hlink) const;
    ZCDB_PORT Zcad::ErrorStatus getHyperlink(ZCHAR** pszName,
                                             ZCHAR** pszDescription, 
                                             ZCHAR** pszSubLocation,
                                             ZCHAR** pszDisplayString,
                                             long* pFlag) const;
    ZCDB_PORT Zcad::ErrorStatus setHyperlink(const ZcHyperlink& hlink);
    ZCDB_PORT Zcad::ErrorStatus setHyperlink(const ZCHAR* pszName, 
                                             const ZCHAR* pszDescription, 
                                             const ZCHAR* pszSubLocation = NULL);
    ZCDB_PORT Zcad::ErrorStatus setHyperlink(const ZCHAR* pszName, 
                                             const ZCHAR* pszDescription, 
                                             const ZCHAR* pszSubLocation,
                                             long lFlag);
    ZCDB_PORT Zcad::ErrorStatus removeHyperlink(void);

    ZCDB_PORT Zcad::ErrorStatus getData     (const ZCHAR* pszKey, 
                                             ZcValue* pData) const;
    ZCDB_PORT Zcad::ErrorStatus setData     (const ZCHAR* pszKey, 
                                             const ZcValue* pData);
    ZCDB_PORT Zcad::ErrorStatus setData     (const ZCHAR* pszKey, 
                                             const ZcValue* pData,
                                             bool bRecursive);

public:

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus subClose();
};




ZCDB_PORT ZcFdFieldEngine* zcdbGetFieldEngine(void);
ZCDB_PORT bool      zcdbGetFieldMarkers     (const ZCHAR*& pszPrefix, 
                                             const ZCHAR*& pszSuffix);
ZCDB_PORT bool      zcdbHasFields           (const ZCHAR * pszText);
ZCDB_PORT bool      zcdbFindField           (const ZCHAR * pszText, 
                                             int iSearchFrom, 
                                             int& nStartPos, 
                                             int& nEndPos);
ZCDB_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectId& objId, 
                                             int nContext, 
                                             const ZCHAR* pszPropName = NULL, 
                                             ZcDbDatabase* pDb        = NULL, 
                                             ZcFd::EvalFields nEvalFlag = ZcFd::kEvalRecursive,
                                             int* pNumFound           = NULL,
                                             int* pNumEvaluated       = NULL);
ZCDB_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectId& objId, 
                                             int nContext, 
                                             const ZcDbObjectIdArray* pFieldsToEvaluate, 
                                             const ZCHAR* pszEvaluatorId, 
                                             ZcDbDatabase* pDb, 
                                             ZcFd::EvalFields nEvalFlag, 
                                             int* pNumFound, 
                                             int* pNumEvaluated);
ZCDB_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectIdArray& objIds, 
                                             int nContext, 
                                             const ZCHAR* pszPropName  = NULL, 
                                             ZcDbDatabase* pDb         = NULL, 
                                             ZcFd::EvalFields nEvalFlag = ZcFd::kEvalRecursive, 
                                             int* pNumFound            = NULL, 
                                             int* pNumEvaluated        = NULL);
ZCDB_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectIdArray& objIds, 
                                             int nContext, 
                                             const ZcDbObjectIdArray* pFieldsToEvaluate, 
                                             const ZCHAR* pszEvaluatorId, 
                                             ZcDbDatabase* pDb, 
                                             ZcFd::EvalFields nEvalFlag, 
                                             int* pNumFound, 
                                             int* pNumEvaluated);
ZCDB_PORT Zcad::ErrorStatus zcdbConvertFieldsToText(ZcDbDatabase* pDb, 
                                             const ZcStringArray* pEvalIds, 
                                             ZcFd::ConvertFieldToText nOption);
ZCDB_PORT Zcad::ErrorStatus zcdbConvertFieldsToText(const ZcDbObjectIdArray& objIds, 
                                             const ZcStringArray* pEvalIds, 
                                             ZcFd::ConvertFieldToText nOption);
ZCDB_PORT Zcad::ErrorStatus zcdbMakeFieldCode(const ZCHAR * pszFieldExpr, 
                                             ZCHAR*& pszFieldCode);
ZCDB_PORT Zcad::ErrorStatus zcdbMakeFieldCode(const ZCHAR * pszFieldExpr, 
                                             ZCHAR*& pszFieldCode, 
                                             const ZCHAR * pszEvalId, 
                                             const ZCHAR * pszFormat, 
                                             const ZcHyperlink* pHyperlink);
