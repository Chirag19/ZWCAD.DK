

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Nov 23 21:21:26 2010
 */
/* Compiler settings for ..\..\ICAD\Property Bar\zxdb\zxdb.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __zxdb_h__
#define __zxdb_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IZcadDatabase_FWD_DEFINED__
#define __IZcadDatabase_FWD_DEFINED__
typedef interface IZcadDatabase IZcadDatabase;
#endif 	/* __IZcadDatabase_FWD_DEFINED__ */


#ifndef __IZcadZcCmColor_FWD_DEFINED__
#define __IZcadZcCmColor_FWD_DEFINED__
typedef interface IZcadZcCmColor IZcadZcCmColor;
#endif 	/* __IZcadZcCmColor_FWD_DEFINED__ */


#ifndef __IZcadHyperlinks_FWD_DEFINED__
#define __IZcadHyperlinks_FWD_DEFINED__
typedef interface IZcadHyperlinks IZcadHyperlinks;
#endif 	/* __IZcadHyperlinks_FWD_DEFINED__ */


#ifndef __IZcadObject_FWD_DEFINED__
#define __IZcadObject_FWD_DEFINED__
typedef interface IZcadObject IZcadObject;
#endif 	/* __IZcadObject_FWD_DEFINED__ */


#ifndef __IZcadDictionary_FWD_DEFINED__
#define __IZcadDictionary_FWD_DEFINED__
typedef interface IZcadDictionary IZcadDictionary;
#endif 	/* __IZcadDictionary_FWD_DEFINED__ */


#ifndef __IZcadEntity_FWD_DEFINED__
#define __IZcadEntity_FWD_DEFINED__
typedef interface IZcadEntity IZcadEntity;
#endif 	/* __IZcadEntity_FWD_DEFINED__ */


#ifndef __IZcadShadowDisplay_FWD_DEFINED__
#define __IZcadShadowDisplay_FWD_DEFINED__
typedef interface IZcadShadowDisplay IZcadShadowDisplay;
#endif 	/* __IZcadShadowDisplay_FWD_DEFINED__ */


#ifndef __IZcadObjectEvents_FWD_DEFINED__
#define __IZcadObjectEvents_FWD_DEFINED__
typedef interface IZcadObjectEvents IZcadObjectEvents;
#endif 	/* __IZcadObjectEvents_FWD_DEFINED__ */


#ifndef __ZcadEntity_FWD_DEFINED__
#define __ZcadEntity_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadEntity ZcadEntity;
#else
typedef struct ZcadEntity ZcadEntity;
#endif /* __cplusplus */

#endif 	/* __ZcadEntity_FWD_DEFINED__ */


#ifndef __ZcadObject_FWD_DEFINED__
#define __ZcadObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadObject ZcadObject;
#else
typedef struct ZcadObject ZcadObject;
#endif /* __cplusplus */

#endif 	/* __ZcadObject_FWD_DEFINED__ */


#ifndef __ZcadZcCmColor_FWD_DEFINED__
#define __ZcadZcCmColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadZcCmColor ZcadZcCmColor;
#else
typedef struct ZcadZcCmColor ZcadZcCmColor;
#endif /* __cplusplus */

#endif 	/* __ZcadZcCmColor_FWD_DEFINED__ */


#ifndef __ZcadHyperlinks_FWD_DEFINED__
#define __ZcadHyperlinks_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadHyperlinks ZcadHyperlinks;
#else
typedef struct ZcadHyperlinks ZcadHyperlinks;
#endif /* __cplusplus */

#endif 	/* __ZcadHyperlinks_FWD_DEFINED__ */


#ifndef __ZcadDictionary_FWD_DEFINED__
#define __ZcadDictionary_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadDictionary ZcadDictionary;
#else
typedef struct ZcadDictionary ZcadDictionary;
#endif /* __cplusplus */

#endif 	/* __ZcadDictionary_FWD_DEFINED__ */


