#ifndef ZCPLPLOTLOGGINGERRORHANDLER_H
#define ZCPLPLOTLOGGINGERRORHANDLER_H


class ZcPlPlotLogger;
class ZcPlSystenInternals;

class ZcPlPlotLoggingErrorHandler : public ZcPlPlotErrorHandler
{
public:
    ZCPL_PORT ZcPlPlotLoggingErrorHandler();
    ZCPL_PORT ZcPlPlotLoggingErrorHandler(ZcPlPlotLogger *);
    ZCPL_PORT virtual ~ZcPlPlotLoggingErrorHandler();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotLoggingErrorHandler);

public:

    ZCPL_PORT virtual void infoMessage(const ZCHAR *pMessage);

    ZCPL_PORT virtual int messageBox(const ZCHAR *pText, 
                                     const ZCHAR *pCaption,
                                     unsigned int uType, 
                                     int defaultReturn);


    ZCPL_PORT virtual void info(ULONG_PTR category, 
                                const unsigned int specific,
                                const ZCHAR *pLocation, 
                                const ZCHAR *pContextData,
                                const ZCHAR *pRevision);


    ZCPL_PORT virtual ErrorResult warning(ULONG_PTR category, 
                                          const unsigned int specific,
                                          const ZCHAR *pLocation,
                                          const ZCHAR *pContextData, 
                                          const ZCHAR *pRevision);


    ZCPL_PORT virtual void severeError(ULONG_PTR category, 
                                       const unsigned int specific, 
                                       const ZCHAR *pLocation, 
                                       const ZCHAR *pContextData, 
                                       const ZCHAR *pRevision);


    ZCPL_PORT virtual ErrorResult error(ULONG_PTR category,
                                        const unsigned int specific, 
                                        const ZCHAR *pLocation, 
                                        const ZCHAR *pContextData, 
                                        const ZCHAR *pRevision);


    ZCPL_PORT virtual ErrorResult ariError(ULONG_PTR category,
                                           const unsigned int specific,
                                           const ZCHAR *pLocation,
                                           const ZCHAR *pContextData,
                                           const ZCHAR *pRevision);


    ZCPL_PORT virtual void terminalError(ULONG_PTR category,
                                         const unsigned int specific,
                                         const ZCHAR *pLocation,
                                         const ZCHAR *pContextData,
                                         const ZCHAR *pRevision);


    ZCPL_PORT virtual void logMessage(const ZCHAR *pTitle, const ZCHAR *pMsg);

};

#endif 
