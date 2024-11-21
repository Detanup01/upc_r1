del /Q /S release86\*
rmdir /S /Q release86
mkdir release86
call build_env_x86.bat
cl /std:c++17 /LD /DEMU_RELEASE_BUILD /DNDEBUG dllmain.cpp CPlayManager.cpp pch.cpp uplay_data.cpp User32.lib Shell32.lib /EHsc /MP12 /Ox /link /OUT:release64\uplay_r1_loader.dll
pasue