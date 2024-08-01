#include "main.h"

HWND makeWin()
{
    return CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, winClassName,
        winName, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 640, 480, NULL, NULL, hin, NULL);
}