#include "ImToASCII.h"

int main()
{
    char* fn = "resourse/traxnut.jpg";

    ImToASCII im(fn);
    im.convert();

    return 0;
}
