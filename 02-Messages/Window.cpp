//Header Files
#include<windows.h>

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
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Registration of WNDCLASSEX
	RegisterClassEx(&wndclass);

	//creating window
	hwnd = CreateWindow(
		szAppName,
	TEXT("ML:Window"),
		WS_OVERLAPPEDWINDOW,
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
	ShowWindow(hwnd, iCmdshow);

	//update the window
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//local variable declarations
    TCHAR str[255];
	int num1,num2,num3;


	//code
	switch (iMsg)
	{
		case WM_CREATE:
			num1=25;
			num2=75;
			num3=num1+num2;
			wsprintf(str,TEXT("Sum of %d and %d is %d "),num1,num2,num3);//WM_CREATE MESSAGE IS RECIEVED (str,TEXT("Sum of %d and %d is %d "),num1,num2,num3
			MessageBox(hwnd,str,TEXT("Message"),MB_OK);
			break;
		case WM_KEYDOWN:
			wsprintf(str,TEXT("WM_KEYDOWN MESSAGE IS RECIEVED"));
			MessageBox(hwnd,str,TEXT("Message"),MB_OK);
			break;
		case WM_LBUTTONDOWN:
			wsprintf(str,TEXT("WM_LBUTTONDOWN MESSAGE IS RECIEVED"));
			MessageBox(hwnd,str,TEXT("Message"),MB_OK);
			break;
		case WM_RBUTTONDOWN:
			wsprintf(str,TEXT("WM_RBUTTONDOWN MESSAGE IS RECIEVED"));
			MessageBox(hwnd,str,TEXT("Message"),MB_OK);
			break;
		// case WM_SETFOCUS:
		// 	wsprintf(str,TEXT("WM_SETFOCUS MESSAGE IS RECIEVED"));
		// 	MessageBox(hwnd,str,TEXT("Message"),MB_OK);
		// 	break;
		// case WM_KILLFOCUS:
		// 	wsprintf(str,TEXT("WM_KILLFOCUS MESSAGE IS RECIEVED"));
		// 	MessageBox(hwnd,str,TEXT("Message"),MB_OK);
		// 	break;	
		case WM_DESTROY:
			wsprintf(str,TEXT("WM_DESTROY MESSAGE IS RECIEVED"));
			MessageBox(hwnd,str,TEXT("Message"),MB_OK);
			PostQuitMessage(0);
			break;
		default:
			break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
