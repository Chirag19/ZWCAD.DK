#include "stdafx.h"
#include "Resource.h"
#include "SCRMenu.h"
#include "zced.h"
#include "zcedzds.h"
#include "zdbapserv.h"

extern Zdesk::Boolean zcedPostCommand(const char* cmdMsg);

// SCRMenu

IMPLEMENT_DYNAMIC(CSCRMenu, CDialogBar)
CSCRMenu::CSCRMenu()
{
}

CSCRMenu::~CSCRMenu()
{
}

BEGIN_MESSAGE_MAP(CSCRMenu, CDialogBar)
	ON_BN_CLICKED(IDC_MESSAGEBOX, OnBtnMessagebox)
	ON_BN_CLICKED(IDC_LINE, OnBtnLine)
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)
	ON_BN_CLICKED(IDC_GETENTITY, OnBtnGetObjInfo)
	ON_CBN_CLOSEUP(IDC_LAYER, OnBtnCloseupLayer)
END_MESSAGE_MAP()



// SCRMenu message handle

void CSCRMenu::OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL /*bDisableIfNoHndler*/)
{

}

void CSCRMenu::InitLayerComboBox()
{
	struct resbuf resbuf;
	m_LayerComboBox.ResetContent();

	ZcDbDatabase *pDb = zcdbHostApplicationServices()->workingDatabase();
	if(!pDb) return;

	CString sCurLayer = CString("");
	if(zcedGetVar("CLAYER", &resbuf) == RTNORM && resbuf.resval.rstring)
	{
		sCurLayer = resbuf.resval.rstring;

		delete resbuf.resval.rstring;
		resbuf.resval.rstring = NULL;
	}

	ZcDbLayerTable *pLayerTab;
	pDb->getSymbolTable(pLayerTab, ZcDb::kForRead);
	if(pLayerTab)
	{
		int nIndex = 0;
		ZCHAR *pLayerName;
		ZcDbLayerTableIterator *pLtIterator;
		pLayerTab->newIterator(pLtIterator);
		for (; !pLtIterator->done(); pLtIterator->step())
		{
			ZcDbLayerTableRecord *pLayerTabRec;
			pLtIterator->getRecord(pLayerTabRec, ZcDb::kForRead);
			pLayerTabRec->getName(pLayerName);
			nIndex = m_LayerComboBox.AddString((LPCTSTR)pLayerName);
			if(sCurLayer == pLayerName)
				m_LayerComboBox.SetCurSel(nIndex);
			pLayerTabRec->close();
		}
		delete pLtIterator;			
	}

	pLayerTab->close();
}

BOOL CSCRMenu::ScreenMenu()
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	HWND hMain = zcedGetZcadFrame()->m_hWnd;
	CFrameWnd* pFrameWnd = (CFrameWnd*)CWnd::FromHandle(hMain);

	if(pFrameWnd)
	{
		if(!GetSafeHwnd())
		{
			if(Create(pFrameWnd, IDD_DIALOG, CBRS_RIGHT, 0))
			{
				SetWindowText("DialogBar");
				pFrameWnd->EnableDocking(CBRS_ALIGN_RIGHT);
				EnableDocking(CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT);
				pFrameWnd->DockControlBar(this, AFX_IDW_DOCKBAR_RIGHT);
				return TRUE;
			}
		}
		else if(GetSafeHwnd())
		{
			InitLayerComboBox();
			ShowWindow(SW_SHOW);
			pFrameWnd->DockControlBar(this, AFX_IDW_DOCKBAR_RIGHT);
			return TRUE;
		}
	}

	return FALSE;
}

void CSCRMenu::OnBtnMessagebox()
{
	MessageBox("Dock Bar");
}

void CSCRMenu::OnBtnLine()
{
	zcedPostCommand("line");
}

LRESULT CSCRMenu::OnInitDialog(WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = Default();

	m_LayerComboBox.SubclassDlgItem(IDC_LAYER, this);
	m_EntityInfoList.SubclassDlgItem(IDC_INFOLIST, this);

	InitLayerComboBox();

	CRect rcClient;
	m_EntityInfoList.GetClientRect(&rcClient);
	int nWidth = rcClient.Width() / 2;

	m_EntityInfoList.InsertColumn(0,"Data", LVCFMT_CENTER, nWidth);
	m_EntityInfoList.InsertColumn(0,"Name", LVCFMT_CENTER, nWidth);
	m_EntityInfoList.InsertItem(0, "Entity Type");
	m_EntityInfoList.InsertItem(1, "Layer");
	m_EntityInfoList.InsertItem(2, "Handle");

	return lRes;
}

void CSCRMenu::OnBtnGetObjInfo()
{
	zcedPostCommand("ObjInfo");
}

void CSCRMenu::OnBtnCloseupLayer()
{
	int nCurSel = m_LayerComboBox.GetCurSel();

	struct resbuf resbuf;
	if(zcedGetVar("CLAYER", &resbuf) == RTNORM)
	{
		CString sLayer = CString("");
		m_LayerComboBox.GetLBText(nCurSel, sLayer);
		if(sLayer != "" && sLayer != resbuf.resval.rstring)
		{
			if(resbuf.resval.rstring)
			{
				delete resbuf.resval.rstring;
				resbuf.resval.rstring = NULL;
			}

			resbuf.resval.rstring = (char*)(LPCTSTR)sLayer;
			zcedSetVar("CLAYER", &resbuf);
		}
	}
}