#ifndef __ZcadDatabase_FWD_DEFINED__
#define __ZcadDatabase_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadDatabase ZcadDatabase;
#else
typedef struct ZcadDatabase ZcadDatabase;
#endif /* __cplusplus */

#endif 	/* __ZcadDatabase_FWD_DEFINED__ */


#ifndef __ZcadShadowDisplay_FWD_DEFINED__
#define __ZcadShadowDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadShadowDisplay ZcadShadowDisplay;
#else
typedef struct ZcadShadowDisplay ZcadShadowDisplay;
#endif /* __cplusplus */

#endif 	/* __ZcadShadowDisplay_FWD_DEFINED__ */


#ifndef __ZcadObjectEvents_FWD_DEFINED__
#define __ZcadObjectEvents_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadObjectEvents ZcadObjectEvents;
#else
typedef struct ZcadObjectEvents ZcadObjectEvents;
#endif /* __cplusplus */

#endif 	/* __ZcadObjectEvents_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_zxdb_0000_0000 */
/* [local] */ 

typedef /* [uuid] */  DECLSPEC_UUID("11E7CF1B-CF35-4b83-BE55-B918CEEA2FDB") double ZCAD_NOUNITS;

typedef /* [uuid] */  DECLSPEC_UUID("F1BB9985-C384-4ee4-AB7A-DA6D5F9B84A5") 
enum ZcColor
    {	acByBlock	= 0,
	acRed	= 1,
	acYellow	= 2,
	acGreen	= 3,
	acCyan	= 4,
	acBlue	= 5,
	acMagenta	= 6,
	acWhite	= 7,
	acByLayer	= 256
    } 	ZcColor;

typedef /* [uuid] */  DECLSPEC_UUID("1A4618BE-9600-42f2-90E6-93E8E1123297") ZcColor ZCAD_COLOR;

typedef /* [uuid] */  DECLSPEC_UUID("6BA4E2F2-F71E-427c-913E-9B64DB10D5FF") 
enum ZcExtendOption
    {	acExtendNone	= 0,
	acExtendThisEntity	= 1,
	acExtendOtherEntity	= 2,
	acExtendBoth	= 3
    } 	ZcExtendOption;

typedef /* [uuid] */  DECLSPEC_UUID("C95097C9-3CAE-49d0-9060-7543A1701F71") 
enum ZcShadowDisplayType
    {	acCastsAndReceivesShadows	= 0,
	acCastsShadows	= 1,
	acReceivesShadows	= 2,
	acIgnoreShadows	= 3
    } 	ZcShadowDisplayType;

typedef /* [uuid] */  DECLSPEC_UUID("401825B5-366C-4233-9810-6D9E66CAB707") 
enum ZcLineWeight
    {	acLnWt000	= 0,
	acLnWt005	= 5,
	acLnWt009	= 9,
	acLnWt013	= 13,
	acLnWt015	= 15,
	acLnWt018	= 18,
	acLnWt020	= 20,
	acLnWt025	= 25,
	acLnWt030	= 30,
	acLnWt035	= 35,
	acLnWt040	= 40,
	acLnWt050	= 50,
	acLnWt053	= 53,
	acLnWt060	= 60,
	acLnWt070	= 70,
	acLnWt080	= 80,
	acLnWt090	= 90,
	acLnWt100	= 100,
	acLnWt106	= 106,
	acLnWt120	= 120,
	acLnWt140	= 140,
	acLnWt158	= 158,
	acLnWt200	= 200,
	acLnWt211	= 211,
	acLnWtByLayer	= -1,
	acLnWtByBlock	= -2,
	acLnWtByLwDefault	= -3
    } 	ZcLineWeight;

typedef /* [uuid] */  DECLSPEC_UUID("26692645-4D39-4370-B0D4-6B43E865036D") ZcLineWeight ZCAD_LWEIGHT;



extern RPC_IF_HANDLE __MIDL_itf_zxdb_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zxdb_0000_0000_v0_0_s_ifspec;

