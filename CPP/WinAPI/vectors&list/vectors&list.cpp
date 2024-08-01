// vectors&list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

vector<string> readFile(const char* filename)
{
	vector<string> txt;

	ifstream file(filename);

	string buf;

	while (getline(file, buf))
	{
		txt.push_back(buf);
	}

	file.close();

	return txt;
}

void print(vector<int> your_vec)
{
	vector<int>::iterator itr = your_vec.begin();
	int i = 0;
	cout << "\tYour vector:\n";
	for (; itr != your_vec.end(); ++itr)
	{
		if (i == 10) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << '\n';
}

void print(list<int> your_list) {
	list<int>::iterator itr = your_list.begin();
	int i = 0;
	cout << "\tYour list:\n";
	for (; itr != your_list.end(); ++itr)
	{
		if (i == 10) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << '\n';
}

void print_reverse(list<int> your_list) {
	list<int>::reverse_iterator itr = your_list.rbegin();
	int i = 0;
	cout << "\tYour reverse list:\n";
	for (; itr != your_list.rend(); ++itr)
	{
		if (i == 10) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << '\n';
}

void print(vector<string> your_vec)
{
	vector<string>::iterator itr = your_vec.begin();
	int i = 0;
	cout << "\tYour vector:\n";
	for (; itr != your_vec.end(); ++itr)
	{
		if (i == 3) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << '\n';
}


int main()
{
	setlocale(LC_ALL, "rus");
	// Объявление
	vector<string> txt_vec;
	vector<int> num_vec;
	list<int> num_list;

	srand(time(nullptr)); // use current time as seed for random generator

	int n = 100;

	for (int i = 0; i < n; i++)
	{
		num_vec.push_back(int(rand()%n));
		num_list.push_back(int(rand() % n));
	}

	cout << "\tВектор случайных чисел\n";
	print(num_vec);
	cout << '\n' << "-------------------------------------------------------------------------------------------" << '\n';
	num_vec.resize(20);
	cout << "\tВектор случайных чисел, обрезанный до 20 первых значений\n";
	print(num_vec);

	txt_vec = readFile("data.txt");

	cout << '\n' << "-------------------------------------------------------------------------------------------" << '\n';
	cout << "\tВектор строк из файла\n";
	print(txt_vec);
	cout << '\n' << "-------------------------------------------------------------------------------------------" << '\n';

	cout << "\tСписок случайных чисел\n";
	print(num_list);

	num_list.sort();

	cout << '\n' << "-------------------------------------------------------------------------------------------" << '\n';
	cout << "\tОтсортированный список случайных чисел\n";
	print(num_list);

	auto res = unique(begin(num_list), end(num_list));
	num_list.erase(res, num_list.end());

	cout << '\n' << "-------------------------------------------------------------------------------------------" << '\n';
	cout << "\tОтсортированный список случайных чисел без дубликатов\n";
	print(num_list);

	cout << '\n' << "-------------------------------------------------------------------------------------------" << '\n';
	cout << "\tСписок в обратном порядке\n";
	print_reverse(num_list);

	return 0;
}
