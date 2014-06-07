#include "StdAfx.h"
#include "HDataTable.h"
#include "ZwInteFuncts.h"
#include "ZwInteAppSvr.h"
#include <math.h>


ZwInteAppSvr::ZwInteAppSvr(LPCTSTR dwgPathName, bool bIsForWrite)
{
	
	m_bIsCurDwg = false;
	m_pFileDb = NULL;
	m_strDwgPath = dwgPathName;
	m_bIsForWrite = bIsForWrite;
	m_dblPlotScale = 1.0;
	m_dblMxbBodyBlkRefHeight = 8.0;

	if (strcmp(m_strDwgPath,"") == 0)
	{
		m_bIsCurDwg = true;
		m_pFileDb = zcdbHostApplicationServices()->workingDatabase();
		const char* curFileName = NULL;
		m_pFileDb->getFilename(curFileName);
		if (strcmp(curFileName, "") == 0)
		{
			AfxMessageBox("The current drawing name is null, please save it before!");
			return;
		}
		m_strDwgPath = curFileName;		

	}
	else
	{
		if(!PathFileExists(m_strDwgPath)) return;
		m_pFileDb = new ZcDbDatabase(false);
		m_pFileDb->readDwgFile(m_strDwgPath);
	}

	getTbBlkRefIds();

	bool bHasBomtitleBlkRef = false;

	if (m_bomtitleBlkRefIds.length() > 0)
	{
		bHasBomtitleBlkRef = true;
	}

	if (m_bIsForWrite)
	{
		ZcGePoint3d mxbBlkInsPt; 
		ZcDbDatabase* pThisDb = NULL;
		if (bHasBomtitleBlkRef)
		{
			ZcDbBlockReference* pBomtitleBlkRef = NULL;
			if (Zcad::eOk == zcdbOpenObject(pBomtitleBlkRef, m_bomtitleBlkRefIds.at(0), ZcDb::kForWrite))
			{
				pThisDb = pBomtitleBlkRef->database();

				ZcGeScale3d blkScale =pBomtitleBlkRef->scaleFactors();
				m_dblPlotScale = blkScale.sx;

				mxbBlkInsPt = pBomtitleBlkRef->position();
				ZcDbExtents extent;
				pBomtitleBlkRef->getGeomExtents(extent);
				pBomtitleBlkRef->close();
				double dblDiffHeight = extent.maxPoint().y - extent.minPoint().y; 
				mxbBlkInsPt.y += dblDiffHeight;
				//mxbBlkInsPt = extent.maxPoint();
			}
		}

		m_pntMxbBlkIns = mxbBlkInsPt;
	}
}

ZwInteAppSvr::~ZwInteAppSvr(void)
{
	if ( !m_bIsCurDwg  &&  m_pFileDb )
	{
		delete m_pFileDb;
		m_pFileDb = NULL;
	}
}

CString ZwInteAppSvr::getDwgPath()
{
	return m_strDwgPath;
}

bool ZwInteAppSvr::getTbBlkRefIds()
{
	if (!m_pFileDb)
	{
		return false;
	}

	ZcDbBlockTable* pTbl = NULL;
	if (Zcad::eOk != m_pFileDb->getBlockTable(pTbl, ZcDb::kForRead))
	{
		return false;
	}

	ZcDbBlockTableRecord* pBlkTblRec = NULL;
	if (Zcad::eOk != pTbl->getAt(ZCDB_MODEL_SPACE, pBlkTblRec, ZcDb::kForRead))
	{
		pTbl->close();
		return false;
	}
	pTbl->close();

	ZcDbBlockTableRecordIterator *pEntIter = NULL;
	pBlkTblRec->newIterator(pEntIter);
	pBlkTblRec->close();

	ZcDbEntity *pEnt = NULL;	
	for (pEntIter->start(); !pEntIter->done(); pEntIter->step())
	{
		pEntIter->getEntity(pEnt, ZcDb::kForRead); 

		if (!pEnt)
		{
			continue;
		}

		if(!pEnt->isKindOf(ZcDbBlockReference::desc()))
		{
			pEnt->close();
			continue;
		}

		ZcDbBlockReference* pBlkRef = (ZcDbBlockReference*)pEnt;

		ZcDbObjectId blkRecId = pBlkRef->blockTableRecord();
		ZcDbBlockTableRecord* pBlkRec = NULL;
		if (Zcad::eOk != zcdbOpenObject(pBlkRec,blkRecId,ZcDb::kForRead))
		{
			pEnt->close();
			continue;
		}

		ZcString strBlkName;
		pBlkRec->getName(strBlkName);
		pBlkRec->close();

	
		if(strBlkName == "ZW_BTL_BLK" || strBlkName == "ZW_FJL_BLK" || strBlkName == "ZW_DHL_BLK" || strBlkName == "ZW_CSL_BLK")
		{
			m_titleBlkRefIds.append(pBlkRef->objectId());
		}

		if(strBlkName == "ZW_MXB_BLK" )
		{
			m_bomBlkRefIds.append(pBlkRef->objectId());
		}

		if (strBlkName == "ZW_MXBTITLE_BLK")
		{
			m_bomtitleBlkRefIds.append(pBlkRef->objectId());
		}

		pEnt->close();		
	}

	delete pEntIter;

	return true;
}


