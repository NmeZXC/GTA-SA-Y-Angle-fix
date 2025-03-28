//Attach header.
#pragma once
#include <Windows.h>
#include "functions.hpp"
void BetterMouseAttach() {
	//Say about attaching.
	MessageBoxA(0, "Better Mouse attached. Thanks for use!", 0, 0);
	//Initializating
	InitializateBM();
}