

#ifndef _ZNav_h
#define _ZNav_h

#if _MSC_VER >= 1000
#pragma once
#endif 



#ifndef ZNAV_BUILD
#define   ZNAV_PORT  __declspec(dllimport)
#else
#define   ZNAV_PORT  __declspec(dllexport)
#endif



#include "zdui.h"
#include <afxole.h>
#include "zNavListCtrl.h"
#include "zNavData.h"
#include "zNavFilter.h"
#include "zNavArray.h"
#include "zNavDataArray.h"
#include "zNavFilterArray.h"
#include "zNavDialog.h"




//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
