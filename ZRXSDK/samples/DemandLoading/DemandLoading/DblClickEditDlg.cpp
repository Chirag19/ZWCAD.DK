// DblClickEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DblClickEditDlg.h"




// CDblClickEditDlg dialog

IMPLEMENT_DYNAMIC(CDblClickEditDlg, CDialog)

CDblClickEditDlg::CDblClickEditDlg(SignEntity* pDblClickEnt, CWnd* pParent /*=NULL*/)
	: CDialog(CDblClickEditDlg::IDD, pParent)
	, m_dblRadius(0)
	, m_dblCenterX(0)
	, m_dblCenterY(0)
	, m_dblCenterZ(0)
{
	m_pSignEntity = pDblClickEnt;
}

CDblClickEditDlg::~CDblClickEditDlg()
{
}

void CDblClickEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RADIUS, m_dblRadius);
	DDX_Text(pDX, IDC_EDIT_CENTER_X, m_dblCenterX);
	DDX_Text(pDX, IDC_EDIT_CENTER_Y, m_dblCenterY);
	DDX_Text(pDX, IDC_EDIT_CENTER_Z, m_dblCenterZ);
}


BEGIN_MESSAGE_MAP(CDblClickEditDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CDblClickEditDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDblClickEditDlg message handlers

BOOL CDblClickEditDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_pSignEntity->getRadius(m_dblRadius);
	ZcGePoint3d pntCenter;
	m_pSignEntity->getCenter(pntCenter);
	m_dblCenterX = pntCenter.x;
	m_dblCenterY = pntCenter.y;
	m_dblCenterZ = pntCenter.z;


	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDblClickEditDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	
	OnOK();
}

