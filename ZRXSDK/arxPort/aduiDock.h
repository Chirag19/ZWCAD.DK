#ifndef _ARXPORT_ADUIDOCK_H_
#define _ARXPORT_ADUIDOCK_H_

#include "..\inc\zduiDock.h"



#include <afxpriv.h>
#include "AdAChar.h"


class CPaletteSetTooltip;
class CZdUiDockFrame;

typedef CZdUiDockFrame CAdUiDockFrame;

#include "..\inc\zduiDock.h"

#define ADUI_DOCK_POSITION_TOOL_KEY  ZDUI_DOCK_POSITION_TOOL_KEY
#define ADUI_XML_DOCK_TOOL_INFO      ZDUI_XML_DOCK_TOOL_INFO
#define ADUI_DOCK_STARTUP_TOOL_KEY   ZDUI_DOCK_STARTUP_TOOL_KEY
#define ADUI_XML_DOCK_STARTUP_INFO   ZDUI_XML_DOCK_STARTUP_INFO


#define ADUI_XML_ROOT                       ZDUI_XML_ROOT
#define ADUI_XML_DOCK_TOOL_INFO             ZDUI_XML_DOCK_TOOL_INFO
#define ADUI_XML_DOCK_TOOL                  ZDUI_XML_DOCK_TOOL
#define ADUI_XML_DOCK_TOOL_CLSID            ZDUI_XML_DOCK_TOOL_CLSID
#define ADUI_XML_DOCK_STARTUP_INFO          ZDUI_XML_DOCK_STARTUP_INFO
#define ADUI_XML_DOCK_STARTUP_TOOL_NAME     ZDUI_XML_DOCK_STARTUP_TOOL_NAME
#define ADUI_XML_DOCK_STARTUP_CMD_NAME      ZDUI_XML_DOCK_STARTUP_CMD_NAME


#define ID_ADUI_ALLOWDOCK                   ID_ZDUI_ALLOWDOCK
#define ID_ADUI_HIDEBAR                     ID_ZDUI_HIDEBAR

#define ADUI_DOCK_CS_DESTROY_ON_CLOSE       ZDUI_DOCK_CS_DESTROY_ON_CLOSE
#define ADUI_DOCK_CS_STDMOUSECLICKS         ZDUI_DOCK_CS_STDMOUSECLICKS

#define ADUI_DOCK_NF_SIZECHANGED            ZDUI_DOCK_NF_SIZECHANGED
#define ADUI_DOCK_NF_STATECHANGED           ZDUI_DOCK_NF_STATECHANGED
#define ADUI_DOCK_NF_FRAMECHANGED           ZDUI_DOCK_NF_FRAMECHANGED

typedef CZdUiDockControlBar CAdUiDockControlBar;
typedef CZdUiDockFrame      CAdUiDockFrame;
typedef CZdUiPaletteSetDockFrame CAdUiPaletteSetDockFrame;

#define AdUiSaveDockingToolPositions ZdUiSaveDockingToolPositions
#define AdUiShowDockControlBars      ZdUiShowDockControlBars
#define AdUiRegisterDockingTool      ZdUiRegisterDockingTool
#define AdUiRegisterTool             ZdUiRegisterTool
#define AdUiSetFloatingFrameClass    ZdUiSetFloatingFrameClass
#define AdUiRegisterFloatingFrameClassAddress ZdUiRegisterFloatingFrameClassAddress
#define AdUiRegisterPaletteSetFloatingFrameClass ZdUiRegisterPaletteSetFloatingFrameClass
#define AdUiGetRegisteredPaletteSetFloatingFrameClass ZdUiGetRegisteredPaletteSetFloatingFrameClass

typedef   ZDUI_LOADFN ADUI_LOADFN;
typedef   ZDUI_SAVEFN ADUI_SAVEFN;
#define   AdUiEnableDocking ZdUiEnableDocking
#define   AdUiEnableDockControlBars ZdUiEnableDockControlBars
#define   CanAutoCADTakeFocus         CanZCADTakeFocus
#endif
