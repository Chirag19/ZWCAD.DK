#ifndef _ARXPORT_AD_RXPROTEVNT_H_
#define _ARXPORT_AD_RXPROTEVNT_H_ 1


#include "rxdefs.h"
#include "acadstrc.h"

class ZcRxProtocolReactor;
class ZcRxProtocolReactorIterator;
class ZcRxProtocolReactorList;
class ZcRxProtocolReactorListIterator;
class ZcRxProtocolReactorManager;
class ZcRxProtocolReactorManagerFactory;

#include "..\inc\zrxprotevnt.h"

typedef ZcRxProtocolReactor					AcRxProtocolReactor;
typedef ZcRxProtocolReactorIterator			AcRxProtocolReactorIterator;
typedef ZcRxProtocolReactorList				AcRxProtocolReactorList;
typedef ZcRxProtocolReactorListIterator		AcRxProtocolReactorListIterator;
typedef ZcRxProtocolReactorManager			AcRxProtocolReactorManager;
typedef ZcRxProtocolReactorManagerFactory	AcRxProtocolReactorManagerFactory;

#define acrxProtocolReactors				zcrxProtocolReactors
#define ACRX_PROTOCOL_REACTOR_MANAGER_AT	ZCRX_PROTOCOL_REACTOR_MANAGER_AT
#define ACRX_PROTOCOL_REACTOR_LIST_AT		ZCRX_PROTOCOL_REACTOR_LIST_AT

#endif
