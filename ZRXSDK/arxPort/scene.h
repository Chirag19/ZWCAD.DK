#ifndef _ARXPORT_AD_SCENE_H_
#define _ARXPORT_AD_SCENE_H_ 1

#include "AdAChar.h"
#include "..\inc\zscene.h"

typedef zscn_cmesh				scn_cmesh;
typedef zscn_vrtc				scn_vrtc;
typedef zscn_pmsh				scn_pmsh;
typedef zscn_cvrt				scn_cvrt;
typedef zscn_node				scn_node;
typedef ze2f_hdr				e2f_hdr;
typedef ze2f_layer				e2f_layer;
typedef ze2f_ent				e2f_ent;
typedef ze2f_xform				e2f_xform;

#ifdef RENDERDATA
typedef ZcReCallout				AcReCallout;
#endif

#define acreEntityToFaces		zcreEntityToFaces
#define acreRegisterCallout		zcreRegisterCallout


#endif