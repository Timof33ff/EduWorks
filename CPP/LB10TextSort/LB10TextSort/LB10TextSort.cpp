// LB10TextSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "HashTable.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string filename( "f12.txt");
    int words_count = 0;
    
    std::string* words = read_file(filename, words_count);
    for ( int i = 0; i<words_count; i++)
    {
	std::cout<< "Text unsorted:"<<std::endl;
	for ( int j = 0; j<words[i]; j++)
    {
    	std::cout<<words[i][j];
	}
	std::cout<<std::endl;
    }
    system("PAUSE >> void");
    return 0;
}


