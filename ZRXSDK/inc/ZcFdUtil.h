

#pragma once

#include "ZdZChar.h"
#include "ZcCell.h"

interface IZcSmDatabase;
interface IZcSmSheetSet;
interface IZcSmComponent;
struct ZcHyperlink;


#ifdef  ZCFD_API
    # define ZCFD_PORT __declspec(dllexport)
#else
    # define ZCFD_PORT
#endif

typedef unsigned long ZcDbEvalNodeId;

namespace ZcFdEval
{
   
    enum ObjectFieldOption
    {
        kObjFieldNone                   = 0,
        kObjFieldUnresolvedBlockRef     = (0x1 << 0),
        kObjFieldApplyBlockTransform    = (0x1 << 1),
        kObjFieldUnresolvedObjectRef    = (0x1 << 2),
    };

    
    enum SheetSetFieldOption
    {
        kSheetSetNone                   = 0,
        kSheetSetHyperlink              = (0x1 << 0),
        kSheetSetUnresolvedComponent    = (0x1 << 1),
    };

   
    enum ExpressionFieldOption
    {
        
        kExprFieldNone                  = 0,
        kExprFieldSum                   = (0x1 << 0),
        kExprFieldAverage               = (0x1 << 1),
        kExprFieldCount                 = (0x1 << 2),
        kExprFieldCell                  = (0x1 << 3),
        kExprFieldEquation              = (0x1 << 4),
    };
};


ZCFD_PORT BOOL   ZcFdMakeFieldCode  (const ZcDbObjectId& objId, 
                                     ZcDbEvalNodeId blockParamId, 
                                     const ZCHAR * pszPropOrConnectionName, 
                                     ZcFdEval::ObjectFieldOption nOption, 
                                     const ZCHAR * pszFormat, 
                                     ZcHyperlink* pHyperlink, 
                                     ZCHAR*& pszFieldCode);
ZCFD_PORT BOOL   ZcFdMakeFieldCode  (IZcSmDatabase* pSmDb, 
                                     IZcSmSheetSet* pSmSheetSet, 
                                     IZcSmComponent* pSmComp, 
                                     const ZCHAR * pszCompName, 
                                     const ZCHAR * pszPropName, 
                                     ZcFdEval::SheetSetFieldOption nOption,
                                     const ZCHAR * pszFormat,
                                     ZCHAR*& pszFieldCode);
ZCFD_PORT BOOL   ZcFdMakeFieldCode  (const ZcDbObjectId& tableId, 
                                     const ZcDbObjectId& targetTableId, 
                                     ZcFdEval::ExpressionFieldOption nOption, 
                                     const ZcCellRangeArray& cellRanges,
                                     const ZCHAR * pszFormat, 
                                     ZcHyperlink* pHyperlink, 
                                     ZCHAR*& pszFieldCode);
ZCFD_PORT BOOL   ZcFdExtractData    (ZcDbField* pField, 
                                     ZCHAR *& pszSheetSetFile, 
                                     ZCHAR *& pszSheetSetId, 
                                     ZCHAR *& pszCompName, 
                                     ZCHAR *& pszCompId, 
                                     ZCHAR *& pszPropName);
ZCFD_PORT BOOL   ZcFdExtractData    (ZcDbField* pField, 
                                     ZcDbObjectId& objId, 
                                     ZCHAR *& pszPropName);

