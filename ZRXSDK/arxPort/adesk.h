
#ifndef _ARXPORT_ADESK_H_
#define _ARXPORT_ADESK_H_ 1

#include "AdAChar.h"
#include "..\inc\Zdesk.h"

typedef Zdesk		Adesk;

typedef ZC_BYTE		AC_BYTE;

#define ADESK_NO_VTABLE __declspec(novtable)
#define ADESK_STDCALL   __stdcall
#define ADESK_DEPRECATED __declspec(deprecated)

#endif
