#pragma once

class CSCRMenu : public CDialogBar
{
	DECLARE_DYNAMIC(CSCRMenu)

public:
	CSCRMenu();
	virtual ~CSCRMenu();
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);

public:
	BOOL ScreenMenu();
	CListCtrl m_EntityInfoList;

protected:
	CComboBox m_LayerComboBox;

protected:
	void InitLayerComboBox();

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBtnMessagebox();
	afx_msg void OnBtnLine();
	afx_msg LRESULT OnInitDialog(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBtnGetObjInfo();
	afx_msg void OnBtnCloseupLayer();
};