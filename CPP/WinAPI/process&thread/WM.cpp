#include "Header.h"

static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HWND hBtn = 0;
    switch (msg)
    {
    case WM_CREATE:
        // Создаем и показываем кнопку
        hBtn = CreateWindow(L"button", L"Create rectangle",
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            50, 50, 140, 30, hwnd, 0, hin, NULL);
        ShowWindow(hBtn, SW_SHOWNORMAL);

        break;
    case WM_COMMAND:
        if (lParam == (LPARAM)hBtn) {
            // обработка нажатия кнопки
            rect = 1;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0); break;
    case WM_PAINT:
        if(rect) Thread1 = CreateThread(0, 0, ThreadFunc1, hwnd, 0, &id1);
        //Thread2 = CreateThread(0, 0, ThreadFunc2, hwnd, 0, &id2);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
