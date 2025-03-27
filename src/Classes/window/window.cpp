#include <iostream>
#include "window.hpp"
#include <glad.h>
#include <GLFW/glfw3.h>
using namespace std;

Window::Window() {}
Window::Window(unsigned int width, unsigned int height, string name) {
    if (!glfwInit()) {
        return;
    }

    if (width <= 0 || height <= 0) {
        throw invalid_argument("Las dimensiones pasadas son inválidas, deben uint > 0");
    }

    this->width = width;
    this->height = height;
    this->visible = false;

    this->window_object = glfwCreateWindow(this->width, this->height, name, NULL, NULL);

    if (!this->window_object || !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Error loading OpenGL" << endl;

        glfwTerminate();
    }
}

void Window::focus() {
    glfwMakeContextCurrent(this->window_object);
}

void Window::setVisibility(bool state) {
    if (state) {
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    } else {
        if (this->IsFocused()) {
            glfwMakeContextCurrent(NULL);
        }

        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    }

    this->visible = state;
}

void Window::update() {
    if (glfwWindowShouldClose(this->window_object)) {
        glfwMakeContextCurrent(NULL);
        glfwDestroyWindow(this->window_object);
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->pixel_buffer);

    glfwSwapBuffers(window);
}

bool Window::isFocused() {
    return (glfwGetCurrentContext() == this->window_object);
}

bool Window::isVisible() {
    return this->visible;
}

Window::~Window() {

}