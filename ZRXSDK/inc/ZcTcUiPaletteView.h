#pragma once

#include "ZcTcUiCatalogView.h"


class ZCTCUI_PORT CZcTcUiPaletteView : public CZcTcUiCatalogView  
{
public:
    CZcTcUiPaletteView();
    virtual ~CZcTcUiPaletteView();

protected:
    virtual DROPEFFECT  DragEnter           (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  DragOver            (ZDUI_DRAGDATA* pDragData);
    virtual void        DragLeave           (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  Drop                (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  DropEx              (ZDUI_DRAGDATA* pDragData);

protected:
    //{{AFX_VIRTUAL(CZcTcUiPaletteView)
    //}}AFX_VIRTUAL

protected:
    // Protected constructor
    CZcTcUiPaletteView(ZcTcUiSystemInternals*);

protected:
    //{{AFX_MSG(CZcTcUiPaletteView)
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnInvokeCommand(UINT nID);
    afx_msg void OnPaletteRemove();
    afx_msg void OnCatalogItemSpecifyImage();
    afx_msg void OnCatalogItemRemoveImage();
    afx_msg void OnCatalogItemUpdateImage();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

