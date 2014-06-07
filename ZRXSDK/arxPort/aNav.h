#ifndef _ARXPORT_ANAV_H_
#define _ARXPORT_ANAV_H_ 1

#ifdef ANAV_BUILD
#define ZNAV_BUILD
#endif

#ifndef ZNAV_BUILD
#define   ZNAV_PORT  __declspec(dllimport)
#else
#define   ZNAV_PORT  __declspec(dllexport)
#endif



#include "adui.h"
#include <afxole.h>
#include "aNavListCtrl.h"
#include "aNavData.h"
#include "aNavFilter.h"
#include "aNavArray.h"
#include "aNavDataArray.h"
#include "aNavFilterArray.h"
#include "aNavDialog.h"

#include "..\inc\zNav.h"

#endif
