#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "LA.CPP"

using namespace std;

int PP(char* s);

int main()
{
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);

	char S[80];
	char T[250];
	int i, k;
	FILE* F1;

	cout << " Enter path or <<Exit>>  " << endl;
	cin >> S;

	while (strcmp(S, "Exit") != 0)
	{
		fopen_s(&F1, S, "rt");
		if (F1 == 0 || strcmp(S, "Exit") != 0)
	{
			fclose(F1); exit(1);
	}
		else
		{
			while (!feof(F1))
			{
				T[0] = 0;
				fgets(T, 250, F1);
				i = k = 0;
				while (T[i] != 0)
				{
					if (T[i] == 32)
					{
						T[i] = 0;
						strcpy_s(S, T + k);

						if ((PP(S) == 1) && (i - k > 2))
							cout << S << endl;

						k = i + 1;
					}
					i++;
				}
			}
			for (int i = 0; i < strlen(S);) S[i++] = 0;
			cout << " Enter path or <<Exit>>  " << endl;
			cin >> S;
		}

	}
	return 0;
}

int PP ( char *s)
{
	AStack St(80);
	
	for ( int i = 0; i < strlen(s); i++ )
	{
		St.push(s[i]); 
	}
		for ( int i = 0; i < strlen(s); i++ )
	{
		if ( St.pop() != s[i] )
		return 0;
	}
	
	return 1;
}
