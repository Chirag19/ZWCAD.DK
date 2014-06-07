
#ifndef _ARXPORT_AD_DATALINK_H_
#define _ARXPORT_AD_DATALINK_H_ 1 

#include "AcString.h"

class ZcValue;
class ZcDbLinkedData;
class ZcDbDataAdapter;
class ZcDbDataLink;
class ZcDbDataLinkManager;
class ZcDbImpDataLinkManager;
class ZcTableSystemInternals;


typedef ZcValue         AcValue;
typedef ZcDbLinkedData  AcDbLinkedData;
typedef ZcDbDataAdapter AcDbDataAdapter;
typedef ZcDbImpDataLinkManager AcDbImpDataLinkManager;
typedef ZcTableSystemInternals AcTableSystemInternals;





#include "..\inc\zDbDataLink.h"

#define ACDB_DATA_ADAPTER_EXCEL ZCDB_DATA_ADAPTER_EXCEL

typedef ZcDbDataLink		AcDbDataLink;
typedef ZcDbDataLinkArray	AcDbDataLinkArray;
typedef ZcDbDataLinkManager AcDbDataLinkManager;

#endif
