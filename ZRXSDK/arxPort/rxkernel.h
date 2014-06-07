#ifndef _ARXPORT_AD_RXKERNEL_H_
#define _ARXPORT_AD_RXKERNEL_H_ 1


#include "rxsrvice.h"

class ZcRxClass;
class ZcRxDictionary;

typedef ZcRxClass			AcRxClass;
typedef ZcRxDictionary		AcRxDictionary;

#include "..\inc\zrxkernel.h"

typedef ZcRxKernel			AcRxKernel;

#define acrxKernel			zcrxKernel

#define newAcRxDictionary	newZcRxDictionary


#endif