
#ifndef ZOPM_CATEGORY_H
#define ZOPM_CATEGORY_H

#define PROPCAT_Nil -1
#define PROPCAT_Misc -2
#define PROPCAT_Font -3
#define PROPCAT_Position -4
#define PROPCAT_Appearance -5
#define PROPCAT_Behavior -6
#define PROPCAT_Data -7
#define PROPCAT_List -8
#define PROPCAT_Text -9
#define PROPCAT_Scale -10
#define PROPCAT_DDE -11
#define PROPCAT_General -12
#define PROPCAT_Mass -13
#define PROPCAT_Pattern -14
#define PROPCAT_DataPoints -15
#define PROPCAT_Mesh -16
#define PROPCAT_ImageAdjust -17
#define PROPCAT_ControlPoints -18
#define PROPCAT_PrimaryUnits -19
#define PROPCAT_AltUnits -20
#define PROPCAT_Fit -21
#define PROPCAT_LinesArrows -22
#define PROPCAT_Tolerances -23
#define PROPCAT_Table     -24
#define PROPCAT_Geometry -25
#define PROPCAT_Section -26
#define PROPCAT_UnderlayAdjust -27
#define PROPCAT_Solid_History -28
#define PROPCAT_Fillet -29
#define PROPCAT_Chamfer -30
#define PROPCAT_3DVisualization -31
#define PROPCAT_Table_Breaks -32

typedef int PROPCAT;

#undef  INTERFACE
#define INTERFACE  ICategorizeProperties
DEFINE_GUID(IID_ICategorizeProperties, 0x2e4eaf83, 0x46ab, 0x4f7a, 0x93, 0x7a, 0x96, 0xef, 0xc4, 0xfe, 0x2e, 0xcb);
interface DECLSPEC_UUID("2E4EAF83-46AB-4f7a-937A-96EFC4FE2ECB") ICategorizeProperties : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    
    STDMETHOD(MapPropertyToCategory)(THIS_ 
                                     /* [in]  */ DISPID dispid,
                                     /* [out] */ PROPCAT* ppropcat) PURE;
    
    STDMETHOD(GetCategoryName)(THIS_
                               /* [in]  */ PROPCAT propcat, 
                               /* [in]  */ LCID lcid,
                               /* [out] */ BSTR* pbstrName) PURE;
};

typedef ICategorizeProperties FAR* LPCATEGORIZEPROPERTIES;

#endif
