
#ifndef ZcDbHostApplicationServices_INC
#define ZcDbHostApplicationServices_INC

#include "zdesk.h"
#include "zcdb.h"
#include "zcarray.h"
#include "zcodepgid.h"


#include "zinetstrc.h"
#include "zrxdlinkr.h"

#pragma pack (push, 8)

class ZcDbAuditInfo;
class ZcDbDatabase;
class ZcDbUndoController;
class ZcDbTransactionManager;
class ZcDbGlobals;
class ZcDbAppSystemVariables;
class COleClientItem;
class CArchive;
class ZcadInternalServices;
struct flagmat;

class ZcDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;

class ZcDbPlotSettingsValidator;
class ZcDbLayoutManager;
class ZcPwdCache;

struct _EXCEPTION_POINTERS;

#ifndef ZCUTIL_API
#    ifdef ZCUTIL_INTERNAL
#        define ZCUTIL_API __declspec(dllexport)
#    else
#        define ZCUTIL_API __declspec(dllimport)
#    endif
#endif

typedef unsigned long LCID;

enum AcSDIValues {
	MDIEnabled = 0,
	SDIUserEnforced,
	SDIAppEnforced,
	SDIUserAndAppEnforced
};

enum ZProdIdCode {
	Prod_ZCAD = 1,
	Prod_LT,
	Prod_OEM,
	Prod_ZcDb
};

ZCUTIL_API extern class ZcDbHostApplicationServices * s_pServices;

int zcdbHostAppMinorVersion();

class ZcDbHostApplicationProgressMeter {
public:
    ZcDbHostApplicationProgressMeter();
    virtual ~ZcDbHostApplicationProgressMeter();

    virtual void start(const ZCHAR * displayString = NULL);
    virtual void stop();
    
    virtual void meterProgress();

    virtual void setLimit(int max);

};

typedef Zcad::ErrorStatus (*SELECTFILEPROC )(/*[out]*/ short *userCancel, 
                                             /*[out]*/ ZCHAR *& chosenPath,
                                             void* h, // HWND
                                             const int nFlags,
                                             const ZCHAR * prompt,
                                             const ZCHAR * dir,
                                             const ZCHAR * name,
                                             const ZCHAR * type,
                                             int* pnChoice,
                                             bool* pbReadOnly,
                                             const ZCHAR * pszWSTags,
                                             void* pReserved);

typedef Zcad::ErrorStatus (* REMAPPROC) (/*[out]*/ ZCHAR *& newName,
                                         const ZCHAR * filename,
                                         int context,
                                         void* pReserved);

typedef void (* MAPFILENOTIFYPROC) (const ZCHAR * filename,
                                    const ZCHAR * newName,
                                    int context,
                                    void* pReserved);


class ZDESK_NO_VTABLE ZcDbHostApplicationServices : public ZcRxObject
{
    friend ZcadInternalServices;
public:    
    ZCRX_DECLARE_MEMBERS(ZcDbHostApplicationServices);
    ZcDbHostApplicationServices( int createGlobals = 1 );
    virtual ~ZcDbHostApplicationServices();

    enum FindFileHint
    {
        kDefault = 0,
        kFontFile,              // Could be either
        kCompiledShapeFile,     // shx
        kTrueTypeFontFile,      // ttf
        kEmbeddedImageFile,
        kXRefDrawing,
        kPatternFile,
        kARXApplication,
        kFontMapFile,
        kUnderlayFile
    };
    
    enum RemapFileContext
    {
        kDrawingOpen,
        kXrefResolution,
        kRasterResolution,
        kAfterXrefResolution
    };

    //
    virtual Zcad::ErrorStatus findFile(ZCHAR * pcFullPathOut,
                 int   nBufferLength,
                 const ZCHAR * pcFilename,
                 ZcDbDatabase * pDb = NULL, 
                 ZcDbHostApplicationServices::FindFileHint hint = kDefault) = 0;

    
    virtual Zcad::ErrorStatus getRoamableRootFolder(const ZCHAR *& folder);
    virtual Zcad::ErrorStatus getLocalRootFolder(const ZCHAR *& folder);


