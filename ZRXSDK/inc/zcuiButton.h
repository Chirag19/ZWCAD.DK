#ifndef _zcuiButton_h
#define _zcuiButton_h

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class ZCUI_PORT CZcUiOwnerDrawButton : public CZdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CZcUiOwnerDrawButton)

public:
	            CZcUiOwnerDrawButton ();
virtual         ~CZcUiOwnerDrawButton ();

public:
	//{{AFX_VIRTUAL(CZcUiOwnerDrawButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiOwnerDrawButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiBitmapButton : public CZdUiBitmapButton {
	DECLARE_DYNAMIC(CZcUiBitmapButton)

public:
	            CZcUiBitmapButton ();
virtual         ~CZcUiBitmapButton ();

public:
	//{{AFX_VIRTUAL(CZcUiBitmapButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiBitmapButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiBitmapStatic : public CZdUiBitmapStatic {
	DECLARE_DYNAMIC(CZcUiBitmapStatic)

public:
	            CZcUiBitmapStatic ();
virtual         ~CZcUiBitmapStatic ();

public:
	//{{AFX_VIRTUAL(CZcUiBitmapStatic)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiBitmapStatic)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiDropSite : public CZdUiDropSite {
	DECLARE_DYNAMIC(CZcUiDropSite)

public:
	            CZcUiDropSite ();
virtual         ~CZcUiDropSite ();

public:
	//{{AFX_VIRTUAL(CZcUiDropSite)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiDropSite)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiPickButton : public CZdUiBitmapButton {
	DECLARE_DYNAMIC(CZcUiPickButton)

public:
	            CZcUiPickButton ();
virtual         ~CZcUiPickButton ();

protected:
virtual BOOL    OnLoadBitmap (LPCTSTR strResId);

public:
	//{{AFX_VIRTUAL(CZcUiPickButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiPickButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiSelectButton : public CZcUiPickButton {
	DECLARE_DYNAMIC(CZcUiSelectButton)

public:
	            CZcUiSelectButton ();
virtual         ~CZcUiSelectButton ();

public:
	//{{AFX_VIRTUAL(CZcUiSelectButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiSelectButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiToolButton : public CZdUiToolButton {
	DECLARE_DYNAMIC(CZcUiToolButton)

public:
	            CZcUiToolButton ();
virtual         ~CZcUiToolButton ();

public:
	//{{AFX_VIRTUAL(CZcUiToolButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiToolButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif

//////////////////////////////////////////////////////////////////////////////
