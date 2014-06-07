
#ifndef _ARXPORT_AD_DYNPROPS_H_
#define _ARXPORT_AD_DYNPROPS_H_ 1


interface IZPropertyManager;
interface IZDynamicProperty;
interface IZPropertyManager2;
interface IZDynamicProperty2;
interface IZPropertySource;


typedef IZPropertyManager				IPropertyManager;
typedef IZDynamicProperty				IDynamicProperty;
typedef IZPropertyManager2				IPropertyManager2;
typedef IZDynamicProperty2				IDynamicProperty2;
typedef IZPropertySource				IPropertySource;

#include "..\inc\zdynprops.h"

typedef ZOPMPerInstancePropertySources			OPMPerInstancePropertySources;
typedef ZOPMPerInstancePropertyExtension		OPMPerInstancePropertyExtension;
typedef ZOPMPerInstancePropertyExtensionFactory	OPMPerInstancePropertyExtensionFactory;

typedef ZOPMPropertyExtension					OPMPropertyExtension;
typedef ZOPMPropertyExtensionFactory			OPMPropertyExtensionFactory;

typedef IZDynamicPropertyNotify					IDynamicPropertyNotify;
typedef LPZDYNAMICPROPERTYNOTIFY				LPDYNAMICPROPERTYNOTIFY;
typedef IZDynamicPropertyNotify2				IDynamicPropertyNotify2;
typedef LPZDYNAMICPROPERTYNOTIFY2				LPDYNAMICPROPERTYNOTIFY2;
typedef IZDynamicProperty						IDynamicProperty;
typedef LPZDYNAMICPROPERTY						LPDYNAMICPROPERTY;
typedef IZDynamicProperty2						IDynamicProperty2;
typedef LPZDYNAMICPROPERTY2						LPDYNAMICPROPERTY2;
typedef IZDynamicEnumProperty					IDynamicEnumProperty;
typedef LPZDYNAMICENUMPROPERTY					LPDYNAMICENUMPROPERTY;
typedef IZDynamicDialogProperty					IDynamicDialogProperty;
typedef LPZDYNAMICDIALOGPROPERTY				LPDYNAMICDIALOGPROPERTY;
typedef IZPropertyManager						IPropertyManager;
typedef LPZPROPERTYMANAGER						LPPROPERTYMANAGER;
typedef IZPropertyManager2						IPropertyManager2;
typedef LPZPROPERTYMANAGER2						LPPROPERTYMANAGER2;
typedef IZPropertySource						IPropertySource;
typedef LPZPROPERTYSOURCE						LPPROPERTYSOURCE;

#endif