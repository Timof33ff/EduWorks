#include <iostream>
#include <string>
#include <windows.h>
#include <process.h>
#include <locale.h>

using namespace std;

string S;  // строка доступная двум потокам
HANDLE Sem; // дескриптор (hendle) семафора

unsigned __stdcall ReadFunc(void* arg)
{
	WaitForSingleObject(Sem, INFINITE);
	cout << "<Было введено: " << S << "\n";
	return 0;
}

unsigned __stdcall WriteFunc(void* arg)
{
	cout << "Введите текст: ";
	getline(cin, S);
	ReleaseSemaphore(Sem, 1, NULL);
	return 0;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);  // параметры установки кодовой страницы, если будет ввод 
	SetConsoleOutputCP(1251);  // русского текста
	Sem = CreateSemaphore(NULL, 0, 1000, NULL);
	unsigned TRDID[2];
	HANDLE TRD[2]; // массив из двух потоков
	TRD[0] = (HANDLE)_beginthreadex(NULL, 0, &ReadFunc, NULL, 0, &TRDID[0]);
	TRD[1] = (HANDLE)_beginthreadex(NULL, 0, &WriteFunc, NULL, 0, &TRDID[1]);
	WaitForMultipleObjects(2, TRD, TRUE, INFINITE);
	CloseHandle(Sem);
	CloseHandle(TRD[0]);
	CloseHandle(TRD[1]);
	return 0;
}
