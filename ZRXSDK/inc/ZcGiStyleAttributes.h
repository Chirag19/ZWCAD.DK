
#ifndef __ZcGiStyleAttributes_H_Defined__
#define __ZcGiStyleAttributes_H_Defined__

#include "ZcGiLineAttributes.h"

typedef enum {
    kNothing                                = 0x00,
    kColor                                  = 0x01,
    kLine                                   = 0x02,
    kLineType                               = 0x04,
    kPlotStyle                              = 0x08,
    kEverything                             = 0x0F
} ZcGiAttributeFlags; 

class ZDESK_NO_VTABLE ZcGiStyleAttributes
{
public:

    ZcGiStyleAttributes();
    ZcGiStyleAttributes(const ZcGiStyleAttributes& source);
    virtual ~ZcGiStyleAttributes();

    ZcCmEntityColor& getColorAttribute();
    const ZcCmEntityColor& getColorAttribute() const;
    void setColorAttribute(const ZcCmEntityColor& color);

    ZcDbObjectId linetypeObjectId() const;
    void setLinetypeObjectId(const ZcDbObjectId& newId);

    ZcDbObjectId plotStyleNameId() const;
    void setPlotStyleName(const ZcDbObjectId& newId);

    virtual ZcGiLineAttributes* getLineAttribute()                              = 0;
    virtual const ZcGiLineAttributes* getLineAttribute() const                  = 0;
    virtual void setLineAttribute(const ZcGiLineAttributes* pLineAttributes)    = 0;

    virtual void EnsureColorVisibility (ZcCmEntityColor& color)                 = 0;    

protected:
    ZcCmEntityColor m_colorAttribute;

    ZcDbObjectId    m_idLinetype;
    ZcDbObjectId    m_idPlotstyle;
};


#endif