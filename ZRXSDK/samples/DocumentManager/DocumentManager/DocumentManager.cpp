// DocumentManager.cpp 


#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <string.h>
#include "Zdesk.h"
#include "zced.h"
#include "zcdocman.h"
#include "zdslib.h"
#include "zctrans.h"
#include "zrxmfcapi.h"
#include "ZcExtensionModule.h"


class ZcDocReactor;
class ZxEditorReactor;

ZcDocReactor*      g_pDocReactor = NULL;       
ZxEditorReactor*   g_pEditReactor = NULL;   


ZC_IMPLEMENT_EXTENSION_MODULE(docmanDLL);

class ZxEditorReactor : public ZcEditorReactor
{
public:
	virtual void saveComplete (ZcDbDatabase*, const char* pActualName);
};


void ZxEditorReactor::saveComplete (ZcDbDatabase*, const char* pActualName)
{
	ZcApDocument* pDoc = zcDocManager->curDocument();
	if (pDoc)
	{
		zcutPrintf(" The document save complete: %s\n", pDoc->fileName());
	}
}

class ZcDocReactor : public ZcApDocManagerReactor
{
public:
	virtual void documentCreateStarted(ZcApDocument* pDoc);
	virtual void documentCreated(ZcApDocument* pDoc);
	virtual void documentToBeDestroyed(ZcApDocument* pDoc);
	virtual void documentDestroyed(const ZCHAR* fileName);

	virtual void documentBecameCurrent(ZcApDocument* pDoc);
	virtual void documentToBeActivated(ZcApDocument* pDoc );
	virtual void documentToBeDeactivated(ZcApDocument* pDoc );
	virtual void documentActivated(ZcApDocument* pDoc);
};




void ZcDocReactor::documentCreated(ZcApDocument* pDoc)
{
	if (pDoc)
	{
		zcutPrintf(" The document created: %s\n", pDoc->fileName());
	}
}

void ZcDocReactor::documentToBeDestroyed(ZcApDocument* pDoc)
{
	if (!zcDocManager) 	return;

	if (zcDocManager->documentCount() == 1) 
	{
		zcutPrintf(" The last document to be destroyed %s\n", pDoc->fileName());
	} 
	else
	{
		zcutPrintf(" The document To be destroyed: %s\n", pDoc->fileName());
	}
}

void ZcDocReactor::documentToBeActivated(ZcApDocument* pActivatingDoc)
{
	if (pActivatingDoc) 
	{
		zcutPrintf(" The document to be Activated: %s\n", pActivatingDoc->fileName());
	}
}

void ZcDocReactor::documentToBeDeactivated(ZcApDocument* pDeactivatingDoc)
{
	if (pDeactivatingDoc) 
	{
		zcutPrintf(" The document to be deactivated: %s\n", pDeactivatingDoc->fileName());
	}
}

void ZcDocReactor::documentBecameCurrent(ZcApDocument* pDoc)
{
	if(pDoc)
	{
		zcutPrintf(" The document became current: %s\n", pDoc->fileName());
	}
}

void ZcDocReactor::documentCreateStarted(ZcApDocument* pDoc)
{
	if (pDoc)
	{
		zcutPrintf(" The document start created:  %s\n", pDoc->fileName());
	}
}

void ZcDocReactor::documentDestroyed(const ZCHAR* fileName)
{
	if (fileName)
	{
		zcutPrintf(" The document destroyed: %s\n", fileName);
	}
}

void ZcDocReactor::documentActivated(ZcApDocument* pDoc)
{
	if (pDoc)
	{
		zcutPrintf(" The document activated: %s\n", pDoc->fileName());
	}
}


void listDocuments()
{
	ZcDbDatabase* pDb = zcdbHostApplicationServices()->workingDatabase();
	ZcApDocument* pCurDoc = zcDocManager->document(pDb);
	const char * strCurTitle = pCurDoc->docTitle();

	zcutPrintf("\n The current document title is: %s", strCurTitle);

	ZcApDocumentIterator* pDocIter;
	pDocIter = zcDocManager->newZcApDocumentIterator();

	zcutPrintf("\n-- List all open documents:");

	ZcApDocument* pDoc = NULL;
	int nIndex = 1;

	for ( ; !pDocIter->done(); pDocIter->step()) 
	{
		pDoc = pDocIter->document();

		const char * strTitle = pDoc->docTitle();
		const char * strFileName = pDoc->fileName();

		zcutPrintf("\n [%d]: The file title =  %s;  The file name = %s", nIndex, strTitle, strFileName);		
		
		nIndex++;
	}

	delete pDocIter;
}


void addDocumentReactor()
{
	if (!g_pDocReactor)
	{
		g_pDocReactor = new ZcDocReactor();
		zcDocManager->addReactor(g_pDocReactor);
	}

	if (!g_pEditReactor)
	{
		g_pEditReactor = new ZxEditorReactor();
		zcedEditor->addReactor(g_pEditReactor);
	}

	zcutPrintf("\n  Added reactor to the Document Manager.");
}


void removeDocumentReactor()
{
	if (g_pDocReactor)
	{
		zcDocManager->removeReactor(g_pDocReactor);
		delete g_pDocReactor;
		g_pDocReactor = NULL;
	}
	
	if (g_pEditReactor)
	{
		zcedEditor->removeReactor(g_pEditReactor);
		delete g_pEditReactor;
		g_pEditReactor = NULL;	
	}	

	zcutPrintf("\n  Removed reactor from the Document Manager.");
}


void newDocument()
{
	zcDocManager->newDocument();
	zcutPrintf("\n Create a new document .");
}


void openDocument()
{
	zcDocManager->openDocument();
	zcutPrintf("\n Open a document .");
}

void initApp()
{
	zcedRegCmds->addCommand("DOCUMENTMANAGER",
		"LISTDOCS",
		"listdocs",
		ZCRX_CMD_MODAL,
		listDocuments);

	zcedRegCmds->addCommand("DOCUMENTMANAGER",
		"NEWDOC",
		"newdoc",
		ZCRX_CMD_MODAL ,
		newDocument);

	zcedRegCmds->addCommand("DOCUMENTMANAGER",
		"OPENDOC",
		"opendoc",
		ZCRX_CMD_MODAL | ZCRX_CMD_NONEWSTACK ,
		openDocument);

	zcedRegCmds->addCommand("DOCUMENTMANAGER",
		"ADDWATCH",
		"addwatch",
		ZCRX_CMD_MODAL,
		addDocumentReactor);

	zcedRegCmds->addCommand("DOCUMENTMANAGER",
		"DELWATCH",
		"delwatch",
		ZCRX_CMD_MODAL,
		removeDocumentReactor);

}

void unloadApp()
{
	zcedRegCmds->removeGroup("DOCUMENTMANAGER");

	removeDocumentReactor();
}

extern "C" ZcRx::AppRetCode
zcrxEntryPoint(ZcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case ZcRx::kInitAppMsg:
		zcrxDynamicLinker->unlockApplication(pkt);
		zcrxDynamicLinker->registerAppMDIAware(pkt);
		initApp();
		break;
	case ZcRx::kUnloadAppMsg:
		unloadApp();
		break;
	}
	return ZcRx::kRetOK;
}