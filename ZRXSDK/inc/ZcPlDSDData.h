#ifndef ZCPLDSDDATA_H
#define ZCPLDSDDATA_H

#pragma once

#include "ZcPl.h"
#include "ZcPlObject.h"
#include "ZcPlDSDEntry.h"
#include "ZcArray.h"

typedef ZcArray<ZcPlDSDEntry, ZcArrayObjectCopyReallocator <ZcPlDSDEntry> > ZcPlDSDEntries;


struct ZcPl3dDwfOptions {
    bool  bGroupByXrefHierarchy;
    bool  bPublishWithMaterials;
};


class ZcPlDSDData  : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlDSDData)

public:

    ZCPL_PORT ZcPlDSDData();

    ZCPL_PORT virtual ~ZcPlDSDData();

    ZCPL_PORT ZcPlDSDData(const ZcPlDSDData & src);

    ZCPL_PORT ZcPlDSDData& operator= (const ZcPlDSDData &src);

    ZCPL_PORT const ZCHAR *      projectPath() const;
    ZCPL_PORT void              setProjectPath(const ZCHAR * pVal);

    ZCPL_PORT const ZCHAR *      destinationName() const;
    ZCPL_PORT void              setDestinationName(const ZCHAR * pVal);

    ZCPL_PORT void              getDSDEntries(ZcPlDSDEntries &val) const;
    ZCPL_PORT void              setDSDEntries(const ZcPlDSDEntries &val);

    ZCPL_PORT int               numberOfDSDEntries() const;
    ZCPL_PORT ZcPlDSDEntry&     DSDEntryAt(int idx);

    ZCPL_PORT ZcPlDSDEntry::SheetType sheetType() const;
    ZCPL_PORT void                    setSheetType(ZcPlDSDEntry::SheetType val);

    ZCPL_PORT const ZCHAR *      password() const;
    ZCPL_PORT void              setPassword(const ZCHAR * pVal);

    ZCPL_PORT void              getUnrecognizedData(
                                    ZcArray<ZCHAR*> &sectionArray, 
                                    ZcArray<ZCHAR*> &dataArray) const;
    ZCPL_PORT void              setUnrecognizedData(
                                    const ZcArray<ZCHAR*> &sectionArray, 
                                    const ZcArray<ZCHAR*> &dataArray);
    ZCPL_PORT void              setUnrecognizedData(
                                    const ZCHAR * pSectionName, 
                                    const ZCHAR * pSectionData);
    
    ZCPL_PORT unsigned int      majorVersion() const;
    ZCPL_PORT void              setMajorVersion(unsigned int majorVersion);

    ZCPL_PORT unsigned int      minorVersion() const;
    ZCPL_PORT void              setMinorVersion(unsigned int minorVersion);

    ZCPL_PORT const ZCHAR *      sheetSetName() const;
    ZCPL_PORT void              setSheetSetName(const ZCHAR * pSheetSetName);

    ZCPL_PORT unsigned int      noOfCopies() const;
    ZCPL_PORT void              setNoOfCopies(unsigned int copies);

    ZCPL_PORT void              setIsSheetSet(bool bSheetSet);
    ZCPL_PORT bool              isSheetSet() const;

    ZCPL_PORT bool              isHomogeneous() const;
    ZCPL_PORT void              setIsHomogeneous(bool bHomogeneous);
    
    ZCPL_PORT bool              plotStampOn() const;
    ZCPL_PORT void              setPlotStampOn(bool bOn);

    ZCPL_PORT const ZCHAR *      selectionSetName() const;
    ZCPL_PORT void              setSelectionSetName(const ZCHAR * pSelSetName);

    ZCPL_PORT const ZCHAR *      categoryName() const;
    ZCPL_PORT void              setCategoryName(const ZCHAR * pCategoryName);

    ZCPL_PORT const ZCHAR *      logFilePath() const;
    ZCPL_PORT void              setLogFilePath(const ZCHAR * pLogFilePath);

    ZCPL_PORT const ZcPl3dDwfOptions&   get3dDwfOptions() const;
    ZCPL_PORT void              set3dDwfOptions(const ZcPl3dDwfOptions &val);

    ZCPL_PORT bool              readDSD(const ZCHAR *pName);
    ZCPL_PORT bool              writeDSD(const ZCHAR *pName);

    
    ZCPL_PORT bool              includeLayerInfo() const;       
    ZCPL_PORT void              setIncludeLayerInfo(bool bOn);
    
    ZCPL_PORT bool              promptForDwfName() const;
    ZCPL_PORT void              setPromptForDwfName(bool bPromptForDwfName);

    ZCPL_PORT bool              pwdProtectPublishedDWF() const;
    ZCPL_PORT void              setPwdProtectPublishedDWF(
                                bool bPwdProtectPublishedDWF);

    ZCPL_PORT bool              promptForPassword() const;
    ZCPL_PORT void              setPromptForPassword(bool bPromptForPassword);
};

#endif 
