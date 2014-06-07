#ifndef _ARXPORT_ADUIBUTTON_H_
#define _ARXPORT_ADUIBUTTON_H_ 1

#include "AdUiTheme.h"


class CZdUiOwnerDrawButton;
class CZdUiTrackButtonDraw;

typedef CZdUiOwnerDrawButton CAdUiOwnerDrawButton;
typedef CZdUiTrackButtonDraw CAdUiTrackButtonDraw;

#include "..\inc\zduiButton.h"

typedef CZdUiODButtonThemeModReactor CAdUiODButtonThemeModReactor;
typedef CZdUiOwnerDrawButton         CAdUiOwnerDrawButton;
typedef CZdUiOwnerDrawButton         CAdUiOwnerDrawButton;
typedef CZdUiBitmapButton            CAdUiBitmapButton;
typedef CZdUiBitmapStatic            CAdUiBitmapStatic;
typedef CZdUiDropSite                CAdUiDropSite;
typedef CZdUiToolButton              CAdUiToolButton;
typedef CZdUiTrackButton             CAdUiTrackButton;


#define GetAdUiParent  GetZdUiParent
#define SetAdUiParent  SetZdUiParent
#define DoAdUiMessage  DoZdUiMessage
#define OnAdUiMessage  OnZdUiMessage



#endif


