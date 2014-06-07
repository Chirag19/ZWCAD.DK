

#pragma warning( disable: 4049 )  



#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif 

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif 

#ifndef ___zcpi_h__
#define ___zcpi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif



#ifndef __IZcPiPropertyInspector_FWD_DEFINED__
#define __IZcPiPropertyInspector_FWD_DEFINED__
typedef interface IZcPiPropertyInspector IZcPiPropertyInspector;
#endif 	


#ifndef __IZcPiPropertyEditControl_FWD_DEFINED__
#define __IZcPiPropertyEditControl_FWD_DEFINED__
typedef interface IZcPiPropertyEditControl IZcPiPropertyEditControl;
#endif 	


#ifndef __IZcPiPropertyEditEventsSink_FWD_DEFINED__
#define __IZcPiPropertyEditEventsSink_FWD_DEFINED__
typedef interface IZcPiPropertyEditEventsSink IZcPiPropertyEditEventsSink;
#endif 	


#ifndef __IZcPiPropertyUnspecified_FWD_DEFINED__
#define __IZcPiPropertyUnspecified_FWD_DEFINED__
typedef interface IZcPiPropertyUnspecified IZcPiPropertyUnspecified;
#endif 


#ifndef __IZcPiPropertyDisplay_FWD_DEFINED__
#define __IZcPiPropertyDisplay_FWD_DEFINED__
typedef interface IZcPiPropertyDisplay IZcPiPropertyDisplay;
#endif 


#ifndef __IZcPiCategorizeProperties_FWD_DEFINED__
#define __IZcPiCategorizeProperties_FWD_DEFINED__
typedef interface IZcPiCategorizeProperties IZcPiCategorizeProperties;
#endif 	


#ifndef __IZcPiPropCommandButtons_FWD_DEFINED__
#define __IZcPiPropCommandButtons_FWD_DEFINED__
typedef interface IZcPiPropCommandButtons IZcPiPropCommandButtons;
#endif 


#ifndef __IZcPiCommandButton_FWD_DEFINED__
#define __IZcPiCommandButton_FWD_DEFINED__
typedef interface IZcPiCommandButton IZcPiCommandButton;
#endif 	


#ifndef __IZcPiCommandButton2_FWD_DEFINED__
#define __IZcPiCommandButton2_FWD_DEFINED__
typedef interface IZcPiCommandButton2 IZcPiCommandButton2;
#endif 


#ifndef __IZcPiPropertyInspectorEventsSink_FWD_DEFINED__
#define __IZcPiPropertyInspectorEventsSink_FWD_DEFINED__
typedef interface IZcPiPropertyInspectorEventsSink IZcPiPropertyInspectorEventsSink;
#endif 	


#ifndef __IZcPiPropertyInspectorInputEventSink_FWD_DEFINED__
#define __IZcPiPropertyInspectorInputEventSink_FWD_DEFINED__
typedef interface IZcPiPropertyInspectorInputEventSink IZcPiPropertyInspectorInputEventSink;
#endif 


#ifndef __ZcPiPropertyInspector_FWD_DEFINED__
#define __ZcPiPropertyInspector_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPiPropertyInspector ZcPiPropertyInspector;
#else
typedef struct ZcPiPropertyInspector ZcPiPropertyInspector;
#endif 

#endif 	



#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 



#define ZCPI_DEFAULT             0x00000000
#define ZCPI_CLEARCACHE_REFRESH  0x00000001
#define ZCPI_CLEARCACHE_DYNAMIC  0x00000002
#define ZCPI_CLEARCACHE_INCLUDED 0x00000004
#define ZCPI_ZCAD_DYN            0x00000008
#define ZCPI_UNION               0x00000010
#define ZCPI_SORTBYNAME          0x00000020
#define ZCPI_SORTBYWEIGHT        0x00000040
#define ZCPI_REFRESH             0x00000080
#define ZCPI_SETCONTROLFOCUS     0x00000001
#define ZCPI_SCROLLTOCONTROL     0x00000002
#define     ZC_TVS_TOOLTIPS             0x00000001
#define     ZC_TVS_GRIDLINES            0x00000002
#define     ZC_TVS_SELHIGHLIGHT         0x00000004
#define     ZC_TVS_GRIDMARKER           0x00000008
#define     ZC_TVS_GRIDROUNDSTYLE       0x00000010
#define     ZC_TVS_GRIDSTATUSBAR        0x00000020
#define     ZC_TVS_GRIDSCROLLRIGHT      0x00000040
#define     ZC_TVS_CALCULATOR           0x00000080

#define     ZC_TVS_GRID                 ((ZC_TVS_SELHIGHLIGHT) | (ZC_TVS_GRIDSTATUSBAR) | (ZC_TVS_GRIDLINES) | (ZC_TVS_TOOLTIPS) | (ZC_TVS_GRIDROUNDSTYLE))
#define DISPID_READONLYBACKCOLOR -2000
#define DISPID_READONLYFORECOLOR -2001
#define DISPID_RBUTTONDOWN -2030
#define DISPID_MBUTTONDOWN -2031
#define DISPID_CHECKED -2010
#define DISPID_BEGINPROPERTYUPDATE -2002
#define DISPID_ENDPROPERTYUPDATE -2003
typedef /* [uuid] */  DECLSPEC_UUID("A8562C86-3B34-4539-A880-1AB4089BCF10") 
enum ZAcPiColorIndex
    {	ACPI_COLOR_TOP	= 0,
	ACPI_COLOR_CATEGORY	= 0x1,
	ACPI_COLOR_ITEM	= 0x2,
	ACPI_COLOR_BORDER	= 0x3,
	ACPI_COLOR_BORDER_ITEM	= 0x4,
	ACPI_COLOR_TEXT_TOP	= 0x5,
	ACPI_COLOR_TEXT_CATEGORY	= 0x6,
	ACPI_COLOR_TEXT_ITEM	= 0x7,
	ACPI_COLOR_FORE_HIGHLIGHT	= 0x8,
	ACPI_COLOR_BACK_HIGHLIGHT	= 0x9,
	ACPI_COLOR_3DSHADOW	= 0xa,
	ACPI_COLOR_BACK_CONTROL	= 0xb,
	ACPI_COLOR_SCROLLBACKGROUND	= 0xc,
	ACPI_COLOR_SCROLLTHUMB	= 0xd,
	ACPI_COLOR_SCROLLARROW	= 0xe,
	ACPI_COLOR_DOUBLECHEVRON1	= 0xf,
	ACPI_COLOR_DOUBLECHEVRON2	= 0x10,
	ACPI_COLOR_SINGLECHEVRON	= 0x11
    } 	AcPiColorIndex;

