//Header Files
#include<windows.h>
#include "Window.h"

//global functions declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//Global variable declarations
#define ID_NUMBER 501

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
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	/* TCHAR str[] = TEXT("Hello World !!!"); */
	HBRUSH hbrush;
	static int iPaintFlag=0;
	
	//code
	switch (iMsg)
	{
		case WM_CREATE:
			SetTimer(hwnd,ID_NUMBER,1000,NULL);//
			break;
		case WM_TIMER:
			KillTimer(hwnd,ID_NUMBER);
			iPaintFlag++;
			if(iPaintFlag>8)
			{
				iPaintFlag=0;
			}
			InvalidateRect(hwnd,NULL,TRUE);
			SetTimer(hwnd,ID_NUMBER,1000,NULL);
			break;
		case WM_PAINT:
			GetClientRect(hwnd,&rc);
			hdc=BeginPaint(hwnd,&ps);// window handle and paint struct
			if(iPaintFlag==1)
			{
				hbrush=CreateSolidBrush(RGB(255,0,0));
			}
			else if(iPaintFlag==2)
			{
				hbrush=CreateSolidBrush(RGB(0,255,0));
			}
			else if(iPaintFlag==3)
			{
				hbrush=CreateSolidBrush(RGB(0,0,255));
			}
			else if(iPaintFlag==4)
			{
				hbrush=CreateSolidBrush(RGB(0,255,255));
			}
			else if(iPaintFlag==5)
			{
				hbrush=CreateSolidBrush(RGB(255,0,255));
			}
			else if(iPaintFlag==6)
			{
				hbrush=CreateSolidBrush(RGB(255,255,0));
			}
			else if(iPaintFlag==7)
			{
				hbrush=CreateSolidBrush(RGB(0,0,0));
			}
			else if(iPaintFlag==8)
			{
				hbrush=CreateSolidBrush(RGB(255,255,255));
			}
			else
			{
				hbrush=CreateSolidBrush(RGB(128,128,128));// medium grey
			}
			FillRect(hdc,&rc,hbrush);
			DeleteObject(hbrush);
			EndPaint(hwnd,&ps);
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