    virtual Zcad::ErrorStatus   selectFile(short *userCancel, 
                                           ZCHAR *& chosenPath,
                                           void* h, // HWND
                                           const int nFlags,
                                           const ZCHAR * prompt,
                                           const ZCHAR * dir,
                                           const ZCHAR * name,
                                           const ZCHAR * type,
                                           int* pnChoice,
                                           bool* pbReadOnly,
                                           const ZCHAR * pszWSTags,
                                           void* pReserved) ;
    virtual Zcad::ErrorStatus   registerSelectFileCallback(const ZCHAR * appName,
                                                   SELECTFILEPROC proc, 
                                                   bool unRegister = false, 
                                                   bool asPrimary  = false);
    virtual const ZCHAR *       primaryClientForSelectFileCallback();
    virtual Zcad::ErrorStatus   getRegisteredSelectFileClients(
                                            ZcArray<const ZCHAR *>& clients);


    virtual Zcad::ErrorStatus   mapFile(/*out*/ ZCHAR *& newName,
                                        const ZCHAR * filename,
                                        int context,
                                        void* pReserved);
    virtual Zcad::ErrorStatus   registerMapFileCallback(const ZCHAR * appName,
                                                REMAPPROC  proc,
                                                bool unRegister = false, 
                                                bool asPrimary  = false);
    virtual const ZCHAR *       primaryClientForMapFileCallback();
    virtual bool                setMapFlag(bool setIt);
    virtual Zcad::ErrorStatus   getRegisteredFileMapClients(
                                            ZcArray<const ZCHAR *>& clients);
    virtual Zcad::ErrorStatus   registerMapFileNotification(const ZCHAR * appName, 
                                                MAPFILENOTIFYPROC,
                                                bool unRegister = false);


    virtual void fatalError(const ZCHAR *format, ...);


    virtual void reportUnhandledZrxException(const _EXCEPTION_POINTERS *pExcPtrs,
                                             const ZCHAR *pAppName);


    virtual Zdesk::Boolean userBreak(bool updCtrlsWhenEnteringIdle = true) const;

    virtual void displayChar(ZCHAR c) const;
    virtual void displayString(const ZCHAR* string, int count) const;


    virtual Zdesk::Boolean readyToDisplayMessages();


    virtual void enableMessageDisplay(Zdesk::Boolean);


    virtual Zdesk::Boolean doFullCRCCheck();


    virtual unsigned int getTempPath(Zdesk::UInt32 lBufferSize, 
                                                ZCHAR* pcBuffer);


    virtual const ZCHAR* getEnv(const ZCHAR * var);


    virtual ZcDbHostApplicationProgressMeter* newProgressMeter();


    void setWorkingProgressMeter(ZcDbHostApplicationProgressMeter* pNewMeter);

    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
    virtual ClipBoundaryArray* newClipBoundaryArray();


    ZcDbDatabase* workingDatabase() const;
    void setWorkingDatabase(ZcDbDatabase* pDatabase);

    virtual ZcDbUndoController* defaultUndoController();
    void setDefaultUndoController(ZcDbUndoController* pUndoCtrl);

    virtual ZcDbTransactionManager* workingTransactionManager();
    void setWorkingTransactionManager(ZcDbTransactionManager* pTM);

    virtual ZcDbGlobals * createWorkingGlobals();
    ZcDbGlobals * workingGlobals() const;
    void setWorkingGlobals(ZcDbGlobals* pGlobals);
    
