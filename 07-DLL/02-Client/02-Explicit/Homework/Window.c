//Header Files
#include<windows.h>
#include "Window.h"

//global functions declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global variable declarations

//Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdshow)
{
	//local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("WINDEV");

	//code
	//wndclass initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	//Registration of WNDCLASSEX
	RegisterClassEx(&wndclass);

	//creating window
	hwnd = CreateWindow(
		szAppName,
	TEXT("ML:Window"),
		WS_OVERLAPPEDWINDOW, // ws_cismenu caption thickframe minimizebox maximizebox
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	//Show window
	ShowWindow(hwnd, iCmdshow); // sw_maximize in pace of iCmdshow try it 

	//update the window
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);// wparam is wordparam and it is unsigned int so we typecast it to int
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//local variable declarations
	HMODULE hDLL=NULL;
	typedef int (*MakeCubeFunctionPointer)(int);
    MakeCubeFunctionPointer pfnMakeCube=NULL; // pfn -> pointer to function
	typedef int (*MakeSquareFunctionPointer)(int);
	MakeSquareFunctionPointer pfnMakeSquare = NULL;
    int iNum=5;
    int iCube;
	int iSquare;
    TCHAR str[255];
	//code
	switch (iMsg)
	{
        case WM_CREATE:
            hDLL=LoadLibrary(TEXT("MyMathTwo.dll"));
            if(hDLL==NULL)
            {
                MessageBox(hwnd,TEXT("Load Library() Failed"),TEXT("ERROR"),MB_OK);
                DestroyWindow(hwnd);
            }
        
            pfnMakeCube=(MakeCubeFunctionPointer)GetProcAddress(hDLL,"MakeCube");
            if(pfnMakeCube==NULL)
            {
                MessageBox(hwnd,TEXT("GetProcAddress() Failed"),TEXT("ERROR"),MB_OK);
                FreeLibrary(hDLL);
                DestroyWindow(hwnd);
            }
            iCube=pfnMakeCube(iNum);
            wsprintf(str,TEXT("Cube of %d is %d "),iNum,iCube);
            MessageBox(hwnd,str,TEXT("Cube Calculation"),MB_OK);
            FreeLibrary(hDLL);
            hDLL=NULL;



			 hDLL=LoadLibrary(TEXT("MyMathOne.dll"));
            if(hDLL==NULL)
            {
                MessageBox(hwnd,TEXT("Load Library() Failed"),TEXT("ERROR"),MB_OK);
                DestroyWindow(hwnd);
            }
        
            pfnMakeSquare=(MakeSquareFunctionPointer)GetProcAddress(hDLL,"MakeSquare");
            if(pfnMakeCube==NULL)
            {
                MessageBox(hwnd,TEXT("GetProcAddress() Failed"),TEXT("ERROR"),MB_OK);
                FreeLibrary(hDLL);
                DestroyWindow(hwnd);
            }
            iSquare=pfnMakeSquare(iNum);
            wsprintf(str,TEXT("Square of %d is %d "),iNum,iSquare);
            MessageBox(hwnd,str,TEXT("Square Calculation"),MB_OK);
            FreeLibrary(hDLL);
            hDLL=NULL;
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            //PostMessage(hwnd,WM_QUIT,0,0L);
            break;
        default:
            break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));// parameters are same as WndProc

}
