#pragma once
#include <windows.h>
#include <iostream>

static const wchar_t winName[] = L"Hello";
static const wchar_t winClassName[] = L"myWin";
static const wchar_t winChClassName[] = L"myChWin";
static const wchar_t childWinName[] = L"How are you?";


static HINSTANCE hin, childHin;// ����������� ���������� ����������

static HWND hwnd2 = NULL; // child window


static HINSTANCE hInst; 	// ���������� ���������� ����������
static HINSTANCE hPrevInst; 	// ���������� ���������
static LPSTR lpCmdLine;	// ��������� �� ��������� ������
static int nCmdShow;

static HWND hBtn; // ���������� ������

static PAINTSTRUCT ps;
static HDC hdc;
static HDC hdc2;
static WCHAR greeting[] = L"Hello, world!";
static WCHAR wup[] = L"How are you?";

ATOM winclass();	 		// ����������� ������ ���� ����������
ATOM childwinclass();
HWND makeWin();	// �������� �������� ���� ����������
void messageprocess();		// ������ ����� ��������� ���������
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam); //��� ������� ���������� ��������� ��������� ��� ����.

HWND makeChildWin(HWND hwnd);	// �������� ������������� ���� ����������



