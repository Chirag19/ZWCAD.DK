#ifndef _ARXPORT_AC_DBCOLOR_H_
#define _ARXPORT_AC_DBCOLOR_H_  1

#include "adesk.h"
#include "acadstrc.h"

class __declspec(dllimport) ZcCmEntityColor;
#include "..\inc\zdbcolor.h"

typedef ZcCmColorBase		AcCmColorBase;
typedef ZcCmEntityColor		AcCmEntityColor;
typedef ZcCmTransparency	AcCmTransparency;
typedef ZcCmDialogColor     AcCmDialogColor;

namespace AcCm
{
    enum DialogTabs
    {   
        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4,
    };

    enum ACIColors
    {   
        kACIByBlock     = 0,
        kACIRed         = 1,
        kACIYellow      = 2,
        kACIGreen       = 3,
        kACICyan        = 4,
        kACIBlue        = 5,
        kACIMagenta     = 6,
        kACIForeground  = 7,
        kACIByLayer     = 256,
    };
};

#endif