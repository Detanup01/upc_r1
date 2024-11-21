del /Q /S full\*
rmdir /S /Q full
mkdir full
call build_env_x64.bat
cl /std:c++17 /LD dllmain.cpp CPlayManager.cpp pch.cpp uplay_data.cpp util.cpp User32.lib Shell32.lib /EHsc /MP12 /Ox /link /OUT:full\upc_r1_loader.dll
echo.
call build_env_x64.bat
cl /std:c++17 /LD dllmain.cpp CPlayManager.cpp pch.cpp uplay_data.cpp util.cpp User32.lib Shell32.lib /EHsc /MP12 /Ox /link /OUT:full\upc_r1_loader64.dll
echo.
pause
echo.