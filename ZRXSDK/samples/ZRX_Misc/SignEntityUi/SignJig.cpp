#include "StdAfx.h"
#include "SignJig.h"

//-----------------------------------------------------------------------------
ZCRX_CONS_DEFINE_MEMBERS(SignJig, ZcEdJig, 1)

//-----------------------------------------------------------------------------
SignJig::SignJig () : ZcEdJig (),
	m_CurrentInputLevel(0), m_pEntity(NULL)
{
}

SignJig::~SignJig ()
{

}

//-----------------------------------------------------------------------------
ZcEdJig::DragStatus SignJig::startJig (SignEntity *pEntity) 
{
	m_pEntity = pEntity;
	
	// Now, m_CurrentInputLevel == 0
	setDispPrompt("\n center point: ");

	ZcEdJig::DragStatus status;
	status = drag();

	// Now, m_CurrentInputLevel == 1
    m_CurrentInputLevel++;   
	setDispPrompt("\n radius: ");
	status = drag();

	// Add the custom entity to the database's current space.
	append();

	return (status) ;
}


ZcEdJig::DragStatus SignJig::sampler()
{
	DragStatus stat;

	if (m_CurrentInputLevel == 0)
	{
		// Acquire the center point.

		static ZcGePoint3d pntTemp;
		stat = acquirePoint(m_pntCen);
		if (pntTemp != m_pntCen)
			pntTemp = m_pntCen;
		else if (stat == ZcEdJig::kNormal)
			return ZcEdJig::kNoChange;
	}
	else if (m_CurrentInputLevel == 1) 
	{
		// Acquire the radius

		static double dblTempRad = -1;
		stat = acquireDist(m_dblRadius, m_pntCen);
		if (dblTempRad != m_dblRadius)
		{
			dblTempRad = m_dblRadius;
		}
		else if (stat == ZcEdJig::kNormal)
		{
			return ZcEdJig::kNoChange;
		}
	}

	return stat;
}

//-----------------------------------------------------------------------------
//- Jigged entity update
Zdesk::Boolean SignJig::update () 
{
	//- Check the current input number to see which update to do
	switch (m_CurrentInputLevel)
	{
		case 0:
			m_pEntity->setCenter (m_pntCen);
			break ;

		case 1:
			m_pEntity->setRadius(m_dblRadius);
			break;

		default:
			break ;
	}

	 return Zdesk::kTrue;
}

//-----------------------------------------------------------------------------
//- Jigged entity pointer return
ZcDbEntity *SignJig::entity () const
{
	return (m_pEntity) ;
}


