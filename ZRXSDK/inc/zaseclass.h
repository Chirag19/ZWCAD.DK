#ifndef _ZASECLASS_H
#define _ZASECLASS_H

#include <zasiappl.h>
#include <zaseconst.h>
#include <zdbmain.h>
#include "zdsdef.h"


#define ASEAPPL(x)       ((AseAppl*)x)
#define ASELINKPATH(x)   ((AseLinkPath*)x)
#define ASELINK(x)       ((AseLink*)x)
#define ASELINKSEL(x)    ((AseLinkSel*)x)


#define ASE_THROW(x)  {((AseApiObj*)x)->appThrow() ;}
#define WORKINGDWG()  NULL




#pragma pack (push, 8)
#if defined(__cplusplus)

class ZAseApiErr ;
class ZAseApiObj ;
  class ZAseAppl ;
  class ZAseLinkPath ;
  class ZAseLinkSel ;
  class ZAseReactor ;

class ZAseApiObj 

{
  public:
	                      ZAseApiObj();
                         ZAseApiObj(ZAseApiObj *pObj) ;
                         ZAseApiObj(ZAseApiObj &Obj) ;
  virtual                ~ZAseApiObj() ;
  virtual EAsiBoolean    init() ;
  virtual EAseApiClassId isA() const = 0 ;
  virtual ZAseApiObj    *clone() const = 0 ;
  virtual EAsiBoolean    copyFrom(const ZAseApiObj *pObj) ;
  virtual ZAseApiObj&    operator=(const ZAseApiObj &Obj) ;
  virtual int            operator==(const ZAseApiObj *pObj) const = 0 ;
  virtual int            operator==(const ZAseApiObj &Obj) const = 0 ;
  virtual EAsiBoolean    isInit() const ;
  const ZCHAR            *version() const ;
  const ZAsiException   *errGet() const ;
  int                    errQty() const ;
  EAseErrDsc             errDsc(int ErrNum) const ;
  int                    errCode(int ErrNum) const ;
  EAsiBoolean            errMsg(int ErrNum,
                                ZCHAR *pBuf,
                                int BufLen) const;
  EAsiBoolean            errClear() ;
  void                   appThrow() const ;
  const ZCHAR            *errDiagParNameCode(int ParNum,
                                            int *pParCode,
                                            int *pIsStr) const ;
  EAsiBoolean            errDiagPar(int ErrNum, 
                                    int ParCode,
                                    int *pIntValue) const ;
  EAsiBoolean            errDiagPar(int ErrNum, 
                                    int ParCode,
                                    ZCHAR *pStrValue,
                                    int BufLen) const ;

  
  EAsiBoolean            errInitAsi(ZAsiException *pErr) ;
  EAsiBoolean            errInitAsi(ZAsiSQLObject *pSQLObj) ;
  EAsiBoolean            errInitAsi(ZAsiSQLObject &sqlObj) ;

  friend class ZAseApiErr ;
  friend class ZAseAppl ;
  protected:
  struct resbuf         *getLast(const struct resbuf *bufptr) const ;
  struct resbuf         *allocAttr(EAseLinkAttr attr, const ZCHAR *pStr=NULL) const ;
  struct resbuf         *copyBuf(const struct resbuf *bufptr, 
                                 const struct resbuf *pBorder=NULL) const ;
  struct resbuf         *nextAttr(const struct resbuf *bufptr) const ;
  struct resbuf         *getAttrType(const struct resbuf *bufptr,
                                     EAseLinkAttr lattr) const ;
  const struct resbuf   *getAttrPtr(const struct resbuf *bufptr,
                                    EAseLinkAttr lattr) const ;
  EAsiBoolean            setAttrPtr(struct resbuf *bufptr,
                                    EAseLinkAttr LinkAttr,
                                    struct resbuf *pAttrValue) const ;
  struct resbuf         *delAttrPtr(struct resbuf *bufptr,
                                    struct resbuf *pAttr) const ;
  EAsiBoolean            parseLisp(struct resbuf *bufptr) ;
  ZAseAppl              *getAppl() const ;
  void                   freeStr(struct resbuf *pBuf) const ;
  EAsiBoolean            isDiffChar() const ;

  void                  *mpErr ;      
} ;

