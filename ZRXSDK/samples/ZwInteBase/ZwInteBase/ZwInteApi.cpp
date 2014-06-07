#include "StdAfx.h"
#include "HDataTable.h"
#include "ZwInteFuncts.h"
#include "ZwInteAppSvr.h"
#include "ZwInteAPI.h"
#include <math.h>

#import "msxml6.dll"


BOOL ZwReadTBData(LPCTSTR strTitleDef, LPCTSTR strBomDef, LPCTSTR strDwgPath)
{
	ZwInteAppSvr theAppSrv(strDwgPath);
	theAppSrv.initializeTitle(strTitleDef);
	theAppSrv.initializeBom(strBomDef);
	TitleArray*	pBtlArray = theAppSrv.getTitleData();	//the set of title data 
	HDataTable*	pMxbTbl   = theAppSrv.getBomData();		//the set of bom data
	CString strDwgFilePath = theAppSrv.getDwgPath();
	CoInitialize(NULL); 

	HRESULT hr;
	IXMLDOMDocumentPtr	xmlDocPtr;
	IXMLDOMElementPtr globeNode;
	IXMLDOMElementPtr partlistNode;
	IXMLDOMElementPtr partlistSunNode;
	IXMLDOMElementPtr listNode;
	IXMLDOMElementPtr structureNode;
	HRESULT res= xmlDocPtr.CreateInstance("Msxml2.DOMDocument");
	if(xmlDocPtr==NULL)	return false;
	
	//root(0)
	IXMLDOMElementPtr rootElem;
	hr = xmlDocPtr->createElement(_bstr_t("root"),&rootElem);
	IXMLDOMNodePtr pOutNewNode;
	xmlDocPtr->appendChild(rootElem,&pOutNewNode);
	
	//file_list(1)
	IXMLDOMElementPtr fileListElem;
	hr = xmlDocPtr->createElement(_bstr_t("file_list"),&fileListElem);
	rootElem->appendChild(fileListElem,&pOutNewNode);
	
	//file_item(2)
	IXMLDOMElementPtr fileItemElem;
	hr = xmlDocPtr->createElement(_bstr_t("file_Item"),&fileItemElem);
	fileItemElem->setAttribute(_bstr_t("path"),_variant_t(strDwgFilePath));
	fileListElem->appendChild(fileItemElem,&pOutNewNode);

	//title_info(3)
	IXMLDOMElementPtr titleInfoElem;
	hr = xmlDocPtr->createElement(_bstr_t("title_info"),&titleInfoElem);
	fileItemElem->appendChild(titleInfoElem,&pOutNewNode);

	IXMLDOMElementPtr btlElem;
	hr = xmlDocPtr->createElement(_bstr_t("attr"),&btlElem);
	for(int i=0; i<pBtlArray->GetCount(); i++)
	{
		ZcString strTag = pBtlArray->GetAt(i).strTag;
		ZcString strVal= pBtlArray->GetAt(i).strVal;
		btlElem->setAttribute((_bstr_t)(const char *)strTag,(_variant_t)(const char *)strVal);
	}
	titleInfoElem->appendChild(btlElem,&pOutNewNode);	

	//bom_info(4)
	IXMLDOMElementPtr bomInfoElem;
	hr = xmlDocPtr->createElement(_bstr_t("bom_info"),&bomInfoElem);
	fileItemElem->appendChild(bomInfoElem,&pOutNewNode);
	
	for( int i=0; i<pMxbTbl->GetRowNum(); i++ )
	{
		IXMLDOMElementPtr partElem;
		hr = xmlDocPtr->createElement(_bstr_t("part"),&partElem);
		for(int j=0; j<pMxbTbl->GetColNum(); j++)
		{
			CString strTag = pMxbTbl->GetColNameAt(j);
			CString strVal = pMxbTbl->GetTextAt(i,j);
			partElem->setAttribute((_bstr_t)strTag,(_variant_t)strVal);
		}
		bomInfoElem->appendChild(partElem,&pOutNewNode);

	}

	CString strXmlName = strDwgFilePath;
	strXmlName = strXmlName.Mid(0, strXmlName.GetLength()-4);
	strXmlName += "_Result.xml";
	xmlDocPtr->save((_variant_t)strXmlName);

	CoUninitialize(); 

	return TRUE;
}


