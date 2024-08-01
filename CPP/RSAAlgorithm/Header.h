#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

int* charToNum(std::string str)
{
    int len = (int)str.length();
    int* num = new int[len];
    for (int i = 0; i < len; i++)
        num[i] = str[i] - 'А' + 1;
    return num;
}

std::string numToChar(int* num, int len)
{
    std::string str;
    for (int j = 0; j < len; j++)
        str[j] = (num[j] + 'А' - 1) % 256;
    return str;
}

bool isprime( int p)
{
    int j = ( int)sqrt(p);
    for (int i = 2; i <= j; i++)
    {
        if (j % i == 0) return false;
    }
    return true;
}

long int powerFast(long int num, long int deg)//возведение в степень за О(log n) 
{
    long int result = 1;
    while (deg) {
        if (deg % 2 == 0) {
            deg /= 2;
            num *= num;
        }
        else {
            deg--;
            result *= num;
        }
    }
    return result;
}

 long int Calculate_d( long int m)
{
    long d = m - 1;

    for (long i = 2; i <= m; i++)
        if ((m % i == 0) && (d % i == 0))
        {
            d--;
            i = 1;
        }
    return d;
}

 long int  Calculate_e(long int d, long int m)
{
     long int e = 10;

     while (true)
     {
         if ((e * d) % m == 1)
             break;
         else
             e++;
     }

     return e;
}

 long int encrypt( long int e, int n, int code)
 {
     return powerFast(code, e) % n;
 }

 long int decrypt(long int d, int n, int crypt_code)
 {
     return powerFast(crypt_code, d) % n;
 }