#define IZPropertyInspector IZcPiPropertyInspector
#define IID_IZPropertyInspector IID_IZcPiPropertyInspector
#define CLSID_ZPropertyInspector CLSID_ZcPiPropertyInspector


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0000_v0_0_s_ifspec;

#ifndef __IZcPiPropertyInspector_INTERFACE_DEFINED__
#define __IZcPiPropertyInspector_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPiPropertyInspector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("22A2DE3F-1F1E-4F04-BD55-D0F1703281F9")
    IZcPiPropertyInspector : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( 
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Style( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Style( 
            /* [in] */ DWORD newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepFocus( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetColor( 
            /* [in] */ AcPiColorIndex index,
            /* [in] */ OLE_COLOR color) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetColor( 
            /* [in] */ AcPiColorIndex __MIDL_0011,
            /* [retval][out] */ OLE_COLOR *pColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IUnknown **pIFont) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IUnknown *pIFont) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BoldFont( 
            /* [retval][out] */ IUnknown **pIFont) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BoldFont( 
            /* [in] */ IUnknown *pIFont) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPersistence( 
            /* [in] */ IUnknown *pINode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPersistence( 
            /* [in] */ IUnknown *pINode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DelayRefresh( 
            /* [retval][out] */ VARIANT_BOOL *pbDelayRefresh) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DelayRefresh( 
            /* [in] */ VARIANT_BOOL bDelayRefresh) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyInspectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyInspector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyInspector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyInspector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcPiPropertyInspector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcPiPropertyInspector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcPiPropertyInspector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcPiPropertyInspector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IZcPiPropertyInspector * This,
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray,
            /* [in] */ DWORD dwFlags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Style )( 
            IZcPiPropertyInspector * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Style )( 
            IZcPiPropertyInspector * This,
            /* [in] */ DWORD newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )( 
            IZcPiPropertyInspector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetColor )( 
            IZcPiPropertyInspector * This,
            /* [in] */ AcPiColorIndex index,
            /* [in] */ OLE_COLOR color);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetColor )( 
            IZcPiPropertyInspector * This,
            /* [in] */ AcPiColorIndex __MIDL_0011,
            /* [retval][out] */ OLE_COLOR *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IZcPiPropertyInspector * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IZcPiPropertyInspector * This,
            /* [in] */ IUnknown *pIFont);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BoldFont )( 
            IZcPiPropertyInspector * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BoldFont )( 
            IZcPiPropertyInspector * This,
            /* [in] */ IUnknown *pIFont);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPersistence )( 
            IZcPiPropertyInspector * This,
            /* [in] */ IUnknown *pINode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPersistence )( 
            IZcPiPropertyInspector * This,
            /* [in] */ IUnknown *pINode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DelayRefresh )( 
            IZcPiPropertyInspector * This,
            /* [retval][out] */ VARIANT_BOOL *pbDelayRefresh);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DelayRefresh )( 
            IZcPiPropertyInspector * This,
            /* [in] */ VARIANT_BOOL bDelayRefresh);
        
        END_INTERFACE
    } IZcPiPropertyInspectorVtbl;

    interface IZcPiPropertyInspector
    {
        CONST_VTBL struct IZcPiPropertyInspectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyInspector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyInspector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyInspector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyInspector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZcPiPropertyInspector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZcPiPropertyInspector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZcPiPropertyInspector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZcPiPropertyInspector_Reset(This,pObjUnkArray,pDynUnkArray,dwFlags)	\
    (This)->lpVtbl -> Reset(This,pObjUnkArray,pDynUnkArray,dwFlags)

#define IZcPiPropertyInspector_get_Style(This,pVal)	\
    (This)->lpVtbl -> get_Style(This,pVal)

#define IZcPiPropertyInspector_put_Style(This,newVal)	\
    (This)->lpVtbl -> put_Style(This,newVal)

#define IZcPiPropertyInspector_get_KeepFocus(This,pVal)	\
    (This)->lpVtbl -> get_KeepFocus(This,pVal)

#define IZcPiPropertyInspector_SetColor(This,index,color)	\
    (This)->lpVtbl -> SetColor(This,index,color)

#define IZcPiPropertyInspector_GetColor(This,__MIDL_0011,pColor)	\
    (This)->lpVtbl -> GetColor(This,__MIDL_0011,pColor)

#define IZcPiPropertyInspector_get_Font(This,pIFont)	\
    (This)->lpVtbl -> get_Font(This,pIFont)

#define IZcPiPropertyInspector_put_Font(This,pIFont)	\
    (This)->lpVtbl -> put_Font(This,pIFont)

#define IZcPiPropertyInspector_get_BoldFont(This,pIFont)	\
    (This)->lpVtbl -> get_BoldFont(This,pIFont)

#define IZcPiPropertyInspector_put_BoldFont(This,pIFont)	\
    (This)->lpVtbl -> put_BoldFont(This,pIFont)

#define IZcPiPropertyInspector_SetPersistence(This,pINode)	\
    (This)->lpVtbl -> SetPersistence(This,pINode)

#define IZcPiPropertyInspector_GetPersistence(This,pINode)	\
    (This)->lpVtbl -> GetPersistence(This,pINode)

#define IZcPiPropertyInspector_get_DelayRefresh(This,pbDelayRefresh)	\
    (This)->lpVtbl -> get_DelayRefresh(This,pbDelayRefresh)

#define IZcPiPropertyInspector_put_DelayRefresh(This,bDelayRefresh)	\
    (This)->lpVtbl -> put_DelayRefresh(This,bDelayRefresh)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_Reset_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ VARIANT *pObjUnkArray,
    /* [in] */ VARIANT *pDynUnkArray,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IZcPiPropertyInspector_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_get_Style_Proxy( 
    IZcPiPropertyInspector * This,
    /* [retval][out] */ DWORD *pVal);


void __RPC_STUB IZcPiPropertyInspector_get_Style_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_put_Style_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ DWORD newVal);


void __RPC_STUB IZcPiPropertyInspector_put_Style_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_get_KeepFocus_Proxy( 
    IZcPiPropertyInspector * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IZcPiPropertyInspector_get_KeepFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_SetColor_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ AcPiColorIndex index,
    /* [in] */ OLE_COLOR color);


void __RPC_STUB IZcPiPropertyInspector_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_GetColor_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ AcPiColorIndex __MIDL_0011,
    /* [retval][out] */ OLE_COLOR *pColor);


void __RPC_STUB IZcPiPropertyInspector_GetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_get_Font_Proxy( 
    IZcPiPropertyInspector * This,
    /* [retval][out] */ IUnknown **pIFont);


