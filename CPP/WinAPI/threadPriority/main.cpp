#include "main.h"


int main(void) // функцию main() используем с целью получения доступа к консоли для удобной отладки
{
    hin = hInst;		 // Сохранение дескриптора экземпляра приложения
    winclass();  	// Регистрация класса окна приложения
    HWND winhandler = makeWin(); 	//Создание главного окна
    ShowWindow(winhandler, SW_SHOW); 	// Отображение созданного окна
    messageprocess();				//Запуск цикла обработки сообщений
    return 0;
}