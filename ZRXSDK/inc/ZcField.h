
#pragma once

#include "ZdZChar.h"
#include "ZcValue.h"

class ZcDbField;
class ZcDbFieldCache;
class ZcFdFieldResult;
class ZcFdFieldEvaluator;
class ZcFdFieldEvaluatorLoader;
class ZcFdFieldEngine;
class ZcFdFieldValue;
class ZcFdImpFieldFormat;
class ZcDbEvalVariant;

class ZCDB_PORT ZcFdFieldEvaluator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEvaluator);

    ZcFdFieldEvaluator(void);
    virtual ~ZcFdFieldEvaluator(void);

    virtual const ZCHAR * evaluatorId(void) const;
    virtual const ZCHAR * evaluatorId(ZcDbField* pField);

    virtual Zcad::ErrorStatus initialize(ZcDbField* pField); 
    virtual Zcad::ErrorStatus compile(ZcDbField* pField, 
                                             ZcDbDatabase* pDb,
                                             ZcFdFieldResult* pResult);
    virtual Zcad::ErrorStatus evaluate(ZcDbField* pField, 
                                             int nContext, 
                                             ZcDbDatabase* pDb, 
                                             ZcFdFieldResult* pResult);
    virtual Zcad::ErrorStatus format(ZcDbField* pField, 
                                             ZCHAR *& pszValue);

protected:
    ZcFdFieldEvaluator(void*);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZCDB_PORT ZcFdFieldEvaluatorLoader : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEvaluatorLoader);

    ZcFdFieldEvaluatorLoader(void);
    ZcFdFieldEvaluatorLoader(void*);    
    ~ZcFdFieldEvaluatorLoader(void);

    virtual ZcFdFieldEvaluator* getEvaluator(
                                                const ZCHAR * pszEvalId);
    virtual ZcFdFieldEvaluator * findEvaluator(ZcDbField* pField, 
                                             const ZCHAR *& pszEvalId);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZCDB_PORT ZcFdFieldEngine : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEngine);

    ZcFdFieldEngine();
    virtual ~ZcFdFieldEngine();

    Zcad::ErrorStatus registerEvaluatorLoader(ZcFdFieldEvaluatorLoader* pLoader);
    Zcad::ErrorStatus unregisterEvaluatorLoader(ZcFdFieldEvaluatorLoader* pLoader);
    int   evaluatorLoaderCount    (void) const;
    ZcFdFieldEvaluatorLoader * getEvaluatorLoader(int iIndex);
    ZcFdFieldEvaluator * getEvaluator (const ZCHAR * pszEvalId);
    ZcFdFieldEvaluator * findEvaluator(ZcDbField* pField, 
                                             const ZCHAR *& pszEvalId);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZcFdFieldResult : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldResult);

    ZcFdFieldResult(void);
    ZCDB_PORT virtual Zcad::ErrorStatus setFieldValue(const ZcValue* pValue);
    ZCDB_PORT virtual Zcad::ErrorStatus setEvaluationStatus(int nStatus, 
                                             int dwErrCode = 0, 
                                             const ZCHAR * pszMsg = NULL);
};

class ZcFdFieldValue : public ZcValue
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldValue);
    
    ZCDB_PORT ZcFdFieldValue(void);
    ZCDB_PORT ZcFdFieldValue(ZcFdFieldValue::DataType nDataType);
    ZCDB_PORT ZcFdFieldValue(const ZcFdFieldValue& value);
    ZCDB_PORT ZcFdFieldValue(const ZCHAR * pszValue);
    ZCDB_PORT ZcFdFieldValue(long lValue);
    ZCDB_PORT ZcFdFieldValue(double fValue);
    ZCDB_PORT ZcFdFieldValue(const __time64_t& date);
    ZCDB_PORT ZcFdFieldValue(const SYSTEMTIME& date);
    ZCDB_PORT ZcFdFieldValue(const ZcGePoint2d& pt);
    ZCDB_PORT ZcFdFieldValue(double x, double y);
    ZCDB_PORT ZcFdFieldValue(const ZcGePoint3d& pt);
    ZCDB_PORT ZcFdFieldValue(double x, double y, double z);
    ZCDB_PORT ZcFdFieldValue(const ZcDbObjectId& id);
    ZCDB_PORT ZcFdFieldValue(const resbuf& rb);
    ZCDB_PORT ZcFdFieldValue(const ZcDbEvalVariant& evalVar);
    ZCDB_PORT ZcFdFieldValue(const VARIANT& var);
    ZCDB_PORT ZcFdFieldValue(const void* pBuf, DWORD dwBufSize);
};

class ZcFdFieldReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldReactor);

    virtual Zcad::ErrorStatus beginEvaluateFields(int nContext, 
                                             ZcDbDatabase* pDb);
    virtual Zcad::ErrorStatus endEvaluateFields(int nContext, 
                                             ZcDbDatabase* pDb);
};

typedef ZcArray<ZcFdFieldReactor*> FieldReactors;


Zcad::ErrorStatus   zcdbAddFieldReactor     (ZcFdFieldReactor* pReactor);
Zcad::ErrorStatus   zcdbRemoveFieldReactor  (ZcFdFieldReactor* pReactor);
