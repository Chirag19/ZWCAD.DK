#pragma once
#include "resource.h"

// CZwDialog dialog

class CZwDialog : public CZcUiDialog
{
	DECLARE_DYNAMIC(CZwDialog)

public:
	CZwDialog(CWnd* pParent = NULL, HINSTANCE hInstance =NULL);   // standard constructor
	virtual ~CZwDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPick();
	CString m_strEntName;
};
