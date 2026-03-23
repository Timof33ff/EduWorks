#include ".rsrc/main.hpp"
#include "Hamming.h"
int main()
{
    string fn = ".txt/text";
    string msg = openfile(fn);
    Hamming H(msg);
    H.setError();
    H.decoder();
    loadToFile(H.HamCodeToString());
    return 0;
}
