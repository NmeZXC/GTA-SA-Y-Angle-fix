//Hooks for SA.
#pragma once
#include <Windows.h>
#include "data.hpp"
#include "offsets.hpp"
#include <iostream>
//WND Proc event hook.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	//Using base pointer arithmetic.
	__try{
		*((float*)(GTABase + GTA_ScopeMouseY)) = ((*(float*)(GTABase + GTA_ScopeMouseX)) / 2);
	}
	__except(1){}
	//Return original
	return CallWindowProcA(oWndProc, hWnd, msg, wParam, lParam);
}
