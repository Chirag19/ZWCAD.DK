

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

#ifndef ___ZcPp_h__
#define ___ZcPp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif



#ifndef __IZcPpZcadInput_FWD_DEFINED__
#define __IZcPpZcadInput_FWD_DEFINED__
typedef interface IZcPpZcadInput IZcPpZcadInput;
#endif 	


#ifndef __IZcPpPalette_FWD_DEFINED__
#define __IZcPpPalette_FWD_DEFINED__
typedef interface IZcPpPalette IZcPpPalette;
#endif 


#ifndef __IZcPpPaletteEvents_FWD_DEFINED__
#define __IZcPpPaletteEvents_FWD_DEFINED__
typedef interface IZcPpPaletteEvents IZcPpPaletteEvents;
#endif 	


#ifndef __IZcPpPaletteSet_FWD_DEFINED__
#define __IZcPpPaletteSet_FWD_DEFINED__
typedef interface IZcPpPaletteSet IZcPpPaletteSet;
#endif 


#ifndef __IZcPpPaletteSetEvents_FWD_DEFINED__
#define __IZcPpPaletteSetEvents_FWD_DEFINED__
typedef interface IZcPpPaletteSetEvents IZcPpPaletteSetEvents;
#endif 


#ifndef __IZcPpNavTreeNode_FWD_DEFINED__
#define __IZcPpNavTreeNode_FWD_DEFINED__
typedef interface IZcPpNavTreeNode IZcPpNavTreeNode;
#endif 	


#ifndef __IZcPpNavTreeNodeCollectionIter_FWD_DEFINED__
#define __IZcPpNavTreeNodeCollectionIter_FWD_DEFINED__
typedef interface IZcPpNavTreeNodeCollectionIter IZcPpNavTreeNodeCollectionIter;
#endif 	


#ifndef __IZcPpNavTreeNodeCollection_FWD_DEFINED__
#define __IZcPpNavTreeNodeCollection_FWD_DEFINED__
typedef interface IZcPpNavTreeNodeCollection IZcPpNavTreeNodeCollection;
#endif 	


#ifndef __IZcPpNavTreeCmdBtn_FWD_DEFINED__
#define __IZcPpNavTreeCmdBtn_FWD_DEFINED__
typedef interface IZcPpNavTreeCmdBtn IZcPpNavTreeCmdBtn;
#endif 


#ifndef __IZcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__
#define __IZcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__
typedef interface IZcPpNavTreeCmdBtnCollectionIter IZcPpNavTreeCmdBtnCollectionIter;
#endif 	


#ifndef __IZcPpNavTreeCmdBtnCollection_FWD_DEFINED__
#define __IZcPpNavTreeCmdBtnCollection_FWD_DEFINED__
typedef interface IZcPpNavTreeCmdBtnCollection IZcPpNavTreeCmdBtnCollection;
#endif 	


#ifndef __IZcPpNavTree_FWD_DEFINED__
#define __IZcPpNavTree_FWD_DEFINED__
typedef interface IZcPpNavTree IZcPpNavTree;
#endif 	


#ifndef __IZcPpNavTreeEvents_FWD_DEFINED__
#define __IZcPpNavTreeEvents_FWD_DEFINED__
typedef interface IZcPpNavTreeEvents IZcPpNavTreeEvents;
#endif 


#ifndef __IZcPpPalette2_FWD_DEFINED__
#define __IZcPpPalette2_FWD_DEFINED__
typedef interface IZcPpPalette2 IZcPpPalette2;
#endif 	


#ifndef __ZcPpZcadInput_FWD_DEFINED__
#define __ZcPpZcadInput_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpZcadInput ZcPpZcadInput;
#else
typedef struct ZcPpZcadInput ZcPpZcadInput;
#endif 

#endif 	


#ifndef __ZcPpPaletteSet_FWD_DEFINED__
#define __ZcPpPaletteSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpPaletteSet ZcPpPaletteSet;
#else
typedef struct ZcPpPaletteSet ZcPpPaletteSet;
#endif 

#endif 


#ifndef __ZcPpPalette_FWD_DEFINED__
#define __ZcPpPalette_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpPalette ZcPpPalette;
#else
typedef struct ZcPpPalette ZcPpPalette;
#endif 

#endif 	


#ifndef __ZcPpPalette2_FWD_DEFINED__
#define __ZcPpPalette2_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpPalette2 ZcPpPalette2;
#else
typedef struct ZcPpPalette2 ZcPpPalette2;
#endif 

#endif 	


#ifndef __ZcPpNavTree_FWD_DEFINED__
#define __ZcPpNavTree_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpNavTree ZcPpNavTree;
#else
typedef struct ZcPpNavTree ZcPpNavTree;
#endif 

#endif 	


#ifndef __ZcPpNavTreeNode_FWD_DEFINED__
#define __ZcPpNavTreeNode_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpNavTreeNode ZcPpNavTreeNode;
#else
typedef struct ZcPpNavTreeNode ZcPpNavTreeNode;
#endif 

#endif 	



#include "oaidl.h"
#include "ocidl.h"
#include "zcpi.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 



#define ZCPPINPUT_ID_VALUE           1
#define ZCPPINPUT_ID_STATUS          2
#define ZCPPINPUT_ID_DOCUMENT        3
#define ZCPPINPUT_ID_CRONLY          4
#define ZCPPINPUT_ID_PROMPT          5
#define ZCPPINPUT_ID_PROMPT2         6
#define ZCPPINPUT_ID_INITGETBIT      7
#define ZCPPINPUT_ID_INITGETKWORD    8
#define ZCPPINPUT_ID_BASEPOINT       9
#define zCPPINPUT_ID_PROMPTTYPE      10
#define ZCPPINPUT_ID_ENABLENOTIFICATION 11


extern RPC_IF_HANDLE __MIDL_itf_ZcPp_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPp_0000_v0_0_s_ifspec;

#ifndef __IZcPpZcadInput_INTERFACE_DEFINED__
#define __IZcPpZcadInput_INTERFACE_DEFINED__



typedef 
enum StatusType
    {	StatusPrompting	= -1,
	StatusRTNORM	= 5100,
	StatusRTERROR	= -5001,
	StatusRTCAN	= -5002,
	StatusRTNONE	= 5000,
	StatusRTREJ	= -5003,
	StatusRTKWORD	= -5005,
	StatusMODELESS	= 5027
    } 	StatusType;

typedef  
enum PromptType
    {	GetAngle	= 1,
	GetCorner	= 2,
	GetDist	= 3,
	GetInt	= 4,
	GetKword	= 5,
	GetOrient	= 6,
	GetPoint	= 7,
	GetReal	= 8,
	GetString	= 9,
	EntSel	= 10
    } 	PromptType;


