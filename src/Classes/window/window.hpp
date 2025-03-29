#pragma once
#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include "Classes/color/color.hpp"
#include <vector>

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
        
        void addBufferToRender(const std::vector<float >& vertices);
        
        void initShaders();
        GLFWwindow* getGLWindow();
        
        // Attributes
        unsigned int width;
        unsigned int height;
        
    private:
        std::vector<std::vector<float>> rendered_buffers;
        std::string name;

        GLuint VAO;
        GLuint shaderProgram;
        bool visible;
        float* pixel_buffer;
        Color* background_color;
        GLFWwindow* window_object;

        void checkShaderCompileStatus(GLuint shader, const std::string& type);
};