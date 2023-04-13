# Win32-2021

## 01-Window
This program creates a simple black window using the Windows API and displays it on the screen. The window does not have any functionality except to be closed when the user clicks the 'X' button in the corner.

## 02-Messages
This is a simple Windows application written in Cpp language using the Win32 API. The program creates a window and handles several messages including WM_CREATE, WM_KEYDOWN, WM_LBUTTONDOWN, WM_RBUTTONDOWN, and WM_DESTROY.

When the program starts, a window is created with the title "ML:Window". On WM_CREATE message, the program displays a message box showing the sum of two numbers 25 and 75. When a key is pressed (WM_KEYDOWN), left mouse button is clicked (WM_LBUTTONDOWN), or right mouse button is clicked (WM_RBUTTONDOWN), a message box is displayed with a corresponding message. On WM_DESTROY message, a message box is displayed and the program terminates.

The program demonstrates how to create and manage a simple window and handle messages in a Win32 application.

## 03-Icon
This is a basic Windows application written in C++ using the Win32 API. The program creates a window and displays it on the screen with a icon which is located at the upper left corner. The main function of the program is WinMain, which handles the initialization of the window and message loop. The WndProc function handles events that occur with the window, such as destruction.

## 04-HelloWorld
This is a basic Windows application written in C++ using the Win32 API. The program creates a window and displays the text "Hello World!!!" in the center of the window using the DrawText function inside the WM_PAINT message handling code. The main function of the program is WinMain, which handles the initialization of the window and message loop. The WndProc function handles events that occur with the window, such as destruction.

## 05-Paint
This is a basic Windows application written in C++ using the Win32 API. The program creates a window that changes color based on user input. The main function of the program is WinMain, which handles the initialization of the window and message loop. The WndProc function handles events that occur with the window, such as key presses and repaints. This code demonstrates how to handle user input in a Windows application and how to use GDI functions, such as CreateSolidBrush() and FillRect(), to draw graphics on the window.

## 06-Multithreading
This is a basic Windows application written in C++ using the Win32 API. The program creates a window and launches two threads using the CreateThread function inside the WM_CREATE message handling code. Each thread uses a separate function, ThreadProcOne and ThreadProcTwo, to perform a loop that displays numbers in either incrementing or decrementing order on the window using the TextOut function. The main function of the program is WinMain, which handles the initialization of the window and message loop. The WndProc function handles events that occur with the window, such as destruction and left mouse button clicks.

## 07-DLL
This is a basic Windows application written in C++ using the Win32 API. The program creates a window and calls a function from a separate DLL, MyMathOne.dll, to calculate the square of a number. The main function of the program is WinMain, which handles the initialization of the window and message loop. The WndProc function handles events that occur with the window, such as destruction. This code demonstrates how to use functions from an external DLL in a Windows application using the LoadLibrary() and GetProcAddress() functions. Note that in order to link to the DLL, the program must include a reference to the .lib file associated with the DLL using the #pragma comment directive.
