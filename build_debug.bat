del /Q /S release64\*
rmdir /S /Q release64
mkdir release64
call build_env_x64.bat
cl /std:c++17 /LD dllmain.cpp CPlayManager.cpp pch.cpp uplay_data.cpp util.cpp User32.lib Shell32.lib /EHsc /MP12 /Ox /link /OUT:release64\uplay_r1_loader64.dll
echo asss
echo aa
pause
echo ss