void __RPC_STUB IZcPiPropertyInspector_get_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_put_Font_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ IUnknown *pIFont);


void __RPC_STUB IZcPiPropertyInspector_put_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_get_BoldFont_Proxy( 
    IZcPiPropertyInspector * This,
    /* [retval][out] */ IUnknown **pIFont);


void __RPC_STUB IZcPiPropertyInspector_get_BoldFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_put_BoldFont_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ IUnknown *pIFont);


void __RPC_STUB IZcPiPropertyInspector_put_BoldFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_SetPersistence_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ IUnknown *pINode);


void __RPC_STUB IZcPiPropertyInspector_SetPersistence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_GetPersistence_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ IUnknown *pINode);


void __RPC_STUB IZcPiPropertyInspector_GetPersistence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_get_DelayRefresh_Proxy( 
    IZcPiPropertyInspector * This,
    /* [retval][out] */ VARIANT_BOOL *pbDelayRefresh);


void __RPC_STUB IZcPiPropertyInspector_get_DelayRefresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspector_put_DelayRefresh_Proxy( 
    IZcPiPropertyInspector * This,
    /* [in] */ VARIANT_BOOL bDelayRefresh);


void __RPC_STUB IZcPiPropertyInspector_put_DelayRefresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	




#define IZPropertyEditControl IZcPiPropertyEditControl
#define IID_IZPropertyEditControl IID_IZcPiPropertyEditControl


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0262_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0262_v0_0_s_ifspec;

#ifndef __IZcPiPropertyEditControl_INTERFACE_DEFINED__
#define __IZcPiPropertyEditControl_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPiPropertyEditControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6371C569-72C0-43a0-A457-1E9D2EB9201E")
    IZcPiPropertyEditControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitEditControl( 
            /* [in] */ LPVARIANT pVarObjDispArray,
            /* [in] */ LPVARIANT pVarDynPropArray,
            /* [in] */ LPVARIANT pDispidArray,
            /* [in] */ VARIANT_BOOL bReadOnly) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepFocus( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnlyBackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnlyBackColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnlyForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnlyForeColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IUnknown *pIFont) = 0;
        
        virtual /* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IUnknown **pIFont) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyEditControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyEditControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyEditControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcPiPropertyEditControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitEditControl )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ LPVARIANT pVarObjDispArray,
            /* [in] */ LPVARIANT pVarDynPropArray,
            /* [in] */ LPVARIANT pDispidArray,
            /* [in] */ VARIANT_BOOL bReadOnly);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ DWORD dwFlags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )( 
            IZcPiPropertyEditControl * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [id][helpstring][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][helpstring][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IZcPiPropertyEditControl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][helpstring][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForeColor )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][helpstring][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForeColor )( 
            IZcPiPropertyEditControl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][helpstring][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnlyBackColor )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][helpstring][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnlyBackColor )( 
            IZcPiPropertyEditControl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][helpstring][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnlyForeColor )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][helpstring][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnlyForeColor )( 
            IZcPiPropertyEditControl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][helpstring][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IZcPiPropertyEditControl * This,
            /* [in] */ IUnknown *pIFont);
        
        /* [id][helpstring][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IZcPiPropertyEditControl * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        END_INTERFACE
    } IZcPiPropertyEditControlVtbl;

    interface IZcPiPropertyEditControl
    {
        CONST_VTBL struct IZcPiPropertyEditControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyEditControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyEditControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyEditControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyEditControl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZcPiPropertyEditControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZcPiPropertyEditControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZcPiPropertyEditControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZcPiPropertyEditControl_InitEditControl(This,pVarObjDispArray,pVarDynPropArray,pDispidArray,bReadOnly)	\
    (This)->lpVtbl -> InitEditControl(This,pVarObjDispArray,pVarDynPropArray,pDispidArray,bReadOnly)

#define IZcPiPropertyEditControl_Refresh(This,dwFlags)	\
    (This)->lpVtbl -> Refresh(This,dwFlags)

#define IZcPiPropertyEditControl_get_KeepFocus(This,pVal)	\
    (This)->lpVtbl -> get_KeepFocus(This,pVal)

#define IZcPiPropertyEditControl_put_BackColor(This,clr)	\
    (This)->lpVtbl -> put_BackColor(This,clr)

#define IZcPiPropertyEditControl_get_BackColor(This,pclr)	\
    (This)->lpVtbl -> get_BackColor(This,pclr)

#define IZcPiPropertyEditControl_put_ForeColor(This,clr)	\
    (This)->lpVtbl -> put_ForeColor(This,clr)

#define IZcPiPropertyEditControl_get_ForeColor(This,pclr)	\
    (This)->lpVtbl -> get_ForeColor(This,pclr)

#define IZcPiPropertyEditControl_put_ReadOnlyBackColor(This,clr)	\
    (This)->lpVtbl -> put_ReadOnlyBackColor(This,clr)

#define IZcPiPropertyEditControl_get_ReadOnlyBackColor(This,pclr)	\
    (This)->lpVtbl -> get_ReadOnlyBackColor(This,pclr)

#define IZcPiPropertyEditControl_put_ReadOnlyForeColor(This,clr)	\
    (This)->lpVtbl -> put_ReadOnlyForeColor(This,clr)

#define IZcPiPropertyEditControl_get_ReadOnlyForeColor(This,pclr)	\
    (This)->lpVtbl -> get_ReadOnlyForeColor(This,pclr)

#define IZcPiPropertyEditControl_put_Font(This,pIFont)	\
    (This)->lpVtbl -> put_Font(This,pIFont)

#define IZcPiPropertyEditControl_get_Font(This,pIFont)	\
    (This)->lpVtbl -> get_Font(This,pIFont)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_InitEditControl_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ LPVARIANT pVarObjDispArray,
    /* [in] */ LPVARIANT pVarDynPropArray,
    /* [in] */ LPVARIANT pDispidArray,
    /* [in] */ VARIANT_BOOL bReadOnly);


void __RPC_STUB IZcPiPropertyEditControl_InitEditControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_Refresh_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IZcPiPropertyEditControl_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_get_KeepFocus_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IZcPiPropertyEditControl_get_KeepFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_put_BackColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IZcPiPropertyEditControl_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_get_BackColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [retval][out] */ OLE_COLOR *pclr);


void __RPC_STUB IZcPiPropertyEditControl_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_put_ForeColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IZcPiPropertyEditControl_put_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_get_ForeColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [retval][out] */ OLE_COLOR *pclr);


