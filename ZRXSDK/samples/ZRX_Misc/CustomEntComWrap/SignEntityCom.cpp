// SignEntityCom.cpp :Implementation of CSignEntityCom 

#include "stdafx.h"
#include "SignEntityCom.h"
#include "zaxpnt3d.h"
#include "zaxlock.h"
#include "zxdb_i.c"
#include "..\SignEntityDb\SignEntity.h"

//-----------------------------------------------------------------------------
STDMETHODIMP CSignEntityCom::InterfaceSupportsErrorInfo (REFIID riid)
{
	static const IID * arr [] =
	{
		&IID_ISignEntityCom
	} ;

	for ( int i =0 ; i < sizeof (arr) / sizeof (arr [0]) ; i++ )
	{
		if ( InlineIsEqualGUID (*arr [i], riid) )
			return (S_OK) ;
	}

	return (S_FALSE) ;
}

//-----------------------------------------------------------------------------
//IZcadBaseObjectImpl
HRESULT CSignEntityCom::CreateNewObject (ZcDbObjectId &objId, ZcDbObjectId &ownerId, TCHAR *keyName) 
{
	try 
	{
		HRESULT hr ;
		if ( FAILED(hr =CreateObject (ownerId, keyName)) )
			throw hr ;
		if ( FAILED(hr =AddToDb (objId, ownerId, keyName)) )
			throw hr ;
	} 
	catch( HRESULT hr ) 
	{
		return (hr) ;
	}
	return (S_OK) ;
}

//-----------------------------------------------------------------------------
//IZcadBaseObject2Impl
STDMETHODIMP CSignEntityCom::ForceDbResident (VARIANT_BOOL *forceDbResident) 
{
	if ( forceDbResident == NULL )
		return (E_POINTER) ;
	//----- Return ACAX_VARIANT_TRUE if the object must be database resident to be functional
	*forceDbResident =ZCAX_VARIANT_FALSE ;
	return (S_OK) ;
}

STDMETHODIMP CSignEntityCom::CreateObject (ZcDbObjectId ownerId /*=ZcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/) 
{
	try 
	{
		Zcad::ErrorStatus es ;
		ZcDbObjectPointer<SignEntity> obj ;
		if ( (es =obj.create ()) != Zcad::eOk )
			throw es ;

		SignEntity *pTmp =NULL ;
		obj.release (pTmp) ;

		SetObject ((ZcDbObject *&)pTmp) ;
	}
	catch ( const Zcad::ErrorStatus )
	{
		return (Error (L"Failed to create SignEntity", IID_ISignEntityCom, E_FAIL)) ;
	}
	return (S_OK) ;
}

STDMETHODIMP CSignEntityCom::AddToDb (ZcDbObjectId &objId, ZcDbObjectId ownerId /*=ZcDbObjectId::kNull*/, TCHAR *keyName /*=NULL*/)
{
	try
	{
		//ZcAxDocLock docLock (ownerId) ;

		Zcad::ErrorStatus es ;
		ZcAxObjectRefPtr<SignEntity> obj (&m_objRef, ZcDb::kForRead) ;

		//----- Non-entities cannot be owned by block table record, but are
		//----- usually owned by dictionaries. If this is not your case, please
		//----- change the code below.
		ZcDbDictionaryPointer pDictionary (ownerId, ZcDb::kForWrite, true) ;
		if ( (es =pDictionary.openStatus ()) != Zcad::eOk )
			throw es ;

		if ( (es =pDictionary->setAt (keyName, obj.object (), objId)) != Zcad::eOk )
			throw es ;
	}
	catch( const Zcad::ErrorStatus ) 
	{
		return (Error(L"Failed to add SignEntity to database", IID_ISignEntityCom, E_FAIL)) ;
	}
	return (SetObjectId (objId)) ;
}

//IOPMPropertyExpander
STDMETHODIMP CSignEntityCom::GetElementValue (DISPID dispID, DWORD dwCookie, VARIANT *pVarOut)
{
	if ( pVarOut == NULL )
		return (E_POINTER) ;
	//----- Add your code here.
	ZcAxObjectRefPtr<SignEntity> pSq(&m_objRef, ZcDb::kForRead);
	if (pSq.openStatus() != Zcad::eOk)
		return E_ACCESSDENIED;          

	if (dispID == DISPID_CENTER) 
	{
		ZcGePoint3d zcgePt;
		pSq->getCenter(zcgePt);
		ZcAxPoint3d zcaxPt(zcgePt);

		::VariantCopy(pVarOut,&CComVariant(zcaxPt[dwCookie]));
	}
	if (dispID == DISPID_RADIUS) 
	{
		double radius = 0;
		pSq->getRadius(radius);
		::VariantCopy(pVarOut,&CComVariant((&radius)[dwCookie]));
	}


	return (S_OK) ; //----- If you do anything in there 
	//return (E_NOTIMPL) ;
}

