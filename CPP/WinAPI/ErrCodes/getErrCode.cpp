#include "getErrCode.h"

LPWSTR getErrCode(DWORD codeErr)
{
    WCHAR Buff[256];
    WCHAR str[256]{};

        FormatMessage(
            FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
            0,
            codeErr,
            0,
            Buff,
            sizeof(Buff) - 1,
            0
        );

        if (Buff == NULL) wcscpy_s(str, L" Неопознанная ошибка.\n");
        else wcscpy_s(str, Buff);

        cout << "\tКод ошибки :\t" << codeErr << "\t||\t";
        wcout << str;
        cout << endl;

        return str;
}