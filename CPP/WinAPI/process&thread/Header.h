#pragma once
#include <windows.h>
static HINSTANCE hin;
static HANDLE Thread1, Thread2;
static DWORD id1, id2;

static BOOL rect = 0;

static LRESULT CALLBACK WidProc(HWND, UINT, WPARAM, LPARAM);
ATOM winclass();
HWND makeexamplewin();
void messageprocess();

DWORD WINAPI ThreadFunc1(LPVOID Param); // выводит прямоугольники
DWORD WINAPI ThreadFunc2(LPVOID Param); // выводит эллипсы
