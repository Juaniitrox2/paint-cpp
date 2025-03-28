#pragma once
#include <iostream>
#include "../pixel/pixel.hpp"
#include "../color/color.hpp"
#include <vector>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "Classes/window/window.hpp"

class Tasks;

/**
*clase pantalla tiene pixeles
*/
class Screen {
    public:
        // Methods
        Screen(unsigned int width, unsigned int height);
        ~Screen();

        void setColor(Color color);
        void start();
        void newWindow(unsigned int width, unsigned int height, std::string name);
        Pixel& getPixel(int x, int y);
        Window* getFocusedWindow();
        Window* getWindowFromGL(GLFWwindow* gl_window);

        // Datos
    private:
        unsigned int width;
        unsigned int height;


        vector<Window*> windows;
        Pixel** screen_pixels;
        float* pixel_buffer;
};