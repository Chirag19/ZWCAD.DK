#ifndef _zduiTabMainDialog_h
#define _zduiTabMainDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class ZDUI_PORT CZdUiTabMainDialog : public CZdUiDialog {
friend class CZdUiTab;

    DECLARE_DYNAMIC(CZdUiTabMainDialog);

public:
  	            CZdUiTabMainDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );

private:
        int m_idDefaultButton;

        CZdUiTab *m_pZcadTab;

        CString m_strTabIndex;

        BOOL    TranslateTabKey ();
protected:
        void    SetZcadTabPointer (CZdUiTab *pZcadTab);

public:        
        int     AddExtendedTabs ();    
        
        int     GetDefaultButton ();

        CZdUiTab *GetTabControl ();

        void    SetDefaultButton (int nIdDefaultButton);

        void    UpdateDefaultButton (HWND hFocusBefore, HWND hFocusAfter);

        void    SetInitialTabIndex(LPCTSTR strTabIndex) {m_strTabIndex = strTabIndex;}
        LPCTSTR GetInitialTabIndex() {return m_strTabIndex;}
        int     GetInitialRequestedTabIndex();        

protected:
virtual void    OnInitDialogBegin ();
virtual void    OnInitDialogFinish ();

protected:
        CZdUiTabExtensionManager m_xtabManager;

public:
virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName);
        CZdUiTabExtensionManager *GetXtabPointer ();

public:
        BOOL    AddTab (
                    int iPos, LPCTSTR tabName,
                    UINT uTemplateID, CZdUiTabChildDialog *pDialog
                );
        BOOL    AddTab (
                    int iPos, UINT uTabStringID,
                    UINT uTemplateID, CZdUiTabChildDialog *pDialog
                );
        int     GetTabIndex (CZdUiTabChildDialog *pDialog);
        BOOL    RemoveTab (int iPos);

public:
	//{{AFX_DATA(CZdUiTabMainDialog)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CZdUiTabMainDialog)
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);        
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void OnCancel();
    virtual void OnOK();
    void RaiseApplyEvent();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZdUiTabMainDialog)
    afx_msg void OnSize(UINT nType, int cx, int cy);    
	//}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
