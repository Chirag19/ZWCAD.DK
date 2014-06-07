#ifndef _zcuiEdit_h
#define _zcuiEdit_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define AC_ES_STRING                        0x01	
#define	AC_ES_SYMBOL                        0x02
#define AC_ES_NUMERIC                       0x04
#define AC_ES_ANGLE                         0x08

#define AC_ES_VAL_ONKILLFOCUS               0x10
#define AC_ES_CONV_ONKILLFOCUS              0x20
#define AC_ES_SHOW_ERRMSG                   0x40
#define AC_ES_ERRMSG_ALLOWIGNORE            0x80

#define AC_ES_NOZERO                        0x100
#define AC_ES_NOBLANK                       0x200	
#define AC_ES_NONEGATIVE                    0x400
#define	AC_ES_INRANGE                       0x800

typedef enum {
    kAcUiError_None,                    
    kAcUiError_Blank,                   
    kAcUiError_Symbol,                  
    kAcUiError_Numeric,                 
    kAcUiError_Angle,                   
    kAcUiError_Zero,                    
    kAcUiError_Negative,                
    kAcUiError_Range                    
} ZCUI_ERROR_CODE;


class ZCUI_PORT CZcUiEdit : public CZdUiEdit {
    DECLARE_DYNAMIC(CZcUiEdit)

public:
                CZcUiEdit ();
virtual         ~CZcUiEdit ();

private:
        BOOL    m_bWantsFocus;
        BOOL    m_bWasValid;

protected:
virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );

public:
virtual void    SetStyleMask (DWORD mask);


private:
        void    DisplayError (UINT);    
public:
        BOOL    m_bChanged;             
        double  m_dMinValue;           
        double  m_dMaxValue;           
        CString m_csMsg;                
        BOOL    m_bTouch;               

        void    Convert ();             
        BOOL    ConvertData (CString& x);
        BOOL    HasChanged ();          
        void    SetDirty ();
        void    SetRange (double vMin, double vMax);
        BOOL    Validate ();			
        ZCUI_ERROR_CODE ValidateData (CString& x);

public:
	//{{AFX_VIRTUAL(CZcUiEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiEdit)
	afx_msg BOOL OnChange();
    afx_msg void OnErrSpace();
    afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiAngleEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiAngleEdit)

public:
                CZcUiAngleEdit ();
virtual         ~CZcUiAngleEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiAngleEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiAngleEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiNumericEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiNumericEdit)

public:
                CZcUiNumericEdit ();
virtual         ~CZcUiNumericEdit ();


public:
virtual void    SetStyleMask (DWORD mask);

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiNumericEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiNumericEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


class ZCUI_PORT CZcUiStringEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiStringEdit)

public:
	            CZcUiStringEdit ();
virtual         ~CZcUiStringEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiStringEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiStringEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiSymbolEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiSymbolEdit)

public:
                CZcUiSymbolEdit ();
virtual         ~CZcUiSymbolEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CZcUiSymbolEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CZcUiSymbolEdit)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
