
#ifndef _ARXPORT_AC_STRING_H_
#define _ARXPORT_AC_STRING_H_ 1

class ZcDbHandle;

typedef ZcDbHandle		AcDbHandle;

#include "..\inc\ZcString.h"

typedef ZcString		AcString;
typedef ZcStringArray	AcStringArray;

#define kACharPtr		kZCharPtr 

#endif // !_ARXPORT_AC_STRING_H_

