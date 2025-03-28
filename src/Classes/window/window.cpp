#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include "window.hpp"
#include "../color/color.hpp"
using namespace std;

Window::Window() {}
Window::Window(unsigned int width, unsigned int height, std::string name) {
    if (width <= 0 || height <= 0) {
        throw invalid_argument("Las dimensiones pasadas son inválidas, deben uint > 0");
    }

    //
    this->width = width;
    this->height = height;
    this->visible = false;
    this->name = name;

    this->pixel_buffer = new float[this->width * this->height * 3];
    this->window_object = glfwCreateWindow(this->width, this->height, "Paint Bloatwave Window", NULL, NULL);
    
    if (!this->window_object) {
        cout << "Error loading window" << endl;
        
        glfwTerminate();
    }
    
    this->focus();
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "Could not load opengl"<< endl;
        glfwTerminate();
        return;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glClearColor(0.25f, 0.35f, 0.11f, 0.0f);
}

void Window::setPixelColor(int x, int y, Color* color) {
    if (x >= this->width || x < 0 || y >= this->height || y < 0) {
        return;
    }

    int flippedY = this->height - 1 - y;

    unsigned int pixelLocation = (flippedY * this->width * 3) + (x * 3);
    this->pixel_buffer[pixelLocation + 0] = color->r;
    this->pixel_buffer[pixelLocation + 1] = color->g;
    this->pixel_buffer[pixelLocation + 2] = color->b;
}

void Window::setAreaColor(int pos_x, int pos_y, int size_x, int size_y, Color* color) {
    for (int y = pos_y; y <= pos_y + size_y; y++) {
        for (int x = pos_x; x <= pos_x + size_x; x++) {
            this->setPixelColor(x, y, color);
        }
    }
}

void Window::focus() {
    glfwMakeContextCurrent(this->window_object);
}

void Window::setVisibility(bool state) {
    if (!this->window_object) return;

    if (state) {
        glfwShowWindow(this->window_object);
    } else {
        if (this->isFocused()) {
            glfwMakeContextCurrent(NULL);
        }

        glfwHideWindow(this->window_object);
    }

    this->visible = state;
}

void Window::setBackgroundColor(Color* new_color) {

}

void Window::update() {
    if (glfwWindowShouldClose(this->window_object)) {
        glfwMakeContextCurrent(NULL);
        glfwDestroyWindow(this->window_object);
        return;
    }

    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    
    glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->pixel_buffer);

    glfwSwapBuffers(this->window_object);
}

bool Window::isFocused() {
    return (glfwGetCurrentContext() == this->window_object);
}

bool Window::isVisible() {
    return this->visible;
}

GLFWwindow* Window::getGLWindow() {
    return this->window_object;
}

Window::~Window() {
    if (this->window_object) {
        if (this->isFocused()) {
            glfwMakeContextCurrent(NULL);
        }

        glfwDestroyWindow(this->window_object);
    }
}