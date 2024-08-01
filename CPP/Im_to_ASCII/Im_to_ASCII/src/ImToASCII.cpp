#include "ImToASCII.h"

ImToASCII::ImToASCII(char* imName)
{
    //name = imName;
    im.loadFromFile(imName);
    char fn[255];
    strcat(strcat(fn, imName),".txt");
    txt = fopen(fn, "w");
    fseek(txt, 0, SEEK_SET);
    //res = new char[im.getSize().y*im.getSize().x];
    //ctor
}

ImToASCII::~ImToASCII()
{
    //dtor
}

void ImToASCII::convert()
{
    int index = 0;
    //int k = 0;

    for (int y = 0; y < im.getSize().y; y++)
    {
        for (int x = 0; x < im.getSize().x; x++)
        {
            color = im.getPixel(x, y);
            index = int(((color.r*0.375+color.g*0.5+color.b*0.16 )/ 263.925) * 11);

            //res[k++] = str[index];
            fputc(str[index], txt);
            fputc('.', txt);
        }
        fputc('\n', txt);
        //res[k++] = '\n';
    }
    fclose(txt);
    //loadToFile("img.txt", res);
}

/*void ImToASCII::loadToFile(char* filename, char* msg)
{
    std::fstream ofile;
    ofile.open(filename);
    int k = 0;
    while(k<im.getSize().y*im.getSize().x){ ofile << msg[k]; k++;}
    ofile.close();
}*/