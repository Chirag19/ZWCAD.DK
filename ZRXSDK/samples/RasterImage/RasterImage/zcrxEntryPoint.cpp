//----- zcrxEntryPoint.h

#include "StdAfx.h"
#include "Image.h"
#include "resource.h"


// EntryPoint
class CRasterImageApp : public ZcRxZrxApp 
{

public:
	CRasterImageApp () : ZcRxZrxApp () {}

	virtual ZcRx::AppRetCode On_kInitAppMsg (void *pkt)
	{		
		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kInitAppMsg (pkt) ;
		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kUnloadAppMsg (void *pkt)
	{
		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kUnloadAppMsg (pkt) ;
		return (retCode) ;
	}

	virtual void RegisterServerComponents ()
	{

	}

	static void ImageCmdGroupCreateImage(void)
	{		
		CustomImageApp	imageApp;
		ZcDbObjectId		entId;	

		Zcad::ErrorStatus	status;
		status = imageApp.newImageAttach (entId);	

		if (status != Zcad::eOk)
		{
			zcutPrintf("\n Attach image failed."); 
		}
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ZRX_ENTRYPOINT(CRasterImageApp)
ZCED_ZRXCOMMAND_ENTRY_AUTO(CRasterImageApp, ImageCmdGroup, CreateImage, CreateImage, ZCRX_CMD_TRANSPARENT, NULL)
