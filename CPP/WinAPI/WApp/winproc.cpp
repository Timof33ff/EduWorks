#include "main.h"

/*HWND CreateWindowEx(
    DWORD dwExStyle,      		// улучшенный стиль окна
    LPCTSTR lpClassName,  	// указатель на зарегистрированное им€ класса
    LPCTSTR lpWindowName, 	// указатель на им€ окна
    DWORD dwStyle,        		// стиль окна
    int x,                			// горизонтальна€ позици€ окна
    int y,                			// вертикальна€ позици€ окна
    int nWidth,           			// ширина окна
    int nHeight,          			// высота окна
    HWND hWndParent,      	// дескриптор родительского или окна владельца
    HMENU hMenu,          		// дескриптор меню или ID дочернего окна
    HINSTANCE hInstance,  	// дескриптор экземпл€ра прикладной программы
    LPVOID lpParam        		// указатель на данные создани€ окна
);*/

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch (msg)
    {
    case WM_CREATE:
        // сообщение создани€ окна
        hInst = ((LPCREATESTRUCT)lParam)->hInstance; // дескриптор приложени€
        // —оздаем и показываем кнопку
        hBtn = CreateWindow(L"button", L"Create new window",
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            50, 50, 140, 30, hwnd, 0, hInst, NULL);
        ShowWindow(hBtn, SW_SHOWNORMAL);
           
        break;
    case WM_COMMAND:
        if (lParam == (LPARAM)hBtn) {
            // обработка нажати€ кнопки
            
            hwnd2 = makeChildWin(hwnd);	// ¬торое окно
            ShowWindow(hwnd2, SW_SHOWNORMAL);
            
            std::cout << " Child window create [1 = yes, 0 = no] :\t" << IsChild(hwnd, hwnd2);
        }
        break;
    case WM_PAINT:
        
        hdc = BeginPaint(hwnd, &ps);
        
       //Here your application is laid out.
       //For this introduction, we just print out "Hello, Windows desktop!"
       //in the top left corner.
        TextOut(hdc,
            5, 5,
            greeting, wcslen(greeting));
        if (hwnd2 != NULL)
        {
            hdc2 = BeginPaint(hwnd2, &ps);
            // Here your application is laid out.
            // For this introduction, we just print out "Hello, Windows desktop!"
            // in the top left corner.
            TextOut(hdc2,
                5, 5,
                wup, wcslen(wup));
        }
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

