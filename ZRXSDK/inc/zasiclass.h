#ifndef ZASI_ASICLASS_HH
#define ZASI_ASICLASS_HH zasiclasshh

#include <zasisdata.h>

#include <zavoidtry.h>

#define ASI_TRY           { AsiExceptionHandler AsiExceptionHandler; try {  

#define ASI_CATCH(x)      } catch(AsiException* x) { x=x;

#define ASI_END_CATCH     }}
#define ASI_THROW(x)      AsiExceptionThrow(x);
#define ASI_THROW_LAST    AsiExceptionThrow(0);

#pragma pack (push, 8)

class DLLScope ZAsiObject;
    class ZAsiHostBuffer;
        class ZAsiParameter;
  
    class ZAsiException;

    class ZAsiSQLObject;
        class ZAsiSession;
        class ZAsiStm;
            class ZAsiExecStm;
            class ZAsiCsr;
                class ZAsiCsrTable;
                    class ZAsiCsrRegTable;
                    class ZAsiCsrInfSchema;
                    class ZAsiEnumerator;
        class ZAsiBinding;


    class ZAsiDSProperties;
class ZAsiTACond;
class ZAsiTCCond;

class ZAsiExceptionHandler;

typedef enum {
    kOpNodeUndefined = 0,
    kOpNot,
    kOpOr,
    kOpAnd,
    kOpTest,
    kOpNull,
    kOpGtr,
    kOpGeq,
    kOpEq,
    kOpLeq,
    kOpLss,
    kOpNeq
} EAsiCompType;

class ZAsiExceptionHandler
{
public:
    ZAsiExceptionHandler(void);
    ~ZAsiExceptionHandler(void);
    ZAsiException*        pException;
    ZAsiExceptionHandler* pPrevHandler;
    EAsiBoolean           wasThrown;
};

class ZAsiException : public ZAsiObject
{
    friend class ZAsiSQLObject;
public:
                            ZAsiException (void);
    virtual					~ZAsiException (void);

    int						CondQty    (void) const;
    AsiError				Err        (int d = 0) const;
    ZAsiUcStr		*		ErrMsg     (int d = 0) const;
    char			*		SQLSTATE   (int d = 0) const;
    int						ErrPosition (void) const;     

    EAsiBoolean				getDiagPar (int, AsiDiag, integer *) const;
    EAsiBoolean				getDiagPar (int, AsiDiag, ZAsiUcStr *) const;

    EAsiBoolean				setErr      (AsiError);
    EAsiBoolean				setErrMsg   (const ZAsiUcStr &);
    EAsiBoolean				setSQLSTATE (const char *);

    EAsiBoolean				setDiagPar	(AsiDiag, integer);
    EAsiBoolean				setDiagPar	(AsiDiag, const ZAsiUcStr &);
     
    EAsiBoolean				pushCond	(void);
    EAsiBoolean				flushCond	(void);

    void			*  		getDiagData (void) const;
    void					setErrPosition (int);

    virtual ZAsiObject *	duplicate	(void) const;         

private:
    void		*			pExceptionBody;
};

class ZAsiSQLObject : public ZAsiObject
{
friend class ZAsiCsr;
friend class ZAsiExecStm;
friend class ZAsiBinding;
public:
protected:
    ZAsiSQLObject();

protected:
    virtual EAsiBoolean         setErr      (EAsiError);
    virtual EAsiBoolean         setErrMsg   (const ZAsiUcStr &);
    virtual EAsiBoolean         setSQLSTATE (const char *);

    virtual EAsiBoolean         setDiagPar (EAsiDiag, integer);
    virtual EAsiBoolean         setDiagPar (EAsiDiag, const ZAsiUcStr &);
        
    virtual EAsiBoolean			pushCond   (void);
    virtual EAsiBoolean			flushCond  (void); 

    virtual EAsiBoolean			pushErr    (EAsiError);
    virtual EAsiBoolean			pushHResult(HRESULT);

public:
    virtual                     ~ZAsiSQLObject  ();

