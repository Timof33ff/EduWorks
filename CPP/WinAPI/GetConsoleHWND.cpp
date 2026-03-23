// GetConsoleHWND.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>
#include<string>

using namespace std;

HWND GetConsoleHWND(void)
{
	HWND HWNDFound;
	const DWORD s = 1024;
	WCHAR pszNWTitle[s];
	WCHAR pszOWTitle[s];

	GetConsoleTitleW(pszOWTitle, s);
	wsprintf(pszNWTitle, L"%d/%d", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitleW(pszNWTitle);
	Sleep(40);
	HWNDFound = FindWindowW(NULL, pszNWTitle);
	SetConsoleTitleW(pszOWTitle);
	return HWNDFound;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	HWND H;
	const DWORD size = 200;
	WCHAR ss[size]; 
	DWORD k = 0;

	H = GetConsoleHWND();

	while (k == 0)
	{
		H = GetNextWindow(H, GW_HWNDNEXT);
		GetWindowText(H, ss, size);
		if (H == NULL) { k = 1;}
		if (wcscmp(ss, L"Mozilla Firefox") == 0) { SendMessage(H, WM_CLOSE, 0, 0); }
	}
	return 0;
}

/*
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	DWORD k;
	HWND H = FindWindowA("MozillaWindowClass", "Mozilla Firefox");
	k = (DWORD)H;
	cout << k << "\n";
	SendMessage(H, WM_CLOSE, 0, 0);
	return 0;
}
*/
