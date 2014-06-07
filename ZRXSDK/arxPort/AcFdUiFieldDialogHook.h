#ifndef _ARXPORT_ACFDUIFIELDDIALOGHOOK_H_
#define _ARXPORT_ACFDUIFIELDDIALOGHOOK_H_ 1


#include "AcFdUi.h"
#include "DbField.h"
#include <afxtempl.h>


class CZcFdUiFieldDialog;
class CZcFdUiFieldOptionDialog;
class CZcFdUiFieldDialogHook;


typedef CZcFdUiFieldDialog               CAcFdUiFieldDialog;
typedef CZcFdUiFieldOptionDialog         CAcFdUiFieldOptionDialog;
typedef CZcFdUiFieldDialogHook           CAcFdUiFieldDialogHook;



#include "..\inc\ZcFdUiFieldDialogHook.h"

#define  AcFdUiFieldDialogHookArray ZcFdUiFieldDialogHookArray

typedef  CZcFdUiFieldDialogHook      CAcFdUiFieldDialogHook;

#endif


