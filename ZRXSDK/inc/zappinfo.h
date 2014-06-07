#ifndef _zappinfo_h
#define _zappinfo_h 1

#include "zcdb.h"
#include "zrxdlinkr.h"
#include "ZdZChar.h"

#pragma pack (push, 8)

class ZcadAppInfoImp;

class ZcadAppInfo: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcadAppInfo);

    enum CmdStatus {
        kNoAction    = 0,
        kRetry       = 1,
        kShowMsg     = 2,
        kNoModule    = 3
    };
    typedef ZcadAppInfo::CmdStatus (*LoaderFunPtr)(void *);

    ZcadAppInfo();
    virtual ~ZcadAppInfo();

    const ZCHAR *appName() const;
    void setAppName(const ZCHAR *);

    const ZCHAR *moduleName() const;
    void setModuleName(const ZCHAR *);

    const ZCHAR *appDesc() const;
    void setAppDesc(const ZCHAR *);

    bool appImplements(const ZCHAR *) const;
    
    bool managed() const;
    void setManaged(bool bManaged);

    ZcadApp::ErrorStatus writeToRegistry(bool bObjDbx = false, bool skipHKLM = false);

    ZcadApp::ErrorStatus readFromRegistry();
    ZcadApp::ErrorStatus delFromRegistry(bool bObjDbx = false);

    ZcadAppInfo::CmdStatus runAppLoader();
    void setAppLoader(LoaderFunPtr);

    ZcadApp::LoadReasons loadReason();
    void setLoadReason(ZcadApp::LoadReasons);
    ZcadApp::ErrorStatus status() const;

    ZcadApp::ErrorStatus writeGroupNameToRegistry(const ZCHAR* group);

    ZcadApp::ErrorStatus writeCommandNameToRegistry(const ZCHAR* globalCmdName,
                                                    const ZCHAR* localCmdName);
    
private:
    ZcadAppInfoImp * mpImp;
};

#pragma pack (pop)
#endif