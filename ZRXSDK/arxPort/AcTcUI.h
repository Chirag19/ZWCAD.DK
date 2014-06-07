#ifndef _ARXPORT_ACTCUI_H_
#define _ARXPORT_ACTCUI_H_ 1

#include "adui.h"
#include "AdAChar.h"
#include <afxtempl.h>


class CZcTcUiManager;
class CZcTcUiToolPaletteSet;
class CZcTcUiToolPalette;
class CZcTcUiCatalogView;
class ZcTcCatalogItem;
class ZcTcCatalog;
class ZcTcStockTool;
class ZcTcTool;

typedef CZcTcUiManager              CAcTcUiManager;
typedef CZcTcUiToolPaletteSet       CAcTcUiToolPaletteSet;
typedef CZcTcUiToolPalette          CAcTcUiToolPalette;
typedef CZcTcUiCatalogView          CAcTcUiCatalogView;
typedef ZcTcCatalogItem             AcTcCatalogItem;
typedef ZcTcCatalog                 AcTcCatalog;
typedef ZcTcStockTool               AcTcStockTool;
typedef ZcTcTool                    AcTcTool;

#include "..\inc\ZcTcUi.h"

#define  AcTcCatalogItemArray          ZcTcCatalogItemArray
#define  AcTcStockToolArray            ZcTcStockToolArray
#define  AcTcCatalogArray              ZcTcCatalogArray
#define  AcTcUiToolPaletteSetArray     ZcTcUiToolPaletteSetArray
#define  AcTcUiToolPaletteArray        ZcTcUiToolPaletteArray
#define  AcTcUiCatalogViewArray        ZcTcUiCatalogViewArray




#define ACTCUI_DRAGFORMAT_CUSTOM        ZCTCUI_DRAGFORMAT_CUSTOM
#define ACTCUI_DRAGFORMAT_IDROP         ZCTCUI_DRAGFORMAT_IDROP
#define ACTCUI_DRAGFORMAT_HDROP         ZCTCUI_DRAGFORMAT_HDROP


#define ACTCUI_CNPS_NOCREATEWINDOW      ZCTCUI_CNPS_NOCREATEWINDOW
#define ACTCUI_CNPS_NOADD               ZCTCUI_CNPS_NOADD
#define ACTCUI_CNPS_CREATEHIDDEN       ZCTCUI_CNPS_CREATEHIDDEN



#define CF_ACTC_CATALOG_ITEM_17_11          CF_ZCTC_CATALOG_ITEM_17_11
#define CF_ACTCUI_CATALOG_ITEM_HEADER_17_11 CF_ZCTCUI_CATALOG_ITEM_HEADER_17_11
#define CF_ACTC_CATALOG_ITEM_17_1           CF_ZCTC_CATALOG_ITEM_17_1
#define CF_ACTCUI_CATALOG_ITEM_HEADER_17_1  CF_ZCTCUI_CATALOG_ITEM_HEADER_17_1
#define CF_ACTC_CATALOG_ITEM_16_1           CF_ZCTC_CATALOG_ITEM_16_1
#define CF_ACTCUI_CATALOG_ITEM_HEADER_16_1  CF_ZCTCUI_CATALOG_ITEM_HEADER_16_1
#define CF_ACTCUI_CATALOG_ITEM              CF_ZCTCUI_CATALOG_ITEM
#define CF_ACTCUI_CATALOG_ITEM_HEADER       CF_ZCTCUI_CATALOG_ITEM_HEADER
#define CF_IDROP_ACTCUI_TOOL                CF_IDROP_ZCTCUI_TOOL
#define CF_IDROP_ACTCUI_PALETTE             CF_IDROP_ZCTCUI_PALETTE
#define CF_IDROP_ACTCUI_PACKAGE             CF_IDROP_ZCTCUI_PACKAGE
#define CF_IDROP_ACTCUI_CATEGORY            CF_IDROP_ZCTCUI_CATEGORY
#define CF_IDROP_ACTCUI_CATALOG             CF_IDROP_ZCTCUI_CATALOG
#define CF_IDROP_ACTCUI_STOCKTOOL           CF_IDROP_ZCTCUI_STOCKTOOL
#define CF_ACTCUI_TOOLBAR_ITEM              CF_ZCTCUI_TOOLBAR_ITEM


#define ACTCUI_PI_SHOW_PROGRESS         ZCTCUI_PI_SHOW_PROGRESS
#define ACTCUI_PI_USE_NEW_IDS           ZCTCUI_PI_USE_NEW_IDS
#define ACTCUI_PI_BREAK_SOURCE_LINK     ZCTCUI_PI_BREAK_SOURCE_LINK
#define ACTCUI_PI_NOTIFY_TOOLS          ZCTCUI_PI_NOTIFY_TOOLS

typedef ZCTCUI_DRAG_HEADER              ACTCUI_DRAG_HEADER;    

#define   AcTcUiGetManager              ZcTcUiGetManager
#define   AcTcUiCopyItems               ZcTcUiCopyItems
#define   AcTcUiGetDragInfo             ZcTcUiGetDragInfo
#define   AcTcUiPasteItems              ZcTcUiPasteItems
#define   AcTcUiGetToolPaletteWindow    ZcTcUiGetToolPaletteWindow
#define   AcTcUiFilterShapesDialog      ZcTcUiFilterShapesDialog

#endif
