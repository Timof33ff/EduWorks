#include "main.h"

ATOM winclass() // Регистрация класса окна
{
    WNDCLASSEX wc; // Структура для информации о классе окна
    memset(&wc, 0, sizeof(WNDCLASS)); // очистка памяти для структуры
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW; // Стиль класса окон
    wc.lpfnWndProc = (WNDPROC)WndProc; // Адрес оконной функции
    wc.cbClsExtra = 0; // Дополнительная память
    wc.cbWndExtra = 0; // Дополнительная память
    wc.hInstance = hin; // Экземпляр приложения
    wc.hIcon = LoadIcon(hin, IDI_APPLICATION); // Пиктограмма для окон
    wc.hCursor = LoadCursor(hin, IDC_ARROW); // Курсор мыши для окон
    wc.hCursor = LoadCursor(hin, IDC_APPSTARTING); // Курсор мыши для окон
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // Кисть для окон
    wc.lpszMenuName = NULL; // Ресурс меню окон
    wc.lpszClassName = L"txtpad"; // Имя класса окон
    wc.hIconSm = LoadCursor(hin, IDC_APPSTARTING); // иконка
    return RegisterClassEx(&wc); // Pегистрация класса окна.
}