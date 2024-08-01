#include "main.h"

/*int WINAPI WinMain(
    HINSTANCE hInst, 	// Дескриптор экземпляра приложения
    HINSTANCE hPrevInst, 	// Предыдущий экземпляр
    LPSTR lpCmdLine, 	// Указатель на командную строку
    int nCmdShow)
{*/


int main(void) // функцию main() используем с целью получения доступа к консоли для удобной отладки
{
    hin = childHin = hInst;		 // Сохранение дескриптора экземпляра приложения
    winclass();  	// Регистрация класса окна приложения
    childwinclass(); 
    HWND winhandler = makeWin(); 	//Создание главного окна
    ShowWindow(winhandler, SW_SHOW); 	// Отображение созданного окна
    messageprocess();				//Запуск цикла обработки сообщений
    return 0;
}