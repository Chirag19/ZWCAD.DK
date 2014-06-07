#ifndef _ARXPORT_ADUI_H_
#define _ARXPORT_ADUI_H_ 1


class CZdUiThemeManager; 
typedef CZdUiThemeManager CAdUiThemeManager;


class CZdUiBaseDialog;
class CZdUiComboBox;
class CZdUiDialog;
class CZdUiDialogBar;
class CZdUiFileDialog;
class CZdUiTab;
class CZdUiTabChildDialog;
class CZdUiTabExtensionManager;
class CZdUiTabMainDialog;
class CZdUiDialogWorksheet;
class CZdUiDropTarget;
class CZdUiTheme;
class CZdUiPalette;
class CZdUiPaletteSet;
class CZdUiThemeMgrReactor;
class CZduiLabelEdit;

typedef  CZdUiBaseDialog                 CAdUiBaseDialog;
typedef  CZdUiComboBox                   CAdUiComboBox;
typedef  CZdUiDialog                     CAdUiDialog;
typedef  CZdUiDialogBar                  CAdUiDialogBar;
typedef  CZdUiFileDialog                 CAdUiFileDialog;
typedef  CZdUiTab                        CAdUiTab;
typedef  CZdUiTabChildDialog             CAdUiTabChildDialog;
typedef  CZdUiTabExtensionManager        CAdUiTabExtensionManager;
typedef  CZdUiTabMainDialog              CAdUiTabMainDialog;
typedef  CZdUiDialogWorksheet            CAdUiDialogWorksheet;
typedef  CZdUiDropTarget                 CAdUiDropTarget;
typedef  CZdUiTheme                      CAdUiTheme;
typedef  CZdUiPalette                    CAdUiPalette;
typedef  CZdUiPaletteSet                 CAdUiPaletteSet;
typedef  CZdUiThemeMgrReactor            CAdUiThemeMgrReactor;
typedef  CZduiLabelEdit                  CAduiLabelEdit;


#include "..\inc\zdui.h"

#define InitAdUiDLL                  InitZdUiDLL
#define AdUiAlertDialog              ZdUiAlertDialog
#define AdUiDataValidationLevel      ZdUiDataValidationLevel
#define AdUiFindContextHelpFullPath  ZdUiFindContextHelpFullPath
#define AdUiSubstituteShellFont      ZdUiSubstituteShellFont 
#define AdUiGetThemeManager          ZdUiGetThemeManager 


namespace AdUi
{
	enum AdUiIconMode{
        kSmall = 0,
        kLarge
    };

    enum AdUiImage
    {
        kImageSmall      = 1,
        kImageLarge      = 2,

        kImageEnable     = 4,
        kImageDisable    = 8,
    };

}; 





#include <winreg.h>


#include <afxole.h>

#include "aduiRegistryAccess.h"

#include "aduiMessage.h"
#include "aduiDropTarget.h"
#include "aduiTabExtension.h"
#include "aduiTextTip.h"
#include "aduiButton.h"
#include "aduiTabCtrl.h"

#include "aduiBaseDialog.h"
#include "aduiDialog.h"
#include "aduiDialogBar.h"
#include "aduiFileDialog.h"
#include "aduiTabChildDialog.h"
#include "aduiTabMainDialog.h"

#include "aduiEdit.h"
#include "aduiHeaderCtrl.h"
#include "aduiListBox.h"
#include "aduiListCtrl.h"
#include "aduiComboBox.h"

#include "aduiDock.h"

#include "aduiVolumeDescriptor.h"
#include "aduiPathname.h"
#include "aduiPalette.h"
#include "aduiPaletteSet.h"

#endif


