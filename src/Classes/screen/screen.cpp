#include "screen.hpp"
#include "../pixel/pixel.hpp"
#include "glad.h"
#include "../tasks/tasks.hpp"
#include <GLFW/glfw3.h>
#include "../color/color.hpp"
#include <tuple>
#include "Classes/window/window.hpp"

Screen::Screen(unsigned int width, unsigned int height) {
    if (!glfwInit()){
        return;
    }   

    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Las dimensiones de la pantalla deben ser positivas.");
    }

    this->width = width;
    this->height= height;

    // Reservar memoria para la matriz de píxeles
    this->screen_pixels = new Pixel*[width];

    this->pixel_buffer = new float[this->width * this->height * 3];

    for (int x = 0; x < width; x++) {
        this->screen_pixels[x] = new Pixel[height]; // This will still fail without a default constructor
    }

    Window main_window(width, height, "Bloatwave Paint");

    this->windows.push_back(main_window);
}

void Screen::start() {
    Tasks task_manager(this);

    task_manager.start();

    while (this->windows.size() > 0){
        glfwPollEvents();
        
        int vector_size = this->windows.size();
        for (unsigned int i = 0; i < vector_size; i++) {
            Window program_window = this->windows.at(i);

            if (program_window.isFocused()) {
                program_window.update();
            }

            if (glfwGetCurrentContext() == NULL && program_window.isVisible()) {
                program_window.focus();
            }
        }
    }

    glfwTerminate();
}

void Screen::setPixelColor(int x, int y, Color* color) {
    if (x >= this->width || x < 0 || y >= this->height || y < 0) {
        return;
    }

    int flippedY = this->height - 1 - y;

    unsigned int pixelLocation = (flippedY * this->width * 3) + (x * 3);
    this->pixel_buffer[pixelLocation + 0] = color->r;
    this->pixel_buffer[pixelLocation + 1] = color->g;
    this->pixel_buffer[pixelLocation + 2] = color->b;
}

void Screen::setAreaColor(int pos_x, int pos_y, int size_x, int size_y, Color* color) {
    for (int y = pos_y; y <= pos_y + size_y; y++) {
        for (int x = pos_x; x <= pos_x + size_x; x++) {
            this->setPixelColor(x, y, color);
        }
    }
}

Window Screen::getFocusedWindow() {
    int vector_size = this->windows.size();
    for (unsigned int i = 0; i < vector_size; i++) {
        Window program_window = this->windows.at(i);

        if (program_window.isFocused()) {
            return program_window;
        }
    }
}

void Screen::setColor(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

Screen::~Screen(){
    for (int x = 0;x < width; x++){
        delete[] screen_pixels[x];
    }
    delete[] screen_pixels;
}