#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

list<string> readFile_tolist(const char* filename)
{
	list<string> txt;
	ifstream file(filename);
	string buf;

	while (getline(file, buf))	txt.push_back(buf);
	
	file.close();
	return txt;
}

map<string, string> readFileToMap(const char* filename)
{
	map<string, string> map; 
	string buf; 
	ifstream f(filename);

	while (getline(f, buf)) map.insert(pairFromStr(buf));

	return map;
}

pair<string, string> pairFromStr(string your_str)
{
	pair<string, string> p;
	string frst, secd;
	for (int i = 0; i < your_str.size(); i++)
	{
		if (i > your_str.size() - 11) frst.push_back(your_str[i]);
		else if (i < your_str.size() - 11) secd.push_back(your_str[i]);
		else continue;
	}
	p.first = frst; p.second = secd;
	return p;
}

void print(list<string> your_list)
{
	list<string>::iterator itr = your_list.begin();
	int i = 0;
	cout << "\tYour list: len = " << your_list.size() << "\n----------------------------------------------------------------------------------------------------\n";
	for (; itr != your_list.end(); ++itr)
	{
		if (i == 2) { cout << '\n'; i = 0; }
		cout << '\t' << *itr << '\t';
		i++;
	}
	cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void print_map(map<string, string> your_map, int countToView)
{
	map<string, string>::iterator itr = your_map.begin();
	int n;
	if (countToView > your_map.size()) n = your_map.size();
	else n = countToView;
	int j = 0;
	cout << "\tYour map: len = " << your_map.size() << "\n----------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i<n; i++)
	{	
		if (j == 2) { cout << '\n'; j = 0; }
		cout << "\t[" << itr->first << "] :\t" << itr->second << '\t';
		j++;
		itr++;
	}
	if(n<your_map.size()) cout << "\n\t.etc................\n----------------------------------------------------------------------------------------------------\n";
	else cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void print_mmap(multimap<string, string> your_map, int countToView)
{
	multimap<string, string>::iterator itr = your_map.begin();
	int n;
	if (countToView > your_map.size()) n = your_map.size();
	else n = countToView;
	int j = 0;
	cout << "\tYour map: len = " << your_map.size() << "\n----------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < n; i++)
	{
		if (j == 2) { cout << '\n'; j = 0; }
		cout << "\t[" << itr->first << "] :\t" << itr->second << '\t';
		j++;
		itr++;
	}
	if (n < your_map.size()) cout << "\n\t.etc................\n----------------------------------------------------------------------------------------------------\n";
	else cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void createMatchMap(map<string, string> base_map, list<string> match_list, multimap<string, string> &res_map)
{
	list<string>::iterator iml = match_list.begin(); // Итератор по сравниваемому списку
	bool search = true; // найдено ли значение в списке или нет
	
	for (; iml != match_list.end(); ++iml)
	{
		auto res = find_if(begin(base_map), end(base_map),     // Если условие лямбда функции выполняется,
					[&](pair<string, string> pair)				// то find_if возвращает указатель на найденный элемент. 
					{											// Условие выполняеться, если значение элемента словаря 
																// соответсвтует зачению из сравниваемого списка.
						if (pair.second == *iml) search = true; 
						else search = false; 
						return search;
					});
		if (search) res_map.insert(*res);
		else res_map.insert(make_pair("000.000000", *iml)); // Если не нашли соответствие, пишел ключ 000.000000
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	const char fn1[]{ "data//RGR31_13.txt" };
	const char fn2[]{ "data//RGR32_13.txt" };
	const char fn3[]{ "data//RGR2.txt" };

	list<string> lst1 = readFile_tolist(fn1); // Читаем в списки
	list<string> lst2 = readFile_tolist(fn2);
	
	//print(lst1); print(lst2);

	lst1.insert(lst1.end(), lst2.begin(), lst2.end()); // Объединяем списки в один
	
	lst1.sort(); // Сортируем
	
	auto res = unique(begin(lst1), end(lst1)); // Находим повторяющиеся значения;
	
	lst1.erase(res, lst1.end()); // Удаляем дубликаты
	
	//print(lst1);

	map<string, string> mp = readFileToMap(fn3); // Словарь имён из файла RGR2
	
	//print_map(mp, 100);

	//lst1.push_back("Привет, мир!");
	//lst1.push_back("/****C++***/");

	multimap<string, string> new_map;	// multimap для хранения двух элементов по одному ключу
	createMatchMap(mp, lst1, new_map);	// Заполняем итоговый словарь совпадений 
	print_mmap(new_map, new_map.size());

	return 0;
}

