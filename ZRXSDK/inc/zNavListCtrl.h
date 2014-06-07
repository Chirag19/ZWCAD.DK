

#ifndef _ZNavListCtrl_h
#define _ZNavListCtrl_h

#pragma once


class  CNavListCtrl;

class CNavDropSource : public COleDropSource
{
public:
    CNavDropSource();       

    CNavListCtrl* m_pListCtrl;

    
    SCODE GiveFeedback(DROPEFFECT dropEffect);
	DECLARE_MESSAGE_MAP()
};


class ZNAV_PORT CNavListCtrl : public CZdUiListCtrl {
public:
    CNavListCtrl ();


public:


protected:
    //{{AFX_MSG()
    afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
    //}}AFX_MSG
    afx_msg LRESULT OnHandleDrag(UINT_PTR pDataSource, LPARAM nSelectedItem);
    DECLARE_MESSAGE_MAP()

    CImageList* m_pDragImage;
    CNavDropSource m_dropSource;

};

#endif
