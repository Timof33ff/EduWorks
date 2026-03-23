// iterator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

vector<string> readFile_tovec(const char* filename)
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

list<string> readFile_tolist(const char* filename)
{
	list<string> txt;

	ifstream file(filename);

	string buf;

	while (getline(file, buf))
	{
		txt.push_back(buf);
	}

	file.close();

	return txt;
}

void print(vector<string> your_vec)
{
	vector<string>::iterator itr = your_vec.begin();
	int i = 0;
	cout << "\tYour vector:\n----------------------------------------------------------------------------------------------------\n";
	for (; itr != your_vec.end(); ++itr)
	{
		if (i == 2) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void print(list<string> your_list)
{
	list<string>::iterator itr = your_list.begin();
	int i = 0;
	cout << "\tYour list:\n----------------------------------------------------------------------------------------------------\n";
	for (; itr != your_list.end(); ++itr)
	{
		if (i == 2) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << "\n----------------------------------------------------------------------------------------------------\n";
}

int main()
{
	setlocale(LC_ALL, "rus");

	const char fn[]{ "Discipline.txt" };
	vector<string> vec = readFile_tovec(fn);
	list<string> lst = readFile_tolist(fn);

	print(vec); print(lst);

	cout << "\n-----------------------------------После сортировки-----------------------------------\n";

	lst.sort(); print(lst);

	vector<string>::iterator iVec = vec.begin();
	list<string>::iterator iLst = lst.begin();

	int n;
	cout << "\n\tВведите интересующий индекс контейнеров: "; cin >> n;
	iVec += int(n-1);
	for(int i = 0; i <= n; i++) iLst ++;

	cout << "\n Элемент вектора по индексу\t" << n << "\t:\t" << *iVec << '\n';
	cout << "\n Элемент списка по индексу\t" << n << "\t:\t" << *iLst << '\n';

	return 0;
}

