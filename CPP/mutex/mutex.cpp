// mutex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <ctime>
#include <chrono>

/*Вариант 13
n = 1 - читателей
m = 4 - писателей
*/

std::mutex mtxr; // мьютекс для читателей
std::mutex mtxw; // мьютекс для писателей

void read(std::string str)
{
	//mtxr.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << " Thread ID: " << std::this_thread::get_id() << '\n';
	std::cout << str << '\n';
	//mtxr.unlock();
}

int main()
{
	setlocale(LC_ALL, "rus");

	std::string str;
	unsigned int start;
	unsigned int end;

	std::thread writer([&]()
		{
			std::lock_guard<std::mutex> lgw(mtxw);
			std::cout << " Thread ID: " << std::this_thread::get_id() << '\n';
			std::cout << "Enter your message :\t";
			std::getline(std::cin, str);
		});
	writer.join();

	start = clock();

	std::thread reader1(read, str);
	std::thread reader2(read, std::ref(str));
	std::thread reader3([&]() {read(str); });
	std::thread reader4(read, std::ref(str));

	reader2.join();
	reader3.join();
	reader1.join();
	reader4.join();

	end = clock();

	std::cout << "Время работы программы: " << (end - start) << " милисек.";

	return 0;
}

