
#pragma once


#include "zdbxHeaders.h"


#pragma pack (push, 8)
#pragma warning (disable: 4311 4312 4275)

#pragma comment (lib ,"zrx.lib")
#pragma comment (lib ,"zxdb.lib")

#include "zccmd.h"
#include "zced.h"		
#include "zcdocman.h"
#include "zctrans.h"
#include "zcedsel.h"
#include "zcedxref.h"
#include "zlngtrans.h"	
#include "zdbltrans.h"
#include "zcaplmgr.h"
#include "zcedinet.h"
#include "zcedinpt.h"
#include "ZcDblClkEdit.h"
#include "ZcGradThumbEng.h"

#include "zdbjig.h"
#include "zdbmatch.h"
#include "zdbInterferencePE.h"
#include "zdbosnap.h"
#include "zxreflock.h"


#include "zclipdata.h"	


#ifdef _AFXEXT
#include "zgs.h"				
#endif 
#include "ZcGsManager.h"	


#include "ZcPl.h"
#include "ZcPlDSDData.h"
#include "ZcPlDSDEntry.h"
#include "ZcPlHostAppServices.h"
#include "ZcPlObject.h"
#include "ZcPlPlotConfig.h"
#include "ZcPlPlotConfigMgr.h"
#include "ZcPlPlotEngine.h"
#include "ZcPlPlotErrorHandler.h"
#include "ZcPlPlotErrorHandlerLock.h"
#include "ZcPlPlotFactory.h"
#include "ZcPlPlotInfo.h"
#include "ZcPlPlotInfoValidator.h"
#include "ZcPlPlotLogger.h"
#include "ZcPlPlotLoggingErrorHandler.h"
#include "ZcPlPlotProgress.h"
#include "zcplplotreactor.h"
#include "zcplplotreactormgr.h"


#include "zcpublishreactors.h"
#include "zcpublishuireactors.h"


#include "zcdmmapi.h"
#include "zcdmmeplotproperties.h"
#include "zcdmmeplotproperty.h"
#include "zcdmmutils.h"


#ifdef _AFXEXT
#pragma warning (disable: 4275)
#include "zdui.h"
#include "ZcExtensionModule.h"
#include "zduiBaseDialog.h"
#include "zduiButton.h"
#include "zduiComboBox.h"
#include "zduiDialog.h"
#include "zduiDialogBar.h"
#include "zduiDialogWorksheet.h"
#include "zduiDock.h"
#include "zduiDropTarget.h"
#include "zduiEdit.h"
#include "zduiFileDialog.h"
#include "zduiHeaderCtrl.h"
#include "zduiListBox.h"
#include "zduiListCtrl.h"
#include "zduiMessage.h"
#include "zduiPalette.h"
#include "zduiPaletteSet.h"
#include "zduiPathname.h"
#include "zduiRegistryAccess.h"
#include "zduiTabChildDialog.h"
#include "zduiTabCtrl.h"
#include "zduiTabExtension.h"
#include "zduiTabMainDialog.h"
#include "zduiTextTip.h"
#include "zduiTheme.h"
#include "zduiThemeManager.h"
#include "zduiVolumeDescriptor.h"
#include "zduiCoupledGroupCtrl.h"
#include "zduiGroupCtrl.h"
#include "zduipathenums.h"


#include "zcui.h"
#include "zrxmfcapi.h"		
#include "ZcStatusBar.h"
#include "zcuiButton.h"
#include "zcuiComboBox.h"
#include "zcuiDialog.h"
#include "zcuiDialogWorksheet.h"
#include "zcuidock.h"
#include "zcuiEdit.h"
#include "zcuiHeaderCtrl.h"
#include "zcuiListBox.h"
#include "zcuiListCtrl.h"
#include "zcuiNavDialog.h"
#include "zcuiPathname.h"
#include "zcuiString.h"
#include "zcuiTabCtrl.h"


#include "zNav.h"
#include "zNavArray.h"
#include "zNavData.h"
#include "zNavDataArray.h"
#include "zNavDialog.h"
#include "zNavFilter.h"
#include "zNavFilterArray.h"
#include "zNavListCtrl.h"


#include "ZcTc.h"
#include "ZcTcUiManager.h"
#include "ZcTcUI.h"
#include "ZcTcUiCatalogView.h"
#include "ZcTcUiCatalogViewItem.h"
#include "ZcTcUiPaletteView.h"
#include "ZcTcUiToolPalette.h"
#include "ZcTcUiToolPaletteSet.h"
#include "ZcTcUiToolPaletteGroup.h"
#include "ZcTcUiScheme.h"
//#include "ZcTc_i.h"		
#include "zdcdispid.h"


#include "ZcFdUi.h"
#include "ZcFdUiFieldDialog.h"
#include "ZcFdUiFieldDialogHook.h"
#include "ZcFdUiFieldFormatDialog.h"
#include "ZcFdUiFieldFormatList.h"
#include "ZcFdUiFieldManager.h"
#include "ZcFdUiFieldOptionDialog.h"
#include "ZcFdUtil.h"

#endif 


#include "zdsdlg.h"
#include "zdsrxdef.h"
#include "zdslib.h"


#include "zcssgetfilter.h"
#include "zcutasrt.h"
#include "zrxEntryPoint.h"
#include "ZcApDMgr.h"


#ifdef __ATLCOM_H__
#include "zdynpropmgr.h"
#endif 


#ifdef _INC_LEAGACY_HEADERS_
#include "zol_errno.h"	
#endif 


#ifdef _ASE_SUPPORT_
#include "zsisys.h"
#include "zsiappl.h"
#include "zcsptypes.h"
#include "zvoidtry.h"
#include "zsiucode.h"
#include "zsiconst.h"
#include "zsisdata.h"
#include "zsiclass.h"
#include "zseconst.h"
#include "zseclass.h"
#endif 


#ifdef _RENDER_SUPPORT_
//#include "zverror.h"
//#include "zvlib.h"
#endif 

#pragma pack (pop)
