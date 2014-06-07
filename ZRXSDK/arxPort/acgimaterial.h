#ifndef _ARXPORT_AD_ACGIMATERIAL_H_
#define _ARXPORT_AD_ACGIMATERIAL_H_ 1

#include "AdAChar.h"
#include "acgi.h"


#ifdef  ACGIMATERIAL_IMPL
#define ZCGIMATERIAL_IMPL
#endif


#ifdef ZCGIMATERIAL_IMPL
  #define ZCGIMAT_IMPEXP __declspec(dllexport)
#else
  #define ZCGIMAT_IMPEXP __declspec(dllimport)
#endif

class ZcGiMaterialColor;
class ZcGiMaterialMap;

typedef  ZcGiMaterialColor  AcGiMaterialColor;
typedef  ZcGiMaterialMap    AcGiMaterialMap;

#include "..\inc\zcgimaterial.h"

typedef ZcGiMaterialTraits			AcGiMaterialTraits;
typedef ZcGiMaterialTraits2			AcGiMaterialTraits2;
typedef ZcGiMaterialColor			AcGiMaterialColor;
typedef ZcGiMaterialTexture			AcGiMaterialTexture;
typedef ZcGiImageFileTexture		AcGiImageFileTexture;
typedef ZcGiProceduralTexture		AcGiProceduralTexture;
typedef ZcGiGenericTexture			AcGiGenericTexture;
typedef ZcGiWoodTexture				AcGiWoodTexture;
typedef ZcGiMarbleTexture			AcGiMarbleTexture;
typedef ZcGiMaterialMap				AcGiMaterialMap;
typedef ZcGiMapper					AcGiMapper;
typedef ZcGiImageTexture			AcGiImageTexture;
#endif 