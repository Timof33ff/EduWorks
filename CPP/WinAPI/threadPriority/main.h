#pragma once
#pragma once
#include <windows.h>
#include <iostream>

static const wchar_t winName[] = L"Hello";
static const wchar_t winClassName[] = L"myWin";


static HINSTANCE hin;


static HINSTANCE hInst; 	// ���������� ���������� ����������
static HINSTANCE hPrevInst; 	// ���������� ���������
static LPSTR lpCmdLine;	// ��������� �� ��������� ������
static int nCmdShow;

static PAINTSTRUCT ps;
static HDC hdc;

//������
static HANDLE Thread1, Thread2;
DWORD WINAPI ThreadFunc1(LPVOID Param);
DWORD WINAPI ThreadFunc2(LPVOID Param);
static DWORD id1, id2;

ATOM winclass();	 		// ����������� ������ ���� ����������
HWND makeWin();	// �������� �������� ���� ����������
void messageprocess();		// ������ ����� ��������� ���������
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam); //��� ������� ���������� ��������� ��������� ��� ����.
