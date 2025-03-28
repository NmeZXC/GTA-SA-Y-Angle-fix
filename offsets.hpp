//Contains all offsets for all functions / variables.
#pragma once
#include <Windows.h>
uintptr_t GTABase = ((uintptr_t)GetModuleHandleA("gta-sa.exe")); // Module

#define GTA_CameraProc 0x12ED00
#define GET_CAMERAPROC (GTABase + GTA_CameraProc) // Camera process.

#define GTA_ScopeMouseX 0x7FC05C
#define GTA_ScopeMouseY 0x7FC058