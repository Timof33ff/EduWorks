#ifndef IMTOASCII_H
#define IMTOASCII_H
#include "SFML/Graphics.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

/*
    Algorithm description:
    **********************
*/

class ImToASCII
{
    public:
        ImToASCII(char* imName);
        virtual ~ImToASCII();

    int W; int H; // width and height vector

    void convert();

    private:

    //void loadToFile(char* filename, char* msg);

    //char* name; // image file name

    FILE* txt; // txt file of result conversation

    sf::Image im; // image

    sf::Color color; // we only need this to get alpha from every pixel of image

    //char* res; // conversation result

    const char* str = "&@#S%?*+;:,."; // letters for draw
};

#endif // IMTOASCII_H
