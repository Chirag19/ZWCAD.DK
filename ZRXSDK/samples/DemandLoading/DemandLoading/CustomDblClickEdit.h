#pragma once


class CustomDblClickEdit : public ZcDbDoubleClickEdit
{
public:
	CustomDblClickEdit(void);
	virtual ~CustomDblClickEdit(void);

	virtual void startEdit(ZcDbEntity *pEnt, ZcGePoint3d pt); 
	virtual void finishEdit(void);


};
