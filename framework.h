#pragma once
#include <codeanalysis\warnings.h>

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#ifdef _WIN64
#include "LinkerExports64.h"
#else
#include "LinkerExports.h"
#endif