//Main better mouse functions. (Hooks not included.)
#pragma once
#include "hooks.hpp"
#include "offsets.hpp"
#include "data.hpp"
void InitializateBM() {
	//Hooking simply WndProc by SetWindowLong.
	oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA(0, "GTA: San Andreas"), GWLP_WNDPROC, (LONG)WndProc);
}