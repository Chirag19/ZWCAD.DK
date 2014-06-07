#include "stdafx.h"
#include "CustomDblClickEdit.h"
#include "DblClickEditDlg.h"
#include "SignEntity.h"

CustomDblClickEdit::CustomDblClickEdit(void)
{

}

CustomDblClickEdit::~CustomDblClickEdit(void)
{
}

void CustomDblClickEdit::startEdit(ZcDbEntity *pEnt, ZcGePoint3d pt)
{
	if (!pEnt->isKindOf(SignEntity::desc()))
	{
		pEnt->close();
		return;
	}

	SignEntity* pSignEnt = (SignEntity*)pEnt;
	
	CDblClickEditDlg dlgEdit(pSignEnt);
	if (IDOK == dlgEdit.DoModal())
	{
		pSignEnt->setRadius(dlgEdit.m_dblRadius);	
		ZcGePoint3d pntCenter;
		pntCenter.x = dlgEdit.m_dblCenterX;
		pntCenter.y = dlgEdit.m_dblCenterY;
		pntCenter.z = dlgEdit.m_dblCenterZ;
		pSignEnt->setCenter(pntCenter);

	}

	pEnt->close();

}

void CustomDblClickEdit::finishEdit(void)
{

}