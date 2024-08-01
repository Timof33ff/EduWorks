#pragma once
#include <windows.h>
#include <iostream>

static const wchar_t winName[] = L"Hello";
static const wchar_t winClassName[] = L"myWin";
static const wchar_t winChClassName[] = L"myChWin";
static const wchar_t childWinName[] = L"How are you?";


static HINSTANCE hin, childHin;// Дескрипторы экземпляра приложения

static HWND hwnd2 = NULL; // child window


static HINSTANCE hInst; 	// Дескриптор экземпляра приложения
static HINSTANCE hPrevInst; 	// Предыдущий экземпляр
static LPSTR lpCmdLine;	// Указатель на командную строку
static int nCmdShow;

static HWND hBtn; // дескриптор кнопки

static PAINTSTRUCT ps;
static HDC hdc;
static HDC hdc2;
static WCHAR greeting[] = L"Hello, world!";
static WCHAR wup[] = L"How are you?";

ATOM winclass();	 		// Регистрация класса окна приложения
ATOM childwinclass();
HWND makeWin();	// Создание главного окна приложения
void messageprocess();		// Запуск цикла обработки сообщений
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam); //Эта функция производит обработку сообщений для окна.

HWND makeChildWin(HWND hwnd);	// Создание родительского окна приложения



