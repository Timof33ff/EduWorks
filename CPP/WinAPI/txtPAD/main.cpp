#include "main.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    hin = hInst;		 // Сохранение дескриптора экземпляра приложения
    winclass();  	// Регистрация класса окна приложения
    HWND winhandler = makeWin(); 	//Создание главного окна
    ShowWindow(winhandler, SW_SHOW); 	// Отображение созданного окна
    UpdateWindow(winhandler);
    messageprocess();				//Запуск цикла обработки сообщений
    return 0;
}


