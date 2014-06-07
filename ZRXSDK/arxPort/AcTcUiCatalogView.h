#ifndef _ARXPORT_ACTCUICATALOGVIEW_H_
#define _ARXPORT_ACTCUICATALOGVIEW_H_ 1


#include "AcTcUi.h"
#include "AcTcUiCatalogViewItem.h"


class CZcTcUiScheme;

typedef CZcTcUiScheme         CAcTcUiScheme;


#include "..\inc\ZcTcUiCatalogView.h"

#define   AcTcCatalogItemArray     ZcTcCatalogItemArray



#define ACTCUI_IDW_CATALOGVIEW                 ZCTCUI_IDW_CATALOGVIEW

#define ACTCUI_CVSTYLE_SHOWTEXT                ZCTCUI_CVSTYLE_SHOWTEXT

#define ACTCUI_CVSTYLE_SAVE_ORDER_IN_CATALOG   ZCTCUI_CVSTYLE_SAVE_ORDER_IN_CATALOG

#define ACTCUI_CVSTYLE_NO_QSL                  ZCTCUI_CVSTYLE_NO_QSL

#define ACTCUI_CVSTYLE_NO_SELECTION            ZCTCUI_CVSTYLE_NO_SELECTION

#define ACTCUI_CVSTYLE_NO_VIEW_BUTTON          ZCTCUI_CVSTYLE_NO_VIEW_BUTTON

#define ACTCUI_CVSTYLE_LISTVIEW                ZCTCUI_CVSTYLE_LISTVIEW

#define ACTCUI_CVSTYLE_TOOLTIPS                ZCTCUI_CVSTYLE_TOOLTIPS

#define ACTCUI_CVSTYLE_MULTISELECT             ZCTCUI_CVSTYLE_MULTISELECT

#define ACTCUI_CVSTYLE_EDITLABELS              ZCTCUI_CVSTYLE_EDITLABELS

#define ACTCUI_CVSTYLE_HOVERSELECT             ZCTCUI_CVSTYLE_HOVERSELECT

#define ACTCUI_CVSTYLE_NO_DRAGDROP             ZCTCUI_CVSTYLE_NO_DRAGDROP

#define ACTCUI_CVSTYLE_NO_CUT                  ZCTCUI_CVSTYLE_NO_CUT

#define ACTCUI_CVSTYLE_NO_COPY                 ZCTCUI_CVSTYLE_NO_COPY

#define ACTCUI_CVSTYLE_NO_PASTE                ZCTCUI_CVSTYLE_NO_PASTE

#define ACTCUI_CVSTYLE_NO_REFRESH              ZCTCUI_CVSTYLE_NO_REFRESH

#define ACTCUI_CVSTYLE_NO_REMOVE               ZCTCUI_CVSTYLE_NO_REMOVE

#define ACTCUI_CVSTYLE_NO_RENAME               ZCTCUI_CVSTYLE_NO_RENAME

#define ACTCUI_CVSTYLE_NO_PROPERTIES           ZCTCUI_CVSTYLE_NO_PROPERTIES

#define ACTCUI_CVSTYLE_NO_HELP                 ZCTCUI_CVSTYLE_NO_HELP

#define ACTCUI_CVSTYLE_NO_VIEWOPTIONS          ZCTCUI_CVSTYLE_NO_VIEWOPTIONS

#define ACTCUI_CVSTYLE_NO_OPERATIONS        (ACTCUI_CVSTYLE_NO_CUT        | \
                                             ACTCUI_CVSTYLE_NO_COPY       | \
                                             ACTCUI_CVSTYLE_NO_PASTE      | \
                                             ACTCUI_CVSTYLE_NO_REFRESH    | \
                                             ACTCUI_CVSTYLE_NO_REMOVE     | \
                                             ACTCUI_CVSTYLE_NO_RENAME     | \
                                             ACTCUI_CVSTYLE_NO_PROPERTIES | \
                                             ACTCUI_CVSTYLE_NO_HELP       | \
                                             ACTCUI_CVSTYLE_NO_VIEWOPTIONS)
