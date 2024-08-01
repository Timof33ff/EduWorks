#ifndef HAMMIG_H
#define HAMMIG_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<math.h>
#include<bitset>
#include<string>
#include<vector>

using namespace std;

typedef bitset<sizeof(char)*8> bs8;

class Hamming //generating Hamming code with dimension of (m+r, m) = (2^r-1, 2^r - r - 1)
{
    string data;
    int m;//data bits
    int s;//data.size()
    int r;//num of redundant bits

    bool* HamCode;// Hamming code
    bool isErr = false;

    private:
    //encode funcs
    void setRedundantBits();
    void initialize(string msg);
    void setBitset();
    bool* calcRedBit(bool* arr);


    public:
        Hamming(string msg);// constructor as encoder
        Hamming( const Hamming &H);// copy constructor
        virtual ~Hamming();

        //decode funcs
        void decoder();


    //other
    void show();
    int calcR();
    void setError();
    string HamCodeToString();
};

#endif // HAMMIG_H
