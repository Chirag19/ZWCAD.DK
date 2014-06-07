#ifndef _ARXPORT_AD_ACSSGETFILTER_H_
#define _ARXPORT_AD_ACSSGETFILTER_H_ 1

class ZcApDocument;

typedef ZcApDocument				AcApDocument;

#include "..\inc\zcssgetfilter.h"

typedef ZcEdSelectionSetService		AcEdSelectionSetService;
typedef ZcDbArrayIntArray			AcDbArrayIntArray;
typedef ZcEdSSGetFilter				AcEdSSGetFilter;

namespace AcEdSSGet {

enum AcEdSSGetFlags {
    kNormal         =   0,
    kPickPoints     =   1,
    kDuplicates     =   2,
    kNestedEntities =   4,
    kSubEntities    =   8,
    kSinglePick     =  16,
    kPickfirstSet   =  32,
    kPreviousSet    =  64,
    kSubSelection   = 128
};

enum AcEdSSGetModes {
    kWin = 1,   //  (Window spec)
    kCross,     //  (Crossing spec)
    kBox,       //  (Box spec)
    kLast,      //  (Last)
    kEntity,    //  (Explicit entity name)
    kAll,       //  (Select all)
    kFence,     //  (Fence Selection)
    kCPoly,     //  (Crossing Poly)
    kWPoly,     //  (Window Poly)
    kPick,      //  (Single pick)
    kEvery,     //  (every entity on single pick)
    kXten,      //  (ssget "X")
    kGroup,     //  (selection set from "group" specification)
    kPrevious   //  (previous selectionset)
};

};

typedef ZcEdSSGetFilter2				AcEdSSGetFilter2;
typedef ZcEdSSGetFilter3				AcEdSSGetFilter3;
typedef ZcEdSubSelectFilterService		AcEdSubSelectFilterService;
typedef ZcEdSSGetSubSelectFilter		AcEdSSGetSubSelectFilter;
#endif