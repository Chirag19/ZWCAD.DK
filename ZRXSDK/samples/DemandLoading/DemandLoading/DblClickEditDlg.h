#pragma once

#include "resource.h"
#include "SignEntity.h"

// CDblClickEditDlg dialog

class CDblClickEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CDblClickEditDlg)

public:
	CDblClickEditDlg(SignEntity* pDblClickEnt, CWnd* pParent = NULL);   // standard constructor
	virtual ~CDblClickEditDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_DBLCLICK_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

public:
	double		m_dblRadius;
	double		m_dblCenterX;
	double		m_dblCenterY;
	double		m_dblCenterZ;
	SignEntity* m_pSignEntity;
	
};
