#ifndef _ARXPORT_ACFDUI_H_
#define _ARXPORT_ACFDUI_H_ 1


class CZcFdUiFieldManager;
class ZcDbField;
class ZcDbDatabase;


typedef CZcFdUiFieldManager  CAcFdUiFieldManager;
typedef ZcDbField            AcDbField;
typedef ZcDbDatabase         AcDbDatabase;

#include "..\inc\ZcFdUi.h"


#define ACFDUI_CATEGORY_ID_ALL     ZCFDUI_CATEGORY_ID_ALL
#define ACFDUI_CATID_USER_FIRST    ZCFDUI_CATID_USER_FIRST
#define ACFDUI_FIELDID_USER_FIRST  ZCFDUI_FIELDID_USER_FIRST


#define AcFdUiGetFieldManager     ZcFdUiGetFieldManager
#define AcFdUiInvokeFieldDialog   ZcFdUiInvokeFieldDialog

#endif
