#ifndef _ARXPORT_ACTC_H_
#define _ARXPORT_ACTC_H_ 1


#include "AdAChar.h"



class ZcTcTool;
class ZcTcStockTool;
class ZcTcCatalog;
class ZcTcCatalogItem;
class ZcTcScheme;
class ZcTcCatalogSet;
class ZcTcSystemInternals;
class ZcTcImpCatalogItem;
class ZcTcCatalogItemReactor;



typedef ZcTcTool                    AcTcTool;
typedef ZcTcStockTool               AcTcStockTool;
typedef ZcTcCatalog                 AcTcCatalog;
typedef ZcTcCatalogItem             AcTcCatalogItem;
typedef ZcTcScheme                  AcTcScheme;
typedef ZcTcCatalogSet              AcTcCatalogSet;
typedef ZcTcSystemInternals         AcTcSystemInternals;
typedef ZcTcImpCatalogItem          AcTcImpCatalogItem;
typedef ZcTcCatalogItemReactor      AcTcCatalogItemReactor;


#include "..\inc\ZcTc.h"

#define ACTC_IMAGE_NORMAL                         ZCTC_IMAGE_NORMAL                  
#define ACTC_IMAGE_SELECTED                       ZCTC_IMAGE_SELECTED               
#define ACTC_IMAGE_HALO                           ZCTC_IMAGE_HALO                    
#define ACTC_IMAGE_SHADOW                         ZCTC_IMAGE_SHADOW                  


#define ACTC_MAX_CATALOG_ITEM_NAME               ZCTC_MAX_CATALOG_ITEM_NAME                   
#define ACTC_MAX_CATALOG_ITEM_DESCRIPTION        ZCTC_MAX_CATALOG_ITEM_DESCRIPTION 
#define ACTC_MAX_CATALOG_ITEM_KEYWORDS           ZCTC_MAX_CATALOG_ITEM_KEYWORDS    
#define ACTC_MAX_CATALOG_ITEM_TOOLTIP_TEXT       ZCTC_MAX_CATALOG_ITEM_TOOLTIP_TEXT  
#define ACTC_MAX_CATALOG_ITEM_LINK_NAME          ZCTC_MAX_CATALOG_ITEM_LINK_NAME    
#define ACTC_MAX_SCHEME_NAME                     ZCTC_MAX_SCHEME_NAME               
#define ACTC_MAX_TOOL_NAME                       ZCTC_MAX_TOOL_NAME                
#define ACTC_MAX_STOCKTOOL_NAME                  ZCTC_MAX_STOCKTOOL_NAME            
#define ACTC_MAX_PALETTE_NAME                    ZCTC_MAX_PALETTE_NAME                             
#define ACTC_MAX_PACKAGE_NAME                    ZCTC_MAX_PACKAGE_NAME             
#define ACTC_MAX_CATEGORY_NAME                   ZCTC_MAX_CATEGORY_NAME            
#define ACTC_MAX_CATALOG_NAME                    ZCTC_MAX_CATALOG_NAME              
#define ACTC_MAX_URL                             ZCTC_MAX_URL                    
#define ACTC_MAX_PATH                            ZCTC_MAX_PATH                     
#define ACTC_MAX_COMMAND_NAME                    ZCTC_MAX_COMMAND_NAME             
#define ACTC_MAX_COMMAND_ARGS                    ZCTC_MAX_COMMAND_ARGS             
#define ACTC_MAX_HELPINFO_FILE                   ZCTC_MAX_HELPINFO_FILE            
#define ACTC_MAX_HELPINFO_COMMAND                ZCTC_MAX_HELPINFO_COMMAND                       
#define ACTC_MAX_HELPINFO_DATA                   ZCTC_MAX_HELPINFO_DATA             
#define ACTC_MAX_PARENT_DOCUMENT_NAME            ZCTC_MAX_PARENT_DOCUMENT_NAME
#define ACTC_MAX_PUBLISHER_NAME                  ZCTC_MAX_PUBLISHER_NAME             
#define ACTC_MAX_PRODUCT_NAME                    ZCTC_MAX_PRODUCT_NAME               
#define ACTC_MAX_LOCALE                          ZCTC_MAX_LOCALE

#define ACTC_POSTDOWNLOADCMD_EXECUTE             ZCTC_POSTDOWNLOADCMD_EXECUTE 
#define ACTC_DEFAULTDIR_IMAGE                    ZCTC_DEFAULTDIR_IMAGE               
#define ACTC_DEFAULTFILE_IMAGE                   ZCTC_DEFAULTFILE_IMAGE              

#define AcTc    ZcTc
using namespace AcTc;
#define CreateAcadTool          CreateZcadTool
#define CreateAcadStockTool     CreateZcadStockTool

typedef ZCTC_IMAGE_INFO              ACTC_IMAGE_INFO;
typedef ZCTC_TARGET_PRODUCT_INFO     ACTC_TARGET_PRODUCT_INFO;
typedef ZcTcImage                    AcTcImage;
typedef ZcTcImageList                AcTcImageList;
typedef ZcTcManager                  AcTcManager;
typedef ZcTcScheme                   AcTcScheme;

typedef ZcTcCatalogSet               AcTcCatalogSet;
typedef ZcTcCatalogItem              AcTcCatalogItem;
typedef ZcTcCategory                 AcTcCategory;

typedef ZcTcStockTool                AcTcStockTool;
typedef ZcTcTool                     AcTcTool;
typedef ZcTcPackage                  AcTcPackage;
typedef ZcTcPalette                  AcTcPalette;  

typedef ZcTcCatalogItemReactor       AcTcCatalogItemReactor;

#define AcTcInitialize      ZcTcInitialize
#define AcTcUninitialize    ZcTcUninitialize
#define AcTcGetManager      ZcTcGetManager
#define AcTcDownloadItem            ZcTcDownloadItem
#define AcTcRefreshItem             ZcTcRefreshItem
#define AcTcSort                    ZcTcSort

#endif




