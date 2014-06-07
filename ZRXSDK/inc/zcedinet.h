#if !defined(AFX_ZCEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_)
#define AFX_ZCEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_
#pragma pack (push, 8)


extern Zdesk::Boolean
zcedCreateShortcut(/*[in]*/void* pvHwndParent, /*[in]*/const ZCHAR* szLinkPath, 
				   /*[in]*/const ZCHAR* szObjectPath, /*[in]*/const ZCHAR* szDesc);



extern Zdesk::Boolean
zcedResolveShortcut(/*[in]*/void* pvHwndParent, /*[in]*/const ZCHAR* szLinkPath, 
					/*[out]*/ZCHAR* szObjectPath);



extern Zdesk::Boolean
zcedGetUserFavoritesDir(/*[out]*/ZCHAR* szFavoritesDir);


extern Zdesk::Boolean
zcedCreateInternetShortcut(/*[in]*/const ZCHAR* szURL, /*[in]*/const ZCHAR* szShortcutPath);


extern Zdesk::Boolean
zcedResolveInternetShortcut(/*[in]*/const ZCHAR* szLinkFile, /*[out]*/ZCHAR* szUrl);



#pragma pack (pop)
#endif	
