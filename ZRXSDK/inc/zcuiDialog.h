#ifndef _zcuiDialog_h
#define _zcuiDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class ZCUI_PORT CZcUiDialog : public CZdUiDialog {
    DECLARE_DYNAMIC(CZcUiDialog);

public:
                CZcUiDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiDialog ();


protected:
virtual BOOL    FindContextHelpFullPath (LPCTSTR fileName, CString& fullPath);


public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual int IsMultiDocumentActivationEnabled();
virtual int EnableMultiDocumentActivation(BOOL bEnable);

virtual void    OnDialogHelp();     

public:
    //{{AFX_DATA(CZcUiDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CZcUiDialog)
	protected:
    virtual void OnOK();
	virtual void OnCancel();
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiDialogBar : public CZdUiDialogBar {
    DECLARE_DYNAMIC(CZcUiDialogBar);

public:
                CZcUiDialogBar ();
virtual         ~CZcUiDialogBar ();


public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();

public:
    //{{AFX_DATA(CZcUiDialogBar)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CZcUiDialogBar)
	protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiDialogBar)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiFileDialog : public CZdUiFileDialog {
    DECLARE_DYNAMIC(CZcUiFileDialog);

public:
                CZcUiFileDialog (
                    BOOL bOpenFileDialog,
                    LPCTSTR lpszDefExt=NULL,
                    LPCTSTR lpszFileName=NULL,
                    DWORD dwFlags=OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                    LPCTSTR lpszFilter=NULL,
                    CWnd *pParentWnd=NULL
                );
virtual         ~CZcUiFileDialog ();

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual void    OnDialogHelp(); 
public:
    //{{AFX_DATA(CZcUiFileDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CZcUiFileDialog)
	protected:
    virtual void OnOK();
	virtual void OnCancel();
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiFileDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};



class ZCUI_PORT CZcUiTabChildDialog:public CZdUiTabChildDialog
{
    DECLARE_DYNAMIC(CZcUiTabChildDialog);

public:
                CZcUiTabChildDialog (
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiTabChildDialog ();


public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual BOOL OnMainDialogHelp();
virtual void    OnDialogHelp();

public:
    //{{AFX_DATA(CZcUiTabChildDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CZcUiTabChildDialog)
	protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZcUiTabChildDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiTabMainDialog : public CZdUiTabMainDialog {
    DECLARE_DYNAMIC(CZcUiTabMainDialog);

public:
  	            CZcUiTabMainDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiTabMainDialog ();

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual void    OnDialogHelp();
virtual int IsMultiDocumentActivationEnabled();
virtual int EnableMultiDocumentActivation(BOOL bEnable);



public:
virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName);

public:
	//{{AFX_DATA(CZcUiTabMainDialog)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CZcUiTabMainDialog)
	protected:
    virtual void OnOK();
	virtual void OnCancel();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiTabMainDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
