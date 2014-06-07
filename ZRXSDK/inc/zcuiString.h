#ifndef _zcuiString_h
#define _zcuiString_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ZdZChar.h"

class CZcUiString : public CString
{
public:
        ZDUI_PORT CZcUiString ();
        ZDUI_PORT CZcUiString (const CString& stringSrc);
        ZDUI_PORT CZcUiString (ZCHAR ch, int nRepeat = 1);
        ZDUI_PORT CZcUiString (LPCTSTR psz);
        ZDUI_PORT CZcUiString (LPCTSTR pch, int nLength);
        ZDUI_PORT CZcUiString (UINT nStringResourceID);

public:
        ZDUI_PORT BOOL    IsTab (int nIndex)          const;
        ZDUI_PORT BOOL    IsWhiteSpace (int nIndex)   const;
        ZDUI_PORT BOOL    IsAlphabetic (int nIndex)   const;
        ZDUI_PORT BOOL    IsAlphanumeric (int nIndex) const;
        ZDUI_PORT BOOL    IsBlank (int nIndex)        const;
        ZDUI_PORT BOOL    IsPunctuation (int nIndex)  const;
        ZDUI_PORT BOOL    IsUppercase (int nIndex)    const;
        ZDUI_PORT BOOL    IsLowercase (int nIndex)    const;
        ZDUI_PORT BOOL    IsNumeric (int nIndex)      const;
        ZDUI_PORT BOOL    IsHexNumeric (int nIndex)   const;

public:
        ZDUI_PORT void    MakeCharUpper (int nIndex);
        ZDUI_PORT void    MakeCharLower (int nIndex);
        ZDUI_PORT void    GetCurrentWorkingDirectory ();
        ZDUI_PORT void    ReplaceCharWithChar (ZCHAR chFrom, ZCHAR chTo);

        ZDUI_PORT void    StripMnemonic ();
        
        ZDUI_PORT void    StripDiesel ();

        
        ZDUI_PORT void    ConvertMenuExecString ();
        
        ZDUI_PORT void    ConvertFromMenuExecString ();

        ZDUI_PORT void    FixFileName ();

        ZDUI_PORT void    WrapLine (CZcUiString& strRest, int nWrapAt);
        ZDUI_PORT void    WrapLine (CStringList& strListWrapped, int nWrapAt);

        
        ZDUI_PORT void    ExpandTabs (int nTabSize = 8);

public:
        ZDUI_PORT void    StripTrailingBlanks  ();
        ZDUI_PORT void    StripPrecedingBlanks ();

        ZDUI_PORT void    StripTrailingCharacters  (ZCHAR cChar);
        ZDUI_PORT void    StripPrecedingCharacters (ZCHAR cChar);

public:
        ZDUI_PORT void    ShortenString (
                    CDC *pDC, 
                    CString OriginalString,
                    UINT width
                );
        ZDUI_PORT CString CreateEllipsedString (
                    CDC *pDC,
                    CString OriginalString,
                    UINT width
                );

};

class CZcUiStringExp : public CZcUiString
{
public:
        ZDUI_PORT CZcUiStringExp ();
        ZDUI_PORT CZcUiStringExp (const CString& stringSrc);
        ZDUI_PORT CZcUiStringExp (ZCHAR ch, int nRepeat = 1);
        ZDUI_PORT CZcUiStringExp (LPCTSTR psz);
        ZDUI_PORT CZcUiStringExp (LPCTSTR pch, int nLength);
        ZDUI_PORT CZcUiStringExp (UINT nStringResourceID);

public:
        ZDUI_PORT virtual BOOL LoadString(UINT nID);
        ZDUI_PORT void    ReplaceProductMacroStrings();
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
