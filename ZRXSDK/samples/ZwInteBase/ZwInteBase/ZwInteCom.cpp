// ZwInteCom.cpp : Implementation of CZwInteCom

#include "stdafx.h"
#include "ZwInteCom.h"
#include "ZwInteApi.h"
#include "comutil.h"

// CZwInteCom

STDMETHODIMP CZwInteCom::ReadTbData(BSTR titleDef, BSTR bomDef, BSTR dwgPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strTitleDef = _com_util::ConvertBSTRToString(titleDef);
	CString strBomDef = _com_util::ConvertBSTRToString(bomDef);
	CString strDwgPath = _com_util::ConvertBSTRToString(dwgPath);

	if (!ZwReadTBData(strTitleDef,strBomDef,strDwgPath))
	{
		return S_FALSE;
	} 

	return S_OK;
}

STDMETHODIMP CZwInteCom::WriteTbData(BSTR titleData, BSTR bomData, BSTR dwgPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strTitleData = _com_util::ConvertBSTRToString(titleData);
	CString strBomData = _com_util::ConvertBSTRToString(bomData);
	CString strDwgPath = _com_util::ConvertBSTRToString(dwgPath);

	if (!ZwWriteTBData(strTitleData,strBomData,strDwgPath))
	{
		return S_FALSE;
	} 

	return S_OK;
}

STDMETHODIMP CZwInteCom::ReadTbDataX(BSTR inputXmlPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strXmlPath = _com_util::ConvertBSTRToString(inputXmlPath);
	if (!ZwReadTBDataX(strXmlPath))
	{
		return S_FALSE;
	} 

	return S_OK;
}

STDMETHODIMP CZwInteCom::WriteTbDataX(BSTR inputXmlPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strXmlPath = _com_util::ConvertBSTRToString(inputXmlPath);
	if (!ZwWriteTBDataX(strXmlPath))
	{
		return S_FALSE;
	} 

	return S_OK;
}

STDMETHODIMP CZwInteCom::InsertText(BSTR strToDwg, BSTR strTextConts)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strDwgPath = _com_util::ConvertBSTRToString(strToDwg);
	CString strInsText = _com_util::ConvertBSTRToString(strTextConts);
	if (!ZwInsertTextToFile(strDwgPath, strInsText))
	{
		return S_FALSE;
	} 

	return S_OK;
}

STDMETHODIMP CZwInteCom::InsertBmp(BSTR strToDwg, BSTR strDefConts)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strDwgPath = _com_util::ConvertBSTRToString(strToDwg);
	CString strInsConts = _com_util::ConvertBSTRToString(strDefConts);
	if (!ZwInsertBmpToFile(strDwgPath, strInsConts))
	{
		return S_FALSE;
	} 

	return S_OK;
}

STDMETHODIMP CZwInteCom::InsertDwg(BSTR strToDwg, BSTR strDefConts)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strDwgPath = _com_util::ConvertBSTRToString(strToDwg);
	CString strInsConts = _com_util::ConvertBSTRToString(strDefConts);
	if (!ZwInsertDwgToFile(strDwgPath, strInsConts))
	{
		return S_FALSE;
	} 

	return S_OK;
}
