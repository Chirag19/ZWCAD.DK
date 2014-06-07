

#ifndef _zcedzds_h
#define _zcedzds_h 1


#ifdef __cplusplus
    extern "C" {
#endif

#include "zdsdef.h"
#include "zcmem.h"
#include "ZdZChar.h"

#pragma pack (push, 8)


void           zcrx_abort (const ZCHAR * format, ...);
ZCHAR*         zcedGetAppName ();
int            zcedUpdate(int vport, zds_point p1, zds_point p2);

#if defined(_WINDEF_)

HWND           zdsw_zcadMainWnd();
#ifndef zdsw_hwndZcad
#define zdsw_hwndZcad zdsw_zcadMainWnd()
#endif


HWND           zdsw_zcadDocWnd();

typedef UINT (*UICOMMANDPROC)(LPVOID);
UINT		   zdsw_executeUICommand(UICOMMANDPROC pfnUICMDProc, LPVOID pParam);

#endif 

int            zcedCommand (int rtype, ...);
int            zcedCmd (const struct resbuf *rbp);

int            zcedRegFunc (int (*fhdl) (void), int fcode);

int            zcedUsrBrk (void);

int            zcedDefun (const ZCHAR *sname, short funcno);

int            zcedSetFunHelp (const ZCHAR* pszFunctionName, 
                               const ZCHAR* pszHelpfile,
                               const ZCHAR* pszTopic, int iCmd);

int            zcedUndef (const ZCHAR *sname, short funcno);

int            zcedGetFunCode (void);
struct resbuf *zcedGetArgs (void);

int            zcedRetList (const struct resbuf *rbuf);
int            zcedRetVal (const struct resbuf *rbuf);
int            zcedRetPoint (const zds_point pt);
int            zcedRetStr (const ZCHAR *s);
int            zcedRetName (const zds_name aname, int type);
int            zcedRetInt (int ival);
int            zcedRetReal (zds_real rval);
int            zcedRetT (void);
int            zcedRetNil (void);
int            zcedRetVoid (void);


int            zcedEntSel (const ZCHAR *str, zds_name entres,
                             zds_point ptres);
int            zcedNEntSel (const ZCHAR *str, zds_name entres,
                              zds_point ptres, zds_point xformres[4],
                              struct resbuf **refstkres);
int            zcedNEntSelP (const ZCHAR *str, zds_name entres,
                              zds_point ptres, int pickflag,
                              zds_matrix xformres,
                              struct resbuf **refstkres);
int            zcedSSGet (const ZCHAR *str, const void *pt1,
                            const void *pt2, const struct resbuf *filter,
                            zds_name ss);
int            zcedSSGetFirst (struct resbuf** gset, struct resbuf** pset);
int            zcedSSSetFirst (const zds_name pset, const zds_name unused);
int            zcedSSFree (const zds_name sname);
int            zcedSSLength (const zds_name sname, long *len);
int            zcedSSAdd (const zds_name ename, const zds_name sname,
                            zds_name result);
int            zcedSSDel (const zds_name ename, const zds_name ss);
int            zcedSSMemb (const zds_name ename, const zds_name ss);
int            zcedSSName (const zds_name ss, long i, zds_name entres);
int            zcedSSNameX (struct resbuf **rbpp, const zds_name ss,
                              const long i);
int            zcedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const ZCHAR*));
int            zcedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const ZCHAR*));
int            zcedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const ZCHAR*));
int            zcedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const ZCHAR*));

int            zcedTrans (const zds_point pt, const struct resbuf *from,
                            const struct resbuf *to, int disp,
                            zds_point result);

int            zcedSetVar (const ZCHAR *sym, const struct resbuf *val);
int            zcedInitGet (int val, const ZCHAR *kwl);

int            zcedGetSym (const ZCHAR *sname, struct resbuf **value);
int            zcedPutSym (const ZCHAR *sname, struct resbuf *value);

int            zcedHelp (const ZCHAR* szFilename, const ZCHAR* szTopic, int iCmd);
int            zcedFNSplit (const ZCHAR *pathToSplit, ZCHAR *prebuf,
                            ZCHAR *namebuf, ZCHAR *extbuf);

#define HELP_CONTENTS     0x0003L
#define HELP_HELPONHELP   0x0004L
#define HELP_PARTIALKEY   0x0105L

struct resbuf  *zcedZrxLoaded (void);
int            zcedZrxLoad (const ZCHAR *app);
int            zcedZrxUnload (const ZCHAR *app);

int            zcedInvoke (const struct resbuf *args,
                             struct resbuf **result);

int            zcedGetVar (const ZCHAR *sym, struct resbuf *result);
int            zcedFindFile (const ZCHAR *fname, ZCHAR *result);


int            zcedGetEnv (const ZCHAR *sym, ZCHAR  *var);
int            zcedSetEnv (const ZCHAR *sym, const ZCHAR *val);


int            zcedGetCfg (const ZCHAR *sym, ZCHAR  *var, int len);
int            zcedSetCfg (const ZCHAR *sym, const ZCHAR *val);


int            zcedGetString (int cronly, const ZCHAR *prompt, ZCHAR *result);
int            zcedGetStringB (int cronly, const ZCHAR *prompt,
                                    ZCHAR *result, int bufsize);


int            zcedMenuCmd (const ZCHAR *str);
int            zcedPrompt (const ZCHAR *str);
int            zcedAlert (const ZCHAR *str);


