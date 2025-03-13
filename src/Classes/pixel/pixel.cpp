#include "pixel.hpp"
#include <tuple>
#include <iostream>
using namespace std;

Pixel::Pixel(tuple<int, int> position, tuple<float, float, float, float> color) {
    position = position;
    color = color;
}

void Pixel::setPixel(float red , float green, float blue, float opacity) {
    color = make_tuple(red, green, blue, opacity);
}