void __RPC_STUB IZcPiPropertyEditControl_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_put_ReadOnlyBackColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IZcPiPropertyEditControl_put_ReadOnlyBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_get_ReadOnlyBackColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [retval][out] */ OLE_COLOR *pclr);


void __RPC_STUB IZcPiPropertyEditControl_get_ReadOnlyBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_put_ReadOnlyForeColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IZcPiPropertyEditControl_put_ReadOnlyForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_get_ReadOnlyForeColor_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [retval][out] */ OLE_COLOR *pclr);


void __RPC_STUB IZcPiPropertyEditControl_get_ReadOnlyForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_put_Font_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [in] */ IUnknown *pIFont);


void __RPC_STUB IZcPiPropertyEditControl_put_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][helpstring][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditControl_get_Font_Proxy( 
    IZcPiPropertyEditControl * This,
    /* [retval][out] */ IUnknown **pIFont);


void __RPC_STUB IZcPiPropertyEditControl_get_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	




#define IZPropEditUIEventsSink IZcPiPropertyEditEventsSink
#define IID_IZPropEditUIEventsSink IID_IZcPiPropertyEditEventsSink


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0263_v0_0_s_ifspec;

#ifndef __IZcPiPropertyEditEventsSink_INTERFACE_DEFINED__
#define __IZcPiPropertyEditEventsSink_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPiPropertyEditEventsSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B7332190-3EA0-4fff-9785-8E8E0D3F6B21")
    IZcPiPropertyEditEventsSink : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnClick( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnDblClick( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnKeyDown( 
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnKeyUp( 
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnRButtonDown( 
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnMButtonDown( 
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnBeginPropertyUpdate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEndPropertyUpdate( void) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyEditEventsSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyEditEventsSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyEditEventsSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyEditEventsSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            IZcPiPropertyEditEventsSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnDblClick )( 
            IZcPiPropertyEditEventsSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnKeyDown )( 
            IZcPiPropertyEditEventsSink * This,
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnKeyUp )( 
            IZcPiPropertyEditEventsSink * This,
            /* [in] */ LONG_PTR pnChar,
            /* [in] */ LONG_PTR keyData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnRButtonDown )( 
            IZcPiPropertyEditEventsSink * This,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnMButtonDown )( 
            IZcPiPropertyEditEventsSink * This,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnBeginPropertyUpdate )( 
            IZcPiPropertyEditEventsSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnEndPropertyUpdate )( 
            IZcPiPropertyEditEventsSink * This);
        
        END_INTERFACE
    } IZcPiPropertyEditEventsSinkVtbl;

    interface IZcPiPropertyEditEventsSink
    {
        CONST_VTBL struct IZcPiPropertyEditEventsSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyEditEventsSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyEditEventsSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyEditEventsSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyEditEventsSink_OnClick(This)	\
    (This)->lpVtbl -> OnClick(This)

#define IZcPiPropertyEditEventsSink_OnDblClick(This)	\
    (This)->lpVtbl -> OnDblClick(This)

#define IZcPiPropertyEditEventsSink_OnKeyDown(This,pnChar,keyData)	\
    (This)->lpVtbl -> OnKeyDown(This,pnChar,keyData)

#define IZcPiPropertyEditEventsSink_OnKeyUp(This,pnChar,keyData)	\
    (This)->lpVtbl -> OnKeyUp(This,pnChar,keyData)

#define IZcPiPropertyEditEventsSink_OnRButtonDown(This,wParam,lParam)	\
    (This)->lpVtbl -> OnRButtonDown(This,wParam,lParam)

#define IZcPiPropertyEditEventsSink_OnMButtonDown(This,wParam,lParam)	\
    (This)->lpVtbl -> OnMButtonDown(This,wParam,lParam)

#define IZcPiPropertyEditEventsSink_OnBeginPropertyUpdate(This)	\
    (This)->lpVtbl -> OnBeginPropertyUpdate(This)

#define IZcPiPropertyEditEventsSink_OnEndPropertyUpdate(This)	\
    (This)->lpVtbl -> OnEndPropertyUpdate(This)

#endif 


#endif 



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnClick_Proxy( 
    IZcPiPropertyEditEventsSink * This);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnDblClick_Proxy( 
    IZcPiPropertyEditEventsSink * This);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnDblClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnKeyDown_Proxy( 
    IZcPiPropertyEditEventsSink * This,
    /* [in] */ LONG_PTR pnChar,
    /* [in] */ LONG_PTR keyData);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnKeyDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnKeyUp_Proxy( 
    IZcPiPropertyEditEventsSink * This,
    /* [in] */ LONG_PTR pnChar,
    /* [in] */ LONG_PTR keyData);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnKeyUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnRButtonDown_Proxy( 
    IZcPiPropertyEditEventsSink * This,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnRButtonDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnMButtonDown_Proxy( 
    IZcPiPropertyEditEventsSink * This,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnMButtonDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnBeginPropertyUpdate_Proxy( 
    IZcPiPropertyEditEventsSink * This);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnBeginPropertyUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyEditEventsSink_OnEndPropertyUpdate_Proxy( 
    IZcPiPropertyEditEventsSink * This);


void __RPC_STUB IZcPiPropertyEditEventsSink_OnEndPropertyUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	




#define IZPropertyUnspecified  IZcPiPropertyUnspecified
#define IID_IZPropertyUnspecified IID_IZcPiPropertyUnspecified


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0264_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0264_v0_0_s_ifspec;

#ifndef __IZcPiPropertyUnspecified_INTERFACE_DEFINED__
#define __IZcPiPropertyUnspecified_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcPiPropertyUnspecified;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("63ECCF04-51B1-4fe1-972C-9EFD420ADEF4")
    IZcPiPropertyUnspecified : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValueUnspecified( 
            /* [in] */ VARIANT varId,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetUnspecified( 
            /* [in] */ VARIANT varId,
            /* [in] */ VARIANT_BOOL bIsUnspecified) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsUnspecifiedAllowed( 
            /* [in] */ VARIANT varId,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUnspecifiedString( 
            /* [in] */ VARIANT varId,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyUnspecifiedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyUnspecified * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyUnspecified * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyUnspecified * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsValueUnspecified )( 
            IZcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetUnspecified )( 
            IZcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [in] */ VARIANT_BOOL bIsUnspecified);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsUnspecifiedAllowed )( 
            IZcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUnspecifiedString )( 
            IZcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IZcPiPropertyUnspecifiedVtbl;

    interface IZcPiPropertyUnspecified
    {
        CONST_VTBL struct IZcPiPropertyUnspecifiedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyUnspecified_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyUnspecified_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyUnspecified_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyUnspecified_IsValueUnspecified(This,varId,pVal)	\
    (This)->lpVtbl -> IsValueUnspecified(This,varId,pVal)

#define IZcPiPropertyUnspecified_SetUnspecified(This,varId,bIsUnspecified)	\
    (This)->lpVtbl -> SetUnspecified(This,varId,bIsUnspecified)

#define IZcPiPropertyUnspecified_IsUnspecifiedAllowed(This,varId,pVal)	\
    (This)->lpVtbl -> IsUnspecifiedAllowed(This,varId,pVal)

#define IZcPiPropertyUnspecified_GetUnspecifiedString(This,varId,pVal)	\
    (This)->lpVtbl -> GetUnspecifiedString(This,varId,pVal)

#endif 


#endif 



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyUnspecified_IsValueUnspecified_Proxy( 
    IZcPiPropertyUnspecified * This,
    /* [in] */ VARIANT varId,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IZcPiPropertyUnspecified_IsValueUnspecified_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyUnspecified_SetUnspecified_Proxy( 
    IZcPiPropertyUnspecified * This,
    /* [in] */ VARIANT varId,
    /* [in] */ VARIANT_BOOL bIsUnspecified);


void __RPC_STUB IZcPiPropertyUnspecified_SetUnspecified_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyUnspecified_IsUnspecifiedAllowed_Proxy( 
    IZcPiPropertyUnspecified * This,
    /* [in] */ VARIANT varId,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IZcPiPropertyUnspecified_IsUnspecifiedAllowed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyUnspecified_GetUnspecifiedString_Proxy( 
    IZcPiPropertyUnspecified * This,
    /* [in] */ VARIANT varId,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcPiPropertyUnspecified_GetUnspecifiedString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	



#define IZPerPropertyDisplay IZcPiPropertyDisplay
#define IID_IZPerPropertyDisplay IID_IZcPiPropertyDisplay


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0265_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0265_v0_0_s_ifspec;

#ifndef __IZcPiPropertyDisplay_INTERFACE_DEFINED__
#define __IZcPiPropertyDisplay_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPiPropertyDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6a0d7861-8773-4d56-ac16-95aff3051ebd")
    IZcPiPropertyDisplay : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCustomPropertyCtrl( 
            /* [in] */ VARIANT Id,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR *pProgId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyIcon( 
            /* [in] */ VARIANT Id,
            /* [out] */ IUnknown **pIcon) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropTextColor( 
            /* [in] */ VARIANT Id,
            /* [out] */ OLE_COLOR *pTextColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsFullView( 
            /* [in] */ VARIANT Id,
            /* [out] */ VARIANT_BOOL *pbVisible,
            /* [out] */ DWORD *pIntegralHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyWeight( 
            /* [in] */ VARIANT Id,
            /* [out] */ long *pPropertyWeight) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyDisplay * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyDisplay * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCustomPropertyCtrl )( 
            IZcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR *pProgId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyIcon )( 
            IZcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ IUnknown **pIcon);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropTextColor )( 
            IZcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ OLE_COLOR *pTextColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsFullView )( 
            IZcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ VARIANT_BOOL *pbVisible,
            /* [out] */ DWORD *pIntegralHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyWeight )( 
            IZcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ long *pPropertyWeight);
        
        END_INTERFACE
    } IZcPiPropertyDisplayVtbl;

    interface IZcPiPropertyDisplay
    {
        CONST_VTBL struct IZcPiPropertyDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyDisplay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyDisplay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyDisplay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyDisplay_GetCustomPropertyCtrl(This,Id,lcid,pProgId)	\
    (This)->lpVtbl -> GetCustomPropertyCtrl(This,Id,lcid,pProgId)

#define IZcPiPropertyDisplay_GetPropertyIcon(This,Id,pIcon)	\
    (This)->lpVtbl -> GetPropertyIcon(This,Id,pIcon)

#define IZcPiPropertyDisplay_GetPropTextColor(This,Id,pTextColor)	\
    (This)->lpVtbl -> GetPropTextColor(This,Id,pTextColor)

#define IZcPiPropertyDisplay_IsFullView(This,Id,pbVisible,pIntegralHeight)	\
    (This)->lpVtbl -> IsFullView(This,Id,pbVisible,pIntegralHeight)

#define IZcPiPropertyDisplay_GetPropertyWeight(This,Id,pPropertyWeight)	\
    (This)->lpVtbl -> GetPropertyWeight(This,Id,pPropertyWeight)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyDisplay_GetCustomPropertyCtrl_Proxy( 
    IZcPiPropertyDisplay * This,
    /* [in] */ VARIANT Id,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR *pProgId);


void __RPC_STUB IZcPiPropertyDisplay_GetCustomPropertyCtrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyDisplay_GetPropertyIcon_Proxy( 
    IZcPiPropertyDisplay * This,
    /* [in] */ VARIANT Id,
    /* [out] */ IUnknown **pIcon);


void __RPC_STUB IZcPiPropertyDisplay_GetPropertyIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyDisplay_GetPropTextColor_Proxy( 
    IZcPiPropertyDisplay * This,
    /* [in] */ VARIANT Id,
    /* [out] */ OLE_COLOR *pTextColor);


void __RPC_STUB IZcPiPropertyDisplay_GetPropTextColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyDisplay_IsFullView_Proxy( 
    IZcPiPropertyDisplay * This,
    /* [in] */ VARIANT Id,
    /* [out] */ VARIANT_BOOL *pbVisible,
    /* [out] */ DWORD *pIntegralHeight);


void __RPC_STUB IZcPiPropertyDisplay_IsFullView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyDisplay_GetPropertyWeight_Proxy( 
    IZcPiPropertyDisplay * This,
    /* [in] */ VARIANT Id,
    /* [out] */ long *pPropertyWeight);


void __RPC_STUB IZcPiPropertyDisplay_GetPropertyWeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	




#define ICategorizeProperties2 IZcPiCategorizeProperties
#define IID_ICategorizeProperties2 IID_IZcPiCategorizeProperties


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0266_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0266_v0_0_s_ifspec;

#ifndef __IZcPiCategorizeProperties_INTERFACE_DEFINED__
#define __IZcPiCategorizeProperties_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcPiCategorizeProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8590b992-d9a1-48d1-899a-358d77e1512a")
    IZcPiCategorizeProperties : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MapPropertyToCategory( 
            /* [in] */ DISPID dispID,
            /* [out] */ int *pCatID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCategoryName( 
            /* [in] */ int CatID,
            /* [in] */ LCID lCid,
            /* [out] */ BSTR *pCategoryName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCategoryDescription( 
            /* [in] */ int CatID,
            /* [in] */ LCID lCid,
            /* [out] */ BSTR *pCategoryDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCategoryWeight( 
            /* [in] */ int CatID,
            /* [out] */ long *pCategoryWeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParentCategory( 
            /* [in] */ int CatID,
            /* [out] */ int *pParentCatID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUniqueID( 
            /* [out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCommandButtons( 
            /* [in] */ int CatID,
            /* [out] */ VARIANT *pCatCmdBtns) = 0;
        
    };
    
#else 	

    typedef struct IZcPiCategorizePropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiCategorizeProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiCategorizeProperties * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MapPropertyToCategory )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ DISPID dispID,
            /* [out] */ int *pCatID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCategoryName )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ int CatID,
            /* [in] */ LCID lCid,
            /* [out] */ BSTR *pCategoryName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCategoryDescription )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ int CatID,
            /* [in] */ LCID lCid,
            /* [out] */ BSTR *pCategoryDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCategoryWeight )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ int CatID,
            /* [out] */ long *pCategoryWeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParentCategory )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ int CatID,
            /* [out] */ int *pParentCatID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUniqueID )( 
            IZcPiCategorizeProperties * This,
            /* [out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCommandButtons )( 
            IZcPiCategorizeProperties * This,
            /* [in] */ int CatID,
            /* [out] */ VARIANT *pCatCmdBtns);
        
        END_INTERFACE
    } IZcPiCategorizePropertiesVtbl;

    interface IZcPiCategorizeProperties
    {
        CONST_VTBL struct IZcPiCategorizePropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiCategorizeProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiCategorizeProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiCategorizeProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiCategorizeProperties_MapPropertyToCategory(This,dispID,pCatID)	\
    (This)->lpVtbl -> MapPropertyToCategory(This,dispID,pCatID)

#define IZcPiCategorizeProperties_GetCategoryName(This,CatID,lCid,pCategoryName)	\
    (This)->lpVtbl -> GetCategoryName(This,CatID,lCid,pCategoryName)

#define IZcPiCategorizeProperties_GetCategoryDescription(This,CatID,lCid,pCategoryDescription)	\
    (This)->lpVtbl -> GetCategoryDescription(This,CatID,lCid,pCategoryDescription)

#define IZcPiCategorizeProperties_GetCategoryWeight(This,CatID,pCategoryWeight)	\
    (This)->lpVtbl -> GetCategoryWeight(This,CatID,pCategoryWeight)

#define IZcPiCategorizeProperties_GetParentCategory(This,CatID,pParentCatID)	\
    (This)->lpVtbl -> GetParentCategory(This,CatID,pParentCatID)

#define IZcPiCategorizeProperties_GetUniqueID(This,pVal)	\
    (This)->lpVtbl -> GetUniqueID(This,pVal)

#define IZcPiCategorizeProperties_GetCommandButtons(This,CatID,pCatCmdBtns)	\
    (This)->lpVtbl -> GetCommandButtons(This,CatID,pCatCmdBtns)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_MapPropertyToCategory_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [in] */ DISPID dispID,
    /* [out] */ int *pCatID);


void __RPC_STUB IZcPiCategorizeProperties_MapPropertyToCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_GetCategoryName_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [in] */ int CatID,
    /* [in] */ LCID lCid,
    /* [out] */ BSTR *pCategoryName);


void __RPC_STUB IZcPiCategorizeProperties_GetCategoryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_GetCategoryDescription_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [in] */ int CatID,
    /* [in] */ LCID lCid,
    /* [out] */ BSTR *pCategoryDescription);


void __RPC_STUB IZcPiCategorizeProperties_GetCategoryDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_GetCategoryWeight_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [in] */ int CatID,
    /* [out] */ long *pCategoryWeight);


void __RPC_STUB IZcPiCategorizeProperties_GetCategoryWeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_GetParentCategory_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [in] */ int CatID,
    /* [out] */ int *pParentCatID);


void __RPC_STUB IZcPiCategorizeProperties_GetParentCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_GetUniqueID_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [out] */ BSTR *pVal);


void __RPC_STUB IZcPiCategorizeProperties_GetUniqueID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCategorizeProperties_GetCommandButtons_Proxy( 
    IZcPiCategorizeProperties * This,
    /* [in] */ int CatID,
    /* [out] */ VARIANT *pCatCmdBtns);


void __RPC_STUB IZcPiCategorizeProperties_GetCommandButtons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 




#define IZPropCommandButtons IZcPiPropCommandButtons
#define IID_IZPropCommandButtons IID_IZcPiPropCommandButtons


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0267_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0267_v0_0_s_ifspec;

#ifndef __IZcPiPropCommandButtons_INTERFACE_DEFINED__
#define __IZcPiPropCommandButtons_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPiPropCommandButtons;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6CD83FA-32A5-4c1e-9F2E-487A612F4A77")
    IZcPiPropCommandButtons : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetButtons( 
            /* [retval][out] */ VARIANT *pButtons) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropCommandButtonsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropCommandButtons * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropCommandButtons * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropCommandButtons * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetButtons )( 
            IZcPiPropCommandButtons * This,
            /* [retval][out] */ VARIANT *pButtons);
        
        END_INTERFACE
    } IZcPiPropCommandButtonsVtbl;

    interface IZcPiPropCommandButtons
    {
        CONST_VTBL struct IZcPiPropCommandButtonsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropCommandButtons_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropCommandButtons_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropCommandButtons_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropCommandButtons_GetButtons(This,pButtons)	\
    (This)->lpVtbl -> GetButtons(This,pButtons)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropCommandButtons_GetButtons_Proxy( 
    IZcPiPropCommandButtons * This,
    /* [retval][out] */ VARIANT *pButtons);


void __RPC_STUB IZcPiPropCommandButtons_GetButtons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	



#define IZCommandButton IZcPiCommandButton
#define IID_IZCommandButton IID_IZcPiCommandButton


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0268_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0268_v0_0_s_ifspec;

#ifndef __IZcPiCommandButton_INTERFACE_DEFINED__
#define __IZcPiCommandButton_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcPiCommandButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A5EAB6FD-EB1A-43d5-BCE0-2DA8C40F21BA")
    IZcPiCommandButton : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnabledPicture( 
            /* [retval][out] */ IUnknown **pPicture) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisabledPicture( 
            /* [retval][out] */ IUnknown **pPicture) = 0;
        
        virtual /* [helpstring][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *bEnabled) = 0;
        
        virtual /* [helpstring][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE get_Checked( 
            /* [retval][out] */ VARIANT_BOOL *bChecked) = 0;
        
        virtual /* [helpstring][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE put_Checked( 
            /* [in] */ VARIANT_BOOL bChecked) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ButtonStyle( 
            /* [retval][out] */ long *style) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ VARIANT Objects) = 0;
        
    };
    
#else 	

    typedef struct IZcPiCommandButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiCommandButton * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiCommandButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiCommandButton * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IZcPiCommandButton * This,
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnabledPicture )( 
            IZcPiCommandButton * This,
            /* [retval][out] */ IUnknown **pPicture);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisabledPicture )( 
            IZcPiCommandButton * This,
            /* [retval][out] */ IUnknown **pPicture);
        
        /* [helpstring][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IZcPiCommandButton * This,
            /* [retval][out] */ VARIANT_BOOL *bEnabled);
        
        /* [helpstring][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IZcPiCommandButton * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][bindable][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Checked )( 
            IZcPiCommandButton * This,
            /* [retval][out] */ VARIANT_BOOL *bChecked);
        
        /* [helpstring][bindable][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Checked )( 
            IZcPiCommandButton * This,
            /* [in] */ VARIANT_BOOL bChecked);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ButtonStyle )( 
            IZcPiCommandButton * This,
            /* [retval][out] */ long *style);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IZcPiCommandButton * This,
            /* [in] */ VARIANT Objects);
        
        END_INTERFACE
    } IZcPiCommandButtonVtbl;

    interface IZcPiCommandButton
    {
        CONST_VTBL struct IZcPiCommandButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiCommandButton_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiCommandButton_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiCommandButton_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiCommandButton_GetName(This,lcid,name)	\
    (This)->lpVtbl -> GetName(This,lcid,name)

#define IZcPiCommandButton_get_EnabledPicture(This,pPicture)	\
    (This)->lpVtbl -> get_EnabledPicture(This,pPicture)

#define IZcPiCommandButton_get_DisabledPicture(This,pPicture)	\
    (This)->lpVtbl -> get_DisabledPicture(This,pPicture)

#define IZcPiCommandButton_get_Enabled(This,bEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,bEnabled)

#define IZcPiCommandButton_put_Enabled(This,bEnabled)	\
    (This)->lpVtbl -> put_Enabled(This,bEnabled)

#define IZcPiCommandButton_get_Checked(This,bChecked)	\
    (This)->lpVtbl -> get_Checked(This,bChecked)

#define IZcPiCommandButton_put_Checked(This,bChecked)	\
    (This)->lpVtbl -> put_Checked(This,bChecked)

#define IZcPiCommandButton_get_ButtonStyle(This,style)	\
    (This)->lpVtbl -> get_ButtonStyle(This,style)

#define IZcPiCommandButton_Execute(This,Objects)	\
    (This)->lpVtbl -> Execute(This,Objects)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_GetName_Proxy( 
    IZcPiCommandButton * This,
    /* [in] */ LCID lcid,
    /* [retval][out] */ BSTR *name);


void __RPC_STUB IZcPiCommandButton_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_get_EnabledPicture_Proxy( 
    IZcPiCommandButton * This,
    /* [retval][out] */ IUnknown **pPicture);


void __RPC_STUB IZcPiCommandButton_get_EnabledPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_get_DisabledPicture_Proxy( 
    IZcPiCommandButton * This,
    /* [retval][out] */ IUnknown **pPicture);


void __RPC_STUB IZcPiCommandButton_get_DisabledPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_get_Enabled_Proxy( 
    IZcPiCommandButton * This,
    /* [retval][out] */ VARIANT_BOOL *bEnabled);


void __RPC_STUB IZcPiCommandButton_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_put_Enabled_Proxy( 
    IZcPiCommandButton * This,
    /* [in] */ VARIANT_BOOL bEnabled);


void __RPC_STUB IZcPiCommandButton_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][bindable][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_get_Checked_Proxy( 
    IZcPiCommandButton * This,
    /* [retval][out] */ VARIANT_BOOL *bChecked);


void __RPC_STUB IZcPiCommandButton_get_Checked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][bindable][propput][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_put_Checked_Proxy( 
    IZcPiCommandButton * This,
    /* [in] */ VARIANT_BOOL bChecked);


void __RPC_STUB IZcPiCommandButton_put_Checked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_get_ButtonStyle_Proxy( 
    IZcPiCommandButton * This,
    /* [retval][out] */ long *style);


void __RPC_STUB IZcPiCommandButton_get_ButtonStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton_Execute_Proxy( 
    IZcPiCommandButton * This,
    /* [in] */ VARIANT Objects);


void __RPC_STUB IZcPiCommandButton_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 


#ifndef __IZcPiCommandButton2_INTERFACE_DEFINED__
#define __IZcPiCommandButton2_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPiCommandButton2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF4178BF-3E04-477e-80B3-33FC2DAE494E")
    IZcPiCommandButton2 : public IUnknown
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CheckedPicture( 
            /* [retval][out] */ IUnknown **pPicture) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UncheckedPicture( 
            /* [retval][out] */ IUnknown **pPicture) = 0;
        
    };
    
