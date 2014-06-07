#ifndef _ARXPORT_ACDBLMGR_H_
#define _ARXPORT_ACDBLMGR_H_ 1

#include "adesk.h"
#include "dbid.h"
#include "dblayout.h"
#include "dblaymgrrctr.h"

class ZcDbObjectId;
typedef ZcDbObjectId AcDbObjectId;
#include "..\inc\zcdblmgr.h"

typedef ZcDbLayoutManager AcDbLayoutManager;

#define acdbClearSetupForLayouts					zcdbClearSetupForLayouts
#define acdbCopyLayout								zcdbCopyLayout
#define acdbDeleteLayout							zcdbDeleteLayout
#define acdbDoSetupForLayouts						zcdbDoSetupForLayouts
#define acdbRenameLayout							zcdbRenameLayout

#endif
