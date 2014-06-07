#pragma once

struct TitleDef
{
	//��ǩ&ֵ
	CString strTag;//��ǩ
	CString strVal;//ֵ

	//����Χ
	ZcGePoint2d pntMin;//���µ�
	ZcGePoint2d pntMax;//���ϵ�

};

typedef CArray<TitleDef> TitleArray;


struct TextInfo
{
	CString strCon;
	ZcGePoint3d position;
};
typedef CArray<TextInfo,TextInfo> TextInfoArr;


bool addEntityToDb     (ZcDbEntity* pEntity, ZcDbObjectId& objId,ZcDbDatabase * pDb);
bool addEntityToDb     (ZcDbEntity* pEntity,ZcDbDatabase * pDb);

bool InsertBmpFile(LPCTSTR bmpFilePath,double fHeight,double fWidth,ZcGePoint3d posCentPt,ZcDbDatabase* pDb);
bool InsertDwgFile(LPCTSTR insDwgPath,double fHeight,double fWidth,ZcGePoint3d posCentPt,ZcDbDatabase* pDb);

BOOL  InsertTextToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef,bool IsPaperSpace = false);
BOOL  InsertBmpToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef,bool IsPaperSpace = false);
BOOL  InsertDwgToFile(LPCTSTR strDwgPath,LPCTSTR strTitleDef,bool IsPaperSpace = false);

bool GetTextWidthLen(const CString& strMsg, double dTextHeight, ZcDbObjectId txtstlId, double &dTextWidthLen);
double TextWidth(CString& stext,double fTxtHeight,ZcDbObjectId styleId,double fWidthFac);

bool GetBlockRecBoundingBox(ZcDbBlockTableRecord* pBlkRec, ZcDbExtents & extBlkRecEnt);
bool GetBlockRefBoundingBox(ZcDbBlockReference*  pBlkRef, ZcDbExtents & extBlkRefEnt);
void GetDbGroupBoundingBox(ZcDbGroup* pGrpEnt, ZcDbExtents & extGrpEnt);
