#ifndef ZCPLPLOTCONFIGMGR_H
#define ZCPLPLOTCONFIGMGR_H

#include "ZdZChar.h"
#include "ZcPl.h"
#include "ZcArray.h"
#include "ZcPlObject.h"

class ZcPlPlotConfig;
class HT_Thin_Plot_Config_Manager;
class HT_Error_Handler;

enum DeviceType {
    kSystemPrinter = 0,
    kPC3File = 1,
    kOneOffConfig = 2,      
    kUninitialized = -1
};

class ZcPlPlotConfigInfo : public ZcPlObject
{
public:
    ZCPL_PORT ZcPlPlotConfigInfo();
	ZCPL_PORT ZcPlPlotConfigInfo(const ZCHAR * pDevName,
                                 const ZCHAR * pFullPath, 
                                 DeviceType devType);
    ZCPL_PORT ZcPlPlotConfigInfo(const ZcPlPlotConfigInfo &copy);

    ZCPL_PORT Zcad::ErrorStatus copyFrom(const ZcRxObject* pSrc);

    ZCPL_PORT const ZcPlPlotConfigInfo& operator=(const ZcPlPlotConfigInfo& src);

    ZCPL_PORT virtual ~ZcPlPlotConfigInfo();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotConfigInfo);

    ZCPL_PORT const ZCHAR * fullPath() const;

    ZCPL_PORT void setFullPath(const ZCHAR * pPath);

    ZCPL_PORT const ZCHAR * deviceName() const;

    ZCPL_PORT void setDeviceName(const ZCHAR * pDevName);

    ZCPL_PORT DeviceType deviceType() const;

    ZCPL_PORT void setDeviceType(DeviceType devType);
};

class ZDESK_NO_VTABLE ZcPlPlotConfigManager
{
public:

    enum RefreshCode {
        kAll,
        kRefreshDevicesList,
        kRefreshStyleList,
        kRefreshSystemDevicesList,
        kRefreshPC3DevicesList
    };
    enum StyTypes {
        kUndefined      = 0,
        kRegular        = 0x01,
        kTranslation    = 0x02,
        kColorDep       = 0x04,
        kAllTypes       = 0x07
    };
    enum StdConfigs {
        kNoneDevice,
        kDefaultWindowsSysPrinter,
        kDWF6ePlot,
        kDWFePlotOptForPlotting,
        kDWFePlotOptForViewing,
        kPublishToWebDWF,
        kPublishToWebJPG,
        kPublishToWebPNG
    };

    virtual bool getDevicesList(ZcArray<ZcPlPlotConfigInfo, 
        ZcArrayObjectCopyReallocator <ZcPlPlotConfigInfo> > &deviceList);

    virtual bool getStyleList(ZcArray<ZCHAR *> &list, 
                              long styType = kAllTypes); 

    virtual void refreshList(RefreshCode refreshCode = kAll);

    virtual Zcad::ErrorStatus getCurrentConfig(ZcPlPlotConfig*& pConfig);

    virtual Zcad::ErrorStatus setCurrentConfig(ZcPlPlotConfig*& pConfig, 
                                               const ZCHAR * pDeviceName);

    virtual const ZCHAR * getStdConfigName(StdConfigs stdConfig);

    virtual HT_Thin_Plot_Config_Manager* thinPltCfgMgr(); 

    virtual HT_Error_Handler* errorHandler(); 

    virtual HT_Error_Handler* zcadErrorHandler(); 
};

ZCPL_PORT ZcPlPlotConfigManager* __stdcall zcplPlotConfigManagerPtr();
#define zcplPlotConfigManager zcplPlotConfigManagerPtr()

#endif // ZCPLPLOTCONFIGMGR_H
