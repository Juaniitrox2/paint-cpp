#pragma once
#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include "Classes/color/color.hpp"

class Window {
    public:
        // Methods
        Window();
        Window(unsigned int width, unsigned int height, std::string name);
        ~Window();
        
        void focus();
        void update();

        bool isFocused();
        bool isVisible();

        void setVisibility(bool state);
        void setBackgroundColor(Color* new_color);
        void setPixelColor(int x, int y, Color* color);
        void setAreaColor(int pos_x, int pos_y, int size_x, int size_y, Color* color);

        GLFWwindow* getGLWindow();

        // Attributes
        unsigned int width;
        unsigned int height;

    private:
        std::string name;
        bool visible;
        float* pixel_buffer;
        Color* background_color;
        GLFWwindow* window_object;
};