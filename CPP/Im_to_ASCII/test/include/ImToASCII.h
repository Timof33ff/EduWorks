#ifndef IMTOASCII_H
#define IMTOASCII_H
#include "SFML/Graphics.hpp"
#include "cmath"
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

    int W; int H; // width and height of grid
    const int font_width = 4; const int font_height = 8; // width and height of font

    void convert();

    private:

    //void loadToFile(char* filename, char* msg);

    //char* name; // image file name

    FILE* txt; // txt file of result conversation

    sf::Image im; // image

    //char* res; // conversation result

    std::vector<sf::Color[font_width*font_height]> pixels;

    const char* str = "&@#S%?*+;:,."; // letters for draw

    void createVec();
};

#endif // IMTOASCII_H