#ifndef __IZcadDatabase_INTERFACE_DEFINED__
#define __IZcadDatabase_INTERFACE_DEFINED__

/* interface IZcadDatabase */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadDatabase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("89014B1B-F206-416F-8C3F-CFA400D3AEBF")
    IZcadDatabase : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IZcadDatabaseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadDatabase * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadDatabase * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadDatabase * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadDatabase * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadDatabase * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadDatabase * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadDatabase * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IZcadDatabaseVtbl;

    interface IZcadDatabase
    {
        CONST_VTBL struct IZcadDatabaseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadDatabase_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadDatabase_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadDatabase_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadDatabase_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZcadDatabase_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZcadDatabase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZcadDatabase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadDatabase_INTERFACE_DEFINED__ */


#ifndef __IZcadZcCmColor_INTERFACE_DEFINED__
#define __IZcadZcCmColor_INTERFACE_DEFINED__

/* interface IZcadZcCmColor */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadZcCmColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3C32217-CDB8-4F6F-B484-47829B996707")
    IZcadZcCmColor : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IZcadZcCmColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadZcCmColor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadZcCmColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadZcCmColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadZcCmColor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadZcCmColor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadZcCmColor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadZcCmColor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IZcadZcCmColorVtbl;

    interface IZcadZcCmColor
    {
        CONST_VTBL struct IZcadZcCmColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadZcCmColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadZcCmColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadZcCmColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadZcCmColor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZcadZcCmColor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZcadZcCmColor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZcadZcCmColor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadZcCmColor_INTERFACE_DEFINED__ */


#ifndef __IZcadHyperlinks_INTERFACE_DEFINED__
#define __IZcadHyperlinks_INTERFACE_DEFINED__

/* interface IZcadHyperlinks */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadHyperlinks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8988FE3-152A-4294-8BA2-70FD01FF7E64")
    IZcadHyperlinks : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IZcadHyperlinksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadHyperlinks * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadHyperlinks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadHyperlinks * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadHyperlinks * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadHyperlinks * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadHyperlinks * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadHyperlinks * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IZcadHyperlinksVtbl;

    interface IZcadHyperlinks
    {
        CONST_VTBL struct IZcadHyperlinksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadHyperlinks_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadHyperlinks_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadHyperlinks_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadHyperlinks_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZcadHyperlinks_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZcadHyperlinks_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZcadHyperlinks_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadHyperlinks_INTERFACE_DEFINED__ */


#ifndef __IZcadObject_INTERFACE_DEFINED__
#define __IZcadObject_INTERFACE_DEFINED__

/* interface IZcadObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("78610D22-7CEC-4E8D-9306-3F10FB2C76EC")
    IZcadObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ BSTR *Handle) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectName( 
            /* [retval][out] */ BSTR *ObjectName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXData( 
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXData( 
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectID( 
            /* [retval][out] */ LONG_PTR *ObjectId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ LPDISPATCH *ApplicationObject) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Database( 
            /* [retval][out] */ IZcadDatabase **pDatabase) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasExtensionDictionary( 
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetExtensionDictionary( 
            /* [retval][out] */ IZcadDictionary **pExtDictionary) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OwnerID( 
            /* [retval][out] */ LONG_PTR *OwnerId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Document( 
            /* [retval][out] */ LPDISPATCH *pDocument) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Erase( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IZcadObject * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IZcadObject * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IZcadObject * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IZcadObject * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IZcadObject * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IZcadObject * This,
            /* [retval][out] */ LONG_PTR *ObjectId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IZcadObject * This,
            /* [retval][out] */ LPDISPATCH *ApplicationObject);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IZcadObject * This,
            /* [retval][out] */ IZcadDatabase **pDatabase);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IZcadObject * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IZcadObject * This,
            /* [retval][out] */ IZcadDictionary **pExtDictionary);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IZcadObject * This,
            /* [retval][out] */ LONG_PTR *OwnerId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IZcadObject * This,
            /* [retval][out] */ LPDISPATCH *pDocument);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IZcadObject * This);
        
        END_INTERFACE
    } IZcadObjectVtbl;

    interface IZcadObject
    {
        CONST_VTBL struct IZcadObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZcadObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZcadObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZcadObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IZcadObject_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IZcadObject_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IZcadObject_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IZcadObject_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IZcadObject_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IZcadObject_get_ObjectID(This,ObjectId)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectId) ) 

#define IZcadObject_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IZcadObject_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IZcadObject_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IZcadObject_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IZcadObject_get_OwnerID(This,OwnerId)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerId) ) 

#define IZcadObject_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IZcadObject_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadObject_INTERFACE_DEFINED__ */


#ifndef __IZcadDictionary_INTERFACE_DEFINED__
#define __IZcadDictionary_INTERFACE_DEFINED__

/* interface IZcadDictionary */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadDictionary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DE878711-1302-4392-AF1F-2E2850E3720F")
    IZcadDictionary : public IZcadObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadDictionaryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadDictionary * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadDictionary * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadDictionary * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadDictionary * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadDictionary * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadDictionary * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadDictionary * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IZcadDictionary * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IZcadDictionary * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IZcadDictionary * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IZcadDictionary * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IZcadDictionary * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IZcadDictionary * This,
            /* [retval][out] */ LONG_PTR *ObjectId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IZcadDictionary * This,
            /* [retval][out] */ LPDISPATCH *ApplicationObject);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IZcadDictionary * This,
            /* [retval][out] */ IZcadDatabase **pDatabase);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IZcadDictionary * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IZcadDictionary * This,
            /* [retval][out] */ IZcadDictionary **pExtDictionary);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IZcadDictionary * This,
            /* [retval][out] */ LONG_PTR *OwnerId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IZcadDictionary * This,
            /* [retval][out] */ LPDISPATCH *pDocument);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IZcadDictionary * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IZcadDictionary * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IZcadDictionary * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IZcadDictionaryVtbl;

    interface IZcadDictionary
    {
        CONST_VTBL struct IZcadDictionaryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadDictionary_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadDictionary_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadDictionary_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadDictionary_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZcadDictionary_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZcadDictionary_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZcadDictionary_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IZcadDictionary_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IZcadDictionary_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IZcadDictionary_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IZcadDictionary_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IZcadDictionary_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IZcadDictionary_get_ObjectID(This,ObjectId)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectId) ) 

