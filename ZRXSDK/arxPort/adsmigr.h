
#ifndef _ARXPORT_AD_ADSMIGR_H_
#define _ARXPORT_AD_ADSMIGR_H_ 1
#include "..\inc\zdsmigr.h"
#define ads_malloc	zcad_malloc
#define ads_free	zcad_free
#define ads__msize	zcad__msize
#define ads_realloc zcad_realloc
#define ads_calloc	zcad_calloc
#define ads_strdup	zcad__strdup

// zced related #defines.
//
#define	ads_getappname	zcedGetAppName
#define	ads_update		zcedUpdate
#define	ads_command		zcedCommand
#define	ads_cmd	zcedCmd
#define	ads_regfunc		zcedRegFunc
#define	ads_usrbrk		zcedUsrBrk
#define	ads_defun		zcedDefun
#define	ads_setfunhelp	zcedSetFunHelp
#define	ads_undef		zcedUndef
#define	ads_getfuncode	zcedGetFunCode
#define	ads_getargs		zcedGetArgs
#define	ads_retlist		zcedRetList
#define	ads_retval		zcedRetVal
#define	ads_retpoint	zcedRetPoint
#define	ads_retstr		zcedRetStr
#define	ads_retname		zcedRetName
#define	ads_retint		zcedRetInt
#define	ads_retreal		zcedRetReal
#define	ads_rett		zcedRetT
#define	ads_retnil		zcedRetNil
#define	ads_retvoid		zcedRetVoid
#define	ads_entsel		zcedEntSel
#define	ads_nentsel		zcedNEntSel
#define	ads_nentselp	zcedNEntSelP
#define	ads_ssget		zcedSSGet

#define	ads_ssgetfirst	zcedSSGetFirst
#define	ads_sssetfirst	zcedSSSetFirst

#define	ads_ssfree		zcedSSFree
#define	ads_sslength	zcedSSLength
#define	ads_ssadd		zcedSSAdd
#define	ads_ssdel		zcedSSDel
#define	ads_ssmemb		zcedSSMemb
#define	ads_ssname		zcedSSName
#define	ads_ssnamex		zcedSSNameX
#define	ads_ssGetKwordCallbackPtr	zcedSSGetKwordCallbackPtr
#define	ads_ssSetKwordCallbackPtr	zcedSSSetKwordCallbackPtr
#define	ads_ssGetOtherCallbackPtr	zcedSSGetOtherCallbackPtr
#define	ads_ssSetOtherCallbackPtr	zcedSSSetOtherCallbackPtr
#define	ads_setvar		zcedSetVar
#define	ads_initget		zcedInitGet
#define	ads_getsym		zcedGetSym
#define	ads_putsym		zcedPutSym
#define	ads_help		zcedHelp
#define	ads_fnsplit		zcedFNSplit
#define	ads_trans		zcedTrans
#define	ads_arxloaded	zcedZrxLoaded
#define	ads_arxload		zcedZrxLoad
#define	ads_arxunload	zcedZrxUnload
#define	ads_invoke		zcedInvoke
#define	ads_getvar		zcedGetVar
#define	ads_findfile	zcedFindFile
#define	ads_agetenv		zcedGetEnv
#define	ads_asetenv		zcedSetEnv
#define	ads_getenv		zcedGetEnv
#define	ads_setenv		zcedSetEnv
#define	ads_agetcfg		zcedGetCfg
#define	ads_asetcfg		zcedSetCfg
#define	ads_getcfg		zcedGetCfg
#define	ads_setcfg		zcedSetCfg
#define	ads_getstring	zcedGetString
#define	ads_getstringb	zcedGetStringB
#define	ads_menucmd		zcedMenuCmd
#define	ads_prompt		zcedPrompt
#define	ads_alert		zcedAlert
#define	ads_getangle	zcedGetAngle
#define	ads_getcorner	zcedGetCorner
#define	ads_getdist		zcedGetDist
#define	ads_getorient	zcedGetOrient
#define	ads_getpoint	zcedGetPoint
#define	ads_getint		zcedGetInt
#define	ads_getkword	zcedGetKword
#define	ads_getreal		zcedGetReal
#define	ads_getinput	zcedGetInput
#define	ads_vports		zcedVports
#define	ads_textscr		zcedTextScr
#define	ads_graphscr	zcedGraphScr
#define	ads_textpage	zcedTextPage
#define	ads_redraw		zcedRedraw
#define	ads_osnap		zcedOsnap
#define	ads_grread		zcedGrRead
#define	ads_grtext		zcedGrText
#define	ads_grdraw		zcedGrDraw
#define	ads_grvecs		zcedGrVecs
#define	ads_xformss		zcedXformSS
#define	ads_draggen		zcedDragGen
#define	ads_setview		zcedSetView
#define	ads_getfiled	zcedGetFileD
#define	ads_textbox		zcedTextBox
#define	ads_tablet		zcedTablet
#define	ads_getcname	zcedGetCName

