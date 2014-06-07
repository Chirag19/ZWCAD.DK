#ifndef ZD_DBPLOTSETTINGS_H
#define ZD_DBPLOTSETTINGS_H


#include "zdbmain.h"
#include "zdbdict.h"

#pragma pack(push, 8)


class ZcDbPlotSettings: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbPlotSettings);

    ZcDbPlotSettings();
    ZcDbPlotSettings(bool ModelType);
    virtual ~ZcDbPlotSettings();

   
    using ZcDbObject::copyFrom;  

    virtual Zcad::ErrorStatus 
    getClassID                 (CLSID* pClsid) const;


    
    Zcad::ErrorStatus 
    copyFrom                   (ZcDbPlotSettings *fromPlotSettings);
    
    enum PlotPaperUnits {
        kInches,
        kMillimeters,
        kPixels
    };

    enum PlotRotation {
        k0degrees,
        k90degrees,
        k180degrees,
        k270degrees
    };

    enum PlotType {
        kDisplay,
        kExtents,
        kLimits,
        kView,
        kWindow,
        kLayout
    };

    enum StdScaleType {
        kScaleToFit,                
        k1_128in_1ft,               
        k1_64in_1ft,                
        k1_32in_1ft,                
        k1_16in_1ft,                
        k3_32in_1ft,                
        k1_8in_1ft,                 
        k3_16in_1ft,                
        k1_4in_1ft,                 
        k3_8in_1ft,                 
        k1_2in_1ft,                 
        k3_4in_1ft,                 
        k1in_1ft,                   
        k3in_1ft,                   
        k6in_1ft,                   
        k1ft_1ft,                   
        k1_1,                       
        k1_2,                       
        k1_4,                       
        k1_8,                       
        k1_10,                      
        k1_16,                      
        k1_20,                      
        k1_30,                      
        k1_40,                      
        k1_50,                      
        k1_100,                     
        k2_1,                       
        k4_1,                       
        k8_1,                       
        k10_1,                      
        k100_1,                     
        k1000_1,                    
        k1and1_2in_1ft              
    };

    enum ShadePlotType {
        kAsDisplayed    = 0,
        kWireframe      = 1,
        kHidden         = 2,
        kRendered       = 3,
        kVisualStyle    = 4,
        kRenderPreset   = 5
    };

    enum ShadePlotResLevel {
        kDraft,
        kPreview,
        kNormal,
        kPresentation,
        kMaximum,
        kCustom
    };

    Zcad::ErrorStatus 
    addToPlotSettingsDict(ZcDbDatabase *towhichDb);

    Zcad::ErrorStatus 
    getPlotSettingsName        (const ZCHAR *& plotSettingsName) const;

    Zcad::ErrorStatus 
    getPlotSettingsName        (ZCHAR *& plotSettingsName) const;

    Zcad::ErrorStatus 
    setPlotSettingsName        (const ZCHAR * plotSettingsName);

    Zcad::ErrorStatus 
    getPlotCfgName             (const ZCHAR *& plotCfgName) const;

    Zcad::ErrorStatus    
    getPlotPaperMargins        (double& printableXmin,
                                double& printableYmin,
                                double& printableXmax,
                                double& printableYmax) const;
    Zcad::ErrorStatus 
    getPlotPaperSize           (double& paperWidth,
                                double& paperHeight) const;
    Zcad::ErrorStatus 
    getCanonicalMediaName      (const ZCHAR *& mediaName) const;

    Zcad::ErrorStatus 
    getPlotOrigin              (double& x,
                                double& y) const;

    ZcDbPlotSettings::PlotPaperUnits 
    plotPaperUnits             () const;

    Zdesk::Boolean    
    plotViewportBorders        () const;

    void              
    setPlotViewportBorders     (Zdesk::Boolean plotViewportBorders);

    Zdesk::Boolean    
    plotPlotStyles             () const;

    void              
    setPlotPlotStyles          (Zdesk::Boolean plotPlotStyles);

    Zdesk::Boolean    
    showPlotStyles             () const;

    void              
    setShowPlotStyles          (Zdesk::Boolean showPlotStyles);

    ZcDbPlotSettings::PlotRotation   
    plotRotation               () const;

    Zdesk::Boolean    
    plotCentered               () const;

    Zdesk::Boolean    
    plotHidden                 () const;

    void              
    setPlotHidden              (Zdesk::Boolean plotHidden);

    ZcDbPlotSettings::ShadePlotType    
    shadePlot                  () const;

    Zcad::ErrorStatus              
    setShadePlot               (ZcDbPlotSettings::ShadePlotType shadePlot);

    ZcDbPlotSettings::ShadePlotResLevel
    shadePlotResLevel          () const;

    Zcad::ErrorStatus
    setShadePlotResLevel       (ZcDbPlotSettings::ShadePlotResLevel resLevel);

    Zdesk::Int16
    shadePlotCustomDPI         () const;

    Zcad::ErrorStatus
    setShadePlotCustomDPI      (Zdesk::Int16 val);

    ZcDbPlotSettings::PlotType 
    plotType                   () const;

    Zcad::ErrorStatus 
    getPlotWindowArea          (double& xmin,
                                double& ymin,
                                double& xmax, 
                                double& ymax) const;

    Zcad::ErrorStatus 
    getPlotViewName            (const ZCHAR *& viewName) const;

    Zdesk::Boolean    
    useStandardScale           () const;

    Zcad::ErrorStatus 
    getCustomPrintScale        (double& numerator,
                                double& denominator) const;

    Zcad::ErrorStatus 
    getCurrentStyleSheet       (const ZCHAR *& styleSheetName) const;

    ZcDbPlotSettings::StdScaleType 
    stdScaleType               () const;

    Zcad::ErrorStatus 
    getStdScale                (double& scale) const;

    Zdesk::Boolean    
    scaleLineweights           () const;

    void              
    setScaleLineweights        (Zdesk::Boolean scaleLineweights);

    Zdesk::Boolean    
    printLineweights           () const;

    void              
    setPrintLineweights        (Zdesk::Boolean printLineweights);

    Zdesk::Boolean    
    drawViewportsFirst         () const;

    void              
    setDrawViewportsFirst      (Zdesk::Boolean drawViewportsFirst);

    Zdesk::Boolean    
    modelType                  () const;

    ZcDbObjectId
    shadePlotId                () const;

    Zcad::ErrorStatus              
    setShadePlot               (const ZcDbPlotSettings::ShadePlotType type,
                                const ZcDbObjectId shadePlotId);

    bool              
    plotWireframe              () const;

    bool
    plotAsRaster               () const;
};

#pragma pack(pop)

#endif