#else 	

    typedef struct IZcPiCommandButton2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiCommandButton2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiCommandButton2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiCommandButton2 * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CheckedPicture )( 
            IZcPiCommandButton2 * This,
            /* [retval][out] */ IUnknown **pPicture);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UncheckedPicture )( 
            IZcPiCommandButton2 * This,
            /* [retval][out] */ IUnknown **pPicture);
        
        END_INTERFACE
    } IZcPiCommandButton2Vtbl;

    interface IZcPiCommandButton2
    {
        CONST_VTBL struct IZcPiCommandButton2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiCommandButton2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiCommandButton2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiCommandButton2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiCommandButton2_get_CheckedPicture(This,pPicture)	\
    (This)->lpVtbl -> get_CheckedPicture(This,pPicture)

#define IZcPiCommandButton2_get_UncheckedPicture(This,pPicture)	\
    (This)->lpVtbl -> get_UncheckedPicture(This,pPicture)

#endif 


#endif 



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton2_get_CheckedPicture_Proxy( 
    IZcPiCommandButton2 * This,
    /* [retval][out] */ IUnknown **pPicture);


void __RPC_STUB IZcPiCommandButton2_get_CheckedPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IZcPiCommandButton2_get_UncheckedPicture_Proxy( 
    IZcPiCommandButton2 * This,
    /* [retval][out] */ IUnknown **pPicture);


void __RPC_STUB IZcPiCommandButton2_get_UncheckedPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	



#define IZPropertyInspectorSink IZcPiPropertyInspectorEventsSink
#define IID_IZPropertyInspectorSink IID_IZcPiPropertyInspectorEventsSink


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0270_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0270_v0_0_s_ifspec;

#ifndef __IZcPiPropertyInspectorEventsSink_INTERFACE_DEFINED__
#define __IZcPiPropertyInspectorEventsSink_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcPiPropertyInspectorEventsSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3EAF5E3F-5D7B-4873-B8F4-A6D9B2D1EB33")
    IZcPiPropertyInspectorEventsSink : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rebuild( 
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshControl( 
            /* [in] */ VARIANT var,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyControl( 
            /* [in] */ VARIANT var,
            /* [out] */ IUnknown **ppUnk) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyInspectorEventsSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyInspectorEventsSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyInspectorEventsSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyInspectorEventsSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rebuild )( 
            IZcPiPropertyInspectorEventsSink * This,
            /* [in] */ DWORD dwFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshControl )( 
            IZcPiPropertyInspectorEventsSink * This,
            /* [in] */ VARIANT var,
            /* [in] */ DWORD dwFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyControl )( 
            IZcPiPropertyInspectorEventsSink * This,
            /* [in] */ VARIANT var,
            /* [out] */ IUnknown **ppUnk);
        
        END_INTERFACE
    } IZcPiPropertyInspectorEventsSinkVtbl;

    interface IZcPiPropertyInspectorEventsSink
    {
        CONST_VTBL struct IZcPiPropertyInspectorEventsSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyInspectorEventsSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyInspectorEventsSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyInspectorEventsSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyInspectorEventsSink_Rebuild(This,dwFlags)	\
    (This)->lpVtbl -> Rebuild(This,dwFlags)

#define IZcPiPropertyInspectorEventsSink_RefreshControl(This,var,dwFlags)	\
    (This)->lpVtbl -> RefreshControl(This,var,dwFlags)

#define IZcPiPropertyInspectorEventsSink_GetPropertyControl(This,var,ppUnk)	\
    (This)->lpVtbl -> GetPropertyControl(This,var,ppUnk)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspectorEventsSink_Rebuild_Proxy( 
    IZcPiPropertyInspectorEventsSink * This,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IZcPiPropertyInspectorEventsSink_Rebuild_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspectorEventsSink_RefreshControl_Proxy( 
    IZcPiPropertyInspectorEventsSink * This,
    /* [in] */ VARIANT var,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IZcPiPropertyInspectorEventsSink_RefreshControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspectorEventsSink_GetPropertyControl_Proxy( 
    IZcPiPropertyInspectorEventsSink * This,
    /* [in] */ VARIANT var,
    /* [out] */ IUnknown **ppUnk);


void __RPC_STUB IZcPiPropertyInspectorEventsSink_GetPropertyControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 



#define IZPropertyInspectorInputEventSink IZcPiPropertyInspectorInputEventSink
#define IID_IZPropertyInspectorInputEventSink IID_IZcPiPropertyInspectorInputEventSink


extern RPC_IF_HANDLE __MIDL_itf_zcpi_0271_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zcpi_0271_v0_0_s_ifspec;

#ifndef __IZcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__
#define __IZcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcPiPropertyInspectorInputEventSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6E9DB08-8B45-4ad2-B33C-985BBE4F3756")
    IZcPiPropertyInspectorInputEventSink : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnKeyDown( 
            /* [in] */ long pnChar,
            /* [in] */ long keyData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPopulateContextMenu( 
            /* [in] */ VARIANT *flagArray,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *szItemArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnContextMenuCommand( 
            /* [in] */ int cmdId) = 0;
        
    };
    
#else 	

    typedef struct IZcPiPropertyInspectorInputEventSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyInspectorInputEventSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyInspectorInputEventSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyInspectorInputEventSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnKeyDown )( 
            IZcPiPropertyInspectorInputEventSink * This,
            /* [in] */ long pnChar,
            /* [in] */ long keyData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPopulateContextMenu )( 
            IZcPiPropertyInspectorInputEventSink * This,
            /* [in] */ VARIANT *flagArray,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *szItemArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnContextMenuCommand )( 
            IZcPiPropertyInspectorInputEventSink * This,
            /* [in] */ int cmdId);
        
        END_INTERFACE
    } IZcPiPropertyInspectorInputEventSinkVtbl;

    interface IZcPiPropertyInspectorInputEventSink
    {
        CONST_VTBL struct IZcPiPropertyInspectorInputEventSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPiPropertyInspectorInputEventSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPiPropertyInspectorInputEventSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPiPropertyInspectorInputEventSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPiPropertyInspectorInputEventSink_OnKeyDown(This,pnChar,keyData)	\
    (This)->lpVtbl -> OnKeyDown(This,pnChar,keyData)

#define IZcPiPropertyInspectorInputEventSink_OnPopulateContextMenu(This,flagArray,idArray,szItemArray)	\
    (This)->lpVtbl -> OnPopulateContextMenu(This,flagArray,idArray,szItemArray)

#define IZcPiPropertyInspectorInputEventSink_OnContextMenuCommand(This,cmdId)	\
    (This)->lpVtbl -> OnContextMenuCommand(This,cmdId)

#endif 


#endif



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspectorInputEventSink_OnKeyDown_Proxy( 
    IZcPiPropertyInspectorInputEventSink * This,
    /* [in] */ long pnChar,
    /* [in] */ long keyData);


void __RPC_STUB IZcPiPropertyInspectorInputEventSink_OnKeyDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspectorInputEventSink_OnPopulateContextMenu_Proxy( 
    IZcPiPropertyInspectorInputEventSink * This,
    /* [in] */ VARIANT *flagArray,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *szItemArray);


void __RPC_STUB IZcPiPropertyInspectorInputEventSink_OnPopulateContextMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPiPropertyInspectorInputEventSink_OnContextMenuCommand_Proxy( 
    IZcPiPropertyInspectorInputEventSink * This,
    /* [in] */ int cmdId);


void __RPC_STUB IZcPiPropertyInspectorInputEventSink_OnContextMenuCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	



#ifndef __ZCPILib_LIBRARY_DEFINED__
#define __ZCPILib_LIBRARY_DEFINED__



EXTERN_C const IID LIBID_ZCPILib;

EXTERN_C const CLSID CLSID_ZcPiPropertyInspector;

#ifdef __cplusplus

class DECLSPEC_UUID("31DBB451-9109-41EA-854C-B25905225AEA")
ZcPiPropertyInspector;
#endif
#endif


unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 


#ifdef __cplusplus
}
#endif

#endif
