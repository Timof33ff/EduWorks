#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    setlocale(0, "1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string file_in, word_in, word_fn;
    file_in = "konstitutsiia1.txt";

    ofstream out(file_in, ios::out | ios::app);
    ifstream in(file_in.c_str(), ios::in);
    if (!in.good())
    {
        clog << "Файл не найден.\n";
        exit(1);
    }
    cout << "Введите слово: ";
    cin >> word_fn;
    int count = 0;
    char* a;
    a = new char;
    while (!in.eof())
    {
        in >> a; 
        count++;
    }
    delete a;
    int k;
    while (in >> word_in)
        for (int i = 0; i <= count; i++)
        {
            if (word_in[i] = word_fn[i])
            {
                if (k > (sizeof(word_fn) + 1))
                {
                    cout << "Слово '" << word_in << "' найдено.\n";
                    system("PAUSE");
                    in.close();
                    return 0;
                }
                else
                {
                    cout << "Слово '" << word_fn << "' не найдено\n";
                }
                system("PAUSE");
                in.close();
                return 0;

                k++;
            }
        }
    in.close();
    return 0;
}