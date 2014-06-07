
#ifndef _ZOPMDRVR_H
#define _ZOPMDRVR_H


HRESULT AXAUTOEXP ZcOpmMapPropertyToCategory(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispid, PROPCAT* ppropcat);
HRESULT AXAUTOEXP ZcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, ZCAD_OPMPROPMAP_ENTRY* pMap, PROPCAT propcat, LCID lcid, BSTR* pbstrName);

HRESULT AXAUTOEXP ZcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrName);
HRESULT AXAUTOEXP ZcOpmGetCategoryCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CATCMDBTN_VECTOR & arr, PROPCAT propcat, VARIANT *pCatCmdBtns);
HRESULT AXAUTOEXP ZcOpmGetParentCategory(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, PROPCAT *pParentCatID);
HRESULT AXAUTOEXP ZcOpmGetCategoryWeight(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, long *pCategoryWeight);
HRESULT AXAUTOEXP ZcOpmGetCategoryDescription(IUnknown *pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrDesc);


HRESULT AXAUTOEXP ZcOpmGetDisplayString(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT AXAUTOEXP ZcOpmMapPropertyToPage(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CLSID *pClsid);
HRESULT AXAUTOEXP ZcOpmGetPredefinedStrings(IUnknown* pUnk, HINSTANCE hResInstance, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut);
HRESULT AXAUTOEXP ZcOpmGetPredefinedValue(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, DWORD dwCookie, VARIANT *pVarOut);
 

HRESULT AXAUTOEXP ZcOpmGetDisplayName(IUnknown* pUnk, HINSTANCE hResInstance, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT AXAUTOEXP ZcOpmEditable(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL __RPC_FAR *bEditable);
HRESULT AXAUTOEXP ZcOpmShowProperty(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL *pShow);


HRESULT AXAUTOEXP ZcOpmGetPropertyWeight(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, long *pPropertyWeight);
HRESULT AXAUTOEXP ZcOpmIsPropFullView(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight);
HRESULT AXAUTOEXP ZcOpmGetPropTextColor(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, OLE_COLOR *pTextColor);
HRESULT AXAUTOEXP ZcOpmGetPropertyIcon(IUnknown *pUnk, HINSTANCE hResInstance, PROP_DISP_VECTOR & arr, VARIANT Id, IUnknown **ppIcon);
HRESULT AXAUTOEXP ZcOpmGetCustomPropertyCtrl(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, LCID lcid, BSTR *psProdId);


HRESULT AXAUTOEXP ZcOpmGetCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CMDBTN_VECTOR & arr, VARIANT *pCmdBtns);

#endif 
