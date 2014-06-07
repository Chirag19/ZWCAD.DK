
#ifndef _ARXPORT_AD_ACMEM_H_
#define _ARXPORT_AD_ACMEM_H_ 1

#include "AdAChar.h"
#include "..\inc\zcmem.h"

#define acad_malloc		zcad_malloc
#define acad_free		zcad_free
#define acad__msize		zcad__msize
#define acad_realloc	zcad_realloc
#define	acad_calloc		zcad_calloc
#define acad__strdup	zcad__strdup

#endif