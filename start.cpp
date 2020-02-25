#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <cstdio>
#include <cstdlib>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{   
    //Register the window class
    MSG msg;
    WNDCLASSEX wc;
    HWND hWnd = NULL;
    const wchar_t CLASS_NAME[] = L"ChatApp";

    ZeroMemory(&msg, sizeof(msg));
    ZeroMemory(&wc, sizeof(wc));
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;

    if (RegisterClassEx(&wc) == -1){
        return -1;
    }

    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 
    CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(
    HWND hWnd, 
    UINT msg, 
    WPARAM wParam, 
    LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
        {
            DestroyWindow(hWnd);
            PostQuitMessage(0);
            break;
        }
        default:
            DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return (LRESULT)0;
}