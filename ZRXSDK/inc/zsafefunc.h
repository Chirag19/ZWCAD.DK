#if _MSC_VER >= 1400		//1400 = VC2005 ; 1310 = VC2003

//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

//#define wcscpy(a, b) \
//	wcscpy_s(a,  wcslen(b) + 1, b); 
//
//#define strcpy(a, b) \
//	strcpy_s(a,  strlen(b) + 1, b); 

//#define _itoa(a, b, c) \
//	_itoa_s(a,  b, sizeof(b) + 1,  c); 
//
//#define vsprintf(a, b, c) \
//	vsprintf_s(a,  sizeof(a) + 1, b, c); 


#endif


#if _MSC_VER < 1400		//1400 = VC2005 ; 1310 = VC2003

#define _tcscpy_s(a, b, c) \
	strcpy(a, c); 

#define strcpy_s(a, b, c) \
	strcpy(a, c); 

#define wcscpy_s(a, b, c) \
	wcscpy(a, c); 

#define _itoa_s(a, b, c, d) \
	_itoa(a, b, d); 

#define _itot_s(a, b, c, d) \
	_itoa(a, b, d); 

#define sscanf_s sscanf

#define swscanf_s swscanf

#define vsprintf_s(a, b, c, d) \
	vsprintf(a, c, d); 

#define _vstprintf_s(a, b, c, d) \
	vsprintf(a, c, d); 

#endif