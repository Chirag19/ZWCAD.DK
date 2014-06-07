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

#ifndef __ZcTc_i_h__
#define __ZcTc_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif


#ifndef __IZcadToolProperties_FWD_DEFINED__
#define __IZcadToolProperties_FWD_DEFINED__
typedef interface IZcadToolProperties IZcadToolProperties;
#endif 	


#ifndef __IZcadToolProperties2_FWD_DEFINED__
#define __IZcadToolProperties2_FWD_DEFINED__
typedef interface IZcadToolProperties2 IZcadToolProperties2;
#endif 	


#ifndef __IZcadStockTool_FWD_DEFINED__
#define __IZcadStockTool_FWD_DEFINED__
typedef interface IZcadStockTool IZcadStockTool;
#endif 	


#ifndef __IZcadToolContextMenu_FWD_DEFINED__
#define __IZcadToolContextMenu_FWD_DEFINED__
typedef interface IZcadToolContextMenu IZcadToolContextMenu;
#endif 	


#ifndef __IZcadTool_FWD_DEFINED__
#define __IZcadTool_FWD_DEFINED__
typedef interface IZcadTool IZcadTool;
#endif 	


#ifndef __IZcadTool2_FWD_DEFINED__
#define __IZcadTool2_FWD_DEFINED__
typedef interface IZcadTool2 IZcadTool2;
#endif 	


#ifndef __IZcadToolFlyoutShape_FWD_DEFINED__
#define __IZcadToolFlyoutShape_FWD_DEFINED__
typedef interface IZcadToolFlyoutShape IZcadToolFlyoutShape;
#endif 	


#ifndef __IZcadToolSort_FWD_DEFINED__
#define __IZcadToolSort_FWD_DEFINED__
typedef interface IZcadToolSort IZcadToolSort;
#endif 	


#ifndef __IZcadToolDropTarget_FWD_DEFINED__
#define __IZcadToolDropTarget_FWD_DEFINED__
typedef interface IZcadToolDropTarget IZcadToolDropTarget;
#endif 	


#ifndef __IZcadToolDragSource_FWD_DEFINED__
#define __IZcadToolDragSource_FWD_DEFINED__
typedef interface IZcadToolDragSource IZcadToolDragSource;
#endif 	


#ifndef __IZcadToolCopyPaste_FWD_DEFINED__
#define __IZcadToolCopyPaste_FWD_DEFINED__
typedef interface IZcadToolCopyPaste IZcadToolCopyPaste;
#endif 	


#ifndef __IZcadToolImage_FWD_DEFINED__
#define __IZcadToolImage_FWD_DEFINED__
typedef interface IZcadToolImage IZcadToolImage;
#endif 	


#ifndef __AcadToolProperties_FWD_DEFINED__
#define __AcadToolProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadToolProperties AcadToolProperties;
#else
typedef struct AcadToolProperties AcadToolProperties;
#endif 

#endif 	


#ifndef __AcadToolImage_FWD_DEFINED__
#define __AcadToolImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcadToolImage AcadToolImage;
#else
typedef struct AcadToolImage AcadToolImage;
#endif 

#endif 	



#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


typedef 
enum __MIDL___MIDL_itf_ZcTc_0000_0001
    {	kEditDefault	= 0,
	kEditCustom	= kEditDefault + 1,
	kEditNone	= kEditCustom + 1,
	kEditMultiple	= 0x4
    } 	ToolEditMode;

typedef 
enum __MIDL___MIDL_itf_ZcTc_0000_0002
    {	kContextNone	= -1,
	kContextMenuPaletteTool	= kContextNone + 1,
	kContextMenuEditorImage	= kContextMenuPaletteTool + 1,
	kContextMenuPaletteBackground	= kContextMenuEditorImage + 1,
	kContextMenuPaletteSetTab	= kContextMenuPaletteBackground + 1,
	kContextMenuPaletteSetCaption	= kContextMenuPaletteSetTab + 1,
	kContextMenuPaletteSetOptionButton	= kContextMenuPaletteSetCaption + 1
    } 	ContextMenuFlag;

typedef 
enum __MIDL___MIDL_itf_ZcTc_0000_0003
    {	kContextMenuShow	= 0,
	kContextMenuHide	= kContextMenuShow + 1,
	kExecutionCanceled	= kContextMenuHide + 1,
	kExecutionCancelRejected	= kExecutionCanceled + 1,
	kContextMenuUpdatePalette	= kExecutionCancelRejected + 1
    } 	ReturnFlag;

typedef 
enum __MIDL___MIDL_itf_ZcTc_0000_0004
    {	kLButtonClicked	= 0,
	kDroppedInDrawing	= kLButtonClicked + 1
    } 	ExecutionContext;



extern RPC_IF_HANDLE __MIDL_itf_ZcTc_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcTc_0000_v0_0_s_ifspec;

#ifndef __IZcadToolProperties_INTERFACE_DEFINED__
#define __IZcadToolProperties_INTERFACE_DEFINED__


