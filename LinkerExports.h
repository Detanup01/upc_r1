#pragma once

#pragma comment(linker, "/export:UPLAY_SAVE_Close=uplay_r1_o.UPLAY_SAVE_Close")
#pragma comment(linker, "/export:UPLAY_SAVE_GetSavegames=uplay_r1_o.UPLAY_SAVE_GetSavegames")
#pragma comment(linker, "/export:UPLAY_SAVE_Open=uplay_r1_o.UPLAY_SAVE_Open")
#pragma comment(linker, "/export:UPLAY_SAVE_Read=uplay_r1_o.UPLAY_SAVE_Read")
#pragma comment(linker, "/export:UPLAY_SAVE_ReleaseGameList=uplay_r1_o.UPLAY_SAVE_ReleaseGameList")
#pragma comment(linker, "/export:UPLAY_SAVE_Remove=uplay_r1_o.UPLAY_SAVE_Remove")
#pragma comment(linker, "/export:UPLAY_SAVE_SetName=uplay_r1_o.UPLAY_SAVE_SetName")
#pragma comment(linker, "/export:UPLAY_SAVE_Write=uplay_r1_o.UPLAY_SAVE_Write")