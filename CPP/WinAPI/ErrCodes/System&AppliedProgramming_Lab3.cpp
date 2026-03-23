// System&AppliedProgramming_Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("chcp 1251");

	WinAPIStyle();
	cout << endl;
	CStyle();
	cout << endl;
	CPPStyle();
	cout << endl;
	return 0;
}