void ZwInteAppSvr::initializeTitle(LPCTSTR strTitle)
{
	m_strTitle = strTitle;

	if (m_bIsForWrite)
	{
		initializeTitleForWrite();
	}
	else
	{
		initializeTitleForRead();
	}
}

void ZwInteAppSvr::initializeBom(LPCTSTR strBom)
{
	m_strBom = strBom;

	if (m_bIsForWrite)
	{
		initializeBomForWrite();
	}
	else
	{
		initializeBomForRead();
	}
}

void ZwInteAppSvr::initializeTitleForRead()
{
	if (m_strTitle == "")
	{
		for (int i=0; i<m_titleBlkRefIds.length(); i++)
		{
			ZcDbBlockReference* pBlkRef = NULL;
			if (Zcad::eOk != zcdbOpenObject(pBlkRef, m_titleBlkRefIds.at(i), ZcDb::kForRead))
			{
				continue;
			}

			ZcDbObjectIterator* pAttIter = pBlkRef->attributeIterator();
			for(pAttIter->start();!pAttIter->done();pAttIter->step())
			{
				ZcDbAttribute* pAtt = ZcDbAttribute::cast(pAttIter->entity());
				ASSERT(pAtt->isKindOf(ZcDbAttribute::desc()));

				TitleDef btlNode;
				btlNode.strTag = pAtt->tag();				
				btlNode.strVal = pAtt->textString();
				pAtt->close();

				m_arrBtlData.Add(btlNode);	
			}
			delete pAttIter;

			pBlkRef->close();
		}
	}
	else
	{
		CString strDefCon = m_strTitle;
		CString resToken;
		int nCurPos = 0;
		resToken = strDefCon.Tokenize(",£¬",nCurPos);//Token char is "," & " " & "£¬"
		while(resToken != "")
		{
			TitleDef btlData;
			btlData.strTag = resToken;
			m_arrBtlData.Add(btlData);
			resToken = strDefCon.Tokenize(",£¬",nCurPos);
		}
	}
}

void ZwInteAppSvr::initializeBomForRead()	
{
	if (m_strBom == "" && m_tblMxbData.GetColNum() == 0)
	{
		for (int i=0; i<m_bomBlkRefIds.length(); i++)
		{
			ZcDbBlockReference* pBlkRef = NULL;
			if (Zcad::eOk != zcdbOpenObject(pBlkRef, m_bomBlkRefIds.at(i), ZcDb::kForRead))
			{
				continue;
			}

			ZcDbObjectIterator* pAttIter = pBlkRef->attributeIterator();
			for (pAttIter->start();!pAttIter->done();pAttIter->step())
			{
				ZcDbAttribute* pAtt = ZcDbAttribute::cast(pAttIter->entity());
				assert(pAtt->isKindOf(ZcDbAttribute::desc()));
				ZcString strAttTag = pAtt->tag();
				pAtt->close();
				m_tblMxbData.AddCol((const char *)strAttTag);
			}
			delete pAttIter;
			pBlkRef->close();
		}
	}
	else
	{
		CString strDefCon = m_strBom;
		int nCurPos = 0;
		CString resToken;
		resToken = strDefCon.Tokenize(",£¬",nCurPos);//Token char is "," & " " & "£¬"
		while(resToken != "")
		{
			m_tblMxbData.AddCol(resToken);
			resToken = strDefCon.Tokenize(",£¬",nCurPos);
		}
	}	
}

