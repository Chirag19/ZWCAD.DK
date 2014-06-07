#ifndef _zcuiDock_h
#define _zcuiDock_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class ZCUI_PORT CZcUiDockFrame : public CZdUiDockFrame {
    DECLARE_DYNCREATE(CZcUiDockFrame);

public:
	            CZcUiDockFrame ();
virtual         ~CZcUiDockFrame ();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiDockFrame)
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiDockFrame)
    afx_msg LRESULT OnZCADKeepFocus (WPARAM wParam, LPARAM lParam);//modified 
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiDockControlBar : public CZdUiDockControlBar {
    DECLARE_DYNCREATE(CZcUiDockControlBar);

public:
    CZcUiDockControlBar () {}

protected:
    virtual bool CanFrameworkTakeFocus ();
};

class ZCUI_PORT CZcUiPaletteSetDockFrame : public CZdUiPaletteSetDockFrame {
    DECLARE_DYNCREATE(CZcUiPaletteSetDockFrame);

public:
	            CZcUiPaletteSetDockFrame ();
virtual         ~CZcUiPaletteSetDockFrame ();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiPaletteSetDockFrame)
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiPaletteSetDockFrame)
    afx_msg LRESULT OnZCADKeepFocus (WPARAM wParam, LPARAM lParam); //modified
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
