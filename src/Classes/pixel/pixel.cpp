#include "pixel.hpp"
#include "Classes/color/color.hpp"
#include <tuple>
#include <iostream>
using namespace std;

Pixel::Pixel() {

}

Pixel::Pixel(tuple<int, int> position, Color color) {
    this->position = position;
    this->color = color;
}

void Pixel::setColor(Color color) {
    this->color = color;
}

Pixel::~Pixel() {

}