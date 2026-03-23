// BinarySearchTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <locale.h>
#include <ctime>
#include "BDP.h"

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int* A, k, n;
    std::cout << " Введите размерность входа  - n: ";
    std::cin>> n;
    
    A = new int[n];
    for (int j = 0; j < n; j++)
    {
        k = rand() % 1000;
        A[j] = k;
        std::cout << k << " ";
    }
    // объявление объекта класса BDP; 
    BDP Tree(A[n/2]);

    // цикл загрузки данных в  бинарное дерево поиска 
    for (int j = 0; j < n; j++)
    {
        Tree.push(Tree.BinSTree, createRoot(A[j]));
    }
    std::cout << '\n';

    // выгрузка ключей  
    Tree.Show(Tree.BinSTree);
    Tree.printTree(Tree.BinSTree);
    std::cout << '\n';

    // поиск ключа  
    int X;
    std::cout<<" Enter search num:" <<std::endl;
    std::cin>> X;

    bool is_finded = Tree.BinSearch(Tree.BinSTree, X);

    if( is_finded == true) 
	{
    std::cout<<" Excellent! Num finded!"<<std::endl;	
	}
	else
	{
	    std::cout<<" Not here :("<<std::endl;		
	}
    std::cout << '\n';

    // максимальная глубина
    int depth = Tree.maxDepth(Tree.BinSTree);
    std::cout << " Maximum depth: " << depth << std::endl;
    std::cout << '\n';

    // вывод максимального элемента 
    std::cout << " Maximum:" << Tree.MaxElement(Tree.BinSTree) << std::endl;
    std::cout << '\n';

    // вывод минимального элемента 
    std::cout << " Minimum:" << Tree.MinElement(Tree.BinSTree) << std::endl;
    std::cout << '\n';

    delete[] A;
    std::cout << '\n';
    system("PAUSE");
}