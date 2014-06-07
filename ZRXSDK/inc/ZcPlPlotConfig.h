#ifndef ZCPLPLOTCONFIG_H
#define ZCPLPLOTCONFIG_H

#include "ZcPl.h"

#include "ZcArray.h"
#include "zgepnt2d.h"
#include "zgeblok2d.h"
#include "zdblayout.h"

class HT_Plot_Config;
class HT_Media_Size;
class HT_Media_Description;

class ZcPlPlotConfig : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlPlotConfig)

public:
    enum PlotToFileCapability {
        kNoPlotToFile       = 0,
        kPlotToFileAllowed  = 1,
        kMustPlotToFile     = 2
    };
        
public:
    ZCPL_PORT virtual ~ZcPlPlotConfig();

    ZCPL_PORT virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* pSrc);

    ZCPL_PORT virtual void getDescriptionFields(ZCHAR*& pDriverName,
                                                ZCHAR*& pLocationName,
                                                ZCHAR*& pComment,
                                                ZCHAR*& pPortName,
                                                ZCHAR*& pServerName,
                                                ZCHAR*& pTagLine) const;

    ZCPL_PORT virtual const ZCHAR* deviceName() const;

    ZCPL_PORT virtual const ZCHAR* fullPath() const;

    ZCPL_PORT virtual unsigned int maxDeviceDPI() const;

    ZCPL_PORT virtual unsigned long deviceType() const;

    ZCPL_PORT virtual void getCanonicalMediaNameList(ZcArray<ZCHAR*> &mediaList) const;

    ZCPL_PORT virtual void getLocalMediaName(const ZCHAR* pCanonicalMediaName, 
                                             ZCHAR* &pLocalMediaName) const;

    ZCPL_PORT virtual void getMediaBounds(const ZCHAR* pCanonicalMediaName,
                                          ZcGePoint2d &pageSize, 
                                          ZcGeBoundBlock2d &printableArea) const;

    ZCPL_PORT virtual void refreshMediaNameList();

    ZCPL_PORT virtual bool isPlotToFile() const;
    ZCPL_PORT virtual Zcad::ErrorStatus setPlotToFile(bool bPlotToFile);

    ZCPL_PORT virtual Zcad::ErrorStatus getDefaultFileExtension(const ZCHAR*& pDefaultExtension) const;

    ZCPL_PORT virtual PlotToFileCapability plotToFileCapability() const;

    ZCPL_PORT virtual bool saveToPC3(const ZCHAR* pPC3Name);

    ZCPL_PORT virtual HT_Plot_Config* plotConfig() const;
    
    ZCPL_PORT virtual unsigned long isCustomPossible(double width, double height, 
                                  bool bIsDimensional, bool bIsSheet, int dpi, const
                                  ZCHAR * pPC3Dir) const;
    
    ZCPL_PORT virtual bool matchMediaSize(double page_x, double page_y,
                                  double printable_w, double printable_h, 
                                  ZcDbLayout::PlotPaperUnits units, 
                                  bool bIsSheet, int dpi, 
                                  const ZCHAR * pTargetCanonicalName, 
                                  ZCHAR *& pNearestSizeName, 
                                  ZCHAR *& pLocalizedName,
                                  double & scaleFactor);

    ZCPL_PORT virtual Zcad::ErrorStatus makeCustomMediaFromSizeDesc( 
        HT_Media_Size * pSize, HT_Media_Description * pDesc,
        bool bSameDriver, bool bSavePC3,
        const ZCHAR * pSourceEntry, const ZCHAR * pSourceName, 
        ZCHAR *& pCanonicalSizeName, ZCHAR *& pLocalizedSizeName, 
        ZCHAR *& pPMPPath, ZCHAR *& pPC3Path, int dpi, double & scaleFactor);

protected:
    friend class ZcPlPlotConfigManagerImp;
    friend class ZcPlPlotInfoImp;
    friend class ZcPlPlotInfoValidatorImp;
    ZcPlPlotConfig(HT_Plot_Config* pConfig, const ZCHAR* pDevName, 
                   const ZCHAR* pFullPath, unsigned long nDevType);

    ZcPlPlotConfig(const ZcPlPlotConfig* pOther);

private:
    ZcPlPlotConfig();

};

#endif // ZCPLPLOTCONFIG_H
