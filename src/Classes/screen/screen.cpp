#include "screen.hpp"
#include "../pixel/pixel.hpp"
#include "glad.h"
#include "../tasks/tasks.hpp"
#include <GLFW/glfw3.h>
#include "../color/color.hpp"
#include <tuple>

Screen::Screen(int width, int height) {
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

    // Screen window
    this->window = glfwCreateWindow(this->width, this->height, "Paint Dih", NULL, NULL);
    glfwMakeContextCurrent(this->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Could not load opengl"<< std::endl;
        glfwTerminate();
        return;
    }
}

void Screen::start() {
    Tasks task_manager(this);

    task_manager.start();

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->pixel_buffer);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}

void Screen::setPixelColor(int x, int y, Color* color) {
    if (x >= this->width || x < 0 || y >= this->height || y < 0) {
        return;
    }

    int flippedY = this->height - 1 - y;

    int pixelLocation = (flippedY * this->width * 3) + (x * 3);
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

void Screen::printScreen() {
    std::cout << "hello!" << std::endl;
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