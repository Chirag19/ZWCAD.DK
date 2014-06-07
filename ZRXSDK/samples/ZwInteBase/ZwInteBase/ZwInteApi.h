#pragma once

#include "afxtempl.h"


AFX_EXT_API BOOL ZwReadTBData	(LPCTSTR strTitleDef = "",	LPCTSTR strBomDef = "", LPCTSTR strDwgPath = "");
AFX_EXT_API BOOL ZwWriteTBData	(LPCTSTR strTitleConts,		LPCTSTR strBomConts,	LPCTSTR strDwgPath = "");

AFX_EXT_API BOOL ZwReadTBDataX	(LPCTSTR strInputXml);
AFX_EXT_API BOOL ZwWriteTBDataX	(LPCTSTR strInputXml);

AFX_EXT_API BOOL  ZwInsertTextToFile(LPCTSTR strDwgPath, LPCTSTR strTitleDef,bool IsPaperSpace = false);
AFX_EXT_API BOOL  ZwInsertBmpToFile	(LPCTSTR strDwgPath, LPCTSTR strTitleDef,bool IsPaperSpace = false);
AFX_EXT_API BOOL  ZwInsertDwgToFile	(LPCTSTR strDwgPath, LPCTSTR strTitleDef,bool IsPaperSpace = false);