class ZAseAppl : public ZAseApiObj 
{
  public:
                         ZAseAppl(ZAseApiObj *pObj=NULL) ;
                         ZAseAppl(ZAseApiObj &Obj) ;
  virtual                ~ZAseAppl() ;
  virtual EAsiBoolean    init() ;
  virtual EAseApiClassId isA() const ;
  virtual ZAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const ZAseApiObj *pObj) ;
  virtual ZAseApiObj&    operator=(const ZAseApiObj &Obj) ;
  virtual int            operator==(const ZAseApiObj *pObj) const ;
  virtual int            operator==(const ZAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;
  void                   term() ;

  LPCTSTR                 getZcadDsPath();

  
  EAsiBoolean            getAseErr() ;
 
  EAsiBoolean            clearAseErr();

  
  ZAsiSession*           connectAse(ZAsiAppl *pAppl,
                                    const TCHAR *pEnvName,
                                    const ZCHAR *pUserName=NULL,
                                    const ZCHAR *pPassWord=NULL,
									EAsiBoolean fPrompt = kAsiFalse) ;

  
  EAsiBoolean            isIndexExist(ZcDbDatabase *pDwg=NULL);                                  
  EAsiBoolean            isIndexUpToDate(ZcDbDatabase *pDwg=WORKINGDWG());
    
  EAsiBoolean            createIndex(ZcDbDatabase *pDwg=WORKINGDWG());
  
  EAsiBoolean            removeIndex(ZcDbDatabase *pDwg=WORKINGDWG());

  
  int					 setIndexSaveMode (int mode);
  
  EAsiBoolean            openDwg(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            openLazyDwg(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            isDwgOpened(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            isDwgLazyOpened(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            closeDwg(ZcDbDatabase *pDwg=WORKINGDWG()) ;
    
  EAsiBoolean            swapEntIds(ZcDbObjectId objectId, 
                                    ZcDbObjectId otherId,
                                    ZcDbDatabase *pDwg=WORKINGDWG());
    
  EAsiBoolean            swapBTRIds(ZcDbObjectId blockId, 
                                    ZcDbObjectId otherId,
                                    ZcDbDatabase *pDwg=WORKINGDWG());
   
  EAsiBoolean            loadLinks(ZcDbEntity *pObj);
  EAsiBoolean            loadLinks(ZcDbObjectId objId);
  EAsiBoolean            translateDataSource(DatasourceTranslationCode xCode,
                                             unsigned int buflen,
                                             const ZCHAR * szFromEnv,
                                             const ZCHAR * szFromCat, 
                                             const ZCHAR * szFromSchema,
                                             const ZCHAR * szFromTable,
                                             const ZCHAR * szFromLpn,
                                             ZCHAR * szToEnv, 
                                             ZCHAR * szToCat, 
                                             ZCHAR * szToSchema,
                                             ZCHAR * szToTable,
                                             ZCHAR * szToLpn);

 
  EAsiBoolean           beginAseTransaction();
  EAsiBoolean           commitAseTransaction();
  EAsiBoolean           abortAseTransaction();
 
  typedef enum {
      kTransAutomatic = 0,      
      kTransUserManaged,        
  } ETransactionMode;

  void                  setAseTransactionMode( ETransactionMode eMode );
  ETransactionMode      getAseTransactionMode();

  protected:
  
   
  struct resbuf *        aseiCallAse(int funCode,
                                     struct resbuf* pParms,
                                     void *pErr,
                                     void *pZcDbDatabase=NULL,
                                     EAsiBoolean needFullOpen=kAsiFalse)  ;

  
  struct resbuf *        ase_invoke(int funCode,
                                    struct resbuf* pParms,
                                    void *pErr,
                                    void *pAse)  ;
  struct resbuf *        ase_fromAse(struct resbuf *pBuf) ;
  EAsiBoolean            ase_toAse(struct resbuf *pBuf) ;
  EAsiBoolean            addObj(const ZAseApiObj *pObj) ;
  EAsiBoolean            remObj(const ZAseApiObj *pObj) ;

  EAsiBoolean            mapErrFromAse(void *pAse, void *pErr);
  
  friend class ZAseApiObj ;
  friend class ZAseLinkPath ;
  friend class ZAseLink ;
  friend class ZAseLinkSel ;
  friend class ZAseApiErr ;
  TCHAR                  *mpVersion ;    
  void                  *mpRes ;        
  void                  *mpObjs ;      
  EAsiBoolean            mIsDiffChar ; 
                                       
  TCHAR                  *mpDefChar ;   
                                        
  ETransactionMode      meTransMode;    

} ;


class ZAseLinkPath : public ZAseApiObj
{
  public:
                         ZAseLinkPath(ZAseApiObj *pObj) ;
                         ZAseLinkPath(ZAseApiObj &Obj) ;
  virtual                ~ZAseLinkPath() ;
  virtual EAsiBoolean    init() ;
  virtual EAseApiClassId isA() const ;
  virtual ZAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const ZAseApiObj *pObj) ;
  virtual ZAseApiObj&    operator=(const ZAseApiObj &Obj) ;
  virtual int            operator==(const ZAseApiObj *pObj) const ;
  virtual int            operator==(const ZAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;

  EAsiBoolean            initPath(const ZCHAR *pPath) ;
  EAsiBoolean            initName(const ZCHAR *pName) ;
  EAsiBoolean            initCurrent() ;
  EAsiBoolean            reInit();
  EAsiBoolean            setName(const ZCHAR *pName,
                                 EAseDoNameCode NameCode=kAseLpnCode) ;
  EAsiBoolean            getName(ZCHAR *pBuf, int BufLen,
                                 EAseDoNameCode NameCode=kAseLpnCode) const ;
  int                    getNameSize(EAseDoNameCode NameCode=kAseLpnCode) const;
  int                    cmpName(const ZCHAR *pName, 
                                 EAseDoNameCode NameCode=kAseLpnCode) const ;
  int                    cmpName(const ZAseLinkPath *pLinkPath, 
                                 EAseDoNameCode NameCode=kAseLpnCode) const ;
  EAseDoNameCode         getPathCode() const;
  int                    getStatus() const;
  EAsiBoolean            isUpdatable() const ;
  EAsiBoolean            getKeyDsc(ZAsiRow **pKeyDsc) const;
  EAsiBoolean            getKeyDsc(ZAsiColumn **pKeyDsc[], int *pColQty) const;
  EAsiBoolean            create(const ZAsiRow *pKeyDsc) ;
  EAsiBoolean            create(const ZAsiRow &KeyDsc) ;
  EAsiBoolean            create(const ZAsiColumn *pKeyDsc[], int ColQty) ;
  EAsiBoolean            erase() ;
  EAsiBoolean            rename(const ZCHAR *pLinkPathName) ;
  EAsiBoolean            setCurrent() const ;
  struct resbuf         *getLinkNames() const ;
  struct resbuf         *getPaths(int Status) const ;
  
  EAsiBoolean            connectAse(const ZCHAR *pUsername=NULL,
                                    const ZCHAR *pPassword=NULL,
									EAsiBoolean fPrompt=kAsiFalse) ;

  EAsiBoolean            connectAseIniString (const ZCHAR *pIniString);

  EAsiBoolean            disconnectAse();  
  
  EAsiBoolean            checkOp(ulong status) const;  
  
  EAsiBoolean            getTableDsc(ZAsiRow **pColumns) const;  
  EAsiBoolean            getTableDsc(ZAsiColumn **pKeyDsc[], 
                                     int *pColQty) const;
  EAsiBoolean            createTable(const ZAsiRow *pCols);
  EAsiBoolean            createTable(const ZAsiColumn *pCols[],
                                     int colNum);
  EAsiBoolean            dropTable();
  
  EAsiBoolean            updRow(const ZAsiRow *pKey,
                                const ZAsiRow *pValue,
                                long *pRowsQty=NULL) const;
  EAsiBoolean            updRow(const ZAsiColumn *pKey[],
                                int numKeys,
                                const ZAsiColumn *pValue[],
                                int numValues,
                                long *pRowsQty=NULL) const;
  EAsiBoolean            delRow(const ZAsiRow *pValue,
                                long *pRowsQty=NULL) const;
  EAsiBoolean            delRow(const ZAsiColumn *pValue[],
                                int numKeys,
                                long *pRowsQty=NULL) const;
  EAsiBoolean            addRow(const ZAsiRow *pValue) const;
  EAsiBoolean            addRow(const ZAsiColumn *pValue[],
                                int numValues) const;
  
   
  EAsiBoolean            getRow(const ZAsiRow *pKeyValue,
                                ZAsiRow *pRowBuffer) const;  
                                
   
  EAsiBoolean            setDwg(const ZcDbDatabase *pDwg=WORKINGDWG()) ;
  
   
  const ZcDbDatabase*    getDwg() const ;

    
  EAsiBoolean            allocCursor(const ZAsiRow *pKeyDsc,
                                     const ZAsiRow *pRow,
                                     long *pCursorNum) const;
    
  EAsiBoolean            getCursorRow(long cursorNum,
                                      const ZAsiRow *pKeyValue,
                                      ZAsiRow *pRow) const;                           
  EAsiBoolean            delCursor(long cursorNum) const;

  protected:
  void                   *mpPath ;    
  void                   *mpDwg ;     
} ;

class ZAseLink : public ZAseApiObj
{
  public:
                         ZAseLink(ZAseApiObj *pObj) ;
                         ZAseLink(ZAseApiObj &Obj) ;
  virtual                ~ZAseLink() ;
  virtual EAsiBoolean    init() ;
  EAsiBoolean            initType(EAseLinkType lType) ;
  EAsiBoolean            initId(LinkID linkId) ;
  EAsiBoolean            initEnt(const ZCHAR *pName, 
                                 const ZAsiRow *pKeyValue, 
                                 zds_name EntName) ;
  EAsiBoolean            initEnt(const ZCHAR *pName, 
                                 const ZAsiRow &KeyValue, 
                                 zds_name EntName) ;
  EAsiBoolean            initEnt(const ZCHAR *pName, 
                                 const ZAsiColumn *pKeyValue[],
                                 int ColQty,
                                 zds_name EntName) ;
  EAsiBoolean            initDA(const ZCHAR *pName, 
                                const ZAsiRow *pKeyValue,
                                const ZAsiRow *pDACols,
                                const struct resbuf *pDAParms) ;
  EAsiBoolean            initDA(const ZCHAR *pName, 
                                const ZAsiRow &KeyValue,
                                const ZAsiRow &DACols,
                                const struct resbuf *pDAParms) ;
  EAsiBoolean            initDA(const ZCHAR *pName, 
                                const ZAsiColumn *pKeyValue[],
                                int ColQty,
                                const ZAsiColumn *pDACols[],
                                int DAColQty,
                                const struct resbuf *pDAParms) ;
  virtual EAseApiClassId isA() const ;
  virtual ZAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const ZAseApiObj *pObj) ;
  virtual ZAseApiObj&    operator=(const ZAseApiObj &Obj) ;
  virtual int            operator==(const ZAseApiObj *pObj) const ;
  virtual int            operator==(const ZAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;

  LinkID                 getId () const ;
  EAseLinkType           getType() const ;
  EAsiBoolean            getName(ZCHAR *pBuf, int len) const;
  int                    getNameSize() const ;
  EAsiBoolean            setName(const ZCHAR *pName) ;
  EAsiBoolean            getEntity(zds_name EntName) const ;
  EAsiBoolean            setEntity(zds_name EntName) ;
  EAsiBoolean            getKey(ZAsiRow *pKeyValue) const ;
  EAsiBoolean            getKey(ZAsiRow &KeyValue) const ;
  EAsiBoolean            getKey(ZAsiColumn *pKeyValue[], int ColQty) const ;
  EAsiBoolean            setKey(const ZAsiRow *pKeyValue) ;
  EAsiBoolean            setKey(const ZAsiRow &KeyValue) ;
  EAsiBoolean            setKey(const ZAsiColumn *pKeyValue[], int ColQty) ;
  EAsiBoolean            setDACols (const ZAsiRow *pCols) ;
  EAsiBoolean            setDACols (const ZAsiRow &Cols) ;
  EAsiBoolean            setDACols(ZAsiColumn *pCols[], int ColQty) ;
  EAsiBoolean            getDACols (ZAsiRow **pCols) const ;
  EAsiBoolean            getDACols(ZAsiColumn **pCols[], int *pColQty) const ;
  EAsiBoolean            setDAParms(const struct resbuf *pParms) ;
  EAsiBoolean            setDAValues(const ZAsiRow *pDAValues) ;
  EAsiBoolean            setDAValues(const ZAsiRow &DAValues) ;
  EAsiBoolean            setDAValues(ZAsiColumn *pCols[], int ColQty) ;
  EAsiBoolean            create () ;
  EAsiBoolean            remove () ;
  EAsiBoolean            update () ;
  EAsiBoolean            getXName(ZCHAR *pBuf, int len) const ;
  EAsiBoolean            isUpdatable() const ;

   
  EAsiBoolean            setDwg(const ZcDbDatabase *pDwg=WORKINGDWG()) ;
  
    
  const ZcDbDatabase*    getDwg() const ;
  
    
  struct resbuf         *getAttr(EAseLinkAttr LinkAttr) const ;
  EAsiBoolean            setAttr(EAseLinkAttr LinkAttr,
                                 const struct resbuf *pAttrValue) ;
  private:
  struct resbuf      *mpBuf ;    
  void               *mpDwg ;    
} ;

class ZAseLinkSel : public ZAseApiObj 
{
  public:
                         ZAseLinkSel(ZAseApiObj *pObj) ;
                         ZAseLinkSel(ZAseApiObj &Obj) ;
  virtual                ~ZAseLinkSel() ;
  virtual EAsiBoolean    init() ;
  EAsiBoolean            initType(EAseLinkType LinkType) ;
  EAsiBoolean            initSel(zds_name EntSelName,
                                 EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initEnt(zds_name EntName,
                                 EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initXName(const ZCHAR *pXName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLp(const ZCHAR *pName,
                                EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLp(const ZAseLinkPath *pLinkPath,
                                EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLp(const ZAseLinkPath &LinkPath,
                                EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpEnt(const ZCHAR *pName,
                                   zds_name EntName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpEnt(const ZAseLinkPath *pLinkPath,
                                   zds_name EntName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpEnt(const ZAseLinkPath &LinkPath,
                                   zds_name EntName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZCHAR *pName,
                                   const ZAsiRow *pKeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZCHAR *pName,
                                   const ZAsiRow &KeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZAseLinkPath *pLinkPath, 
                                   const ZAsiRow *pKeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZAseLinkPath &LinkPath, 
                                   const ZAsiRow &KeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZCHAR *pName,
                                   const ZAsiColumn *pKeyValue[],
                                   int ColQty,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZAseLinkPath *pLinkPath, 
                                   const ZAsiColumn *pKeyValue[],
                                   int ColQty,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpCond(const ZCHAR *pName,
                                    const ZCHAR *pTextCondition,
                                    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpCond(const ZAseLinkPath *pLinkPath, 
                                    const ZCHAR *pTextCondition,
                                    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpCond(const ZAseLinkPath &LinkPath, 
                                    const ZCHAR *pTextCondition,
                                    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpSel(const ZCHAR *pName,
                                   zds_name EntSelName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpSel(const ZAseLinkPath *pLinkPath, 
                                   zds_name EntSelName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpSel(const ZAseLinkPath &LinkPath, 
                                   zds_name EntSelName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initPartialKey(const ZCHAR *pName,
                                        const ZAsiRow *pKeyValue,
                                        EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initPartialKey(const ZAseLinkPath *pLinkPath, 
                                        const ZAsiRow *pKeyValue,
                                        EAseLinkType LinkType=kAseUnknownLinkType) ;

  virtual EAseApiClassId isA() const ;
  virtual ZAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const ZAseApiObj *pObj) ;
  virtual ZAseApiObj&    operator=(const ZAseApiObj &Obj) ;
  virtual int            operator==(const ZAseApiObj *pObj) const ;
  virtual int            operator==(const ZAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;
  EAsiBoolean            isUpdatable() const ;

  long                   getQty() const ;
  LinkID                 getId(long ItemNum) const ;
  EAsiBoolean            addId(LinkID linkId) ;
  EAsiBoolean            delId(long ItemNum) ;
  long                   membId(LinkID linkId) const ;
  
  EAsiBoolean            unite(const ZAseLinkSel *pSel) ;
  EAsiBoolean            unite(const ZAseLinkSel &Sel) ;
  EAsiBoolean            subtract(const ZAseLinkSel *pSel) ;
  EAsiBoolean            subtract(const ZAseLinkSel &Sel) ;
  EAsiBoolean            intersect(const ZAseLinkSel *pSel) ;
  EAsiBoolean            intersect(const ZAseLinkSel &Sel) ;

  EAsiBoolean            intersectType(EAseLinkType LinkType) ;
  EAsiBoolean            intersectEnt(zds_name EntName) ;
  EAsiBoolean            intersectSel(zds_name EntSelName) ;
  EAsiBoolean            intersectXName(const ZCHAR *pXName) ;
  EAsiBoolean            intersectLp(const ZCHAR *pName) ;
  EAsiBoolean            intersectLp(const ZAseLinkPath *pLinkPath) ;
  EAsiBoolean            intersectLp(const ZAseLinkPath &LinkPath) ;
  EAsiBoolean            intersectLpKey(const ZCHAR *pName,
                                        const ZAsiRow *pKeyValue) ;
  EAsiBoolean            intersectLpKey(const ZCHAR *pName,
                                        const ZAsiRow &KeyValue) ;
  EAsiBoolean            intersectLpKey(const ZAseLinkPath *pLinkPath, 
                                        const ZAsiRow *pKeyValue) ;
  EAsiBoolean            intersectLpKey(const ZAseLinkPath &LinkPath, 
                                        const ZAsiRow &KeyValue) ;
  EAsiBoolean            intersectLpKey(const ZCHAR *pName,
                                        const ZAsiColumn *pKeyValue[],
                                        int ColQty) ;
  EAsiBoolean            intersectLpKey(const ZAseLinkPath *pLinkPath, 
                                        const ZAsiColumn *pKeyValue[],
                                        int ColQty);
  EAsiBoolean            intersectLpCond(const ZCHAR *pName,
                                         const ZCHAR *pTextCondition) ;
  EAsiBoolean            intersectLpCond(const ZAseLinkPath *pLinkPath, 
                                         const ZCHAR *pTextCondition) ;
  EAsiBoolean            intersectLpCond(const ZAseLinkPath &LinkPath, 
                                         const ZCHAR *pTextCondition) ;

  EAsiBoolean            intersectPartialKey(const ZCHAR *pName,
                                             const ZAsiRow *pKeyValue) ;
  EAsiBoolean            intersectPartialKey(const ZAseLinkPath *pLinkPath, 
                                             const ZAsiRow *pKeyValue) ;
                                             
   
  EAsiBoolean            getLinkName(long ItemNum,
                                     TCHAR *pNameBuf,
                                     int nameBufLen) const;
                                     
   
  EAsiBoolean            getLinkKey(long ItemNum, ZAsiRow *pKeyValue);
  
   
  EAsiBoolean            getLinkEnt(long ItemNum, zds_name ename);                                   
  
    
  int                    getIdArray(ZcDbObjectIdArray *pLinkedEntities) const;
  
   
  EAsiBoolean            getLinkEnt(long ItemNum, ZcDbObjectId *pId);                                   
   
  EAsiBoolean            setDwg(const ZcDbDatabase *pDwg=WORKINGDWG()) ;
  
   
  const ZcDbDatabase*    getDwg() const ;

  struct resbuf         *getXNames() const ;
  struct resbuf         *getLinkNames() const ;
  EAsiBoolean            getEntSel(zds_name EntSelName) const ;
  EAsiBoolean            erase() ;

  
  virtual EAsiBoolean    initFilter(struct resbuf *pLinkFilter,
                                    EAsiBoolean needFullOpen=kAsiFalse) ;
  
  virtual EAsiBoolean    intersectFilter(const struct resbuf *pLinkFilter) ;

  protected:
  void                   freeSel() ;
  struct resbuf         *makeFilter(EAseLinkType LinkType,
                                    const ZCHAR *pXName,
                                    zds_name EntName,
                                    zds_name EntSelName,
                                    const ZCHAR *pName,
                                    const ZAseLinkPath *pLinkPath,
                                    const ZAsiRow *pKeyValue,
                                    const ZCHAR *pTextCondition,
                                    const ZAsiRow *pParKeyValue = NULL) ;

  LinkSelID              mSelId ;   
  void                   *mpDwg ;    
} ;

#endif 
#pragma pack (pop)
#endif

