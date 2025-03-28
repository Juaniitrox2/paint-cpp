#include "screen.hpp"
#include "../pixel/pixel.hpp"
#include "glad.h"
#include "../tasks/tasks.hpp"
#include <GLFW/glfw3.h>
#include "../color/color.hpp"
#include <tuple>
#include "../window/window.hpp"

Screen::Screen(unsigned int width, unsigned int height) {
    if (!glfwInit()) {
        return;
    }

    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Las dimensiones de la pantalla deben ser positivas.");
    }

    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
    });

    this->width = width;
    this->height= height;

    // Reservar memoria para la matriz de píxeles
    this->screen_pixels = new Pixel*[width];

    this->pixel_buffer = new float[this->width * this->height * 3];

    for (int x = 0; x < width; x++) {
        this->screen_pixels[x] = new Pixel[height]; // This will still fail without a default constructor
    }

    Window* main_window = new Window(width, height, "Bloatwave Paint");

    this->windows.push_back(main_window);
}

void Screen::start() {
    Tasks task_manager(this);

    task_manager.start();

    while (this->windows.size() > 0){
        int vector_size = this->windows.size();
        for (unsigned int i = 0; i < vector_size; i++) {
            Window* program_window = this->windows.at(i);

            if (program_window->isFocused()) {
                Color* red = new Color(255, 0, 0, 0);
                program_window->update();
            }

            if (glfwGetCurrentContext() == NULL && program_window->isVisible()) {
                std::cout << "focused!" << endl;
                program_window->focus();
            }
        }

        if (glfwGetCurrentContext() == NULL) break;
    }

    glfwTerminate();
}

Window* Screen::getFocusedWindow() {
    int vector_size = this->windows.size();
    for (unsigned int i = 0; i < vector_size; i++) {
        Window* program_window = this->windows.at(i);

        if (program_window->isFocused()) {
            return program_window;
        }
    }

    Window* empty = new Window();
    return empty;
}

void Screen::setColor(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

Window* Screen::getWindowFromGL(GLFWwindow* gl_window) {
    int vector_size = this->windows.size();
    for (unsigned int i = 0; i < vector_size; i++) {
        Window* program_window = this->windows.at(i);

        if (program_window->getGLWindow() == gl_window) {
            return program_window;
        }
    }

    throw invalid_argument("Invalid window given, not bound to a Window object");    
}

Screen::~Screen(){
    for (int x = 0;x < width; x++){
        delete[] screen_pixels[x];
    }
    delete[] screen_pixels;
}