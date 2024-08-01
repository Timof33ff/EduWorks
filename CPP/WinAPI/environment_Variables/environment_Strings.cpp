// environment_Strings.cpp : Этот файл содержит функцию "_tmain". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#include <locale>
#include "getErrCode.h"
#include <tchar.h>
#include <stdio.h>

int _tmain()
{
    setlocale(LC_CTYPE, "Russian");

    LPTSTR lpszVariable;
    LPTCH lpvEnv;

    // Get a pointer to the environment block. 

    lpvEnv = GetEnvironmentStrings();

    // If the returned pointer is NULL, exit.
    if (lpvEnv == NULL)
    {
        printf("GetEnvironmentStrings failed (%d)", getErrCode(GetLastError()), "\n");
        return 0;
    }

    // Variable strings are separated by NULL byte, and the block is 
    // terminated by a NULL byte. 

    lpszVariable = (LPTSTR)lpvEnv;

    while (*lpszVariable)
    {
        _tprintf(TEXT("%s\n"), lpszVariable);
        lpszVariable += lstrlen(lpszVariable) + 1;
    }
    FreeEnvironmentStrings(lpvEnv);
    return 1;
}

