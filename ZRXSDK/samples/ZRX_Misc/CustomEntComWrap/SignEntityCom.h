// SignEntityCom.h : 

#pragma once
#include "resource.h"      
#include "CustomEntComWrap.h"
#include "zaxtempl.h"
#include "zcategory.h"

#define DISPID_RADIUS      0x01
#define DISPID_CENTER      0x02


// CSignEntityCom

class ATL_NO_VTABLE CSignEntityCom : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSignEntityCom, &CLSID_SignEntityCom>,
	public ISupportErrorInfo,
	public IOPMPropertyExtensionImpl<CSignEntityCom>,
	public IOPMPropertyExpander,
	public IZcadEntityDispatchImpl<CSignEntityCom, &CLSID_SignEntityCom, ISignEntityCom, &IID_ISignEntityCom, &LIBID_CustomEntComWrapLib>
{
public:
	CSignEntityCom()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_SIGNENTITYCOM)


	BEGIN_COM_MAP(CSignEntityCom)
		COM_INTERFACE_ENTRY(ISignEntityCom)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IOPMPropertyExtension)
		COM_INTERFACE_ENTRY(ICategorizeProperties)
		COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
		COM_INTERFACE_ENTRY(IOPMPropertyExpander)
		COM_INTERFACE_ENTRY(IZcadBaseObject)
		COM_INTERFACE_ENTRY(IZcadBaseObject2)
		COM_INTERFACE_ENTRY(IZcadObject)
		COM_INTERFACE_ENTRY(IZcadEntity)
		COM_INTERFACE_ENTRY(IRetrieveApplication)
	END_COM_MAP()

	//----- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease() 
	{
	}

	//IZcadBaseObjectImpl
	virtual HRESULT CreateNewObject (ZcDbObjectId &objId, ZcDbObjectId &ownerId, TCHAR *keyName);
	STDMETHOD(ForceDbResident)(VARIANT_BOOL *forceDbResident) ;
	STDMETHOD(CreateObject)(ZcDbObjectId ownerId =ZcDbObjectId::kNull, TCHAR *keyName =NULL);
	STDMETHOD(AddToDb)(ZcDbObjectId &objId, ZcDbObjectId ownerId =ZcDbObjectId::kNull, TCHAR *keyName =NULL);

	//IOPMPropertyExtension
	BEGIN_OPMPROP_MAP()
		//----- Use the OPMPROP_ENTRY/OPMPROP_CAT_ENTRY mzcros for ezch of your properties
		OPMPROP_ENTRY(0, 0x00000001, PROPCAT_Geometry, \
		0, 0, 0, "", 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, 0x00000002, PROPCAT_Data, \
		0, 0, 0, "", 0, 1, IID_NULL, IID_NULL, "")

	END_OPMPROP_MAP()
	//IOPMPropertyExtensionImpl
	virtual HINSTANCE GetResourceInstance () 
	{ 
		return  _AtlBaseModule.GetResourceInstance();
		//return (_hdllInstance);
	}

	//IOPMPropertyExpander
	STDMETHOD(GetElementValue)(/*[in]*/DISPID dispID, /*[in]*/DWORD dwCookie, /*[out]*/VARIANT *pVarOut);
	STDMETHOD(SetElementValue)(/*[in]*/DISPID dispID, /*[in]*/DWORD dwCookie, /*[in]*/VARIANT VarIn);
	STDMETHOD(GetElementStrings)(/*[in]*/DISPID dispID, /*[out]*/OPMLPOLESTR __RPC_FAR *pCaStringsOut, /*[out]*/OPMDWORD __RPC_FAR *pCaCookiesOut);
	STDMETHOD(GetElementGrouping)(/*[in]*/DISPID dispID, /*[out]*/short *groupingNumber);
	STDMETHOD(GetGroupCount)(/*[in]*/DISPID dispID, /*[out]*/long *nGroupCnt);

public:

	STDMETHOD(get_Radius)(DOUBLE* pVal);
	STDMETHOD(put_Radius)(DOUBLE newVal);
	STDMETHOD(get_Center)(VARIANT* pVal);
	STDMETHOD(put_Center)(VARIANT newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(SignEntityCom), CSignEntityCom)