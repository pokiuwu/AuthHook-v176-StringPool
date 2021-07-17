//---------------------------------------------------------------------------------------------
// v176.1 Localhost Enabler - Rajan
//---------------------------------------------------------------------------------------------

#include "Global.h"

VOID WINAPI HeaderProc(DWORD dwPID)
{
	Log("------------------------------------------------");
	Log("[Rajan] [%s] [v%s] [PID: %d]", OPT_APPNAME, OPT_APPVERSION, dwPID);
	Log("[Rajan]       \\    /\\  ");
	Log("[Rajan]        )  ( ')   ");
	Log("[Rajan]       (  /  )    ");
	Log("[Rajan] cat    \\(__)|   ");
	Log("[Rajan] [Built: %s]", __TIMESTAMP__);
	Log("------------------------------------------------");
}

DWORD WINAPI MainProc(PVOID)
{
	DWORD dwCurProcId = GetCurrentProcessId();
	HeaderProc(dwCurProcId);

	if (!HookSockApi())
		Log("Failed Hooking SockApi");

	if (!HookWinApi())
		Log("Failed Hooking WinApi");

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&MainProc, NULL, NULL, NULL);
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		//
	}

	return TRUE;
}