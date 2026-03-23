#include "main.h"

HWND makeWin()
{
    return CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, winClassName,
        winName, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 640, 480, NULL, NULL, hin, NULL);
}

HWND makeChildWin(HWND hwnd)
{
    return CreateWindow(winChClassName, childWinName,
        WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_BORDER,
        200, 170, 240, 140, hwnd, 0, childHin, NULL);
}