#ifndef _zcuiTabCtrl_h
#define _zcuiTabCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class ZCUI_PORT CZcUiTab : public CZdUiTab {
    DECLARE_DYNAMIC(CZcUiTab);

public:
	            CZcUiTab ();
virtual         ~CZcUiTab ();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiTab)
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiTab)
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