EXTERN_C const IID IID_IZcadToolProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0659777-57F0-4742-9A12-F47742BAB69D")
    IZcadToolProperties : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ GUID *pId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolTipText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolTipText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpCommand( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpData( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HelpData( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *pReadOnly) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolType( 
            /* [retval][out] */ LONG *pToolType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolType( 
            /* [in] */ LONG lToolType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsFlyoutEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pEnabled) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsFlyoutEnabled( 
            /* [in] */ VARIANT_BOOL bUseFlyout) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShapePackageId( 
            /* [retval][out] */ GUID *pId) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShapePackageId( 
            /* [in] */ GUID *pId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentShapeId( 
            /* [retval][out] */ GUID *pId) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentShapeId( 
            /* [in] */ GUID *pId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveShapeIds( 
            /* [retval][out] */ VARIANT *pShapes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveShapeIds( 
            /* [in] */ VARIANT *pShapes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImage( 
            /* [in] */ long cx,
            /* [in] */ long cy,
            /* [out] */ IUnknown **pVal,
            /* [out] */ BSTR *sResourceName,
            /* [out] */ BSTR *sSourceFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetImage( 
            /* [in] */ long cx,
            /* [in] */ long cy,
            /* [in] */ IUnknown *newVal,
            /* [in] */ BSTR sResourceName,
            /* [in] */ BSTR sSourceFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCustomData( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrentShape( 
            /* [out] */ IUnknown **ppTool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOverlayImage( 
            /* [out] */ IUnknown **pVal,
            /* [out] */ BSTR *pResourceName,
            /* [out] */ BSTR *pSourceFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOverlayImage( 
            /* [in] */ IUnknown *newVal,
            /* [in] */ BSTR sResourceName,
            /* [in] */ BSTR sSourceFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetZcTcTool( 
            /* [retval][out] */ DWORD_PTR *ppZcTcTool) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadToolProperties * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadToolProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadToolProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadToolProperties * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IZcadToolProperties * This,
            /* [retval][out] */ GUID *pId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IZcadToolProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IZcadToolProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IZcadToolProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IZcadToolProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolTipText )( 
            IZcadToolProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolTipText )( 
            IZcadToolProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpFile )( 
            IZcadToolProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HelpFile )( 
            IZcadToolProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpCommand )( 
            IZcadToolProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HelpCommand )( 
            IZcadToolProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpData )( 
            IZcadToolProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HelpData )( 
            IZcadToolProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IZcadToolProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pReadOnly);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolType )( 
            IZcadToolProperties * This,
            /* [retval][out] */ LONG *pToolType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolType )( 
            IZcadToolProperties * This,
            /* [in] */ LONG lToolType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsFlyoutEnabled )( 
            IZcadToolProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsFlyoutEnabled )( 
            IZcadToolProperties * This,
            /* [in] */ VARIANT_BOOL bUseFlyout);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShapePackageId )( 
            IZcadToolProperties * This,
            /* [retval][out] */ GUID *pId);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShapePackageId )( 
            IZcadToolProperties * This,
            /* [in] */ GUID *pId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentShapeId )( 
            IZcadToolProperties * This,
            /* [retval][out] */ GUID *pId);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentShapeId )( 
            IZcadToolProperties * This,
            /* [in] */ GUID *pId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveShapeIds )( 
            IZcadToolProperties * This,
            /* [retval][out] */ VARIANT *pShapes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveShapeIds )( 
            IZcadToolProperties * This,
            /* [in] */ VARIANT *pShapes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            IZcadToolProperties * This,
            /* [in] */ long cx,
            /* [in] */ long cy,
            /* [out] */ IUnknown **pVal,
            /* [out] */ BSTR *sResourceName,
            /* [out] */ BSTR *sSourceFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetImage )( 
            IZcadToolProperties * This,
            /* [in] */ long cx,
            /* [in] */ long cy,
            /* [in] */ IUnknown *newVal,
            /* [in] */ BSTR sResourceName,
            /* [in] */ BSTR sSourceFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCustomData )( 
            IZcadToolProperties * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentShape )( 
            IZcadToolProperties * This,
            /* [out] */ IUnknown **ppTool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOverlayImage )( 
            IZcadToolProperties * This,
            /* [out] */ IUnknown **pVal,
            /* [out] */ BSTR *pResourceName,
            /* [out] */ BSTR *pSourceFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayImage )( 
            IZcadToolProperties * This,
            /* [in] */ IUnknown *newVal,
            /* [in] */ BSTR sResourceName,
            /* [in] */ BSTR sSourceFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetZcTcTool )( 
            IZcadToolProperties * This,
            /* [retval][out] */ DWORD_PTR *ppZcTcTool);
        
        END_INTERFACE
    } IZcadToolPropertiesVtbl;

    interface IZcadToolProperties
    {
        CONST_VTBL struct IZcadToolPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolProperties_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZcadToolProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZcadToolProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZcadToolProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZcadToolProperties_get_ID(This,pId)	\
    (This)->lpVtbl -> get_ID(This,pId)

#define IZcadToolProperties_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IZcadToolProperties_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IZcadToolProperties_get_Description(This,pVal)	\
    (This)->lpVtbl -> get_Description(This,pVal)

#define IZcadToolProperties_put_Description(This,newVal)	\
    (This)->lpVtbl -> put_Description(This,newVal)

#define IZcadToolProperties_get_ToolTipText(This,pVal)	\
    (This)->lpVtbl -> get_ToolTipText(This,pVal)

#define IZcadToolProperties_put_ToolTipText(This,newVal)	\
    (This)->lpVtbl -> put_ToolTipText(This,newVal)

#define IZcadToolProperties_get_HelpFile(This,pVal)	\
    (This)->lpVtbl -> get_HelpFile(This,pVal)

#define IZcadToolProperties_put_HelpFile(This,newVal)	\
    (This)->lpVtbl -> put_HelpFile(This,newVal)

#define IZcadToolProperties_get_HelpCommand(This,pVal)	\
    (This)->lpVtbl -> get_HelpCommand(This,pVal)

#define IZcadToolProperties_put_HelpCommand(This,newVal)	\
    (This)->lpVtbl -> put_HelpCommand(This,newVal)

#define IZcadToolProperties_get_HelpData(This,pVal)	\
    (This)->lpVtbl -> get_HelpData(This,pVal)

#define IZcadToolProperties_put_HelpData(This,newVal)	\
    (This)->lpVtbl -> put_HelpData(This,newVal)

#define IZcadToolProperties_get_IsReadOnly(This,pReadOnly)	\
    (This)->lpVtbl -> get_IsReadOnly(This,pReadOnly)

#define IZcadToolProperties_get_ToolType(This,pToolType)	\
    (This)->lpVtbl -> get_ToolType(This,pToolType)

#define IZcadToolProperties_put_ToolType(This,lToolType)	\
    (This)->lpVtbl -> put_ToolType(This,lToolType)

#define IZcadToolProperties_get_IsFlyoutEnabled(This,pEnabled)	\
    (This)->lpVtbl -> get_IsFlyoutEnabled(This,pEnabled)

#define IZcadToolProperties_put_IsFlyoutEnabled(This,bUseFlyout)	\
    (This)->lpVtbl -> put_IsFlyoutEnabled(This,bUseFlyout)

#define IZcadToolProperties_get_ShapePackageId(This,pId)	\
    (This)->lpVtbl -> get_ShapePackageId(This,pId)

#define IZcadToolProperties_put_ShapePackageId(This,pId)	\
    (This)->lpVtbl -> put_ShapePackageId(This,pId)

#define IZcadToolProperties_get_CurrentShapeId(This,pId)	\
    (This)->lpVtbl -> get_CurrentShapeId(This,pId)

#define IZcadToolProperties_put_CurrentShapeId(This,pId)	\
    (This)->lpVtbl -> put_CurrentShapeId(This,pId)

#define IZcadToolProperties_get_ActiveShapeIds(This,pShapes)	\
    (This)->lpVtbl -> get_ActiveShapeIds(This,pShapes)

#define IZcadToolProperties_put_ActiveShapeIds(This,pShapes)	\
    (This)->lpVtbl -> put_ActiveShapeIds(This,pShapes)

#define IZcadToolProperties_GetImage(This,cx,cy,pVal,sResourceName,sSourceFile)	\
    (This)->lpVtbl -> GetImage(This,cx,cy,pVal,sResourceName,sSourceFile)

#define IZcadToolProperties_SetImage(This,cx,cy,newVal,sResourceName,sSourceFile)	\
    (This)->lpVtbl -> SetImage(This,cx,cy,newVal,sResourceName,sSourceFile)

#define IZcadToolProperties_GetCustomData(This,ppVal)	\
    (This)->lpVtbl -> GetCustomData(This,ppVal)

#define IZcadToolProperties_GetCurrentShape(This,ppTool)	\
    (This)->lpVtbl -> GetCurrentShape(This,ppTool)

#define IZcadToolProperties_GetOverlayImage(This,pVal,pResourceName,pSourceFile)	\
    (This)->lpVtbl -> GetOverlayImage(This,pVal,pResourceName,pSourceFile)

#define IZcadToolProperties_SetOverlayImage(This,newVal,sResourceName,sSourceFile)	\
    (This)->lpVtbl -> SetOverlayImage(This,newVal,sResourceName,sSourceFile)

#define IZcadToolProperties_GetZcTcTool(This,ppZcTcTool)	\
    (This)->lpVtbl -> GetZcTcTool(This,ppZcTcTool)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_ID_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ GUID *pId);


void __RPC_STUB IZcadToolProperties_get_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_Name_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcadToolProperties_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_Name_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcadToolProperties_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_Description_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcadToolProperties_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_Description_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcadToolProperties_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_ToolTipText_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcadToolProperties_get_ToolTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_ToolTipText_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcadToolProperties_put_ToolTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_HelpFile_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcadToolProperties_get_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_HelpFile_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcadToolProperties_put_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_HelpCommand_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcadToolProperties_get_HelpCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_HelpCommand_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcadToolProperties_put_HelpCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_HelpData_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IZcadToolProperties_get_HelpData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_HelpData_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IZcadToolProperties_put_HelpData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_IsReadOnly_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ VARIANT_BOOL *pReadOnly);


void __RPC_STUB IZcadToolProperties_get_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_ToolType_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ LONG *pToolType);


void __RPC_STUB IZcadToolProperties_get_ToolType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_ToolType_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ LONG lToolType);


void __RPC_STUB IZcadToolProperties_put_ToolType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_IsFlyoutEnabled_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ VARIANT_BOOL *pEnabled);


void __RPC_STUB IZcadToolProperties_get_IsFlyoutEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_IsFlyoutEnabled_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ VARIANT_BOOL bUseFlyout);


void __RPC_STUB IZcadToolProperties_put_IsFlyoutEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_ShapePackageId_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ GUID *pId);


void __RPC_STUB IZcadToolProperties_get_ShapePackageId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_ShapePackageId_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ GUID *pId);


