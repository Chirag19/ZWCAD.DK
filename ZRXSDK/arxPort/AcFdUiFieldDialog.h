#ifndef _ARXPORT_ACFDUIFIELDDIALOG_H_
#define _ARXPORT_ACFDUIFIELDDIALOG_H_ 1

#include "adui.h"
#include "AcFdUi.h"

class CZcFdUiSystemInternals;
class CZcFdUiFieldOptionDialog;
class CZcFdUiImpFieldDialog;


typedef CZcFdUiSystemInternals       AcFdUiSystemInternals;
typedef CZcFdUiFieldOptionDialog     CAcFdUiFieldOptionDialog;
typedef CZcFdUiImpFieldDialog        CAcFdUiImpFieldDialog;



#include "..\inc\ZcFdUiFieldDialog.h"

#define ACFDUI_FD_CREATE_FIELD         ZCFDUI_FD_CREATE_FIELD
#define ACFDUI_FD_EDIT_FIELD           ZCFDUI_FD_EDIT_FIELD

typedef CZcFdUiFieldDialog             CAcFdUiFieldDialog; 

#endif