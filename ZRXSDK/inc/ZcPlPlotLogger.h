#ifndef ZCPLPLOTLOGGER_H
#define ZCPLPLOTLOGGER_H

class ZDESK_NO_VTABLE ZcPlPlotLogger
{
public:

    ZcPlPlotLogger(){};
    virtual ~ZcPlPlotLogger(){};

    virtual Zcad::ErrorStatus startJob(void) = 0;

    virtual Zcad::ErrorStatus startSheet(void) = 0;

    virtual Zcad::ErrorStatus logTerminalError(const ZCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logARIError(const ZCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logSevereError(const ZCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logError(const ZCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logWarning(const ZCHAR *pWarningString) = 0;

    virtual Zcad::ErrorStatus logMessage(const ZCHAR *pMessageString) = 0;

    virtual Zcad::ErrorStatus logInformation(const ZCHAR *pMessageString) = 0;

    virtual Zcad::ErrorStatus endSheet(void) = 0;

    virtual bool errorHasHappenedInSheet(void) const = 0;

    virtual bool warningHasHappenedInSheet(void) const = 0;

    virtual Zcad::ErrorStatus endJob(void) = 0;

    virtual bool errorHasHappenedInJob(void) const = 0;

    virtual bool warningHasHappenedInJob(void) const = 0;
};

#endif