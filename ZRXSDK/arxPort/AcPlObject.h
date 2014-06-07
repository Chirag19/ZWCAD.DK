
#ifndef _ARXPORT_AD_ACPLOBJECT_H_
#define _ARXPORT_AD_ACPLOBJECT_H_ 1

#include "rxobject.h"
#include "AcHeapOpers.h"

class ZcPlObjectImp;
class ZcPlSystemInternals;

typedef ZcPlObjectImp				AcPlObjectImp;
typedef ZcPlSystemInternals			AcPlSystemInternals;

#include "..\inc\ZcPlObject.h"

typedef ZcPlObject		AcPlObject;

#define ACPL_DECLARE_MEMBERS		ZCPL_DECLARE_MEMBERS
#define AcPlGetHostAppServices		ZcPlGetHostAppServices
#define ACPL_DEFINE_MEMBERS			ZCPL_DEFINE_MEMBERS
#endif