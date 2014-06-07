// HDataTable.cpp: implementation of the HDataTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HDataTable.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HDataTable::HDataTable()
{
	m_RowNum = 0;
	m_ColNum = 0; 
}

HDataTable::~HDataTable()
{
	//free
	for ( int i =0; i< GetRowNum(); i++)
	{
		delete m_HDataTbl.GetAt(i);
	}

}
