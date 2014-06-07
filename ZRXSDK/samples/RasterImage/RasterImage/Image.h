#ifndef _CustomImageApp_H
#define _CustomImageApp_H 1


class CustomImageApp 
{
public:
	// Methods

	// Attaches an new Image
	virtual Zcad::ErrorStatus newImageAttach(ZcDbObjectId & parEntityId);
	// Create Objects
	virtual Zcad::ErrorStatus createZcDbRasterImage(ZcDbObjectId & parEntityId, ZcDbObjectId parObjectId);
	// creates the entity
	virtual Zcad::ErrorStatus createZcDbRasterImageDef(ZcDbObjectId &	parObjectId, CString parImageName, CString parImagePath);
	// Utilities Method
	virtual	Zcad::ErrorStatus appendToPaperOrModelSpace(ZcDbEntity* parEntity, Zdesk::Boolean parbToPaperSpace);

	double dWidth;
	double dHeight;
};

#endif