BOOL ZwWriteTBData(LPCTSTR strTitleConts, LPCTSTR strBomConts, LPCTSTR strDwgPath)
{
	ZwInteAppSvr theAppSvr(strDwgPath, true);
	theAppSvr.initializeTitle(strTitleConts);
	theAppSvr.initializeBom(strBomConts);
	theAppSvr.setTitleData();
	theAppSvr.setBomData();
	theAppSvr.save();
	
	return TRUE;
}



BOOL  ZwInsertBmpToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef, bool IsPaperSpace)
{
	return InsertBmpToFile(strDwgPath, strTitleDef, IsPaperSpace);
}

BOOL  ZwInsertTextToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef, bool IsPaperSpace)
{
	return InsertTextToFile(strDwgPath, strTitleDef, IsPaperSpace);
}

BOOL  ZwInsertDwgToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef,bool IsPaperSpace )
{
	return InsertDwgToFile(strDwgPath, strTitleDef, IsPaperSpace);
}

BOOL ZwReadTBDataX(LPCTSTR strInputXml)
{
	CoInitialize(NULL); 

	CStringArray arrDwgPathArr;
	IXMLDOMDocumentPtr	pInputDocPtr;		
	HRESULT res= pInputDocPtr.CreateInstance("Msxml2.DOMDocument");

	VARIANT_BOOL bIsSuccessful;
	BOOL bRt = pInputDocPtr->load((_variant_t)strInputXml, &bIsSuccessful);
	
	IXMLDOMNodePtr pRootElement;
	pInputDocPtr->selectSingleNode(_bstr_t("root"), &pRootElement);
	IXMLDOMNodePtr pFilelistElement;
	pRootElement->selectSingleNode(_bstr_t("file_list"), &pFilelistElement);
	IXMLDOMNodeListPtr pNodeList;
	pFilelistElement->selectNodes(_bstr_t("file_item"), &pNodeList);

	long lngNum;
	pNodeList->get_length(&lngNum);
	for (int i=0; i<lngNum; i++)
	{
		IXMLDOMNodePtr pNode;
		pNodeList->get_item(i, &pNode);

		IXMLDOMNamedNodeMapPtr pNodAtts;
		pNode->get_attributes(&pNodAtts);
		IXMLDOMNodePtr partAttNode;
		pNodAtts->get_item(0, &partAttNode);

		BSTR strNodeName;
		partAttNode->get_nodeName(&strNodeName);
		VARIANT strNodeVaule;
		partAttNode->get_nodeValue(&strNodeVaule);

		CString strFilename  = (LPCTSTR)(_bstr_t)strNodeVaule.bstrVal;
		arrDwgPathArr.Add(strFilename);
	}

	HRESULT hr;
	IXMLDOMDocumentPtr	pResultDocPtr;
	IXMLDOMElementPtr globeNode;
	IXMLDOMElementPtr partlistNode;
	IXMLDOMElementPtr partlistSunNode;
	IXMLDOMElementPtr listNode;
	IXMLDOMElementPtr structureNode;
	HRESULT result = pResultDocPtr.CreateInstance("Msxml2.DOMDocument");
	if(pResultDocPtr==NULL)	return false;

	//root(1)
	IXMLDOMElementPtr rootElem;
	hr = pResultDocPtr->createElement(_bstr_t("root"),&rootElem);
	IXMLDOMNodePtr pOutNewNode;
	pResultDocPtr->appendChild(rootElem,&pOutNewNode);
	IXMLDOMElementPtr fileListElem;
	hr = pResultDocPtr->createElement(_bstr_t("file_list"),&fileListElem);
	rootElem->appendChild(fileListElem,&pOutNewNode);

	for (int i=0; i<arrDwgPathArr.GetCount(); i++)
	{
		CString strDwgFname = arrDwgPathArr.GetAt(i);
		if (!PathFileExists(strDwgFname) ) continue;

		ZwInteAppSvr theAppSrv(strDwgFname);
		CString strTitleDef = "";
		CString strBomDef = "";
		theAppSrv.initializeTitle(strTitleDef);
		theAppSrv.initializeBom(strBomDef);
		TitleArray*	pBtlArray = theAppSrv.getTitleData();	//the set of title data
		HDataTable*	pMxbTbl   = theAppSrv.getBomData();		//the set of bom data

		//file_info(1)
		IXMLDOMElementPtr fileItemElem;
		hr = pResultDocPtr->createElement(_bstr_t("file_item"),&fileItemElem);
		fileListElem->appendChild(fileItemElem,&pOutNewNode);
		fileItemElem->setAttribute(_bstr_t("path"),_variant_t(strDwgFname));	

		//title_info(2)
		IXMLDOMElementPtr titleInfoElem;
		hr = pResultDocPtr->createElement(_bstr_t("title_info"),&titleInfoElem);
		fileItemElem->appendChild(titleInfoElem,&pOutNewNode);

		IXMLDOMElementPtr btlElem;
		hr = pResultDocPtr->createElement(_bstr_t("attr"),&btlElem);
		for(int i=0; i<pBtlArray->GetCount(); i++)
		{
			CString strTag = pBtlArray->GetAt(i).strTag;
			CString strVal= pBtlArray->GetAt(i).strVal;
			btlElem->setAttribute((_bstr_t)(const char *)strTag,(_variant_t)(const char *)strVal);
		}
		titleInfoElem->appendChild(btlElem,&pOutNewNode);	

		//bom_info(2)
		IXMLDOMElementPtr bomInfoElem;
		hr = pResultDocPtr->createElement(_bstr_t("bom_info"),&bomInfoElem);
		fileItemElem->appendChild(bomInfoElem,&pOutNewNode);

		for( int i=0; i<pMxbTbl->GetRowNum(); i++ )
		{
			IXMLDOMElementPtr partElem;
			hr = pResultDocPtr->createElement(_bstr_t("part"),&partElem);
			for(int j=0; j<pMxbTbl->GetColNum(); j++)
			{
				CString strTag = pMxbTbl->GetColNameAt(j);
				CString strVal = pMxbTbl->GetTextAt(i,j);
				partElem->setAttribute((_bstr_t)strTag,(_variant_t)strVal);
			}
			bomInfoElem->appendChild(partElem,&pOutNewNode);

		}
	}

	CString strXmlName = strInputXml;
	strXmlName = strXmlName.Mid(0, strXmlName.GetLength()-4);
	strXmlName += "_Result.xml";
	pResultDocPtr->save((_variant_t)strXmlName);

	CoUninitialize(); 

	return TRUE;
}


