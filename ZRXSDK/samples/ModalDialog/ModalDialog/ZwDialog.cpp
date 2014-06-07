// ZwDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ZwDialog.h"


// CZwDialog dialog

IMPLEMENT_DYNAMIC(CZwDialog, CZcUiDialog)

CZwDialog::CZwDialog(CWnd* pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/)
	: CZcUiDialog(CZwDialog::IDD, pParent, hInstance)
	, m_strEntName(_T(""))
{

}

CZwDialog::~CZwDialog()
{
}

void CZwDialog::DoDataExchange(CDataExchange* pDX)
{
	CZcUiDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strEntName);
}


BEGIN_MESSAGE_MAP(CZwDialog, CZcUiDialog)
	ON_BN_CLICKED(IDC_BUTTON_PICK, &CZwDialog::OnBnClickedButtonPick)
END_MESSAGE_MAP()


// CZwDialog message handlers

void CZwDialog::OnBnClickedButtonPick()
{
	// TODO: Add your control notification handler code here
	BeginEditorCommand();

	zds_name entName;
	zds_point pntPick;
	if (zcedEntSel(_T("\n Select an entity"), entName, pntPick) == RTNORM)
	{
		ZcDbObjectId entId;
		zcdbGetObjectId(entId, entName);
		ZcDbObject* pObj = NULL;
		if(zcdbOpenObject(pObj, entId, ZcDb::kForRead) == Zcad::eOk)
		{
			m_strEntName = pObj->isA()->name();
			pObj->close();
		}

	}

	CompleteEditorCommand();

	UpdateData(FALSE);
}
