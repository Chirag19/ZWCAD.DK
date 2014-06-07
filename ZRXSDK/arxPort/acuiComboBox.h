#ifndef _ARXPORT_ACUICOMBOBOX_H_
#define _ARXPORT_ACUICOMBOBOX_H_ 1


class     CZcUiMRUComboBox;
class     CZcUiMRUListBox;
typedef   CZcUiMRUComboBox CAcUiMRUComboBox;
typedef   CZcUiMRUListBox  CAcUiMRUListBox;

#include "..\inc\zcuiComboBox.h"

typedef ZcCmColorTable         AcCmColorTable;
typedef CZcUiComboBox          CAcUiComboBox;
typedef CZcUiAngleComboBox     CAcUiAngleComboBox;
typedef CZcUiNumericComboBox   CAcUiNumericComboBox;
typedef CZcUiStringComboBox    CAcUiStringComboBox;
typedef CZcUiSymbolComboBox    CAcUiSymbolComboBox;




#define ACUI_MAX_COMBOBOX_MRU                    ZCUI_MAX_COMBOBOX_MRU
#define ACUI_MAX_TRUECOLOR_COMBOBOX_MRU          ZCUI_MAX_TRUECOLOR_COMBOBOX_MRU

typedef ZCUI_MRU_CARGO           ACUI_MRU_CARGO;

typedef CZcUiMRUListBox        CAcUiMRUListBox;
typedef CZcUiMRUComboBox       CAcUiMRUComboBox;
typedef CZcUiLTypeRecord       CAcUiLTypeRecord;
typedef CZcUiLineTypeComboBox  CAcUiLineTypeComboBox;
typedef CZcUiColorComboBox     CAcUiColorComboBox;

#define ACUI_TRUECOLOR_COMBOBOX_TABLE_SIZE ZCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE

typedef CZcUiTrueColorComboBox       CAcUiTrueColorComboBox;
typedef CZcUiLineWeightComboBox      CAcUiLineWeightComboBox;
typedef CZcUiArrowHeadComboBox       CAcUiArrowHeadComboBox;
typedef CZcUiPlotStyleTablesComboBox CAcUiPlotStyleTablesComboBox;
typedef CZcUiPlotStyleNamesComboBox  CAcUiPlotStyleNamesComboBox;
typedef CZcUiPredefBlockComboBox     CAcUiPredefBlockComboBox;

#define initAcCmColorTable   initZcCmColorTable
#define AcUiEditBox          ZcUiEditBox 
#endif
