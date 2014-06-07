
#ifndef _ZOPMEXT_H
#define _ZOPMEXT_H
#pragma pack (push, 8)

typedef struct  tagOPMLPOLESTR
    {
    ULONG cElems;
     LPOLESTR __RPC_FAR *pElems;
    }	OPMLPOLESTR;

typedef struct tagOPMLPOLESTR __RPC_FAR *LPOPMLPOLESTR;

typedef struct  tagOPMDWORD
    {
    ULONG cElems;
    DWORD __RPC_FAR *pElems;
    }	OPMDWORD;

typedef struct tagOPMDWORD __RPC_FAR *LPOPMDWORD;


DEFINE_GUID(IID_IOPMPropertyExtension, 
0x8061e55c, 0xa46f, 0x45b7, 0x92, 0x6f, 0x9c, 0x98, 0x89, 0xc3, 0xe5, 0x68);
  
interface DECLSPEC_UUID("8061E55C-A46F-45b7-926F-9C9889C3E568") IOPMPropertyExtension : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    
    virtual HRESULT STDMETHODCALLTYPE GetDisplayName(
        /* [in] */ DISPID dispID,
		/* [out] */ BSTR * propName) = 0;

   
	virtual HRESULT STDMETHODCALLTYPE Editable( 
		/* [in] */ DISPID dispID,
		/* [out] */ BOOL __RPC_FAR *bEditable) = 0;

  
	virtual HRESULT STDMETHODCALLTYPE ShowProperty(
		/* [in] */ DISPID dispID, 
		/* [out] */ BOOL *pShow) = 0;
};



DEFINE_GUID(IID_IOPMPropertyExpander, 
0x82c2be5d, 0x1187, 0x40dc, 0xa4, 0xee, 0xaa, 0x6c, 0xea, 0xd4, 0x3a, 0xe5);

interface DECLSPEC_UUID("82C2BE5D-1187-40dc-A4EE-AA6CEAD43AE5") IOPMPropertyExpander : public IUnknown
{
  
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    
	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
		/* [in] */ DISPID dispID,
		/* [in] */ DWORD dwCookie,
		/* [out] */ VARIANT * pVarOut) = 0;

   
	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
		/* [in] */ DISPID dispID,
		/* [in] */ DWORD dwCookie,
		/* [in] */ VARIANT VarIn) = 0;       

    
	virtual HRESULT STDMETHODCALLTYPE GetElementStrings( 
		/* [in] */ DISPID dispID,
		/* [out] */ OPMLPOLESTR __RPC_FAR *pCaStringsOut,
		/* [out] */ OPMDWORD __RPC_FAR *pCaCookiesOut) = 0;

    
    virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
        /* [in] */ DISPID dispID,
		/* [out] */ short *groupingNumber) = 0;

    
    virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
        /* [in] */ DISPID dispID,
		/* [out] */ long *nGroupCnt) = 0;
};


DEFINE_GUID(IID_IOPMPropertyExpander2, 
0x6da25685, 0xa698, 0x4a96, 0xae, 0x86, 0x1b, 0x3, 0x6a, 0x87, 0xc7, 0x3);

interface DECLSPEC_UUID("6DA25685-A698-4a96-AE86-1B036A87C703") IOPMPropertyExpander2 : public IUnknown
{
   
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

   
	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
		/* [in] */ DISPID dispID,
		/* [in] */ IUnknown * pUnk,
		/* [in] */ DWORD dwCookie,
		/* [out] */ VARIANT * pVarOut) = 0;

    
	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
		/* [in] */ DISPID dispID,
		/* [in] */ IUnknown * pUnk,
		/* [in] */ DWORD dwCookie,
		/* [in] */ VARIANT VarIn) = 0;       

    
	virtual HRESULT STDMETHODCALLTYPE GetElementStrings( 
		/* [in] */ DISPID dispID,
		/* [in] */ IUnknown * pUnk,
		/* [out] */ OPMLPOLESTR __RPC_FAR *pCaStringsOut,
		/* [out] */ OPMDWORD __RPC_FAR *pCaCookiesOut) = 0;

    
    virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
        /* [in] */ DISPID dispID,
		/* [in] */ IUnknown * pUnk,
		/* [out] */ short *groupingNumber) = 0;

    
    virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
        /* [in] */ DISPID dispID,
		/* [in] */ IUnknown * pUnk,
		/* [out] */ long *nGroupCnt) = 0;
};

#pragma pack (pop)
#endif 

