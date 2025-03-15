#pragma once
#include <iostream>
#include "Classes/color/color.hpp"
using namespace std;
/** 
* Clase pixel
*/
class Pixel {

    public:
    Pixel();
    Pixel(tuple<int, int> position, Color color);
    ~Pixel();
    int id;
    void setColor(Color color);

    private:

    tuple<int, int> position;             
    Color color;
};