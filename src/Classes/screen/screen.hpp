#pragma once
#include <iostream>
#include "../pixel/pixel.hpp"
#include "../color/color.hpp"
#include <vector>
#include "glad.h"
#include <GLFW/glfw3.h>

/**
*clase pantalla tiene pixeles
*/
class Screen {
    public:
    // Constructores
    Screen(int width , int height);
    ~Screen();
    void setColor(Color color);
    /**
    * @brief Printea la screen
    */
    Pixel& getPixel(int x, int y);
    void setPixelColor(int x, int y, Color color);
    void printScreen();
    void start();

    // Datos
    int width;
    int height;

    GLFWwindow* window;
    Pixel** screen_pixels;
    float** pixel_buffer;
    tuple <float, float,float,float> color;
};