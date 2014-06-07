

#ifndef _ZCPUBLISHUIREACTORS_H
#define _ZCPUBLISHUIREACTORS_H

#include "ZdZChar.h"
#include "ZcPublishReactors.h"
#include "zrxobject.h"
#include "zcarray.h"
#include "ZcPlDSDData.h"


#include "ZcPublishReactors.h"

class ZcPublishUIReactorInfo
{
public:

    ZcPublishUIReactorInfo() {};

    virtual ~ZcPublishUIReactorInfo() {};

    virtual const ZcPlDSDData * GetDSDData() = 0;

    virtual const ZcNameValuePairVec 
        GetPrivateData(const ZCHAR * sectionName) = 0;


    virtual bool WritePrivateSection(const ZCHAR * sectionName, 
        const ZcNameValuePairVec nameValuePairVec) = 0;

    virtual bool JobWillPublishInBackground() = 0;
};


class ZcPublishUIReactor : public ZcRxObject
{
public:
    virtual void OnInitPublishOptionsDialog(IUnknown **pUnk, 
                                            ZcPublishUIReactorInfo *pInfo);
    
    virtual ~ZcPublishUIReactor() {};

protected:
    ZcPublishUIReactor() {};
};


inline void 
ZcPublishUIReactor::OnInitPublishOptionsDialog(IUnknown **pUnk,
                                               ZcPublishUIReactorInfo *pInfo)
{
};

void ZcGlobAddPublishUIReactor(ZcPublishUIReactor *pReactor);

void ZcGlobRemovePublishUIReactor(ZcPublishUIReactor *pReactor);

typedef void (__cdecl * ZCGLOBADDPUBLISHUIREACTOR)(ZcPublishUIReactor * pReactor);
typedef void (__cdecl * ZCGLOBREMOVEPUBLISHUIREACTOR)(ZcPublishUIReactor * pReactor);


#endif//_ZCPUBLISHUIREACTORS_H

