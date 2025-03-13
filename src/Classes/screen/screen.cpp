#include "screen.hpp"
#include "pixel.hpp"

Screen::Screen(int width, int height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Las dimensiones de la pantalla deben ser positivas.");
    }

    // Reservar memoria para la matriz de píxeles
    screen_pixels = new Pixel*[width]; // "[][][] Asumiendo width 3"

    for (int x = 0; x < width; x++){
        screen_pixels[x] = new Pixel[height];
        // "[- - -] [- - - ] [ - - -]"
    }

}

void Screen::printScreen() {
    std::cout << "hello!" << std::endl;
}

void Screen::setColor(float r, float g, float b, float a) {
    color = std::make_tuple(r, g, b, a);
}


Screen::~Screen(){
    for (int x = 0;x < width; x++){
        delete[] screen_pixels[x];
    }
    delete[] screen_pixels;
}