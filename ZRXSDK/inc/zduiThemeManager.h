#ifndef _ZDUI_THEME_MANAGER_H_
#define _ZDUI_THEME_MANAGER_H_


class CZdUiThemeMgrReactor
{
public:
    CZdUiThemeMgrReactor();
    virtual void ThemeAdded(const CString & strThemeName) = 0;
    virtual void ThemeRemoved(const CString & strThemeName) = 0;
    virtual void SystemColorChanged() = 0;
    ~CZdUiThemeMgrReactor();
};


class CZdUiThemeManager 
{
    friend class CZdUiThemeMgrReactor;

public:
    CZdUiThemeManager();
    ~CZdUiThemeManager();

    CZdUiTheme * GetTheme(const ZCHAR *pThemeName);
    BOOL ReleaseTheme(CZdUiTheme * pTheme);

    BOOL HasTheme(const ZCHAR *pThemeName) const;

    void SystemColorChanged();

private:
    int  RemoveTheme(const ZCHAR *pThemeName);
    void Cleanup();
    int  GetThemeIndex(const ZCHAR *pThemeName) const;
    int  GetThemeIndex(const CZdUiTheme *pTheme) const;
    BOOL RegisterThemeMgrReactor(CZdUiThemeMgrReactor * pReactor);
    BOOL UnregisterThemeMgrReactor(CZdUiThemeMgrReactor * pReactor);
    void NotifyThemeAddedReactors(const CString & strThemeName);
    void NotifySysColorReactors();
    CObArray        m_list;
    CTypedPtrArray<CPtrArray, CZdUiThemeMgrReactor*> m_arrayThemeMgrReactors;
};
#endif  
