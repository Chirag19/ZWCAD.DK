

#ifndef   _ZCPROFILE_H__
#define   _ZCPROFILE_H__

#include "zcarray.h"
#include "ZdZChar.h"
#pragma pack (push, 8)

class ZcApProfileStorage;

class ZcApProfileManagerReactor 
{
public:
    virtual void currentProfileWillChange(const ZCHAR *newProfile);
    virtual void currentProfileChanged(const ZCHAR *newProfile);
    virtual void currentProfileWillBeReset(const ZCHAR *currentProfile);
    virtual void currentProfileReset(const ZCHAR *currentProfile);
    virtual void currentProfileWillBeSaved(const ZCHAR *currentProfile);
    virtual void currentProfileSaved(const ZCHAR *currentProfile);
    virtual void profileWillReset(const ZCHAR *profileName);
    virtual void profileReset(const ZCHAR *profileName);
    virtual void profileWillBeSaved(const ZCHAR *profileName);
    virtual void profileSaved(const ZCHAR *profileName);
    virtual ~ZcApProfileManagerReactor() {}
};

typedef ZcArray<ZCHAR *> ZcApProfileNameArray;

class ZcApProfileManager 
{
    public:

        virtual void ProfileRegistryKey(ZCHAR *& strRegProfileKey,
                                        const ZCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileStorage(ZcApProfileStorage*& pStore,
                                        const ZCHAR * strProfileName, 
                                        BOOL bCreateIfNotExists = TRUE)=0;
        virtual Zcad::ErrorStatus FixedProfileStorage(ZcApProfileStorage*& pStore, 
                                        BOOL bCreateIfNotExists = TRUE)=0;

        virtual int ProfileListNames(ZcApProfileNameArray& nameList)=0;

        virtual Zcad::ErrorStatus ProfileExport(const ZCHAR * strProfileName,
                                                const ZCHAR * exportFileName)=0;

        virtual Zcad::ErrorStatus ProfileImport(const ZCHAR * strProfileName,
                                                const ZCHAR * importFileName,
                                                const ZCHAR * profileDescription,
                                                Zdesk::Boolean bImportPathInfo)=0; 

        virtual Zcad::ErrorStatus ProfileDelete(const ZCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileReset(const ZCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileSetCurrent(const ZCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileCopy(const ZCHAR * newProfileName,
                                              const ZCHAR * oldProfileName,
                                              const ZCHAR * newProfileDesc)=0;

        virtual Zcad::ErrorStatus ProfileRename(const ZCHAR * newProfileName,
                                                const ZCHAR * oldProfileName,
                                                const ZCHAR * newProfileDesc)=0;

        virtual void addReactor(ZcApProfileManagerReactor* ) = 0;
        virtual void removeReactor(ZcApProfileManagerReactor* ) = 0;

};

ZcApProfileManager* zcProfileManagerPtr();
#define zcProfileManager zcProfileManagerPtr()

class ZcApProfileStorage
{
    public:
        virtual ~ZcApProfileStorage() {}
        virtual Zcad::ErrorStatus CreateNode(const ZCHAR * pszNodePath, 
            IUnknown*& pUnknown) = 0;
        virtual Zcad::ErrorStatus GetNode(const ZCHAR * pszNodePath, 
            IUnknown*& pUnknown) = 0;
        virtual Zcad::ErrorStatus ReplaceNode(const ZCHAR * pszNodePath, 
            IUnknown* pUnknown) = 0;
        virtual Zcad::ErrorStatus DeleteNode(const ZCHAR * pszNodePath) = 0;
        virtual Zcad::ErrorStatus GetStorageFile(LPTSTR pszFile) = 0;
        virtual Zcad::ErrorStatus Save(void) = 0;
};


#pragma pack (pop)
#endif 
