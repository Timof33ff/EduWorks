#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "LA.CPP"
#include <string>
using namespace std;

int PP ( char *s);

int main () 
{
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
	
	char S[80];
	char T[250];
	char path[80];
	int i, k;
	FILE *F1;

	cout << " Enter path" << endl;
	cin >> path;

    fopen_s( &F1, path, "rt");
	
	  while ( !feof(F1))
	  {
		T[0] = 0;
		fgets( T, 250, F1);
		i = k = 0;
		while ( T[i] != 0 )
		{
			if ( T[i] == 32 )
			{
				T[i] = 0;
				strcpy_s( S, T + k);

				if ( (PP( S) == 1) && (i - k > 2))
     			cout << S << endl;
     			k = i + 1;
			}
			i++;
		}		
	  }

 	  for( int i=0; i< strlen(S);) S[i++]= 0;
	  
    fclose( F1);
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
		if ( St.pop() != s[i] ) return 0;
	}
	
	return 1;
}
