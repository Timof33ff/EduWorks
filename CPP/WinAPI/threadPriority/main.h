#pragma once
#pragma once
#include <windows.h>
#include <iostream>

static const wchar_t winName[] = L"Hello";
static const wchar_t winClassName[] = L"myWin";


static HINSTANCE hin;


static HINSTANCE hInst; 	// Дескриптор экземпляра приложения
static HINSTANCE hPrevInst; 	// Предыдущий экземпляр
static LPSTR lpCmdLine;	// Указатель на командную строку
static int nCmdShow;

static PAINTSTRUCT ps;
static HDC hdc;

//Потоки
static HANDLE Thread1, Thread2;
DWORD WINAPI ThreadFunc1(LPVOID Param);
DWORD WINAPI ThreadFunc2(LPVOID Param);
static DWORD id1, id2;

ATOM winclass();	 		// Регистрация класса окна приложения
HWND makeWin();	// Создание главного окна приложения
void messageprocess();		// Запуск цикла обработки сообщений
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam); //Эта функция производит обработку сообщений для окна.