    EAsiStatement               StmType         (void) const;
    LONG_PTR                    RowCount        (void) const;

    virtual EAsiBoolean         IsRowset        (void) const;

    virtual int                 ErrPosition     (void) const;     

    virtual int                 CondQty         (void) const;
    virtual EAsiError           Err             (int d = 0) const;
    virtual ZAsiUcStr       *   ErrMsg          (int d = 0);
    virtual char            *   SQLSTATE        (int d = 0);

    virtual EAsiBoolean         getDiagPar      (int d,EAsiDiag,integer*) const;
    virtual EAsiBoolean         getDiagPar      (int d,EAsiDiag, ZAsiUcStr*) const;

    EAsiBoolean                 DBMS            (ZAsiUcStr *) const;
    EAsiBoolean                 SQLObject       (ZAsiUcStr *) const;
    EAsiBoolean                 DrvMessage      (ZAsiUcStr *) const;
    EAsiBoolean                 CheckOp         (ulong);
    virtual EAsiBoolean         GetStatus       (EAsiStatInfo, ULONG_PTR *);

    const char             *    Version         (void) const;

protected:
    EAsiBoolean                 isInit      (void) const;
    EAsiBoolean                 InitErrorInfo (HRESULT, IUnknown *, GUID);
    void                        ReleaseErrorInfo ();
    void						InheritStatusInfo (const ZAsiSQLObject &);

protected:
    IErrorInfo          *       m_pIErrorInfo;
    HRESULT                     m_HResult;

private:
    static const char   *       m_pAsiVersion;
    ZAsiException               m_Except;

protected:
    EAsiBoolean                 m_CSP;

protected:
    EAsiStatement               m_eStmType;
	LONG_PTR                m_lRowCount;

    ZAsiDSProperties	   *	m_pDSProperties;

};

class ZAsiAppl: public ZAsiSQLObject
{
friend class ZAsiSession;
friend class ZAsiEnumerator;
friend class ZAsiCsr;
public:
      ZAsiAppl();  
      virtual ~ZAsiAppl();

      EAsiBoolean               Init            (void);
      EAsiBoolean               Term            (void);
      EAsiBoolean               Abort           (void);
      EAsiBoolean               DisconnectAll   (void);

protected:
      EAsiBoolean               addConnection   (ZAsiSession *);
      EAsiBoolean               removeConnection(ZAsiSession *);

private: 
      EAsiBoolean               rollbackAll     (void);

private:
      IClassFactory		*		m_pIClassFactory;
      IDataInitialize	*		m_pIDataInitialize;
      IDataConvert		*		m_pIDataConvert;
      ZAsiObject        *       m_pSessions;
};

class ZAsiSession: public ZAsiSQLObject
{
friend class ZAsiStm;
friend class ZAsiCsr;
friend class ZAsiExecStm;
friend class ZAsiAppl;
friend class ZAsiCsrTable;
friend class ZAsiCsrInfSchema;
friend class ZAsiCsrRegTable;
public:
    ZAsiSession         (ZAsiAppl *);
    virtual                 ~ZAsiSession        ();

    EAsiBoolean             Connect             (const ZAsiUcStr & LinkFile, 
                                                 const ZAsiUcStr & Username,
                                                 const ZAsiUcStr & Password,
                                                 EAsiBoolean	   fPrompt = kAsiFalse);

    EAsiBoolean				ConnectIniString	(const ZAsiUcStr & IniString);

    EAsiBoolean				GetConnectionString (ZAsiUcStr *);
    EAsiBoolean             Disconnect          (void);

    EAsiBoolean             SetCatalog          (const ZAsiUcStr &);
    EAsiBoolean             SetSchema           (const ZAsiUcStr &);
    EAsiBoolean             SetNames            (const ZAsiUcStr &);
    EAsiBoolean             SetTimeZone         (const ZAsiDT &);
    EAsiBoolean             SetTimeZone         (void);
    EAsiBoolean             SetAuthor           (const ZAsiUcStr &);

