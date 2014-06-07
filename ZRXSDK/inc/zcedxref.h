

#ifndef   _ZCEDXREF_H
#define   _ZCEDXREF_H
#pragma pack (push, 8)

Zcad::ErrorStatus
zcedXrefAttach(const ZCHAR*           XrefPathname,
               const ZCHAR*           XrefBlockname,
                     ZcDbObjectId*   pXrefBTRid       = NULL,
                     ZcDbObjectId*   pXrefRefid       = NULL,
               const ZcGePoint3d*    pXrefInsertPt    = NULL,
               const ZcGeScale3d*    pXrefScale       = NULL,
               const double*         pXrefRotateAngle = NULL,
               const bool            bQuiet           = true,
                     ZcDbDatabase*   pHostDb          = NULL,
               const wchar_t*       wszPassword       = NULL);

Zcad::ErrorStatus
zcedXrefOverlay(const ZCHAR*           XrefPathname,
                const ZCHAR*           XrefBlockname,
                      ZcDbObjectId*   pXrefBTRid       = NULL,
                      ZcDbObjectId*   pXrefRefid       = NULL,
                const ZcGePoint3d*    pXrefInsertPt    = NULL,
                const ZcGeScale3d*    pXrefScale       = NULL,
                const double*         pXrefRotateAngle = NULL,
                const bool            bQuiet           = true,
                      ZcDbDatabase*   pHostDb          = NULL,
                const wchar_t*        wszPassword      = NULL);

Zcad::ErrorStatus
zcedXrefUnload(const ZCHAR*           XrefBlockname,
               const bool            bQuiet        = true,
                     ZcDbDatabase*   pHostDb       = NULL);
Zcad::ErrorStatus
zcedXrefDetach(const ZCHAR*           XrefBlockname,
               const bool            bQuiet        = true,
                     ZcDbDatabase*   pHostDb       = NULL);
Zcad::ErrorStatus
zcedXrefReload(const ZCHAR*           XrefBlockname,
               const bool            bQuiet        = true, 
                     ZcDbDatabase*   pHostDb       = NULL);
Zcad::ErrorStatus
zcedXrefBind(const ZCHAR*           XrefBlockname,
             const bool            bInsertBind     = false,
             const bool            bQuiet          = true,
                   ZcDbDatabase*   pHostDb         = NULL);

Zcad::ErrorStatus
zcedXrefCreateBlockname(const ZCHAR*  XrefPathname,
                              ZCHAR*& XrefBlockname);

Zcad::ErrorStatus
zcedXrefReload(const ZcDbObjectIdArray& XrefBTRids,
                     bool               bQuiet     = true,
                     ZcDbDatabase*      pHostDb    = NULL);

Zcad::ErrorStatus
zcedXrefXBind(const ZcDbObjectIdArray symbolIds,
              const bool              bQuiet       = true,
                    ZcDbDatabase*     pHostDb      = NULL);

Zcad::ErrorStatus
zcedXrefResolve(ZcDbDatabase* pHostDb, const bool bQuiet = true);

#pragma pack (pop)
#endif 

