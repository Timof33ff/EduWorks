#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "LA.CPP"

using namespace std;

int SSS ( int *A, int n);

int main () 
{
	SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
	int A[100], n = 100;
	for(int i = 0; i < n; i++)
		{A[i]= rand()%10;
		cout << A[i] << " ";
		if((i+1)%10 == 0)
			cout << endl;
		}
	SSS(A, n);
	for(int i = 0; i < n; i++)
		{
		cout << A[i] << " ";
		if((i+1)%10 == 0)
			cout << endl;
		}



	return 0;
}

int SSS (int * A, int n)
{
	AList SP;
	
	for ( int i = 0; i < n; i++)
		SP.push(A[i]); 
	SP.out(A);
	return 0;
}