int            zcedGetAngle (const zds_point pt, const ZCHAR *prompt,
                               zds_real *result);
int            zcedGetCorner (const zds_point pt, const ZCHAR *prompt,
                                zds_point result);
int            zcedGetDist (const zds_point pt, const ZCHAR *prompt,
                              zds_real *result);
int            zcedGetOrient (const zds_point pt, const ZCHAR *prompt,
                                zds_real *result);
int            zcedGetPoint (const zds_point pt, const ZCHAR *prompt,
                               zds_point result);
int            zcedGetInt (const ZCHAR *prompt, int *result);
int            zcedGetKword (const ZCHAR *prompt, ZCHAR *result);
int            zcedGetReal (const ZCHAR *prompt, zds_real *result);
int            zcedGetInput (ZCHAR *str);
int            zcedVports (struct resbuf **vlist);


int            zcedTextScr (void);
int            zcedGraphScr (void);
int            zcedTextPage (void);


int            zcedRedraw (const zds_name ent, int mode);
int            zcedOsnap (const zds_point pt, const ZCHAR *mode,
                            zds_point result);
int            zcedGrRead (int track, int *type, struct resbuf *result);
int            zcedGrText (int box, const ZCHAR *text, int hl);
int            zcedGrDraw (const zds_point from, const zds_point to,
                             int color, int hl);
int            zcedGrVecs (const struct resbuf *vlist, zds_matrix mat);
int            zcedXformSS (const zds_name ssname,
                              zds_matrix genmat);
int            zcedDragGen (const zds_name ss, const ZCHAR *pmt, int cursor,
                              int (*scnf) (zds_point pt, zds_matrix mt),
                              zds_point p);
int            zcedSetView (const struct resbuf *view, int vport);


int            zcedGetFileD (const ZCHAR *title, const ZCHAR *defawlt,
                               const ZCHAR *ext, int flags,
                               struct resbuf *result);
int            zcedGetFileNavDialog (const ZCHAR *title, const ZCHAR *defawlt,
                             const ZCHAR *ext, const ZCHAR *dlgname, int flags,
                             struct resbuf **result);

int            zcedTextBox (const struct resbuf *args,
                              zds_point pt1, zds_point pt2);

int            zcedTablet  (const struct resbuf *args,
                              struct resbuf **result);


int            zcedGetCName (const ZCHAR *cmd, ZCHAR **result);


int           zcedEatCommandThroat(void);


int            zcdbEntDel (const zds_name ent);
struct resbuf *zcdbEntGetX (const zds_name ent, const struct resbuf *args);
struct resbuf *zcdbEntGet (const zds_name ent);
int            zcdbEntLast (zds_name result);
int            zcdbEntNext (const zds_name ent, zds_name result);
int            zcdbEntUpd (const zds_name ent);
int            zcdbEntMod (const struct resbuf *ent);
int            zcdbEntMake (const struct resbuf *ent);
int            zcdbEntMakeX (const struct resbuf *entm, zds_name result);
int            zcdbRegApp (const ZCHAR *appname);
struct resbuf *zcdbTblNext (const ZCHAR *tblname, int rewind);
struct resbuf *zcdbTblSearch (const ZCHAR *tblname, const ZCHAR *sym,
                              int setnext);
int            zcdbNamedObjDict (zds_name result);
struct resbuf *zcdbDictSearch (const zds_name dict, const ZCHAR* sym, 
                               int setnext);
struct resbuf *zcdbDictNext (const zds_name dict, int rewind);
int            zcdbDictRename (const zds_name dictname, const ZCHAR* oldsym,
                               const ZCHAR* newsym);
int            zcdbDictRemove (const zds_name dictname, const ZCHAR* symname);
int            zcdbDictAdd (const zds_name dictname, const ZCHAR* symname,
                            const zds_name newobj);

int            zcdbTblObjName (const ZCHAR *tblname, const ZCHAR *sym, 
                               zds_name result);

int            zcdbAngToS (zds_real v, int unit, int prec, ZCHAR *str);
int            zcdbRawAngToS (zds_real v, int unit, int prec, ZCHAR *str);
int            zcdbRToS (zds_real val, int unit, int prec, ZCHAR *str);
int            zcdbAngToF (const ZCHAR *str, int unit, zds_real *v);
int            zcdbRawAngToF (const ZCHAR *str, int unit, zds_real *v);
int            zcdbDisToF (const ZCHAR *str, int unit, zds_real *v);
int            zcdbInters (const zds_point from1, const zds_point to1,
                             const zds_point from2, const zds_point to2,
                             int teston, zds_point result);
int            zcdbSNValid (const ZCHAR *tbstr, int pipetest);
int			   zcedQueueExpr(ZCHAR* expr);

#pragma pack (pop)

#ifdef __cplusplus
    }
#endif

#pragma pack (push, 8)
#ifdef __cplusplus
extern "C++" {

int            zcedGetFullInput(ZCHAR *&pStr);
int            zcedGetFullKword(const ZCHAR * pString, ZCHAR *&pStr);
int            zcedGetFullString(int cronly, const ZCHAR *pString,
                                 ZCHAR *&pResult);
int            zcedSSNameXEx (struct resbuf **rbpp, const zds_name ss,
                              const long i, unsigned int flags = 0);
}

#endif

#pragma pack (pop)

#endif
