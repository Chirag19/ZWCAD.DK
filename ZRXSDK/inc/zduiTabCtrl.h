#ifndef _zduiTabCtrl_h
#define _zduiTabCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiTab : public CTabCtrl {
friend class CZdUiTabMainDialog;
friend class CZdUiTabChildDialog;

    DECLARE_DYNAMIC(CZdUiTab);

public:
	            CZdUiTab ();
virtual         ~CZdUiTab ();

// Operations
private:
        BOOL    m_bDirty;
        HWND    m_hwndFocus;
        int     m_iActiveTab;
        UINT    m_uApplyButtonID;

        BOOL    BringTabToFront(int iPos);
        void    PositionTabDialog (CZdUiTabChildDialog *pDialog);
public:
        BOOL    AddTab (
                    int iPos, CString const& sTabname,
                    UINT uTemplateID, CZdUiTabChildDialog *pDialog
                );
        BOOL    AddTab (
                    int iPos, UINT uTabStringID,
                    UINT uTemplateID, CZdUiTabChildDialog *pDialog
                );

        BOOL    DeleteItem (int iPos);

        BOOL    DestroyTab (int iPos, BOOL bUpdateData=FALSE);

        int     GetActiveTab ();
        CZdUiTabMainDialog *GetMainDialog ();
        int     GetTabIndex (CZdUiTabChildDialog *pDialog);
        CZdUiTabChildDialog *GetDialogPointer (int iPos);
        BOOL    IsDirty ();
        
        BOOL    RemoveTab (int iPos);

        int     SetActiveTab (int iPos);
        void    SetApplyButtonID (UINT uID);
        
        void    SetChildFocus ();

        void    SetDirty (BOOL bDirty=TRUE);
        void    SetValidationInfo (CDataExchange* pDX);

public:
        BOOL    DisplayData ();
        BOOL    ExchangeData (BOOL bSaveAndValidate);
        BOOL    ValidateData ();

public:
	//{{AFX_VIRTUAL(CZdUiTab)
	protected:
	virtual void PreSubclassWindow();    
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZdUiTab)
    afx_msg void OnSelChange(NMHDR* pNMHDR, LRESULT* pResult);    
    afx_msg void OnSelChanging(NMHDR* pNMHDR, LRESULT* pResult);  
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
