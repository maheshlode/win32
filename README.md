# Win32-2021

## 01-Window
This program creates a simple black window using the Windows API and displays it on the screen. The window does not have any functionality except to be closed when the user clicks the 'X' button in the corner.

## 02-Messages
This is a simple Windows application written in Cpp language using the Win32 API. The program creates a window and handles several messages including WM_CREATE, WM_KEYDOWN, WM_LBUTTONDOWN, WM_RBUTTONDOWN, and WM_DESTROY.

When the program starts, a window is created with the title "ML:Window". On WM_CREATE message, the program displays a message box showing the sum of two numbers 25 and 75. When a key is pressed (WM_KEYDOWN), left mouse button is clicked (WM_LBUTTONDOWN), or right mouse button is clicked (WM_RBUTTONDOWN), a message box is displayed with a corresponding message. On WM_DESTROY message, a message box is displayed and the program terminates.

The program demonstrates how to create and manage a simple window and handle messages in a Win32 application.
