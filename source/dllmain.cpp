// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "MemoryMgr.h"
#include <iostream>

using namespace Memory::VP;

void print_debug(char* a1)
{
	printf(a1);
}


extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		InjectHook(0x4BCDF0, print_debug, PATCH_JUMP);
		InjectHook(0x614B50, print_debug, PATCH_JUMP);
	}
}