void __RPC_STUB IZcadToolProperties_put_ShapePackageId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_CurrentShapeId_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ GUID *pId);


void __RPC_STUB IZcadToolProperties_get_CurrentShapeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_CurrentShapeId_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ GUID *pId);


void __RPC_STUB IZcadToolProperties_put_CurrentShapeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_get_ActiveShapeIds_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ VARIANT *pShapes);


void __RPC_STUB IZcadToolProperties_get_ActiveShapeIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_put_ActiveShapeIds_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ VARIANT *pShapes);


void __RPC_STUB IZcadToolProperties_put_ActiveShapeIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_GetImage_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ long cx,
    /* [in] */ long cy,
    /* [out] */ IUnknown **pVal,
    /* [out] */ BSTR *sResourceName,
    /* [out] */ BSTR *sSourceFile);


void __RPC_STUB IZcadToolProperties_GetImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_SetImage_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ long cx,
    /* [in] */ long cy,
    /* [in] */ IUnknown *newVal,
    /* [in] */ BSTR sResourceName,
    /* [in] */ BSTR sSourceFile);


void __RPC_STUB IZcadToolProperties_SetImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_GetCustomData_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ IUnknown **ppVal);


void __RPC_STUB IZcadToolProperties_GetCustomData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_GetCurrentShape_Proxy( 
    IZcadToolProperties * This,
    /* [out] */ IUnknown **ppTool);


void __RPC_STUB IZcadToolProperties_GetCurrentShape_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_GetOverlayImage_Proxy( 
    IZcadToolProperties * This,
    /* [out] */ IUnknown **pVal,
    /* [out] */ BSTR *pResourceName,
    /* [out] */ BSTR *pSourceFile);


void __RPC_STUB IZcadToolProperties_GetOverlayImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_SetOverlayImage_Proxy( 
    IZcadToolProperties * This,
    /* [in] */ IUnknown *newVal,
    /* [in] */ BSTR sResourceName,
    /* [in] */ BSTR sSourceFile);


void __RPC_STUB IZcadToolProperties_SetOverlayImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties_GetZcTcTool_Proxy( 
    IZcadToolProperties * This,
    /* [retval][out] */ DWORD_PTR *ppZcTcTool);


