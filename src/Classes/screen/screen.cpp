#include "screen.hpp"
#include "../pixel/pixel.hpp"
#include "glad.h"
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

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->pixel_buffer)

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}

void Screen::setPixelColor(int x, int y, Color color) {
    int pixelLocation;
    
    pixelLocation = (y * this->width * 3) + (x * 3);
    this->pixel_buffer[1] = 0
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