    EAsiBoolean             SetTrans            (EAsiTILevel, EAsiTMode, uint dSize = 64);
    EAsiBoolean             DeferrConstr        (ZAsiIdent * cnst = 0);
    EAsiBoolean             ImmConstr           (ZAsiIdent * cnst = 0);

    EAsiBoolean             Commit              (void);
    EAsiBoolean             Rollback            (void);

    const ZAsiUcStr      &  Name                (void) const;
    virtual EAsiBoolean     GetStatus			(EAsiStatInfo, ULONG_PTR *);

protected:
    EAsiBoolean             Disconnect          (ZAsiObject *);
    EAsiBoolean				GetCatalog			(ZAsiUcStr *);

private:
    virtual ZAsiObject  *   duplicate           (void) const;
    EAsiBoolean			CreateSession		(IDBInitialize *);

    EAsiBoolean            Execute             (const ZAsiUcStr &);

    EAsiBoolean			CheckForNotNull		(EAsiInfSchTab, int);
    EAsiBoolean			CanRetrieveCatalogs	(void);
    EAsiBoolean			CanRetrieveSchemas	(void);
    void					GetProviderTypes	(void);
    EAsiBoolean			GetStatusInfo 		();

    void					AttachStm			(ZAsiExecStm *);
    void					DetachStm			(ZAsiExecStm *);
    void					DetachAllStm 		(void);
    void					DeallocateAllStm	(void);


    void					AttachCsr			(ZAsiCsr *);
    void					DetachCsr 			(ZAsiCsr *);
    void					DetachAllCsr 		(void);

    EAsiBoolean			HasOpenedObjects	(void);

private: 
    ZAsiAppl            *   m_pAppl;
    ZAsiUcStr               m_LinkFileName ;
    ZAsiUcStr				m_ConnectionString;
    IUnknown            *   m_pISession;
    ZAsiUcStr				m_ucCatalog;

    ULONG                   m_BLOBStorage;

    ZAsiList			*	m_pStms;
    ZAsiList			*	m_pCsrs;
};

class ZAsiStm: public ZAsiSQLObject
{
friend class ZAsiSession;

public:
    ZAsiStm(void);
    virtual ~ZAsiStm(void);

    void SetSession(ZAsiSession *);

    virtual int                 ParamQty        (void) const;
    virtual ZAsiParameter   *   ParamDsc        (int) const;

    virtual EAsiBoolean         Bind            (int, ZAsiData *);
    virtual EAsiBoolean         Bind            (int, void *, short *,
                                                 int, EAsiHostType);

    virtual EAsiBoolean         Bind            (const ZAsiIdent &, ZAsiData *);
    virtual EAsiBoolean         Bind            (const ZAsiIdent &, void *, short *,
                                                 int, EAsiHostType);
    virtual int                 ColQty          (void) const;
    virtual ZAsiColumn *        ColDsc          (int) const;

    virtual EAsiBoolean         Sob             (int, ZAsiData *);
    virtual EAsiBoolean         Sob             (int, void *, short *,
                                                 int, EAsiHostType); 

    virtual EAsiBoolean         Cvl             (int, ZAsiData *);
    virtual EAsiBoolean         Cvl             (int, void *, short *,int, EAsiHostType);

protected:
    EAsiBoolean                 CvlInt          (int, ZAsiData *) const;
    EAsiBoolean                 pInput          (void);
    EAsiBoolean				InitColsDsc		();

protected:
    ZAsiBinding             *   m_pInput;
    ZAsiBinding             *   m_pOutput;

    ZAsiSession             *   m_pSession;

    ULONG_PTR                   m_lColNumber;
    DBCOLUMNINFO            *   m_pColumnInfo;
    OLECHAR                 *   m_pStringBuff;
    ZAsiRow                 *   m_pAsiRow;
};

class ZAsiExecStm: public ZAsiStm
{
friend class ZAsiCsr;
friend class ZAsiSession;
public:
                                ZAsiExecStm         (void);
    virtual                     ~ZAsiExecStm        (void);


    virtual EAsiBoolean         IsRowset            (void) const;

