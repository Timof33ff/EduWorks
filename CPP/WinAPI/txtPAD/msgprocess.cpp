#include "main.h"

void messageprocess()
{
    MSG msg;
    while (GetMessage(&msg, (HWND)NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}