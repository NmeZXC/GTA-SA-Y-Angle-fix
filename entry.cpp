//Entry point.
#include <Windows.h>
#include "attach.hpp"
#include <iostream>
#pragma comment(lib, "d3d9.lib")
//GTA use FreeLibrary for all don't need dll, and for BMD9.dll also. We hook it and check!
//https://learn.microsoft.com/en-us/windows/win32/dlls/dllmain
BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    DisableThreadLibraryCalls(hinstDLL);
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH: {
        LoadLibraryA("d3d9.dll");
        char ret[1] = { 0xC3 }; // Protection delete.
        WriteProcessMemory(GetCurrentProcess(), &FreeLibrary, ret, 1, 0);
        //Hook freeLibrary.
        //Call main better mouse thread.
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BetterMouseAttach, 0, 0, 0);
        break;
    }
    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        if (lpvReserved != nullptr)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}