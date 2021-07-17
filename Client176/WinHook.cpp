#include "Global.h"

bool Hook_CreateWindowExA(bool bEnable)
{
	static auto _CreateWindowExA = decltype(&CreateWindowExA)(GetFuncAddress("USER32", "CreateWindowExA"));

	decltype(&CreateWindowExA) Hook = [](DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) -> HWND
	{
		auto lpLocalWndName = lpWindowName;

		if (!strcmp(lpClassName, "StartUpDlgClass"))
		{
			return NULL;
		}
		else if (!strcmp(lpClassName, "NexonADBallon"))
		{
			return NULL;
		}
		else if (!strcmp(lpClassName, "MapleStoryClass"))
		{
			FuckMaple();
			lpLocalWndName = OPT_APPNAME;
			Log("CWvsApp [%#08x]", lpParam);
		}

		return _CreateWindowExA(dwExStyle, lpClassName, lpLocalWndName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	};

	return SetHook(bEnable, reinterpret_cast<void**>(&_CreateWindowExA), Hook);
}

bool Hook_CreateMutexA(bool bEnable)
{
	static auto _CreateMutexA = decltype(&CreateMutexA)(GetFuncAddress("KERNEL32", "CreateMutexA"));

	decltype(&CreateMutexA) Hook = [](LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName) -> HANDLE
	{
		if (lpName && !strcmp(lpName, "WvsClientMtx"))
		{
			Log("MultiClient: Faking %s", lpName);
			return (HANDLE)0xBADF00D;
		}

		return _CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
	};

	return SetHook(bEnable, reinterpret_cast<void**>(&_CreateMutexA), Hook);
}

bool HookWinApi()
{
	bool bResult = true;

	bResult &= Hook_CreateWindowExA(true);
	bResult &= Hook_CreateMutexA(true);

	return bResult;
}
