#ifndef ZCUIDLGWORKSHEET_H
#define ZCUIDLGWORKSHEET_H

#include "zduiDIalogWorksheet.h"



class ZCUI_PORT CZcUiDialogWorksheet : public CZdUiDialogWorksheet
{
    DECLARE_DYNAMIC(CZcUiDialogWorksheet);
    
public:
    CZcUiDialogWorksheet(UINT ID, CWnd* pParent = NULL, HINSTANCE hResInst=NULL);
    ~CZcUiDialogWorksheet();

    // Dialog Data
    //{{AFX_DATA(CZcUiDialogWorksheet)
    enum { IDD = 0 };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CZcUiDialogWorksheet)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    // Generated message map functions
    //{{AFX_MSG(CZcUiDialogWorksheet)
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg void OnNcPaint();
    afx_msg BOOL OnNcActivate(BOOL bActive);
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg void OnNcLButtonDown( UINT nHitTest, CPoint point );
    afx_msg void OnNcLButtonUp( UINT nHitTest, CPoint point );
    afx_msg void OnNcMouseMove(UINT nHitTest,CPoint point);
    afx_msg void OnMouseMove(UINT nHitTest,CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
    afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
    afx_msg void OnSysColorChange();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif /* ZCUIDLGWORKSHEET_H */