STDMETHODIMP CSignEntityCom::SetElementValue (DISPID dispID, DWORD dwCookie, VARIANT VarIn) 
{
	//----- Add your code here.

	//ZcAxDocLock docLock(m_objRef.objectId(), ZcAxDocLock::kNormal);
	//if(docLock.lockStatus() != Zcad::eOk && docLock.lockStatus() != Zcad::eNoDatabase)
	//	return E_ACCESSDENIED;

	ZcAxObjectRefPtr<SignEntity> pSq(&m_objRef, ZcDb::kForRead);
	if (pSq.openStatus() != Zcad::eOk)
		return E_ACCESSDENIED;          

	if (dispID == DISPID_CENTER) 
	{
		ZcGePoint3d zcgePt;
		pSq->getCenter(zcgePt);
		ZcAxPoint3d zcaxPt(zcgePt);

		zcaxPt[dwCookie] = V_R8(&VarIn);
		pSq->upgradeOpen();
		pSq->setCenter(zcaxPt);
		Fire_Notification(DISPID_CENTER);
	}
	if (dispID == DISPID_RADIUS) 
	{
		double radius;
		pSq->getRadius(radius);

		(&radius)[dwCookie] = V_R8(&VarIn);
		pSq->upgradeOpen();
		pSq->setRadius(radius);
		Fire_Notification(DISPID_RADIUS);
	}

	return (S_OK) ; //----- If you do anything in there 
	//return (E_NOTIMPL) ;
}

STDMETHODIMP CSignEntityCom::GetElementStrings (DISPID dispID, OPMLPOLESTR __RPC_FAR *pCaStringsOut, OPMDWORD __RPC_FAR *pCaCookiesOut)
{
	if ( pCaStringsOut == NULL || pCaCookiesOut == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	if (dispID == DISPID_CENTER)
	{
		long size;
		size = 3;
		pCaStringsOut->pElems = (LPOLESTR *)::CoTaskMemAlloc(sizeof(LPOLESTR) * size);
		pCaCookiesOut->pElems = (DWORD *)::CoTaskMemAlloc(sizeof(DWORD) * size);
		for (long i=0;i<size;i++)
			pCaCookiesOut->pElems[i] = i;

		pCaStringsOut->cElems = size;
		pCaCookiesOut->cElems = size;

		pCaStringsOut->pElems[0] = ::SysAllocString(L"Center Point X");
		pCaStringsOut->pElems[1] = ::SysAllocString(L"Center Point Y");
		pCaStringsOut->pElems[2] = ::SysAllocString(L"Center Point Z");
	}
	if (dispID == DISPID_RADIUS)
	{
		pCaStringsOut->pElems = (LPOLESTR *)::CoTaskMemAlloc(sizeof(LPOLESTR));
		pCaCookiesOut->pElems = (DWORD *)::CoTaskMemAlloc(sizeof(DWORD));
		pCaCookiesOut->pElems[0] = 0;
		pCaStringsOut->cElems = 1;
		pCaCookiesOut->cElems = 1;
		pCaStringsOut->pElems[0] = ::SysAllocString(L"Radius R");
	}

	return (S_OK) ; //----- If you do anything in there 
	//return (E_NOTIMPL) ;
}

STDMETHODIMP CSignEntityCom::GetElementGrouping (DISPID dispID, short *groupingNumber) 
{
	if ( groupingNumber == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CSignEntityCom::GetGroupCount (DISPID dispID, long *nGroupCnt) 
{
	if ( nGroupCnt == NULL )
		return (E_POINTER) ;
	//----- Add your code here.

	//return (S_OK) ; //----- If you do anything in there 
	return (E_NOTIMPL) ;
}

STDMETHODIMP CSignEntityCom::get_Radius(DOUBLE* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 
	ZcAxObjectRefPtr<SignEntity> pSq(&m_objRef, ZcDb::kForRead);
	if (pSq.openStatus() != Zcad::eOk)
		return E_ACCESSDENIED;          

	double radius;
	pSq->getRadius(radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CSignEntityCom::put_Radius(DOUBLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 
	//ZcAxDocLock docLock(m_objRef.objectId(), ZcAxDocLock::kNormal);
	//if(docLock.lockStatus() != Zcad::eOk && docLock.lockStatus() != Zcad::eNoDatabase)
	//	return E_ACCESSDENIED;

	double radius = newVal;

	ZcAxObjectRefPtr<SignEntity> pSq(&m_objRef, ZcDb::kForWrite, Zdesk::kTrue);
	if (pSq.openStatus() != Zcad::eOk)
		return E_ACCESSDENIED;          

	pSq->setRadius(radius);
	Fire_Notification(DISPID_RADIUS);

	return S_OK;
}

STDMETHODIMP CSignEntityCom::get_Center(VARIANT* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:
	ZcAxObjectRefPtr<SignEntity> pSq(&m_objRef, ZcDb::kForRead);
	if (pSq.openStatus() != Zcad::eOk)
		return E_ACCESSDENIED;          

	ZcAxPoint3d pt;
	pSq->getCenter(pt);

	pt.setVariant(pVal);

	return S_OK;
}

STDMETHODIMP CSignEntityCom::put_Center(VARIANT newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 
	//ZcAxDocLock docLock(m_objRef.objectId(), ZcAxDocLock::kNormal);
	//if(docLock.lockStatus() != Zcad::eOk && docLock.lockStatus() != Zcad::eNoDatabase)
	//	return E_ACCESSDENIED;

	ZcAxPoint3d pt = newVal;

	ZcAxObjectRefPtr<SignEntity> pSq(&m_objRef, ZcDb::kForWrite, Zdesk::kTrue);
	if (pSq.openStatus() != Zcad::eOk)
		return E_ACCESSDENIED;          

	pSq->setCenter(pt);
	Fire_Notification(DISPID_CENTER);

	return S_OK;
}
