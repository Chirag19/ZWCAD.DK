#ifndef ZCPLHOSTAPPSERVICES_H
#define ZCPLHOSTAPPSERVICES_H


class ZcPlPlotLogger;
class ZcadPlotInternalServices;



class ZDESK_NO_VTABLE ZcPlHostAppServices
{
public:
    enum PlotStatus {
        kSheetIdxAndName = -5, kDisableCancelSheet = -4, kDwfFilePlotted = -3, kPlottingMsg = -2,
        kNoPlotYet = -1, kPlotStart = 0, kViewPlotLog = 1, kPlotSuccessful = 2,
        kPlotHadErrors = 3, kPlotHadSystemError = 4
    };

    virtual ZcPlPlotLogger * getPlotLogger(void) = 0;
    virtual const ZcadPlotInternalServices* zcadInternalServices() = 0;

    virtual void updatePlotJobStatus(enum ZcPlHostAppServices::PlotStatus nStatus, const ZCHAR *szPlotMsg) = 0;
};

ZCPL_PORT Zcad::ErrorStatus ZcPlSetHostAppServices(ZcPlHostAppServices *pHostServices);
ZCPL_PORT ZcPlHostAppServices *ZcPlGetHostAppServices();

#endif 
