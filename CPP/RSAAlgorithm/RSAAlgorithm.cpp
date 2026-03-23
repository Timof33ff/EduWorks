// RSAAlgorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream> 
#include <cmath>
#include <vector>
#include <string>
#include <Windows.h>
#include "Header.h"
/*                  THEORY
 
 | Encryption |                | Decryption |
С = (М ^ e)mod n;             M = (C ^ d)mod n;
e - public key                d - private key
(e*d)mod m = 1

C - encrypted message          
M - message                   
n = p * q - integer num
m = ( p-1) * (q-1) - integer num                */

const int p = 283; //first prime num
const int q = 601; //second prime num
const int blocks_col = 3;

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string message = "TALANT";

	int size = (int)message.length();
	long int n = p * q;
	long int m = (p - 1) * (q - 1);
	long int d = Calculate_d(m);
	long int e = Calculate_e(d, m);

	std::cout << "Public key:[" << e << "," << n << "]" << std::endl;
	std::cout << "Private key:[" << d << "," << n << "]" << std::endl;

	std::string* blocks = new std::string[blocks_col];
	for (int i = 0; i < blocks_col; i++) 
	{
		std::cout << " Block[" << i + 1 << "]" << std::endl;
		for (int j = 0; j < size - 1; j++)
		{
			blocks[i][j] = message[j];
		}
		std::cout << blocks[i] << std::endl;
	}
	std::vector<int*> codes;
	std::vector<int*>::iterator itr;

	for (int i = 0; i < blocks_col; i++)
	{
		codes.push_back(charToNum(blocks[i]));
	}

	for (itr = codes.begin(); itr != codes.end()-1; itr++)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Code:" << *itr[i] << std::endl;
			encrypt(e, n, *itr[i]);
			std::cout << "Encryption: [" << encrypt(e, n, *itr[i]) << "] " << std::endl;
		}
	}
	/*
	for (itr = codes.begin(); itr != codes.end()-1; itr++)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Code:" << *itr[i] << std::endl;
			decrypt_num[i] = decrypt(d, n, *itr[i]);
			std::cout << "Decryption: [" << decrypt(d, n, *itr[i]) << "] " << std::endl;
		}
	}
	std::cout << numToChar(decrypt_num, 6);*/
	return 1;
}