void ZwInteAppSvr::initializeTitleForWrite()	
{
	CString strDefCon = m_strTitle;
	CString resToken;
	int nCurPos = 0;
	resToken = strDefCon.Tokenize(";£»",nCurPos);//Token char is ";"  & "£»"
	while(resToken != "")
	{
		CString strL,strR;
		int pos = resToken.Find("=");
		assert(pos > 0);
		strL = resToken.Left(pos);
		strL.Remove(' ');
		strR = resToken.Mid(pos+1);
		//strR.Remove(' ');
		TitleDef btlData;
		btlData.strTag = strL;
		btlData.strVal = strR;
		m_arrBtlData.Add(btlData);
		resToken = strDefCon.Tokenize(";£»",nCurPos);
	}
}

void ZwInteAppSvr::initializeBomForWrite()
{
	CStringArray mxbDataStrArr;
	CString strDefCon = m_strBom;
	int nCurPos = 0;
	CString resToken = strDefCon.Tokenize(";£»",nCurPos);//Token char is ";"  & "£»"
	while(resToken != "")
	{
		mxbDataStrArr.Add(resToken);
		resToken = strDefCon.Tokenize(";£»",nCurPos);
	}

	if( mxbDataStrArr.GetCount() > 0 )
	{
		strDefCon = mxbDataStrArr[0];
		nCurPos = 0;
		resToken = strDefCon.Tokenize(",£¬",nCurPos);//Token char is ","  & "£¬"
		while(resToken != "")
		{
			int pos = resToken.Find("=");
			resToken = resToken.Left(pos);
			resToken.Remove(' ');
			m_tblMxbData.AddCol(resToken);
			resToken = strDefCon.Tokenize(",£¬",nCurPos);
		}
	}
	
	for( int i=0; i<mxbDataStrArr.GetCount(); i++ )
	{
		HDataArray row;
		strDefCon = mxbDataStrArr[i];
		nCurPos = 0;
		resToken = strDefCon.Tokenize(",£¬",nCurPos);//Token char is ","  & "£¬"
		while(resToken != "")
		{
			int pos = resToken.Find("=");
			resToken = resToken.Mid(pos+1);
			resToken.Remove(' ');
			row.Add(resToken);
			resToken = strDefCon.Tokenize(",£¬",nCurPos);
		}

		if(row.GetCount() != m_tblMxbData.GetColNum()) continue;

		m_tblMxbData.AddRow(&row);
	}
	
}

TitleArray* ZwInteAppSvr::getTitleData()
{
	for (int i=0; i<m_titleBlkRefIds.length(); i++)
	{
		ZcDbBlockReference* pBlkRef = NULL;
		if (Zcad::eOk != zcdbOpenObject(pBlkRef, m_titleBlkRefIds.at(i), ZcDb::kForRead))
		{
			continue;
		}

		for(int i=0; i<m_arrBtlData.GetCount(); i++)
		{
			CString strTag = m_arrBtlData[i].strTag;
			ZcDbObjectIterator* pAttIter = pBlkRef->attributeIterator();
			for(pAttIter->start();!pAttIter->done();pAttIter->step())
			{
				ZcDbAttribute* pAtt = ZcDbAttribute::cast(pAttIter->entity());
				ASSERT(pAtt->isKindOf(ZcDbAttribute::desc()));
				CString strAttTag = pAtt->tag();
				strTag.Remove(' ');
				strAttTag.Remove(' ');
				if( strTag != strAttTag )
				{
					pAtt->close();
					continue;
				}

				m_arrBtlData[i].strVal = pAtt->textString();
				pAtt->close();
				break;
			}
			delete pAttIter;
		}

		pBlkRef->close();
	}

	return &m_arrBtlData;
}