BOOL ZwWriteTBDataX(LPCTSTR strInputXml)
{
	CStringArray arrDwgPath;
	CStringArray arrTtlData;
	CStringArray arrBomData;

	CoInitialize(NULL); 

	IXMLDOMDocumentPtr	pInputDocPtr;		
	HRESULT res= pInputDocPtr.CreateInstance("Msxml2.DOMDocument");

	VARIANT_BOOL bIsSuccessful;
	BOOL bRt = pInputDocPtr->load((_variant_t)strInputXml, &bIsSuccessful);
	
	IXMLDOMNodePtr pRootElement;
	pInputDocPtr->selectSingleNode(_bstr_t("root"), &pRootElement);
	IXMLDOMNodePtr pFilelistElement;
	pRootElement->selectSingleNode(_bstr_t("file_list"), &pFilelistElement);
	IXMLDOMNodeListPtr pNodeList;
	pFilelistElement->selectNodes(_bstr_t("file_item"), &pNodeList);

	long lngNum;
	pNodeList->get_length(&lngNum);
	for (int i=0; i<lngNum; i++)
	{
		IXMLDOMNodePtr pNode;
		pNodeList->get_item(i, &pNode);

		IXMLDOMNamedNodeMapPtr pNodAtts;
		pNode->get_attributes(&pNodAtts);
		IXMLDOMNodePtr partAttNode;
		pNodAtts->get_item(0, &partAttNode);

		BSTR strNodeName;
		partAttNode->get_nodeName(&strNodeName);
		VARIANT strNodeVaule;
		partAttNode->get_nodeValue(&strNodeVaule);
		CString strFilename  = (LPCTSTR)(_bstr_t)strNodeVaule.bstrVal;
		arrDwgPath.Add(strFilename);

		IXMLDOMNodePtr pTitleInfo;
		pNode->selectSingleNode(_bstr_t("title_info"), &pTitleInfo);
		IXMLDOMNodePtr pTtlAttNode;
		pTitleInfo->selectSingleNode(_bstr_t("attr"), &pTtlAttNode);

		IXMLDOMNamedNodeMapPtr pTitleAtts;
		pTtlAttNode->get_attributes(&pTitleAtts);
		long lngTltAttNum = 0;
		pTitleAtts->get_length(&lngTltAttNum);
		CString strTitle;
		for (int j=0; j<lngTltAttNum; j++)
		{
			IXMLDOMNodePtr titleAttNode;
			pTitleAtts->get_item(j, &titleAttNode);
			BSTR strNodeName;
			titleAttNode->get_nodeName(&strNodeName);
			VARIANT strNodeVaule;
			titleAttNode->get_nodeValue(&strNodeVaule);
			CString strNode   = (LPCTSTR)(_bstr_t)strNodeName;
			CString strVaule  = (LPCTSTR)(_bstr_t)strNodeVaule;
			strTitle += strNode + "=" + strVaule + ";";
		}
		arrTtlData.Add(strTitle);

		IXMLDOMNodePtr pBomInfo;
		pNode->selectSingleNode(_bstr_t("bom_info"), &pBomInfo);
		IXMLDOMNodeListPtr pPartList;
		pBomInfo->selectNodes(_bstr_t("part"), &pPartList);
		long lngPart = 0;
		pPartList->get_length(&lngPart);
		CString strBom;
		for (int j=0; j<lngPart; j++)
		{
			IXMLDOMNodePtr pPartNode;
			pPartList->get_item(j, &pPartNode);
			IXMLDOMNamedNodeMapPtr pPartAtts;
			pPartNode->get_attributes(&pPartAtts);
			long lngPartAttNum = 0;
			pPartAtts->get_length(&lngPartAttNum);
			CString strSingleMxl;
			for (int k=0; k<lngPartAttNum; k++)
			{
				IXMLDOMNodePtr partAttNode;
				pPartAtts->get_item(k, &partAttNode);
				BSTR strNodeName;
				partAttNode->get_nodeName(&strNodeName);
				VARIANT strNodeVaule;
				partAttNode->get_nodeValue(&strNodeVaule);
				CString strNode   = (LPCTSTR)(_bstr_t)strNodeName;
				CString strVaule  = (LPCTSTR)(_bstr_t)strNodeVaule;
				strSingleMxl += strNode + "=" + strVaule + ",";
			}
			strBom += strSingleMxl + ";";			
		}
		arrBomData.Add(strBom);
	}

	CoUninitialize(); 

	for (int i=0; i<arrDwgPath.GetCount(); i++)
	{
		ZwWriteTBData(arrTtlData[i], arrBomData[i], arrDwgPath[i]);
	}

	return true; 
}