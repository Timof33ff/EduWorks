#include "main.h"

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {
    case WM_CREATE:
        // сообщение создани¤ окна
        hInst = ((LPCREATESTRUCT)lParam)->hInstance; // дескриптор приложени¤

        break;
    case WM_COMMAND:
        break;
    case WM_PAINT:

        hdc = BeginPaint(hwnd, &ps);
        Thread1 = CreateThread(0, 0, ThreadFunc1, hwnd, CREATE_SUSPENDED, &id1);
        SetThreadPriority(Thread1, THREAD_PRIORITY_TIME_CRITICAL);
        Thread2 = CreateThread(0, 0, ThreadFunc2, hwnd, CREATE_SUSPENDED, &id2);
        SetThreadPriority(Thread2, THREAD_PRIORITY_IDLE);
        ResumeThread(Thread1);
        ResumeThread(Thread2);
        Sleep(6000);
        exit(1);
        // End application-specific layout section.
        EndPaint(hwnd, &ps);
        //EndPaint(hwnd2, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0); break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

