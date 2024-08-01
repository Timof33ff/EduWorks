#include "main.h"

DWORD __stdcall ThreadFunc1(LPVOID Param)
{
    int j = 0; HWND hwnd; HDC DC;
    hwnd = (HWND)Param;
    DC = GetDC(hwnd);
    while (j < 400)
    {
        for (int k = 0; k < 10000000; k++) rand();  // задержка
        TextOut(DC, 10 + j, 10, L"A", 1);
        j += 10;
    }
    return 0;
}

DWORD __stdcall ThreadFunc2(LPVOID Param)
{
    int j = 0; HWND hwnd; HDC DC;
    hwnd = (HWND)Param;
    DC = GetDC(hwnd);
    while (j < 400)
    {
        for (int k = 0; k < 10000000; k++) rand();  // задержка
        TextOut(DC, 10 + j, 30, L"B", 1);
        j += 10;
    }
    return 0;
}