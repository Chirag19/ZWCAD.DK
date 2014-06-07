#ifndef _ARXPORT_ACFDUIFORMATDIALOG_H_
#define _ARXPORT_ACFDUIFORMATDIALOG_H_ 1


#include "adui.h"
#include "AcFdUi.h"


class ZcFdUiFormatList;


typedef ZcFdUiFormatList        CAcFdUiFormatList;


#include "..\inc\ZcFdUiFormatDialog.h"

#define ACFDUI_UM_FORMAT_CHANGED             ZCFDUI_UM_FORMAT_CHANGED             
#define ACFDUI_UM_BEGIN_FORMATEX_DIALOG      ZCFDUI_UM_BEGIN_FORMATEX_DIALOG      
#define ACFDUI_UM_END_FORMATEX_DIALOG        ZCFDUI_UM_END_FORMATEX_DIALOG        



#define ACFDUI_FDSTYLE_SIMPLE               ZCFDUI_FDSTYLE_SIMPLE               
#define ACFDUI_FDSTYLE_FILENAME             ZCFDUI_FDSTYLE_FILENAME             
#define ACFDUI_FDSTYLE_DOUBLE               ZCFDUI_FDSTYLE_DOUBLE               
#define ACFDUI_FDSTYLE_DOUBLE_POINT         ZCFDUI_FDSTYLE_DOUBLE_POINT         
#define ACFDUI_FDSTYLE_ALL                  ZCFDUI_FDSTYLE_ALL                  

typedef CZcFdUiFormatDialog                 CAcFdUiFormatDialog;

#endif