HDataTable*	ZwInteAppSvr::getBomData()
{
	for (int i=0; i<m_bomBlkRefIds.length(); i++)
	{
		ZcDbBlockReference* pBlkRef = NULL;
		if (Zcad::eOk != zcdbOpenObject(pBlkRef, m_bomBlkRefIds.at(i), ZcDb::kForRead))
		{
			continue;
		}

		HDataArray mxbRowData;
		for( int i=0; i<m_tblMxbData.GetColNum(); i++ )
		{
			CString colName = m_tblMxbData.GetColNameAt(i);
			ZcDbObjectIterator* pAttIter = pBlkRef->attributeIterator();

			for(pAttIter->start();!pAttIter->done();pAttIter->step())
			{
				ZcDbAttribute* pAtt = ZcDbAttribute::cast(pAttIter->entity());
				assert(pAtt->isKindOf(ZcDbAttribute::desc()));
				CString strAttTag = pAtt->tag();
				colName.Remove(' ');
				strAttTag.Remove(' ');
				if( colName != strAttTag )
				{
					pAtt->close();
					continue;
				}

				CString strCell = pAtt->textString();
				pAtt->close();
				mxbRowData.Add(strCell);
				break;
			}
			delete pAttIter;
		}

		assert(m_tblMxbData.GetColNum() == mxbRowData.GetCount());
		if (m_tblMxbData.GetColNum() == mxbRowData.GetCount())
		{
			m_tblMxbData.AddRow(&mxbRowData);
		}
	}

	return &m_tblMxbData;
}

void ZwInteAppSvr::setTitleData()
{
	for (int i=0; i<m_titleBlkRefIds.length(); i++)
	{
		ZcDbBlockReference* pBlkRef = NULL;
		if (Zcad::eOk != zcdbOpenObject(pBlkRef, m_titleBlkRefIds.at(i), ZcDb::kForWrite))
		{
			continue;
		}

		for (int i=0; i<m_arrBtlData.GetCount(); i++)
		{
			CString strTag = m_arrBtlData[i].strTag;
			CString strVal = m_arrBtlData[i].strVal;

			ZcDbObjectIterator* pAttIter = pBlkRef->attributeIterator();
			for (pAttIter->start();!pAttIter->done();pAttIter->step())
			{
				ZcDbAttribute* pAtt = ZcDbAttribute::cast(pAttIter->entity());
				pAtt->upgradeOpen();

				ASSERT(pAtt->isKindOf(ZcDbAttribute::desc()));
				CString strAttTag = pAtt->tag();
				strTag.Remove(' ');
				strAttTag.Remove(' ');
				if( strTag != strAttTag ) 
				{
					pAtt->close();
					continue;
				}


				if(strVal.Find(".dxf") > 1 || strVal.Find(".dwg") > 1 || strVal.Find(".DXF") > 1 || strVal.Find(".DWG") > 1 )
				{//Insert DWG/DXF 
					pAtt->setTextString("");

				}				
				else if(strVal.Find(".bmp{") > 1 || strVal.Find(".BMP{") > 1 ||	strVal.Find(".jpg{") > 1 || strVal.Find(".JPG{") > 1 )
				{  //Insert BMP 
					ZcDbExtents extent;
					pAtt->getGeomExtents(extent);

					CString bmpFilePath;
					int pos = strVal.Find("{");
					bmpFilePath = (const char *)strVal.Left(pos);
					bmpFilePath.TrimLeft();

					ZcGeVector3d posCenPt;
					double h,w;
					CString strPosition = strVal.Mid(pos+1);
					pos = strPosition.Find(",");
					w = atof(strPosition.Left(pos))*m_dblPlotScale;
					strPosition = strPosition.Mid(pos+1);
					pos = strPosition.Find(",");
					h = atof(strPosition.Left(pos))*m_dblPlotScale;
					strPosition = strPosition.Mid(pos+1);
					pos = strPosition.Find(",");
					posCenPt.x = atof(strPosition.Left(pos))*m_dblPlotScale;
					strPosition = strPosition.Mid(pos+1);
					posCenPt.y = atof(strPosition)*m_dblPlotScale;
					if( InsertBmpFile(bmpFilePath,h,w,pBlkRef->position()+posCenPt,pBlkRef->database()) )
					{                             			
						pAtt->setTextString("");
					}
				}
				else//Insert text
				{
					pAtt->setTextString(strVal);
				}
				pAtt->close();
				break;
			}

			delete pAttIter;
		}

		pBlkRef->close();
	}
}