EXTERN_C const IID IID_IZcPpZcadInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07816A95-3C14-4236-B9D3-AA7F4A4A1EFB")
    IZcPpZcadInput : public IUnknown
    {
    public:
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_Status( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_Document( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_Document( 
            /* [in] */ IUnknown *newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_CrOnly( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_CrOnly( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_Prompt( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_Prompt( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_Prompt2( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_Prompt2( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_InitGetBit( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_InitGetBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_InitGetKword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_InitGetKword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_BasePoint( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_BasePoint( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_PromptType( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_PromptType( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableNotification( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableNotification( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DoPrompt( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelPrompt( void) = 0;
        
    };
    
#else 	

    typedef struct IZcPpZcadInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpZcadInput * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpZcadInput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpZcadInput * This);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IZcPpZcadInput * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Status )( 
            IZcPpZcadInput * This,
            /* [in] */ long newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Document )( 
            IZcPpZcadInput * This,
            /* [in] */ IUnknown *newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CrOnly )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CrOnly )( 
            IZcPpZcadInput * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Prompt )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Prompt )( 
            IZcPpZcadInput * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Prompt2 )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Prompt2 )( 
            IZcPpZcadInput * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InitGetBit )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InitGetBit )( 
            IZcPpZcadInput * This,
            /* [in] */ long newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InitGetKword )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InitGetKword )( 
            IZcPpZcadInput * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BasePoint )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BasePoint )( 
            IZcPpZcadInput * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PromptType )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PromptType )( 
            IZcPpZcadInput * This,
            /* [in] */ short newVal);
        
        /* [helpstring][requestedit][bindable][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableNotification )( 
            IZcPpZcadInput * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][requestedit][bindable][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableNotification )( 
            IZcPpZcadInput * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DoPrompt )( 
            IZcPpZcadInput * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelPrompt )( 
            IZcPpZcadInput * This);
        
        END_INTERFACE
    } IZcPpZcadInputVtbl;

    interface IZcPpZcadInput
    {
        CONST_VTBL struct IZcPpZcadInputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpZcadInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpZcadInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpZcadInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpZcadInput_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IZcPpZcadInput_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#define IZcPpZcadInput_get_Status(This,pVal)	\
    (This)->lpVtbl -> get_Status(This,pVal)

#define IZcPpZcadInput_put_Status(This,newVal)	\
    (This)->lpVtbl -> put_Status(This,newVal)

#define IZcPpZcadInput_get_Document(This,pVal)	\
    (This)->lpVtbl -> get_Document(This,pVal)

#define IZcPpZcadInput_put_Document(This,newVal)	\
    (This)->lpVtbl -> put_Document(This,newVal)

#define IZcPpZcadInput_get_CrOnly(This,pVal)	\
    (This)->lpVtbl -> get_CrOnly(This,pVal)

#define IZcPpZcadInput_put_CrOnly(This,newVal)	\
    (This)->lpVtbl -> put_CrOnly(This,newVal)

#define IZcPpZcadInput_get_Prompt(This,pVal)	\
    (This)->lpVtbl -> get_Prompt(This,pVal)

#define IZcPpZcadInput_put_Prompt(This,newVal)	\
    (This)->lpVtbl -> put_Prompt(This,newVal)

#define IZcPpZcadInput_get_Prompt2(This,pVal)	\
    (This)->lpVtbl -> get_Prompt2(This,pVal)

#define IZcPpZcadInput_put_Prompt2(This,newVal)	\
    (This)->lpVtbl -> put_Prompt2(This,newVal)

#define IZcPpZcadInput_get_InitGetBit(This,pVal)	\
    (This)->lpVtbl -> get_InitGetBit(This,pVal)

#define IZcPpZcadInput_put_InitGetBit(This,newVal)	\
    (This)->lpVtbl -> put_InitGetBit(This,newVal)

#define IZcPpZcadInput_get_InitGetKword(This,pVal)	\
    (This)->lpVtbl -> get_InitGetKword(This,pVal)

#define IZcPpZcadInput_put_InitGetKword(This,newVal)	\
    (This)->lpVtbl -> put_InitGetKword(This,newVal)

#define IZcPpZcadInput_get_BasePoint(This,pVal)	\
    (This)->lpVtbl -> get_BasePoint(This,pVal)

#define IZcPpZcadInput_put_BasePoint(This,newVal)	\
    (This)->lpVtbl -> put_BasePoint(This,newVal)

#define IZcPpZcadInput_get_PromptType(This,pVal)	\
    (This)->lpVtbl -> get_PromptType(This,pVal)

#define IZcPpZcadInput_put_PromptType(This,newVal)	\
    (This)->lpVtbl -> put_PromptType(This,newVal)

#define IZcPpZcadInput_get_EnableNotification(This,pVal)	\
    (This)->lpVtbl -> get_EnableNotification(This,pVal)

#define IZcPpZcadInput_put_EnableNotification(This,newVal)	\
    (This)->lpVtbl -> put_EnableNotification(This,newVal)

#define IZcPpZcadInput_DoPrompt(This)	\
    (This)->lpVtbl -> DoPrompt(This)

#define IZcPpZcadInput_CancelPrompt(This)	\
    (This)->lpVtbl -> CancelPrompt(This)

#endif 


#endif 	



/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_Value_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IZcPpZcadInput_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_Value_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IZcPpZcadInput_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_Status_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IZcPpZcadInput_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_Status_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ long newVal);


void __RPC_STUB IZcPpZcadInput_put_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_Document_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB IZcPpZcadInput_get_Document_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_Document_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ IUnknown *newVal);


void __RPC_STUB IZcPpZcadInput_put_Document_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_CrOnly_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IZcPpZcadInput_get_CrOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_CrOnly_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IZcPpZcadInput_put_CrOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_Prompt_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcPpZcadInput_get_Prompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_Prompt_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcPpZcadInput_put_Prompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_Prompt2_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcPpZcadInput_get_Prompt2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_Prompt2_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcPpZcadInput_put_Prompt2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_InitGetBit_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IZcPpZcadInput_get_InitGetBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_InitGetBit_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ long newVal);


void __RPC_STUB IZcPpZcadInput_put_InitGetBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_InitGetKword_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcPpZcadInput_get_InitGetKword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_InitGetKword_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcPpZcadInput_put_InitGetKword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_BasePoint_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IZcPpZcadInput_get_BasePoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_BasePoint_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IZcPpZcadInput_put_BasePoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_PromptType_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IZcPpZcadInput_get_PromptType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_PromptType_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ short newVal);


void __RPC_STUB IZcPpZcadInput_put_PromptType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_get_EnableNotification_Proxy( 
    IZcPpZcadInput * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IZcPpZcadInput_get_EnableNotification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][requestedit][bindable][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_put_EnableNotification_Proxy( 
    IZcPpZcadInput * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IZcPpZcadInput_put_EnableNotification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_DoPrompt_Proxy( 
    IZcPpZcadInput * This);


void __RPC_STUB IZcPpZcadInput_DoPrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpZcadInput_CancelPrompt_Proxy( 
    IZcPpZcadInput * This);


void __RPC_STUB IZcPpZcadInput_CancelPrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcPpPalette_INTERFACE_DEFINED__
#define __IZcPpPalette_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpPalette;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A20A927F-5508-4624-9157-FD5CBE5B2D64")
    IZcPpPalette : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InspectorControl( 
            /* [retval][out] */ IZcPiPropertyInspector **pInspector) = 0;
        
    };
    
#else 	

    typedef struct IZcPpPaletteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpPalette * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpPalette * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpPalette * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IZcPpPalette * This,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IZcPpPalette * This,
            /* [in] */ BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InspectorControl )( 
            IZcPpPalette * This,
            /* [retval][out] */ IZcPiPropertyInspector **pInspector);
        
        END_INTERFACE
    } IZcPpPaletteVtbl;

    interface IZcPpPalette
    {
        CONST_VTBL struct IZcPpPaletteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpPalette_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpPalette_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpPalette_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpPalette_get_Name(This,name)	\
    (This)->lpVtbl -> get_Name(This,name)

#define IZcPpPalette_put_Name(This,name)	\
    (This)->lpVtbl -> put_Name(This,name)

#define IZcPpPalette_get_InspectorControl(This,pInspector)	\
    (This)->lpVtbl -> get_InspectorControl(This,pInspector)

#endif 


#endif 	



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpPalette_get_Name_Proxy( 
    IZcPpPalette * This,
    /* [retval][out] */ BSTR *name);


void __RPC_STUB IZcPpPalette_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpPalette_put_Name_Proxy( 
    IZcPpPalette * This,
    /* [in] */ BSTR name);


void __RPC_STUB IZcPpPalette_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpPalette_get_InspectorControl_Proxy( 
    IZcPpPalette * This,
    /* [retval][out] */ IZcPiPropertyInspector **pInspector);


void __RPC_STUB IZcPpPalette_get_InspectorControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcPpPaletteEvents_INTERFACE_DEFINED__
#define __IZcPpPaletteEvents_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpPaletteEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1EA7682-303C-4173-BA92-0EEF3DD3756E")
    IZcPpPaletteEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnNameChanged( 
            /* [in] */ BSTR newName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSelectionChanged( 
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray,
            /* [out][in] */ VARIANT_BOOL *bHandled) = 0;
        
    };
    
#else 	

    typedef struct IZcPpPaletteEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpPaletteEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpPaletteEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpPaletteEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnNameChanged )( 
            IZcPpPaletteEvents * This,
            /* [in] */ BSTR newName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSelectionChanged )( 
            IZcPpPaletteEvents * This,
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray,
            /* [out][in] */ VARIANT_BOOL *bHandled);
        
        END_INTERFACE
    } IZcPpPaletteEventsVtbl;

    interface IZcPpPaletteEvents
    {
        CONST_VTBL struct IZcPpPaletteEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpPaletteEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpPaletteEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpPaletteEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpPaletteEvents_OnNameChanged(This,newName)	\
    (This)->lpVtbl -> OnNameChanged(This,newName)

#define IZcPpPaletteEvents_OnSelectionChanged(This,newObjectArray,newPropMgrArray,bHandled)	\
    (This)->lpVtbl -> OnSelectionChanged(This,newObjectArray,newPropMgrArray,bHandled)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteEvents_OnNameChanged_Proxy( 
    IZcPpPaletteEvents * This,
    /* [in] */ BSTR newName);


void __RPC_STUB IZcPpPaletteEvents_OnNameChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteEvents_OnSelectionChanged_Proxy( 
    IZcPpPaletteEvents * This,
    /* [in] */ VARIANT *newObjectArray,
    /* [in] */ VARIANT *newPropMgrArray,
    /* [out][in] */ VARIANT_BOOL *bHandled);


void __RPC_STUB IZcPpPaletteEvents_OnSelectionChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcPpPaletteSet_INTERFACE_DEFINED__
#define __IZcPpPaletteSet_INTERFACE_DEFINED__



typedef /* [v1_enum] */ 
enum DockPos
    {	Floating	= -1,
	Left	= 0xe81c,
	Right	= 0xe81d
    } 	ZDockPos;


EXTERN_C const IID IID_IZcPpPaletteSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CC0CED7-7D69-490b-A84B-A7500674A29C")
    IZcPpPaletteSet : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPalette( 
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeletePalette( 
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertPalette( 
            /* [in] */ int index,
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPalette( 
            /* [in] */ int index,
            /* [retval][out] */ IZcPpPalette **pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPaletteByName( 
            /* [in] */ BSTR paletteName,
            /* [retval][out] */ IZcPpPalette **pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZctivatePalette( 
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PaletteCount( 
            /* [retval][out] */ int *nPalettes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Visibility( 
            /* [retval][out] */ VARIANT_BOOL *bIsVisible) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Visibility( 
            /* [in] */ VARIANT_BOOL bIsVisible) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIndex( 
            /* [retval][out] */ int *nCurrentIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDockingState( 
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDockingState( 
            /* [in] */ int nDockPos,
            /* [in] */ long left,
            /* [in] */ long top,
            /* [in] */ long width,
            /* [in] */ long height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFloatingRect( 
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDockingRect( 
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height) = 0;
        
    };
    
#else 	

    typedef struct IZcPpPaletteSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpPaletteSet * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpPaletteSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpPaletteSet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPalette )( 
            IZcPpPaletteSet * This,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeletePalette )( 
            IZcPpPaletteSet * This,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertPalette )( 
            IZcPpPaletteSet * This,
            /* [in] */ int index,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPalette )( 
            IZcPpPaletteSet * This,
            /* [in] */ int index,
            /* [retval][out] */ IZcPpPalette **pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPaletteByName )( 
            IZcPpPaletteSet * This,
            /* [in] */ BSTR paletteName,
            /* [retval][out] */ IZcPpPalette **pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZctivatePalette )( 
            IZcPpPaletteSet * This,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PaletteCount )( 
            IZcPpPaletteSet * This,
            /* [retval][out] */ int *nPalettes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visibility )( 
            IZcPpPaletteSet * This,
            /* [retval][out] */ VARIANT_BOOL *bIsVisible);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visibility )( 
            IZcPpPaletteSet * This,
            /* [in] */ VARIANT_BOOL bIsVisible);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentIndex )( 
            IZcPpPaletteSet * This,
            /* [retval][out] */ int *nCurrentIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDockingState )( 
            IZcPpPaletteSet * This,
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDockingState )( 
            IZcPpPaletteSet * This,
            /* [in] */ int nDockPos,
            /* [in] */ long left,
            /* [in] */ long top,
            /* [in] */ long width,
            /* [in] */ long height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFloatingRect )( 
            IZcPpPaletteSet * This,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDockingRect )( 
            IZcPpPaletteSet * This,
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height);
        
        END_INTERFACE
    } IZcPpPaletteSetVtbl;

    interface IZcPpPaletteSet
    {
        CONST_VTBL struct IZcPpPaletteSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpPaletteSet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpPaletteSet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpPaletteSet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpPaletteSet_AddPalette(This,pPalette)	\
    (This)->lpVtbl -> AddPalette(This,pPalette)

#define IZcPpPaletteSet_DeletePalette(This,pPalette)	\
    (This)->lpVtbl -> DeletePalette(This,pPalette)

#define IZcPpPaletteSet_InsertPalette(This,index,pPalette)	\
    (This)->lpVtbl -> InsertPalette(This,index,pPalette)

#define IZcPpPaletteSet_GetPalette(This,index,pPalette)	\
    (This)->lpVtbl -> GetPalette(This,index,pPalette)

#define IZcPpPaletteSet_GetPaletteByName(This,paletteName,pPalette)	\
    (This)->lpVtbl -> GetPaletteByName(This,paletteName,pPalette)

#define IZcPpPaletteSet_ZctivatePalette(This,pPalette)	\
    (This)->lpVtbl -> ZctivatePalette(This,pPalette)

#define IZcPpPaletteSet_get_PaletteCount(This,nPalettes)	\
    (This)->lpVtbl -> get_PaletteCount(This,nPalettes)

#define IZcPpPaletteSet_get_Visibility(This,bIsVisible)	\
    (This)->lpVtbl -> get_Visibility(This,bIsVisible)

#define IZcPpPaletteSet_put_Visibility(This,bIsVisible)	\
    (This)->lpVtbl -> put_Visibility(This,bIsVisible)

#define IZcPpPaletteSet_get_CurrentIndex(This,nCurrentIndex)	\
    (This)->lpVtbl -> get_CurrentIndex(This,nCurrentIndex)

#define IZcPpPaletteSet_GetDockingState(This,nDockPos,left,top,width,height)	\
    (This)->lpVtbl -> GetDockingState(This,nDockPos,left,top,width,height)

#define IZcPpPaletteSet_SetDockingState(This,nDockPos,left,top,width,height)	\
    (This)->lpVtbl -> SetDockingState(This,nDockPos,left,top,width,height)

#define IZcPpPaletteSet_GetFloatingRect(This,left,top,width,height)	\
    (This)->lpVtbl -> GetFloatingRect(This,left,top,width,height)

#define IZcPpPaletteSet_GetDockingRect(This,nDockPos,left,top,width,height)	\
    (This)->lpVtbl -> GetDockingRect(This,nDockPos,left,top,width,height)

#endif 


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_AddPalette_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSet_AddPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_DeletePalette_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSet_DeletePalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_InsertPalette_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ int index,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSet_InsertPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_GetPalette_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ int index,
    /* [retval][out] */ IZcPpPalette **pPalette);


void __RPC_STUB IZcPpPaletteSet_GetPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_GetPaletteByName_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ BSTR paletteName,
    /* [retval][out] */ IZcPpPalette **pPalette);


void __RPC_STUB IZcPpPaletteSet_GetPaletteByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_ZctivatePalette_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSet_ZctivatePalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_get_PaletteCount_Proxy( 
    IZcPpPaletteSet * This,
    /* [retval][out] */ int *nPalettes);


void __RPC_STUB IZcPpPaletteSet_get_PaletteCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_get_Visibility_Proxy( 
    IZcPpPaletteSet * This,
    /* [retval][out] */ VARIANT_BOOL *bIsVisible);


void __RPC_STUB IZcPpPaletteSet_get_Visibility_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_put_Visibility_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ VARIANT_BOOL bIsVisible);


void __RPC_STUB IZcPpPaletteSet_put_Visibility_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_get_CurrentIndex_Proxy( 
    IZcPpPaletteSet * This,
    /* [retval][out] */ int *nCurrentIndex);


void __RPC_STUB IZcPpPaletteSet_get_CurrentIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_GetDockingState_Proxy( 
    IZcPpPaletteSet * This,
    /* [out] */ int *nDockPos,
    /* [out] */ long *left,
    /* [out] */ long *top,
    /* [out] */ long *width,
    /* [out] */ long *height);


void __RPC_STUB IZcPpPaletteSet_GetDockingState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_SetDockingState_Proxy( 
    IZcPpPaletteSet * This,
    /* [in] */ int nDockPos,
    /* [in] */ long left,
    /* [in] */ long top,
    /* [in] */ long width,
    /* [in] */ long height);


void __RPC_STUB IZcPpPaletteSet_SetDockingState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_GetFloatingRect_Proxy( 
    IZcPpPaletteSet * This,
    /* [out] */ long *left,
    /* [out] */ long *top,
    /* [out] */ long *width,
    /* [out] */ long *height);


void __RPC_STUB IZcPpPaletteSet_GetFloatingRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSet_GetDockingRect_Proxy( 
    IZcPpPaletteSet * This,
    /* [out] */ int *nDockPos,
    /* [out] */ long *left,
    /* [out] */ long *top,
    /* [out] */ long *width,
    /* [out] */ long *height);


void __RPC_STUB IZcPpPaletteSet_GetDockingRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcPpPaletteSetEvents_INTERFACE_DEFINED__
#define __IZcPpPaletteSetEvents_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpPaletteSetEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C3F530AF-E211-49fa-9E02-28290E4141F6")
    IZcPpPaletteSetEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPaletteAdded( 
            /* [in] */ IZcPpPalette *pNewPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPaletteDeleted( 
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPaletteZctivated( 
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPaletteDeZctivated( 
            /* [in] */ IZcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSelectionChanged( 
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnVisibilityChanged( 
            /* [in] */ VARIANT_BOOL bIsVisible) = 0;
        
    };
    
#else 	

    typedef struct IZcPpPaletteSetEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpPaletteSetEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpPaletteSetEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPaletteAdded )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ IZcPpPalette *pNewPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPaletteDeleted )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPaletteZctivated )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPaletteDeZctivated )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ IZcPpPalette *pPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSelectionChanged )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnVisibilityChanged )( 
            IZcPpPaletteSetEvents * This,
            /* [in] */ VARIANT_BOOL bIsVisible);
        
        END_INTERFACE
    } IZcPpPaletteSetEventsVtbl;

    interface IZcPpPaletteSetEvents
    {
        CONST_VTBL struct IZcPpPaletteSetEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpPaletteSetEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpPaletteSetEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpPaletteSetEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpPaletteSetEvents_OnPaletteAdded(This,pNewPalette)	\
    (This)->lpVtbl -> OnPaletteAdded(This,pNewPalette)

#define IZcPpPaletteSetEvents_OnPaletteDeleted(This,pPalette)	\
    (This)->lpVtbl -> OnPaletteDeleted(This,pPalette)

#define IZcPpPaletteSetEvents_OnPaletteZctivated(This,pPalette)	\
    (This)->lpVtbl -> OnPaletteZctivated(This,pPalette)

#define IZcPpPaletteSetEvents_OnPaletteDeZctivated(This,pPalette)	\
    (This)->lpVtbl -> OnPaletteDeZctivated(This,pPalette)

#define IZcPpPaletteSetEvents_OnSelectionChanged(This,newObjectArray,newPropMgrArray)	\
    (This)->lpVtbl -> OnSelectionChanged(This,newObjectArray,newPropMgrArray)

#define IZcPpPaletteSetEvents_OnVisibilityChanged(This,bIsVisible)	\
    (This)->lpVtbl -> OnVisibilityChanged(This,bIsVisible)

#endif


#endif 	



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSetEvents_OnPaletteAdded_Proxy( 
    IZcPpPaletteSetEvents * This,
    /* [in] */ IZcPpPalette *pNewPalette);


void __RPC_STUB IZcPpPaletteSetEvents_OnPaletteAdded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSetEvents_OnPaletteDeleted_Proxy( 
    IZcPpPaletteSetEvents * This,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSetEvents_OnPaletteDeleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSetEvents_OnPaletteZctivated_Proxy( 
    IZcPpPaletteSetEvents * This,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSetEvents_OnPaletteZctivated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSetEvents_OnPaletteDeZctivated_Proxy( 
    IZcPpPaletteSetEvents * This,
    /* [in] */ IZcPpPalette *pPalette);


void __RPC_STUB IZcPpPaletteSetEvents_OnPaletteDeZctivated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSetEvents_OnSelectionChanged_Proxy( 
    IZcPpPaletteSetEvents * This,
    /* [in] */ VARIANT *newObjectArray,
    /* [in] */ VARIANT *newPropMgrArray);


void __RPC_STUB IZcPpPaletteSetEvents_OnSelectionChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpPaletteSetEvents_OnVisibilityChanged_Proxy( 
    IZcPpPaletteSetEvents * This,
    /* [in] */ VARIANT_BOOL bIsVisible);


void __RPC_STUB IZcPpPaletteSetEvents_OnVisibilityChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 


#ifndef __IZcPpNavTreeNode_INTERFACE_DEFINED__
#define __IZcPpNavTreeNode_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11E68B1B-2A9F-4b1d-BB58-CD5A43FB6F30")
    IZcPpNavTreeNode : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentID( 
            /* [retval][out] */ long *pID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Label( 
            /* [retval][out] */ BSTR *pLabel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftIconRes( 
            /* [retval][out] */ BSTR *pPath) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftIconResType( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetObject( 
            VARIANT *pObject) = 0;
        
    };
    
#else 	

    typedef struct IZcPpNavTreeNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeNode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeNode * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IZcPpNavTreeNode * This,
            /* [retval][out] */ long *pID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentID )( 
            IZcPpNavTreeNode * This,
            /* [retval][out] */ long *pID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Label )( 
            IZcPpNavTreeNode * This,
            /* [retval][out] */ BSTR *pLabel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftIconRes )( 
            IZcPpNavTreeNode * This,
            /* [retval][out] */ BSTR *pPath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftIconResType )( 
            IZcPpNavTreeNode * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            IZcPpNavTreeNode * This,
            VARIANT *pObject);
        
        END_INTERFACE
    } IZcPpNavTreeNodeVtbl;

    interface IZcPpNavTreeNode
    {
        CONST_VTBL struct IZcPpNavTreeNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeNode_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeNode_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeNode_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeNode_get_ID(This,pID)	\
    (This)->lpVtbl -> get_ID(This,pID)

#define IZcPpNavTreeNode_get_ParentID(This,pID)	\
    (This)->lpVtbl -> get_ParentID(This,pID)

#define IZcPpNavTreeNode_get_Label(This,pLabel)	\
    (This)->lpVtbl -> get_Label(This,pLabel)

#define IZcPpNavTreeNode_get_LeftIconRes(This,pPath)	\
    (This)->lpVtbl -> get_LeftIconRes(This,pPath)

#define IZcPpNavTreeNode_get_LeftIconResType(This,pVal)	\
    (This)->lpVtbl -> get_LeftIconResType(This,pVal)

#define IZcPpNavTreeNode_GetObject(This,pObject)	\
    (This)->lpVtbl -> GetObject(This,pObject)

#endif 


#endif 	



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNode_get_ID_Proxy( 
    IZcPpNavTreeNode * This,
    /* [retval][out] */ long *pID);


void __RPC_STUB IZcPpNavTreeNode_get_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNode_get_ParentID_Proxy( 
    IZcPpNavTreeNode * This,
    /* [retval][out] */ long *pID);


void __RPC_STUB IZcPpNavTreeNode_get_ParentID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNode_get_Label_Proxy( 
    IZcPpNavTreeNode * This,
    /* [retval][out] */ BSTR *pLabel);


void __RPC_STUB IZcPpNavTreeNode_get_Label_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNode_get_LeftIconRes_Proxy( 
    IZcPpNavTreeNode * This,
    /* [retval][out] */ BSTR *pPath);


void __RPC_STUB IZcPpNavTreeNode_get_LeftIconRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNode_get_LeftIconResType_Proxy( 
    IZcPpNavTreeNode * This,
    /* [retval][out] */ ULONG *pVal);


void __RPC_STUB IZcPpNavTreeNode_get_LeftIconResType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNode_GetObject_Proxy( 
    IZcPpNavTreeNode * This,
    VARIANT *pObject);


void __RPC_STUB IZcPpNavTreeNode_GetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__
#define __IZcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeNodeCollectionIter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82AE492A-56B9-45cb-81DD-9678CA98E3B4")
    IZcPpNavTreeNodeCollectionIter : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Current( 
            /* [out] */ IZcPpNavTreeNode **pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Done( 
            /* [out] */ VARIANT_BOOL *pBool) = 0;
        
    };
    
#else 	

    typedef struct IZcPpNavTreeNodeCollectionIterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeNodeCollectionIter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeNodeCollectionIter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeNodeCollectionIter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IZcPpNavTreeNodeCollectionIter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IZcPpNavTreeNodeCollectionIter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Current )( 
            IZcPpNavTreeNodeCollectionIter * This,
            /* [out] */ IZcPpNavTreeNode **pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Done )( 
            IZcPpNavTreeNodeCollectionIter * This,
            /* [out] */ VARIANT_BOOL *pBool);
        
        END_INTERFACE
    } IZcPpNavTreeNodeCollectionIterVtbl;

    interface IZcPpNavTreeNodeCollectionIter
    {
        CONST_VTBL struct IZcPpNavTreeNodeCollectionIterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeNodeCollectionIter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeNodeCollectionIter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeNodeCollectionIter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeNodeCollectionIter_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IZcPpNavTreeNodeCollectionIter_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IZcPpNavTreeNodeCollectionIter_Current(This,pNode)	\
    (This)->lpVtbl -> Current(This,pNode)

#define IZcPpNavTreeNodeCollectionIter_Done(This,pBool)	\
    (This)->lpVtbl -> Done(This,pBool)

#endif 


#endif



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollectionIter_Start_Proxy( 
    IZcPpNavTreeNodeCollectionIter * This);


void __RPC_STUB IZcPpNavTreeNodeCollectionIter_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollectionIter_Next_Proxy( 
    IZcPpNavTreeNodeCollectionIter * This);


void __RPC_STUB IZcPpNavTreeNodeCollectionIter_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollectionIter_Current_Proxy( 
    IZcPpNavTreeNodeCollectionIter * This,
    /* [out] */ IZcPpNavTreeNode **pNode);


void __RPC_STUB IZcPpNavTreeNodeCollectionIter_Current_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollectionIter_Done_Proxy( 
    IZcPpNavTreeNodeCollectionIter * This,
    /* [out] */ VARIANT_BOOL *pBool);


void __RPC_STUB IZcPpNavTreeNodeCollectionIter_Done_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif


#ifndef __IZcPpNavTreeNodeCollection_INTERFACE_DEFINED__
#define __IZcPpNavTreeNodeCollection_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeNodeCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9A28A23F-9714-4c48-8BE9-CB8D591F1F3C")
    IZcPpNavTreeNodeCollection : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddNode( 
            /* [in] */ IZcPpNavTreeNode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteNode( 
            /* [in] */ IZcPpNavTreeNode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteAllNodes( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNodeCollectionIter( 
            /* [retval][out] */ IZcPpNavTreeNodeCollectionIter **PIter) = 0;
        
    };
    
#else

    typedef struct IZcPpNavTreeNodeCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeNodeCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeNodeCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeNodeCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddNode )( 
            IZcPpNavTreeNodeCollection * This,
            /* [in] */ IZcPpNavTreeNode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteNode )( 
            IZcPpNavTreeNodeCollection * This,
            /* [in] */ IZcPpNavTreeNode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteAllNodes )( 
            IZcPpNavTreeNodeCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNodeCollectionIter )( 
            IZcPpNavTreeNodeCollection * This,
            /* [retval][out] */ IZcPpNavTreeNodeCollectionIter **PIter);
        
        END_INTERFACE
    } IZcPpNavTreeNodeCollectionVtbl;

    interface IZcPpNavTreeNodeCollection
    {
        CONST_VTBL struct IZcPpNavTreeNodeCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeNodeCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeNodeCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeNodeCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeNodeCollection_AddNode(This,pNode)	\
    (This)->lpVtbl -> AddNode(This,pNode)

#define IZcPpNavTreeNodeCollection_DeleteNode(This,pNode)	\
    (This)->lpVtbl -> DeleteNode(This,pNode)

#define IZcPpNavTreeNodeCollection_DeleteAllNodes(This)	\
    (This)->lpVtbl -> DeleteAllNodes(This)

#define IZcPpNavTreeNodeCollection_GetNodeCollectionIter(This,PIter)	\
    (This)->lpVtbl -> GetNodeCollectionIter(This,PIter)

#endif


#endif



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollection_AddNode_Proxy( 
    IZcPpNavTreeNodeCollection * This,
    /* [in] */ IZcPpNavTreeNode *pNode);


void __RPC_STUB IZcPpNavTreeNodeCollection_AddNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollection_DeleteNode_Proxy( 
    IZcPpNavTreeNodeCollection * This,
    /* [in] */ IZcPpNavTreeNode *pNode);


void __RPC_STUB IZcPpNavTreeNodeCollection_DeleteNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollection_DeleteAllNodes_Proxy( 
    IZcPpNavTreeNodeCollection * This);


void __RPC_STUB IZcPpNavTreeNodeCollection_DeleteAllNodes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeNodeCollection_GetNodeCollectionIter_Proxy( 
    IZcPpNavTreeNodeCollection * This,
    /* [retval][out] */ IZcPpNavTreeNodeCollectionIter **PIter);


void __RPC_STUB IZcPpNavTreeNodeCollection_GetNodeCollectionIter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif


#ifndef __IZcPpNavTreeCmdBtn_INTERFACE_DEFINED__
#define __IZcPpNavTreeCmdBtn_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeCmdBtn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17F515C8-18E6-4731-A29A-12A5AB72F2A9")
    IZcPpNavTreeCmdBtn : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBtnImage( 
            /* [out] */ BSTR *pPath,
            /* [out] */ ULONG *pImgType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
    };
    
#else

    typedef struct IZcPpNavTreeCmdBtnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeCmdBtn * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeCmdBtn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeCmdBtn * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IZcPpNavTreeCmdBtn * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBtnImage )( 
            IZcPpNavTreeCmdBtn * This,
            /* [out] */ BSTR *pPath,
            /* [out] */ ULONG *pImgType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IZcPpNavTreeCmdBtn * This);
        
        END_INTERFACE
    } IZcPpNavTreeCmdBtnVtbl;

    interface IZcPpNavTreeCmdBtn
    {
        CONST_VTBL struct IZcPpNavTreeCmdBtnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeCmdBtn_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeCmdBtn_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeCmdBtn_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeCmdBtn_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IZcPpNavTreeCmdBtn_GetBtnImage(This,pPath,pImgType)	\
    (This)->lpVtbl -> GetBtnImage(This,pPath,pImgType)

#define IZcPpNavTreeCmdBtn_Execute(This)	\
    (This)->lpVtbl -> Execute(This)

#endif


#endif



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtn_get_Name_Proxy( 
    IZcPpNavTreeCmdBtn * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB IZcPpNavTreeCmdBtn_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtn_GetBtnImage_Proxy( 
    IZcPpNavTreeCmdBtn * This,
    /* [out] */ BSTR *pPath,
    /* [out] */ ULONG *pImgType);


void __RPC_STUB IZcPpNavTreeCmdBtn_GetBtnImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtn_Execute_Proxy( 
    IZcPpNavTreeCmdBtn * This);


void __RPC_STUB IZcPpNavTreeCmdBtn_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif


#ifndef __IZcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__
#define __IZcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeCmdBtnCollectionIter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1B14B5F9-D967-4c62-AE3B-FAD4CF051F63")
    IZcPpNavTreeCmdBtnCollectionIter : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Current( 
            /* [out] */ IZcPpNavTreeCmdBtn **pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Done( 
            /* [out] */ VARIANT_BOOL *pBool) = 0;
        
    };
    
#else

    typedef struct IZcPpNavTreeCmdBtnCollectionIterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeCmdBtnCollectionIter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeCmdBtnCollectionIter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeCmdBtnCollectionIter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IZcPpNavTreeCmdBtnCollectionIter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IZcPpNavTreeCmdBtnCollectionIter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Current )( 
            IZcPpNavTreeCmdBtnCollectionIter * This,
            /* [out] */ IZcPpNavTreeCmdBtn **pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Done )( 
            IZcPpNavTreeCmdBtnCollectionIter * This,
            /* [out] */ VARIANT_BOOL *pBool);
        
        END_INTERFACE
    } IZcPpNavTreeCmdBtnCollectionIterVtbl;

    interface IZcPpNavTreeCmdBtnCollectionIter
    {
        CONST_VTBL struct IZcPpNavTreeCmdBtnCollectionIterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeCmdBtnCollectionIter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeCmdBtnCollectionIter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeCmdBtnCollectionIter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeCmdBtnCollectionIter_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IZcPpNavTreeCmdBtnCollectionIter_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IZcPpNavTreeCmdBtnCollectionIter_Current(This,pNode)	\
    (This)->lpVtbl -> Current(This,pNode)

#define IZcPpNavTreeCmdBtnCollectionIter_Done(This,pBool)	\
    (This)->lpVtbl -> Done(This,pBool)

#endif


#endif



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollectionIter_Start_Proxy( 
    IZcPpNavTreeCmdBtnCollectionIter * This);


void __RPC_STUB IZcPpNavTreeCmdBtnCollectionIter_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollectionIter_Next_Proxy( 
    IZcPpNavTreeCmdBtnCollectionIter * This);


void __RPC_STUB IZcPpNavTreeCmdBtnCollectionIter_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollectionIter_Current_Proxy( 
    IZcPpNavTreeCmdBtnCollectionIter * This,
    /* [out] */ IZcPpNavTreeCmdBtn **pNode);


void __RPC_STUB IZcPpNavTreeCmdBtnCollectionIter_Current_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollectionIter_Done_Proxy( 
    IZcPpNavTreeCmdBtnCollectionIter * This,
    /* [out] */ VARIANT_BOOL *pBool);


void __RPC_STUB IZcPpNavTreeCmdBtnCollectionIter_Done_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif


#ifndef __IZcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__
#define __IZcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeCmdBtnCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5AD8767E-93C1-4256-8031-29D726F4D8ED")
    IZcPpNavTreeCmdBtnCollection : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddButton( 
            /* [in] */ IZcPpNavTreeCmdBtn *pBtn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteButton( 
            /* [in] */ IZcPpNavTreeCmdBtn *pBtn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteAllButtons( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCmdBtnCollectionIter( 
            /* [retval][out] */ IZcPpNavTreeCmdBtnCollectionIter **pIter) = 0;
        
    };
    
#else 

    typedef struct IZcPpNavTreeCmdBtnCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeCmdBtnCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeCmdBtnCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeCmdBtnCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddButton )( 
            IZcPpNavTreeCmdBtnCollection * This,
            /* [in] */ IZcPpNavTreeCmdBtn *pBtn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteButton )( 
            IZcPpNavTreeCmdBtnCollection * This,
            /* [in] */ IZcPpNavTreeCmdBtn *pBtn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteAllButtons )( 
            IZcPpNavTreeCmdBtnCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCmdBtnCollectionIter )( 
            IZcPpNavTreeCmdBtnCollection * This,
            /* [retval][out] */ IZcPpNavTreeCmdBtnCollectionIter **pIter);
        
        END_INTERFACE
    } IZcPpNavTreeCmdBtnCollectionVtbl;

    interface IZcPpNavTreeCmdBtnCollection
    {
        CONST_VTBL struct IZcPpNavTreeCmdBtnCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeCmdBtnCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeCmdBtnCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeCmdBtnCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeCmdBtnCollection_AddButton(This,pBtn)	\
    (This)->lpVtbl -> AddButton(This,pBtn)

#define IZcPpNavTreeCmdBtnCollection_DeleteButton(This,pBtn)	\
    (This)->lpVtbl -> DeleteButton(This,pBtn)

#define IZcPpNavTreeCmdBtnCollection_DeleteAllButtons(This)	\
    (This)->lpVtbl -> DeleteAllButtons(This)

#define IZcPpNavTreeCmdBtnCollection_GetCmdBtnCollectionIter(This,pIter)	\
    (This)->lpVtbl -> GetCmdBtnCollectionIter(This,pIter)

#endif 


#endif



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollection_AddButton_Proxy( 
    IZcPpNavTreeCmdBtnCollection * This,
    /* [in] */ IZcPpNavTreeCmdBtn *pBtn);


void __RPC_STUB IZcPpNavTreeCmdBtnCollection_AddButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollection_DeleteButton_Proxy( 
    IZcPpNavTreeCmdBtnCollection * This,
    /* [in] */ IZcPpNavTreeCmdBtn *pBtn);


void __RPC_STUB IZcPpNavTreeCmdBtnCollection_DeleteButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollection_DeleteAllButtons_Proxy( 
    IZcPpNavTreeCmdBtnCollection * This);


void __RPC_STUB IZcPpNavTreeCmdBtnCollection_DeleteAllButtons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeCmdBtnCollection_GetCmdBtnCollectionIter_Proxy( 
    IZcPpNavTreeCmdBtnCollection * This,
    /* [retval][out] */ IZcPpNavTreeCmdBtnCollectionIter **pIter);


void __RPC_STUB IZcPpNavTreeCmdBtnCollection_GetCmdBtnCollectionIter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 


#ifndef __IZcPpNavTree_INTERFACE_DEFINED__
#define __IZcPpNavTree_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTree;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3412E0C1-20F7-43dd-B9ED-4299CCD4506C")
    IZcPpNavTree : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( 
            /* [in] */ IZcPpNavTreeNodeCollection *pNodeCollection,
            /* [in] */ IZcPpNavTreeCmdBtnCollection *pCmdBtnCollection) = 0;
        
    };
    
#else

    typedef struct IZcPpNavTreeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTree * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTree * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IZcPpNavTree * This,
            /* [in] */ IZcPpNavTreeNodeCollection *pNodeCollection,
            /* [in] */ IZcPpNavTreeCmdBtnCollection *pCmdBtnCollection);
        
        END_INTERFACE
    } IZcPpNavTreeVtbl;

    interface IZcPpNavTree
    {
        CONST_VTBL struct IZcPpNavTreeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTree_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTree_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTree_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTree_Reset(This,pNodeCollection,pCmdBtnCollection)	\
    (This)->lpVtbl -> Reset(This,pNodeCollection,pCmdBtnCollection)

#endif 


#endif 



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTree_Reset_Proxy( 
    IZcPpNavTree * This,
    /* [in] */ IZcPpNavTreeNodeCollection *pNodeCollection,
    /* [in] */ IZcPpNavTreeCmdBtnCollection *pCmdBtnCollection);


void __RPC_STUB IZcPpNavTree_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcPpNavTreeEvents_INTERFACE_DEFINED__
#define __IZcPpNavTreeEvents_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcPpNavTreeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E08AE839-864C-42a7-90D2-F700306C811C")
    IZcPpNavTreeEvents : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSelectionChanged( 
            /* [in] */ VARIANT *pIntArray,
            /* [out] */ VARIANT *pObjUnkArray,
            /* [out][in] */ VARIANT_BOOL *bHandled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnDblClickTreeItem( 
            /* [in] */ ULONG index,
            /* [in] */ UINT nResourceId) = 0;
        
    };
    
#else

    typedef struct IZcPpNavTreeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpNavTreeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpNavTreeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpNavTreeEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSelectionChanged )( 
            IZcPpNavTreeEvents * This,
            /* [in] */ VARIANT *pIntArray,
            /* [out] */ VARIANT *pObjUnkArray,
            /* [out][in] */ VARIANT_BOOL *bHandled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnDblClickTreeItem )( 
            IZcPpNavTreeEvents * This,
            /* [in] */ ULONG index,
            /* [in] */ UINT nResourceId);
        
        END_INTERFACE
    } IZcPpNavTreeEventsVtbl;

    interface IZcPpNavTreeEvents
    {
        CONST_VTBL struct IZcPpNavTreeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpNavTreeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpNavTreeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpNavTreeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpNavTreeEvents_OnSelectionChanged(This,pIntArray,pObjUnkArray,bHandled)	\
    (This)->lpVtbl -> OnSelectionChanged(This,pIntArray,pObjUnkArray,bHandled)

#define IZcPpNavTreeEvents_OnDblClickTreeItem(This,index,nResourceId)	\
    (This)->lpVtbl -> OnDblClickTreeItem(This,index,nResourceId)

#endif


#endif



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeEvents_OnSelectionChanged_Proxy( 
    IZcPpNavTreeEvents * This,
    /* [in] */ VARIANT *pIntArray,
    /* [out] */ VARIANT *pObjUnkArray,
    /* [out][in] */ VARIANT_BOOL *bHandled);


void __RPC_STUB IZcPpNavTreeEvents_OnSelectionChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPpNavTreeEvents_OnDblClickTreeItem_Proxy( 
    IZcPpNavTreeEvents * This,
    /* [in] */ ULONG index,
    /* [in] */ UINT nResourceId);


void __RPC_STUB IZcPpNavTreeEvents_OnDblClickTreeItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 


#ifndef __IZcPpPalette2_INTERFACE_DEFINED__
#define __IZcPpPalette2_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcPpPalette2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("772460DD-82F1-4e99-B7BF-5AA4B31E3DB1")
    IZcPpPalette2 : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NavTree( 
            /* [retval][out] */ IZcPpNavTree **pNavTree) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NavTree( 
            /* [in] */ IZcPpNavTree *pNavTree) = 0;
        
    };
    
#else

    typedef struct IZcPpPalette2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPpPalette2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPpPalette2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPpPalette2 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NavTree )( 
            IZcPpPalette2 * This,
            /* [retval][out] */ IZcPpNavTree **pNavTree);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NavTree )( 
            IZcPpPalette2 * This,
            /* [in] */ IZcPpNavTree *pNavTree);
        
        END_INTERFACE
    } IZcPpPalette2Vtbl;

    interface IZcPpPalette2
    {
        CONST_VTBL struct IZcPpPalette2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPpPalette2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPpPalette2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPpPalette2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPpPalette2_get_NavTree(This,pNavTree)	\
    (This)->lpVtbl -> get_NavTree(This,pNavTree)

#define IZcPpPalette2_put_NavTree(This,pNavTree)	\
    (This)->lpVtbl -> put_NavTree(This,pNavTree)

#endif


#endif



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcPpPalette2_get_NavTree_Proxy( 
    IZcPpPalette2 * This,
    /* [retval][out] */ IZcPpNavTree **pNavTree);


void __RPC_STUB IZcPpPalette2_get_NavTree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcPpPalette2_put_NavTree_Proxy( 
    IZcPpPalette2 * This,
    /* [in] */ IZcPpNavTree *pNavTree);


void __RPC_STUB IZcPpPalette2_put_NavTree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif



#ifndef __ZcPpLib_LIBRARY_DEFINED__
#define __ZcPpLib_LIBRARY_DEFINED__



EXTERN_C const IID LIBID_ZcPpLib;

EXTERN_C const CLSID CLSID_ZcPpZcadInput;

#ifdef __cplusplus

class DECLSPEC_UUID("9307A809-170D-4A75-B8EC-D3C462D2F4DB")
ZcPpZcadInput;
#endif

EXTERN_C const CLSID CLSID_ZcPpPaletteSet;

#ifdef __cplusplus

class DECLSPEC_UUID("2FAA8BEA-AB1B-479a-97B2-6E7AAB38750E")
ZcPpPaletteSet;
#endif

EXTERN_C const CLSID CLSID_ZcPpPalette;

#ifdef __cplusplus

class DECLSPEC_UUID("83E53FB0-C3F9-44c8-8917-1A79D89B90AA")
ZcPpPalette;
#endif

EXTERN_C const CLSID CLSID_ZcPpPalette2;

#ifdef __cplusplus

class DECLSPEC_UUID("D43BEA50-AE29-4bd6-83B6-DE3ED23F517A")
ZcPpPalette2;
#endif

EXTERN_C const CLSID CLSID_ZcPpNavTree;

#ifdef __cplusplus

class DECLSPEC_UUID("F06460E2-3313-47b0-B464-DAC6B1F45A21")
ZcPpNavTree;
#endif

EXTERN_C const CLSID CLSID_ZcPpNavTreeNode;

#ifdef __cplusplus

class DECLSPEC_UUID("927E6A91-B46D-4149-B0F9-EC25712FF1E0")
ZcPpNavTreeNode;
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


