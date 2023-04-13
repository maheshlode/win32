#include<Windows.h>

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

__declspec(dllexport) int MakeSquare(int num) // known as microsoft specifier
{
	// code

	return (num*num);

}
