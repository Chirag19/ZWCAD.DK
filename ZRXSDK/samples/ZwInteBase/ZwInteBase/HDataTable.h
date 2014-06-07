// HDataTable.h: interface for the HDataTable class.
// 二维字符数据表格定义
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HDATATABLE_H__3CED9067_AFDE_47DE_B043_2749061C55E0__INCLUDED_)
#define AFX_HDATATABLE_H__3CED9067_AFDE_47DE_B043_2749061C55E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afxtempl.h"
#include "Shlwapi.h"

#pragma comment(lib, "Shlwapi.lib")

typedef CArray<CString,CString &> HDataArray;
typedef CArray <HDataArray *,HDataArray * &> HDataTbl;

class HDataTable  
{
private:
	//表行数
	int m_RowNum;
	//表列数
	int m_ColNum;
	//表数据成员
	HDataTbl m_HDataTbl;
	//表名
	CString m_tblName;
	//表列标题名
	HDataArray m_ColNameArray;
	//表列数据
	HDataArray m_TblDataArray;

public:
	HDataTable();
	virtual ~HDataTable();



	int AddCol(CString colname = "")
	{
		m_ColNameArray.Add(colname);		
		m_ColNum++;
		return m_ColNum;
	}

	int AddRow(HDataArray * colNode)
	{
		int nCols = (int)colNode->GetCount();
		ASSERT(nCols == m_ColNum);
		HDataArray * pRow = new HDataArray;
		for( int indx=0;indx<m_ColNum;indx++)
		{
			CString strVal = colNode->GetAt(indx);
			pRow->Add(strVal);
		}

		m_HDataTbl.Add(pRow);
		m_RowNum++;
		return m_RowNum;
	}


	int GetRowNum()
	{
		return m_RowNum;
	}

	int GetColNum()
	{
		return m_ColNum;
	}

	CString GetColNameAt(int nIndex)
	{
		return m_ColNameArray.GetAt(nIndex);
	}

	BOOL GetRowAt(HDataArray *  Row,int nIndex)
	{
	  	Row = m_HDataTbl.GetAt(nIndex);	
		if (!Row)
			return FALSE;
		else
			return TRUE;
	}

	CString GetTextAt(int nRow,int nCol)
	{
		CString strValue;
		strValue = m_HDataTbl.GetAt(nRow)->GetAt(nCol);
		return strValue;
	}
	
	void SetTableName(CString tablename)
	{
		m_tblName = tablename;
	}

	CString GetTableName()
	{
		return m_tblName;
	}

	

};

#endif // !defined(AFX_HDATATABLE_H__3CED9067_AFDE_47DE_B043_2749061C55E0__INCLUDED_)
