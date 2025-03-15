#pragma once
#include <iostream>

/**
* @brief Los valores RGBA se pasan de 0-255 (int) y se convierten de 0-1f
*/

class Color {
    public:
        float r;
        float g;
        float b;
        float a;

    Color();
    Color(int r, int g, int b, int a);
    ~Color();
};