//- SignJig.h
#pragma once

#include "..\SignEntityDb\SignEntity.h"

//-----------------------------------------------------------------------------
class SignJig : public ZcEdJig 
{

public:
	ZCRX_DECLARE_MEMBERS(SignJig);

public:
	SignJig () ;
	~SignJig () ;

	//- Command invoke the jig, call passing a new'd instance of the object to jig
	ZcEdJig::DragStatus startJig (SignEntity *pEntityToJig) ;

protected:
	//- ZcEdJig overrides
	//- input sampler
	virtual DragStatus sampler () ;
	//- jigged entity update
	virtual Zdesk::Boolean update () ;
	//- jigged entity pointer return
	virtual ZcDbEntity *entity () const ;

	//- Entity being jigged
	SignEntity *m_pEntity ;
	//- current input level, increment for ezch input
	int m_CurrentInputLevel ;

	ZcGePoint3d m_pntCen;
	double m_dblRadius;
} ;

#ifdef SIGNENTITYUI_MODULE
ZCDB_REGISTER_OBJECT_ENTRY_AUTO(SignJig)
#endif