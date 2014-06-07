
#ifndef _ARXPORT_AD_AXDB_H_
#define _ARXPORT_AD_AXDB_H_ 1

#include "..\inc\zxdb.h"

typedef ZcColor AcColor;
typedef ZcShadowDisplayType AcShadowDisplayType;
typedef ZcExtendOption AcExtendOption;
typedef ZcLineWeight   AcLineWeight;
typedef ZCAD_LWEIGHT   ACAD_LWEIGHT;

typedef IZcadObject         IAcadObject;
typedef IZcadEntity         IAcadEntity;
typedef IZcadObjectEvents   IAcadObjectEvents;
typedef IZcadDatabase       IAcadDatabase;
typedef IZcadDictionary     IAcadDictionary;
typedef ZCAD_NOUNITS        ACAD_NOUNITS;
typedef IZcadZcCmColor		IAcadAcCmColor;
typedef IZcadHyperlinks		IAcadHyperlinks;

#define IID_IAcadObject      IID_IZcadObject
#define IID_IAcadEntity      IID_IZcadEntity
#define CLSID_AcadAcCmColor  CLSID_ZcadZcCmColor


#endif