#define IZcadDictionary_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IZcadDictionary_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IZcadDictionary_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IZcadDictionary_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IZcadDictionary_get_OwnerID(This,OwnerId)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerId) ) 

#define IZcadDictionary_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IZcadDictionary_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IZcadDictionary_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IZcadDictionary_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadDictionary_INTERFACE_DEFINED__ */


#ifndef __IZcadEntity_INTERFACE_DEFINED__
#define __IZcadEntity_INTERFACE_DEFINED__

/* interface IZcadEntity */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadEntity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94DC013D-106F-46C6-A375-8A02A0A0CF06")
    IZcadEntity : public IZcadObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TrueColor( 
            /* [retval][out] */ IZcadZcCmColor **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TrueColor( 
            /* [in] */ IZcadZcCmColor *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Layer( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Layer( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Linetype( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Linetype( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LinetypeScale( 
            /* [retval][out] */ ZCAD_NOUNITS *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LinetypeScale( 
            /* [in] */ ZCAD_NOUNITS newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ArrayPolar( 
            int NumberOfObjects,
            double AngleToFill,
            VARIANT CenterPoint,
            /* [out] */ VARIANT *pArrayObjs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ArrayRectangular( 
            int NumberOfRows,
            int NumberOfColumns,
            int NumberOfLevels,
            double DistBetweenRows,
            double DistBetweenCols,
            double DistBetweenLevels,
            /* [out] */ VARIANT *pArrayObjs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Highlight( 
            VARIANT_BOOL HighlightFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ LPDISPATCH *pCopyObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            VARIANT FromPoint,
            VARIANT ToPoint) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate( 
            VARIANT BasePoint,
            double RotationAngle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate3D( 
            VARIANT Point1,
            VARIANT Point2,
            double RotationAngle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mirror( 
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ LPDISPATCH *pMirrorObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mirror3D( 
            /* [in] */ VARIANT point1,
            /* [in] */ VARIANT point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ LPDISPATCH *pMirrorObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ScaleEntity( 
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransformBy( 
            /* [in] */ VARIANT TransformationMatrix) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBoundingBox( 
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IntersectWith( 
            /* [in] */ LPDISPATCH IntersectObject,
            /* [in] */ ZcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlotStyleName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PlotStyleName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Lineweight( 
            /* [retval][out] */ ZCAD_LWEIGHT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Lineweight( 
            /* [in] */ ZCAD_LWEIGHT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hyperlinks( 
            /* [retval][out] */ IZcadHyperlinks **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Material( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Material( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EntityName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EntityType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ ZCAD_COLOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Color( 
            /* [in] */ ZCAD_COLOR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadEntityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadEntity * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadEntity * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadEntity * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadEntity * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadEntity * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadEntity * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IZcadEntity * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IZcadEntity * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IZcadEntity * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IZcadEntity * This,
            /* [retval][out] */ LONG_PTR *ObjectId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IZcadEntity * This,
            /* [retval][out] */ LPDISPATCH *ApplicationObject);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IZcadEntity * This,
            /* [retval][out] */ IZcadDatabase **pDatabase);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IZcadEntity * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IZcadEntity * This,
            /* [retval][out] */ IZcadDictionary **pExtDictionary);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IZcadEntity * This,
            /* [retval][out] */ LONG_PTR *OwnerId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IZcadEntity * This,
            /* [retval][out] */ LPDISPATCH *pDocument);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IZcadEntity * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IZcadEntity * This,
            /* [retval][out] */ IZcadZcCmColor **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IZcadEntity * This,
            /* [in] */ IZcadZcCmColor *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IZcadEntity * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IZcadEntity * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IZcadEntity * This,
            /* [retval][out] */ ZCAD_NOUNITS *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IZcadEntity * This,
            /* [in] */ ZCAD_NOUNITS newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IZcadEntity * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IZcadEntity * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IZcadEntity * This,
            int NumberOfObjects,
            double AngleToFill,
            VARIANT CenterPoint,
            /* [out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IZcadEntity * This,
            int NumberOfRows,
            int NumberOfColumns,
            int NumberOfLevels,
            double DistBetweenRows,
            double DistBetweenCols,
            double DistBetweenLevels,
            /* [out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IZcadEntity * This,
            VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IZcadEntity * This,
            /* [out] */ LPDISPATCH *pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IZcadEntity * This,
            VARIANT FromPoint,
            VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IZcadEntity * This,
            VARIANT BasePoint,
            double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IZcadEntity * This,
            VARIANT Point1,
            VARIANT Point2,
            double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IZcadEntity * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ LPDISPATCH *pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IZcadEntity * This,
            /* [in] */ VARIANT point1,
            /* [in] */ VARIANT point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ LPDISPATCH *pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IZcadEntity * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IZcadEntity * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IZcadEntity * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IZcadEntity * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IZcadEntity * This,
            /* [in] */ LPDISPATCH IntersectObject,
            /* [in] */ ZcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IZcadEntity * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IZcadEntity * This,
            /* [retval][out] */ ZCAD_LWEIGHT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IZcadEntity * This,
            /* [in] */ ZCAD_LWEIGHT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IZcadEntity * This,
            /* [retval][out] */ IZcadHyperlinks **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IZcadEntity * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IZcadEntity * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IZcadEntity * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IZcadEntity * This,
            /* [retval][out] */ ZCAD_COLOR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IZcadEntity * This,
            /* [in] */ ZCAD_COLOR newVal);
        
        END_INTERFACE
    } IZcadEntityVtbl;

    interface IZcadEntity
    {
        CONST_VTBL struct IZcadEntityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadEntity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadEntity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadEntity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadEntity_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IZcadEntity_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IZcadEntity_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IZcadEntity_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IZcadEntity_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IZcadEntity_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IZcadEntity_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IZcadEntity_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IZcadEntity_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IZcadEntity_get_ObjectID(This,ObjectId)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectId) ) 

#define IZcadEntity_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IZcadEntity_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IZcadEntity_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IZcadEntity_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IZcadEntity_get_OwnerID(This,OwnerId)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerId) ) 

#define IZcadEntity_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IZcadEntity_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IZcadEntity_get_TrueColor(This,pVal)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pVal) ) 

#define IZcadEntity_put_TrueColor(This,newVal)	\
    ( (This)->lpVtbl -> put_TrueColor(This,newVal) ) 

#define IZcadEntity_get_Layer(This,pVal)	\
    ( (This)->lpVtbl -> get_Layer(This,pVal) ) 

#define IZcadEntity_put_Layer(This,newVal)	\
    ( (This)->lpVtbl -> put_Layer(This,newVal) ) 

#define IZcadEntity_get_Linetype(This,pVal)	\
    ( (This)->lpVtbl -> get_Linetype(This,pVal) ) 

#define IZcadEntity_put_Linetype(This,newVal)	\
    ( (This)->lpVtbl -> put_Linetype(This,newVal) ) 

#define IZcadEntity_get_LinetypeScale(This,pVal)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,pVal) ) 

#define IZcadEntity_put_LinetypeScale(This,newVal)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,newVal) ) 

#define IZcadEntity_get_Visible(This,pVal)	\
    ( (This)->lpVtbl -> get_Visible(This,pVal) ) 

#define IZcadEntity_put_Visible(This,newVal)	\
    ( (This)->lpVtbl -> put_Visible(This,newVal) ) 

#define IZcadEntity_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IZcadEntity_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IZcadEntity_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IZcadEntity_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IZcadEntity_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IZcadEntity_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IZcadEntity_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IZcadEntity_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IZcadEntity_Mirror3D(This,point1,point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,point1,point2,point3,pMirrorObj) ) 

#define IZcadEntity_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IZcadEntity_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IZcadEntity_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IZcadEntity_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IZcadEntity_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IZcadEntity_get_PlotStyleName(This,pVal)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,pVal) ) 

#define IZcadEntity_put_PlotStyleName(This,newVal)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,newVal) ) 

#define IZcadEntity_get_Lineweight(This,pVal)	\
    ( (This)->lpVtbl -> get_Lineweight(This,pVal) ) 

#define IZcadEntity_put_Lineweight(This,newVal)	\
    ( (This)->lpVtbl -> put_Lineweight(This,newVal) ) 

#define IZcadEntity_get_Hyperlinks(This,pVal)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,pVal) ) 

#define IZcadEntity_get_Material(This,pVal)	\
    ( (This)->lpVtbl -> get_Material(This,pVal) ) 

#define IZcadEntity_put_Material(This,newVal)	\
    ( (This)->lpVtbl -> put_Material(This,newVal) ) 

#define IZcadEntity_get_EntityName(This,pVal)	\
    ( (This)->lpVtbl -> get_EntityName(This,pVal) ) 

#define IZcadEntity_get_EntityType(This,pVal)	\
    ( (This)->lpVtbl -> get_EntityType(This,pVal) ) 

#define IZcadEntity_get_Color(This,pVal)	\
    ( (This)->lpVtbl -> get_Color(This,pVal) ) 

#define IZcadEntity_put_Color(This,newVal)	\
    ( (This)->lpVtbl -> put_Color(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadEntity_INTERFACE_DEFINED__ */


#ifndef __IZcadShadowDisplay_INTERFACE_DEFINED__
#define __IZcadShadowDisplay_INTERFACE_DEFINED__

/* interface IZcadShadowDisplay */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IZcadShadowDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A8BFE4BA-618C-4E5C-AA1C-453FA963F630")
    IZcadShadowDisplay : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IZcadShadowDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadShadowDisplay * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadShadowDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadShadowDisplay * This);
        
        END_INTERFACE
    } IZcadShadowDisplayVtbl;

    interface IZcadShadowDisplay
    {
        CONST_VTBL struct IZcadShadowDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadShadowDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadShadowDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadShadowDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadShadowDisplay_INTERFACE_DEFINED__ */


#ifndef __IZcadObjectEvents_INTERFACE_DEFINED__
#define __IZcadObjectEvents_INTERFACE_DEFINED__

/* interface IZcadObjectEvents */
/* [unique][helpstring][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IZcadObjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C867AC42-0BCF-40DC-96A6-4AAE73D5381D")
    IZcadObjectEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Modified( 
            /* [in] */ IZcadObject *pVAl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadObjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadObjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadObjectEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Modified )( 
            IZcadObjectEvents * This,
            /* [in] */ IZcadObject *pVAl);
        
        END_INTERFACE
    } IZcadObjectEventsVtbl;

    interface IZcadObjectEvents
    {
        CONST_VTBL struct IZcadObjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadObjectEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IZcadObjectEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IZcadObjectEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IZcadObjectEvents_Modified(This,pVAl)	\
    ( (This)->lpVtbl -> Modified(This,pVAl) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IZcadObjectEvents_INTERFACE_DEFINED__ */



#ifndef __zxdbLib_LIBRARY_DEFINED__
#define __zxdbLib_LIBRARY_DEFINED__

/* library zxdbLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_zxdbLib;

EXTERN_C const CLSID CLSID_ZcadEntity;

#ifdef __cplusplus

class DECLSPEC_UUID("D695998E-2274-4687-93DD-213DE2D95B37")
ZcadEntity;
#endif

EXTERN_C const CLSID CLSID_ZcadObject;

#ifdef __cplusplus

class DECLSPEC_UUID("AF7FB1FC-5ECD-4743-AB11-6F97F49ABB28")
ZcadObject;
#endif

EXTERN_C const CLSID CLSID_ZcadZcCmColor;

#ifdef __cplusplus

class DECLSPEC_UUID("813B1628-4C5C-4EBC-B6BF-ABECD91A99F4")
ZcadZcCmColor;
#endif

EXTERN_C const CLSID CLSID_ZcadHyperlinks;

#ifdef __cplusplus

class DECLSPEC_UUID("5E4EFD21-5066-46F2-B526-2707D1565B53")
ZcadHyperlinks;
#endif

EXTERN_C const CLSID CLSID_ZcadDictionary;

#ifdef __cplusplus

class DECLSPEC_UUID("6FE811FF-F9FF-4EDC-90A4-1776FC475D03")
ZcadDictionary;
#endif

EXTERN_C const CLSID CLSID_ZcadDatabase;

#ifdef __cplusplus

class DECLSPEC_UUID("8F34C6E4-8486-4471-987A-A88A8D0DE248")
ZcadDatabase;
#endif

EXTERN_C const CLSID CLSID_ZcadShadowDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("C75B6CC5-A8C8-4844-BAEE-53E2CAE13CA2")
ZcadShadowDisplay;
#endif

EXTERN_C const CLSID CLSID_ZcadObjectEvents;

#ifdef __cplusplus

class DECLSPEC_UUID("10A4FD17-8AD8-4009-BE76-5B6F0D0061D2")
ZcadObjectEvents;
#endif
#endif /* __zxdbLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


