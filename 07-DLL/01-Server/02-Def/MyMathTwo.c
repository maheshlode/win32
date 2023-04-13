#include<Windows.h>

// entry point function of DLL (OS call it through LoadLibrary)
BOOL WINAPI DllMain(HMODULE hModule,DWORD dwReason,LPVOID lpReserved)
{
	// code 
	switch(dwReason)
	{
		case DLL_PROCESS_ATTACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			break;
		default:
			break;
	}

	return (TRUE);

}

int MakeCube(int num) // known as microsoft specifier
{
	// code

	return (num*num*num);

}
