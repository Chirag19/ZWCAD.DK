#ifndef ZD_DBPLOTSETVAL_H
#define ZD_DBPLOTSETVAL_H

#include "ZdZChar.h"

#pragma pack (push, 8)
template <class T, class R> class ZcArray;
class ZcDbPlotSettings;

#include "zdbplotsettings.h"

class ZcDbPlotSettingsValidator {
public:    
    virtual Zcad::ErrorStatus 
    setPlotCfgName            (ZcDbPlotSettings* pPlotSet,
                               const ZCHAR * plotDeviceName,
                               const ZCHAR * mediaName = NULL     ) = 0;
    virtual Zcad::ErrorStatus 
    setCanonicalMediaName     (ZcDbPlotSettings* pPlotSet,
                               const ZCHAR * mediaName            ) = 0;
    virtual Zcad::ErrorStatus
    setPlotOrigin             (ZcDbPlotSettings *pPlotSet, 
                               const double xCoordinate,
                               const double yCoordinate         ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotPaperUnits         (ZcDbPlotSettings* pPlotSet,
                               const ZcDbPlotSettings::PlotPaperUnits units ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotRotation           (ZcDbPlotSettings* pPlotSet,
                               const ZcDbPlotSettings::PlotRotation rotationType) = 0;
    virtual Zcad::ErrorStatus 
    setPlotCentered           (ZcDbPlotSettings* pPlotSet,
                               Zdesk::Boolean isCentered        ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotType               (ZcDbPlotSettings* pPlotSet,
                               const ZcDbPlotSettings::PlotType plotAreaType ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotWindowArea         (ZcDbPlotSettings* pPlotSet,
                               const double xmin,
                               const double ymin,
                               const double xmax,
                               const double ymax                ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotViewName           (ZcDbPlotSettings* pPlotSet,
                               const ZCHAR * viewName             ) = 0;
    virtual Zcad::ErrorStatus 
    setUseStandardScale       (ZcDbPlotSettings* pPlotSet,
                               Zdesk::Boolean useStandard       ) = 0;
    virtual Zcad::ErrorStatus 
    setCustomPrintScale       (ZcDbPlotSettings* pPlotSet,
                               const double numerator,
                               const double denominator         ) = 0;
    virtual Zcad::ErrorStatus 
    setCurrentStyleSheet      (ZcDbPlotSettings* pPlotSet,
                               const ZCHAR * styleSheetName       ) = 0;
    virtual Zcad::ErrorStatus 
    setStdScaleType           (ZcDbPlotSettings* pPlotSet,
                               const ZcDbPlotSettings::StdScaleType scaleType ) = 0;
    virtual Zcad::ErrorStatus 
    setStdScale               (ZcDbPlotSettings* pPlotSet,
                               const double standardScale       ) = 0;
    virtual Zcad::ErrorStatus               
    plotDeviceList            (ZcArray<const ZCHAR *> & deviceList) = 0;

    virtual Zcad::ErrorStatus               
    canonicalMediaNameList    (ZcDbPlotSettings* pPlotSet,
                               ZcArray<const ZCHAR *> & mediaList ) = 0;
    virtual Zcad::ErrorStatus
    getLocaleMediaName        (ZcDbPlotSettings *pPlotSet,
                               const ZCHAR *  canonicalName,
                               const ZCHAR *& localeName          ) = 0;
    virtual Zcad::ErrorStatus
    getLocaleMediaName        (ZcDbPlotSettings *pPlotSet,
                               int index,
                               const ZCHAR *& localeName          ) = 0;
    virtual Zcad::ErrorStatus
    setClosestMediaName       (ZcDbPlotSettings* pPlotSet,
                               const double paperWidth,
                               const double paperHeight,
                               const ZcDbPlotSettings::PlotPaperUnits units,       
                               Zdesk::Boolean matchPrintableArea) = 0;
    virtual Zcad::ErrorStatus               
    plotStyleSheetList        (ZcArray<const ZCHAR *> & styleList ) = 0;  

    virtual void              
    refreshLists              (ZcDbPlotSettings* pPlotSet       ) = 0;

    virtual void
    setZoomToPaperOnUpdate    (ZcDbPlotSettings* pPlotSet,
                               Zdesk::Boolean doZoom            ) = 0;

    virtual Zcad::ErrorStatus
    setDefaultPlotConfig       (ZcDbPlotSettings* pPlotSet      ) = 0;
};
#pragma pack (pop)
#endif // ZD_DBPLOTSETVAL_H

