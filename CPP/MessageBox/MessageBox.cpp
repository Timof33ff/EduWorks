// MessageBox.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    DWORD res = MessageBox(
        NULL,
        L"Text message",
        L"Operation complete",
        MB_ICONERROR | MB_YESNO
    );
    cout << res << endl;
    return 0;
}