    virtual EAsiBoolean         Prepare             (ZAsiSession *, 
                                                     const ZAsiUcStr &, 
                                                     EAsiBoolean trans = kAsiTrue);
    virtual EAsiBoolean         Deallocate          (void);

    virtual EAsiBoolean         Execute             (void);
    virtual EAsiBoolean         ImmediateExecute    (ZAsiSession *, 
                                                     const ZAsiUcStr &,
                                                     EAsiBoolean trans = kAsiTrue);
    EAsiBoolean					Cancel              (void);

    virtual int                 ParamQty            (void) const;
    virtual ZAsiParameter   *   ParamDsc            (int) const;

    virtual EAsiBoolean         Bind                (int, ZAsiData *);
    virtual EAsiBoolean         Bind                (int, void *, short *, int, EAsiHostType);
    virtual EAsiBoolean         Bind                (const ZAsiIdent &, ZAsiData *);
    virtual EAsiBoolean         Bind                (const ZAsiIdent &, void *, short *, int, EAsiHostType);


    virtual int                 ColQty              (void) const;
    virtual ZAsiColumn *        ColDsc              (int) const; 

    virtual EAsiBoolean			GetStatus			(EAsiStatInfo, ULONG_PTR *);


private:
    virtual ZAsiObject      *   duplicate           (void) const;

    EAsiBoolean                 Prepare             (void);

    EAsiBoolean					IsPrepared			(void) const;
    void						AttachCsr			(ZAsiCsr *);
    void						DetachCsr			(ZAsiCsr *);
    void						DetachAllCsr 		(void);
    void						CloseAllCsr			(void);

protected:
    ICommandText            *   m_pICommand;

    ULONG                       m_lParNumber;
    DBPARAMINFO             *   m_pParamInfo;
    OLECHAR                 *   m_pStringBuffParam;

    ZAsiList				*	m_pCsrs;
};

class ZAsiCsr: public ZAsiStm
{
friend class ZAsiExecStm;
public:
	ZAsiCsr(void);
	virtual ~ZAsiCsr(void);
    EAsiBoolean                 Allocate            (ZAsiExecStm * csrspec,      
                                                     const ZAsiIdent & csrname, 
                                                     EAsiCurScr sc = kAsiNonScroll,
                                                     EAsiCurSns sn = kAsiSnsUndef,
                                                     EAsiBoolean upd = kAsiUnknown,
                                                     EAsiBoolean fIns = kAsiFalse);

    virtual int                 ParamQty            (void) const;
    virtual ZAsiParameter   *   ParamDsc            (int) const;

    virtual EAsiBoolean         Bind                (int, ZAsiData *);
    virtual EAsiBoolean         Bind                (int, void *, short *, int, EAsiHostType);
    virtual EAsiBoolean         Bind                (const ZAsiIdent &, ZAsiData *);
    virtual EAsiBoolean         Bind                (const ZAsiIdent &, void *, short *, int, EAsiHostType);

    virtual EAsiBoolean         Sob                 (int, ZAsiData *);
    virtual EAsiBoolean         Sob                 (int, void *, short *, int, EAsiHostType); 

    virtual EAsiBoolean         Open                (void);
    virtual EAsiBoolean         Close               (void);
    EAsiBoolean				 Cancel              (void);

    virtual EAsiBoolean         Fetch               (void);
    virtual EAsiBoolean         FetchPrior          (void);
    virtual EAsiBoolean         FetchFirst          (void);
    virtual EAsiBoolean         FetchLast           (void);
    virtual EAsiBoolean         FetchRelative       (long);
    virtual EAsiBoolean         FetchAbsolute       (long);
    virtual EAsiBoolean         CheckCCondition     (ZAsiData **);

    ZAsiRow*       getCurrentRow       (void);

    virtual EAsiBoolean         Delete              (void);
    virtual EAsiBoolean         Update              (const ZAsiRow &);

    virtual EAsiBoolean			Insert				(const ZAsiRow &);
    virtual EAsiBoolean			Insert				(void);


