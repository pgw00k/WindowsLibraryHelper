#pragma once

#include <Windows.h>
#include <stdio.h>
#include <DLLExport.h>

DLLEXPORT void OpenConsole(HINSTANCE hinstDLL,DWORD pid)
{

	AllocConsole();
	SetConsoleTitle(L"Dummy");
	AttachConsole(pid);

	FILE* pFile = NULL;
	freopen_s(&pFile, "CON", "r", stdin);
	freopen_s(&pFile, "CON", "w", stdout);
	freopen_s(&pFile, "CON", "w", stderr);

	printf("Hello,Dummy! %d %d\n",pid,GetCurrentProcessId());

	//DisableThreadLibraryCalls(hinstDLL);
}

DLLEXPORT void CloseConsole()
{
	FreeConsole();
}