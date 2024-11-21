#include "pch.h"
#include "util.h"

path getDllDir(HMODULE hModule)
{
	TCHAR name[MAX_PATH];
	auto result = GetModuleFileName(hModule, name, MAX_PATH);
	return path(name).parent_path();
}
