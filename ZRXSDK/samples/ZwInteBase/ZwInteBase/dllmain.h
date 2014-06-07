// dllmain.h : Declaration of module class.

class CZwInteBaseModule : public CAtlMfcModule
{
public :
	DECLARE_LIBID(LIBID_ZwInteBaseLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ZWINTEBASE, "{69E2B62B-CC6D-4F10-90C9-B855E060C28B}")
};

extern class CZwInteBaseModule _AtlModule;
