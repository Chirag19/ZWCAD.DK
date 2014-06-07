
#ifndef ZCDOCMAN_H
#define ZCDOCMAN_H

#include <wtypes.h>

#include "zcdb.h"
#pragma pack (push, 8)

class ZcTransactionManager;
class ZcDbDatabase;
class CDocument;
class ZcEdInputPointManager;
class ZcApStatusBar;
class ZcApPlotReactor;
class ZcRxIterator;

class ZcApDocImpManagerReactor;

struct IDispatch;


#define ZC_DOCUMENT_MANAGER_OBJ _T("ZcApDocManager")

struct ZcAp {

    enum DocLockMode   {   kNone               = 0x00,
                           kAutoWrite          = 0x01,
                           kNotLocked          = 0x02,
                           kWrite              = 0x04,
                           kProtectedAutoWrite = 0x14,
                           kRead               = 0x20,
                           kXWrite             = 0x40  };
};

class ZcLispAppInfo
{
public:
    ZCHAR appFileName[_MAX_PATH];
    bool bUnloadable;
};

class ZDESK_NO_VTABLE ZcApDocument : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocument);

    virtual const ZCHAR*       fileName() const = 0;

    virtual CDocument* cDoc() const = 0;

    virtual ZcTransactionManager* transactionManager() const = 0;

    virtual ZcDbDatabase*     database() const = 0;

	enum SaveFormat {
		kUnknown = -1, 
		kR12_dxf = 1,

		kR13_dwg = 4,
		kR13_dxf = 5, 

		kR14_dwg = 8,
		kR14_dxf = 9,

		k2000_dwg = 12,
		k2000_dxf = 13,
		k2000_Template = 14,
		k2000_Standard = 15,
		k2000_xml = 16,

		k2004_dwg = 24,
		k2004_dxf = 25,
		k2004_Template = 26,
		k2004_Standard = 27,

		k2007_dwg =36,
		k2007_dxf =37, 
		k2007_Template = 38,
		k2007_Standard = 39,

		kNative = k2007_dwg,

		kR15_dwg = k2000_dwg,
		kR15_dxf = k2000_dxf,
		kR15_Template = k2000_Template,
		kR15_Standard = k2000_Standard,
		kR15_xml = k2000_xml,

		kR18_dwg = k2004_dwg,
		kR18_dxf = k2004_dxf,
		kR18_Template = k2004_Template,
		kR18_Standard = k2004_Standard
	};

    virtual SaveFormat formatForSave() const = 0;

    virtual ZcAp::DocLockMode lockMode(bool bIncludeMyLocks =
                                           false) const = 0;
    virtual ZcAp::DocLockMode myLockMode() const = 0;

    virtual bool    isQuiescent() const = 0;

    virtual void * contextPtr() const = 0;

    virtual ZcEdInputPointManager* inputPointManager() = 0;

    virtual const ZCHAR * docTitle() const = 0;

    virtual IDispatch * GetIDispatch(bool bAddRef) = 0;

    virtual bool isReadOnly() const = 0;

    virtual int GetCountOfLispList() const = 0;
    virtual ZcLispAppInfo* GetItemOfLispList(int nIndex) const = 0;

    virtual ZcApStatusBar* drawingStatusBar() const = 0;

    void              pushDbmod();
    Zcad::ErrorStatus popDbmod();
};


class ZDESK_NO_VTABLE ZcApDocManagerReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocManagerReactor);

    virtual void              documentCreateStarted(ZcApDocument* pDocCreating);
    virtual void              documentCreated(ZcApDocument* pDocCreating);
    virtual void              documentToBeDestroyed(ZcApDocument* pDocToDestroy);
    virtual void              documentDestroyed(const ZCHAR* fileName);
    virtual void              documentCreateCanceled(ZcApDocument* pDocCreateCancelled);


    virtual void              documentLockModeWillChange(ZcApDocument* ,
                                         ZcAp::DocLockMode myCurrentMode,
                                         ZcAp::DocLockMode myNewMode,
                                         ZcAp::DocLockMode currentMode,
                                         const ZCHAR* pGlobalCmdName);
    virtual void              documentLockModeChangeVetoed(ZcApDocument* ,
                                         const ZCHAR* pGlobalCmdName);
    virtual void              documentLockModeChanged(ZcApDocument* ,
                                         ZcAp::DocLockMode myPreviousMode,
                                         ZcAp::DocLockMode myCurrentMode,
                                         ZcAp::DocLockMode currentMode,
                                         const ZCHAR* pGlobalCmdName);

    virtual void              documentBecameCurrent(ZcApDocument* );
 
    virtual void              documentToBeActivated(ZcApDocument* pActivatingDoc );

    virtual void              documentToBeDeactivated(ZcApDocument* pDeActivatedDoc );

    virtual void              documentActivationModified(bool bActivation);

    virtual void              documentActivated(ZcApDocument* pActivatedDoc);
