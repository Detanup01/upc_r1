#include "pch.h"
#include "CPlayManager.h"
#include "uplay_data.h"
#include "util.h"
#include "framework.h"

HMODULE originalDLL = nullptr;

void init(HMODULE hModule)
{
	auto originalPath = getDllDir(hModule) / ORIG_DLL;
	originalDLL = LoadLibraryW(originalPath.c_str());
	if(!originalDLL)
	{
		exit(1);
	}
}


void shutdown()
{
	FreeLibrary(originalDLL);
}



#define UPLAY_EXPORT extern "C" _declspec(dllexport)

struct Chunks
{
	ULONG_PTR d1;
	void* d2;
};
struct Overmapped
{
	signed char pd[4];
	int32_t f4;
	int32_t f8;
};
struct FileOverlap
{
	DWORD addr1;
	DWORD addr2;
	DWORD addr3;
};
struct FileList
{
	DWORD num;
	void* bufferstring;
	DWORD pointer;
};
struct MyFileRef
{
	bool Write;
	HANDLE hFile;
	char* nameoffile;
};
std::mutex ThreadSafe;
std::multimap<DWORD, MyFileRef> FileStream;

// Exports implementations
UPLAY_EXPORT int UPLAY_ACH_EarnAchievement()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_GetAchievementImage()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_GetAchievements()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_ReleaseAchievementImage()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_ReleaseAchievementList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ACH_Write()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_AVATAR_Get(void* buf1)
{
	return 1;
}
UPLAY_EXPORT int UPLAY_AVATAR_GetAvatarIdForCurrentUser()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_AVATAR_GetBitmap()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_AVATAR_Release()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_ClearGameSession()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_AddPlayedWith()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_AddToBlackList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_DisableFriendMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_EnableFriendMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_GetFriendList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_Init()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_InviteToGame()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_IsBlackListed()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_IsFriend()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RemoveFriendship()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RemoveFromBlackList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RequestFriendship()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_RespondToGameInvite()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_ShowFriendSelectionUI()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_FRIENDS_ShowInviteFriendsToGameUI()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_GetLastError()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_GetNextEvent()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_GetOverlappedOperationResult(void* buf1, int* buf2)
{
	Overmapped* ovr = (Overmapped*)buf1;
	if (ovr->f4 == 0) {
		return 0;
	}
	else {
		*buf2 = ovr->f8;
		return 1;
	}
}
UPLAY_EXPORT int UPLAY_HasOverlappedOperationCompleted(void* buf1)
{
	Overmapped* ovr = (Overmapped*)buf1;
	return ovr->f4;
}
UPLAY_EXPORT int UPLAY_INSTALLER_AreChunksInstalled()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_INSTALLER_GetChunkIdsFromTag()
{
	return 0;
}
Chunks* chunks = nullptr;
UPLAY_EXPORT int UPLAY_INSTALLER_GetChunks(void** buf1)
{
	ThreadSafe.lock();

	chunks = (Chunks*)VirtualAlloc(0, 10, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	chunks->d1 = 1;
	chunks->d2 = VirtualAlloc(0, 1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (buf1)
		*buf1 = (void*)chunks;

	ThreadSafe.unlock();
	return 1;

}
UPLAY_EXPORT const char* UPLAY_INSTALLER_GetLanguageUtf8()
{
	return Uplay_Configuration::GameLanguage;
}
UPLAY_EXPORT int UPLAY_INSTALLER_Init()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_INSTALLER_ReleaseChunkIdList()
{
	ThreadSafe.lock();

	VirtualFree((void*)chunks, 0, MEM_RELEASE);

	ThreadSafe.unlock();
	return 1;
}
UPLAY_EXPORT int UPLAY_INSTALLER_UpdateInstallOrder()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_Init()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_METADATA_ClearContinuousTag()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_METADATA_SetContinuousTag()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_METADATA_SetSingleEventTag()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Apply()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Close()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Enumerate()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Get()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Open()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_ReleaseKeyValueList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_Set()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OPTIONS_SetInGameState()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_SetShopUrl()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_Show()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowBrowserUrl()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowFacebookAuthentication()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowNotification()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowMicroApp()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_OVERLAY_ShowShopUrl()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_DisablePartyMemberMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_EnablePartyMemberMenuItem()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_GetFullMemberList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_GetId()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_GetInGameMemberList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_Init()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_InvitePartyToGame()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_InviteToParty()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_IsInParty()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_IsPartyLeader()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_PromoteToLeader()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_RespondToGameInvite()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_SetGuest()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PARTY_SetUserData()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_PARTY_ShowGameInviteOverlayUI()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PRESENCE_SetPresence()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_PeekNextEvent()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_Quit()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_Release()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_STORE_Checkout()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_GetPartner()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_GetProducts()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_ReleaseProductsList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_ShowProductDetails()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_ShowProducts()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_SetGameSession()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_SetLanguage(const char* language)
{
	std::strcpy(Uplay_Configuration::GameLanguage, language);
	return 1;
}
UPLAY_EXPORT int UPLAY_Start()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_StartCN()
{
	return UPLAY_Start();
}
UPLAY_EXPORT int UPLAY_Startup()
{
	return UPLAY_Start();
}
UPLAY_EXPORT int UPLAY_USER_ClearGameSession()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_ConsumeItem()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_GetAccountId()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetAccountIdUtf8()
{
	return Uplay_Configuration::UserId;
}
UPLAY_EXPORT int UPLAY_USER_GetCPUScore()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetCdKeyUtf8()
{
	return Uplay_Configuration::CdKey;
}
UPLAY_EXPORT int UPLAY_USER_GetCdKeys()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_GetConsumableItems(void* buf1)
{
#ifdef _WIN64
	memset(buf1, 0, 8);
#else
	memset(buf1, 0, 4);
#endif
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_GetCredentials()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_GetEmail()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetEmailUtf8()
{
	return Uplay_Configuration::UserEmail;
}
UPLAY_EXPORT int UPLAY_USER_GetGPUScore()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_GetGPUScoreConfidenceLevel()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetNameUtf8()
{
	return Uplay_Configuration::UserName;
}
UPLAY_EXPORT int UPLAY_USER_GetPassword()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetPasswordUtf8()
{
	return Uplay_Configuration::password;
}
UPLAY_EXPORT int UPLAY_USER_GetProfile()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetTicketUtf8()
{
	return Uplay_Configuration::TickedId;
}
UPLAY_EXPORT int UPLAY_USER_GetUsername()
{
	return 0;
}
UPLAY_EXPORT const char* UPLAY_USER_GetUsernameUtf8()
{
	return Uplay_Configuration::UserName;
}
UPLAY_EXPORT int UPLAY_USER_IsConnected()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_IsInOfflineMode()
{
	return Uplay_Configuration::Offline;
}
UPLAY_EXPORT int UPLAY_USER_IsOwned(int data)
{
	return Uplay_Configuration::appowned;
}
UPLAY_EXPORT int UPLAY_USER_ReleaseCdKeyList()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_ReleaseConsumeItemResult()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_USER_ReleaseProfile()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_USER_SetGameSession()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_Update()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_GetActions()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_WIN_GetRewards()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_WIN_GetUnitBalance()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_WIN_RefreshActions()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_ReleaseActionList()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_ReleaseRewardList()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_WIN_SetActionsCompleted()
{
	return 1;
}
UPLAY_EXPORT int UPLAY_CHAT_GetHistory()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_Init()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_ReleaseHistoryList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_SendMessage()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_CHAT_SentMessagesRead()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PRODUCT_GetProductList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_PRODUCT_ReleaseProductList()
{
	return 0;
}
UPLAY_EXPORT int UPLAY_STORE_IsEnabled()
{
	return 0;
}