    ZcDbAppSystemVariables * workingAppSysvars() const;
    void setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars);

    virtual const ZCHAR * program ();
    virtual const ZCHAR * product ();
    virtual const ZCHAR * companyName();
    virtual const ZProdIdCode prodcode();
    virtual const ZCHAR * releaseMajorMinorString();
    virtual int   releaseMajorVersion();
    virtual int   releaseMinorVersion();
    virtual const ZCHAR * versionString();
    virtual const ZCHAR * getRegistryProductRootKey ();
    virtual LCID  getRegistryProductLCID() ;
    virtual bool  supportsMultiRedo() const { return false; }
    enum ModelerFlavor {kModelerFull=0, kModelerRegionsOnly=1, kModelerObjectsOnly=2};
    virtual ModelerFlavor  getModelerFlavor() const { return ZcDbHostApplicationServices::kModelerFull; }

    code_page_id getSystemCodePage() const;


    void setSystemCodePage(code_page_id);

    virtual ZcadInternalServices* zcadInternalServices();

    void * zcadInternalGetvar (const ZCHAR *name);


    virtual Zdesk::Boolean isURL(const ZCHAR * pszURL) const;


    virtual Zdesk::Boolean isRemoteFile(const ZCHAR * pszLocalFile,
                                          ZCHAR * pszURL) const;


    virtual Zcad::ErrorStatus getRemoteFile(const ZCHAR * pszURL,
     ZCHAR * pszLocalFile, Zdesk::Boolean bIgnoreCache = Zdesk::kFalse) const;


    virtual Zcad::ErrorStatus putRemoteFile(const ZCHAR * pszURL, 
        const ZCHAR * pszLocalFile) const;


    virtual Zdesk::Boolean launchBrowserDialog(
                 ZCHAR *          pszSelectedURL,
                 const ZCHAR *    pszDialogTitle,
                 const ZCHAR *    pszOpenButtonCaption,
                 const ZCHAR *    pszStartURL, 
                 const ZCHAR *    pszRegistryRootKey = 0,
                 Zdesk::Boolean bOpenButtonAlwaysEnabled = Zdesk::kFalse) const;


    virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
                                      Zdesk::LongPtr hdc, 
        long left, long top, long right, long bottom);


    virtual Zcad::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);


    virtual Zcad::ErrorStatus serializeOleItem(COleClientItem* pItem,
        CArchive*);


    virtual Zdesk::Boolean _entToWorldTransform(double normal[3], 
                                                flagmat *tran);

    virtual void terminateScript(); 


    virtual Zdesk::Boolean getSubstituteFont(ZCHAR **pFileName,
                                             ZCHAR *prompt, 
                                             int type, int fontAlt); 
    virtual void alert(const ZCHAR * string) const;

    virtual void auditPrintReport(ZcDbAuditInfo * pAuditInfo,
                                             const ZCHAR *    line,
                                             int             both) const;

    virtual ZCHAR * getAlternateFontName() const { return ZCRX_T(""); }

    virtual ZCHAR * getFontMapFileName() const { return ZCRX_T(""); }

    virtual bool cacheSymbolIndices() const { return false; }

    virtual ZcDbPlotSettingsValidator* plotSettingsValidator() const; 
    virtual ZcDbLayoutManager* layoutManager() const;
    virtual bool loadApp(const ZCHAR * appName, 
                         ZcadApp::LoadReasons why, 
                         bool printit, 
                         bool asCmd);
    virtual void getDefaultPlotCfgInfo(ZCHAR * plotDeviceName,
                                       ZCHAR * plotStyleName); 


    virtual Zcad::ErrorStatus signingComplete(Zcad::ErrorStatus es,
                                              const ZCHAR * msg,
                                              bool* result);

    enum PasswordOptions {kPasswordOptionDefault = 0, kPasswordOptionUpperCase =1, kPasswordOptionIsExternalReference = 2};
    virtual bool getPassword(const ZCHAR * dwgName,
                             PasswordOptions options,
                             wchar_t *password, 
                             const size_t bufSize);

    virtual void usedPasswordFromCacheMsg(const ZCHAR *dwgName);
    virtual void missingCryptoProviderMsg();

    virtual const ZCHAR * getColorBookLocation() const { return NULL; }

    ZcPwdCache * getPasswordCache() const;

protected:
    

    Zcad::ErrorStatus mapInetStatusToZcadStatus(
        const ZcadInet::Status status) const;



protected:

    void * mp_sessionVars;

    void zcadInternalSetvar (const ZCHAR *name, void * var);

private:
    

    ZcDbDatabase* mpWorkingDatabase;
    ZcDbUndoController* mpDefaultUndoController;
    ZcDbTransactionManager* mpWorkingTransactionManager;
    ZcDbGlobals * mpWorkingGlobals;
    ZcDbAppSystemVariables * mpWorkingAppSysvars;

    code_page_id m_eSystemCodePage;
                                
    Zdesk::Boolean mbDisplayMessages;

    ZcPwdCache * mpPasswordCache;
};


Zcad::ErrorStatus zcdbSetHostApplicationServices(ZcDbHostApplicationServices * pServices);


inline ZcDbHostApplicationServices * 
zcdbHostApplicationServices()
{
    return s_pServices;
}