// ZcDb related #defines that are available to ObjectDBX
// applications.
#define	ads_xdroom	zcdbXdRoom
#define	ads_xdsize	zcdbXdSize

/* NOTE that the result is the SECOND argument,
   consistent with ZDS usage.  The standard C ones require <string.h> */
#ifdef __STDC__
#define ads_name_set(from, to)  (memcpy(to, from, sizeof(zds_name)))
#define ads_point_set(from,to)  (memcpy(to, from, sizeof(zds_point)))
#else
#define ads_name_set(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define ads_point_set(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif  /* !__STDC__ */

/* Define null value for ads_names.  These values are NOT guaranteed valid;
   that is, there is no zctual guarantee (such as C gives with NULL) that the
   system will never under any circumstances generate the values as valid data.
   The correct values will be created as part of the Lisp reinitialization
   project, if we go through with that one, and will then be inserted here.
   */
#define ads_name_clear(name)    name[0] = name[1] = 0
#define ads_name_nil(name)      (name[0] == 0 && name[1] == 0)
#define ads_name_equal(name1, name2)  (name1[0]==name2[0] \
                                       && name1[1]==name2[1])


// ZcDb related #defines that are not currently available
// to ObjectDBX applications.  7/14/98
#define	ads_entdel		zcdbEntDel
#define	ads_entgetx		zcdbEntGetX
#define	ads_entget		zcdbEntGet
#define	ads_entlast		zcdbEntLast
#define	ads_entnext		zcdbEntNext
#define	ads_entupd		zcdbEntUpd
#define	ads_entmod		zcdbEntMod
#define	ads_entmake		zcdbEntMake
#define	ads_entmakex	zcdbEntMakeX
#define	ads_tblnext		zcdbTblNext
#define	ads_tblsearch	zcdbTblSearch
#define	ads_namedobjdict	zcdbNamedObjDict
#define	ads_dictsearch	zcdbDictSearch
#define	ads_dictnext	zcdbDictNext
#define	ads_dictrename	zcdbDictRename
#define	ads_dictremove	zcdbDictRemove
#define	ads_dictadd		zcdbDictAdd
#define	ads_tblobjname	zcdbTblObjName
#define	ads_handent		zcdbHandEnt
#define	ads_inters		zcdbInters
#define	ads_snvalid		zcdbSNValid
#define	ads_xstrsave	zcdbXStrSave
#define	ads_xstrcase	zcdbXStrCase
#define	ads_regapp		zcdbRegApp
#define	ads_fail		zcdbFail
#define	ads_angtos		zcdbAngToS
#define	ads_rangtos		zcdbRawAngToS
#define	ads_rtos		zcdbRToS
#define	ads_angtof		zcdbAngToF
#define	ads_rangtof		zcdbRawAngToF
#define	ads_distof		zcdbDisToF
// Obsolete: we don't save as r12 anymore, so the xsave12 arg
// is ignored.
#define ads_regappx(appname, xsave12)   zcdbRegApp(appname)


// Functions that are now in acutil dll
#define	ads_printf		zcutPrintf
#define	ads_cvunit		zcutCvUnit
#define	ads_wcmatch		zcutWcMatch
#define	ads_angle		zcutAngle
#define	ads_distance	zcutDistance
#define	ads_polar		zcutPolar
#define	ads_isalpha		zcutIsAlpha
#define	ads_isupper		zcutIsUpper
#define	ads_islower		zcutIsLower
#define	ads_isdigit		zcutIsDigit
#define	ads_isxdigit	zcutIsXDigit
#define	ads_isspace		zcutIsSpace
#define	ads_ispunct		zcutIsPunct
#define	ads_isalnum		zcutIsAlNum
#define	ads_isprint		zcutIsPrint
#define	ads_isgraph		zcutIsGraph
#define	ads_iscntrl		zcutIsCntrl
#define	ads_toupper		zcutToUpper
#define	ads_tolower		zcutToLower
#define	ads_newrb		zcutNewRb
#define	ads_relrb		zcutRelRb
#define	ads_buildlist	zcutBuildList

#endif // !adsmigr_h
