#ifndef ZCPLPLOTERRORHANDLER_H
#define ZCPLPLOTERRORHANDLER_H


#include "ZcPlObject.h"

class ZcPlSystemInternals;

class ZcPlPlotErrorHandler : public ZcPlObject
{
public:
    enum ErrorResult {
        kAbort,
        kRetry,
        kIgnore
    };
    enum Handler {
        kInfo,
        kWarning,
        kError,
        kARI,
        kSevere,
        kTerminal,
        kNone 
    };

    ZCPL_PORT ZcPlPlotErrorHandler();
    ZCPL_PORT ~ZcPlPlotErrorHandler();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotErrorHandler);

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


    ZCPL_PORT virtual bool takeResponsibility(Handler kind) ;


    ZCPL_PORT virtual bool setLogHandle(const ZCHAR *pFilePathName) ;


    ZCPL_PORT virtual void setQuietMode(bool bQuiet);


    ZCPL_PORT virtual void setLogMode(bool bLog);


    ZCPL_PORT virtual bool quietMode() const;


    ZCPL_PORT virtual bool logMode() const;



    ZCPL_PORT void getProductString(ZCHAR*& pProductString) const;
    ZCPL_PORT void getProgramString(ZCHAR*& pProgramString) const;
    ZCPL_PORT void getCompanyString(ZCHAR*& pCompanyString) const;

    ZCPL_PORT virtual const ZCHAR* warningTitle() const;
    ZCPL_PORT virtual const ZCHAR* severeTitle() const;
    ZCPL_PORT virtual const ZCHAR* errorTitle() const;
    ZCPL_PORT virtual const ZCHAR* ariTitle() const;
    ZCPL_PORT virtual const ZCHAR* terminalTitle() const;
    ZCPL_PORT virtual const ZCHAR* infoTitle() const;

protected:



    ZCPL_PORT void appInfoMessage(const ZCHAR *pMessage);

    ZCPL_PORT int appMessageBox(const ZCHAR *pText, 
                                const ZCHAR *pCaption,
                                unsigned int uType, 
                                int defaultReturn);

    ZCPL_PORT void appInfo(ULONG_PTR category, 
                           const unsigned int specific,
                           const ZCHAR *pLocation, 
                           const ZCHAR *pContextData,
                           const ZCHAR *pRevision);


    ZCPL_PORT ErrorResult appWarning(ULONG_PTR category,
                                     const unsigned int specific,
                                     const ZCHAR *pLocation,
                                     const ZCHAR *pContextData,
                                     const ZCHAR *pRevision);


    ZCPL_PORT void appSevereError(ULONG_PTR category,
                                  const unsigned int specific,
                                  const ZCHAR *pLocation,
                                  const ZCHAR *pContextData,
                                  const ZCHAR *pRevision);


    ZCPL_PORT ErrorResult appError(ULONG_PTR category,
                                   const unsigned int specific,
                                   const ZCHAR *pLocation,
                                   const ZCHAR *pContextData,
                                   const ZCHAR *pRevision);


    ZCPL_PORT ErrorResult appARIError(ULONG_PTR category,
                                      const unsigned int specific,
                                      const ZCHAR *pLocation,
                                      const ZCHAR *pContextData,
                                      const ZCHAR *pRevision);


    ZCPL_PORT void appTerminalError(ULONG_PTR category,
                                    const unsigned int specific,
                                    const ZCHAR *pLocation,
                                    const ZCHAR *pContextData,
                                    const ZCHAR *pRevision);


    ZCPL_PORT void appLogMessage(const ZCHAR *pTitle, const ZCHAR *pMsg);

    ZCPL_PORT bool appSetLogHandle(const ZCHAR *pFilePathName);
};

#endif 
