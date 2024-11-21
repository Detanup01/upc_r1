// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdlib.h>
#include "CPlayManager.h"
#include "uplay_data.h"


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{

		CPlay::InitEmu(hModule);
		init(hModule);
	}
	else if(ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		shutdown();
	}
	return TRUE;
}
