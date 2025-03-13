#pragma once
#include <iostream>
using namespace std;
/** 
* Clase pixel
*/
class Pixel {
    public:
    Pixel() : position(0,0), color(0,0,0,0) {};
    Pixel(tuple<int, int> position, tuple<float, float, float, float> color) {}
    int id;
    void setPixel(float red, float green, float blue, float opacity) {};

    private:

    tuple<int, int> position;             
    tuple<float, float, float, float> color;
};