    virtual int                 ColQty              (void) const;
    virtual ZAsiColumn *        ColDsc              (int) const; 

    virtual EAsiBoolean         Cvl                 (int, ZAsiData *);
    virtual EAsiBoolean         Cvl                 (int, void *, short *,
                                                     int, EAsiHostType); 

	virtual EAsiBoolean		 GetStatus			(EAsiStatInfo, ULONG_PTR *);
    virtual EAsiBoolean         IsRowset            (void) const;
    virtual EAsiBoolean         is_updatable        (void) const;
    virtual EAsiBoolean         is_insertable       (void) const;
    virtual EAsiBoolean         is_scrollable       (void) const;
    virtual EAsiBoolean         is_insensitive      (void) const;
    virtual EAsiBoolean         is_open             (void) const;
    virtual EAsiCurPos          position            (void) const;


private:
    virtual ZAsiObject  *       duplicate           (void) const;

protected:
    EAsiBoolean                 InitOutputBind      ();
    EAsiBoolean                 MakeCursorProp      (DBPROPSET  * pRowsetPropSet);
    EAsiBoolean                 QueryCursorProp     (void);
    EAsiBoolean					SobValues           (void);
    EAsiBoolean					Svl                 (int);
    EAsiBoolean                 ReadData            (void);
    EAsiBoolean                 GetColValue         (int, ZAsiData *);
    EAsiBoolean					StoreValueFromDBType(ZAsiData *, DBTYPE, void *);
	EAsiBoolean					InitAccessor		(ULONG_PTR, DBCOLUMNINFO *, const ZAsiRow &,
                                                     ULONG *, DBBINDING	**,	HACCESSOR *,
                                                     EAsiBoolean);

    EAsiBoolean					DoChangeErrors		(HRESULT hr, ULONG, DBBINDING *);
    EAsiBoolean                 UpdateRow           (ULONG_PTR, DBCOLUMNINFO *, const ZAsiRow &);
    EAsiBoolean                 InsertRow           (ULONG_PTR, DBCOLUMNINFO *, const ZAsiRow &);

protected:
    ZAsiExecStm         *       m_pCursorSpec;
    IRowset             *       m_pIRowset;
    IRowsetChange       *       m_pIRowsetChange;
    IRowsetLocate       *       m_pIRowsetLocate;

    IAccessor           *       m_pIAccessor;
    HACCESSOR                   m_hAccessor;
    DWORD_PTR                   m_lRowCount; 
    DWORD                       m_lCurrRow;

    IDataConvert		*		m_pIDataConvert;

    HROW                *       m_rghRows;
    BYTE                *       m_pData;

    DWORD_PTR                   m_dwOffset;
    DBBINDING           *       m_rgBind;
    int                         m_iNumBind;
    EAsiBoolean                m_fDataRead;


    EAsiBoolean				m_fBlkStorObj;
    EAsiBoolean                m_fBLOBExpected;
    IUnknown			*		m_pIUnknown;

    ZAsiIdent                   m_CsrName;
    EAsiCurScr                 m_ScrFlag;
    EAsiCurSns                 m_SnsFlag;
    EAsiBoolean                m_fUpd;
    EAsiBoolean                m_fIns;
    EAsiBoolean				m_fOwnInserts;
    EAsiBoolean				m_fOwnUpdates;


    EAsiBoolean				m_fIsOpen;

    EAsiCurPos                 m_CsrPos;

    ULONG_PTR                   m_ulColumns;
    ULONG                       m_ulCurrentRowNo;
    ULONG                       m_ulMaxRowNo;
    ULONG                       m_ulRows;
    ZAsiTCCond              *   m_pTCCond;
};

class ZAsiCsrTable : public ZAsiCsr
{
public:
                                ZAsiCsrTable        (void);
    virtual                     ~ZAsiCsrTable       (void);

    virtual int                 ColQty              (void) const;
    virtual ZAsiColumn *        ColDsc              (int) const; 

