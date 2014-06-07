
// ZwInteAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZwInteApp.h"
#include "ZwInteAppDlg.h"
#include "..\ZwInteBase\ZwInteBase_i.h"
#include "..\ZwInteBase\ZwInteBase_i.c"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZwInteAppDlg dialog




CZwInteAppDlg::CZwInteAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZwInteAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZwInteAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CZwInteAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CZwInteAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CZwInteAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CZwInteAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CZwInteAppDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CZwInteAppDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CZwInteAppDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CZwInteAppDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CZwInteAppDlg message handlers

BOOL CZwInteAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZwInteAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZwInteAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool InvokeComInterface(int iOpera)
{
	CString strTitleDef		=	"";
	CString strBomDef		=	"";
	CString strTitleData	=	"图样代号=GB678/456;设计 = HXF; 审核 = 中望";
	CString strBomData		=   "序号=1,代号=H3807,名称=零件1,数量=,材料=T749,单重=,总重=,备注=,零件类型=;序号=2,代号=H3802,名称=零件2,数量=,材料=T748,单重=,总重=,备注=,零件类型=";

	::CoInitialize(NULL);

	HRESULT hr;
	LPCLASSFACTORY pLocalClassFact = NULL;
	IZwInteCom *pInterfaceObj = NULL;

	hr = CoGetClassObject(CLSID_ZwInteCom, CLSCTX_LOCAL_SERVER, NULL,IID_IClassFactory, (void**)&pLocalClassFact);
	if(SUCCEEDED(hr))
	{
		hr = pLocalClassFact->CreateInstance(NULL, IID_IZwInteCom, (void**)&pInterfaceObj);
		if (SUCCEEDED(hr))
		{
			switch (iOpera)
			{
			case 1:	
				hr = pInterfaceObj->ReadTbData(strTitleDef.AllocSysString(), strBomDef.AllocSysString(),_bstr_t("C:\\Test1.dwg"));
				break;
			case 2:
				hr = pInterfaceObj->WriteTbData(strTitleData.AllocSysString(), strBomData.AllocSysString(), _bstr_t("C:\\Test1.dwg"));
				break;
			case 3:
				hr = pInterfaceObj->ReadTbDataX(_bstr_t("C:\\InputForR.xml"));
				break;
			case 4:
				hr = pInterfaceObj->WriteTbDataX(_bstr_t("C:\\InputForW.xml"));
				break;
			case 5:
				hr = pInterfaceObj->InsertText(_bstr_t("C:\\Test1.dwg"), _bstr_t("ZWSOFT{10,8,-300,100}"));
				break;
			case 6:
				hr = pInterfaceObj->InsertBmp(_bstr_t("C:\\Test1.dwg"), _bstr_t("C:\\Insert.jpg{8,4,-157.5,17.5}"));
				break;
			case 7:
				hr = pInterfaceObj->InsertDwg(_bstr_t("C:\\Test1.dwg"), _bstr_t("C:\\Insert.dwg{8,4,-157.5,17.5}"));
				break;
			default:
				break;
			}
		}
	}

	if(NULL != pLocalClassFact) hr = pLocalClassFact->Release();
	if(NULL != pInterfaceObj) hr = pInterfaceObj->Release();

	::CoUninitialize();

	if (SUCCEEDED(hr)) 	return true;

	return false;
}


void CZwInteAppDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(1);
}

void CZwInteAppDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(2);
}

void CZwInteAppDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(3);
}

void CZwInteAppDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(4);
}

void CZwInteAppDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(5);
}

void CZwInteAppDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(6);
}

void CZwInteAppDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	InvokeComInterface(7);
}
