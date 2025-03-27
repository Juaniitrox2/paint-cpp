#pragma once
#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include "Classes/color/color.hpp"
using namespace std;

class Window {
    public:
        // Methods
        Window();
        Window(unsigned int width, unsigned int height, string name);
        ~Window();
        
        void focus();
        void update();

        bool isFocused();
        bool isVisible();

        void setVisibility();
        void setBackgroundColor(Color* new_color);

        // Attributes
        unsigned int width;
        unsigned int height;

    private:
        bool visible;
        float** pixel_buffer;
        Color* background_color;
        GLFWwindow* window_object;
};