#include "plugin.h"

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <winnt.h>

static void openConsole()
{
    if (AllocConsole()) {
        FILE* fs {};
        freopen_s(&fs, "CONIN$", "r", stdin);
        freopen_s(&fs, "CONOUT$", "w", stdout);
        freopen_s(&fs, "CONOUT$", "w", stderr);
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH) {
        openConsole();
    }

    return TRUE;
}
