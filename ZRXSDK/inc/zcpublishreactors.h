
#ifndef _ZCPUBLISHREACTORS_H
#define _ZCPUBLISHREACTORS_H

#include <vector>
#include <tchar.h>
#include "zrxobject.h"
#include "ZcArray.h"
#include "ZcPlDSDData.h"
#include "ZcPlDSDEntry.h"
#include "ZcDMMUtils.h"
#include "ZcDMMEPlotProperty.h"
#include "ZcPlPlotErrorHandler.h"
#include "ZcPlPlotLogger.h"

class ZcPublishReactorManager;
class ZcPublishReactor;
class ZcPublishReactorInfo;

class ZcPublishBeginJobInfo;
class ZcPublishSheetInfo;

class ZcNameValuePair
{
public:
    ZcNameValuePair() 
    {
        m_pName = NULL;
        m_pValue = NULL;
    };

	~ZcNameValuePair() 
    {
        if (NULL != m_pName)
            delete [] m_pName;
        if (NULL != m_pValue)
            delete [] m_pValue;
    };

    ZcNameValuePair(const ZCHAR *name, const ZCHAR *value)
    {
        if (NULL != name) {
            m_pName = new ZCHAR[_tcslen(name) + 1];
            _tcscpy_s(m_pName, _tcslen(name) + 1, name);
        } else
            m_pName = NULL;
        
        if (NULL != value) {
            m_pValue = new ZCHAR[_tcslen(value) + 1];
            _tcscpy_s(m_pValue, _tcslen(value) + 1, value);
        } else
            m_pValue = NULL;
    }

    ZcNameValuePair(const ZcNameValuePair &src)
    : m_pName(NULL),
      m_pValue(NULL)
    {
        *this = src;
    }    

    const ZCHAR * name() const {return m_pName;};


    const ZCHAR * value() const {return m_pValue;};

    void setName(const ZCHAR * name)
    {
        if (NULL != m_pName)
            delete [] m_pName;
        if (NULL != name) {
            m_pName = new ZCHAR[_tcslen(name) + 1];
            _tcscpy_s(m_pName, _tcslen(name) + 1, name);
        } else
            m_pName = NULL;
    }

    void setValue(const ZCHAR * value)
    {
        if (NULL != m_pValue)
            delete [] m_pValue;
        if (NULL != value) {
            m_pValue = new ZCHAR[_tcslen(value) + 1];
            _tcscpy_s(m_pValue, _tcslen(value) + 1, value);
        } else
            m_pValue = NULL;
    }


    ZcNameValuePair & operator= (const ZcNameValuePair &src)
    {
        if (this == &src)
            return *this;

        setName(src.m_pName);
        setValue(src.m_pValue);
        return *this;
    }

private:
    ZCHAR * m_pName;
    ZCHAR * m_pValue;    
};

typedef std::vector<ZcNameValuePair> ZcNameValuePairVec;

class ZcPublishBeforeJobInfo
{
public:

    ZcPublishBeforeJobInfo() {};

    virtual ~ZcPublishBeforeJobInfo() {};

    virtual const ZcPlDSDData * GetDSDData() = 0;

    virtual const ZcNameValuePairVec 
        GetPrivateData(const ZCHAR * sectionName) = 0;

    virtual bool WritePrivateSection(const ZCHAR * sectionName, 
        const ZcNameValuePairVec nameValuePairVec) = 0;

    virtual bool JobWillPublishInBackground() = 0;    
};

class ZcPublishBeginJobInfo
{
public:

    ZcPublishBeginJobInfo() {};

    virtual ~ZcPublishBeginJobInfo() {};

    virtual const ZcPlDSDData * GetDSDData() = 0;

    virtual const ZcNameValuePairVec 
        GetPrivateData(const ZCHAR * sectionName) = 0;

    virtual bool WritePrivateSection(const ZCHAR * sectionName, 
        const ZcNameValuePairVec nameValuePairVec) = 0;

    virtual bool JobWillPublishInBackground() = 0;    

    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
};

class ZcPublishSheetInfo
{
public:
    ZcPublishSheetInfo() {};

    virtual ~ZcPublishSheetInfo() {};

    virtual const ZcPlDSDEntry * GetDSDEntry() = 0;

    virtual const ZCHAR * GetUniqueId() = 0;

    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
};

class ZcPublishAggregationInfo
{
public:
    ZcPublishAggregationInfo() {};

    virtual ~ZcPublishAggregationInfo() {};

    virtual void AddGlobalProperties(ZcDMMEPlotPropertyVec props) = 0;

    virtual void AddGlobalResources(ZcDMMResourceVec resources) = 0;

    virtual ZcPlPlotLogger * GetPlotLogger() = 0;

    virtual const ZCHAR* dwfFileName() = 0;

    virtual const ZCHAR* dwfPassword() = 0;
};


class ZcPublishReactorInfo
{
public:
    ZcPublishReactorInfo() {};

    virtual ~ZcPublishReactorInfo() {};

    virtual const ZCHAR* dwfFileName() = 0;

    virtual const ZCHAR* tempDwfFileName() = 0;

    virtual const ZCHAR* dwfPassword() = 0;

    virtual bool isMultiSheetDwf() = 0;
};



class ZcPublishReactor : public ZcRxObject
{
public:
    virtual void OnAboutToBeginBackgroundPublishing(ZcPublishBeforeJobInfo 
        *pInfo);

    virtual void OnAboutToBeginPublishing(ZcPublishBeginJobInfo *pInfo);

    virtual void OnBeginPublishingSheet(ZcPublishSheetInfo *pInfo);

    virtual void OnBeginAggregation(ZcPublishAggregationInfo *pInfo);


    virtual void OnAboutToEndPublishing(ZcPublishReactorInfo *pInfo);

    virtual void OnAboutToMoveFile(ZcPublishReactorInfo *pInfo);

    virtual void OnEndPublish(ZcPublishReactorInfo *pInfo);

    virtual void OnCancelledOrFailedPublishing(ZcPublishReactorInfo *pInfo);

    virtual ~ZcPublishReactor() {};

protected:
    ZcPublishReactor() {};
};

inline void 
    ZcPublishReactor::OnAboutToBeginBackgroundPublishing(ZcPublishBeforeJobInfo
    *pInfo) {};

inline void 
    ZcPublishReactor::OnAboutToBeginPublishing(ZcPublishBeginJobInfo *pInfo) {};

inline void 
    ZcPublishReactor::OnBeginPublishingSheet(ZcPublishSheetInfo *pInfo) {};

inline void 
    ZcPublishReactor::OnBeginAggregation(ZcPublishAggregationInfo *pInfo) {};

inline void 
    ZcPublishReactor::OnAboutToEndPublishing(ZcPublishReactorInfo *pInfo) {};

inline void 
    ZcPublishReactor::OnAboutToMoveFile(ZcPublishReactorInfo *pInfo) {};

inline void 
    ZcPublishReactor::OnEndPublish(ZcPublishReactorInfo *pInfo) {};

inline void 
    ZcPublishReactor::OnCancelledOrFailedPublishing(ZcPublishReactorInfo 
    *pInfo) {};

void ZcGlobAddPublishReactor(ZcPublishReactor *pReactor);

void ZcGlobRemovePublishReactor(ZcPublishReactor *pReactor);

typedef void (__cdecl * ZCGLOBADDPUBLISHREACTOR)(ZcPublishReactor * pReactor);
typedef void (__cdecl * ZCGLOBREMOVEPUBLISHREACTOR)(ZcPublishReactor * pReactor);

#endif//_ZCPUBLISHREACTORS_H

