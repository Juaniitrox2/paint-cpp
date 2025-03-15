#include "color.hpp"

Color::Color() {}

Color::Color(int r, int g, int b, int a) {
    this->r = static_cast<float>(r)/255.0f;
    this->g = static_cast<float>(g)/255.0f;
    this->b = static_cast<float>(b)/255.0f;
    this->a = static_cast<float>(a)/255.0f;

    std::cout << this->r << std::endl;
}

Color::~Color() {

}