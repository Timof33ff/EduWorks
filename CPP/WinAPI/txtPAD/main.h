#pragma once

#include <Windows.h>
#include <iostream>

#define BUFSIZE 65535 
#define SHIFTED 0x8000 

static HWND hwnd, edit, sBtn;
static HINSTANCE hInst, hPrevInst, hin;

static LPSTR lpCmdLine;	// Указатель на командную строку
static int nCmdShow;
static PAINTSTRUCT ps;
static HDC hdc;

static HANDLE H;
static DWORD T;

static const int size = 10000;
static int i = 0;
static TCHAR text[size];



ATOM winclass();	 		// Регистрация класса окна приложения
HWND makeWin();	// Создание главного окна приложения
void messageprocess();		// Запуск цикла обработки сообщений
LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);