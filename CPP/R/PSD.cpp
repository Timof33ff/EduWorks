#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <cmath>
#include "LA.CPP"

using namespace std;

int PSD ( int *A, int n);

int main () 
{
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
	int A[100], n = 100;
	for(int i = 0; i < n; i++)
		{A[i]= rand()%10000;
		cout << A[i] << " ";
		if((i+1)%10 == 0)
			cout << endl;
		}
		cout<< endl;
	PSD(A, n);
	for(int i = 0; i < n; i++)
		{
		cout << A[i] << " ";
		if((i+1)%10 == 0)
			cout << endl;
		}
	return 0;
}

int PSD (int * A, int n)
{
    AQueue Q[10];
    int k, r, p, g;
    r = 1;
    
  for ( int i1 = 0; i1 < 4; i1++)
    {
    	g = i1;
    	for ( int j = 0; j < n; j++)
    	{
    	  k = A[j];
    	  k /= pow(10, g);
    	  r = k%10;
    	  Q[r].push(A[j]);
		}
		
		p = 0;
		
		for ( int k = 0; k < 10; k++)
		{
			p = Q[k].Out(A, p);
			Q[k].Init();	 
		}
	}
	return 0;
}
