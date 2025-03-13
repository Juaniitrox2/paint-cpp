#include <iostream>
#include "../pixel/pixel.hpp"
#include <vector>

/**
*clase pantalla tiene pixeles
*/
class Screen {
    public:
    // Constructores
    Screen(int width , int height) {};
    void setColor(float r, float g, float b, float a);
    /**
    * @brief Printea la screen
    */
    void printScreen();
    Pixel& getPixel(int x, int y);

    // Datos
    int width;
    int height;

    Pixel** screen_pixels;
    tuple <float, float,float,float> color;
};