void ZwInteAppSvr::setBomData()
{
	bool bHasBomtitleBlkRef = false;
	if (m_bomtitleBlkRefIds.length()>0) bHasBomtitleBlkRef = true;
	if (!bHasBomtitleBlkRef) return; 

	// Erase  all old mxb block reference
	for (int i=0; i<m_bomBlkRefIds.length(); i++)
	{
		ZcDbBlockReference* pBlkRef = NULL;
		if (Zcad::eOk != zcdbOpenObject(pBlkRef, m_bomBlkRefIds.at(i), ZcDb::kForWrite))
		{
			continue;
		}
		pBlkRef->erase();
		pBlkRef->close();
	}

	// Update Named Object Dictionay
	ZcDbObjectId nameObjectDictId = m_pFileDb->namedObjectsDictionaryId();
	ZcDbDictionary* pNOD = NULL;
	if (Zcad::eOk == zcdbOpenObject(pNOD, nameObjectDictId, ZcDb::kForWrite))
	{
		if (pNOD->has("ZWCAD_MXB_DICTIONARY"))
		{
			ZcDbDictionary* pMxbDict = NULL;
			pNOD->getAt("ZWCAD_MXB_DICTIONARY", (ZcDbObject*&)pMxbDict, ZcDb::kForRead);

			// Remove all old mxl info in NOD
			ZcDbDictionaryIterator* pIter = pMxbDict->newIterator();
			pMxbDict->close();
			for ( ; !pIter->done(); pIter->next())
			{
				ZcDbObject* pItem = NULL;
				pIter->getObject(pItem, ZcDb::kForWrite);
				pItem->erase();
				pItem->close();
			}
			delete pIter;

			for (int i=0; i<m_tblMxbData.GetRowNum(); i++)
			{
				ZcDbXrecord* pMxlXrec = new ZcDbXrecord();
				CString strMxlName;
				strMxlName.Format("ZWCAD_MXB_MXL%d", i+1);
				ZcDbObjectId eId;
				pMxbDict->setAt(strMxlName, pMxlXrec,eId);
				CString strName = m_tblMxbData.GetColNameAt(0);
				CString strVal = m_tblMxbData.GetTextAt(i,0); 
				struct resbuf * pHead, *pTmp;
				pHead = zcutNewRb(ZcDb::kDxfXTextString);
				pTmp = pHead;
				pTmp->resval.rstring = new char[(strlen(strName)+1)];
				strcpy(pTmp->resval.rstring,strName);

				pTmp->rbnext = zcutNewRb(ZcDb::kDxfXTextString);
				pTmp = pTmp->rbnext;
				pTmp->resval.rstring = new char[(strlen(strVal)+1)];
				strcpy(pTmp->resval.rstring,strVal);


				for (int j=1; j<m_tblMxbData.GetColNum(); j++)
				{
					CString strName = m_tblMxbData.GetColNameAt(j);
					pTmp->rbnext = zcutNewRb(ZcDb::kDxfXTextString);
					pTmp = pTmp->rbnext;
					pTmp->resval.rstring = new char[(strlen(strName)+1)];
					strcpy(pTmp->resval.rstring,strName);

					CString strVal = m_tblMxbData.GetTextAt(i,j);
					pTmp->rbnext = zcutNewRb(ZcDb::kDxfXTextString);
					pTmp = pTmp->rbnext;
					pTmp->resval.rstring = new char[(strlen(strVal)+1)];
					strcpy(pTmp->resval.rstring,strVal);
				}	

				pMxlXrec->setFromRbChain(*pHead);			
				pMxlXrec->close();
				zcutRelRb(pHead);
			}
			pMxbDict->close();
		}
		pNOD->close();
	}
	
	// Insert Mxl Block Reference and set the attributes
	ZcDbBlockTable* pBlkTbl = NULL;
	m_pFileDb->getBlockTable(pBlkTbl, ZcDb::kForRead);
	ZcDbObjectId idMxbBodyBlkRec;
	pBlkTbl->getAt("ZW_MXB_BLK", idMxbBodyBlkRec);
	if (!idMxbBodyBlkRec)
	{
		return;
	}
	pBlkTbl->close();

	
	ZcGePoint3d mxbBlkInsPt = m_pntMxbBlkIns;

	for( int i=0; i<m_tblMxbData.GetRowNum(); i++ )
	{
		ZcDbBlockReference* pBlkRef = new ZcDbBlockReference();
		pBlkRef->setBlockTableRecord(idMxbBodyBlkRec);
		pBlkRef->setPosition(mxbBlkInsPt);
		pBlkRef->setRotation(0);
		ZcGeScale3d XrefScale(m_dblPlotScale, m_dblPlotScale,1);
		pBlkRef->setScaleFactors( XrefScale);

		ZcDbObjectId idBlkRef;
		addEntityToDb(pBlkRef,idBlkRef,m_pFileDb);

		ZcDbBlockTableRecord* pBlkTblRec = NULL;
		zcdbOpenObject(pBlkTblRec, idMxbBodyBlkRec, ZcDb::kForRead);

		ZcDbBlockTableRecordIterator* pIterator = NULL;
		pBlkTblRec->newIterator(pIterator);
		pBlkTblRec->close();

		for(pIterator->start(); !pIterator->done(); pIterator->step())
		{
			ZcDbEntity* pEnt = NULL;
			ZcDbAttributeDefinition* pAttdef = NULL;

			pIterator->getEntity(pEnt, ZcDb::kForRead);		
			pAttdef = ZcDbAttributeDefinition::cast(pEnt);

			if (pAttdef && !pAttdef->isConstant())
			{
				ZcDbAttribute* pAtt = new ZcDbAttribute();
				pAtt->setPropertiesFrom(pAttdef);
				Zdesk::Boolean bInvisible = pAttdef->isInvisible();
				pAtt->setInvisible(bInvisible);
				pAtt->setTextStyle(pAttdef->textStyle());

				ZcGePoint3d basePoint = pAttdef->position();
				basePoint.scaleBy(m_dblPlotScale);
				basePoint += pBlkRef->position().asVector();
				pAtt->setPosition(basePoint);

				ZcGePoint3d adjustPoint = pAttdef->alignmentPoint();
				adjustPoint += pBlkRef->position().asVector();
				pAtt->setAlignmentPoint(adjustPoint);

				pAtt->setHeight(pAttdef->height()*m_dblPlotScale);
				pAtt->setRotation(pAttdef->rotation());

				pAtt->setTag(pAttdef->tag());
				pAtt->setFieldLength(pAttdef->fieldLength());

				pAtt->setTextString(pAttdef->textString());
				ZcDbObjectId attId;
				pBlkRef->appendAttribute(attId, pAtt);
				pAtt->close();
			}
			delete pAttdef;
		}

		delete pIterator;

		for(int j=0; j<m_tblMxbData.GetColNum(); j++)
		{
			CString strTag = m_tblMxbData.GetColNameAt(j);
			CString strVal = m_tblMxbData.GetTextAt(i,j);
			ZcDbObjectIterator* pAttIter = pBlkRef->attributeIterator();
			for(pAttIter->start();!pAttIter->done();pAttIter->step())
			{
				ZcDbAttribute* pAtt = (ZcDbAttribute*)pAttIter->entity();
				pAtt->upgradeOpen();

				assert(pAtt->isKindOf(ZcDbAttribute::desc()));
				CString strAttTag = pAtt->tag();
				strTag.Remove(' ');
				strAttTag.Remove(' ');
				if( strTag != strAttTag ) 
				{
					pAtt->close();
					continue;
				}

				pAtt->setTextString(strVal);

				double dblAttDefLen = fabs(pAtt->alignmentPoint().x - pAtt->position().x);
				double dblTextWidthLen;
				GetTextWidthLen(strVal, pAtt->height(), pAtt->textStyle(), dblTextWidthLen);

				if (dblTextWidthLen > dblAttDefLen)
				{
					pAtt->setHorizontalMode(ZcDb::kTextFit);
					pAtt->setVerticalMode(ZcDb::kTextBase);
				}
				pAtt->close();
			}
		}

		//Add the Xdata
		Zcad::ErrorStatus es;
		char appName[132] = "_ZWCAD_MXL_";
		CString strMxlItem;
		strMxlItem.Format("ZWCAD_MXB_MXL%d", i+1);

		resbuf* pRb = NULL;
		zcdbRegApp(appName);
		pRb = zcutBuildList(			-3,
			ZcDb::kDxfRegAppName,		appName,
			ZcDb::kDxfXdInteger16,		1,
			ZcDb::kDxfXdAsciiString,	strMxlItem,
			ZcDb::kDxfXdInteger16,		2,
			ZcDb::kDxfXdAsciiString,	_T(""),
			ZcDb::kDxfXdInteger16,		3,
			ZcDb::kDxfXdAsciiString,	_T("0"),
			0);

		es = pBlkRef->setXData(pRb);
		zcutRelRb(pRb);
		pBlkRef->close();
		mxbBlkInsPt.y += m_dblMxbBodyBlkRefHeight * m_dblPlotScale;
	}
	
}

void ZwInteAppSvr::save()
{
	if (!m_bIsCurDwg && m_bIsForWrite)
	{
		m_pFileDb->save();
	}
}