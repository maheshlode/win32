//Header Files
#include<windows.h>
#include "Window.h"

//global functions declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

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
	//HDC hdc;
	HANDLE hThread1=NULL;
	HANDLE hThread2=NULL;

	
	//code
	switch (iMsg)
	{
	
		case WM_CREATE:
			hThread1=CreateThread(
				NULL,
				0,
				(LPTHREAD_START_ROUTINE)ThreadProcOne,
				(LPVOID)hwnd,
				0,
				NULL
			);
			hThread2=CreateThread(
				NULL,
				0,
				(LPTHREAD_START_ROUTINE)ThreadProcTwo,
				(LPVOID)hwnd,
				0,
				NULL
			);
			break;
		case WM_LBUTTONDOWN:
			MessageBox(hwnd,TEXT("This is my message box !!"),TEXT("MESSAGE"),MB_OK);
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

DWORD WINAPI ThreadProcOne(LPVOID param)
{
	//variable declarations
	HDC hdc;
	TCHAR str[255];
	//wchar_t str[255];
	int i;

	//code 
	hdc=GetDC((HWND)param);
	SetBkColor(hdc,RGB(0,0,0));
	SetTextColor(hdc,RGB(255,255,0));
	for(i=0;i<32767;i++)
	{
		wsprintf(str,TEXT("Numbers In Incrementing Order : %d"),i);
		TextOut(hdc,5,5,str,wcslen(str));
	}
	ReleaseDC((HWND)param,hdc);

	return 0;

}


DWORD WINAPI ThreadProcTwo(LPVOID param)
{
	//variable declarations
	HDC hdc;
	TCHAR str[255];
	int i;

	//code 
	hdc=GetDC((HWND)param);
	SetBkColor(hdc,RGB(0,0,0));
	SetTextColor(hdc,RGB(0,255,255));
	for(i=32767;i>=0;i--)
	{
		wsprintf(str,TEXT("Numbers In Decrementing Order : %d"),i);
		TextOut(hdc,5,20,str,wcslen(str));
	}
	ReleaseDC((HWND)param,hdc);

	return 0;

}

