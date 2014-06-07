
#ifndef _ZNavFilterArray_h
#define _ZNavFilterArray_h

#if _MSC_VER >= 1000
#pragma once
#endif 


#pragma warning(push)
#pragma warning(disable : 4275)
class ZNAV_PORT CNavFilterArray : public CNavArray<CNavFilter> {
public:
                CNavFilterArray ();
virtual         ~CNavFilterArray ();


public:
        void    SetFrom (LPCTSTR str, BOOL bUseFullDescrition = FALSE);
        int     Find (LPCTSTR str);
        int     FindExact (LPCTSTR str);                
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