void __RPC_STUB IZcadToolProperties_GetZcTcTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolProperties2_INTERFACE_DEFINED__
#define __IZcadToolProperties2_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcadToolProperties2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A0E6B0E3-09FB-4E3C-B134-5EDD05CBAB37")
    IZcadToolProperties2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemOption( 
            /* [retval][out] */ LONG *pItemOption) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ItemOption( 
            /* [in] */ LONG lItemOption) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageOption( 
            /* [retval][out] */ LONG *pImageOption) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageOption( 
            /* [in] */ LONG lImageOption) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolProperties2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolProperties2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolProperties2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolProperties2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadToolProperties2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadToolProperties2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadToolProperties2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadToolProperties2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemOption )( 
            IZcadToolProperties2 * This,
            /* [retval][out] */ LONG *pItemOption);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ItemOption )( 
            IZcadToolProperties2 * This,
            /* [in] */ LONG lItemOption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageOption )( 
            IZcadToolProperties2 * This,
            /* [retval][out] */ LONG *pImageOption);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageOption )( 
            IZcadToolProperties2 * This,
            /* [in] */ LONG lImageOption);
        
        END_INTERFACE
    } IZcadToolProperties2Vtbl;

    interface IZcadToolProperties2
    {
        CONST_VTBL struct IZcadToolProperties2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolProperties2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolProperties2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolProperties2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolProperties2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZcadToolProperties2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZcadToolProperties2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZcadToolProperties2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZcadToolProperties2_get_ItemOption(This,pItemOption)	\
    (This)->lpVtbl -> get_ItemOption(This,pItemOption)

#define IZcadToolProperties2_put_ItemOption(This,lItemOption)	\
    (This)->lpVtbl -> put_ItemOption(This,lItemOption)

#define IZcadToolProperties2_get_ImageOption(This,pImageOption)	\
    (This)->lpVtbl -> get_ImageOption(This,pImageOption)

#define IZcadToolProperties2_put_ImageOption(This,lImageOption)	\
    (This)->lpVtbl -> put_ImageOption(This,lImageOption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties2_get_ItemOption_Proxy( 
    IZcadToolProperties2 * This,
    /* [retval][out] */ LONG *pItemOption);


void __RPC_STUB IZcadToolProperties2_get_ItemOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties2_put_ItemOption_Proxy( 
    IZcadToolProperties2 * This,
    /* [in] */ LONG lItemOption);


void __RPC_STUB IZcadToolProperties2_put_ItemOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties2_get_ImageOption_Proxy( 
    IZcadToolProperties2 * This,
    /* [retval][out] */ LONG *pImageOption);


void __RPC_STUB IZcadToolProperties2_get_ImageOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZcadToolProperties2_put_ImageOption_Proxy( 
    IZcadToolProperties2 * This,
    /* [in] */ LONG lImageOption);


void __RPC_STUB IZcadToolProperties2_put_ImageOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadStockTool_INTERFACE_DEFINED__
#define __IZcadStockTool_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadStockTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9A18560-C006-4F2D-8E22-FF55389DABEB")
    IZcadStockTool : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateTool( 
            /* [retval][out] */ IUnknown **ppTool) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadStockToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadStockTool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadStockTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadStockTool * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateTool )( 
            IZcadStockTool * This,
            /* [retval][out] */ IUnknown **ppTool);
        
        END_INTERFACE
    } IZcadStockToolVtbl;

    interface IZcadStockTool
    {
        CONST_VTBL struct IZcadStockToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadStockTool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadStockTool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadStockTool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadStockTool_CreateTool(This,ppTool)	\
    (This)->lpVtbl -> CreateTool(This,ppTool)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadStockTool_CreateTool_Proxy( 
    IZcadStockTool * This,
    /* [retval][out] */ IUnknown **ppTool);


void __RPC_STUB IZcadStockTool_CreateTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolContextMenu_INTERFACE_DEFINED__
#define __IZcadToolContextMenu_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcadToolContextMenu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95FD297B-92FF-4FC3-A7C9-9E65C929DD44")
    IZcadToolContextMenu : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Customize( 
            /* [in] */ int nContextFlag,
            /* [in] */ DWORD_PTR hMenu,
            /* [in] */ UINT idCmdFirst,
            /* [in] */ UINT idCmdLast,
            /* [in] */ GUID *pPaletteId,
            /* [retval][out] */ DWORD *pFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMenuHelp( 
            /* [in] */ UINT idCmd,
            /* [retval][out] */ BSTR *pbstrHelpText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InvokeMenuCommand( 
            /* [in] */ UINT idCmd,
            /* [in] */ GUID *pPaletteId,
            /* [in] */ DWORD_PTR hWnd,
            /* [retval][out] */ DWORD *pFlag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolContextMenuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolContextMenu * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolContextMenu * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolContextMenu * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Customize )( 
            IZcadToolContextMenu * This,
            /* [in] */ int nContextFlag,
            /* [in] */ DWORD_PTR hMenu,
            /* [in] */ UINT idCmdFirst,
            /* [in] */ UINT idCmdLast,
            /* [in] */ GUID *pPaletteId,
            /* [retval][out] */ DWORD *pFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMenuHelp )( 
            IZcadToolContextMenu * This,
            /* [in] */ UINT idCmd,
            /* [retval][out] */ BSTR *pbstrHelpText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InvokeMenuCommand )( 
            IZcadToolContextMenu * This,
            /* [in] */ UINT idCmd,
            /* [in] */ GUID *pPaletteId,
            /* [in] */ DWORD_PTR hWnd,
            /* [retval][out] */ DWORD *pFlag);
        
        END_INTERFACE
    } IZcadToolContextMenuVtbl;

    interface IZcadToolContextMenu
    {
        CONST_VTBL struct IZcadToolContextMenuVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolContextMenu_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolContextMenu_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolContextMenu_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolContextMenu_Customize(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pPaletteId,pFlag)	\
    (This)->lpVtbl -> Customize(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pPaletteId,pFlag)

#define IZcadToolContextMenu_GetMenuHelp(This,idCmd,pbstrHelpText)	\
    (This)->lpVtbl -> GetMenuHelp(This,idCmd,pbstrHelpText)

#define IZcadToolContextMenu_InvokeMenuCommand(This,idCmd,pPaletteId,hWnd,pFlag)	\
    (This)->lpVtbl -> InvokeMenuCommand(This,idCmd,pPaletteId,hWnd,pFlag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolContextMenu_Customize_Proxy( 
    IZcadToolContextMenu * This,
    /* [in] */ int nContextFlag,
    /* [in] */ DWORD_PTR hMenu,
    /* [in] */ UINT idCmdFirst,
    /* [in] */ UINT idCmdLast,
    /* [in] */ GUID *pPaletteId,
    /* [retval][out] */ DWORD *pFlag);


void __RPC_STUB IZcadToolContextMenu_Customize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolContextMenu_GetMenuHelp_Proxy( 
    IZcadToolContextMenu * This,
    /* [in] */ UINT idCmd,
    /* [retval][out] */ BSTR *pbstrHelpText);


void __RPC_STUB IZcadToolContextMenu_GetMenuHelp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolContextMenu_InvokeMenuCommand_Proxy( 
    IZcadToolContextMenu * This,
    /* [in] */ UINT idCmd,
    /* [in] */ GUID *pPaletteId,
    /* [in] */ DWORD_PTR hWnd,
    /* [retval][out] */ DWORD *pFlag);


void __RPC_STUB IZcadToolContextMenu_InvokeMenuCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadTool_INTERFACE_DEFINED__
#define __IZcadTool_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9E842E9C-2A44-4B89-9AB5-F4926F321F2A")
    IZcadTool : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EditMode( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStockTool( 
            /* [retval][out] */ IUnknown **ppToolClass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetToolProperties( 
            /* [in] */ IUnknown *pProp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ IUnknown *pXmlElement) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ IUnknown *pXmlElement) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ LONG_PTR lFlag,
            /* [in] */ DWORD_PTR hWnd,
            /* [in] */ DWORD point,
            /* [in] */ DWORD dwKeyState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginEdit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Edit( 
            /* [in] */ IUnknown *pProp,
            /* [in] */ LONG_PTR hWndParent,
            /* [out] */ VARIANT_BOOL *pRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndEdit( 
            /* [in] */ VARIANT_BOOL bEditCancelled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDropTarget( 
            /* [retval][out] */ IUnknown **ppDropTarget) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetContextMenu( 
            /* [in] */ INT_PTR nContextFlag,
            /* [in] */ DWORD_PTR hMenu,
            /* [in] */ UINT idCmdFirst,
            /* [in] */ UINT idCmdLast,
            /* [retval][out] */ DWORD_PTR *pFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCommandString( 
            /* [in] */ UINT idCmd,
            /* [retval][out] */ BSTR *pbstrHelpText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InvokeCommand( 
            /* [in] */ UINT idCmd,
            /* [in] */ DWORD_PTR hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDragDropContextInfo( 
            /* [in] */ IUnknown *pIUnknown,
            /* [out] */ BSTR *pbstrText,
            /* [out] */ DWORD *pFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dropped( 
            /* [in] */ BSTR bstrUrl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refreshed( 
            /* [in] */ BSTR bstrUrl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEditorWindow( 
            /* [in] */ LONG_PTR hWndEditor,
            /* [in] */ IUnknown *pPropInspector) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ValidateEditChanges( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetToolProperties( 
            /* [retval][out] */ IUnknown **pToolProp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginMultipleEdit( 
            /* [in] */ VARIANT tools,
            /* [in] */ VARIANT stockToolIds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndMultipleEdit( 
            /* [in] */ VARIANT tools,
            /* [in] */ VARIANT stockToolIds,
            /* [in] */ VARIANT_BOOL bEditCancelled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MultipleEdit( 
            /* [in] */ VARIANT tools,
            /* [in] */ VARIANT stockToolIds,
            /* [in] */ LONG_PTR hWndParent,
            /* [out] */ VARIANT_BOOL *pRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadTool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadTool * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EditMode )( 
            IZcadTool * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStockTool )( 
            IZcadTool * This,
            /* [retval][out] */ IUnknown **ppToolClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetToolProperties )( 
            IZcadTool * This,
            /* [in] */ IUnknown *pProp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IZcadTool * This,
            /* [in] */ IUnknown *pXmlElement);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IZcadTool * This,
            /* [in] */ IUnknown *pXmlElement);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IZcadTool * This,
            /* [in] */ LONG_PTR lFlag,
            /* [in] */ DWORD_PTR hWnd,
            /* [in] */ DWORD point,
            /* [in] */ DWORD dwKeyState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            IZcadTool * This,
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginEdit )( 
            IZcadTool * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Edit )( 
            IZcadTool * This,
            /* [in] */ IUnknown *pProp,
            /* [in] */ LONG_PTR hWndParent,
            /* [out] */ VARIANT_BOOL *pRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndEdit )( 
            IZcadTool * This,
            /* [in] */ VARIANT_BOOL bEditCancelled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *New )( 
            IZcadTool * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDropTarget )( 
            IZcadTool * This,
            /* [retval][out] */ IUnknown **ppDropTarget);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetContextMenu )( 
            IZcadTool * This,
            /* [in] */ INT_PTR nContextFlag,
            /* [in] */ DWORD_PTR hMenu,
            /* [in] */ UINT idCmdFirst,
            /* [in] */ UINT idCmdLast,
            /* [retval][out] */ DWORD_PTR *pFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCommandString )( 
            IZcadTool * This,
            /* [in] */ UINT idCmd,
            /* [retval][out] */ BSTR *pbstrHelpText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InvokeCommand )( 
            IZcadTool * This,
            /* [in] */ UINT idCmd,
            /* [in] */ DWORD_PTR hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDragDropContextInfo )( 
            IZcadTool * This,
            /* [in] */ IUnknown *pIUnknown,
            /* [out] */ BSTR *pbstrText,
            /* [out] */ DWORD *pFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dropped )( 
            IZcadTool * This,
            /* [in] */ BSTR bstrUrl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refreshed )( 
            IZcadTool * This,
            /* [in] */ BSTR bstrUrl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetEditorWindow )( 
            IZcadTool * This,
            /* [in] */ LONG_PTR hWndEditor,
            /* [in] */ IUnknown *pPropInspector);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ValidateEditChanges )( 
            IZcadTool * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetToolProperties )( 
            IZcadTool * This,
            /* [retval][out] */ IUnknown **pToolProp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginMultipleEdit )( 
            IZcadTool * This,
            /* [in] */ VARIANT tools,
            /* [in] */ VARIANT stockToolIds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndMultipleEdit )( 
            IZcadTool * This,
            /* [in] */ VARIANT tools,
            /* [in] */ VARIANT stockToolIds,
            /* [in] */ VARIANT_BOOL bEditCancelled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MultipleEdit )( 
            IZcadTool * This,
            /* [in] */ VARIANT tools,
            /* [in] */ VARIANT stockToolIds,
            /* [in] */ LONG_PTR hWndParent,
            /* [out] */ VARIANT_BOOL *pRet);
        
        END_INTERFACE
    } IZcadToolVtbl;

    interface IZcadTool
    {
        CONST_VTBL struct IZcadToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadTool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadTool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadTool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadTool_get_EditMode(This,pVal)	\
    (This)->lpVtbl -> get_EditMode(This,pVal)

#define IZcadTool_GetStockTool(This,ppToolClass)	\
    (This)->lpVtbl -> GetStockTool(This,ppToolClass)

#define IZcadTool_SetToolProperties(This,pProp)	\
    (This)->lpVtbl -> SetToolProperties(This,pProp)

#define IZcadTool_Load(This,pXmlElement)	\
    (This)->lpVtbl -> Load(This,pXmlElement)

#define IZcadTool_Save(This,pXmlElement)	\
    (This)->lpVtbl -> Save(This,pXmlElement)

#define IZcadTool_Execute(This,lFlag,hWnd,point,dwKeyState)	\
    (This)->lpVtbl -> Execute(This,lFlag,hWnd,point,dwKeyState)

#define IZcadTool_GetData(This,pObjUnkArray,pDynUnkArray)	\
    (This)->lpVtbl -> GetData(This,pObjUnkArray,pDynUnkArray)

#define IZcadTool_BeginEdit(This)	\
    (This)->lpVtbl -> BeginEdit(This)

#define IZcadTool_Edit(This,pProp,hWndParent,pRet)	\
    (This)->lpVtbl -> Edit(This,pProp,hWndParent,pRet)

#define IZcadTool_EndEdit(This,bEditCancelled)	\
    (This)->lpVtbl -> EndEdit(This,bEditCancelled)

#define IZcadTool_New(This)	\
    (This)->lpVtbl -> New(This)

#define IZcadTool_GetDropTarget(This,ppDropTarget)	\
    (This)->lpVtbl -> GetDropTarget(This,ppDropTarget)

#define IZcadTool_GetContextMenu(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pFlag)	\
    (This)->lpVtbl -> GetContextMenu(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pFlag)

#define IZcadTool_GetCommandString(This,idCmd,pbstrHelpText)	\
    (This)->lpVtbl -> GetCommandString(This,idCmd,pbstrHelpText)

#define IZcadTool_InvokeCommand(This,idCmd,hWnd)	\
    (This)->lpVtbl -> InvokeCommand(This,idCmd,hWnd)

#define IZcadTool_GetDragDropContextInfo(This,pIUnknown,pbstrText,pFlag)	\
    (This)->lpVtbl -> GetDragDropContextInfo(This,pIUnknown,pbstrText,pFlag)

#define IZcadTool_Dropped(This,bstrUrl)	\
    (This)->lpVtbl -> Dropped(This,bstrUrl)

#define IZcadTool_Refreshed(This,bstrUrl)	\
    (This)->lpVtbl -> Refreshed(This,bstrUrl)

#define IZcadTool_SetEditorWindow(This,hWndEditor,pPropInspector)	\
    (This)->lpVtbl -> SetEditorWindow(This,hWndEditor,pPropInspector)

#define IZcadTool_ValidateEditChanges(This)	\
    (This)->lpVtbl -> ValidateEditChanges(This)

#define IZcadTool_GetToolProperties(This,pToolProp)	\
    (This)->lpVtbl -> GetToolProperties(This,pToolProp)

#define IZcadTool_BeginMultipleEdit(This,tools,stockToolIds)	\
    (This)->lpVtbl -> BeginMultipleEdit(This,tools,stockToolIds)

#define IZcadTool_EndMultipleEdit(This,tools,stockToolIds,bEditCancelled)	\
    (This)->lpVtbl -> EndMultipleEdit(This,tools,stockToolIds,bEditCancelled)

#define IZcadTool_MultipleEdit(This,tools,stockToolIds,hWndParent,pRet)	\
    (This)->lpVtbl -> MultipleEdit(This,tools,stockToolIds,hWndParent,pRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZcadTool_get_EditMode_Proxy( 
    IZcadTool * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IZcadTool_get_EditMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetStockTool_Proxy( 
    IZcadTool * This,
    /* [retval][out] */ IUnknown **ppToolClass);


void __RPC_STUB IZcadTool_GetStockTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_SetToolProperties_Proxy( 
    IZcadTool * This,
    /* [in] */ IUnknown *pProp);


void __RPC_STUB IZcadTool_SetToolProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_Load_Proxy( 
    IZcadTool * This,
    /* [in] */ IUnknown *pXmlElement);


void __RPC_STUB IZcadTool_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_Save_Proxy( 
    IZcadTool * This,
    /* [in] */ IUnknown *pXmlElement);


void __RPC_STUB IZcadTool_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_Execute_Proxy( 
    IZcadTool * This,
    /* [in] */ LONG_PTR lFlag,
    /* [in] */ DWORD_PTR hWnd,
    /* [in] */ DWORD point,
    /* [in] */ DWORD dwKeyState);


void __RPC_STUB IZcadTool_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetData_Proxy( 
    IZcadTool * This,
    /* [in] */ VARIANT *pObjUnkArray,
    /* [in] */ VARIANT *pDynUnkArray);


void __RPC_STUB IZcadTool_GetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_BeginEdit_Proxy( 
    IZcadTool * This);


void __RPC_STUB IZcadTool_BeginEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_Edit_Proxy( 
    IZcadTool * This,
    /* [in] */ IUnknown *pProp,
    /* [in] */ LONG_PTR hWndParent,
    /* [out] */ VARIANT_BOOL *pRet);


void __RPC_STUB IZcadTool_Edit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_EndEdit_Proxy( 
    IZcadTool * This,
    /* [in] */ VARIANT_BOOL bEditCancelled);


void __RPC_STUB IZcadTool_EndEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_New_Proxy( 
    IZcadTool * This);


void __RPC_STUB IZcadTool_New_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetDropTarget_Proxy( 
    IZcadTool * This,
    /* [retval][out] */ IUnknown **ppDropTarget);


void __RPC_STUB IZcadTool_GetDropTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetContextMenu_Proxy( 
    IZcadTool * This,
    /* [in] */ INT_PTR nContextFlag,
    /* [in] */ DWORD_PTR hMenu,
    /* [in] */ UINT idCmdFirst,
    /* [in] */ UINT idCmdLast,
    /* [retval][out] */ DWORD_PTR *pFlag);


void __RPC_STUB IZcadTool_GetContextMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetCommandString_Proxy( 
    IZcadTool * This,
    /* [in] */ UINT idCmd,
    /* [retval][out] */ BSTR *pbstrHelpText);


void __RPC_STUB IZcadTool_GetCommandString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_InvokeCommand_Proxy( 
    IZcadTool * This,
    /* [in] */ UINT idCmd,
    /* [in] */ DWORD_PTR hWnd);


void __RPC_STUB IZcadTool_InvokeCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetDragDropContextInfo_Proxy( 
    IZcadTool * This,
    /* [in] */ IUnknown *pIUnknown,
    /* [out] */ BSTR *pbstrText,
    /* [out] */ DWORD *pFlag);


void __RPC_STUB IZcadTool_GetDragDropContextInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_Dropped_Proxy( 
    IZcadTool * This,
    /* [in] */ BSTR bstrUrl);


void __RPC_STUB IZcadTool_Dropped_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_Refreshed_Proxy( 
    IZcadTool * This,
    /* [in] */ BSTR bstrUrl);


void __RPC_STUB IZcadTool_Refreshed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_SetEditorWindow_Proxy( 
    IZcadTool * This,
    /* [in] */ LONG_PTR hWndEditor,
    /* [in] */ IUnknown *pPropInspector);


void __RPC_STUB IZcadTool_SetEditorWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_ValidateEditChanges_Proxy( 
    IZcadTool * This);


void __RPC_STUB IZcadTool_ValidateEditChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_GetToolProperties_Proxy( 
    IZcadTool * This,
    /* [retval][out] */ IUnknown **pToolProp);


void __RPC_STUB IZcadTool_GetToolProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_BeginMultipleEdit_Proxy( 
    IZcadTool * This,
    /* [in] */ VARIANT tools,
    /* [in] */ VARIANT stockToolIds);


void __RPC_STUB IZcadTool_BeginMultipleEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_EndMultipleEdit_Proxy( 
    IZcadTool * This,
    /* [in] */ VARIANT tools,
    /* [in] */ VARIANT stockToolIds,
    /* [in] */ VARIANT_BOOL bEditCancelled);


void __RPC_STUB IZcadTool_EndMultipleEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool_MultipleEdit_Proxy( 
    IZcadTool * This,
    /* [in] */ VARIANT tools,
    /* [in] */ VARIANT stockToolIds,
    /* [in] */ LONG_PTR hWndParent,
    /* [out] */ VARIANT_BOOL *pRet);


void __RPC_STUB IZcadTool_MultipleEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadTool2_INTERFACE_DEFINED__
#define __IZcadTool2_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadTool2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB0E3669-222E-46AB-9DD0-9876E6D052AD")
    IZcadTool2 : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateImage( void) = 0;
        
    };
    
#else 

    typedef struct IZcadTool2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadTool2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadTool2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadTool2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateImage )( 
            IZcadTool2 * This);
        
        END_INTERFACE
    } IZcadTool2Vtbl;

    interface IZcadTool2
    {
        CONST_VTBL struct IZcadTool2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadTool2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadTool2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadTool2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadTool2_UpdateImage(This)	\
    (This)->lpVtbl -> UpdateImage(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadTool2_UpdateImage_Proxy( 
    IZcadTool2 * This);


void __RPC_STUB IZcadTool2_UpdateImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolFlyoutShape_INTERFACE_DEFINED__
#define __IZcadToolFlyoutShape_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadToolFlyoutShape;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F1A2EE9-32C3-489A-A29E-08851FC927DA")
    IZcadToolFlyoutShape : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFlyoutTools( 
            /* [in] */ VARIANT *pFlyoutToolIds) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolFlyoutShapeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolFlyoutShape * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolFlyoutShape * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolFlyoutShape * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFlyoutTools )( 
            IZcadToolFlyoutShape * This,
            /* [in] */ VARIANT *pFlyoutToolIds);
        
        END_INTERFACE
    } IZcadToolFlyoutShapeVtbl;

    interface IZcadToolFlyoutShape
    {
        CONST_VTBL struct IZcadToolFlyoutShapeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolFlyoutShape_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolFlyoutShape_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolFlyoutShape_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolFlyoutShape_SetFlyoutTools(This,pFlyoutToolIds)	\
    (This)->lpVtbl -> SetFlyoutTools(This,pFlyoutToolIds)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolFlyoutShape_SetFlyoutTools_Proxy( 
    IZcadToolFlyoutShape * This,
    /* [in] */ VARIANT *pFlyoutToolIds);


void __RPC_STUB IZcadToolFlyoutShape_SetFlyoutTools_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolSort_INTERFACE_DEFINED__
#define __IZcadToolSort_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadToolSort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF6D759E-0EDD-46DF-9E0B-8DC01A206CF7")
    IZcadToolSort : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Compare( 
            /* [in] */ IUnknown *pTool,
            /* [in] */ long lSortOption,
            /* [retval][out] */ long *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolSortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolSort * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolSort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolSort * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Compare )( 
            IZcadToolSort * This,
            /* [in] */ IUnknown *pTool,
            /* [in] */ long lSortOption,
            /* [retval][out] */ long *pResult);
        
        END_INTERFACE
    } IZcadToolSortVtbl;

    interface IZcadToolSort
    {
        CONST_VTBL struct IZcadToolSortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolSort_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolSort_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolSort_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolSort_Compare(This,pTool,lSortOption,pResult)	\
    (This)->lpVtbl -> Compare(This,pTool,lSortOption,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolSort_Compare_Proxy( 
    IZcadToolSort * This,
    /* [in] */ IUnknown *pTool,
    /* [in] */ long lSortOption,
    /* [retval][out] */ long *pResult);


void __RPC_STUB IZcadToolSort_Compare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolDropTarget_INTERFACE_DEFINED__
#define __IZcadToolDropTarget_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcadToolDropTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76B9A439-B3BF-4346-8001-74EBFAD3113A")
    IZcadToolDropTarget : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragEnter( 
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ DWORD *pdwEffect) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragOver( 
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ DWORD *pdwEffect) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragLeave( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Drop( 
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ DWORD *pdwEffect,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ GUID *pParentId,
            /* [retval][out] */ VARIANT *pNewToolIds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDragDropContextMenuItem( 
            /* [in] */ IUnknown *pIUnknown,
            /* [out] */ BSTR *pbstrText,
            /* [out] */ DWORD *pFlag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolDropTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolDropTarget * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolDropTarget * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolDropTarget * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragEnter )( 
            IZcadToolDropTarget * This,
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ DWORD *pdwEffect);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragOver )( 
            IZcadToolDropTarget * This,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ DWORD *pdwEffect);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragLeave )( 
            IZcadToolDropTarget * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Drop )( 
            IZcadToolDropTarget * This,
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ DWORD *pdwEffect,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ GUID *pParentId,
            /* [retval][out] */ VARIANT *pNewToolIds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDragDropContextMenuItem )( 
            IZcadToolDropTarget * This,
            /* [in] */ IUnknown *pIUnknown,
            /* [out] */ BSTR *pbstrText,
            /* [out] */ DWORD *pFlag);
        
        END_INTERFACE
    } IZcadToolDropTargetVtbl;

    interface IZcadToolDropTarget
    {
        CONST_VTBL struct IZcadToolDropTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolDropTarget_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolDropTarget_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolDropTarget_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolDropTarget_DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)

#define IZcadToolDropTarget_DragOver(This,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> DragOver(This,grfKeyState,pt,pdwEffect)

#define IZcadToolDropTarget_DragLeave(This)	\
    (This)->lpVtbl -> DragLeave(This)

#define IZcadToolDropTarget_Drop(This,pDataObj,grfKeyState,pt,pdwEffect,pCurrentStockToolId,pParentId,pNewToolIds)	\
    (This)->lpVtbl -> Drop(This,pDataObj,grfKeyState,pt,pdwEffect,pCurrentStockToolId,pParentId,pNewToolIds)

#define IZcadToolDropTarget_GetDragDropContextMenuItem(This,pIUnknown,pbstrText,pFlag)	\
    (This)->lpVtbl -> GetDragDropContextMenuItem(This,pIUnknown,pbstrText,pFlag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDropTarget_DragEnter_Proxy( 
    IZcadToolDropTarget * This,
    /* [in] */ IDataObject *pDataObj,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ DWORD *pdwEffect);


void __RPC_STUB IZcadToolDropTarget_DragEnter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDropTarget_DragOver_Proxy( 
    IZcadToolDropTarget * This,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ DWORD *pdwEffect);


void __RPC_STUB IZcadToolDropTarget_DragOver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDropTarget_DragLeave_Proxy( 
    IZcadToolDropTarget * This);


void __RPC_STUB IZcadToolDropTarget_DragLeave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDropTarget_Drop_Proxy( 
    IZcadToolDropTarget * This,
    /* [in] */ IDataObject *pDataObj,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ DWORD *pdwEffect,
    /* [in] */ GUID *pCurrentStockToolId,
    /* [in] */ GUID *pParentId,
    /* [retval][out] */ VARIANT *pNewToolIds);


void __RPC_STUB IZcadToolDropTarget_Drop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDropTarget_GetDragDropContextMenuItem_Proxy( 
    IZcadToolDropTarget * This,
    /* [in] */ IUnknown *pIUnknown,
    /* [out] */ BSTR *pbstrText,
    /* [out] */ DWORD *pFlag);


void __RPC_STUB IZcadToolDropTarget_GetDragDropContextMenuItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolDragSource_INTERFACE_DEFINED__
#define __IZcadToolDragSource_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadToolDragSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8C6D2B1-A430-4949-8F5A-FF3C3533CF00")
    IZcadToolDragSource : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginDrag( 
            /* [in] */ VARIANT *pToolIds,
            /* [in] */ VARIANT *pAllStockToolIds,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD dwKeyState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragInProgress( 
            /* [in] */ DWORD dwDropEffect) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndDrag( 
            /* [in] */ DWORD dwDropEffect) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragEnterDrawing( 
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [retval][out] */ DWORD *pDropEffect) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragOverDrawing( 
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [retval][out] */ DWORD *pDropEffect) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DragLeaveDrawing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DropInDrawing( 
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [retval][out] */ DWORD *pDropEffect) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolDragSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolDragSource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolDragSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolDragSource * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginDrag )( 
            IZcadToolDragSource * This,
            /* [in] */ VARIANT *pToolIds,
            /* [in] */ VARIANT *pAllStockToolIds,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD dwKeyState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragInProgress )( 
            IZcadToolDragSource * This,
            /* [in] */ DWORD dwDropEffect);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndDrag )( 
            IZcadToolDragSource * This,
            /* [in] */ DWORD dwDropEffect);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragEnterDrawing )( 
            IZcadToolDragSource * This,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [retval][out] */ DWORD *pDropEffect);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragOverDrawing )( 
            IZcadToolDragSource * This,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [retval][out] */ DWORD *pDropEffect);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DragLeaveDrawing )( 
            IZcadToolDragSource * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DropInDrawing )( 
            IZcadToolDragSource * This,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [retval][out] */ DWORD *pDropEffect);
        
        END_INTERFACE
    } IZcadToolDragSourceVtbl;

    interface IZcadToolDragSource
    {
        CONST_VTBL struct IZcadToolDragSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolDragSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolDragSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolDragSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolDragSource_BeginDrag(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject,dwKeyState)	\
    (This)->lpVtbl -> BeginDrag(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject,dwKeyState)

#define IZcadToolDragSource_DragInProgress(This,dwDropEffect)	\
    (This)->lpVtbl -> DragInProgress(This,dwDropEffect)

#define IZcadToolDragSource_EndDrag(This,dwDropEffect)	\
    (This)->lpVtbl -> EndDrag(This,dwDropEffect)

#define IZcadToolDragSource_DragEnterDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)	\
    (This)->lpVtbl -> DragEnterDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)

#define IZcadToolDragSource_DragOverDrawing(This,grfKeyState,pt,pDropEffect)	\
    (This)->lpVtbl -> DragOverDrawing(This,grfKeyState,pt,pDropEffect)

#define IZcadToolDragSource_DragLeaveDrawing(This)	\
    (This)->lpVtbl -> DragLeaveDrawing(This)

#define IZcadToolDragSource_DropInDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)	\
    (This)->lpVtbl -> DropInDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_BeginDrag_Proxy( 
    IZcadToolDragSource * This,
    /* [in] */ VARIANT *pToolIds,
    /* [in] */ VARIANT *pAllStockToolIds,
    /* [in] */ GUID *pCurrentStockToolId,
    /* [in] */ IDataObject *pDataObject,
    /* [in] */ DWORD dwKeyState);


void __RPC_STUB IZcadToolDragSource_BeginDrag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_DragInProgress_Proxy( 
    IZcadToolDragSource * This,
    /* [in] */ DWORD dwDropEffect);


void __RPC_STUB IZcadToolDragSource_DragInProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_EndDrag_Proxy( 
    IZcadToolDragSource * This,
    /* [in] */ DWORD dwDropEffect);


void __RPC_STUB IZcadToolDragSource_EndDrag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_DragEnterDrawing_Proxy( 
    IZcadToolDragSource * This,
    /* [in] */ IDataObject *pDataObject,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [retval][out] */ DWORD *pDropEffect);


void __RPC_STUB IZcadToolDragSource_DragEnterDrawing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_DragOverDrawing_Proxy( 
    IZcadToolDragSource * This,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [retval][out] */ DWORD *pDropEffect);


void __RPC_STUB IZcadToolDragSource_DragOverDrawing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_DragLeaveDrawing_Proxy( 
    IZcadToolDragSource * This);


void __RPC_STUB IZcadToolDragSource_DragLeaveDrawing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolDragSource_DropInDrawing_Proxy( 
    IZcadToolDragSource * This,
    /* [in] */ IDataObject *pDataObject,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [retval][out] */ DWORD *pDropEffect);


void __RPC_STUB IZcadToolDragSource_DropInDrawing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolCopyPaste_INTERFACE_DEFINED__
#define __IZcadToolCopyPaste_INTERFACE_DEFINED__



EXTERN_C const IID IID_IZcadToolCopyPaste;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E32FE25-7769-4C8E-9447-DB921D1D249E")
    IZcadToolCopyPaste : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ VARIANT *pToolIds,
            /* [in] */ VARIANT *pAllStockToolIds,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ IDataObject *pDataObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( 
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ GUID *pParentId,
            /* [in] */ IDataObject *pDataObject,
            /* [retval][out] */ VARIANT *pNewToolIds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanPaste( 
            /* [in] */ IDataObject *pDataObject,
            /* [retval][out] */ VARIANT_BOOL *pCanPaste) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolCopyPasteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolCopyPaste * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolCopyPaste * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolCopyPaste * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IZcadToolCopyPaste * This,
            /* [in] */ VARIANT *pToolIds,
            /* [in] */ VARIANT *pAllStockToolIds,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ IDataObject *pDataObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IZcadToolCopyPaste * This,
            /* [in] */ GUID *pCurrentStockToolId,
            /* [in] */ GUID *pParentId,
            /* [in] */ IDataObject *pDataObject,
            /* [retval][out] */ VARIANT *pNewToolIds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanPaste )( 
            IZcadToolCopyPaste * This,
            /* [in] */ IDataObject *pDataObject,
            /* [retval][out] */ VARIANT_BOOL *pCanPaste);
        
        END_INTERFACE
    } IZcadToolCopyPasteVtbl;

    interface IZcadToolCopyPaste
    {
        CONST_VTBL struct IZcadToolCopyPasteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolCopyPaste_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolCopyPaste_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolCopyPaste_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolCopyPaste_Copy(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject)	\
    (This)->lpVtbl -> Copy(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject)

#define IZcadToolCopyPaste_Paste(This,pCurrentStockToolId,pParentId,pDataObject,pNewToolIds)	\
    (This)->lpVtbl -> Paste(This,pCurrentStockToolId,pParentId,pDataObject,pNewToolIds)

#define IZcadToolCopyPaste_CanPaste(This,pDataObject,pCanPaste)	\
    (This)->lpVtbl -> CanPaste(This,pDataObject,pCanPaste)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolCopyPaste_Copy_Proxy( 
    IZcadToolCopyPaste * This,
    /* [in] */ VARIANT *pToolIds,
    /* [in] */ VARIANT *pAllStockToolIds,
    /* [in] */ GUID *pCurrentStockToolId,
    /* [in] */ IDataObject *pDataObject);


void __RPC_STUB IZcadToolCopyPaste_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolCopyPaste_Paste_Proxy( 
    IZcadToolCopyPaste * This,
    /* [in] */ GUID *pCurrentStockToolId,
    /* [in] */ GUID *pParentId,
    /* [in] */ IDataObject *pDataObject,
    /* [retval][out] */ VARIANT *pNewToolIds);


void __RPC_STUB IZcadToolCopyPaste_Paste_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolCopyPaste_CanPaste_Proxy( 
    IZcadToolCopyPaste * This,
    /* [in] */ IDataObject *pDataObject,
    /* [retval][out] */ VARIANT_BOOL *pCanPaste);


void __RPC_STUB IZcadToolCopyPaste_CanPaste_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	


#ifndef __IZcadToolImage_INTERFACE_DEFINED__
#define __IZcadToolImage_INTERFACE_DEFINED__




EXTERN_C const IID IID_IZcadToolImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("74009B5D-217A-44B6-8271-3A439851EAB5")
    IZcadToolImage : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR bsFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR bsFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Render( 
            /* [in] */ HDC hdc,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long cx,
            /* [in] */ long cy,
            /* [in] */ long nStyle,
            /* [in] */ VARIANT_BOOL bTransparentBitmap) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long *pWidth,
            /* [out] */ long *pHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ short *pType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsImageLoaded( 
            /* [out] */ BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcadToolImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolImage * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IZcadToolImage * This,
            /* [in] */ BSTR bsFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IZcadToolImage * This,
            /* [in] */ BSTR bsFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            IZcadToolImage * This,
            /* [in] */ HDC hdc,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long cx,
            /* [in] */ long cy,
            /* [in] */ long nStyle,
            /* [in] */ VARIANT_BOOL bTransparentBitmap);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IZcadToolImage * This,
            /* [out] */ long *pWidth,
            /* [out] */ long *pHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IZcadToolImage * This,
            /* [out] */ short *pType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsImageLoaded )( 
            IZcadToolImage * This,
            /* [out] */ BOOL *pVal);
        
        END_INTERFACE
    } IZcadToolImageVtbl;

    interface IZcadToolImage
    {
        CONST_VTBL struct IZcadToolImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolImage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcadToolImage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcadToolImage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcadToolImage_Load(This,bsFileName)	\
    (This)->lpVtbl -> Load(This,bsFileName)

#define IZcadToolImage_Save(This,bsFileName)	\
    (This)->lpVtbl -> Save(This,bsFileName)

#define IZcadToolImage_Render(This,hdc,x,y,cx,cy,nStyle,bTransparentBitmap)	\
    (This)->lpVtbl -> Render(This,hdc,x,y,cx,cy,nStyle,bTransparentBitmap)

#define IZcadToolImage_GetSize(This,pWidth,pHeight)	\
    (This)->lpVtbl -> GetSize(This,pWidth,pHeight)

#define IZcadToolImage_GetType(This,pType)	\
    (This)->lpVtbl -> GetType(This,pType)

#define IZcadToolImage_IsImageLoaded(This,pVal)	\
    (This)->lpVtbl -> IsImageLoaded(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolImage_Load_Proxy( 
    IZcadToolImage * This,
    /* [in] */ BSTR bsFileName);


void __RPC_STUB IZcadToolImage_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolImage_Save_Proxy( 
    IZcadToolImage * This,
    /* [in] */ BSTR bsFileName);


void __RPC_STUB IZcadToolImage_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolImage_Render_Proxy( 
    IZcadToolImage * This,
    /* [in] */ HDC hdc,
    /* [in] */ long x,
    /* [in] */ long y,
    /* [in] */ long cx,
    /* [in] */ long cy,
    /* [in] */ long nStyle,
    /* [in] */ VARIANT_BOOL bTransparentBitmap);


void __RPC_STUB IZcadToolImage_Render_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolImage_GetSize_Proxy( 
    IZcadToolImage * This,
    /* [out] */ long *pWidth,
    /* [out] */ long *pHeight);


void __RPC_STUB IZcadToolImage_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolImage_GetType_Proxy( 
    IZcadToolImage * This,
    /* [out] */ short *pType);


void __RPC_STUB IZcadToolImage_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcadToolImage_IsImageLoaded_Proxy( 
    IZcadToolImage * This,
    /* [out] */ BOOL *pVal);


void __RPC_STUB IZcadToolImage_IsImageLoaded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcadToolImage_INTERFACE_DEFINED__ */



#ifndef __ZcTcLib_LIBRARY_DEFINED__
#define __ZcTcLib_LIBRARY_DEFINED__

/* library ZcTcLib */
/* [helpstring][custom][version][uuid] */ 


EXTERN_C const IID LIBID_ZcTcLib;

EXTERN_C const CLSID CLSID_AcadToolProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("8C7C7AB1-0466-4FEB-B15A-5DF69318A043")
AcadToolProperties;
#endif

EXTERN_C const CLSID CLSID_AcadToolImage;

#ifdef __cplusplus

class DECLSPEC_UUID("79DC18B6-B07B-4559-BFB9-3DD88D9E8A5A")
AcadToolImage;
#endif
#endif /* __ZcTcLib_LIBRARY_DEFINED__ */

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


