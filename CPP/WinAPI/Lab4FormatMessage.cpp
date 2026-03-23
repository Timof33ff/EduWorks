// Lab4FormatMessage.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <locale>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    system("chcp 1251");
    int codeErr = 144;
    WCHAR Buff[256];
    WCHAR str[256]{};

    while (codeErr != 0)
    {
        cout << " Введите код ошибки : " << endl << "\t";
        cin >> codeErr;

        FormatMessage(
        FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
        0,
        codeErr,
        0,
        Buff,
        sizeof(Buff)-1,
        0
        );

        if (Buff == NULL) wcscpy(str, L" Неопознанная ошибка.\n");
        else wcscpy(str, Buff);

        cout << " Код ошибки : " << codeErr << " || "; wcout << str;
        cout << endl;
    }
    cout << " Работа программы успешно завершена!";
    return 0;
}

