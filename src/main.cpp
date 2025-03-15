#include <iostream> 
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"

int main() {
    Color white(255, 255, 255, 120);
    Color* red = new Color(255, 0, 0, 0);
    Screen test_screen(500, 500);
    //test_screen.setColor(white);

    
    for (int y = 250; y <= 300; y++) {
        for (int x = 50; x <= 100; x++) {
            test_screen.setPixelColor(x, y, red);
        }
    }

    test_screen.start();

    return 1;
}