Zcad::ErrorStatus zcdbSendInitialDwgFileOpenComplete(ZcDbDatabase* pDb);

extern ZcDbGlobals* getDefaultGlobals();

inline ZcDbGlobals *
ZcDbHostApplicationServices::workingGlobals() const
{
    return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
}

inline code_page_id
ZcDbHostApplicationServices::getSystemCodePage() const
{
    return this->m_eSystemCodePage;
}

inline ZcDbUndoController *
ZcDbHostApplicationServices::defaultUndoController()
{
    return mpDefaultUndoController;
}

inline ZcDbAppSystemVariables * 
ZcDbHostApplicationServices::workingAppSysvars() const
{
    return mpWorkingAppSysvars;
}

inline void 
ZcDbHostApplicationServices::setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars)
{
    mpWorkingAppSysvars = pSysvars;
}

inline void 
ZcDbHostApplicationServices::terminateScript()
{
    return;
}

inline void 
ZcDbHostApplicationServices::reportUnhandledZrxException(
                    const _EXCEPTION_POINTERS *pExcPtrs,
                    const ZCHAR *pAppName)
{
    return;
}

inline Zcad::ErrorStatus
ZcDbHostApplicationServices::selectFile(/*[out]*/ short *userCancel,
                                        /*[out]*/ ZCHAR *& chosenPath,
                                        void* h, // HWND
                                        const int nFlags,
                                        const ZCHAR * prompt,
                                        const ZCHAR * dir,
                                        const ZCHAR * name,
                                        const ZCHAR * type,
                                        int* pnChoice,
                                        bool* pbReadOnly,
                                        const ZCHAR * pszWSTags,
                                        void* pReserved) 
{ 
    return Zcad::eNotHandled;
}

inline Zcad::ErrorStatus   
ZcDbHostApplicationServices::registerSelectFileCallback(const ZCHAR * appName,
                                                        SELECTFILEPROC proc, 
                                                        bool unRegister, 
                                                        bool asPrimary)
{
	return Zcad::eNotImplementedYet;
}
inline const ZCHAR *
ZcDbHostApplicationServices::primaryClientForSelectFileCallback() 
{
    return NULL;
}


inline Zcad::ErrorStatus 
ZcDbHostApplicationServices::mapFile(ZCHAR *& newName,
                                     const ZCHAR * filename,
                                     int context,
                                     void* pReserved) 
{
    return Zcad::eNotHandled;
}
    
inline Zcad::ErrorStatus
ZcDbHostApplicationServices::registerMapFileCallback(const ZCHAR *, REMAPPROC,
                                                     bool unRegister,
                                                     bool asPrimary)
{
    return Zcad::eNotImplementedYet;
}
    
inline const ZCHAR *
ZcDbHostApplicationServices::primaryClientForMapFileCallback() 
{
    return NULL;
}

inline
Zcad::ErrorStatus
ZcDbHostApplicationServices::getRegisteredSelectFileClients(
                                            ZcArray<const ZCHAR *>& clients)
{
    return Zcad::eNotImplementedYet;
}

inline
Zcad::ErrorStatus
ZcDbHostApplicationServices::getRegisteredFileMapClients(
                                            ZcArray<const ZCHAR *>& clients)
{
    return Zcad::eNotImplementedYet;
}

inline Zcad::ErrorStatus
ZcDbHostApplicationServices::registerMapFileNotification(const ZCHAR * appName, 
                                                         MAPFILENOTIFYPROC,
                                                         bool unRegister)
{
    return Zcad::eNotImplementedYet;
}

inline bool
ZcDbHostApplicationServices::setMapFlag(bool setIt)
{
    return false;
}

inline ZcPwdCache * 
ZcDbHostApplicationServices::getPasswordCache() const
{
    return mpPasswordCache;
}


void zcdbTriggerZcadOctTreeReclassification();


Zcad::ErrorStatus zcdbSetBreak3dQueueForRegen(bool);



class ZDESK_NO_VTABLE ZcDbPasswordedFile
{
protected:
    virtual Zcad::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;
    virtual const ZCHAR* getFullPath() = 0;
public:
    Zcad::ErrorStatus open(const wchar_t* wszPassword, ZcDbHostApplicationServices::PasswordOptions options);
};

#pragma pack (pop)

#endif