    virtual EAsiBoolean         Open                (void);
    virtual EAsiBoolean         Close               (void);

    virtual EAsiBoolean         Update              (const ZAsiRow &); 

    virtual EAsiBoolean         Cvl                 (int, ZAsiData *);
    virtual EAsiBoolean         Cvl                 (int, void *, short *,
                                                     int, EAsiHostType); 

    virtual EAsiBoolean         SetFilter           (ZAsiTCCond *);
    virtual EAsiBoolean         SetOrder            ();

protected:
    void                        DeallocCsr          (void);

protected:
};

class ZAsiCsrRegTable : public ZAsiCsrTable
{
public:
	ZAsiCsrRegTable     (void);
    virtual                     ~ZAsiCsrRegTable    (void);

    EAsiBoolean                 Allocate            (ZAsiSession * ses, 
                                                     const ZAsiUcStr & catalog,    
                                                     const ZAsiUcStr & schema,   
                                                     const ZAsiUcStr & table,
                                                     EAsiCurScr    sc = kAsiNonScroll,
                                                     EAsiBoolean   upd = kAsiUnknown
                                                     ); 

protected:
    ZAsiUcStr                   m_pCatalog ;
    ZAsiUcStr                   m_pSchema;
    ZAsiUcStr                   m_pName;
};

class ZAsiCsrInfSchema : public ZAsiCsrTable
{
public:
                                ZAsiCsrInfSchema    (void);
    virtual                     ~ZAsiCsrInfSchema   (void);

    EAsiBoolean                 Allocate            (ZAsiSession * ses, 
                                                     EAsiInfSchTab ischema,
                                                     EAsiCurScr    sc = kAsiNonScroll
                                                     );

protected:
    EAsiInfSchTab               m_istType;
};

class ZAsiEnumerator: public ZAsiCsrTable
{
public:
	ZAsiEnumerator      (void);
    virtual                     ~ZAsiEnumerator     (void);

    EAsiBoolean                 Allocate            (ZAsiAppl *);
    EAsiBoolean                 Allocate            (ZAsiAppl *, CLSID & clsidEnum);

     void                        SetFilter           (EAsiDataSourceType dst,
                                                     const ZAsiUcStr & pName,
                                                     EAsiBoolean isParent = kAsiUnknown);

    virtual EAsiBoolean         Fetch               (void);

protected:
    CLSID                       m_clsidEnum;  
    EAsiDataSourceType          m_eDsType;
    ZAsiUcStr                   m_pName;
    EAsiBoolean                 m_fIsParent;
};

class ZAsiTACond: public ZAsiObject
{
    friend class ZAsiTCCond;

public:
                                ZAsiTACond          (void);
                                ZAsiTACond          (const ZAsiTACond &);
    virtual                      ~ZAsiTACond        (void);

    virtual ZAsiObject      *   duplicate           (void) const;

    ZAsiData                *   m_pData;
    int                         m_cColnum;
    EAsiCompType                m_CompOp;
};

class ZAsiTCCond: public ZAsiObject
{
public:
	ZAsiTCCond          (void);
	ZAsiTCCond          (int);
	ZAsiTCCond          (const ZAsiTCCond &);
	virtual                     ~ZAsiTCCond         (void);

	int Count(void) const;
	void Append(const ZAsiTACond &);

	ZAsiTACond& operator [] (int);

	virtual ZAsiObject* duplicate(void) const;

private:
	int m_cQnty;
	ZAsiList m_Conds;
};

EAsiBoolean ZAsiAllocateDSEnumerator (
    ZAsiAppl		*		pAppl,
    const GUID      *       guidEnum,
    const ZAsiUcStr &       pDS,
    ZAsiEnumerator  **      pEnum
);

EAsiBoolean ZAsiGetDSEnumerator (
    ZAsiAppl		*		pAppl,
    const GUID      *       guidEnum,
    const ZAsiUcStr &       pDS,
    GUID            *       guidDsEnum
);

extern "C" {
void ZAsiExceptionThrow (ZAsiException*);
}

#pragma pack (pop)
#endif