#define ACTCUI_CVSTYLE_NO_FLYOUT            ZCTCUI_CVSTYLE_NO_FLYOUT
#define ACTCUI_CVSTYLE_NO_SCROLLBAR         ZCTCUI_CVSTYLE_NO_SCROLLBAR



#define ACTCUI_DDO_ACCEPT_TOOL              ZCTCUI_DDO_ACCEPT_TOOL

#define ACTCUI_DDO_ACCEPT_PALETTE           ZCTCUI_DDO_ACCEPT_PALETTE

#define ACTCUI_DDO_ACCEPT_PACKAGE           ZCTCUI_DDO_ACCEPT_PACKAGE

#define ACTCUI_DDO_ACCEPT_CATEGORY          ZCTCUI_DDO_ACCEPT_CATEGORY

#define ACTCUI_DDO_ACCEPT_CATALOG           ZCTCUI_DDO_ACCEPT_CATALOG

#define ACTCUI_DDO_ACCEPT_STOCKTOOL         ZCTCUI_DDO_ACCEPT_STOCKTOOL

#define ACTCUI_DDO_ACCEPT_FILES             ZCTCUI_DDO_ACCEPT_FILES

#define ACTCUI_DDO_ACCEPT_ALL_ITEMS         (ACTCUI_DDO_ACCEPT_TOOL     | \
                                             ACTCUI_DDO_ACCEPT_STOCKTOOL| \
                                             ACTCUI_DDO_ACCEPT_PALETTE  | \
                                             ACTCUI_DDO_ACCEPT_PACKAGE  | \
                                             ACTCUI_DDO_ACCEPT_CATEGORY | \
                                             ACTCUI_DDO_ACCEPT_CATALOG  | \
                                             ACTCUI_DDO_ACCEPT_FILES)





#define ACTCUI_CVHT_NOWHERE                 ZCTCUI_CVHT_NOWHERE

#define ACTCUI_CVHT_ITEM                    ZCTCUI_CVHT_ITEM

#define ACTCUI_CVHT_ITEMIMAGE               ZCTCUI_CVHT_ITEMIMAGE

#define ACTCUI_CVHT_ITEMLABEL               ZCTCUI_CVHT_ITEMLABEL

#define ACTCUI_CVHT_BACKGROUND              ZCTCUI_CVHT_BACKGROUND

#define ACTCUI_CVHT_ABOVE                   ZCTCUI_CVHT_ABOVE

#define ACTCUI_CVHT_BELOW                   ZCTCUI_CVHT_BELOW

#define ACTCUI_CVHT_LEFT                    ZCTCUI_CVHT_LEFT

#define ACTCUI_CVHT_RIGHT                   ZCTCUI_CVHT_RIGHT

#define ACTCUI_CVHT_ITEMTRIGGER             ZCTCUI_CVHT_ITEMTRIGGER



#define ACTCUI_OVERLAY_ALIGN_TOPLEFT        ZCTCUI_OVERLAY_ALIGN_TOPLEFT
#define ACTCUI_OVERLAY_ALIGN_TOPRIGHT       ZCTCUI_OVERLAY_ALIGN_TOPRIGHT
#define ACTCUI_OVERLAY_ALIGN_BOTTOMLEFT     ZCTCUI_OVERLAY_ALIGN_BOTTOMLEFT
#define ACTCUI_OVERLAY_ALIGN_BOTTOMRIGHT    ZCTCUI_OVERLAY_ALIGN_BOTTOMRIGHT


typedef CZcTcUiCatalogView CAcTcUiCatalogView;

#define OnBeginAcadDrop  OnBeginZcadDrop     
#define OnEndAcadDrop    OnEndZcadDrop

#endif