protected:
    ZcApDocManagerReactor();
    Zcad::ErrorStatus         veto();

private:
    Zdesk::Int8               mVeto;
	ZcApDocImpManagerReactor* mpImp;

friend class ZcApDocImpManager;
};


class ZDESK_NO_VTABLE ZcApDocumentIterator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocumentIterator);

    virtual bool    done() const = 0;
    virtual void              step() = 0;
    virtual ZcApDocument*       document() = 0;
};


class ZDESK_NO_VTABLE ZcApDocManager : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocManager);

    virtual ZcApDocument*       curDocument() const = 0;
    virtual ZcApDocument*       mdiActiveDocument() const = 0;

    virtual bool    isApplicationContext() const = 0;

    virtual ZcApDocument*       document(const ZcDbDatabase* ) const = 0;

    virtual Zcad::ErrorStatus lockDocument(ZcApDocument* pDoc,
                                   ZcAp::DocLockMode = ZcAp::kWrite,
                                   const ZCHAR* pGlobalCmdName = NULL,
                                   const ZCHAR* pLocalCmdName = NULL,
                                   bool prompt = true) = 0;
    virtual Zcad::ErrorStatus unlockDocument(ZcApDocument* pDoc) = 0;

    virtual ZcApDocumentIterator* newZcApDocumentIterator() = 0;

    virtual void              addReactor(ZcApDocManagerReactor* ) = 0;
    virtual void              removeReactor(ZcApDocManagerReactor* ) = 0;

    virtual Zcad::ErrorStatus setDefaultFormatForSave(
                                ZcApDocument::SaveFormat format) = 0;

    virtual Zcad::ErrorStatus setCurDocument(ZcApDocument* pDoc,
                                   ZcAp::DocLockMode = ZcAp::kNone,
                                   bool activate = false) = 0;

    virtual Zcad::ErrorStatus activateDocument(ZcApDocument* pZcTargetDocument,
                                               bool bPassScript = false) = 0;

    virtual Zcad::ErrorStatus sendStringToExecute(ZcApDocument* pZcTargetDocument,
                                       const ZCHAR * pszExecute,
                                       bool bActivate = true,
                                       bool bWrapUpInactiveDoc = false,
                                       bool bEchoString = true) = 0;    

    virtual Zcad::ErrorStatus appContextNewDocument(const ZCHAR *pszTemplateName) = 0;
    virtual Zcad::ErrorStatus appContextOpenDocument(const ZCHAR *pszDrawingName) = 0;

    struct DocOpenParams {
        union {
            const ZCHAR * mpszFileName;
            const wchar_t * mpwszFileName;
        };
        union {
            const ZCHAR * mpszViewName;
            const wchar_t * mpwszViewName;
            const double * mpCoords;
        };
        enum {kUnknown = 0,
              kDefaultView = 1, 
              kLayoutName = 2, 
              kViewName = 3, 
              kLayoutHandle = 4,
              kViewHandle = 5,
              kViewWorldCoords = 6};
        BYTE mnInitialViewType;
        enum {  kDisallowReadOnly       = 0x01,
                kRequireReadOnly        = 0x02,
                kFileNameArgIsUnicode   = 0x04,
                kViewNameArgIsUnicode   = 0x08,
                kUseUIOnErrors          = 0x10};
        int  mnFlags; 
        const wchar_t * mpwszPassword;
        void  * mpUnused;
        int  mnUnused;
    };

    virtual Zcad::ErrorStatus newDocument() = 0;
    virtual Zcad::ErrorStatus openDocument() = 0;
    virtual Zcad::ErrorStatus closeDocument(ZcApDocument* pZcTargetDocument) = 0;

    virtual int    inputPending(ZcApDocument* pZcTargetDocument) = 0;

    virtual Zcad::ErrorStatus disableDocumentActivation() = 0;
    virtual Zcad::ErrorStatus enableDocumentActivation() = 0;
    virtual bool isDocumentActivationEnabled() = 0;

    virtual void executeInApplicationContext(void (*procAddr)(void *), void *pData ) const = 0;

    virtual int documentCount() const = 0;

    virtual void pushResourceHandle( HINSTANCE hNewResourceHandle) = 0;
    virtual void pushZcadResourceHandle() = 0;
    virtual void popResourceHandle() = 0;
    virtual Zcad::ErrorStatus sendModelessInterrupt(ZcApDocument* pZcTargetDocument) = 0;
};



ZcApDocManager* zcDocManagerPtr();
#define zcDocManager zcDocManagerPtr()

inline ZcApDocument* curDoc() { return ::zcDocManager->curDocument(); }

#pragma pack (pop)
#endif

