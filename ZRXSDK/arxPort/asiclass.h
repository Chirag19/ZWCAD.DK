
#ifndef _ARXPORT_AD_ASICLASS_H_
#define _ARXPORT_AD_ASICLASS_H_
class ZAsiObject;
class ZAsiHostBuffer;
class ZAsiParameter;
class ZAsiException;
class ZAsiSQLObject;
class ZAsiSession;
class ZAsiStm;
class ZAsiExecStm;
class ZAsiCsr;
class ZAsiCsrTable;
class ZAsiCsrRegTable;
class ZAsiCsrInfSchema;
class ZAsiEnumerator;
class ZAsiBinding;
class ZAsiDSProperties;
class ZAsiTACond;
class ZAsiTCCond;
class ZAsiExceptionHandler;

typedef ZAsiObject					 CAsiObject;
typedef ZAsiHostBuffer			     CAsiHostBuffer;
typedef ZAsiParameter				 CAsiParameter;
typedef ZAsiException				 CAsiException;
typedef ZAsiSQLObject				 CAsiSQLObject;
typedef ZAsiSession					 CAsiSession;
typedef ZAsiStm						 CAsiStm;
typedef ZAsiExecStm					 CAsiExecStm;
typedef ZAsiCsr						 CAsiCsr;
typedef ZAsiCsrTable				 CAsiCsrTable;
typedef ZAsiCsrRegTable				 CAsiCsrRegTable;
typedef ZAsiCsrInfSchema			 CAsiCsrInfSchema;
typedef ZAsiEnumerator				 CAsiEnumerator;
typedef ZAsiBinding					 CAsiBinding;
typedef ZAsiDSProperties			 CAsiDSProperties;
typedef ZAsiTACond					 CAsiTACond;
typedef ZAsiTCCond					 CAsiTCCond;
typedef ZAsiExceptionHandler		 CAsiExceptionHandler;

#include <asisdata.h>

#include <avoidtry.h> //for DecreaseGlobalAccount only
#include "..\inc\zasiclass.h"

typedef ZAsiExceptionHandler		AsiExceptionHandler;
typedef ZAsiException				AsiException;
typedef ZAsiSQLObject				ASiSQLObject;
typedef ZAsiAppl					ASiAppl;
typedef ZAsiSession					ASiSession;
typedef ZAsiStm						ASiStm;
typedef ZAsiExecStm					ASiExecStm;
typedef ZAsiCsr						ASiCsr;
typedef ZAsiCsrTable				ASiCsrTable;
typedef ZAsiCsrRegTable				ASiCsrRegTable;
typedef ZAsiCsrInfSchema			ASiCsrInfSchema;
typedef ZAsiEnumerator				ASiEnumerator;
typedef ZAsiTACond					ASiTACond;
typedef ZAsiTCCond					ASiTCCond;


#define AsiAllocateDSEnumerator		ZAsiAllocateDSEnumerator
#define AsiGetDSEnumerator			ZAsiGetDSEnumerator
#define AsiExceptionThrow			ZAsiExceptionThrow

#endif
