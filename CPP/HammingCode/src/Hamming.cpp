#include "Hamming.h"

Hamming::Hamming(string msg)
{
    initialize(msg);
    setBitset();
    setRedundantBits();
    //ctor
}

Hamming::~Hamming()
{
    delete [] this->HamCode;
    //dtor
}

Hamming::Hamming(const Hamming &H)
{
this->HamCode = new bool[H.s];
    //copyctor
}

void Hamming::initialize(string msg)
{
    this->data = msg;
    this->s = this->data.size();
    this->r = calcR();
    this->m = pow(2,r)-1-r;

    HamCode = new bool[(m+r)]{};//init memory for bool arr size of data size*(m+r)
                                //consider bitset arrs
}

int Hamming::calcR()
{
 int r = 0;
 for(int i = 1; i<=s*8; i*=2)
 {
  r++;
 }
 return r;
}

void Hamming::setBitset()
{
 int k = 0;//iterator for skiping elements under powers of two indices
 int j = 0;//iterator for data`s element
 int q = 0;//iterator for current char bitset

 for(int i = 0; i<(m+r);)
 {
    if(j>=s) { break;}
    else if(i == pow(2,k)-1) { k++; i++; continue;}
    else
    {
        if(q>=sizeof(bs8)) { j++; q=0; continue;}
        else {HamCode[i++] = bs8(data[j])[q++];}
    }
 }
}

void Hamming::show()//show hamming code
{
 cout<< " CODE is :: " << endl << "------------------------------------------------------------" << endl;
 int k = 0;
 for(int i = 0; i<(m+r); i++)
 {
        if(i == pow(2,k)-1)
        {
            k++;
            cout<< " {" << HamCode[i] << "} ";//redundant bit
        }
        else
        {
            cout<< HamCode[i];//message bit
        }
 }
cout<< endl << "------------------------------------------------------------" << endl;
}

void Hamming::setRedundantBits()
{
 int counter = 0;

     for(int k = 0; k<r; k++)
     {
        for(int j = pow(2,k)-1; j<(m+r); j+=2*pow(2,k))
        {
            for(int q = j; q<(pow(2,k)+j); q++)
            {
                if(HamCode[q]==1)
                {
                    counter++;
                }
                else
                {
                    continue;
                }
            }
        }
     if(counter%2 == 0) HamCode[int(pow(2,k)-1)] = 1; //if count of 1 in current bitset %2 == 0
                                                        //then set 1 to current redundant bit

     else HamCode[int(pow(2,k)-1)] = 0;               //else set 0

     counter = 0;
     }
}

void Hamming::setError()
{
if(!isErr)//work if no error set
 {
 srand(time(0));

 int n = rand() % m+r;//calc random err index

 cout<< " Error set in " << n << endl;

 HamCode[n] = HamCode[n] ^ 1;//XOR operation on n`st element

 isErr = true;
 }
}

bool* Hamming::calcRedBit(bool* arr)
{
int counter = 0;//counter for '1'

bool* r_bs{new bool[r]{}};//bool array contained only redundant bits for input bs

     for(int k = 0; k<r; k++)
     {
        for(int j = pow(2,k)-1; j<(m+r); j+=2*pow(2,k))
        {
            for(int q = j; q<(pow(2,k)+j); q++)
            {
            if(q!=pow(2,k)-1)
            {
                if(arr[q]==1)
                {
                    counter++;
                }
                else
                {
                    continue;
                }
            }
            }
        }
     if(counter%2 == 0) r_bs[k] = 1; //if count of 1 in current bitset %2 == 0
                                     //then set 1 to current redundant bit
                                     //else set 0
     counter = 0;
     }

 return r_bs;
}

void Hamming::decoder()
{
 int errIndex = 0;//error index of
 int counter = 0;//counter for '1'
 int k = 0;
 bool* redundantBitset = calcRedBit(HamCode);// biset for recalc redundant bits

     for(int k = 0; k<r; k++)
     {
     if(redundantBitset[k]!= HamCode[int(pow(2,k)-1)]) errIndex+=int(pow(2,k));
     }
     if(errIndex!=0)
     {
      cout<< " Error finded in " << errIndex-1 << " bit." << endl;
      HamCode[errIndex-1] = HamCode[errIndex-1]^1;
      cout<< " Error fixed." <<endl;
     }
     else cout<< " No error finded :)" << endl;

  delete [] redundantBitset;
}

string Hamming::HamCodeToString()
{
 string msg;

 int k = 0;
 int q = 0;
 int j = 0;
 int res = 0;

 for(int i = 0; i<(m+r);)
 {
    if(j>=s) { break;}
    else if(i == pow(2,k)-1) { k++; i++; continue;}
    else
    {
        if(q==sizeof(bs8))
        {
        j++;
        q = 0;
        msg.push_back(static_cast<char>(res));
        res = 0;
        continue;
        }
        else
        {
            if(HamCode[i]) res += pow(2,q);
            q++;
            i++;
        }
    }
 }
 return msg;
}


