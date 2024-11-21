#include "CPlayManager.h"

char UplayDllPath[MAX_PATH] = { 0 };

namespace Uplay_Configuration
{
	char UserName[0x200] = { "UserName" };
	char UserEmail[0x200] = { "UplayEmu@cplay42.com" };
	char password[0x200] = { "UplayPassword74" };
	char GameLanguage[0x200] = { "en-US" };
	char UserId[1024] = { "c91c91c9-1c91-c91c-91c9-1c91c91c91c9" };
	char CdKey[1024] = { "1111-2222-3333-4444" };
	char TickedId[1024] = { "noT456umPqRt" };
	bool Offline = true;
	bool appowned = true;

	int cdkey1 = 0;
	int cdkey2 = 0;
	uint32_t gameAppId = 0;
}
namespace CPlay
{
	const char* FormatTheString(const char* Format, const char* ValueS, uint64_t ValueU)
	{
		char TheString[300] = { 0 };
		if (std::strcmp(ValueS, EMPTY) == 0) {
			std::sprintf(TheString, Format, ValueU);
			return TheString;
		}
		std::sprintf(TheString, Format, ValueS);
		return TheString;
	}
	bool IsTargetExist(LPCSTR path)
	{
		if (GetFileAttributesA(path) == INVALID_FILE_ATTRIBUTES)
			return false;
		return true;
	}
	void InitEmu(HMODULE MainModule)
	{
		char INI[MAX_PATH] = { 0 };					// Get ini directory
		GetModuleFileNameA(MainModule, INI, MAX_PATH);
		lstrcpyA(UplayDllPath, INI);

		int Size = lstrlenA(INI);
		for (int i = Size; i > 0; i--) {
			if (INI[i] == '\\') {
				ZeroMemory(&UplayDllPath[i + 1], (Size - i) + 1);
				lstrcpyA(&INI[i], "\\CPlay.ini");
				break;
			}
		}
		if (!IsTargetExist(INI)) {
			MessageBoxA(0, "Couldn't find CPlay.ini.", "CPlay", MB_ICONERROR);
			ExitProcess(0);
		}
// Read ini informations
		Uplay_Configuration::appowned = GetPrivateProfileIntA("Uplay", "IsAppOwned", 0, INI) == TRUE;
		Uplay_Configuration::Offline = GetPrivateProfileIntA("Uplay", "UplayConnection", 0, INI) != TRUE;
		Uplay_Configuration::gameAppId = GetPrivateProfileIntA("Uplay", "AppId", 0, INI);
		GetPrivateProfileStringA("Uplay", "Username", "CPlay", Uplay_Configuration::UserName, 0x200, INI);
		GetPrivateProfileStringA("Uplay", "Email", "UplayEmu@cplay42.com", Uplay_Configuration::UserEmail, 0x200, INI);
		GetPrivateProfileStringA("Uplay", "Password", "UplayPassword74", Uplay_Configuration::password, 0x200, INI);
		GetPrivateProfileStringA("Uplay", "Language", "en-US", Uplay_Configuration::GameLanguage, 0x200, INI);
		GetPrivateProfileStringA("Uplay", "CdKey", "1111-2222-3333-4444", Uplay_Configuration::CdKey, 0x200, INI);
		GetPrivateProfileStringA("Uplay", "UserId", "c91c91c9-1c91-c91c-91c9-1c91c91c91c9", Uplay_Configuration::UserId, 0x200, INI);
		GetPrivateProfileStringA("Uplay", "TickedId", "noT456umPqRt", Uplay_Configuration::TickedId, 0x200, INI);
	}
}